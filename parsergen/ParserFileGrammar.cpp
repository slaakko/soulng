#include "ParserFileGrammar.hpp"
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
#include <soulng/code/Declarator.hpp>
#include <soulng/code/Expression.hpp>
#include <soulng/code/Statement.hpp>
#include <soulng/code/Identifier.hpp>

namespace soulng { namespace parsergen {

using namespace soulng::parsing;
using namespace soulng::util;
using namespace soulng::unicode;

ParserFileGrammar* ParserFileGrammar::Create()
{
    return Create(new soulng::parsing::ParsingDomain());
}

ParserFileGrammar* ParserFileGrammar::Create(soulng::parsing::ParsingDomain* parsingDomain)
{
    RegisterParsingDomain(parsingDomain);
    ParserFileGrammar* grammar(new ParserFileGrammar(parsingDomain));
    parsingDomain->AddGrammar(grammar);
    grammar->CreateRules();
    grammar->Link();
    return grammar;
}

ParserFileGrammar::ParserFileGrammar(soulng::parsing::ParsingDomain* parsingDomain_): soulng::parsing::Grammar(ToUtf32("ParserFileGrammar"), parsingDomain_->GetNamespaceScope(ToUtf32("soulng.parsergen")), parsingDomain_)
{
    SetOwner(0);
    keywords0.push_back(ToUtf32("empty"));
    keywords0.push_back(ToUtf32("lexer"));
    keywords0.push_back(ToUtf32("main"));
    keywords0.push_back(ToUtf32("namespace"));
    keywords0.push_back(ToUtf32("parser"));
    keywords0.push_back(ToUtf32("ruleinfo"));
    keywords0.push_back(ToUtf32("using"));
}

ParserFile* ParserFileGrammar::Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName)
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
    ParserFile* result = *static_cast<soulng::parsing::ValueObject<ParserFile*>*>(value.get());
    stack.pop();
    return result;
}

class ParserFileGrammar::ParserFileRule : public soulng::parsing::Rule
{
public:
    ParserFileRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("ParserFile*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<ParserFile*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ParserFileRule>(this, &ParserFileRule::A0Action));
        soulng::parsing::NonterminalParser* declarationNonterminalParser = GetNonterminal(ToUtf32("declaration"));
        declarationNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<ParserFileRule>(this, &ParserFileRule::Predeclaration));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new ParserFile(fileName);
    }
    void Predeclaration(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<ParserFile*>(context->value)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        ParserFile* value;
    };
};

class ParserFileGrammar::DeclarationRule : public soulng::parsing::Rule
{
public:
    DeclarationRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("ParserFile*"), ToUtf32("parserFile")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> parserFile_value = std::move(stack.top());
        context->parserFile = *static_cast<soulng::parsing::ValueObject<ParserFile*>*>(parserFile_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeclarationRule>(this, &DeclarationRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeclarationRule>(this, &DeclarationRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeclarationRule>(this, &DeclarationRule::A2Action));
        soulng::parsing::NonterminalParser* includeNonterminalParser = GetNonterminal(ToUtf32("include"));
        includeNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DeclarationRule>(this, &DeclarationRule::Postinclude));
        soulng::parsing::NonterminalParser* usingNsNonterminalParser = GetNonterminal(ToUtf32("usingNs"));
        usingNsNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DeclarationRule>(this, &DeclarationRule::PostusingNs));
        soulng::parsing::NonterminalParser* grmrNonterminalParser = GetNonterminal(ToUtf32("grmr"));
        grmrNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DeclarationRule>(this, &DeclarationRule::Postgrmr));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->parserFile->AddInclude(context->frominclude);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->parserFile->AddUsingNamespace(context->fromusingNs);
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->parserFile->AddGrammar(context->fromgrmr);
    }
    void Postinclude(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> frominclude_value = std::move(stack.top());
            context->frominclude = *static_cast<soulng::parsing::ValueObject<Include*>*>(frominclude_value.get());
            stack.pop();
        }
    }
    void PostusingNs(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromusingNs_value = std::move(stack.top());
            context->fromusingNs = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromusingNs_value.get());
            stack.pop();
        }
    }
    void Postgrmr(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromgrmr_value = std::move(stack.top());
            context->fromgrmr = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::GrammarParser*>*>(fromgrmr_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): parserFile(), frominclude(), fromusingNs(), fromgrmr() {}
        ParserFile* parserFile;
        Include* frominclude;
        std::u32string fromusingNs;
        soulng::parsergen::GrammarParser* fromgrmr;
    };
};

class ParserFileGrammar::IncludeDeclarationRule : public soulng::parsing::Rule
{
public:
    IncludeDeclarationRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("Include*"));
        AddLocalVariable(AttrOrVariable(ToUtf32("std::u32string"), ToUtf32("include")));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Include*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<IncludeDeclarationRule>(this, &IncludeDeclarationRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<IncludeDeclarationRule>(this, &IncludeDeclarationRule::A1Action));
        soulng::parsing::NonterminalParser* prefixNonterminalParser = GetNonterminal(ToUtf32("prefix"));
        prefixNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<IncludeDeclarationRule>(this, &IncludeDeclarationRule::Postprefix));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new Include(context->fromprefix, context->include);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->include = std::u32string(matchBegin, matchEnd);
    }
    void Postprefix(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromprefix_value = std::move(stack.top());
            context->fromprefix = *static_cast<soulng::parsing::ValueObject<bool>*>(fromprefix_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), include(), fromprefix() {}
        Include* value;
        std::u32string include;
        bool fromprefix;
    };
};

class ParserFileGrammar::IncludePrefixRule : public soulng::parsing::Rule
{
public:
    IncludePrefixRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("bool"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<bool>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<IncludePrefixRule>(this, &IncludePrefixRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<IncludePrefixRule>(this, &IncludePrefixRule::A1Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = false;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = true;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        bool value;
    };
};

class ParserFileGrammar::UsingNamespaceDeclarationRule : public soulng::parsing::Rule
{
public:
    UsingNamespaceDeclarationRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
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
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UsingNamespaceDeclarationRule>(this, &UsingNamespaceDeclarationRule::A0Action));
        soulng::parsing::NonterminalParser* qidNonterminalParser = GetNonterminal(ToUtf32("qid"));
        qidNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<UsingNamespaceDeclarationRule>(this, &UsingNamespaceDeclarationRule::Postqid));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = std::u32string(matchBegin, matchEnd);
    }
    void Postqid(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromqid_value = std::move(stack.top());
            context->fromqid = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromqid_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromqid() {}
        std::u32string value;
        std::u32string fromqid;
    };
};

