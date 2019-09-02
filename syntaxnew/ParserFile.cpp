#include "ParserFile.hpp"
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
#include <soulng/parsing/Namespace.hpp>
#include <soulng/parsing/Grammar.hpp>
#include <soulng/code/Declaration.hpp>
#include <soulng/syntax/Element.hpp>
#include <soulng/syntax/Grammar.hpp>

namespace soulng { namespace syntax {

using namespace soulng::parsing;
using namespace soulng::util;
using namespace soulng::unicode;

ParserFile* ParserFile::Create()
{
    return Create(new soulng::parsing::ParsingDomain());
}

ParserFile* ParserFile::Create(soulng::parsing::ParsingDomain* parsingDomain)
{
    RegisterParsingDomain(parsingDomain);
    ParserFile* grammar(new ParserFile(parsingDomain));
    parsingDomain->AddGrammar(grammar);
    grammar->CreateRules();
    grammar->Link();
    return grammar;
}

ParserFile::ParserFile(soulng::parsing::ParsingDomain* parsingDomain_): soulng::parsing::Grammar(ToUtf32("ParserFile"), parsingDomain_->GetNamespaceScope(ToUtf32("soulng.syntax")), parsingDomain_)
{
    SetOwner(0);
}

ParserFileContent* ParserFile::Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName, int id_, soulng::parsing::ParsingDomain* parsingDomain_)
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
    stack.push(std::unique_ptr<soulng::parsing::Object>(new ValueObject<int>(id_)));
    stack.push(std::unique_ptr<soulng::parsing::Object>(new ValueObject<soulng::parsing::ParsingDomain*>(parsingDomain_)));
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
    ParserFileContent* result = *static_cast<soulng::parsing::ValueObject<ParserFileContent*>*>(value.get());
    stack.pop();
    return result;
}

class ParserFile::ParserFileRule : public soulng::parsing::Rule
{
public:
    ParserFileRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("int"), ToUtf32("id_")));
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::parsing::ParsingDomain*"), ToUtf32("parsingDomain_")));
        SetValueTypeName(ToUtf32("ParserFileContent*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> parsingDomain__value = std::move(stack.top());
        context->parsingDomain_ = *static_cast<soulng::parsing::ValueObject<soulng::parsing::ParsingDomain*>*>(parsingDomain__value.get());
        stack.pop();
        std::unique_ptr<soulng::parsing::Object> id__value = std::move(stack.top());
        context->id_ = *static_cast<soulng::parsing::ValueObject<int>*>(id__value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<ParserFileContent*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ParserFileRule>(this, &ParserFileRule::A0Action));
        soulng::parsing::NonterminalParser* includeDirectivesNonterminalParser = GetNonterminal(ToUtf32("IncludeDirectives"));
        includeDirectivesNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<ParserFileRule>(this, &ParserFileRule::PreIncludeDirectives));
        soulng::parsing::NonterminalParser* namespaceContentNonterminalParser = GetNonterminal(ToUtf32("NamespaceContent"));
        namespaceContentNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<ParserFileRule>(this, &ParserFileRule::PreNamespaceContent));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new ParserFileContent(context->id_, context->parsingDomain_);
        context->value->SetFilePath(fileName);
    }
    void PreIncludeDirectives(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<ParserFileContent*>(context->value)));
    }
    void PreNamespaceContent(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<ParserFileContent*>(context->value)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): id_(), parsingDomain_(), value() {}
        int id_;
        soulng::parsing::ParsingDomain* parsingDomain_;
        ParserFileContent* value;
    };
};

class ParserFile::IncludeDirectivesRule : public soulng::parsing::Rule
{
public:
    IncludeDirectivesRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("ParserFileContent*"), ToUtf32("parserFileContent")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> parserFileContent_value = std::move(stack.top());
        context->parserFileContent = *static_cast<soulng::parsing::ValueObject<ParserFileContent*>*>(parserFileContent_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::NonterminalParser* includeDirectiveNonterminalParser = GetNonterminal(ToUtf32("IncludeDirective"));
        includeDirectiveNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<IncludeDirectivesRule>(this, &IncludeDirectivesRule::PreIncludeDirective));
    }
    void PreIncludeDirective(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<ParserFileContent*>(context->parserFileContent)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): parserFileContent() {}
        ParserFileContent* parserFileContent;
    };
};

