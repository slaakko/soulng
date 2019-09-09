#include "RegEx.hpp"
#include <soulng/parsing/Action.hpp>
#include <soulng/parsing/Rule.hpp>
#include <soulng/parsing/ParsingDomain.hpp>
#include <soulng/parsing/Primitive.hpp>
#include <soulng/parsing/Composite.hpp>
#include <soulng/parsing/Nonterminal.hpp>
#include <soulng/parsing/Exception.hpp>
#include <soulng/parsing/StdLib.hpp>
#include <soulng/parsing/XmlLog.hpp>
#include <soulng/util/Unicode.hpp>

namespace soulng { namespace lexergen {

using namespace soulng::parsing;
using namespace soulng::util;
using namespace soulng::unicode;

RegExGrammar* RegExGrammar::Create()
{
    return Create(new soulng::parsing::ParsingDomain());
}

RegExGrammar* RegExGrammar::Create(soulng::parsing::ParsingDomain* parsingDomain)
{
    RegisterParsingDomain(parsingDomain);
    RegExGrammar* grammar(new RegExGrammar(parsingDomain));
    parsingDomain->AddGrammar(grammar);
    grammar->CreateRules();
    grammar->Link();
    return grammar;
}

RegExGrammar::RegExGrammar(soulng::parsing::ParsingDomain* parsingDomain_): soulng::parsing::Grammar(ToUtf32("RegExGrammar"), parsingDomain_->GetNamespaceScope(ToUtf32("soulng.lexergen")), parsingDomain_)
{
    SetOwner(0);
}

Nfa RegExGrammar::Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName, LexerContext* lexerContext)
{
    soulng::parsing::Scanner scanner(start, end, fileName, fileIndex, SkipRule());
    std::unique_ptr<soulng::parsing::XmlLog> xmlLog;
    if (Log())
    {
        xmlLog.reset(new soulng::parsing::XmlLog(*Log(), MaxLogLineLength()));
        scanner.SetLog(xmlLog.get());
        xmlLog->WriteBeginRule("parse");
    }
    soulng::parsing::ObjectStack stack;
    std::unique_ptr<soulng::parsing::ParsingData> parsingData(new soulng::parsing::ParsingData(GetParsingDomain()->GetNumRules()));
    scanner.SetParsingData(parsingData.get());
    stack.push(std::unique_ptr<soulng::parsing::Object>(new ValueObject<LexerContext*>(lexerContext)));
    soulng::parsing::Match match = soulng::parsing::Grammar::Parse(scanner, stack, parsingData.get());
    soulng::parsing::Span stop = scanner.GetSpan();
    if (Log())
    {
        xmlLog->WriteEndRule("parse");
    }
    if (!match.Hit() || stop.Start() != int(end - start))
    {
        if (StartRule())
        {
            throw soulng::parsing::ExpectationFailure(StartRule()->Info(), fileName, stop, start, end);
        }
        else
        {
            throw soulng::parsing::ParsingException("grammar '" + ToUtf8(Name()) + "' has no start rule", fileName, scanner.GetSpan(), start, end);
        }
    }
    std::unique_ptr<soulng::parsing::Object> value = std::move(stack.top());
    Nfa result = *static_cast<soulng::parsing::ValueObject<Nfa>*>(value.get());
    stack.pop();
    return result;
}

class RegExGrammar::RegExRule : public soulng::parsing::Rule
{
public:
    RegExRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("LexerContext*"), ToUtf32("lexerContext")));
        SetValueTypeName(ToUtf32("Nfa"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> lexerContext_value = std::move(stack.top());
        context->lexerContext = *static_cast<soulng::parsing::ValueObject<LexerContext*>*>(lexerContext_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Nfa>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RegExRule>(this, &RegExRule::A0Action));
        soulng::parsing::NonterminalParser* alternativeNonterminalParser = GetNonterminal(ToUtf32("Alternative"));
        alternativeNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<RegExRule>(this, &RegExRule::PreAlternative));
        alternativeNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RegExRule>(this, &RegExRule::PostAlternative));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromAlternative;
    }
    void PreAlternative(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<LexerContext*>(context->lexerContext)));
    }
    void PostAlternative(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromAlternative_value = std::move(stack.top());
            context->fromAlternative = *static_cast<soulng::parsing::ValueObject<Nfa>*>(fromAlternative_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): lexerContext(), value(), fromAlternative() {}
        LexerContext* lexerContext;
        Nfa value;
        Nfa fromAlternative;
    };
};

