#include "Element.hpp"
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
#include <soulng/parsing/Rule.hpp>
#include <soulng/codedom/Type.hpp>
#include <soulng/code/Declarator.hpp>

namespace soulng { namespace syntax {

using namespace soulng::parsing;
using namespace soulng::util;
using namespace soulng::unicode;

Element* Element::Create()
{
    return Create(new soulng::parsing::ParsingDomain());
}

Element* Element::Create(soulng::parsing::ParsingDomain* parsingDomain)
{
    RegisterParsingDomain(parsingDomain);
    Element* grammar(new Element(parsingDomain));
    parsingDomain->AddGrammar(grammar);
    grammar->CreateRules();
    grammar->Link();
    return grammar;
}

Element::Element(soulng::parsing::ParsingDomain* parsingDomain_): soulng::parsing::Grammar(ToUtf32("Element"), parsingDomain_->GetNamespaceScope(ToUtf32("soulng.syntax")), parsingDomain_)
{
    SetOwner(0);
    keywords0.push_back(ToUtf32("alphabetic"));
    keywords0.push_back(ToUtf32("anychar"));
    keywords0.push_back(ToUtf32("basechar"));
    keywords0.push_back(ToUtf32("cased_letter"));
    keywords0.push_back(ToUtf32("close_punctuation"));
    keywords0.push_back(ToUtf32("connector_punctuation"));
    keywords0.push_back(ToUtf32("control"));
    keywords0.push_back(ToUtf32("currency_symbol"));
    keywords0.push_back(ToUtf32("dash_punctuation"));
    keywords0.push_back(ToUtf32("decimal_number"));
    keywords0.push_back(ToUtf32("digit"));
    keywords0.push_back(ToUtf32("empty"));
    keywords0.push_back(ToUtf32("enclosing_mark"));
    keywords0.push_back(ToUtf32("end"));
    keywords0.push_back(ToUtf32("final_punctuation"));
    keywords0.push_back(ToUtf32("format"));
    keywords0.push_back(ToUtf32("grammar"));
    keywords0.push_back(ToUtf32("graphic"));
    keywords0.push_back(ToUtf32("hexdigit"));
    keywords0.push_back(ToUtf32("idcont"));
    keywords0.push_back(ToUtf32("idstart"));
    keywords0.push_back(ToUtf32("initial_punctuation"));
    keywords0.push_back(ToUtf32("keyword"));
    keywords0.push_back(ToUtf32("keyword_list"));
    keywords0.push_back(ToUtf32("letter"));
    keywords0.push_back(ToUtf32("letter_number"));
    keywords0.push_back(ToUtf32("line_separator"));
    keywords0.push_back(ToUtf32("lower_letter"));
    keywords0.push_back(ToUtf32("mark"));
    keywords0.push_back(ToUtf32("math_symbol"));
    keywords0.push_back(ToUtf32("modifier_letter"));
    keywords0.push_back(ToUtf32("modifier_symbol"));
    keywords0.push_back(ToUtf32("nonspacing_mark"));
    keywords0.push_back(ToUtf32("number"));
    keywords0.push_back(ToUtf32("open_punctuation"));
    keywords0.push_back(ToUtf32("other"));
    keywords0.push_back(ToUtf32("other_letter"));
    keywords0.push_back(ToUtf32("other_number"));
    keywords0.push_back(ToUtf32("other_punctuation"));
    keywords0.push_back(ToUtf32("other_symbol"));
    keywords0.push_back(ToUtf32("paragraph_separator"));
    keywords0.push_back(ToUtf32("private_use"));
    keywords0.push_back(ToUtf32("punctuation"));
    keywords0.push_back(ToUtf32("range"));
    keywords0.push_back(ToUtf32("separator"));
    keywords0.push_back(ToUtf32("skip"));
    keywords0.push_back(ToUtf32("space"));
    keywords0.push_back(ToUtf32("space_separator"));
    keywords0.push_back(ToUtf32("spacing_mark"));
    keywords0.push_back(ToUtf32("start"));
    keywords0.push_back(ToUtf32("surrogate"));
    keywords0.push_back(ToUtf32("symbol"));
    keywords0.push_back(ToUtf32("title_letter"));
    keywords0.push_back(ToUtf32("token"));
    keywords0.push_back(ToUtf32("unassigned"));
    keywords0.push_back(ToUtf32("upper_letter"));
    keywords0.push_back(ToUtf32("using"));
    keywords0.push_back(ToUtf32("value"));
    keywords0.push_back(ToUtf32("var"));
}

void Element::Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName, soulng::parsing::Grammar* grammar)
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
    stack.push(std::unique_ptr<soulng::parsing::Object>(new ValueObject<soulng::parsing::Grammar*>(grammar)));
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
}