class ParserFileGrammar::GrammarDeclarationRule : public soulng::parsing::Rule
{
public:
    GrammarDeclarationRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsergen::GrammarParser*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::GrammarParser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<GrammarDeclarationRule>(this, &GrammarDeclarationRule::A0Action));
        soulng::parsing::NonterminalParser* grammarNameNonterminalParser = GetNonterminal(ToUtf32("grammarName"));
        grammarNameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<GrammarDeclarationRule>(this, &GrammarDeclarationRule::PostgrammarName));
        soulng::parsing::NonterminalParser* grammarStatementNonterminalParser = GetNonterminal(ToUtf32("GrammarStatement"));
        grammarStatementNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<GrammarDeclarationRule>(this, &GrammarDeclarationRule::PreGrammarStatement));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::parsergen::GrammarParser(context->fromgrammarName);
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
    void PreGrammarStatement(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::GrammarParser*>(context->value)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromgrammarName() {}
        soulng::parsergen::GrammarParser* value;
        std::u32string fromgrammarName;
    };
};

class ParserFileGrammar::GrammarStatementRule : public soulng::parsing::Rule
{
public:
    GrammarStatementRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsergen::GrammarParser*"), ToUtf32("grammar")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> grammar_value = std::move(stack.top());
        context->grammar = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::GrammarParser*>*>(grammar_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::NonterminalParser* mainStatementNonterminalParser = GetNonterminal(ToUtf32("MainStatement"));
        mainStatementNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<GrammarStatementRule>(this, &GrammarStatementRule::PreMainStatement));
        soulng::parsing::NonterminalParser* usingStatementNonterminalParser = GetNonterminal(ToUtf32("UsingStatement"));
        usingStatementNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<GrammarStatementRule>(this, &GrammarStatementRule::PreUsingStatement));
        soulng::parsing::NonterminalParser* lexerStatementNonterminalParser = GetNonterminal(ToUtf32("LexerStatement"));
        lexerStatementNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<GrammarStatementRule>(this, &GrammarStatementRule::PreLexerStatement));
        soulng::parsing::NonterminalParser* ruleInfoStatementNonterminalParser = GetNonterminal(ToUtf32("RuleInfoStatement"));
        ruleInfoStatementNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<GrammarStatementRule>(this, &GrammarStatementRule::PreRuleInfoStatement));
        soulng::parsing::NonterminalParser* ruleStatementNonterminalParser = GetNonterminal(ToUtf32("RuleStatement"));
        ruleStatementNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<GrammarStatementRule>(this, &GrammarStatementRule::PreRuleStatement));
    }
    void PreMainStatement(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::GrammarParser*>(context->grammar)));
    }
    void PreUsingStatement(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::GrammarParser*>(context->grammar)));
    }
    void PreLexerStatement(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::GrammarParser*>(context->grammar)));
    }
    void PreRuleInfoStatement(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::GrammarParser*>(context->grammar)));
    }
    void PreRuleStatement(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::GrammarParser*>(context->grammar)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): grammar() {}
        soulng::parsergen::GrammarParser* grammar;
    };
};

class ParserFileGrammar::MainStatementRule : public soulng::parsing::Rule
{
public:
    MainStatementRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsergen::GrammarParser*"), ToUtf32("grammar")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> grammar_value = std::move(stack.top());
        context->grammar = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::GrammarParser*>*>(grammar_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<MainStatementRule>(this, &MainStatementRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->grammar->SetMain();
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): grammar() {}
        soulng::parsergen::GrammarParser* grammar;
    };
};

class ParserFileGrammar::UsingStatementRule : public soulng::parsing::Rule
{
public:
    UsingStatementRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsergen::GrammarParser*"), ToUtf32("grammar")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> grammar_value = std::move(stack.top());
        context->grammar = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::GrammarParser*>*>(grammar_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UsingStatementRule>(this, &UsingStatementRule::A0Action));
        soulng::parsing::NonterminalParser* idNonterminalParser = GetNonterminal(ToUtf32("id"));
        idNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<UsingStatementRule>(this, &UsingStatementRule::Postid));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->grammar->AddUsing(context->fromid);
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
private:
    struct Context : soulng::parsing::Context
    {
        Context(): grammar(), fromid() {}
        soulng::parsergen::GrammarParser* grammar;
        std::u32string fromid;
    };
};

class ParserFileGrammar::LexerStatementRule : public soulng::parsing::Rule
{
public:
    LexerStatementRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsergen::GrammarParser*"), ToUtf32("grammar")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> grammar_value = std::move(stack.top());
        context->grammar = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::GrammarParser*>*>(grammar_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<LexerStatementRule>(this, &LexerStatementRule::A0Action));
        soulng::parsing::NonterminalParser* idNonterminalParser = GetNonterminal(ToUtf32("id"));
        idNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<LexerStatementRule>(this, &LexerStatementRule::Postid));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->grammar->SetLexer(context->fromid);
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
private:
    struct Context : soulng::parsing::Context
    {
        Context(): grammar(), fromid() {}
        soulng::parsergen::GrammarParser* grammar;
        std::u32string fromid;
    };
};

class ParserFileGrammar::RuleInfoStatementRule : public soulng::parsing::Rule
{
public:
    RuleInfoStatementRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsergen::GrammarParser*"), ToUtf32("grammar")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> grammar_value = std::move(stack.top());
        context->grammar = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::GrammarParser*>*>(grammar_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::NonterminalParser* ruleInfoNonterminalParser = GetNonterminal(ToUtf32("RuleInfo"));
        ruleInfoNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<RuleInfoStatementRule>(this, &RuleInfoStatementRule::PreRuleInfo));
    }
    void PreRuleInfo(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::GrammarParser*>(context->grammar)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): grammar() {}
        soulng::parsergen::GrammarParser* grammar;
    };
};

