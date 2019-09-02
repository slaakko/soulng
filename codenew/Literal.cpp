#include "Literal.hpp"
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

namespace soulng { namespace code {

using namespace soulng::cppcode;
using namespace soulng::parsing;
using namespace soulng::util;
using namespace soulng::unicode;

Literal* Literal::Create()
{
    return Create(new soulng::parsing::ParsingDomain());
}

Literal* Literal::Create(soulng::parsing::ParsingDomain* parsingDomain)
{
    RegisterParsingDomain(parsingDomain);
    Literal* grammar(new Literal(parsingDomain));
    parsingDomain->AddGrammar(grammar);
    grammar->CreateRules();
    grammar->Link();
    return grammar;
}

Literal::Literal(soulng::parsing::ParsingDomain* parsingDomain_): soulng::parsing::Grammar(ToUtf32("Literal"), parsingDomain_->GetNamespaceScope(ToUtf32("soulng.code")), parsingDomain_)
{
    SetOwner(0);
}

soulng::cppcode::Literal* Literal::Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName)
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
    soulng::cppcode::Literal* result = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::Literal*>*>(value.get());
    stack.pop();
    return result;
}

class Literal::LiteralRule : public soulng::parsing::Rule
{
public:
    LiteralRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::Literal*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::Literal*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<LiteralRule>(this, &LiteralRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<LiteralRule>(this, &LiteralRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<LiteralRule>(this, &LiteralRule::A2Action));
        soulng::parsing::ActionParser* a3ActionParser = GetAction(ToUtf32("A3"));
        a3ActionParser->SetAction(new soulng::parsing::MemberParsingAction<LiteralRule>(this, &LiteralRule::A3Action));
        soulng::parsing::ActionParser* a4ActionParser = GetAction(ToUtf32("A4"));
        a4ActionParser->SetAction(new soulng::parsing::MemberParsingAction<LiteralRule>(this, &LiteralRule::A4Action));
        soulng::parsing::ActionParser* a5ActionParser = GetAction(ToUtf32("A5"));
        a5ActionParser->SetAction(new soulng::parsing::MemberParsingAction<LiteralRule>(this, &LiteralRule::A5Action));
        soulng::parsing::NonterminalParser* integerLiteralNonterminalParser = GetNonterminal(ToUtf32("IntegerLiteral"));
        integerLiteralNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<LiteralRule>(this, &LiteralRule::PostIntegerLiteral));
        soulng::parsing::NonterminalParser* characterLiteralNonterminalParser = GetNonterminal(ToUtf32("CharacterLiteral"));
        characterLiteralNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<LiteralRule>(this, &LiteralRule::PostCharacterLiteral));
        soulng::parsing::NonterminalParser* floatingLiteralNonterminalParser = GetNonterminal(ToUtf32("FloatingLiteral"));
        floatingLiteralNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<LiteralRule>(this, &LiteralRule::PostFloatingLiteral));
        soulng::parsing::NonterminalParser* stringLiteralNonterminalParser = GetNonterminal(ToUtf32("StringLiteral"));
        stringLiteralNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<LiteralRule>(this, &LiteralRule::PostStringLiteral));
        soulng::parsing::NonterminalParser* booleanLiteralNonterminalParser = GetNonterminal(ToUtf32("BooleanLiteral"));
        booleanLiteralNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<LiteralRule>(this, &LiteralRule::PostBooleanLiteral));
        soulng::parsing::NonterminalParser* pointerLiteralNonterminalParser = GetNonterminal(ToUtf32("PointerLiteral"));
        pointerLiteralNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<LiteralRule>(this, &LiteralRule::PostPointerLiteral));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromIntegerLiteral;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromCharacterLiteral;
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromFloatingLiteral;
    }
    void A3Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromStringLiteral;
    }
    void A4Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromBooleanLiteral;
    }
    void A5Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromPointerLiteral;
    }
    void PostIntegerLiteral(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromIntegerLiteral_value = std::move(stack.top());
            context->fromIntegerLiteral = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::Literal*>*>(fromIntegerLiteral_value.get());
            stack.pop();
        }
    }
    void PostCharacterLiteral(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromCharacterLiteral_value = std::move(stack.top());
            context->fromCharacterLiteral = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::Literal*>*>(fromCharacterLiteral_value.get());
            stack.pop();
        }
    }
    void PostFloatingLiteral(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromFloatingLiteral_value = std::move(stack.top());
            context->fromFloatingLiteral = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::Literal*>*>(fromFloatingLiteral_value.get());
            stack.pop();
        }
    }
    void PostStringLiteral(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromStringLiteral_value = std::move(stack.top());
            context->fromStringLiteral = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::Literal*>*>(fromStringLiteral_value.get());
            stack.pop();
        }
    }
    void PostBooleanLiteral(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromBooleanLiteral_value = std::move(stack.top());
            context->fromBooleanLiteral = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::Literal*>*>(fromBooleanLiteral_value.get());
            stack.pop();
        }
    }
    void PostPointerLiteral(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromPointerLiteral_value = std::move(stack.top());
            context->fromPointerLiteral = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::Literal*>*>(fromPointerLiteral_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromIntegerLiteral(), fromCharacterLiteral(), fromFloatingLiteral(), fromStringLiteral(), fromBooleanLiteral(), fromPointerLiteral() {}
        soulng::cppcode::Literal* value;
        soulng::cppcode::Literal* fromIntegerLiteral;
        soulng::cppcode::Literal* fromCharacterLiteral;
        soulng::cppcode::Literal* fromFloatingLiteral;
        soulng::cppcode::Literal* fromStringLiteral;
        soulng::cppcode::Literal* fromBooleanLiteral;
        soulng::cppcode::Literal* fromPointerLiteral;
    };
};