class Element::RuleLinkRule : public soulng::parsing::Rule
{
public:
    RuleLinkRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsing::Grammar*"), ToUtf32("grammar")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> grammar_value = std::move(stack.top());
        context->grammar = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Grammar*>*>(grammar_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RuleLinkRule>(this, &RuleLinkRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RuleLinkRule>(this, &RuleLinkRule::A1Action));
        soulng::parsing::NonterminalParser* aliasNameNonterminalParser = GetNonterminal(ToUtf32("aliasName"));
        aliasNameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleLinkRule>(this, &RuleLinkRule::PostaliasName));
        soulng::parsing::NonterminalParser* ruleNameNonterminalParser = GetNonterminal(ToUtf32("ruleName"));
        ruleNameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleLinkRule>(this, &RuleLinkRule::PostruleName));
        soulng::parsing::NonterminalParser* qualified_idNonterminalParser = GetNonterminal(ToUtf32("qualified_id"));
        qualified_idNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleLinkRule>(this, &RuleLinkRule::Postqualified_id));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        RuleLink * link(new RuleLink(context->fromaliasName, context->grammar, context->fromruleName));
        link->SetSpan(span);
        context->grammar->AddRuleLink(link);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        RuleLink * link(new RuleLink(context->grammar, context->fromqualified_id));
        link->SetSpan(span);
        context->grammar->AddRuleLink(link);
    }
    void PostaliasName(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromaliasName_value = std::move(stack.top());
            context->fromaliasName = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromaliasName_value.get());
            stack.pop();
        }
    }
    void PostruleName(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromruleName_value = std::move(stack.top());
            context->fromruleName = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromruleName_value.get());
            stack.pop();
        }
    }
    void Postqualified_id(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromqualified_id_value = std::move(stack.top());
            context->fromqualified_id = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromqualified_id_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): grammar(), fromaliasName(), fromruleName(), fromqualified_id() {}
        soulng::parsing::Grammar* grammar;
        std::u32string fromaliasName;
        std::u32string fromruleName;
        std::u32string fromqualified_id;
    };
};

class Element::SignatureRule : public soulng::parsing::Rule
{
public:
    SignatureRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsing::Rule*"), ToUtf32("rule")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> rule_value = std::move(stack.top());
        context->rule = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Rule*>*>(rule_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::NonterminalParser* parameterListNonterminalParser = GetNonterminal(ToUtf32("ParameterList"));
        parameterListNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<SignatureRule>(this, &SignatureRule::PreParameterList));
        soulng::parsing::NonterminalParser* returnTypeNonterminalParser = GetNonterminal(ToUtf32("ReturnType"));
        returnTypeNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<SignatureRule>(this, &SignatureRule::PreReturnType));
    }
    void PreParameterList(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Rule*>(context->rule)));
    }
    void PreReturnType(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Rule*>(context->rule)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): rule() {}
        soulng::parsing::Rule* rule;
    };
};