class ParserFileGrammar::RuleInfoRule : public soulng::parsing::Rule
{
public:
    RuleInfoRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsergen::GrammarParser*"), ToUtf32("grammar")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> grammar_value = std::move(stack.top());
        context->grammar = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::GrammarParser*>*>(grammar_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RuleInfoRule>(this, &RuleInfoRule::A0Action));
        soulng::parsing::NonterminalParser* ruleNameNonterminalParser = GetNonterminal(ToUtf32("ruleName"));
        ruleNameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleInfoRule>(this, &RuleInfoRule::PostruleName));
        soulng::parsing::NonterminalParser* ruleInfoNonterminalParser = GetNonterminal(ToUtf32("ruleInfo"));
        ruleInfoNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleInfoRule>(this, &RuleInfoRule::PostruleInfo));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->grammar->AddRuleInfo(context->fromruleName, context->fromruleInfo);
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
    void PostruleInfo(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromruleInfo_value = std::move(stack.top());
            context->fromruleInfo = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromruleInfo_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): grammar(), fromruleName(), fromruleInfo() {}
        soulng::parsergen::GrammarParser* grammar;
        std::u32string fromruleName;
        std::u32string fromruleInfo;
    };
};

class ParserFileGrammar::RuleStatementRule : public soulng::parsing::Rule
{
public:
    RuleStatementRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsergen::GrammarParser*"), ToUtf32("grammar")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> grammar_value = std::move(stack.top());
        context->grammar = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::GrammarParser*>*>(grammar_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RuleStatementRule>(this, &RuleStatementRule::A0Action));
        soulng::parsing::NonterminalParser* ruleNameNonterminalParser = GetNonterminal(ToUtf32("ruleName"));
        ruleNameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleStatementRule>(this, &RuleStatementRule::PostruleName));
        soulng::parsing::NonterminalParser* paramsNonterminalParser = GetNonterminal(ToUtf32("params"));
        paramsNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleStatementRule>(this, &RuleStatementRule::Postparams));
        soulng::parsing::NonterminalParser* returnTypeNonterminalParser = GetNonterminal(ToUtf32("returnType"));
        returnTypeNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleStatementRule>(this, &RuleStatementRule::PostreturnType));
        soulng::parsing::NonterminalParser* definitionNonterminalParser = GetNonterminal(ToUtf32("definition"));
        definitionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleStatementRule>(this, &RuleStatementRule::Postdefinition));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        soulng::parsergen::RuleParser * rule = new soulng::parsergen::RuleParser(context->fromruleName, context->fromdefinition);
        rule->SetParameters(context->fromparams);
        rule->SetReturnType(context->fromreturnType);
        context->grammar->AddRule(rule);
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
    void Postparams(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromparams_value = std::move(stack.top());
            context->fromparams = *static_cast<soulng::parsing::ValueObject<std::vector<soulng::parsergen::Parameter*>>*>(fromparams_value.get());
            stack.pop();
        }
    }
    void PostreturnType(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromreturnType_value = std::move(stack.top());
            context->fromreturnType = *static_cast<soulng::parsing::ValueObject<soulng::codedom::TypeId*>*>(fromreturnType_value.get());
            stack.pop();
        }
    }
    void Postdefinition(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromdefinition_value = std::move(stack.top());
            context->fromdefinition = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::Parser*>*>(fromdefinition_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): grammar(), fromruleName(), fromparams(), fromreturnType(), fromdefinition() {}
        soulng::parsergen::GrammarParser* grammar;
        std::u32string fromruleName;
        std::vector<soulng::parsergen::Parameter*> fromparams;
        soulng::codedom::TypeId* fromreturnType;
        soulng::parsergen::Parser* fromdefinition;
    };
};

class ParserFileGrammar::RuleBodyRule : public soulng::parsing::Rule
{
public:
    RuleBodyRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsergen::Parser*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RuleBodyRule>(this, &RuleBodyRule::A0Action));
        soulng::parsing::NonterminalParser* altNonterminalParser = GetNonterminal(ToUtf32("alt"));
        altNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleBodyRule>(this, &RuleBodyRule::Postalt));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromalt;
    }
    void Postalt(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromalt_value = std::move(stack.top());
            context->fromalt = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::Parser*>*>(fromalt_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromalt() {}
        soulng::parsergen::Parser* value;
        soulng::parsergen::Parser* fromalt;
    };
};

class ParserFileGrammar::AlternativeRule : public soulng::parsing::Rule
{
public:
    AlternativeRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsergen::Parser*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::Parser*>(context->value)));
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
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<AlternativeRule>(this, &AlternativeRule::Postleft));
        soulng::parsing::NonterminalParser* rightNonterminalParser = GetNonterminal(ToUtf32("right"));
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
        context->value = new soulng::parsergen::AlternativeParser(context->value, context->fromright);
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::Parser*>*>(fromleft_value.get());
            stack.pop();
        }
    }
    void Postright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromright_value = std::move(stack.top());
            context->fromright = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::Parser*>*>(fromright_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromleft(), fromright() {}
        soulng::parsergen::Parser* value;
        soulng::parsergen::Parser* fromleft;
        soulng::parsergen::Parser* fromright;
    };
};

class ParserFileGrammar::SequenceRule : public soulng::parsing::Rule
{
public:
    SequenceRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsergen::Parser*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<SequenceRule>(this, &SequenceRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<SequenceRule>(this, &SequenceRule::A1Action));
        soulng::parsing::NonterminalParser* leftNonterminalParser = GetNonterminal(ToUtf32("left"));
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<SequenceRule>(this, &SequenceRule::Postleft));
        soulng::parsing::NonterminalParser* rightNonterminalParser = GetNonterminal(ToUtf32("right"));
        rightNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<SequenceRule>(this, &SequenceRule::Postright));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromleft;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::parsergen::SequenceParser(context->value, context->fromright);
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::Parser*>*>(fromleft_value.get());
            stack.pop();
        }
    }
    void Postright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromright_value = std::move(stack.top());
            context->fromright = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::Parser*>*>(fromright_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromleft(), fromright() {}
        soulng::parsergen::Parser* value;
        soulng::parsergen::Parser* fromleft;
        soulng::parsergen::Parser* fromright;
    };
};

