#include "Declaration.hpp"
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
#include <soulng/code/Identifier.hpp>
#include <soulng/code/Expression.hpp>
#include <soulng/cppcode/Type.hpp>

namespace soulng { namespace code {

using namespace soulng::cppcode;
using namespace soulng::parsing;
using namespace soulng::util;
using namespace soulng::unicode;

Declaration* Declaration::Create()
{
    return Create(new soulng::parsing::ParsingDomain());
}

Declaration* Declaration::Create(soulng::parsing::ParsingDomain* parsingDomain)
{
    RegisterParsingDomain(parsingDomain);
    Declaration* grammar(new Declaration(parsingDomain));
    parsingDomain->AddGrammar(grammar);
    grammar->CreateRules();
    grammar->Link();
    return grammar;
}

Declaration::Declaration(soulng::parsing::ParsingDomain* parsingDomain_): soulng::parsing::Grammar(ToUtf32("Declaration"), parsingDomain_->GetNamespaceScope(ToUtf32("soulng.code")), parsingDomain_)
{
    SetOwner(0);
    keywords0.push_back(ToUtf32("auto"));
    keywords0.push_back(ToUtf32("extern"));
    keywords0.push_back(ToUtf32("mutable"));
    keywords0.push_back(ToUtf32("register"));
    keywords0.push_back(ToUtf32("static"));
    keywords1.push_back(ToUtf32("bool"));
    keywords1.push_back(ToUtf32("char"));
    keywords1.push_back(ToUtf32("double"));
    keywords1.push_back(ToUtf32("float"));
    keywords1.push_back(ToUtf32("int"));
    keywords1.push_back(ToUtf32("long"));
    keywords1.push_back(ToUtf32("short"));
    keywords1.push_back(ToUtf32("signed"));
    keywords1.push_back(ToUtf32("unsigned"));
    keywords1.push_back(ToUtf32("void"));
    keywords1.push_back(ToUtf32("wchar_t"));
}

soulng::cppcode::CppObject* Declaration::Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName)
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
    soulng::cppcode::CppObject* result = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::CppObject*>*>(value.get());
    stack.pop();
    return result;
}

class Declaration::BlockDeclarationRule : public soulng::parsing::Rule
{
public:
    BlockDeclarationRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::CppObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<BlockDeclarationRule>(this, &BlockDeclarationRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<BlockDeclarationRule>(this, &BlockDeclarationRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<BlockDeclarationRule>(this, &BlockDeclarationRule::A2Action));
        soulng::parsing::ActionParser* a3ActionParser = GetAction(ToUtf32("A3"));
        a3ActionParser->SetAction(new soulng::parsing::MemberParsingAction<BlockDeclarationRule>(this, &BlockDeclarationRule::A3Action));
        soulng::parsing::NonterminalParser* namespaceAliasDefinitionNonterminalParser = GetNonterminal(ToUtf32("NamespaceAliasDefinition"));
        namespaceAliasDefinitionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<BlockDeclarationRule>(this, &BlockDeclarationRule::PostNamespaceAliasDefinition));
        soulng::parsing::NonterminalParser* usingDirectiveNonterminalParser = GetNonterminal(ToUtf32("UsingDirective"));
        usingDirectiveNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<BlockDeclarationRule>(this, &BlockDeclarationRule::PostUsingDirective));
        soulng::parsing::NonterminalParser* usingDeclarationNonterminalParser = GetNonterminal(ToUtf32("UsingDeclaration"));
        usingDeclarationNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<BlockDeclarationRule>(this, &BlockDeclarationRule::PostUsingDeclaration));
        soulng::parsing::NonterminalParser* simpleDeclarationNonterminalParser = GetNonterminal(ToUtf32("SimpleDeclaration"));
        simpleDeclarationNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<BlockDeclarationRule>(this, &BlockDeclarationRule::PostSimpleDeclaration));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromNamespaceAliasDefinition;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromUsingDirective;
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromUsingDeclaration;
    }
    void A3Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromSimpleDeclaration;
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
    void PostSimpleDeclaration(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromSimpleDeclaration_value = std::move(stack.top());
            context->fromSimpleDeclaration = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::SimpleDeclaration*>*>(fromSimpleDeclaration_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromNamespaceAliasDefinition(), fromUsingDirective(), fromUsingDeclaration(), fromSimpleDeclaration() {}
        soulng::cppcode::CppObject* value;
        soulng::cppcode::UsingObject* fromNamespaceAliasDefinition;
        soulng::cppcode::UsingObject* fromUsingDirective;
        soulng::cppcode::UsingObject* fromUsingDeclaration;
        soulng::cppcode::SimpleDeclaration* fromSimpleDeclaration;
    };
};

