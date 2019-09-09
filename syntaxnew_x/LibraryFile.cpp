#include "LibraryFile.hpp"
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
#include <soulng/parsing/Namespace.hpp>
#include <soulng/syntax/Element.hpp>

namespace soulng { namespace syntax {

using namespace soulng::parsing;
using namespace soulng::util;
using namespace soulng::unicode;

LibraryFile* LibraryFile::Create()
{
    return Create(new soulng::parsing::ParsingDomain());
}

LibraryFile* LibraryFile::Create(soulng::parsing::ParsingDomain* parsingDomain)
{
    RegisterParsingDomain(parsingDomain);
    LibraryFile* grammar(new LibraryFile(parsingDomain));
    parsingDomain->AddGrammar(grammar);
    grammar->CreateRules();
    grammar->Link();
    return grammar;
}

LibraryFile::LibraryFile(soulng::parsing::ParsingDomain* parsingDomain_): soulng::parsing::Grammar(ToUtf32("LibraryFile"), parsingDomain_->GetNamespaceScope(ToUtf32("soulng.syntax")), parsingDomain_)
{
    SetOwner(0);
}

void LibraryFile::Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName, soulng::parsing::ParsingDomain* parsingDomain)
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
    stack.push(std::unique_ptr<soulng::parsing::Object>(new ValueObject<soulng::parsing::ParsingDomain*>(parsingDomain)));
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

class LibraryFile::LibraryFileRule : public soulng::parsing::Rule
{
public:
    LibraryFileRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsing::ParsingDomain*"), ToUtf32("parsingDomain")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> parsingDomain_value = std::move(stack.top());
        context->parsingDomain = *static_cast<soulng::parsing::ValueObject<soulng::parsing::ParsingDomain*>*>(parsingDomain_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::NonterminalParser* namespaceContentNonterminalParser = GetNonterminal(ToUtf32("NamespaceContent"));
        namespaceContentNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<LibraryFileRule>(this, &LibraryFileRule::PreNamespaceContent));
    }
    void PreNamespaceContent(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::ParsingDomain*>(context->parsingDomain)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): parsingDomain() {}
        soulng::parsing::ParsingDomain* parsingDomain;
    };
};

class LibraryFile::NamespaceContentRule : public soulng::parsing::Rule
{
public:
    NamespaceContentRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsing::ParsingDomain*"), ToUtf32("parsingDomain")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> parsingDomain_value = std::move(stack.top());
        context->parsingDomain = *static_cast<soulng::parsing::ValueObject<soulng::parsing::ParsingDomain*>*>(parsingDomain_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NamespaceContentRule>(this, &NamespaceContentRule::A0Action));
        soulng::parsing::NonterminalParser* grammarNonterminalParser = GetNonterminal(ToUtf32("Grammar"));
        grammarNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<NamespaceContentRule>(this, &NamespaceContentRule::PreGrammar));
        grammarNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<NamespaceContentRule>(this, &NamespaceContentRule::PostGrammar));
        soulng::parsing::NonterminalParser* namespaceNonterminalParser = GetNonterminal(ToUtf32("Namespace"));
        namespaceNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<NamespaceContentRule>(this, &NamespaceContentRule::PreNamespace));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->parsingDomain->AddGrammar(context->fromGrammar);
    }
    void PreGrammar(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Scope*>(context->parsingDomain->CurrentNamespace()->GetScope())));
    }
    void PostGrammar(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromGrammar_value = std::move(stack.top());
            context->fromGrammar = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Grammar*>*>(fromGrammar_value.get());
            stack.pop();
        }
    }
    void PreNamespace(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::ParsingDomain*>(context->parsingDomain)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): parsingDomain(), fromGrammar() {}
        soulng::parsing::ParsingDomain* parsingDomain;
        soulng::parsing::Grammar* fromGrammar;
    };
};

class LibraryFile::NamespaceRule : public soulng::parsing::Rule
{
public:
    NamespaceRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsing::ParsingDomain*"), ToUtf32("parsingDomain")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> parsingDomain_value = std::move(stack.top());
        context->parsingDomain = *static_cast<soulng::parsing::ValueObject<soulng::parsing::ParsingDomain*>*>(parsingDomain_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NamespaceRule>(this, &NamespaceRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NamespaceRule>(this, &NamespaceRule::A1Action));
        soulng::parsing::NonterminalParser* nsNonterminalParser = GetNonterminal(ToUtf32("ns"));
        nsNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<NamespaceRule>(this, &NamespaceRule::Postns));
        soulng::parsing::NonterminalParser* namespaceContentNonterminalParser = GetNonterminal(ToUtf32("NamespaceContent"));
        namespaceContentNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<NamespaceRule>(this, &NamespaceRule::PreNamespaceContent));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->parsingDomain->BeginNamespace(context->fromns);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->parsingDomain->EndNamespace();
    }
    void Postns(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromns_value = std::move(stack.top());
            context->fromns = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromns_value.get());
            stack.pop();
        }
    }
    void PreNamespaceContent(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::ParsingDomain*>(context->parsingDomain)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): parsingDomain(), fromns() {}
        soulng::parsing::ParsingDomain* parsingDomain;
        std::u32string fromns;
    };
};

