#include "Primary.hpp"
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
#include <soulng/code/Expression.hpp>
#include <soulng/code/Statement.hpp>
#include <soulng/syntax/Primitive.hpp>
#include <soulng/syntax/Composite.hpp>
#include <soulng/syntax/Element.hpp>
#include <soulng/parsing/Nonterminal.hpp>
#include <soulng/codedom/Statement.hpp>

namespace soulng { namespace syntax {

using namespace soulng::code;
using namespace soulng::parsing;
using namespace soulng::util;
using namespace soulng::unicode;

Primary* Primary::Create()
{
    return Create(new soulng::parsing::ParsingDomain());
}

Primary* Primary::Create(soulng::parsing::ParsingDomain* parsingDomain)
{
    RegisterParsingDomain(parsingDomain);
    Primary* grammar(new Primary(parsingDomain));
    parsingDomain->AddGrammar(grammar);
    grammar->CreateRules();
    grammar->Link();
    return grammar;
}

Primary::Primary(soulng::parsing::ParsingDomain* parsingDomain_): soulng::parsing::Grammar(ToUtf32("Primary"), parsingDomain_->GetNamespaceScope(ToUtf32("soulng.syntax")), parsingDomain_)
{
    SetOwner(0);
}

soulng::parsing::Parser* Primary::Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName, soulng::parsing::Scope* enclosingScope)
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
    stack.push(std::unique_ptr<soulng::parsing::Object>(new ValueObject<soulng::parsing::Scope*>(enclosingScope)));
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
    soulng::parsing::Parser* result = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(value.get());
    stack.pop();
    return result;
}

class Primary::PrimaryRule : public soulng::parsing::Rule
{
public:
    PrimaryRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsing::Scope*"), ToUtf32("enclosingScope")));
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> enclosingScope_value = std::move(stack.top());
        context->enclosingScope = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Scope*>*>(enclosingScope_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
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
        soulng::parsing::NonterminalParser* ruleCallNonterminalParser = GetNonterminal(ToUtf32("RuleCall"));
        ruleCallNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimaryRule>(this, &PrimaryRule::PostRuleCall));
        soulng::parsing::NonterminalParser* primitiveNonterminalParser = GetNonterminal(ToUtf32("Primitive"));
        primitiveNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimaryRule>(this, &PrimaryRule::PostPrimitive));
        soulng::parsing::NonterminalParser* groupingNonterminalParser = GetNonterminal(ToUtf32("Grouping"));
        groupingNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<PrimaryRule>(this, &PrimaryRule::PreGrouping));
        groupingNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimaryRule>(this, &PrimaryRule::PostGrouping));
        soulng::parsing::NonterminalParser* tokenNonterminalParser = GetNonterminal(ToUtf32("Token"));
        tokenNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<PrimaryRule>(this, &PrimaryRule::PreToken));
        tokenNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimaryRule>(this, &PrimaryRule::PostToken));
        soulng::parsing::NonterminalParser* expectationNonterminalParser = GetNonterminal(ToUtf32("Expectation"));
        expectationNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<PrimaryRule>(this, &PrimaryRule::PreExpectation));
        expectationNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimaryRule>(this, &PrimaryRule::PostExpectation));
        soulng::parsing::NonterminalParser* actionNonterminalParser = GetNonterminal(ToUtf32("Action"));
        actionNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<PrimaryRule>(this, &PrimaryRule::PreAction));
        actionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimaryRule>(this, &PrimaryRule::PostAction));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromRuleCall;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromPrimitive;
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromGrouping;
    }
    void A3Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromToken;
    }
    void A4Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromExpectation;
    }
    void A5Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromAction;
    }
    void PostRuleCall(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromRuleCall_value = std::move(stack.top());
            context->fromRuleCall = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromRuleCall_value.get());
            stack.pop();
        }
    }
    void PostPrimitive(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromPrimitive_value = std::move(stack.top());
            context->fromPrimitive = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromPrimitive_value.get());
            stack.pop();
        }
    }
    void PreGrouping(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Scope*>(context->enclosingScope)));
    }
    void PostGrouping(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromGrouping_value = std::move(stack.top());
            context->fromGrouping = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromGrouping_value.get());
            stack.pop();
        }
    }
    void PreToken(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Scope*>(context->enclosingScope)));
    }
    void PostToken(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromToken_value = std::move(stack.top());
            context->fromToken = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromToken_value.get());
            stack.pop();
        }
    }
    void PreExpectation(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
    }
    void PostExpectation(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromExpectation_value = std::move(stack.top());
            context->fromExpectation = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromExpectation_value.get());
            stack.pop();
        }
    }
    void PreAction(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
    }
    void PostAction(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromAction_value = std::move(stack.top());
            context->fromAction = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromAction_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): enclosingScope(), value(), fromRuleCall(), fromPrimitive(), fromGrouping(), fromToken(), fromExpectation(), fromAction() {}
        soulng::parsing::Scope* enclosingScope;
        soulng::parsing::Parser* value;
        soulng::parsing::Parser* fromRuleCall;
        soulng::parsing::Parser* fromPrimitive;
        soulng::parsing::Parser* fromGrouping;
        soulng::parsing::Parser* fromToken;
        soulng::parsing::Parser* fromExpectation;
        soulng::parsing::Parser* fromAction;
    };
};