class Declaration::SimpleDeclarationRule : public soulng::parsing::Rule
{
public:
    SimpleDeclarationRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::SimpleDeclaration*"));
        AddLocalVariable(AttrOrVariable(ToUtf32("std::unique_ptr<SimpleDeclaration>"), ToUtf32("sd")));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::SimpleDeclaration*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<SimpleDeclarationRule>(this, &SimpleDeclarationRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<SimpleDeclarationRule>(this, &SimpleDeclarationRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<SimpleDeclarationRule>(this, &SimpleDeclarationRule::A2Action));
        soulng::parsing::NonterminalParser* declSpecifierSeqNonterminalParser = GetNonterminal(ToUtf32("DeclSpecifierSeq"));
        declSpecifierSeqNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<SimpleDeclarationRule>(this, &SimpleDeclarationRule::PreDeclSpecifierSeq));
        soulng::parsing::NonterminalParser* initDeclaratorListNonterminalParser = GetNonterminal(ToUtf32("InitDeclaratorList"));
        initDeclaratorListNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<SimpleDeclarationRule>(this, &SimpleDeclarationRule::PostInitDeclaratorList));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->sd.reset(new SimpleDeclaration);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->sd.release();
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->sd->SetInitDeclaratorList(context->fromInitDeclaratorList);
    }
    void PreDeclSpecifierSeq(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::SimpleDeclaration*>(context->sd.get())));
    }
    void PostInitDeclaratorList(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromInitDeclaratorList_value = std::move(stack.top());
            context->fromInitDeclaratorList = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::InitDeclaratorList*>*>(fromInitDeclaratorList_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), sd(), fromInitDeclaratorList() {}
        soulng::cppcode::SimpleDeclaration* value;
        std::unique_ptr<SimpleDeclaration> sd;
        soulng::cppcode::InitDeclaratorList* fromInitDeclaratorList;
    };
};

class Declaration::DeclSpecifierSeqRule : public soulng::parsing::Rule
{
public:
    DeclSpecifierSeqRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::cppcode::SimpleDeclaration*"), ToUtf32("declaration")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> declaration_value = std::move(stack.top());
        context->declaration = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::SimpleDeclaration*>*>(declaration_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeclSpecifierSeqRule>(this, &DeclSpecifierSeqRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeclSpecifierSeqRule>(this, &DeclSpecifierSeqRule::A1Action));
        soulng::parsing::NonterminalParser* declSpecifierNonterminalParser = GetNonterminal(ToUtf32("DeclSpecifier"));
        declSpecifierNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DeclSpecifierSeqRule>(this, &DeclSpecifierSeqRule::PostDeclSpecifier));
        soulng::parsing::NonterminalParser* typeNameNonterminalParser = GetNonterminal(ToUtf32("TypeName"));
        typeNameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DeclSpecifierSeqRule>(this, &DeclSpecifierSeqRule::PostTypeName));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->declaration->Add(context->fromDeclSpecifier);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->declaration->Add(context->fromTypeName);
    }
    void PostDeclSpecifier(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromDeclSpecifier_value = std::move(stack.top());
            context->fromDeclSpecifier = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::DeclSpecifier*>*>(fromDeclSpecifier_value.get());
            stack.pop();
        }
    }
    void PostTypeName(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromTypeName_value = std::move(stack.top());
            context->fromTypeName = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::TypeName*>*>(fromTypeName_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): declaration(), fromDeclSpecifier(), fromTypeName() {}
        soulng::cppcode::SimpleDeclaration* declaration;
        soulng::cppcode::DeclSpecifier* fromDeclSpecifier;
        soulng::cppcode::TypeName* fromTypeName;
    };
};