class ParserFile::IncludeDirectiveRule : public soulng::parsing::Rule
{
public:
    IncludeDirectiveRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("ParserFileContent*"), ToUtf32("parserFileContent")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> parserFileContent_value = std::move(stack.top());
        context->parserFileContent = *static_cast<soulng::parsing::ValueObject<ParserFileContent*>*>(parserFileContent_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<IncludeDirectiveRule>(this, &IncludeDirectiveRule::A0Action));
        soulng::parsing::NonterminalParser* fileAttributeNonterminalParser = GetNonterminal(ToUtf32("FileAttribute"));
        fileAttributeNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<IncludeDirectiveRule>(this, &IncludeDirectiveRule::PostFileAttribute));
        soulng::parsing::NonterminalParser* includeFileNameNonterminalParser = GetNonterminal(ToUtf32("IncludeFileName"));
        includeFileNameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<IncludeDirectiveRule>(this, &IncludeDirectiveRule::PostIncludeFileName));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->parserFileContent->AddIncludeDirective(ToUtf8(context->fromIncludeFileName), ToUtf8(context->fromFileAttribute));
    }
    void PostFileAttribute(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromFileAttribute_value = std::move(stack.top());
            context->fromFileAttribute = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromFileAttribute_value.get());
            stack.pop();
        }
    }
    void PostIncludeFileName(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromIncludeFileName_value = std::move(stack.top());
            context->fromIncludeFileName = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromIncludeFileName_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): parserFileContent(), fromFileAttribute(), fromIncludeFileName() {}
        ParserFileContent* parserFileContent;
        std::u32string fromFileAttribute;
        std::u32string fromIncludeFileName;
    };
};

class ParserFile::FileAttributeRule : public soulng::parsing::Rule
{
public:
    FileAttributeRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
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
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<FileAttributeRule>(this, &FileAttributeRule::A0Action));
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

class ParserFile::IncludeFileNameRule : public soulng::parsing::Rule
{
public:
    IncludeFileNameRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
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
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<IncludeFileNameRule>(this, &IncludeFileNameRule::A0Action));
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