class RegExGrammar::AlternativeRule : public soulng::parsing::Rule
{
public:
    AlternativeRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("LexerContext*"), ToUtf32("lexerContext")));
        SetValueTypeName(ToUtf32("Nfa"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> lexerContext_value = std::move(stack.top());
        context->lexerContext = *static_cast<soulng::parsing::ValueObject<LexerContext*>*>(lexerContext_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Nfa>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<AlternativeRule>(this, &AlternativeRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<AlternativeRule>(this, &AlternativeRule::A1Action));
        soulng::parsing::NonterminalParser* leftNonterminalParser = GetNonterminal(ToUtf32("left"));
        leftNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<AlternativeRule>(this, &AlternativeRule::Preleft));
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<AlternativeRule>(this, &AlternativeRule::Postleft));
        soulng::parsing::NonterminalParser* rightNonterminalParser = GetNonterminal(ToUtf32("right"));
        rightNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<AlternativeRule>(this, &AlternativeRule::Preright));
        rightNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<AlternativeRule>(this, &AlternativeRule::Postright));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromleft;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Alt(*context->lexerContext, context->value, context->fromright);
    }
    void Preleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<LexerContext*>(context->lexerContext)));
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<Nfa>*>(fromleft_value.get());
            stack.pop();
        }
    }
    void Preright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<LexerContext*>(context->lexerContext)));
    }
    void Postright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromright_value = std::move(stack.top());
            context->fromright = *static_cast<soulng::parsing::ValueObject<Nfa>*>(fromright_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): lexerContext(), value(), fromleft(), fromright() {}
        LexerContext* lexerContext;
        Nfa value;
        Nfa fromleft;
        Nfa fromright;
    };
};

class RegExGrammar::CatenationRule : public soulng::parsing::Rule
{
public:
    CatenationRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("LexerContext*"), ToUtf32("lexerContext")));
        SetValueTypeName(ToUtf32("Nfa"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> lexerContext_value = std::move(stack.top());
        context->lexerContext = *static_cast<soulng::parsing::ValueObject<LexerContext*>*>(lexerContext_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Nfa>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CatenationRule>(this, &CatenationRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CatenationRule>(this, &CatenationRule::A1Action));
        soulng::parsing::NonterminalParser* leftNonterminalParser = GetNonterminal(ToUtf32("left"));
        leftNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<CatenationRule>(this, &CatenationRule::Preleft));
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<CatenationRule>(this, &CatenationRule::Postleft));
        soulng::parsing::NonterminalParser* rightNonterminalParser = GetNonterminal(ToUtf32("right"));
        rightNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<CatenationRule>(this, &CatenationRule::Preright));
        rightNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<CatenationRule>(this, &CatenationRule::Postright));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromleft;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Cat(context->value, context->fromright);
    }
    void Preleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<LexerContext*>(context->lexerContext)));
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<Nfa>*>(fromleft_value.get());
            stack.pop();
        }
    }
    void Preright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<LexerContext*>(context->lexerContext)));
    }
    void Postright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromright_value = std::move(stack.top());
            context->fromright = *static_cast<soulng::parsing::ValueObject<Nfa>*>(fromright_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): lexerContext(), value(), fromleft(), fromright() {}
        LexerContext* lexerContext;
        Nfa value;
        Nfa fromleft;
        Nfa fromright;
    };
};

class RegExGrammar::RepetitionRule : public soulng::parsing::Rule
{
public:
    RepetitionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("LexerContext*"), ToUtf32("lexerContext")));
        SetValueTypeName(ToUtf32("Nfa"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> lexerContext_value = std::move(stack.top());
        context->lexerContext = *static_cast<soulng::parsing::ValueObject<LexerContext*>*>(lexerContext_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Nfa>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RepetitionRule>(this, &RepetitionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RepetitionRule>(this, &RepetitionRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RepetitionRule>(this, &RepetitionRule::A2Action));
        soulng::parsing::ActionParser* a3ActionParser = GetAction(ToUtf32("A3"));
        a3ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RepetitionRule>(this, &RepetitionRule::A3Action));
        soulng::parsing::NonterminalParser* leftNonterminalParser = GetNonterminal(ToUtf32("left"));
        leftNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<RepetitionRule>(this, &RepetitionRule::Preleft));
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RepetitionRule>(this, &RepetitionRule::Postleft));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromleft;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Kleene(*context->lexerContext, context->value);
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Pos(*context->lexerContext, context->value);
    }
    void A3Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Opt(*context->lexerContext, context->value);
    }
    void Preleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<LexerContext*>(context->lexerContext)));
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<Nfa>*>(fromleft_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): lexerContext(), value(), fromleft() {}
        LexerContext* lexerContext;
        Nfa value;
        Nfa fromleft;
    };
};