class Declaration::DeclSpecifierRule : public soulng::parsing::Rule
{
public:
    DeclSpecifierRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::DeclSpecifier*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::DeclSpecifier*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeclSpecifierRule>(this, &DeclSpecifierRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeclSpecifierRule>(this, &DeclSpecifierRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeclSpecifierRule>(this, &DeclSpecifierRule::A2Action));
        soulng::parsing::NonterminalParser* storageClassSpecifierNonterminalParser = GetNonterminal(ToUtf32("StorageClassSpecifier"));
        storageClassSpecifierNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DeclSpecifierRule>(this, &DeclSpecifierRule::PostStorageClassSpecifier));
        soulng::parsing::NonterminalParser* typeSpecifierNonterminalParser = GetNonterminal(ToUtf32("TypeSpecifier"));
        typeSpecifierNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DeclSpecifierRule>(this, &DeclSpecifierRule::PostTypeSpecifier));
        soulng::parsing::NonterminalParser* typedefNonterminalParser = GetNonterminal(ToUtf32("Typedef"));
        typedefNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DeclSpecifierRule>(this, &DeclSpecifierRule::PostTypedef));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromStorageClassSpecifier;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromTypeSpecifier;
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromTypedef;
    }
    void PostStorageClassSpecifier(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromStorageClassSpecifier_value = std::move(stack.top());
            context->fromStorageClassSpecifier = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::StorageClassSpecifier*>*>(fromStorageClassSpecifier_value.get());
            stack.pop();
        }
    }
    void PostTypeSpecifier(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromTypeSpecifier_value = std::move(stack.top());
            context->fromTypeSpecifier = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::TypeSpecifier*>*>(fromTypeSpecifier_value.get());
            stack.pop();
        }
    }
    void PostTypedef(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromTypedef_value = std::move(stack.top());
            context->fromTypedef = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::DeclSpecifier*>*>(fromTypedef_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromStorageClassSpecifier(), fromTypeSpecifier(), fromTypedef() {}
        soulng::cppcode::DeclSpecifier* value;
        soulng::cppcode::StorageClassSpecifier* fromStorageClassSpecifier;
        soulng::cppcode::TypeSpecifier* fromTypeSpecifier;
        soulng::cppcode::DeclSpecifier* fromTypedef;
    };
};

class Declaration::StorageClassSpecifierRule : public soulng::parsing::Rule
{
public:
    StorageClassSpecifierRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::StorageClassSpecifier*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::StorageClassSpecifier*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<StorageClassSpecifierRule>(this, &StorageClassSpecifierRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new StorageClassSpecifier(std::u32string(matchBegin, matchEnd));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::cppcode::StorageClassSpecifier* value;
    };
};

class Declaration::TypeSpecifierRule : public soulng::parsing::Rule
{
public:
    TypeSpecifierRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::TypeSpecifier*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::TypeSpecifier*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TypeSpecifierRule>(this, &TypeSpecifierRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TypeSpecifierRule>(this, &TypeSpecifierRule::A1Action));
        soulng::parsing::NonterminalParser* simpleTypeSpecifierNonterminalParser = GetNonterminal(ToUtf32("SimpleTypeSpecifier"));
        simpleTypeSpecifierNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<TypeSpecifierRule>(this, &TypeSpecifierRule::PostSimpleTypeSpecifier));
        soulng::parsing::NonterminalParser* cVQualifierNonterminalParser = GetNonterminal(ToUtf32("CVQualifier"));
        cVQualifierNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<TypeSpecifierRule>(this, &TypeSpecifierRule::PostCVQualifier));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromSimpleTypeSpecifier;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromCVQualifier;
    }
    void PostSimpleTypeSpecifier(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromSimpleTypeSpecifier_value = std::move(stack.top());
            context->fromSimpleTypeSpecifier = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::TypeSpecifier*>*>(fromSimpleTypeSpecifier_value.get());
            stack.pop();
        }
    }
    void PostCVQualifier(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromCVQualifier_value = std::move(stack.top());
            context->fromCVQualifier = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::TypeSpecifier*>*>(fromCVQualifier_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromSimpleTypeSpecifier(), fromCVQualifier() {}
        soulng::cppcode::TypeSpecifier* value;
        soulng::cppcode::TypeSpecifier* fromSimpleTypeSpecifier;
        soulng::cppcode::TypeSpecifier* fromCVQualifier;
    };
};