class Literal::IntegerLiteralRule : public soulng::parsing::Rule
{
public:
    IntegerLiteralRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::Literal*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::Literal*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<IntegerLiteralRule>(this, &IntegerLiteralRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<IntegerLiteralRule>(this, &IntegerLiteralRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<IntegerLiteralRule>(this, &IntegerLiteralRule::A2Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::cppcode::Literal(std::u32string(matchBegin, matchEnd));
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::cppcode::Literal(std::u32string(matchBegin, matchEnd));
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::cppcode::Literal(std::u32string(matchBegin, matchEnd));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::cppcode::Literal* value;
    };
};

class Literal::CharacterLiteralRule : public soulng::parsing::Rule
{
public:
    CharacterLiteralRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::Literal*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::Literal*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CharacterLiteralRule>(this, &CharacterLiteralRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CharacterLiteralRule>(this, &CharacterLiteralRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CharacterLiteralRule>(this, &CharacterLiteralRule::A2Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::cppcode::Literal(std::u32string(matchBegin, matchEnd));
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::cppcode::Literal(std::u32string(matchBegin, matchEnd));
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::cppcode::Literal(std::u32string(matchBegin, matchEnd));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::cppcode::Literal* value;
    };
};

class Literal::CCharSequenceRule : public soulng::parsing::Rule
{
public:
    CCharSequenceRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("std::u32string"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<std::u32string>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CCharSequenceRule>(this, &CCharSequenceRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = std::u32string(matchBegin, matchEnd);
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        std::u32string value;
    };
};

class Literal::FloatingLiteralRule : public soulng::parsing::Rule
{
public:
    FloatingLiteralRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::Literal*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::Literal*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<FloatingLiteralRule>(this, &FloatingLiteralRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<FloatingLiteralRule>(this, &FloatingLiteralRule::A1Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::cppcode::Literal(std::u32string(matchBegin, matchEnd));
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::cppcode::Literal(std::u32string(matchBegin, matchEnd));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::cppcode::Literal* value;
    };
};

class Literal::StringLiteralRule : public soulng::parsing::Rule
{
public:
    StringLiteralRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::Literal*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::Literal*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<StringLiteralRule>(this, &StringLiteralRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::cppcode::Literal(std::u32string(matchBegin, matchEnd));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::cppcode::Literal* value;
    };
};

class Literal::BooleanLiteralRule : public soulng::parsing::Rule
{
public:
    BooleanLiteralRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::Literal*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::Literal*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<BooleanLiteralRule>(this, &BooleanLiteralRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<BooleanLiteralRule>(this, &BooleanLiteralRule::A1Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::cppcode::Literal(U"true");
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::cppcode::Literal(U"false");
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::cppcode::Literal* value;
    };
};

class Literal::PointerLiteralRule : public soulng::parsing::Rule
{
public:
    PointerLiteralRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::Literal*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::Literal*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PointerLiteralRule>(this, &PointerLiteralRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::cppcode::Literal(U"nullptr");
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::cppcode::Literal* value;
    };
};

void Literal::GetReferencedGrammars()
{
}

void Literal::CreateRules()
{
    AddRule(new LiteralRule(ToUtf32("Literal"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::AlternativeParser(
                        new soulng::parsing::AlternativeParser(
                            new soulng::parsing::ActionParser(ToUtf32("A0"),
                                new soulng::parsing::NonterminalParser(ToUtf32("IntegerLiteral"), ToUtf32("IntegerLiteral"), 0)),
                            new soulng::parsing::ActionParser(ToUtf32("A1"),
                                new soulng::parsing::NonterminalParser(ToUtf32("CharacterLiteral"), ToUtf32("CharacterLiteral"), 0))),
                        new soulng::parsing::ActionParser(ToUtf32("A2"),
                            new soulng::parsing::NonterminalParser(ToUtf32("FloatingLiteral"), ToUtf32("FloatingLiteral"), 0))),
                    new soulng::parsing::ActionParser(ToUtf32("A3"),
                        new soulng::parsing::NonterminalParser(ToUtf32("StringLiteral"), ToUtf32("StringLiteral"), 0))),
                new soulng::parsing::ActionParser(ToUtf32("A4"),
                    new soulng::parsing::NonterminalParser(ToUtf32("BooleanLiteral"), ToUtf32("BooleanLiteral"), 0))),
            new soulng::parsing::ActionParser(ToUtf32("A5"),
                new soulng::parsing::NonterminalParser(ToUtf32("PointerLiteral"), ToUtf32("PointerLiteral"), 0)))));
    AddRule(new IntegerLiteralRule(ToUtf32("IntegerLiteral"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::ActionParser(ToUtf32("A0"),
                    new soulng::parsing::TokenParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("dl"), ToUtf32("DecimalLiteral"), 0),
                            new soulng::parsing::OptionalParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("is1"), ToUtf32("IntegerSuffix"), 0))))),
                new soulng::parsing::ActionParser(ToUtf32("A1"),
                    new soulng::parsing::TokenParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("ol"), ToUtf32("OctalLiteral"), 0),
                            new soulng::parsing::OptionalParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("is2"), ToUtf32("IntegerSuffix"), 0)))))),
            new soulng::parsing::ActionParser(ToUtf32("A2"),
                new soulng::parsing::TokenParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("hl"), ToUtf32("HexadecimalLiteral"), 0),
                        new soulng::parsing::OptionalParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("is3"), ToUtf32("IntegerSuffix"), 0))))))));
    AddRule(new soulng::parsing::Rule(ToUtf32("DecimalLiteral"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::TokenParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::CharSetParser(ToUtf32("1-9")),
                new soulng::parsing::KleeneStarParser(
                    new soulng::parsing::DigitParser())))));
    AddRule(new soulng::parsing::Rule(ToUtf32("OctalLiteral"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::TokenParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::CharParser('0'),
                new soulng::parsing::KleeneStarParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("OctalDigit"), ToUtf32("OctalDigit"), 0))))));
    AddRule(new soulng::parsing::Rule(ToUtf32("OctalDigit"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::CharSetParser(ToUtf32("0-7"))));
    AddRule(new soulng::parsing::Rule(ToUtf32("HexadecimalLiteral"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::TokenParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::AlternativeParser(
                        new soulng::parsing::StringParser(ToUtf32("0x")),
                        new soulng::parsing::StringParser(ToUtf32("0X")))),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::PositiveParser(
                        new soulng::parsing::HexDigitParser()))))));
    AddRule(new soulng::parsing::Rule(ToUtf32("IntegerSuffix"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::TokenParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("UnsignedSuffix"), ToUtf32("UnsignedSuffix"), 0),
                        new soulng::parsing::OptionalParser(
                            new soulng::parsing::GroupingParser(
                                new soulng::parsing::AlternativeParser(
                                    new soulng::parsing::NonterminalParser(ToUtf32("LongLongSuffix"), ToUtf32("LongLongSuffix"), 0),
                                    new soulng::parsing::NonterminalParser(ToUtf32("LongSuffix"), ToUtf32("LongSuffix"), 0)))))),
                new soulng::parsing::TokenParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("LongLongSuffix"), ToUtf32("LongLongSuffix"), 0),
                        new soulng::parsing::OptionalParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("UnsignedSuffix"), ToUtf32("UnsignedSuffix"), 0))))),
            new soulng::parsing::TokenParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("LongSuffix"), ToUtf32("LongSuffix"), 0),
                    new soulng::parsing::OptionalParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("UnsignedSuffix"), ToUtf32("UnsignedSuffix"), 0)))))));
    AddRule(new soulng::parsing::Rule(ToUtf32("UnsignedSuffix"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::CharParser('u'),
            new soulng::parsing::CharParser('U'))));
    AddRule(new soulng::parsing::Rule(ToUtf32("LongLongSuffix"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::StringParser(ToUtf32("ll")),
            new soulng::parsing::StringParser(ToUtf32("LL")))));
    AddRule(new soulng::parsing::Rule(ToUtf32("LongSuffix"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::CharParser('l'),
            new soulng::parsing::CharParser('L'))));
    AddRule(new CharacterLiteralRule(ToUtf32("CharacterLiteral"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::ActionParser(ToUtf32("A0"),
                    new soulng::parsing::NonterminalParser(ToUtf32("NarrowCharacterLiteral"), ToUtf32("NarrowCharacterLiteral"), 0)),
                new soulng::parsing::ActionParser(ToUtf32("A1"),
                    new soulng::parsing::NonterminalParser(ToUtf32("UniversalCharacterLiteral"), ToUtf32("UniversalCharacterLiteral"), 0))),
            new soulng::parsing::ActionParser(ToUtf32("A2"),
                new soulng::parsing::NonterminalParser(ToUtf32("WideCharacterLiteral"), ToUtf32("WideCharacterLiteral"), 0)))));
    AddRule(new soulng::parsing::Rule(ToUtf32("NarrowCharacterLiteral"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::TokenParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::CharParser('\''),
                    new soulng::parsing::NonterminalParser(ToUtf32("CCharSequence"), ToUtf32("CCharSequence"), 0)),
                new soulng::parsing::CharParser('\'')))));
    AddRule(new soulng::parsing::Rule(ToUtf32("UniversalCharacterLiteral"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::TokenParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::CharParser('u'),
                            new soulng::parsing::CharParser('\'')),
                        new soulng::parsing::NonterminalParser(ToUtf32("cs1"), ToUtf32("CCharSequence"), 0)),
                    new soulng::parsing::CharParser('\''))),
            new soulng::parsing::TokenParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::CharParser('U'),
                            new soulng::parsing::CharParser('\'')),
                        new soulng::parsing::NonterminalParser(ToUtf32("cs2"), ToUtf32("CCharSequence"), 0)),
                    new soulng::parsing::CharParser('\''))))));
    AddRule(new soulng::parsing::Rule(ToUtf32("WideCharacterLiteral"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::TokenParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::CharParser('L'),
                        new soulng::parsing::CharParser('\'')),
                    new soulng::parsing::NonterminalParser(ToUtf32("CCharSequence"), ToUtf32("CCharSequence"), 0)),
                new soulng::parsing::CharParser('\'')))));
    AddRule(new CCharSequenceRule(ToUtf32("CCharSequence"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::TokenParser(
                new soulng::parsing::PositiveParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("CChar"), ToUtf32("CChar"), 0))))));
    AddRule(new soulng::parsing::Rule(ToUtf32("CChar"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::CharSetParser(ToUtf32("\'\\\n"), true),
            new soulng::parsing::NonterminalParser(ToUtf32("EscapeSequence"), ToUtf32("EscapeSequence"), 0))));
    AddRule(new soulng::parsing::Rule(ToUtf32("EscapeSequence"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::NonterminalParser(ToUtf32("SimpleEscapeSequence"), ToUtf32("SimpleEscapeSequence"), 0),
                new soulng::parsing::NonterminalParser(ToUtf32("OctalEscapeSequence"), ToUtf32("OctalEscapeSequence"), 0)),
            new soulng::parsing::NonterminalParser(ToUtf32("HexadecimalEscapeSequence"), ToUtf32("HexadecimalEscapeSequence"), 0))));
    AddRule(new soulng::parsing::Rule(ToUtf32("SimpleEscapeSequence"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::AlternativeParser(
                        new soulng::parsing::AlternativeParser(
                            new soulng::parsing::AlternativeParser(
                                new soulng::parsing::AlternativeParser(
                                    new soulng::parsing::AlternativeParser(
                                        new soulng::parsing::AlternativeParser(
                                            new soulng::parsing::AlternativeParser(
                                                new soulng::parsing::StringParser(ToUtf32("\\\'")),
                                                new soulng::parsing::StringParser(ToUtf32("\\\""))),
                                            new soulng::parsing::StringParser(ToUtf32("\\?"))),
                                        new soulng::parsing::StringParser(ToUtf32("\\\\"))),
                                    new soulng::parsing::StringParser(ToUtf32("\\a"))),
                                new soulng::parsing::StringParser(ToUtf32("\\b"))),
                            new soulng::parsing::StringParser(ToUtf32("\\f"))),
                        new soulng::parsing::StringParser(ToUtf32("\\n"))),
                    new soulng::parsing::StringParser(ToUtf32("\\r"))),
                new soulng::parsing::StringParser(ToUtf32("\\t"))),
            new soulng::parsing::StringParser(ToUtf32("\\v")))));
    AddRule(new soulng::parsing::Rule(ToUtf32("OctalEscapeSequence"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::CharParser('\\'),
                    new soulng::parsing::NonterminalParser(ToUtf32("OctalDigit"), ToUtf32("OctalDigit"), 0)),
                new soulng::parsing::OptionalParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("OctalDigit"), ToUtf32("OctalDigit"), 0))),
            new soulng::parsing::OptionalParser(
                new soulng::parsing::NonterminalParser(ToUtf32("OctalDigit"), ToUtf32("OctalDigit"), 0)))));
    AddRule(new soulng::parsing::Rule(ToUtf32("HexadecimalEscapeSequence"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::StringParser(ToUtf32("\\x")),
            new soulng::parsing::PositiveParser(
                new soulng::parsing::HexDigitParser()))));
    AddRule(new FloatingLiteralRule(ToUtf32("FloatingLiteral"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::TokenParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("FractionalConstant"), ToUtf32("FractionalConstant"), 0),
                            new soulng::parsing::OptionalParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("ExponentPart"), ToUtf32("ExponentPart"), 0))),
                        new soulng::parsing::OptionalParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("FloatingSuffix"), ToUtf32("FloatingSuffix"), 0))))),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::TokenParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("DigitSequence"), ToUtf32("DigitSequence"), 0),
                            new soulng::parsing::NonterminalParser(ToUtf32("ExponentPart"), ToUtf32("ExponentPart"), 0)),
                        new soulng::parsing::OptionalParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("FloatingSuffix"), ToUtf32("FloatingSuffix"), 0))))))));
    AddRule(new soulng::parsing::Rule(ToUtf32("FractionalConstant"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::OptionalParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("DigitSequence"), ToUtf32("DigitSequence"), 0)),
                    new soulng::parsing::CharParser('.')),
                new soulng::parsing::NonterminalParser(ToUtf32("DigitSequence"), ToUtf32("DigitSequence"), 0)),
            new soulng::parsing::SequenceParser(
                new soulng::parsing::NonterminalParser(ToUtf32("DigitSequence"), ToUtf32("DigitSequence"), 0),
                new soulng::parsing::CharParser('.')))));
    AddRule(new soulng::parsing::Rule(ToUtf32("DigitSequence"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::PositiveParser(
            new soulng::parsing::DigitParser())));
    AddRule(new soulng::parsing::Rule(ToUtf32("ExponentPart"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::AlternativeParser(
                        new soulng::parsing::CharParser('e'),
                        new soulng::parsing::CharParser('E'))),
                new soulng::parsing::OptionalParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("Sign"), ToUtf32("Sign"), 0))),
            new soulng::parsing::NonterminalParser(ToUtf32("DigitSequence"), ToUtf32("DigitSequence"), 0))));
    AddRule(new soulng::parsing::Rule(ToUtf32("Sign"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::CharParser('+'),
            new soulng::parsing::CharParser('-'))));
    AddRule(new soulng::parsing::Rule(ToUtf32("FloatingSuffix"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::CharSetParser(ToUtf32("fFlL"))));
    AddRule(new StringLiteralRule(ToUtf32("StringLiteral"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::TokenParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::OptionalParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("EncodingPrefix"), ToUtf32("EncodingPrefix"), 0)),
                            new soulng::parsing::CharParser('\"')),
                        new soulng::parsing::OptionalParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("SCharSequence"), ToUtf32("SCharSequence"), 0))),
                    new soulng::parsing::CharParser('\"'))))));
    AddRule(new soulng::parsing::Rule(ToUtf32("EncodingPrefix"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::StringParser(ToUtf32("u8")),
                    new soulng::parsing::CharParser('u')),
                new soulng::parsing::CharParser('U')),
            new soulng::parsing::CharParser('L'))));
    AddRule(new soulng::parsing::Rule(ToUtf32("SCharSequence"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::GroupingParser(
            new soulng::parsing::PositiveParser(
                new soulng::parsing::NonterminalParser(ToUtf32("SChar"), ToUtf32("SChar"), 0)))));
    AddRule(new soulng::parsing::Rule(ToUtf32("SChar"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::CharSetParser(ToUtf32("\"\\\n"), true),
            new soulng::parsing::NonterminalParser(ToUtf32("EscapeSequence"), ToUtf32("EscapeSequence"), 0))));
    AddRule(new BooleanLiteralRule(ToUtf32("BooleanLiteral"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::KeywordParser(ToUtf32("true"))),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::KeywordParser(ToUtf32("false"))))));
    AddRule(new PointerLiteralRule(ToUtf32("PointerLiteral"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("nullptr")))));
}

} } // namespace soulng.code