class Primary::RuleCallRule : public soulng::parsing::Rule
{
public:
    RuleCallRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RuleCallRule>(this, &RuleCallRule::A0Action));
        soulng::parsing::NonterminalParser* ntWithArgsNonterminalParser = GetNonterminal(ToUtf32("ntWithArgs"));
        ntWithArgsNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleCallRule>(this, &RuleCallRule::PostntWithArgs));
        soulng::parsing::NonterminalParser* expressionListNonterminalParser = GetNonterminal(ToUtf32("ExpressionList"));
        expressionListNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleCallRule>(this, &RuleCallRule::PostExpressionList));
        soulng::parsing::NonterminalParser* ntNonterminalParser = GetNonterminal(ToUtf32("nt"));
        ntNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleCallRule>(this, &RuleCallRule::Postnt));
        soulng::parsing::NonterminalParser* aliasNonterminalParser = GetNonterminal(ToUtf32("Alias"));
        aliasNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleCallRule>(this, &RuleCallRule::PostAlias));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::u32string ruleName;
        if (!context->fromntWithArgs.empty())
        {
            ruleName = context->fromntWithArgs;
        }
        else
        {
            ruleName = context->fromnt;
        }
        std::u32string alias = context->fromAlias;
        std::u32string name = !alias.empty() ? alias : ruleName;
        NonterminalParser * parser(new NonterminalParser(name, ruleName));
        parser->SetSpan(span);
        if (!context->fromExpressionList.empty())
        {
            parser->SetArguments(context->fromExpressionList);
        }
        context->value = parser;
    }
    void PostntWithArgs(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromntWithArgs_value = std::move(stack.top());
            context->fromntWithArgs = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromntWithArgs_value.get());
            stack.pop();
        }
    }
    void PostExpressionList(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromExpressionList_value = std::move(stack.top());
            context->fromExpressionList = *static_cast<soulng::parsing::ValueObject<std::vector<soulng::codedom::CppObject*>>*>(fromExpressionList_value.get());
            stack.pop();
        }
    }
    void Postnt(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromnt_value = std::move(stack.top());
            context->fromnt = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromnt_value.get());
            stack.pop();
        }
    }
    void PostAlias(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromAlias_value = std::move(stack.top());
            context->fromAlias = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromAlias_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromntWithArgs(), fromExpressionList(), fromnt(), fromAlias() {}
        soulng::parsing::Parser* value;
        std::u32string fromntWithArgs;
        std::vector<soulng::codedom::CppObject*> fromExpressionList;
        std::u32string fromnt;
        std::u32string fromAlias;
    };
};

class Primary::NonterminalRule : public soulng::parsing::Rule
{
public:
    NonterminalRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
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
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NonterminalRule>(this, &NonterminalRule::A0Action));
        soulng::parsing::NonterminalParser* identifierNonterminalParser = GetNonterminal(ToUtf32("Identifier"));
        identifierNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<NonterminalRule>(this, &NonterminalRule::PostIdentifier));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromIdentifier;
    }
    void PostIdentifier(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromIdentifier_value = std::move(stack.top());
            context->fromIdentifier = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromIdentifier_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromIdentifier() {}
        std::u32string value;
        std::u32string fromIdentifier;
    };
};

class Primary::AliasRule : public soulng::parsing::Rule
{
public:
    AliasRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
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
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<AliasRule>(this, &AliasRule::A0Action));
        soulng::parsing::NonterminalParser* identifierNonterminalParser = GetNonterminal(ToUtf32("Identifier"));
        identifierNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<AliasRule>(this, &AliasRule::PostIdentifier));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromIdentifier;
    }
    void PostIdentifier(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromIdentifier_value = std::move(stack.top());
            context->fromIdentifier = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromIdentifier_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromIdentifier() {}
        std::u32string value;
        std::u32string fromIdentifier;
    };
};