class Declaration::SimpleTypeSpecifierRule : public soulng::parsing::Rule
{
public:
    SimpleTypeSpecifierRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::TypeSpecifier*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::TypeSpecifier*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<SimpleTypeSpecifierRule>(this, &SimpleTypeSpecifierRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new TypeSpecifier(std::u32string(matchBegin, matchEnd));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::cppcode::TypeSpecifier* value;
    };
};

class Declaration::TypeNameRule : public soulng::parsing::Rule
{
public:
    TypeNameRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::TypeName*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::TypeName*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TypeNameRule>(this, &TypeNameRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TypeNameRule>(this, &TypeNameRule::A1Action));
        soulng::parsing::NonterminalParser* qualifiedIdNonterminalParser = GetNonterminal(ToUtf32("QualifiedId"));
        qualifiedIdNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<TypeNameRule>(this, &TypeNameRule::PostQualifiedId));
        soulng::parsing::NonterminalParser* templateArgumentListNonterminalParser = GetNonterminal(ToUtf32("TemplateArgumentList"));
        templateArgumentListNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<TypeNameRule>(this, &TypeNameRule::PreTemplateArgumentList));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new soulng::cppcode::TypeName(std::u32string(matchBegin, matchEnd));
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value->IsTemplate() = true;
    }
    void PostQualifiedId(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromQualifiedId_value = std::move(stack.top());
            context->fromQualifiedId = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromQualifiedId_value.get());
            stack.pop();
        }
    }
    void PreTemplateArgumentList(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::TypeName*>(context->value)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromQualifiedId() {}
        soulng::cppcode::TypeName* value;
        std::u32string fromQualifiedId;
    };
};

class Declaration::TemplateArgumentListRule : public soulng::parsing::Rule
{
public:
    TemplateArgumentListRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::cppcode::TypeName*"), ToUtf32("typeName")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> typeName_value = std::move(stack.top());
        context->typeName = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::TypeName*>*>(typeName_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TemplateArgumentListRule>(this, &TemplateArgumentListRule::A0Action));
        soulng::parsing::NonterminalParser* templateArgumentNonterminalParser = GetNonterminal(ToUtf32("TemplateArgument"));
        templateArgumentNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<TemplateArgumentListRule>(this, &TemplateArgumentListRule::PostTemplateArgument));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->typeName->AddTemplateArgument(context->fromTemplateArgument);
    }
    void PostTemplateArgument(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromTemplateArgument_value = std::move(stack.top());
            context->fromTemplateArgument = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::CppObject*>*>(fromTemplateArgument_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): typeName(), fromTemplateArgument() {}
        soulng::cppcode::TypeName* typeName;
        soulng::cppcode::CppObject* fromTemplateArgument;
    };
};