class LibraryFile::GrammarRule : public soulng::parsing::Rule
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
        soulng::parsing::NonterminalParser* grammarNameNonterminalParser = GetNonterminal(ToUtf32("grammarName"));
        grammarNameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<GrammarRule>(this, &GrammarRule::PostgrammarName));
        soulng::parsing::NonterminalParser* grammarContentNonterminalParser = GetNonterminal(ToUtf32("GrammarContent"));
        grammarContentNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<GrammarRule>(this, &GrammarRule::PreGrammarContent));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new Grammar(context->fromgrammarName, context->enclosingScope);
        context->value->SetNs(context->enclosingScope->Ns());
    }
    void PostgrammarName(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromgrammarName_value = std::move(stack.top());
            context->fromgrammarName = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromgrammarName_value.get());
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
        Context(): enclosingScope(), value(), fromgrammarName() {}
        soulng::parsing::Scope* enclosingScope;
        soulng::parsing::Grammar* value;
        std::u32string fromgrammarName;
    };
};

class LibraryFile::GrammarContentRule : public soulng::parsing::Rule
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
        soulng::parsing::NonterminalParser* ruleNonterminalParser = GetNonterminal(ToUtf32("Rule"));
        ruleNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<GrammarContentRule>(this, &GrammarContentRule::PreRule));
        ruleNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<GrammarContentRule>(this, &GrammarContentRule::PostRule));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->grammar->AddRule(context->fromRule);
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

class LibraryFile::RuleRule : public soulng::parsing::Rule
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
        soulng::parsing::NonterminalParser* ruleNameNonterminalParser = GetNonterminal(ToUtf32("ruleName"));
        ruleNameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleRule>(this, &RuleRule::PostruleName));
        soulng::parsing::NonterminalParser* signatureNonterminalParser = GetNonterminal(ToUtf32("Signature"));
        signatureNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<RuleRule>(this, &RuleRule::PreSignature));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::parsing::Rule(context->fromruleName, context->enclosingScope);
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
    void PreSignature(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Rule*>(context->value)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): enclosingScope(), value(), fromruleName() {}
        soulng::parsing::Scope* enclosingScope;
        soulng::parsing::Rule* value;
        std::u32string fromruleName;
    };
};

void LibraryFile::GetReferencedGrammars()
{
    soulng::parsing::ParsingDomain* pd = GetParsingDomain();
    soulng::parsing::Grammar* grammar0 = pd->GetGrammar(ToUtf32("soulng.parsing.stdlib"));
    if (!grammar0)
    {
        grammar0 = soulng::parsing::stdlib::Create(pd);
    }
    AddGrammarReference(grammar0);
    soulng::parsing::Grammar* grammar1 = pd->GetGrammar(ToUtf32("soulng.syntax.Element"));
    if (!grammar1)
    {
        grammar1 = soulng::syntax::Element::Create(pd);
    }
    AddGrammarReference(grammar1);
}

void LibraryFile::CreateRules()
{
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("identifier"), this, ToUtf32("soulng.parsing.stdlib.identifier")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("qualified_id"), this, ToUtf32("soulng.parsing.stdlib.qualified_id")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("spaces_and_comments"), this, ToUtf32("soulng.parsing.stdlib.spaces_and_comments")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("Identifier"), this, ToUtf32("Element.Identifier")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("Signature"), this, ToUtf32("Element.Signature")));
    AddRule(new LibraryFileRule(ToUtf32("LibraryFile"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::NonterminalParser(ToUtf32("NamespaceContent"), ToUtf32("NamespaceContent"), 1)));
    AddRule(new NamespaceContentRule(ToUtf32("NamespaceContent"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::KleeneStarParser(
            new soulng::parsing::GroupingParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::ActionParser(ToUtf32("A0"),
                        new soulng::parsing::NonterminalParser(ToUtf32("Grammar"), ToUtf32("Grammar"), 1)),
                    new soulng::parsing::NonterminalParser(ToUtf32("Namespace"), ToUtf32("Namespace"), 1))))));
    AddRule(new NamespaceRule(ToUtf32("Namespace"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::KeywordParser(ToUtf32("namespace")),
                        new soulng::parsing::ActionParser(ToUtf32("A0"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("ns"), ToUtf32("qualified_id"), 0)))),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser('{'))),
                new soulng::parsing::NonterminalParser(ToUtf32("NamespaceContent"), ToUtf32("NamespaceContent"), 1)),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::ExpectationParser(
                    new soulng::parsing::CharParser('}'))))));
    AddRule(new GrammarRule(ToUtf32("Grammar"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::KeywordParser(ToUtf32("grammar")),
                        new soulng::parsing::ActionParser(ToUtf32("A0"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("grammarName"), ToUtf32("Identifier"), 0)))),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser('{'))),
                new soulng::parsing::NonterminalParser(ToUtf32("GrammarContent"), ToUtf32("GrammarContent"), 1)),
            new soulng::parsing::ExpectationParser(
                new soulng::parsing::CharParser('}')))));
    AddRule(new GrammarContentRule(ToUtf32("GrammarContent"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::KleeneStarParser(
            new soulng::parsing::GroupingParser(
                new soulng::parsing::ActionParser(ToUtf32("A0"),
                    new soulng::parsing::NonterminalParser(ToUtf32("Rule"), ToUtf32("Rule"), 1))))));
    AddRule(new RuleRule(ToUtf32("Rule"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::ActionParser(ToUtf32("A0"),
                    new soulng::parsing::NonterminalParser(ToUtf32("ruleName"), ToUtf32("Identifier"), 0)),
                new soulng::parsing::NonterminalParser(ToUtf32("Signature"), ToUtf32("Signature"), 1)),
            new soulng::parsing::CharParser(';'))));
    SetSkipRuleName(ToUtf32("spaces_and_comments"));
}

} } // namespace soulng.syntax