class ParserFileGrammar::DifferenceRule : public soulng::parsing::Rule
{
public:
    DifferenceRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsergen::Parser*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DifferenceRule>(this, &DifferenceRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DifferenceRule>(this, &DifferenceRule::A1Action));
        soulng::parsing::NonterminalParser* leftNonterminalParser = GetNonterminal(ToUtf32("left"));
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DifferenceRule>(this, &DifferenceRule::Postleft));
        soulng::parsing::NonterminalParser* rightNonterminalParser = GetNonterminal(ToUtf32("right"));
        rightNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DifferenceRule>(this, &DifferenceRule::Postright));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromleft;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::parsergen::DifferenceParser(context->value, context->fromright);
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::Parser*>*>(fromleft_value.get());
            stack.pop();
        }
    }
    void Postright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromright_value = std::move(stack.top());
            context->fromright = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::Parser*>*>(fromright_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromleft(), fromright() {}
        soulng::parsergen::Parser* value;
        soulng::parsergen::Parser* fromleft;
        soulng::parsergen::Parser* fromright;
    };
};

class ParserFileGrammar::ListRule : public soulng::parsing::Rule
{
public:
    ListRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsergen::Parser*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ListRule>(this, &ListRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ListRule>(this, &ListRule::A1Action));
        soulng::parsing::NonterminalParser* leftNonterminalParser = GetNonterminal(ToUtf32("left"));
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ListRule>(this, &ListRule::Postleft));
        soulng::parsing::NonterminalParser* rightNonterminalParser = GetNonterminal(ToUtf32("right"));
        rightNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ListRule>(this, &ListRule::Postright));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromleft;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::parsergen::ListParser(context->value, context->fromright);
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::Parser*>*>(fromleft_value.get());
            stack.pop();
        }
    }
    void Postright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromright_value = std::move(stack.top());
            context->fromright = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::Parser*>*>(fromright_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromleft(), fromright() {}
        soulng::parsergen::Parser* value;
        soulng::parsergen::Parser* fromleft;
        soulng::parsergen::Parser* fromright;
    };
};

class ParserFileGrammar::PostfixRule : public soulng::parsing::Rule
{
public:
    PostfixRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsergen::Parser*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PostfixRule>(this, &PostfixRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PostfixRule>(this, &PostfixRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PostfixRule>(this, &PostfixRule::A2Action));
        soulng::parsing::ActionParser* a3ActionParser = GetAction(ToUtf32("A3"));
        a3ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PostfixRule>(this, &PostfixRule::A3Action));
        soulng::parsing::NonterminalParser* primaryNonterminalParser = GetNonterminal(ToUtf32("primary"));
        primaryNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PostfixRule>(this, &PostfixRule::Postprimary));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromprimary;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::parsergen::KleeneParser(context->value);
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::parsergen::PositiveParser(context->value);
    }
    void A3Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::parsergen::OptionalParser(context->value);
    }
    void Postprimary(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromprimary_value = std::move(stack.top());
            context->fromprimary = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::Parser*>*>(fromprimary_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromprimary() {}
        soulng::parsergen::Parser* value;
        soulng::parsergen::Parser* fromprimary;
    };
};

class ParserFileGrammar::PrimaryRule : public soulng::parsing::Rule
{
public:
    PrimaryRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsergen::Parser*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::Parser*>(context->value)));
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
        soulng::parsing::NonterminalParser* ruleCallNonterminalParser = GetNonterminal(ToUtf32("RuleCall"));
        ruleCallNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimaryRule>(this, &PrimaryRule::PostRuleCall));
        soulng::parsing::NonterminalParser* primitiveNonterminalParser = GetNonterminal(ToUtf32("Primitive"));
        primitiveNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimaryRule>(this, &PrimaryRule::PostPrimitive));
        soulng::parsing::NonterminalParser* groupingNonterminalParser = GetNonterminal(ToUtf32("Grouping"));
        groupingNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimaryRule>(this, &PrimaryRule::PostGrouping));
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
        context->value = context->fromExpectation;
    }
    void A4Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
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
            context->fromRuleCall = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::Parser*>*>(fromRuleCall_value.get());
            stack.pop();
        }
    }
    void PostPrimitive(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromPrimitive_value = std::move(stack.top());
            context->fromPrimitive = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::Parser*>*>(fromPrimitive_value.get());
            stack.pop();
        }
    }
    void PostGrouping(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromGrouping_value = std::move(stack.top());
            context->fromGrouping = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::Parser*>*>(fromGrouping_value.get());
            stack.pop();
        }
    }
    void PreExpectation(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::Parser*>(context->value)));
    }
    void PostExpectation(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromExpectation_value = std::move(stack.top());
            context->fromExpectation = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::Parser*>*>(fromExpectation_value.get());
            stack.pop();
        }
    }
    void PreAction(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::Parser*>(context->value)));
    }
    void PostAction(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromAction_value = std::move(stack.top());
            context->fromAction = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::Parser*>*>(fromAction_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromRuleCall(), fromPrimitive(), fromGrouping(), fromExpectation(), fromAction() {}
        soulng::parsergen::Parser* value;
        soulng::parsergen::Parser* fromRuleCall;
        soulng::parsergen::Parser* fromPrimitive;
        soulng::parsergen::Parser* fromGrouping;
        soulng::parsergen::Parser* fromExpectation;
        soulng::parsergen::Parser* fromAction;
    };
};