class Element::ParameterListRule : public soulng::parsing::Rule
{
public:
    ParameterListRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsing::Rule*"), ToUtf32("rule")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> rule_value = std::move(stack.top());
        context->rule = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Rule*>*>(rule_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::NonterminalParser* variableNonterminalParser = GetNonterminal(ToUtf32("Variable"));
        variableNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<ParameterListRule>(this, &ParameterListRule::PreVariable));
        soulng::parsing::NonterminalParser* parameterNonterminalParser = GetNonterminal(ToUtf32("Parameter"));
        parameterNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<ParameterListRule>(this, &ParameterListRule::PreParameter));
    }
    void PreVariable(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Rule*>(context->rule)));
    }
    void PreParameter(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Rule*>(context->rule)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): rule() {}
        soulng::parsing::Rule* rule;
    };
};

class Element::VariableRule : public soulng::parsing::Rule
{
public:
    VariableRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsing::Rule*"), ToUtf32("rule")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> rule_value = std::move(stack.top());
        context->rule = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Rule*>*>(rule_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<VariableRule>(this, &VariableRule::A0Action));
        soulng::parsing::NonterminalParser* typeIdNonterminalParser = GetNonterminal(ToUtf32("TypeId"));
        typeIdNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<VariableRule>(this, &VariableRule::PostTypeId));
        soulng::parsing::NonterminalParser* declaratorNonterminalParser = GetNonterminal(ToUtf32("Declarator"));
        declaratorNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<VariableRule>(this, &VariableRule::PostDeclarator));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->rule->AddLocalVariable(AttrOrVariable(context->fromTypeId->ToString(), context->fromDeclarator));
        delete context->fromTypeId;
    }
    void PostTypeId(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromTypeId_value = std::move(stack.top());
            context->fromTypeId = *static_cast<soulng::parsing::ValueObject<soulng::codedom::TypeId*>*>(fromTypeId_value.get());
            stack.pop();
        }
    }
    void PostDeclarator(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromDeclarator_value = std::move(stack.top());
            context->fromDeclarator = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromDeclarator_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): rule(), fromTypeId(), fromDeclarator() {}
        soulng::parsing::Rule* rule;
        soulng::codedom::TypeId* fromTypeId;
        std::u32string fromDeclarator;
    };
};

class Element::ParameterRule : public soulng::parsing::Rule
{
public:
    ParameterRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsing::Rule*"), ToUtf32("rule")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> rule_value = std::move(stack.top());
        context->rule = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Rule*>*>(rule_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ParameterRule>(this, &ParameterRule::A0Action));
        soulng::parsing::NonterminalParser* typeIdNonterminalParser = GetNonterminal(ToUtf32("TypeId"));
        typeIdNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ParameterRule>(this, &ParameterRule::PostTypeId));
        soulng::parsing::NonterminalParser* declaratorNonterminalParser = GetNonterminal(ToUtf32("Declarator"));
        declaratorNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ParameterRule>(this, &ParameterRule::PostDeclarator));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->rule->AddInheritedAttribute(AttrOrVariable(context->fromTypeId->ToString(), context->fromDeclarator));
        delete context->fromTypeId;
    }
    void PostTypeId(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromTypeId_value = std::move(stack.top());
            context->fromTypeId = *static_cast<soulng::parsing::ValueObject<soulng::codedom::TypeId*>*>(fromTypeId_value.get());
            stack.pop();
        }
    }
    void PostDeclarator(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromDeclarator_value = std::move(stack.top());
            context->fromDeclarator = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromDeclarator_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): rule(), fromTypeId(), fromDeclarator() {}
        soulng::parsing::Rule* rule;
        soulng::codedom::TypeId* fromTypeId;
        std::u32string fromDeclarator;
    };
};

class Element::ReturnTypeRule : public soulng::parsing::Rule
{
public:
    ReturnTypeRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsing::Rule*"), ToUtf32("rule")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> rule_value = std::move(stack.top());
        context->rule = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Rule*>*>(rule_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ReturnTypeRule>(this, &ReturnTypeRule::A0Action));
        soulng::parsing::NonterminalParser* typeIdNonterminalParser = GetNonterminal(ToUtf32("TypeId"));
        typeIdNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ReturnTypeRule>(this, &ReturnTypeRule::PostTypeId));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->rule->SetValueTypeName(context->fromTypeId->ToString());
        delete context->fromTypeId;
    }
    void PostTypeId(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromTypeId_value = std::move(stack.top());
            context->fromTypeId = *static_cast<soulng::parsing::ValueObject<soulng::codedom::TypeId*>*>(fromTypeId_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): rule(), fromTypeId() {}
        soulng::parsing::Rule* rule;
        soulng::codedom::TypeId* fromTypeId;
    };
};

