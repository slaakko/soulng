#include "Grammar.hpp"
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
#include <soulng/syntax/Rule.hpp>

namespace soulng { namespace syntax {

using namespace soulng::parsing;
using namespace soulng::util;
using namespace soulng::unicode;

GrammarGrammar* GrammarGrammar::Create()
{
    return Create(new soulng::parsing::ParsingDomain());
}

GrammarGrammar* GrammarGrammar::Create(soulng::parsing::ParsingDomain* parsingDomain)
{
    RegisterParsingDomain(parsingDomain);
    GrammarGrammar* grammar(new GrammarGrammar(parsingDomain));
    parsingDomain->AddGrammar(grammar);
    grammar->CreateRules();
    grammar->Link();
    return grammar;
}

GrammarGrammar::GrammarGrammar(soulng::parsing::ParsingDomain* parsingDomain_): soulng::parsing::Grammar(ToUtf32("GrammarGrammar"), parsingDomain_->GetNamespaceScope(ToUtf32("soulng.syntax")), parsingDomain_)
{
    SetOwner(0);
}

soulng::parsing::Grammar* GrammarGrammar::Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName, soulng::parsing::Scope* enclosingScope)
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
    soulng::parsing::Grammar* result = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Grammar*>*>(value.get());
    stack.pop();
    return result;
}

class GrammarGrammar::GrammarRule : public soulng::parsing::Rule
{
public:
    GrammarRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsing::Scope*"), ToUtf32("enclosingScope")));
        SetValueTypeName(ToUtf32("soulng::parsing::Grammar*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Grammar*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<GrammarRule>(this, &GrammarRule::A0Action));
        soulng::parsing::NonterminalParser* nameNonterminalParser = GetNonterminal(ToUtf32("name"));
        nameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<GrammarRule>(this, &GrammarRule::Postname));
        soulng::parsing::NonterminalParser* grammarContentNonterminalParser = GetNonterminal(ToUtf32("GrammarContent"));
        grammarContentNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<GrammarRule>(this, &GrammarRule::PreGrammarContent));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new Grammar(context->fromname, context->enclosingScope);
        context->value->SetSpan(span);
        context->value->SetNs(context->enclosingScope->Ns());
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
    void PreGrammarContent(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Grammar*>(context->value)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): enclosingScope(), value(), fromname() {}
        soulng::parsing::Scope* enclosingScope;
        soulng::parsing::Grammar* value;
        std::u32string fromname;
    };
};

class GrammarGrammar::GrammarContentRule : public soulng::parsing::Rule
{
public:
    GrammarContentRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
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
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<GrammarContentRule>(this, &GrammarContentRule::A0Action));
        soulng::parsing::NonterminalParser* startClauseNonterminalParser = GetNonterminal(ToUtf32("StartClause"));
        startClauseNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<GrammarContentRule>(this, &GrammarContentRule::PreStartClause));
        soulng::parsing::NonterminalParser* skipClauseNonterminalParser = GetNonterminal(ToUtf32("SkipClause"));
        skipClauseNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<GrammarContentRule>(this, &GrammarContentRule::PreSkipClause));
        soulng::parsing::NonterminalParser* ruleLinkNonterminalParser = GetNonterminal(ToUtf32("RuleLink"));
        ruleLinkNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<GrammarContentRule>(this, &GrammarContentRule::PreRuleLink));
        soulng::parsing::NonterminalParser* ruleNonterminalParser = GetNonterminal(ToUtf32("Rule"));
        ruleNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<GrammarContentRule>(this, &GrammarContentRule::PreRule));
        ruleNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<GrammarContentRule>(this, &GrammarContentRule::PostRule));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->grammar->AddRule(context->fromRule);
    }
    void PreStartClause(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Grammar*>(context->grammar)));
    }
    void PreSkipClause(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Grammar*>(context->grammar)));
    }
    void PreRuleLink(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Grammar*>(context->grammar)));
    }
    void PreRule(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Scope*>(context->grammar->GetScope())));
    }
    void PostRule(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromRule_value = std::move(stack.top());
            context->fromRule = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Rule*>*>(fromRule_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): grammar(), fromRule() {}
        soulng::parsing::Grammar* grammar;
        soulng::parsing::Rule* fromRule;
    };
};