class Declaration::TemplateArgumentRule : public soulng::parsing::Rule
{
public:
    TemplateArgumentRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::CppObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TemplateArgumentRule>(this, &TemplateArgumentRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TemplateArgumentRule>(this, &TemplateArgumentRule::A1Action));
        soulng::parsing::NonterminalParser* typeIdNonterminalParser = GetNonterminal(ToUtf32("TypeId"));
        typeIdNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<TemplateArgumentRule>(this, &TemplateArgumentRule::PostTypeId));
        soulng::parsing::NonterminalParser* assignmentExpressionNonterminalParser = GetNonterminal(ToUtf32("AssignmentExpression"));
        assignmentExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<TemplateArgumentRule>(this, &TemplateArgumentRule::PostAssignmentExpression));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromTypeId;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromAssignmentExpression;
    }
    void PostTypeId(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromTypeId_value = std::move(stack.top());
            context->fromTypeId = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::TypeId*>*>(fromTypeId_value.get());
            stack.pop();
        }
    }
    void PostAssignmentExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromAssignmentExpression_value = std::move(stack.top());
            context->fromAssignmentExpression = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::CppObject*>*>(fromAssignmentExpression_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromTypeId(), fromAssignmentExpression() {}
        soulng::cppcode::CppObject* value;
        soulng::cppcode::TypeId* fromTypeId;
        soulng::cppcode::CppObject* fromAssignmentExpression;
    };
};

class Declaration::TypedefRule : public soulng::parsing::Rule
{
public:
    TypedefRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::DeclSpecifier*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::DeclSpecifier*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TypedefRule>(this, &TypedefRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new Typedef;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::cppcode::DeclSpecifier* value;
    };
};

class Declaration::CVQualifierRule : public soulng::parsing::Rule
{
public:
    CVQualifierRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::TypeSpecifier*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::TypeSpecifier*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CVQualifierRule>(this, &CVQualifierRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CVQualifierRule>(this, &CVQualifierRule::A1Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new Const;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new Volatile;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::cppcode::TypeSpecifier* value;
    };
};

class Declaration::NamespaceAliasDefinitionRule : public soulng::parsing::Rule
{
public:
    NamespaceAliasDefinitionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::UsingObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::UsingObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NamespaceAliasDefinitionRule>(this, &NamespaceAliasDefinitionRule::A0Action));
        soulng::parsing::NonterminalParser* identifierNonterminalParser = GetNonterminal(ToUtf32("Identifier"));
        identifierNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<NamespaceAliasDefinitionRule>(this, &NamespaceAliasDefinitionRule::PostIdentifier));
        soulng::parsing::NonterminalParser* qualifiedIdNonterminalParser = GetNonterminal(ToUtf32("QualifiedId"));
        qualifiedIdNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<NamespaceAliasDefinitionRule>(this, &NamespaceAliasDefinitionRule::PostQualifiedId));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new NamespaceAlias(context->fromIdentifier, context->fromQualifiedId);
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
    void PostQualifiedId(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromQualifiedId_value = std::move(stack.top());
            context->fromQualifiedId = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromQualifiedId_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromIdentifier(), fromQualifiedId() {}
        soulng::cppcode::UsingObject* value;
        std::u32string fromIdentifier;
        std::u32string fromQualifiedId;
    };
};

class Declaration::UsingDeclarationRule : public soulng::parsing::Rule
{
public:
    UsingDeclarationRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::UsingObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::UsingObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UsingDeclarationRule>(this, &UsingDeclarationRule::A0Action));
        soulng::parsing::NonterminalParser* qualifiedIdNonterminalParser = GetNonterminal(ToUtf32("QualifiedId"));
        qualifiedIdNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<UsingDeclarationRule>(this, &UsingDeclarationRule::PostQualifiedId));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new UsingDeclaration(context->fromQualifiedId);
    }
    void PostQualifiedId(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromQualifiedId_value = std::move(stack.top());
            context->fromQualifiedId = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromQualifiedId_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromQualifiedId() {}
        soulng::cppcode::UsingObject* value;
        std::u32string fromQualifiedId;
    };
};