class RegExGrammar::PrimaryRule : public soulng::parsing::Rule
{
public:
    PrimaryRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("LexerContext*"), ToUtf32("lexerContext")));
        SetValueTypeName(ToUtf32("Nfa"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> lexerContext_value = std::move(stack.top());
        context->lexerContext = *static_cast<soulng::parsing::ValueObject<LexerContext*>*>(lexerContext_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Nfa>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimaryRule>(this, &PrimaryRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimaryRule>(this, &PrimaryRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimaryRule>(this, &PrimaryRule::A2Action));
        soulng::parsing::ActionParser* a3ActionParser = GetAction(ToUtf32("A3"));
        a3ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimaryRule>(this, &PrimaryRule::A3Action));
        soulng::parsing::ActionParser* a4ActionParser = GetAction(ToUtf32("A4"));
        a4ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimaryRule>(this, &PrimaryRule::A4Action));
        soulng::parsing::ActionParser* a5ActionParser = GetAction(ToUtf32("A5"));
        a5ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimaryRule>(this, &PrimaryRule::A5Action));
        soulng::parsing::NonterminalParser* altNonterminalParser = GetNonterminal(ToUtf32("alt"));
        altNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<PrimaryRule>(this, &PrimaryRule::Prealt));
        altNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimaryRule>(this, &PrimaryRule::Postalt));
        soulng::parsing::NonterminalParser* idNonterminalParser = GetNonterminal(ToUtf32("id"));
        idNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimaryRule>(this, &PrimaryRule::Postid));
        soulng::parsing::NonterminalParser* classNonterminalParser = GetNonterminal(ToUtf32("Class"));
        classNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<PrimaryRule>(this, &PrimaryRule::PreClass));
        classNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimaryRule>(this, &PrimaryRule::PostClass));
        soulng::parsing::NonterminalParser* escNonterminalParser = GetNonterminal(ToUtf32("esc"));
        escNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimaryRule>(this, &PrimaryRule::Postesc));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromalt;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->lexerContext->MakeExpr(context->fromid);
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = MakeNfa(*context->lexerContext, context->fromClass);
    }
    void A3Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = MakeNfa(*context->lexerContext, context->lexerContext->MakeChar(context->fromesc));
    }
    void A4Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = MakeNfa(*context->lexerContext, context->lexerContext->MakeAny());
    }
    void A5Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = MakeNfa(*context->lexerContext, context->lexerContext->MakeChar(*matchBegin));
    }
    void Prealt(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<LexerContext*>(context->lexerContext)));
    }
    void Postalt(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromalt_value = std::move(stack.top());
            context->fromalt = *static_cast<soulng::parsing::ValueObject<Nfa>*>(fromalt_value.get());
            stack.pop();
        }
    }
    void Postid(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromid_value = std::move(stack.top());
            context->fromid = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromid_value.get());
            stack.pop();
        }
    }
    void PreClass(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<LexerContext*>(context->lexerContext)));
    }
    void PostClass(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromClass_value = std::move(stack.top());
            context->fromClass = *static_cast<soulng::parsing::ValueObject<Class*>*>(fromClass_value.get());
            stack.pop();
        }
    }
    void Postesc(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromesc_value = std::move(stack.top());
            context->fromesc = *static_cast<soulng::parsing::ValueObject<char32_t>*>(fromesc_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): lexerContext(), value(), fromalt(), fromid(), fromClass(), fromesc() {}
        LexerContext* lexerContext;
        Nfa value;
        Nfa fromalt;
        std::u32string fromid;
        Class* fromClass;
        char32_t fromesc;
    };
};

