#include "Rule.hpp"
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
#include <soulng/syntax/Element.hpp>
#include <soulng/syntax/Composite.hpp>

namespace soulng { namespace syntax {

using namespace soulng::parsing;
using namespace soulng::util;
using namespace soulng::unicode;

Rule* Rule::Create()
{
    return Create(new soulng::parsing::ParsingDomain());
}

Rule* Rule::Create(soulng::parsing::ParsingDomain* parsingDomain)
{
    RegisterParsingDomain(parsingDomain);
    Rule* grammar(new Rule(parsingDomain));
    parsingDomain->AddGrammar(grammar);
    grammar->CreateRules();
    grammar->Link();
    return grammar;
}

Rule::Rule(soulng::parsing::ParsingDomain* parsingDomain_): soulng::parsing::Grammar(ToUtf32("Rule"), parsingDomain_->GetNamespaceScope(ToUtf32("soulng.syntax")), parsingDomain_)
{
    SetOwner(0);
}

soulng::parsing::Rule* Rule::Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName, soulng::parsing::Scope* enclosingScope)
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
    soulng::parsing::Rule* result = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Rule*>*>(value.get());
    stack.pop();
    return result;
}

class Rule::RuleRule : public soulng::parsing::Rule
{
public:
    RuleRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsing::Scope*"), ToUtf32("enclosingScope")));
        SetValueTypeName(ToUtf32("soulng::parsing::Rule*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Rule*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RuleRule>(this, &RuleRule::A0Action));
        soulng::parsing::NonterminalParser* ruleHeaderNonterminalParser = GetNonterminal(ToUtf32("RuleHeader"));
        ruleHeaderNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<RuleRule>(this, &RuleRule::PreRuleHeader));
        ruleHeaderNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleRule>(this, &RuleRule::PostRuleHeader));
        soulng::parsing::NonterminalParser* ruleBodyNonterminalParser = GetNonterminal(ToUtf32("RuleBody"));
        ruleBodyNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<RuleRule>(this, &RuleRule::PreRuleBody));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromRuleHeader;
    }
    void PreRuleHeader(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Scope*>(context->enclosingScope)));
    }
    void PostRuleHeader(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromRuleHeader_value = std::move(stack.top());
            context->fromRuleHeader = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Rule*>*>(fromRuleHeader_value.get());
            stack.pop();
        }
    }
    void PreRuleBody(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Rule*>(context->value)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): enclosingScope(), value(), fromRuleHeader() {}
        soulng::parsing::Scope* enclosingScope;
        soulng::parsing::Rule* value;
        soulng::parsing::Rule* fromRuleHeader;
    };
};

class Rule::RuleHeaderRule : public soulng::parsing::Rule
{
public:
    RuleHeaderRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsing::Scope*"), ToUtf32("enclosingScope")));
        SetValueTypeName(ToUtf32("soulng::parsing::Rule*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Rule*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RuleHeaderRule>(this, &RuleHeaderRule::A0Action));
        soulng::parsing::NonterminalParser* nameNonterminalParser = GetNonterminal(ToUtf32("name"));
        nameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleHeaderRule>(this, &RuleHeaderRule::Postname));
        soulng::parsing::NonterminalParser* signatureNonterminalParser = GetNonterminal(ToUtf32("Signature"));
        signatureNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<RuleHeaderRule>(this, &RuleHeaderRule::PreSignature));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new Rule(context->fromname, context->enclosingScope);
        context->value->SetSpan(span);
    }
    void Postname(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromname_value = std::move(stack.top());
            context->fromname = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromname_value.get());
            stack.pop();
        }
    }
    void PreSignature(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Rule*>(context->value)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): enclosingScope(), value(), fromname() {}
        soulng::parsing::Scope* enclosingScope;
        soulng::parsing::Rule* value;
        std::u32string fromname;
    };
};

class Rule::RuleBodyRule : public soulng::parsing::Rule
{
public:
    RuleBodyRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
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
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RuleBodyRule>(this, &RuleBodyRule::A0Action));
        soulng::parsing::NonterminalParser* definitionNonterminalParser = GetNonterminal(ToUtf32("definition"));
        definitionNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<RuleBodyRule>(this, &RuleBodyRule::Predefinition));
        definitionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleBodyRule>(this, &RuleBodyRule::Postdefinition));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->rule->SetDefinition(context->fromdefinition);
    }
    void Predefinition(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Scope*>(context->rule->GetScope())));
    }
    void Postdefinition(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromdefinition_value = std::move(stack.top());
            context->fromdefinition = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromdefinition_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): rule(), fromdefinition() {}
        soulng::parsing::Rule* rule;
        soulng::parsing::Parser* fromdefinition;
    };
};

void Rule::GetReferencedGrammars()
{
    soulng::parsing::ParsingDomain* pd = GetParsingDomain();
    soulng::parsing::Grammar* grammar0 = pd->GetGrammar(ToUtf32("soulng.syntax.Element"));
    if (!grammar0)
    {
        grammar0 = soulng::syntax::Element::Create(pd);
    }
    AddGrammarReference(grammar0);
    soulng::parsing::Grammar* grammar1 = pd->GetGrammar(ToUtf32("soulng.parsing.stdlib"));
    if (!grammar1)
    {
        grammar1 = soulng::parsing::stdlib::Create(pd);
    }
    AddGrammarReference(grammar1);
    soulng::parsing::Grammar* grammar2 = pd->GetGrammar(ToUtf32("soulng.syntax.Composite"));
    if (!grammar2)
    {
        grammar2 = soulng::syntax::Composite::Create(pd);
    }
    AddGrammarReference(grammar2);
}

void Rule::CreateRules()
{
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("Signature"), this, ToUtf32("Element.Signature")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("Identifier"), this, ToUtf32("Element.Identifier")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("string"), this, ToUtf32("soulng.parsing.stdlib.string")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("Alternative"), this, ToUtf32("Composite.Alternative")));
    AddRule(new RuleRule(ToUtf32("Rule"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::ActionParser(ToUtf32("A0"),
                    new soulng::parsing::NonterminalParser(ToUtf32("RuleHeader"), ToUtf32("RuleHeader"), 1)),
                new soulng::parsing::StringParser(ToUtf32("::="))),
            new soulng::parsing::NonterminalParser(ToUtf32("RuleBody"), ToUtf32("RuleBody"), 1))));
    AddRule(new RuleHeaderRule(ToUtf32("RuleHeader"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("name"), ToUtf32("Identifier"), 0)),
            new soulng::parsing::NonterminalParser(ToUtf32("Signature"), ToUtf32("Signature"), 1))));
    AddRule(new RuleBodyRule(ToUtf32("RuleBody"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("definition"), ToUtf32("Alternative"), 1)),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser(';')))))));
}

} } // namespace soulng.syntax