class ParserFileGrammar::RuleCallRule : public soulng::parsing::Rule
{
public:
    RuleCallRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsergen::Parser*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RuleCallRule>(this, &RuleCallRule::A0Action));
        soulng::parsing::NonterminalParser* ntArgsNonterminalParser = GetNonterminal(ToUtf32("ntArgs"));
        ntArgsNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleCallRule>(this, &RuleCallRule::PostntArgs));
        soulng::parsing::NonterminalParser* argsNonterminalParser = GetNonterminal(ToUtf32("args"));
        argsNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleCallRule>(this, &RuleCallRule::Postargs));
        soulng::parsing::NonterminalParser* ntNonterminalParser = GetNonterminal(ToUtf32("nt"));
        ntNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleCallRule>(this, &RuleCallRule::Postnt));
        soulng::parsing::NonterminalParser* nameNonterminalParser = GetNonterminal(ToUtf32("name"));
        nameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RuleCallRule>(this, &RuleCallRule::Postname));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::u32string ruleName;
        if (!context->fromntArgs.empty())
        {
            ruleName = context->fromntArgs;
        }
        else
        {
            ruleName = context->fromnt;
        }
        soulng::parsergen::NonterminalParser * parser = new soulng::parsergen::NonterminalParser(context->fromname, ruleName);
        if (!context->fromargs.empty())
        {
            parser->SetArguments(context->fromargs);
        }
        context->value = parser;
    }
    void PostntArgs(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromntArgs_value = std::move(stack.top());
            context->fromntArgs = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromntArgs_value.get());
            stack.pop();
        }
    }
    void Postargs(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromargs_value = std::move(stack.top());
            context->fromargs = *static_cast<soulng::parsing::ValueObject<std::vector<soulng::codedom::CppObject*>>*>(fromargs_value.get());
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
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromntArgs(), fromargs(), fromnt(), fromname() {}
        soulng::parsergen::Parser* value;
        std::u32string fromntArgs;
        std::vector<soulng::codedom::CppObject*> fromargs;
        std::u32string fromnt;
        std::u32string fromname;
    };
};

class ParserFileGrammar::PrimitiveRule : public soulng::parsing::Rule
{
public:
    PrimitiveRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsergen::Parser*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A1Action));
        soulng::parsing::NonterminalParser* tknNonterminalParser = GetNonterminal(ToUtf32("tkn"));
        tknNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::Posttkn));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::parsergen::EmptyParser;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::parsergen::TokenParser(context->fromtkn);
    }
    void Posttkn(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromtkn_value = std::move(stack.top());
            context->fromtkn = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromtkn_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromtkn() {}
        soulng::parsergen::Parser* value;
        std::u32string fromtkn;
    };
};

class ParserFileGrammar::GroupingRule : public soulng::parsing::Rule
{
public:
    GroupingRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsergen::Parser*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<GroupingRule>(this, &GroupingRule::A0Action));
        soulng::parsing::NonterminalParser* altNonterminalParser = GetNonterminal(ToUtf32("alt"));
        altNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<GroupingRule>(this, &GroupingRule::Postalt));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::parsergen::GroupingParser(context->fromalt);
    }
    void Postalt(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromalt_value = std::move(stack.top());
            context->fromalt = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::Parser*>*>(fromalt_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromalt() {}
        soulng::parsergen::Parser* value;
        soulng::parsergen::Parser* fromalt;
    };
};

class ParserFileGrammar::ExpectationRule : public soulng::parsing::Rule
{
public:
    ExpectationRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsergen::Parser*"), ToUtf32("parser")));
        SetValueTypeName(ToUtf32("soulng::parsergen::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> parser_value = std::move(stack.top());
        context->parser = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::Parser*>*>(parser_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::Parser*>(context->value)));
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
        context->value = new soulng::parsergen::ExpectationParser(context->parser);
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): parser(), value() {}
        soulng::parsergen::Parser* parser;
        soulng::parsergen::Parser* value;
    };
};

class ParserFileGrammar::ActionRule : public soulng::parsing::Rule
{
public:
    ActionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsergen::Parser*"), ToUtf32("parser")));
        SetValueTypeName(ToUtf32("soulng::parsergen::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> parser_value = std::move(stack.top());
        context->parser = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::Parser*>*>(parser_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ActionRule>(this, &ActionRule::A0Action));
        soulng::parsing::NonterminalParser* successCodeNonterminalParser = GetNonterminal(ToUtf32("successCode"));
        successCodeNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ActionRule>(this, &ActionRule::PostsuccessCode));
        soulng::parsing::NonterminalParser* failureCodeNonterminalParser = GetNonterminal(ToUtf32("failureCode"));
        failureCodeNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ActionRule>(this, &ActionRule::PostfailureCode));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::parsergen::ActionParser(context->fromsuccessCode, context->fromfailureCode, context->parser);
    }
    void PostsuccessCode(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromsuccessCode_value = std::move(stack.top());
            context->fromsuccessCode = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CompoundStatement*>*>(fromsuccessCode_value.get());
            stack.pop();
        }
    }
    void PostfailureCode(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromfailureCode_value = std::move(stack.top());
            context->fromfailureCode = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CompoundStatement*>*>(fromfailureCode_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): parser(), value(), fromsuccessCode(), fromfailureCode() {}
        soulng::parsergen::Parser* parser;
        soulng::parsergen::Parser* value;
        soulng::codedom::CompoundStatement* fromsuccessCode;
        soulng::codedom::CompoundStatement* fromfailureCode;
    };
};

class ParserFileGrammar::NonterminalRule : public soulng::parsing::Rule
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
        soulng::parsing::NonterminalParser* ntNonterminalParser = GetNonterminal(ToUtf32("nt"));
        ntNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<NonterminalRule>(this, &NonterminalRule::Postnt));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromnt;
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
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromnt() {}
        std::u32string value;
        std::u32string fromnt;
    };
};

class ParserFileGrammar::ParameterListRule : public soulng::parsing::Rule
{
public:
    ParameterListRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("std::vector<soulng::parsergen::Parameter*>"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<std::vector<soulng::parsergen::Parameter*>>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ParameterListRule>(this, &ParameterListRule::A0Action));
        soulng::parsing::NonterminalParser* paramNonterminalParser = GetNonterminal(ToUtf32("param"));
        paramNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ParameterListRule>(this, &ParameterListRule::Postparam));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value.push_back(context->fromparam);
    }
    void Postparam(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromparam_value = std::move(stack.top());
            context->fromparam = *static_cast<soulng::parsing::ValueObject<soulng::parsergen::Parameter*>*>(fromparam_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromparam() {}
        std::vector<soulng::parsergen::Parameter*> value;
        soulng::parsergen::Parameter* fromparam;
    };
};