class RegExGrammar::ClassRule : public soulng::parsing::Rule
{
public:
    ClassRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("LexerContext*"), ToUtf32("lexerContext")));
        SetValueTypeName(ToUtf32("Class*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> lexerContext_value = std::move(stack.top());
        context->lexerContext = *static_cast<soulng::parsing::ValueObject<LexerContext*>*>(lexerContext_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Class*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ClassRule>(this, &ClassRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ClassRule>(this, &ClassRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ClassRule>(this, &ClassRule::A2Action));
        soulng::parsing::NonterminalParser* rNonterminalParser = GetNonterminal(ToUtf32("r"));
        rNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<ClassRule>(this, &ClassRule::Prer));
        rNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ClassRule>(this, &ClassRule::Postr));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->lexerContext->MakeClass();
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value->SetInverse();
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value->AddSymbol(context->fromr);
    }
    void Prer(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<LexerContext*>(context->lexerContext)));
    }
    void Postr(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromr_value = std::move(stack.top());
            context->fromr = *static_cast<soulng::parsing::ValueObject<Symbol*>*>(fromr_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): lexerContext(), value(), fromr() {}
        LexerContext* lexerContext;
        Class* value;
        Symbol* fromr;
    };
};

class RegExGrammar::RangeRule : public soulng::parsing::Rule
{
public:
    RangeRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("LexerContext*"), ToUtf32("lexerContext")));
        SetValueTypeName(ToUtf32("Symbol*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> lexerContext_value = std::move(stack.top());
        context->lexerContext = *static_cast<soulng::parsing::ValueObject<LexerContext*>*>(lexerContext_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Symbol*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RangeRule>(this, &RangeRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RangeRule>(this, &RangeRule::A1Action));
        soulng::parsing::NonterminalParser* sNonterminalParser = GetNonterminal(ToUtf32("s"));
        sNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RangeRule>(this, &RangeRule::Posts));
        soulng::parsing::NonterminalParser* eNonterminalParser = GetNonterminal(ToUtf32("e"));
        eNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RangeRule>(this, &RangeRule::Poste));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->lexerContext->MakeRange(context->froms, context->frome);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->lexerContext->MakeChar(context->froms);
    }
    void Posts(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> froms_value = std::move(stack.top());
            context->froms = *static_cast<soulng::parsing::ValueObject<char32_t>*>(froms_value.get());
            stack.pop();
        }
    }
    void Poste(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> frome_value = std::move(stack.top());
            context->frome = *static_cast<soulng::parsing::ValueObject<char32_t>*>(frome_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): lexerContext(), value(), froms(), frome() {}
        LexerContext* lexerContext;
        Symbol* value;
        char32_t froms;
        char32_t frome;
    };
};

class RegExGrammar::CharRule : public soulng::parsing::Rule
{
public:
    CharRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("char32_t"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<char32_t>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CharRule>(this, &CharRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CharRule>(this, &CharRule::A1Action));
        soulng::parsing::NonterminalParser* escNonterminalParser = GetNonterminal(ToUtf32("esc"));
        escNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<CharRule>(this, &CharRule::Postesc));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromesc;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = *matchBegin;
    }
    void Postesc(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromesc_value = std::move(stack.top());
            context->fromesc = *static_cast<soulng::parsing::ValueObject<char32_t>*>(fromesc_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromesc() {}
        char32_t value;
        char32_t fromesc;
    };
};

class RegExGrammar::EscapeRule : public soulng::parsing::Rule
{
public:
    EscapeRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("char32_t"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<char32_t>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<EscapeRule>(this, &EscapeRule::A0Action));
        soulng::parsing::NonterminalParser* escapeNonterminalParser = GetNonterminal(ToUtf32("escape"));
        escapeNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<EscapeRule>(this, &EscapeRule::Postescape));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromescape;
    }
    void Postescape(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromescape_value = std::move(stack.top());
            context->fromescape = *static_cast<soulng::parsing::ValueObject<char32_t>*>(fromescape_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromescape() {}
        char32_t value;
        char32_t fromescape;
    };
};

void RegExGrammar::GetReferencedGrammars()
{
    soulng::parsing::ParsingDomain* pd = GetParsingDomain();
    soulng::parsing::Grammar* grammar0 = pd->GetGrammar(ToUtf32("soulng.parsing.stdlib"));
    if (!grammar0)
    {
        grammar0 = soulng::parsing::stdlib::Create(pd);
    }
    AddGrammarReference(grammar0);
}