class Element::IdentifierRule : public soulng::parsing::Rule
{
public:
    IdentifierRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
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
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<IdentifierRule>(this, &IdentifierRule::A0Action));
        soulng::parsing::NonterminalParser* identifierNonterminalParser = GetNonterminal(ToUtf32("identifier"));
        identifierNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<IdentifierRule>(this, &IdentifierRule::Postidentifier));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = std::u32string(matchBegin, matchEnd);
    }
    void Postidentifier(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromidentifier_value = std::move(stack.top());
            context->fromidentifier = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromidentifier_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromidentifier() {}
        std::u32string value;
        std::u32string fromidentifier;
    };
};

class Element::QualifiedIdRule : public soulng::parsing::Rule
{
public:
    QualifiedIdRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
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
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<QualifiedIdRule>(this, &QualifiedIdRule::A0Action));
        soulng::parsing::NonterminalParser* firstNonterminalParser = GetNonterminal(ToUtf32("first"));
        firstNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<QualifiedIdRule>(this, &QualifiedIdRule::Postfirst));
        soulng::parsing::NonterminalParser* restNonterminalParser = GetNonterminal(ToUtf32("rest"));
        restNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<QualifiedIdRule>(this, &QualifiedIdRule::Postrest));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = std::u32string(matchBegin, matchEnd);
    }
    void Postfirst(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromfirst_value = std::move(stack.top());
            context->fromfirst = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromfirst_value.get());
            stack.pop();
        }
    }
    void Postrest(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromrest_value = std::move(stack.top());
            context->fromrest = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromrest_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromfirst(), fromrest() {}
        std::u32string value;
        std::u32string fromfirst;
        std::u32string fromrest;
    };
};

class Element::StringArrayRule : public soulng::parsing::Rule
{
public:
    StringArrayRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("std::vector<std::u32string>*"), ToUtf32("array")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> array_value = std::move(stack.top());
        context->array = *static_cast<soulng::parsing::ValueObject<std::vector<std::u32string>*>*>(array_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<StringArrayRule>(this, &StringArrayRule::A0Action));
        soulng::parsing::NonterminalParser* strNonterminalParser = GetNonterminal(ToUtf32("str"));
        strNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<StringArrayRule>(this, &StringArrayRule::Poststr));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->array->push_back(context->fromstr);
    }
    void Poststr(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromstr_value = std::move(stack.top());
            context->fromstr = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromstr_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): array(), fromstr() {}
        std::vector<std::u32string>* array;
        std::u32string fromstr;
    };
};

void Element::GetReferencedGrammars()
{
    soulng::parsing::ParsingDomain* pd = GetParsingDomain();
    soulng::parsing::Grammar* grammar0 = pd->GetGrammar(ToUtf32("soulng.code.Declarator"));
    if (!grammar0)
    {
        grammar0 = soulng::code::Declarator::Create(pd);
    }
    AddGrammarReference(grammar0);
    soulng::parsing::Grammar* grammar1 = pd->GetGrammar(ToUtf32("soulng.parsing.stdlib"));
    if (!grammar1)
    {
        grammar1 = soulng::parsing::stdlib::Create(pd);
    }
    AddGrammarReference(grammar1);
}