class ParserFileGrammar::ParameterRule : public soulng::parsing::Rule
{
public:
    ParameterRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsergen::Parameter*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsergen::Parameter*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ParameterRule>(this, &ParameterRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ParameterRule>(this, &ParameterRule::A1Action));
        soulng::parsing::NonterminalParser* vartypeNonterminalParser = GetNonterminal(ToUtf32("vartype"));
        vartypeNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ParameterRule>(this, &ParameterRule::Postvartype));
        soulng::parsing::NonterminalParser* varnameNonterminalParser = GetNonterminal(ToUtf32("varname"));
        varnameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ParameterRule>(this, &ParameterRule::Postvarname));
        soulng::parsing::NonterminalParser* paramtypeNonterminalParser = GetNonterminal(ToUtf32("paramtype"));
        paramtypeNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ParameterRule>(this, &ParameterRule::Postparamtype));
        soulng::parsing::NonterminalParser* paramnameNonterminalParser = GetNonterminal(ToUtf32("paramname"));
        paramnameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ParameterRule>(this, &ParameterRule::Postparamname));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::parsergen::Variable(context->fromvartype, context->fromvarname);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::parsergen::Parameter(context->fromparamtype, context->fromparamname);
    }
    void Postvartype(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromvartype_value = std::move(stack.top());
            context->fromvartype = *static_cast<soulng::parsing::ValueObject<soulng::codedom::TypeId*>*>(fromvartype_value.get());
            stack.pop();
        }
    }
    void Postvarname(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromvarname_value = std::move(stack.top());
            context->fromvarname = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromvarname_value.get());
            stack.pop();
        }
    }
    void Postparamtype(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromparamtype_value = std::move(stack.top());
            context->fromparamtype = *static_cast<soulng::parsing::ValueObject<soulng::codedom::TypeId*>*>(fromparamtype_value.get());
            stack.pop();
        }
    }
    void Postparamname(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromparamname_value = std::move(stack.top());
            context->fromparamname = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromparamname_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromvartype(), fromvarname(), fromparamtype(), fromparamname() {}
        soulng::parsergen::Parameter* value;
        soulng::codedom::TypeId* fromvartype;
        std::u32string fromvarname;
        soulng::codedom::TypeId* fromparamtype;
        std::u32string fromparamname;
    };
};

class ParserFileGrammar::ReturnTypeRule : public soulng::parsing::Rule
{
public:
    ReturnTypeRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::TypeId*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::TypeId*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ReturnTypeRule>(this, &ReturnTypeRule::A0Action));
        soulng::parsing::NonterminalParser* typeNonterminalParser = GetNonterminal(ToUtf32("type"));
        typeNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ReturnTypeRule>(this, &ReturnTypeRule::Posttype));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromtype;
    }
    void Posttype(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromtype_value = std::move(stack.top());
            context->fromtype = *static_cast<soulng::parsing::ValueObject<soulng::codedom::TypeId*>*>(fromtype_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromtype() {}
        soulng::codedom::TypeId* value;
        soulng::codedom::TypeId* fromtype;
    };
};

class ParserFileGrammar::IdentifierRule : public soulng::parsing::Rule
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
        soulng::parsing::NonterminalParser* idNonterminalParser = GetNonterminal(ToUtf32("id"));
        idNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<IdentifierRule>(this, &IdentifierRule::Postid));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromid;
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
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromid() {}
        std::u32string value;
        std::u32string fromid;
    };
};

class ParserFileGrammar::UsingQualifiedIdRule : public soulng::parsing::Rule
{
public:
    UsingQualifiedIdRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
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
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UsingQualifiedIdRule>(this, &UsingQualifiedIdRule::A0Action));
        soulng::parsing::NonterminalParser* leftNonterminalParser = GetNonterminal(ToUtf32("left"));
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<UsingQualifiedIdRule>(this, &UsingQualifiedIdRule::Postleft));
        soulng::parsing::NonterminalParser* rightNonterminalParser = GetNonterminal(ToUtf32("right"));
        rightNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<UsingQualifiedIdRule>(this, &UsingQualifiedIdRule::Postright));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = std::u32string(matchBegin, matchEnd);
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromleft_value.get());
            stack.pop();
        }
    }
    void Postright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromright_value = std::move(stack.top());
            context->fromright = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromright_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromleft(), fromright() {}
        std::u32string value;
        std::u32string fromleft;
        std::u32string fromright;
    };
};

void ParserFileGrammar::GetReferencedGrammars()
{
    soulng::parsing::ParsingDomain* pd = GetParsingDomain();
    soulng::parsing::Grammar* grammar0 = pd->GetGrammar(ToUtf32("soulng.parsing.stdlib"));
    if (!grammar0)
    {
        grammar0 = soulng::parsing::stdlib::Create(pd);
    }
    AddGrammarReference(grammar0);
    soulng::parsing::Grammar* grammar1 = pd->GetGrammar(ToUtf32("soulng.code.Expression"));
    if (!grammar1)
    {
        grammar1 = soulng::code::Expression::Create(pd);
    }
    AddGrammarReference(grammar1);
    soulng::parsing::Grammar* grammar2 = pd->GetGrammar(ToUtf32("soulng.code.Declarator"));
    if (!grammar2)
    {
        grammar2 = soulng::code::Declarator::Create(pd);
    }
    AddGrammarReference(grammar2);
    soulng::parsing::Grammar* grammar3 = pd->GetGrammar(ToUtf32("soulng.code.Identifier"));
    if (!grammar3)
    {
        grammar3 = soulng::code::Identifier::Create(pd);
    }
    AddGrammarReference(grammar3);
    soulng::parsing::Grammar* grammar4 = pd->GetGrammar(ToUtf32("soulng.code.Statement"));
    if (!grammar4)
    {
        grammar4 = soulng::code::Statement::Create(pd);
    }
    AddGrammarReference(grammar4);
}