void RegExGrammar::CreateRules()
{
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("escape"), this, ToUtf32("soulng.parsing.stdlib.escape")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("identifier"), this, ToUtf32("soulng.parsing.stdlib.identifier")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("int"), this, ToUtf32("soulng.parsing.stdlib.int")));
    AddRule(new RegExRule(ToUtf32("RegEx"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::NonterminalParser(ToUtf32("Alternative"), ToUtf32("Alternative"), 1))));
    AddRule(new AlternativeRule(ToUtf32("Alternative"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("Catenation"), 1)),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::CharParser('|'),
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("right"), ToUtf32("Catenation"), 1)))))))));
    AddRule(new CatenationRule(ToUtf32("Catenation"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("Repetition"), 1)),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::ActionParser(ToUtf32("A1"),
                        new soulng::parsing::NonterminalParser(ToUtf32("right"), ToUtf32("Repetition"), 1)))))));
    AddRule(new RepetitionRule(ToUtf32("Repetition"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("Primary"), 1)),
            new soulng::parsing::OptionalParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::AlternativeParser(
                        new soulng::parsing::AlternativeParser(
                            new soulng::parsing::ActionParser(ToUtf32("A1"),
                                new soulng::parsing::CharParser('*')),
                            new soulng::parsing::ActionParser(ToUtf32("A2"),
                                new soulng::parsing::CharParser('+'))),
                        new soulng::parsing::ActionParser(ToUtf32("A3"),
                            new soulng::parsing::CharParser('?'))))))));
    AddRule(new PrimaryRule(ToUtf32("Primary"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::AlternativeParser(
                        new soulng::parsing::AlternativeParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::SequenceParser(
                                    new soulng::parsing::CharParser('('),
                                    new soulng::parsing::ActionParser(ToUtf32("A0"),
                                        new soulng::parsing::ExpectationParser(
                                            new soulng::parsing::NonterminalParser(ToUtf32("alt"), ToUtf32("Alternative"), 1)))),
                                new soulng::parsing::ExpectationParser(
                                    new soulng::parsing::CharParser(')'))),
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::SequenceParser(
                                    new soulng::parsing::CharParser('{'),
                                    new soulng::parsing::ActionParser(ToUtf32("A1"),
                                        new soulng::parsing::ExpectationParser(
                                            new soulng::parsing::NonterminalParser(ToUtf32("id"), ToUtf32("identifier"), 0)))),
                                new soulng::parsing::ExpectationParser(
                                    new soulng::parsing::CharParser('}')))),
                        new soulng::parsing::ActionParser(ToUtf32("A2"),
                            new soulng::parsing::NonterminalParser(ToUtf32("Class"), ToUtf32("Class"), 1))),
                    new soulng::parsing::ActionParser(ToUtf32("A3"),
                        new soulng::parsing::NonterminalParser(ToUtf32("esc"), ToUtf32("Escape"), 0))),
                new soulng::parsing::ActionParser(ToUtf32("A4"),
                    new soulng::parsing::CharParser('.'))),
            new soulng::parsing::ActionParser(ToUtf32("A5"),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::DifferenceParser(
                        new soulng::parsing::AnyCharParser(),
                        new soulng::parsing::CharSetParser(ToUtf32("*+?|)}"))))))));
    AddRule(new ClassRule(ToUtf32("Class"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::ActionParser(ToUtf32("A0"),
                    new soulng::parsing::CharParser('[')),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::OptionalParser(
                            new soulng::parsing::GroupingParser(
                                new soulng::parsing::ActionParser(ToUtf32("A1"),
                                    new soulng::parsing::CharParser('^')))),
                        new soulng::parsing::KleeneStarParser(
                            new soulng::parsing::GroupingParser(
                                new soulng::parsing::ActionParser(ToUtf32("A2"),
                                    new soulng::parsing::NonterminalParser(ToUtf32("r"), ToUtf32("Range"), 1))))))),
            new soulng::parsing::ExpectationParser(
                new soulng::parsing::CharParser(']')))));
    AddRule(new RangeRule(ToUtf32("Range"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::NonterminalParser(ToUtf32("s"), ToUtf32("Char"), 0),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::CharParser('-'),
                        new soulng::parsing::ActionParser(ToUtf32("A0"),
                            new soulng::parsing::NonterminalParser(ToUtf32("e"), ToUtf32("Char"), 0))),
                    new soulng::parsing::ActionParser(ToUtf32("A1"),
                        new soulng::parsing::EmptyParser()))))));
    AddRule(new CharRule(ToUtf32("Char"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("esc"), ToUtf32("Escape"), 0)),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::DifferenceParser(
                        new soulng::parsing::AnyCharParser(),
                        new soulng::parsing::CharParser(']')))))));
    AddRule(new EscapeRule(ToUtf32("Escape"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::NonterminalParser(ToUtf32("escape"), ToUtf32("escape"), 0))));
}

} } // namespace soulng.lexergen