class ParserFile::NamespaceContentRule : public soulng::parsing::Rule
{
public:
    NamespaceContentRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("ParserFileContent*"), ToUtf32("parserFileContent")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> parserFileContent_value = std::move(stack.top());
        context->parserFileContent = *static_cast<soulng::parsing::ValueObject<ParserFileContent*>*>(parserFileContent_value.get());
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
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NamespaceContentRule>(this, &NamespaceContentRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NamespaceContentRule>(this, &NamespaceContentRule::A2Action));
        soulng::parsing::ActionParser* a3ActionParser = GetAction(ToUtf32("A3"));
        a3ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NamespaceContentRule>(this, &NamespaceContentRule::A3Action));
        soulng::parsing::NonterminalParser* fileAttributeNonterminalParser = GetNonterminal(ToUtf32("FileAttribute"));
        fileAttributeNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<NamespaceContentRule>(this, &NamespaceContentRule::PostFileAttribute));
        soulng::parsing::NonterminalParser* usingDeclarationNonterminalParser = GetNonterminal(ToUtf32("UsingDeclaration"));
        usingDeclarationNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<NamespaceContentRule>(this, &NamespaceContentRule::PostUsingDeclaration));
        soulng::parsing::NonterminalParser* usingDirectiveNonterminalParser = GetNonterminal(ToUtf32("UsingDirective"));
        usingDirectiveNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<NamespaceContentRule>(this, &NamespaceContentRule::PostUsingDirective));
        soulng::parsing::NonterminalParser* namespaceAliasDefinitionNonterminalParser = GetNonterminal(ToUtf32("NamespaceAliasDefinition"));
        namespaceAliasDefinitionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<NamespaceContentRule>(this, &NamespaceContentRule::PostNamespaceAliasDefinition));
        soulng::parsing::NonterminalParser* grammarNonterminalParser = GetNonterminal(ToUtf32("Grammar"));
        grammarNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<NamespaceContentRule>(this, &NamespaceContentRule::PreGrammar));
        grammarNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<NamespaceContentRule>(this, &NamespaceContentRule::PostGrammar));
        soulng::parsing::NonterminalParser* namespaceNonterminalParser = GetNonterminal(ToUtf32("Namespace"));
        namespaceNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<NamespaceContentRule>(this, &NamespaceContentRule::PreNamespace));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->fromUsingDeclaration->SetFileAttr(context->fromFileAttribute);
        context->parserFileContent->AddUsingObject(context->fromUsingDeclaration);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->fromUsingDirective->SetFileAttr(context->fromFileAttribute);
        context->parserFileContent->AddUsingObject(context->fromUsingDirective);
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->fromNamespaceAliasDefinition->SetFileAttr(context->fromFileAttribute);
        context->parserFileContent->AddUsingObject(context->fromNamespaceAliasDefinition);
    }
    void A3Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->parserFileContent->AddGrammar(context->fromGrammar);
    }
    void PostFileAttribute(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromFileAttribute_value = std::move(stack.top());
            context->fromFileAttribute = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromFileAttribute_value.get());
            stack.pop();
        }
    }
    void PostUsingDeclaration(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromUsingDeclaration_value = std::move(stack.top());
            context->fromUsingDeclaration = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::UsingObject*>*>(fromUsingDeclaration_value.get());
            stack.pop();
        }
    }
    void PostUsingDirective(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromUsingDirective_value = std::move(stack.top());
            context->fromUsingDirective = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::UsingObject*>*>(fromUsingDirective_value.get());
            stack.pop();
        }
    }
    void PostNamespaceAliasDefinition(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromNamespaceAliasDefinition_value = std::move(stack.top());
            context->fromNamespaceAliasDefinition = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::UsingObject*>*>(fromNamespaceAliasDefinition_value.get());
            stack.pop();
        }
    }
    void PreGrammar(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Scope*>(context->parserFileContent->CurrentScope())));
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
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<ParserFileContent*>(context->parserFileContent)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): parserFileContent(), fromFileAttribute(), fromUsingDeclaration(), fromUsingDirective(), fromNamespaceAliasDefinition(), fromGrammar() {}
        ParserFileContent* parserFileContent;
        std::u32string fromFileAttribute;
        soulng::cppcode::UsingObject* fromUsingDeclaration;
        soulng::cppcode::UsingObject* fromUsingDirective;
        soulng::cppcode::UsingObject* fromNamespaceAliasDefinition;
        soulng::parsing::Grammar* fromGrammar;
    };
};

class ParserFile::NamespaceRule : public soulng::parsing::Rule
{
public:
    NamespaceRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("ParserFileContent*"), ToUtf32("parserFileContent")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> parserFileContent_value = std::move(stack.top());
        context->parserFileContent = *static_cast<soulng::parsing::ValueObject<ParserFileContent*>*>(parserFileContent_value.get());
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
        context->parserFileContent->BeginNamespace(context->fromns);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->parserFileContent->EndNamespace();
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
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<ParserFileContent*>(context->parserFileContent)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): parserFileContent(), fromns() {}
        ParserFileContent* parserFileContent;
        std::u32string fromns;
    };
};

void ParserFile::GetReferencedGrammars()
{
    soulng::parsing::ParsingDomain* pd = GetParsingDomain();
    soulng::parsing::Grammar* grammar0 = pd->GetGrammar(ToUtf32("soulng.syntax.GrammarGrammar"));
    if (!grammar0)
    {
        grammar0 = soulng::syntax::GrammarGrammar::Create(pd);
    }
    AddGrammarReference(grammar0);
    soulng::parsing::Grammar* grammar1 = pd->GetGrammar(ToUtf32("soulng.parsing.stdlib"));
    if (!grammar1)
    {
        grammar1 = soulng::parsing::stdlib::Create(pd);
    }
    AddGrammarReference(grammar1);
    soulng::parsing::Grammar* grammar2 = pd->GetGrammar(ToUtf32("soulng.code.Declaration"));
    if (!grammar2)
    {
        grammar2 = soulng::code::Declaration::Create(pd);
    }
    AddGrammarReference(grammar2);
}