class Declaration::UsingDirectiveRule : public soulng::parsing::Rule
{
public:
    UsingDirectiveRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::UsingObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::UsingObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UsingDirectiveRule>(this, &UsingDirectiveRule::A0Action));
        soulng::parsing::NonterminalParser* qualifiedIdNonterminalParser = GetNonterminal(ToUtf32("QualifiedId"));
        qualifiedIdNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<UsingDirectiveRule>(this, &UsingDirectiveRule::PostQualifiedId));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new UsingDirective(context->fromQualifiedId);
    }
    void PostQualifiedId(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromQualifiedId_value = std::move(stack.top());
            context->fromQualifiedId = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromQualifiedId_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromQualifiedId() {}
        soulng::cppcode::UsingObject* value;
        std::u32string fromQualifiedId;
    };
};

void Declaration::GetReferencedGrammars()
{
    soulng::parsing::ParsingDomain* pd = GetParsingDomain();
    soulng::parsing::Grammar* grammar0 = pd->GetGrammar(ToUtf32("soulng.code.Identifier"));
    if (!grammar0)
    {
        grammar0 = soulng::code::Identifier::Create(pd);
    }
    AddGrammarReference(grammar0);
    soulng::parsing::Grammar* grammar1 = pd->GetGrammar(ToUtf32("soulng.parsing.stdlib"));
    if (!grammar1)
    {
        grammar1 = soulng::parsing::stdlib::Create(pd);
    }
    AddGrammarReference(grammar1);
    soulng::parsing::Grammar* grammar2 = pd->GetGrammar(ToUtf32("soulng.code.Declarator"));
    if (!grammar2)
    {
        grammar2 = soulng::code::Declarator::Create(pd);
    }
    AddGrammarReference(grammar2);
    soulng::parsing::Grammar* grammar3 = pd->GetGrammar(ToUtf32("soulng.code.Expression"));
    if (!grammar3)
    {
        grammar3 = soulng::code::Expression::Create(pd);
    }
    AddGrammarReference(grammar3);
}