void ParserFileGrammar::CreateRules()
{
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("identifier"), this, ToUtf32("soulng.parsing.stdlib.identifier")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("string"), this, ToUtf32("soulng.parsing.stdlib.string")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("Declarator"), this, ToUtf32("soulng.code.Declarator.Declarator")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("spaces_and_comments"), this, ToUtf32("soulng.parsing.stdlib.spaces_and_comments")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("TypeId"), this, ToUtf32("soulng.code.Declarator.TypeId")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("ExpressionList"), this, ToUtf32("soulng.code.Expression.ExpressionList")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("QualifiedId"), this, ToUtf32("soulng.code.Identifier.QualifiedId")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("CompoundStatement"), this, ToUtf32("soulng.code.Statement.CompoundStatement")));
    AddRule(new ParserFileRule(ToUtf32("ParserFile"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::EmptyParser()),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::NonterminalParser(ToUtf32("declaration"), ToUtf32("Declaration"), 1)))));
    AddRule(new DeclarationRule(ToUtf32("Declaration"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::ActionParser(ToUtf32("A0"),
                    new soulng::parsing::NonterminalParser(ToUtf32("include"), ToUtf32("IncludeDeclaration"), 0)),
                new soulng::parsing::ActionParser(ToUtf32("A1"),
                    new soulng::parsing::NonterminalParser(ToUtf32("usingNs"), ToUtf32("UsingNamespaceDeclaration"), 0))),
            new soulng::parsing::ActionParser(ToUtf32("A2"),
                new soulng::parsing::NonterminalParser(ToUtf32("grmr"), ToUtf32("GrammarDeclaration"), 0)))));
    AddRule(new IncludeDeclarationRule(ToUtf32("IncludeDeclaration"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::OptionalParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("prefix"), ToUtf32("IncludePrefix"), 0)),
                    new soulng::parsing::ActionParser(ToUtf32("A1"),
                        new soulng::parsing::GroupingParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::StringParser(ToUtf32("#include")),
                                new soulng::parsing::TokenParser(
                                    new soulng::parsing::SequenceParser(
                                        new soulng::parsing::SequenceParser(
                                            new soulng::parsing::CharParser('<'),
                                            new soulng::parsing::KleeneStarParser(
                                                new soulng::parsing::CharSetParser(ToUtf32(">"), true))),
                                        new soulng::parsing::CharParser('>')))))))))));
    AddRule(new IncludePrefixRule(ToUtf32("IncludePrefix"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::StringParser(ToUtf32("[cpp]"))),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::StringParser(ToUtf32("[hpp]"))))));
    AddRule(new UsingNamespaceDeclarationRule(ToUtf32("UsingNamespaceDeclaration"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::KeywordParser(ToUtf32("using")),
                            new soulng::parsing::KeywordParser(ToUtf32("namespace"))),
                        new soulng::parsing::NonterminalParser(ToUtf32("qid"), ToUtf32("QualifiedId"), 0)),
                    new soulng::parsing::CharParser(';'))))));
    AddRule(new GrammarDeclarationRule(ToUtf32("GrammarDeclaration"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::KeywordParser(ToUtf32("parser")),
                        new soulng::parsing::ActionParser(ToUtf32("A0"),
                            new soulng::parsing::NonterminalParser(ToUtf32("grammarName"), ToUtf32("Identifier"), 0))),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser('{'))),
                new soulng::parsing::KleeneStarParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("GrammarStatement"), ToUtf32("GrammarStatement"), 1))),
            new soulng::parsing::ExpectationParser(
                new soulng::parsing::CharParser('}')))));
    AddRule(new GrammarStatementRule(ToUtf32("GrammarStatement"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::AlternativeParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("MainStatement"), ToUtf32("MainStatement"), 1),
                        new soulng::parsing::NonterminalParser(ToUtf32("UsingStatement"), ToUtf32("UsingStatement"), 1)),
                    new soulng::parsing::NonterminalParser(ToUtf32("LexerStatement"), ToUtf32("LexerStatement"), 1)),
                new soulng::parsing::NonterminalParser(ToUtf32("RuleInfoStatement"), ToUtf32("RuleInfoStatement"), 1)),
            new soulng::parsing::NonterminalParser(ToUtf32("RuleStatement"), ToUtf32("RuleStatement"), 1))));
    AddRule(new MainStatementRule(ToUtf32("MainStatement"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::KeywordParser(ToUtf32("main")),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser(';')))))));
    AddRule(new UsingStatementRule(ToUtf32("UsingStatement"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::KeywordParser(ToUtf32("using")),
                        new soulng::parsing::NonterminalParser(ToUtf32("id"), ToUtf32("UsingQualifiedId"), 0)),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser(';')))))));
    AddRule(new LexerStatementRule(ToUtf32("LexerStatement"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::KeywordParser(ToUtf32("lexer")),
                        new soulng::parsing::NonterminalParser(ToUtf32("id"), ToUtf32("Identifier"), 0)),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser(';')))))));
    AddRule(new RuleInfoStatementRule(ToUtf32("RuleInfoStatement"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::KeywordParser(ToUtf32("ruleinfo")),
                    new soulng::parsing::CharParser('{')),
                new soulng::parsing::OptionalParser(
                    new soulng::parsing::GroupingParser(
                        new soulng::parsing::ListParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("RuleInfo"), ToUtf32("RuleInfo"), 1),
                            new soulng::parsing::CharParser(','))))),
            new soulng::parsing::CharParser('}'))));
    AddRule(new RuleInfoRule(ToUtf32("RuleInfo"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::CharParser('('),
                                new soulng::parsing::ExpectationParser(
                                    new soulng::parsing::NonterminalParser(ToUtf32("ruleName"), ToUtf32("Identifier"), 0))),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::CharParser(','))),
                        new soulng::parsing::ExpectationParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("ruleInfo"), ToUtf32("string"), 0))),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser(')')))))));
    AddRule(new RuleStatementRule(ToUtf32("RuleStatement"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::SequenceParser(
                                    new soulng::parsing::NonterminalParser(ToUtf32("ruleName"), ToUtf32("Identifier"), 0),
                                    new soulng::parsing::OptionalParser(
                                        new soulng::parsing::NonterminalParser(ToUtf32("params"), ToUtf32("ParameterList"), 0))),
                                new soulng::parsing::OptionalParser(
                                    new soulng::parsing::NonterminalParser(ToUtf32("returnType"), ToUtf32("ReturnType"), 0))),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::StringParser(ToUtf32("::=")))),
                        new soulng::parsing::ExpectationParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("definition"), ToUtf32("RuleBody"), 0))),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser(';')))))));
    AddRule(new RuleBodyRule(ToUtf32("RuleBody"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::NonterminalParser(ToUtf32("alt"), ToUtf32("Alternative"), 0))));
    AddRule(new AlternativeRule(ToUtf32("Alternative"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("Sequence"), 0)),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::CharParser('|'),
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("right"), ToUtf32("Sequence"), 0)))))))));
    AddRule(new SequenceRule(ToUtf32("Sequence"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("Difference"), 0)),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::ActionParser(ToUtf32("A1"),
                        new soulng::parsing::NonterminalParser(ToUtf32("right"), ToUtf32("Difference"), 0)))))));
    AddRule(new DifferenceRule(ToUtf32("Difference"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("List"), 0)),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::CharParser('-'),
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("right"), ToUtf32("List"), 0)))))))));
    AddRule(new ListRule(ToUtf32("List"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("Postfix"), 0)),
            new soulng::parsing::OptionalParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::CharParser('%'),
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("right"), ToUtf32("Postfix"), 0)))))))));
    AddRule(new PostfixRule(ToUtf32("Postfix"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("primary"), ToUtf32("Primary"), 0)),
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
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::AlternativeParser(
                        new soulng::parsing::AlternativeParser(
                            new soulng::parsing::ActionParser(ToUtf32("A0"),
                                new soulng::parsing::NonterminalParser(ToUtf32("RuleCall"), ToUtf32("RuleCall"), 0)),
                            new soulng::parsing::ActionParser(ToUtf32("A1"),
                                new soulng::parsing::NonterminalParser(ToUtf32("Primitive"), ToUtf32("Primitive"), 0))),
                        new soulng::parsing::ActionParser(ToUtf32("A2"),
                            new soulng::parsing::NonterminalParser(ToUtf32("Grouping"), ToUtf32("Grouping"), 0)))),
                new soulng::parsing::OptionalParser(
                    new soulng::parsing::GroupingParser(
                        new soulng::parsing::ActionParser(ToUtf32("A3"),
                            new soulng::parsing::NonterminalParser(ToUtf32("Expectation"), ToUtf32("Expectation"), 1))))),
            new soulng::parsing::OptionalParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::ActionParser(ToUtf32("A4"),
                        new soulng::parsing::NonterminalParser(ToUtf32("Action"), ToUtf32("Action"), 1)))))));
    AddRule(new RuleCallRule(ToUtf32("RuleCall"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::GroupingParser(
                            new soulng::parsing::AlternativeParser(
                                new soulng::parsing::SequenceParser(
                                    new soulng::parsing::SequenceParser(
                                        new soulng::parsing::TokenParser(
                                            new soulng::parsing::SequenceParser(
                                                new soulng::parsing::NonterminalParser(ToUtf32("ntArgs"), ToUtf32("Nonterminal"), 0),
                                                new soulng::parsing::CharParser('('))),
                                        new soulng::parsing::ExpectationParser(
                                            new soulng::parsing::NonterminalParser(ToUtf32("args"), ToUtf32("ExpressionList"), 0))),
                                    new soulng::parsing::ExpectationParser(
                                        new soulng::parsing::CharParser(')'))),
                                new soulng::parsing::NonterminalParser(ToUtf32("nt"), ToUtf32("Nonterminal"), 0))),
                        new soulng::parsing::CharParser(':')),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("name"), ToUtf32("Identifier"), 0)))))));
    AddRule(new PrimitiveRule(ToUtf32("Primitive"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::KeywordParser(ToUtf32("empty"))),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::NonterminalParser(ToUtf32("tkn"), ToUtf32("Identifier"), 0)))));
    AddRule(new GroupingRule(ToUtf32("Grouping"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::CharParser('('),
                        new soulng::parsing::ExpectationParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("alt"), ToUtf32("Alternative"), 0))),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser(')')))))));
    AddRule(new ExpectationRule(ToUtf32("Expectation"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::CharParser('!'))));
    AddRule(new ActionRule(ToUtf32("Action"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("successCode"), ToUtf32("CompoundStatement"), 0),
                    new soulng::parsing::OptionalParser(
                        new soulng::parsing::GroupingParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::CharParser('/'),
                                new soulng::parsing::NonterminalParser(ToUtf32("failureCode"), ToUtf32("CompoundStatement"), 0)))))))));
    AddRule(new NonterminalRule(ToUtf32("Nonterminal"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::NonterminalParser(ToUtf32("nt"), ToUtf32("Identifier"), 0))));
    AddRule(new ParameterListRule(ToUtf32("ParameterList"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::CharParser('('),
                new soulng::parsing::OptionalParser(
                    new soulng::parsing::GroupingParser(
                        new soulng::parsing::ListParser(
                            new soulng::parsing::ActionParser(ToUtf32("A0"),
                                new soulng::parsing::NonterminalParser(ToUtf32("param"), ToUtf32("Parameter"), 0)),
                            new soulng::parsing::CharParser(','))))),
            new soulng::parsing::ExpectationParser(
                new soulng::parsing::CharParser(')')))));
    AddRule(new ParameterRule(ToUtf32("Parameter"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::KeywordParser(ToUtf32("var")),
                            new soulng::parsing::NonterminalParser(ToUtf32("vartype"), ToUtf32("TypeId"), 0)),
                        new soulng::parsing::NonterminalParser(ToUtf32("varname"), ToUtf32("Declarator"), 0)))),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("paramtype"), ToUtf32("TypeId"), 0),
                        new soulng::parsing::NonterminalParser(ToUtf32("paramname"), ToUtf32("Declarator"), 0)))))));
    AddRule(new ReturnTypeRule(ToUtf32("ReturnType"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::CharParser(':'),
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("type"), ToUtf32("TypeId"), 0)))));
    AddRule(new soulng::parsing::Rule(ToUtf32("Keyword"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::KeywordListParser(ToUtf32("identifier"), keywords0)));
    AddRule(new IdentifierRule(ToUtf32("Identifier"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::DifferenceParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("id"), ToUtf32("identifier"), 0),
                    new soulng::parsing::NonterminalParser(ToUtf32("Keyword"), ToUtf32("Keyword"), 0))))));
    AddRule(new UsingQualifiedIdRule(ToUtf32("UsingQualifiedId"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::TokenParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("Identifier"), 0),
                    new soulng::parsing::KleeneStarParser(
                        new soulng::parsing::GroupingParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::CharParser('.'),
                                new soulng::parsing::NonterminalParser(ToUtf32("right"), ToUtf32("Identifier"), 0)))))))));
    SetSkipRuleName(ToUtf32("spaces_and_comments"));
}

} } // namespace soulng.parsergen