void ParserFile::CreateRules()
{
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("Grammar"), this, ToUtf32("GrammarGrammar.Grammar")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("newline"), this, ToUtf32("soulng.parsing.stdlib.newline")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("spaces_and_comments"), this, ToUtf32("soulng.parsing.stdlib.spaces_and_comments")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("qualified_id"), this, ToUtf32("soulng.parsing.stdlib.qualified_id")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("UsingDeclaration"), this, ToUtf32("soulng.code.Declaration.UsingDeclaration")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("UsingDirective"), this, ToUtf32("soulng.code.Declaration.UsingDirective")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("NamespaceAliasDefinition"), this, ToUtf32("soulng.code.Declaration.NamespaceAliasDefinition")));
    AddRule(new ParserFileRule(ToUtf32("ParserFile"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::ActionParser(ToUtf32("A0"),
                    new soulng::parsing::EmptyParser()),
                new soulng::parsing::OptionalParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("IncludeDirectives"), ToUtf32("IncludeDirectives"), 1))),
            new soulng::parsing::NonterminalParser(ToUtf32("NamespaceContent"), ToUtf32("NamespaceContent"), 1))));
    AddRule(new IncludeDirectivesRule(ToUtf32("IncludeDirectives"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::PositiveParser(
            new soulng::parsing::NonterminalParser(ToUtf32("IncludeDirective"), ToUtf32("IncludeDirective"), 1))));
    AddRule(new IncludeDirectiveRule(ToUtf32("IncludeDirective"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::OptionalParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("FileAttribute"), ToUtf32("FileAttribute"), 0)),
                    new soulng::parsing::CharParser('#')),
                new soulng::parsing::KeywordParser(ToUtf32("include"))),
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::TokenParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("IncludeFileName"), ToUtf32("IncludeFileName"), 0),
                            new soulng::parsing::KleeneStarParser(
                                new soulng::parsing::CharSetParser(ToUtf32("\r\n"), true))),
                        new soulng::parsing::NonterminalParser(ToUtf32("newline"), ToUtf32("newline"), 0)))))));
    AddRule(new FileAttributeRule(ToUtf32("FileAttribute"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::CharParser('['),
                new soulng::parsing::ActionParser(ToUtf32("A0"),
                    new soulng::parsing::GroupingParser(
                        new soulng::parsing::AlternativeParser(
                            new soulng::parsing::StringParser(ToUtf32("cpp")),
                            new soulng::parsing::StringParser(ToUtf32("hpp")))))),
            new soulng::parsing::CharParser(']'))));
    AddRule(new IncludeFileNameRule(ToUtf32("IncludeFileName"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::TokenParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::CharParser('<'),
                        new soulng::parsing::PositiveParser(
                            new soulng::parsing::CharSetParser(ToUtf32(">\r\n"), true))),
                    new soulng::parsing::CharParser('>'))))));
    AddRule(new NamespaceContentRule(ToUtf32("NamespaceContent"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::KleeneStarParser(
            new soulng::parsing::GroupingParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::AlternativeParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::OptionalParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("FileAttribute"), ToUtf32("FileAttribute"), 0)),
                            new soulng::parsing::GroupingParser(
                                new soulng::parsing::AlternativeParser(
                                    new soulng::parsing::AlternativeParser(
                                        new soulng::parsing::ActionParser(ToUtf32("A0"),
                                            new soulng::parsing::NonterminalParser(ToUtf32("UsingDeclaration"), ToUtf32("UsingDeclaration"), 0)),
                                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                                            new soulng::parsing::NonterminalParser(ToUtf32("UsingDirective"), ToUtf32("UsingDirective"), 0))),
                                    new soulng::parsing::ActionParser(ToUtf32("A2"),
                                        new soulng::parsing::NonterminalParser(ToUtf32("NamespaceAliasDefinition"), ToUtf32("NamespaceAliasDefinition"), 0))))),
                        new soulng::parsing::ActionParser(ToUtf32("A3"),
                            new soulng::parsing::NonterminalParser(ToUtf32("Grammar"), ToUtf32("Grammar"), 1))),
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
    SetSkipRuleName(ToUtf32("spaces_and_comments"));
}

} } // namespace soulng.syntax