class Primary::GroupingRule : public soulng::parsing::Rule
{
public:
    GroupingRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsing::Scope*"), ToUtf32("enclosingScope")));
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> enclosingScope_value = std::move(stack.top());
        context->enclosingScope = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Scope*>*>(enclosingScope_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<GroupingRule>(this, &GroupingRule::A0Action));
        soulng::parsing::NonterminalParser* alternativeNonterminalParser = GetNonterminal(ToUtf32("Alternative"));
        alternativeNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<GroupingRule>(this, &GroupingRule::PreAlternative));
        alternativeNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<GroupingRule>(this, &GroupingRule::PostAlternative));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new GroupingParser(context->fromAlternative);
    }
    void PreAlternative(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Scope*>(context->enclosingScope)));
    }
    void PostAlternative(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromAlternative_value = std::move(stack.top());
            context->fromAlternative = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromAlternative_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): enclosingScope(), value(), fromAlternative() {}
        soulng::parsing::Scope* enclosingScope;
        soulng::parsing::Parser* value;
        soulng::parsing::Parser* fromAlternative;
    };
};

class Primary::TokenRule : public soulng::parsing::Rule
{
public:
    TokenRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsing::Scope*"), ToUtf32("enclosingScope")));
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> enclosingScope_value = std::move(stack.top());
        context->enclosingScope = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Scope*>*>(enclosingScope_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TokenRule>(this, &TokenRule::A0Action));
        soulng::parsing::NonterminalParser* alternativeNonterminalParser = GetNonterminal(ToUtf32("Alternative"));
        alternativeNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<TokenRule>(this, &TokenRule::PreAlternative));
        alternativeNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<TokenRule>(this, &TokenRule::PostAlternative));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new TokenParser(context->fromAlternative);
    }
    void PreAlternative(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Scope*>(context->enclosingScope)));
    }
    void PostAlternative(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromAlternative_value = std::move(stack.top());
            context->fromAlternative = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromAlternative_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): enclosingScope(), value(), fromAlternative() {}
        soulng::parsing::Scope* enclosingScope;
        soulng::parsing::Parser* value;
        soulng::parsing::Parser* fromAlternative;
    };
};

class Primary::ExpectationRule : public soulng::parsing::Rule
{
public:
    ExpectationRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsing::Parser*"), ToUtf32("child")));
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> child_value = std::move(stack.top());
        context->child = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(child_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ExpectationRule>(this, &ExpectationRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new ExpectationParser(context->child);
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): child(), value() {}
        soulng::parsing::Parser* child;
        soulng::parsing::Parser* value;
    };
};

class Primary::ActionRule : public soulng::parsing::Rule
{
public:
    ActionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsing::Parser*"), ToUtf32("child")));
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> child_value = std::move(stack.top());
        context->child = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(child_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ActionRule>(this, &ActionRule::A0Action));
        soulng::parsing::NonterminalParser* actionNonterminalParser = GetNonterminal(ToUtf32("action"));
        actionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ActionRule>(this, &ActionRule::Postaction));
        soulng::parsing::NonterminalParser* failureActionNonterminalParser = GetNonterminal(ToUtf32("failureAction"));
        failureActionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ActionRule>(this, &ActionRule::PostfailureAction));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new ActionParser(U"", context->fromaction, context->fromfailureAction, context->child);
    }
    void Postaction(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromaction_value = std::move(stack.top());
            context->fromaction = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CompoundStatement*>*>(fromaction_value.get());
            stack.pop();
        }
    }
    void PostfailureAction(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromfailureAction_value = std::move(stack.top());
            context->fromfailureAction = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CompoundStatement*>*>(fromfailureAction_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): child(), value(), fromaction(), fromfailureAction() {}
        soulng::parsing::Parser* child;
        soulng::parsing::Parser* value;
        soulng::codedom::CompoundStatement* fromaction;
        soulng::codedom::CompoundStatement* fromfailureAction;
    };
};

void Primary::GetReferencedGrammars()
{
    soulng::parsing::ParsingDomain* pd = GetParsingDomain();
    soulng::parsing::Grammar* grammar0 = pd->GetGrammar(ToUtf32("soulng.code.Expression"));
    if (!grammar0)
    {
        grammar0 = soulng::code::Expression::Create(pd);
    }
    AddGrammarReference(grammar0);
    soulng::parsing::Grammar* grammar1 = pd->GetGrammar(ToUtf32("soulng.syntax.Composite"));
    if (!grammar1)
    {
        grammar1 = soulng::syntax::Composite::Create(pd);
    }
    AddGrammarReference(grammar1);
    soulng::parsing::Grammar* grammar2 = pd->GetGrammar(ToUtf32("soulng.syntax.Element"));
    if (!grammar2)
    {
        grammar2 = soulng::syntax::Element::Create(pd);
    }
    AddGrammarReference(grammar2);
    soulng::parsing::Grammar* grammar3 = pd->GetGrammar(ToUtf32("soulng.code.Statement"));
    if (!grammar3)
    {
        grammar3 = soulng::code::Statement::Create(pd);
    }
    AddGrammarReference(grammar3);
    soulng::parsing::Grammar* grammar4 = pd->GetGrammar(ToUtf32("soulng.syntax.Primitive"));
    if (!grammar4)
    {
        grammar4 = soulng::syntax::Primitive::Create(pd);
    }
    AddGrammarReference(grammar4);
}