void Element::CreateRules()
{
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("qualified_id"), this, ToUtf32("soulng.parsing.stdlib.qualified_id")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("identifier"), this, ToUtf32("soulng.parsing.stdlib.identifier")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("Declarator"), this, ToUtf32("soulng.code.Declarator.Declarator")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("string"), this, ToUtf32("soulng.parsing.stdlib.string")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("TypeId"), this, ToUtf32("soulng.code.Declarator.TypeId")));
    AddRule(new RuleLinkRule(ToUtf32("RuleLink"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::SequenceParser(
                                    new soulng::parsing::KeywordParser(ToUtf32("using")),
                                    new soulng::parsing::NonterminalParser(ToUtf32("aliasName"), ToUtf32("identifier"), 0)),
                                new soulng::parsing::CharParser('=')),
                            new soulng::parsing::NonterminalParser(ToUtf32("ruleName"), ToUtf32("qualified_id"), 0)),
                        new soulng::parsing::CharParser(';')))),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::KeywordParser(ToUtf32("using")),
                            new soulng::parsing::NonterminalParser(ToUtf32("qualified_id"), ToUtf32("qualified_id"), 0)),
                        new soulng::parsing::CharParser(';')))))));
    AddRule(new SignatureRule(ToUtf32("Signature"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::OptionalParser(
                new soulng::parsing::NonterminalParser(ToUtf32("ParameterList"), ToUtf32("ParameterList"), 1)),
            new soulng::parsing::OptionalParser(
                new soulng::parsing::NonterminalParser(ToUtf32("ReturnType"), ToUtf32("ReturnType"), 1)))));
    AddRule(new ParameterListRule(ToUtf32("ParameterList"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::CharParser('('),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::ListParser(
                        new soulng::parsing::GroupingParser(
                            new soulng::parsing::AlternativeParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("Variable"), ToUtf32("Variable"), 1),
                                new soulng::parsing::NonterminalParser(ToUtf32("Parameter"), ToUtf32("Parameter"), 1))),
                        new soulng::parsing::CharParser(',')))),
            new soulng::parsing::ExpectationParser(
                new soulng::parsing::CharParser(')')))));
    AddRule(new VariableRule(ToUtf32("Variable"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::KeywordParser(ToUtf32("var")),
                new soulng::parsing::NonterminalParser(ToUtf32("TypeId"), ToUtf32("TypeId"), 0)),
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("Declarator"), ToUtf32("Declarator"), 0)))));
    AddRule(new ParameterRule(ToUtf32("Parameter"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::NonterminalParser(ToUtf32("TypeId"), ToUtf32("TypeId"), 0),
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("Declarator"), ToUtf32("Declarator"), 0)))));
    AddRule(new ReturnTypeRule(ToUtf32("ReturnType"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::GroupingParser(
                new soulng::parsing::DifferenceParser(
                    new soulng::parsing::CharParser(':'),
                    new soulng::parsing::StringParser(ToUtf32("::")))),
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("TypeId"), ToUtf32("TypeId"), 0)))));
    AddRule(new soulng::parsing::Rule(ToUtf32("Keyword"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::KeywordListParser(ToUtf32("identifier"), keywords0)));
    AddRule(new IdentifierRule(ToUtf32("Identifier"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::DifferenceParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("identifier"), ToUtf32("identifier"), 0),
                    new soulng::parsing::NonterminalParser(ToUtf32("Keyword"), ToUtf32("Keyword"), 0))))));
    AddRule(new QualifiedIdRule(ToUtf32("QualifiedId"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::TokenParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("first"), ToUtf32("Identifier"), 0),
                    new soulng::parsing::KleeneStarParser(
                        new soulng::parsing::GroupingParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::CharParser('.'),
                                new soulng::parsing::NonterminalParser(ToUtf32("rest"), ToUtf32("Identifier"), 0)))))))));
    AddRule(new StringArrayRule(ToUtf32("StringArray"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::CharParser('['),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::ListParser(
                        new soulng::parsing::ActionParser(ToUtf32("A0"),
                            new soulng::parsing::NonterminalParser(ToUtf32("str"), ToUtf32("string"), 0)),
                        new soulng::parsing::CharParser(',')))),
            new soulng::parsing::ExpectationParser(
                new soulng::parsing::CharParser(']')))));
}

} } // namespace soulng.syntax