void Declaration::CreateRules()
{
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("QualifiedId"), this, ToUtf32("Identifier.QualifiedId")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("identifier"), this, ToUtf32("soulng.parsing.stdlib.identifier")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("InitDeclaratorList"), this, ToUtf32("Declarator.InitDeclaratorList")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("Identifier"), this, ToUtf32("Identifier.Identifier")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("TypeId"), this, ToUtf32("Declarator.TypeId")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("AssignmentExpression"), this, ToUtf32("Expression.AssignmentExpression")));
    AddRule(new BlockDeclarationRule(ToUtf32("BlockDeclaration"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::ActionParser(ToUtf32("A0"),
                        new soulng::parsing::NonterminalParser(ToUtf32("NamespaceAliasDefinition"), ToUtf32("NamespaceAliasDefinition"), 0)),
                    new soulng::parsing::ActionParser(ToUtf32("A1"),
                        new soulng::parsing::NonterminalParser(ToUtf32("UsingDirective"), ToUtf32("UsingDirective"), 0))),
                new soulng::parsing::ActionParser(ToUtf32("A2"),
                    new soulng::parsing::NonterminalParser(ToUtf32("UsingDeclaration"), ToUtf32("UsingDeclaration"), 0))),
            new soulng::parsing::ActionParser(ToUtf32("A3"),
                new soulng::parsing::NonterminalParser(ToUtf32("SimpleDeclaration"), ToUtf32("SimpleDeclaration"), 0)))));
    AddRule(new SimpleDeclarationRule(ToUtf32("SimpleDeclaration"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::EmptyParser()),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::OptionalParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("DeclSpecifierSeq"), ToUtf32("DeclSpecifierSeq"), 1)),
                            new soulng::parsing::OptionalParser(
                                new soulng::parsing::GroupingParser(
                                    new soulng::parsing::ActionParser(ToUtf32("A2"),
                                        new soulng::parsing::NonterminalParser(ToUtf32("InitDeclaratorList"), ToUtf32("InitDeclaratorList"), 0))))),
                        new soulng::parsing::CharParser(';')))))));
    AddRule(new DeclSpecifierSeqRule(ToUtf32("DeclSpecifierSeq"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::PositiveParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::ActionParser(ToUtf32("A0"),
                        new soulng::parsing::NonterminalParser(ToUtf32("DeclSpecifier"), ToUtf32("DeclSpecifier"), 0)))),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::NonterminalParser(ToUtf32("TypeName"), ToUtf32("TypeName"), 0)))));
    AddRule(new DeclSpecifierRule(ToUtf32("DeclSpecifier"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::ActionParser(ToUtf32("A0"),
                    new soulng::parsing::NonterminalParser(ToUtf32("StorageClassSpecifier"), ToUtf32("StorageClassSpecifier"), 0)),
                new soulng::parsing::ActionParser(ToUtf32("A1"),
                    new soulng::parsing::NonterminalParser(ToUtf32("TypeSpecifier"), ToUtf32("TypeSpecifier"), 0))),
            new soulng::parsing::ActionParser(ToUtf32("A2"),
                new soulng::parsing::NonterminalParser(ToUtf32("Typedef"), ToUtf32("Typedef"), 0)))));
    AddRule(new StorageClassSpecifierRule(ToUtf32("StorageClassSpecifier"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordListParser(ToUtf32("identifier"), keywords0))));
    AddRule(new TypeSpecifierRule(ToUtf32("TypeSpecifier"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("SimpleTypeSpecifier"), ToUtf32("SimpleTypeSpecifier"), 0)),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::NonterminalParser(ToUtf32("CVQualifier"), ToUtf32("CVQualifier"), 0)))));
    AddRule(new SimpleTypeSpecifierRule(ToUtf32("SimpleTypeSpecifier"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordListParser(ToUtf32("identifier"), keywords1))));
    AddRule(new TypeNameRule(ToUtf32("TypeName"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("QualifiedId"), ToUtf32("QualifiedId"), 0)),
            new soulng::parsing::OptionalParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::ActionParser(ToUtf32("A1"),
                                new soulng::parsing::CharParser('<')),
                            new soulng::parsing::NonterminalParser(ToUtf32("TemplateArgumentList"), ToUtf32("TemplateArgumentList"), 1)),
                        new soulng::parsing::CharParser('>')))))));
    AddRule(new TemplateArgumentListRule(ToUtf32("TemplateArgumentList"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ListParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("TemplateArgument"), ToUtf32("TemplateArgument"), 0)),
            new soulng::parsing::CharParser(','))));
    AddRule(new TemplateArgumentRule(ToUtf32("TemplateArgument"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("TypeId"), ToUtf32("TypeId"), 0)),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::NonterminalParser(ToUtf32("AssignmentExpression"), ToUtf32("AssignmentExpression"), 0)))));
    AddRule(new TypedefRule(ToUtf32("Typedef"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("typedef")))));
    AddRule(new CVQualifierRule(ToUtf32("CVQualifier"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::KeywordParser(ToUtf32("const"))),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::KeywordParser(ToUtf32("volatile"))))));
    AddRule(new NamespaceAliasDefinitionRule(ToUtf32("NamespaceAliasDefinition"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::KeywordParser(ToUtf32("namespace")),
                        new soulng::parsing::NonterminalParser(ToUtf32("Identifier"), ToUtf32("Identifier"), 0)),
                    new soulng::parsing::CharParser('=')),
                new soulng::parsing::NonterminalParser(ToUtf32("QualifiedId"), ToUtf32("QualifiedId"), 0)),
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::CharParser(';')))));
    AddRule(new UsingDeclarationRule(ToUtf32("UsingDeclaration"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::KeywordParser(ToUtf32("using")),
                new soulng::parsing::NonterminalParser(ToUtf32("QualifiedId"), ToUtf32("QualifiedId"), 0)),
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::CharParser(';')))));
    AddRule(new UsingDirectiveRule(ToUtf32("UsingDirective"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::KeywordParser(ToUtf32("using")),
                    new soulng::parsing::KeywordParser(ToUtf32("namespace"))),
                new soulng::parsing::NonterminalParser(ToUtf32("QualifiedId"), ToUtf32("QualifiedId"), 0)),
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::CharParser(';')))));
}

} } // namespace soulng.code