void Primary::CreateRules()
{
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("ExpressionList"), this, ToUtf32("soulng.code.Expression.ExpressionList")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("Alternative"), this, ToUtf32("Composite.Alternative")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("Identifier"), this, ToUtf32("Element.Identifier")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("Primitive"), this, ToUtf32("Primitive.Primitive")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("CompoundStatement"), this, ToUtf32("soulng.code.Statement.CompoundStatement")));
    AddRule(new PrimaryRule(ToUtf32("Primary"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::AlternativeParser(
                        new soulng::parsing::AlternativeParser(
                            new soulng::parsing::AlternativeParser(
                                new soulng::parsing::ActionParser(ToUtf32("A0"),
                                    new soulng::parsing::NonterminalParser(ToUtf32("RuleCall"), ToUtf32("RuleCall"), 0)),
                                new soulng::parsing::ActionParser(ToUtf32("A1"),
                                    new soulng::parsing::NonterminalParser(ToUtf32("Primitive"), ToUtf32("Primitive"), 0))),
                            new soulng::parsing::ActionParser(ToUtf32("A2"),
                                new soulng::parsing::NonterminalParser(ToUtf32("Grouping"), ToUtf32("Grouping"), 1))),
                        new soulng::parsing::ActionParser(ToUtf32("A3"),
                            new soulng::parsing::NonterminalParser(ToUtf32("Token"), ToUtf32("Token"), 1)))),
                new soulng::parsing::OptionalParser(
                    new soulng::parsing::GroupingParser(
                        new soulng::parsing::ActionParser(ToUtf32("A4"),
                            new soulng::parsing::NonterminalParser(ToUtf32("Expectation"), ToUtf32("Expectation"), 1))))),
            new soulng::parsing::OptionalParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::ActionParser(ToUtf32("A5"),
                        new soulng::parsing::NonterminalParser(ToUtf32("Action"), ToUtf32("Action"), 1)))))));
    AddRule(new RuleCallRule(ToUtf32("RuleCall"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::GroupingParser(
                        new soulng::parsing::AlternativeParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::SequenceParser(
                                    new soulng::parsing::TokenParser(
                                        new soulng::parsing::SequenceParser(
                                            new soulng::parsing::NonterminalParser(ToUtf32("ntWithArgs"), ToUtf32("Nonterminal"), 0),
                                            new soulng::parsing::CharParser('('))),
                                    new soulng::parsing::NonterminalParser(ToUtf32("ExpressionList"), ToUtf32("ExpressionList"), 0)),
                                new soulng::parsing::CharParser(')')),
                            new soulng::parsing::NonterminalParser(ToUtf32("nt"), ToUtf32("Nonterminal"), 0))),
                    new soulng::parsing::OptionalParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("Alias"), ToUtf32("Alias"), 0)))))));
    AddRule(new NonterminalRule(ToUtf32("Nonterminal"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::NonterminalParser(ToUtf32("Identifier"), ToUtf32("Identifier"), 0))));
    AddRule(new AliasRule(ToUtf32("Alias"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::CharParser(':'),
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::ExpectationParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("Identifier"), ToUtf32("Identifier"), 0))))));
    AddRule(new GroupingRule(ToUtf32("Grouping"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::CharParser('('),
                new soulng::parsing::ExpectationParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("Alternative"), ToUtf32("Alternative"), 1))),
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::ExpectationParser(
                    new soulng::parsing::CharParser(')'))))));
    AddRule(new TokenRule(ToUtf32("Token"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::KeywordParser(ToUtf32("token")),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser('('))),
                new soulng::parsing::ExpectationParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("Alternative"), ToUtf32("Alternative"), 1))),
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::ExpectationParser(
                    new soulng::parsing::CharParser(')'))))));
    AddRule(new ExpectationRule(ToUtf32("Expectation"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::CharParser('!'))));
    AddRule(new ActionRule(ToUtf32("Action"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("action"), ToUtf32("CompoundStatement"), 0),
                    new soulng::parsing::OptionalParser(
                        new soulng::parsing::GroupingParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::CharParser('/'),
                                new soulng::parsing::NonterminalParser(ToUtf32("failureAction"), ToUtf32("CompoundStatement"), 0)))))))));
}

} } // namespace soulng.syntax