class GrammarGrammar::StartClauseRule : public soulng::parsing::Rule
{
public:
    StartClauseRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
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
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<StartClauseRule>(this, &StartClauseRule::A0Action));
        soulng::parsing::NonterminalParser* strtNonterminalParser = GetNonterminal(ToUtf32("strt"));
        strtNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<StartClauseRule>(this, &StartClauseRule::Poststrt));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->grammar->SetStartRuleName(context->fromstrt);
    }
    void Poststrt(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromstrt_value = std::move(stack.top());
            context->fromstrt = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromstrt_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): grammar(), fromstrt() {}
        soulng::parsing::Grammar* grammar;
        std::u32string fromstrt;
    };
};

class GrammarGrammar::SkipClauseRule : public soulng::parsing::Rule
{
public:
    SkipClauseRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
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
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<SkipClauseRule>(this, &SkipClauseRule::A0Action));
        soulng::parsing::NonterminalParser* skpNonterminalParser = GetNonterminal(ToUtf32("skp"));
        skpNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<SkipClauseRule>(this, &SkipClauseRule::Postskp));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->grammar->SetSkipRuleName(context->fromskp);
    }
    void Postskp(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromskp_value = std::move(stack.top());
            context->fromskp = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromskp_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): grammar(), fromskp() {}
        soulng::parsing::Grammar* grammar;
        std::u32string fromskp;
    };
};

void GrammarGrammar::GetReferencedGrammars()
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
    soulng::parsing::Grammar* grammar2 = pd->GetGrammar(ToUtf32("soulng.syntax.Rule"));
    if (!grammar2)
    {
        grammar2 = soulng::syntax::Rule::Create(pd);
    }
    AddGrammarReference(grammar2);
}

void GrammarGrammar::CreateRules()
{
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("Identifier"), this, ToUtf32("Element.Identifier")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("char"), this, ToUtf32("soulng.parsing.stdlib.char")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("QualifiedId"), this, ToUtf32("Element.QualifiedId")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("Signature"), this, ToUtf32("Element.Signature")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("Rule"), this, ToUtf32("Rule.Rule")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("RuleLink"), this, ToUtf32("Element.RuleLink")));
    AddRule(new GrammarRule(ToUtf32("Grammar"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::KeywordParser(ToUtf32("grammar")),
                        new soulng::parsing::ActionParser(ToUtf32("A0"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("name"), ToUtf32("Identifier"), 0)))),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser('{'))),
                new soulng::parsing::NonterminalParser(ToUtf32("GrammarContent"), ToUtf32("GrammarContent"), 1)),
            new soulng::parsing::ExpectationParser(
                new soulng::parsing::CharParser('}')))));
    AddRule(new GrammarContentRule(ToUtf32("GrammarContent"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::KleeneStarParser(
            new soulng::parsing::GroupingParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::AlternativeParser(
                        new soulng::parsing::AlternativeParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("StartClause"), ToUtf32("StartClause"), 1),
                            new soulng::parsing::NonterminalParser(ToUtf32("SkipClause"), ToUtf32("SkipClause"), 1)),
                        new soulng::parsing::NonterminalParser(ToUtf32("RuleLink"), ToUtf32("RuleLink"), 1)),
                    new soulng::parsing::ActionParser(ToUtf32("A0"),
                        new soulng::parsing::NonterminalParser(ToUtf32("Rule"), ToUtf32("Rule"), 1)))))));
    AddRule(new StartClauseRule(ToUtf32("StartClause"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::KeywordParser(ToUtf32("start")),
                new soulng::parsing::ExpectationParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("strt"), ToUtf32("Identifier"), 0))),
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::CharParser(';')))));
    AddRule(new SkipClauseRule(ToUtf32("SkipClause"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::KeywordParser(ToUtf32("skip")),
                new soulng::parsing::ExpectationParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("skp"), ToUtf32("QualifiedId"), 0))),
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::CharParser(';')))));
}

} } // namespace soulng.syntax
