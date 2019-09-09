#include "Declarator.hpp"
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
#include <soulng/code/Declaration.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/cppcode/Type.hpp>

namespace soulng { namespace code {

using soulng::util::Trim;
using namespace soulng::cppcode;
using namespace soulng::parsing;
using namespace soulng::util;
using namespace soulng::unicode;

Declarator* Declarator::Create()
{
    return Create(new soulng::parsing::ParsingDomain());
}

Declarator* Declarator::Create(soulng::parsing::ParsingDomain* parsingDomain)
{
    RegisterParsingDomain(parsingDomain);
    Declarator* grammar(new Declarator(parsingDomain));
    parsingDomain->AddGrammar(grammar);
    grammar->CreateRules();
    grammar->Link();
    return grammar;
}

Declarator::Declarator(soulng::parsing::ParsingDomain* parsingDomain_): soulng::parsing::Grammar(ToUtf32("Declarator"), parsingDomain_->GetNamespaceScope(ToUtf32("soulng.code")), parsingDomain_)
{
    SetOwner(0);
}

soulng::cppcode::InitDeclaratorList* Declarator::Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName)
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
    soulng::cppcode::InitDeclaratorList* result = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::InitDeclaratorList*>*>(value.get());
    stack.pop();
    return result;
}

class Declarator::InitDeclaratorListRule : public soulng::parsing::Rule
{
public:
    InitDeclaratorListRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::InitDeclaratorList*"));
        AddLocalVariable(AttrOrVariable(ToUtf32("std::unique_ptr<InitDeclaratorList>"), ToUtf32("idl")));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::InitDeclaratorList*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<InitDeclaratorListRule>(this, &InitDeclaratorListRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<InitDeclaratorListRule>(this, &InitDeclaratorListRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<InitDeclaratorListRule>(this, &InitDeclaratorListRule::A2Action));
        soulng::parsing::NonterminalParser* initDeclaratorNonterminalParser = GetNonterminal(ToUtf32("InitDeclarator"));
        initDeclaratorNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<InitDeclaratorListRule>(this, &InitDeclaratorListRule::PostInitDeclarator));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->idl.reset(new InitDeclaratorList);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->idl.release();
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->idl->Add(context->fromInitDeclarator);
    }
    void PostInitDeclarator(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromInitDeclarator_value = std::move(stack.top());
            context->fromInitDeclarator = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::InitDeclarator*>*>(fromInitDeclarator_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), idl(), fromInitDeclarator() {}
        soulng::cppcode::InitDeclaratorList* value;
        std::unique_ptr<InitDeclaratorList> idl;
        soulng::cppcode::InitDeclarator* fromInitDeclarator;
    };
};

class Declarator::InitDeclaratorRule : public soulng::parsing::Rule
{
public:
    InitDeclaratorRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::InitDeclarator*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::InitDeclarator*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<InitDeclaratorRule>(this, &InitDeclaratorRule::A0Action));
        soulng::parsing::NonterminalParser* declaratorNonterminalParser = GetNonterminal(ToUtf32("Declarator"));
        declaratorNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<InitDeclaratorRule>(this, &InitDeclaratorRule::PostDeclarator));
        soulng::parsing::NonterminalParser* initializerNonterminalParser = GetNonterminal(ToUtf32("Initializer"));
        initializerNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<InitDeclaratorRule>(this, &InitDeclaratorRule::PostInitializer));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new InitDeclarator(context->fromDeclarator, context->fromInitializer);
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
    void PostInitializer(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromInitializer_value = std::move(stack.top());
            context->fromInitializer = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::Initializer*>*>(fromInitializer_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromDeclarator(), fromInitializer() {}
        soulng::cppcode::InitDeclarator* value;
        std::u32string fromDeclarator;
        soulng::cppcode::Initializer* fromInitializer;
    };
};

class Declarator::DeclaratorRule : public soulng::parsing::Rule
{
public:
    DeclaratorRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
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
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeclaratorRule>(this, &DeclaratorRule::A0Action));
        soulng::parsing::NonterminalParser* directDeclaratorNonterminalParser = GetNonterminal(ToUtf32("DirectDeclarator"));
        soulng::parsing::NonterminalParser* declaratorNonterminalParser = GetNonterminal(ToUtf32("Declarator"));
        declaratorNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DeclaratorRule>(this, &DeclaratorRule::PostDeclarator));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Trim(std::u32string(matchBegin, matchEnd));
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
        Context(): value(), fromDeclarator() {}
        std::u32string value;
        std::u32string fromDeclarator;
    };
};

class Declarator::DirectDeclaratorRule : public soulng::parsing::Rule
{
public:
    DirectDeclaratorRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddLocalVariable(AttrOrVariable(ToUtf32("std::unique_ptr<CppObject>"), ToUtf32("o")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DirectDeclaratorRule>(this, &DirectDeclaratorRule::A0Action));
        soulng::parsing::NonterminalParser* declaratorIdNonterminalParser = GetNonterminal(ToUtf32("DeclaratorId"));
        soulng::parsing::NonterminalParser* constantExpressionNonterminalParser = GetNonterminal(ToUtf32("ConstantExpression"));
        constantExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DirectDeclaratorRule>(this, &DirectDeclaratorRule::PostConstantExpression));
        soulng::parsing::NonterminalParser* declaratorNonterminalParser = GetNonterminal(ToUtf32("Declarator"));
        declaratorNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DirectDeclaratorRule>(this, &DirectDeclaratorRule::PostDeclarator));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->o.reset(context->fromConstantExpression);
    }
    void PostConstantExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromConstantExpression_value = std::move(stack.top());
            context->fromConstantExpression = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::CppObject*>*>(fromConstantExpression_value.get());
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
        Context(): o(), fromConstantExpression(), fromDeclarator() {}
        std::unique_ptr<CppObject> o;
        soulng::cppcode::CppObject* fromConstantExpression;
        std::u32string fromDeclarator;
    };
};

class Declarator::DeclaratorIdRule : public soulng::parsing::Rule
{
public:
    DeclaratorIdRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddLocalVariable(AttrOrVariable(ToUtf32("std::unique_ptr<CppObject>"), ToUtf32("o")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeclaratorIdRule>(this, &DeclaratorIdRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeclaratorIdRule>(this, &DeclaratorIdRule::A1Action));
        soulng::parsing::NonterminalParser* idExpressionNonterminalParser = GetNonterminal(ToUtf32("IdExpression"));
        idExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DeclaratorIdRule>(this, &DeclaratorIdRule::PostIdExpression));
        soulng::parsing::NonterminalParser* typeNameNonterminalParser = GetNonterminal(ToUtf32("TypeName"));
        typeNameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DeclaratorIdRule>(this, &DeclaratorIdRule::PostTypeName));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->o.reset(context->fromIdExpression);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->o.reset(context->fromTypeName);
    }
    void PostIdExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromIdExpression_value = std::move(stack.top());
            context->fromIdExpression = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::IdExpr*>*>(fromIdExpression_value.get());
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
        Context(): o(), fromIdExpression(), fromTypeName() {}
        std::unique_ptr<CppObject> o;
        soulng::cppcode::IdExpr* fromIdExpression;
        soulng::cppcode::TypeName* fromTypeName;
    };
};

class Declarator::TypeIdRule : public soulng::parsing::Rule
{
public:
    TypeIdRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::TypeId*"));
        AddLocalVariable(AttrOrVariable(ToUtf32("std::unique_ptr<TypeId>"), ToUtf32("ti")));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::TypeId*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TypeIdRule>(this, &TypeIdRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TypeIdRule>(this, &TypeIdRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TypeIdRule>(this, &TypeIdRule::A2Action));
        soulng::parsing::ActionParser* a3ActionParser = GetAction(ToUtf32("A3"));
        a3ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TypeIdRule>(this, &TypeIdRule::A3Action));
        soulng::parsing::NonterminalParser* typeSpecifierSeqNonterminalParser = GetNonterminal(ToUtf32("TypeSpecifierSeq"));
        typeSpecifierSeqNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<TypeIdRule>(this, &TypeIdRule::PreTypeSpecifierSeq));
        soulng::parsing::NonterminalParser* typeNameNonterminalParser = GetNonterminal(ToUtf32("TypeName"));
        typeNameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<TypeIdRule>(this, &TypeIdRule::PostTypeName));
        soulng::parsing::NonterminalParser* abstractDeclaratorNonterminalParser = GetNonterminal(ToUtf32("AbstractDeclarator"));
        abstractDeclaratorNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<TypeIdRule>(this, &TypeIdRule::PostAbstractDeclarator));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->ti.reset(new TypeId);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->ti.release();
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->ti->Add(context->fromTypeName);
    }
    void A3Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->ti->Declarator() = context->fromAbstractDeclarator;
    }
    void PreTypeSpecifierSeq(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::TypeId*>(context->ti.get())));
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
    void PostAbstractDeclarator(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromAbstractDeclarator_value = std::move(stack.top());
            context->fromAbstractDeclarator = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromAbstractDeclarator_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), ti(), fromTypeName(), fromAbstractDeclarator() {}
        soulng::cppcode::TypeId* value;
        std::unique_ptr<TypeId> ti;
        soulng::cppcode::TypeName* fromTypeName;
        std::u32string fromAbstractDeclarator;
    };
};

class Declarator::TypeRule : public soulng::parsing::Rule
{
public:
    TypeRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::Type*"));
        AddLocalVariable(AttrOrVariable(ToUtf32("std::unique_ptr<Type>"), ToUtf32("t")));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::Type*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TypeRule>(this, &TypeRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TypeRule>(this, &TypeRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TypeRule>(this, &TypeRule::A2Action));
        soulng::parsing::ActionParser* a3ActionParser = GetAction(ToUtf32("A3"));
        a3ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TypeRule>(this, &TypeRule::A3Action));
        soulng::parsing::NonterminalParser* typeSpecifierNonterminalParser = GetNonterminal(ToUtf32("TypeSpecifier"));
        typeSpecifierNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<TypeRule>(this, &TypeRule::PostTypeSpecifier));
        soulng::parsing::NonterminalParser* typeNameNonterminalParser = GetNonterminal(ToUtf32("TypeName"));
        typeNameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<TypeRule>(this, &TypeRule::PostTypeName));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->t.reset(new Type);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->t.release();
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->t->Add(context->fromTypeSpecifier);
    }
    void A3Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->t->Add(context->fromTypeName);
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
        Context(): value(), t(), fromTypeSpecifier(), fromTypeName() {}
        soulng::cppcode::Type* value;
        std::unique_ptr<Type> t;
        soulng::cppcode::TypeSpecifier* fromTypeSpecifier;
        soulng::cppcode::TypeName* fromTypeName;
    };
};

class Declarator::TypeSpecifierSeqRule : public soulng::parsing::Rule
{
public:
    TypeSpecifierSeqRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::cppcode::TypeId*"), ToUtf32("typeId")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> typeId_value = std::move(stack.top());
        context->typeId = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::TypeId*>*>(typeId_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TypeSpecifierSeqRule>(this, &TypeSpecifierSeqRule::A0Action));
        soulng::parsing::NonterminalParser* typeSpecifierNonterminalParser = GetNonterminal(ToUtf32("TypeSpecifier"));
        typeSpecifierNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<TypeSpecifierSeqRule>(this, &TypeSpecifierSeqRule::PostTypeSpecifier));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->typeId->Add(context->fromTypeSpecifier);
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
private:
    struct Context : soulng::parsing::Context
    {
        Context(): typeId(), fromTypeSpecifier() {}
        soulng::cppcode::TypeId* typeId;
        soulng::cppcode::TypeSpecifier* fromTypeSpecifier;
    };
};

class Declarator::AbstractDeclaratorRule : public soulng::parsing::Rule
{
public:
    AbstractDeclaratorRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
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
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<AbstractDeclaratorRule>(this, &AbstractDeclaratorRule::A0Action));
        soulng::parsing::NonterminalParser* abstractDeclaratorNonterminalParser = GetNonterminal(ToUtf32("AbstractDeclarator"));
        abstractDeclaratorNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<AbstractDeclaratorRule>(this, &AbstractDeclaratorRule::PostAbstractDeclarator));
        soulng::parsing::NonterminalParser* directAbstractDeclaratorNonterminalParser = GetNonterminal(ToUtf32("DirectAbstractDeclarator"));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Trim(std::u32string(matchBegin, matchEnd));
    }
    void PostAbstractDeclarator(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromAbstractDeclarator_value = std::move(stack.top());
            context->fromAbstractDeclarator = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromAbstractDeclarator_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromAbstractDeclarator() {}
        std::u32string value;
        std::u32string fromAbstractDeclarator;
    };
};

class Declarator::DirectAbstractDeclaratorRule : public soulng::parsing::Rule
{
public:
    DirectAbstractDeclaratorRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddLocalVariable(AttrOrVariable(ToUtf32("std::unique_ptr<CppObject>"), ToUtf32("o")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DirectAbstractDeclaratorRule>(this, &DirectAbstractDeclaratorRule::A0Action));
        soulng::parsing::NonterminalParser* constantExpressionNonterminalParser = GetNonterminal(ToUtf32("ConstantExpression"));
        constantExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DirectAbstractDeclaratorRule>(this, &DirectAbstractDeclaratorRule::PostConstantExpression));
        soulng::parsing::NonterminalParser* abstractDeclaratorNonterminalParser = GetNonterminal(ToUtf32("AbstractDeclarator"));
        abstractDeclaratorNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DirectAbstractDeclaratorRule>(this, &DirectAbstractDeclaratorRule::PostAbstractDeclarator));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->o.reset(context->fromConstantExpression);
    }
    void PostConstantExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromConstantExpression_value = std::move(stack.top());
            context->fromConstantExpression = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::CppObject*>*>(fromConstantExpression_value.get());
            stack.pop();
        }
    }
    void PostAbstractDeclarator(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromAbstractDeclarator_value = std::move(stack.top());
            context->fromAbstractDeclarator = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromAbstractDeclarator_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): o(), fromConstantExpression(), fromAbstractDeclarator() {}
        std::unique_ptr<CppObject> o;
        soulng::cppcode::CppObject* fromConstantExpression;
        std::u32string fromAbstractDeclarator;
    };
};

class Declarator::CVQualifierSeqRule : public soulng::parsing::Rule
{
public:
    CVQualifierSeqRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddLocalVariable(AttrOrVariable(ToUtf32("std::unique_ptr<CppObject>"), ToUtf32("o")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CVQualifierSeqRule>(this, &CVQualifierSeqRule::A0Action));
        soulng::parsing::NonterminalParser* cVQualifierNonterminalParser = GetNonterminal(ToUtf32("CVQualifier"));
        cVQualifierNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<CVQualifierSeqRule>(this, &CVQualifierSeqRule::PostCVQualifier));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->o.reset(context->fromCVQualifier);
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
        Context(): o(), fromCVQualifier() {}
        std::unique_ptr<CppObject> o;
        soulng::cppcode::TypeSpecifier* fromCVQualifier;
    };
};

class Declarator::InitializerRule : public soulng::parsing::Rule
{
public:
    InitializerRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::Initializer*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::Initializer*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<InitializerRule>(this, &InitializerRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<InitializerRule>(this, &InitializerRule::A1Action));
        soulng::parsing::NonterminalParser* initializerClauseNonterminalParser = GetNonterminal(ToUtf32("InitializerClause"));
        initializerClauseNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<InitializerRule>(this, &InitializerRule::PostInitializerClause));
        soulng::parsing::NonterminalParser* expressionListNonterminalParser = GetNonterminal(ToUtf32("ExpressionList"));
        expressionListNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<InitializerRule>(this, &InitializerRule::PreExpressionList));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new Initializer(context->fromInitializerClause);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new Initializer(nullptr);
    }
    void PostInitializerClause(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromInitializerClause_value = std::move(stack.top());
            context->fromInitializerClause = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::AssignInit*>*>(fromInitializerClause_value.get());
            stack.pop();
        }
    }
    void PreExpressionList(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::CppObject*>(context->value)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromInitializerClause() {}
        soulng::cppcode::Initializer* value;
        soulng::cppcode::AssignInit* fromInitializerClause;
    };
};

class Declarator::InitializerClauseRule : public soulng::parsing::Rule
{
public:
    InitializerClauseRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::cppcode::AssignInit*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::AssignInit*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<InitializerClauseRule>(this, &InitializerClauseRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<InitializerClauseRule>(this, &InitializerClauseRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<InitializerClauseRule>(this, &InitializerClauseRule::A2Action));
        soulng::parsing::NonterminalParser* assignmentExpressionNonterminalParser = GetNonterminal(ToUtf32("AssignmentExpression"));
        assignmentExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<InitializerClauseRule>(this, &InitializerClauseRule::PostAssignmentExpression));
        soulng::parsing::NonterminalParser* initializerListNonterminalParser = GetNonterminal(ToUtf32("InitializerList"));
        initializerListNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<InitializerClauseRule>(this, &InitializerClauseRule::PreInitializerList));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new AssignInit(context->fromAssignmentExpression);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new AssignInit(nullptr);
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new AssignInit(nullptr);
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
    void PreInitializerList(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::cppcode::AssignInit*>(context->value)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromAssignmentExpression() {}
        soulng::cppcode::AssignInit* value;
        soulng::cppcode::CppObject* fromAssignmentExpression;
    };
};

class Declarator::InitializerListRule : public soulng::parsing::Rule
{
public:
    InitializerListRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("soulng::cppcode::AssignInit*"), ToUtf32("init")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> init_value = std::move(stack.top());
        context->init = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::AssignInit*>*>(init_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<InitializerListRule>(this, &InitializerListRule::A0Action));
        soulng::parsing::NonterminalParser* initializerClauseNonterminalParser = GetNonterminal(ToUtf32("InitializerClause"));
        initializerClauseNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<InitializerListRule>(this, &InitializerListRule::PostInitializerClause));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->init->Add(context->fromInitializerClause);
    }
    void PostInitializerClause(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromInitializerClause_value = std::move(stack.top());
            context->fromInitializerClause = *static_cast<soulng::parsing::ValueObject<soulng::cppcode::AssignInit*>*>(fromInitializerClause_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): init(), fromInitializerClause() {}
        soulng::cppcode::AssignInit* init;
        soulng::cppcode::AssignInit* fromInitializerClause;
    };
};

void Declarator::GetReferencedGrammars()
{
    soulng::parsing::ParsingDomain* pd = GetParsingDomain();
    soulng::parsing::Grammar* grammar0 = pd->GetGrammar(ToUtf32("soulng.code.Expression"));
    if (!grammar0)
    {
        grammar0 = soulng::code::Expression::Create(pd);
    }
    AddGrammarReference(grammar0);
    soulng::parsing::Grammar* grammar1 = pd->GetGrammar(ToUtf32("soulng.code.Declaration"));
    if (!grammar1)
    {
        grammar1 = soulng::code::Declaration::Create(pd);
    }
    AddGrammarReference(grammar1);
}

void Declarator::CreateRules()
{
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("ConstantExpression"), this, ToUtf32("Expression.ConstantExpression")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("CVQualifier"), this, ToUtf32("Declaration.CVQualifier")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("IdExpression"), this, ToUtf32("Expression.IdExpression")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("ExpressionList"), this, ToUtf32("Expression.ExpressionList")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("AssignmentExpression"), this, ToUtf32("Expression.AssignmentExpression")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("TypeSpecifier"), this, ToUtf32("Declaration.TypeSpecifier")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("TypeName"), this, ToUtf32("Declaration.TypeName")));
    AddRule(new InitDeclaratorListRule(ToUtf32("InitDeclaratorList"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::EmptyParser()),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::ListParser(
                        new soulng::parsing::ActionParser(ToUtf32("A2"),
                            new soulng::parsing::NonterminalParser(ToUtf32("InitDeclarator"), ToUtf32("InitDeclarator"), 0)),
                        new soulng::parsing::CharParser(',')))))));
    AddRule(new InitDeclaratorRule(ToUtf32("InitDeclarator"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("Declarator"), ToUtf32("Declarator"), 0),
                    new soulng::parsing::OptionalParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("Initializer"), ToUtf32("Initializer"), 0)))))));
    AddRule(new DeclaratorRule(ToUtf32("Declarator"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("DirectDeclarator"), ToUtf32("DirectDeclarator"), 0),
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("PtrOperator"), ToUtf32("PtrOperator"), 0),
                        new soulng::parsing::NonterminalParser(ToUtf32("Declarator"), ToUtf32("Declarator"), 0)))))));
    AddRule(new DirectDeclaratorRule(ToUtf32("DirectDeclarator"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::NonterminalParser(ToUtf32("DeclaratorId"), ToUtf32("DeclaratorId"), 0),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::SequenceParser(
                                    new soulng::parsing::SequenceParser(
                                        new soulng::parsing::CharParser('['),
                                        new soulng::parsing::OptionalParser(
                                            new soulng::parsing::GroupingParser(
                                                new soulng::parsing::ActionParser(ToUtf32("A0"),
                                                    new soulng::parsing::NonterminalParser(ToUtf32("ConstantExpression"), ToUtf32("ConstantExpression"), 0))))),
                                    new soulng::parsing::CharParser(']')),
                                new soulng::parsing::CharParser('(')),
                            new soulng::parsing::NonterminalParser(ToUtf32("Declarator"), ToUtf32("Declarator"), 0)),
                        new soulng::parsing::CharParser(')')))))));
    AddRule(new DeclaratorIdRule(ToUtf32("DeclaratorId"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("IdExpression"), ToUtf32("IdExpression"), 0)),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::NonterminalParser(ToUtf32("TypeName"), ToUtf32("TypeName"), 0)))));
    AddRule(new TypeIdRule(ToUtf32("TypeId"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::EmptyParser()),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::GroupingParser(
                            new soulng::parsing::AlternativeParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("TypeSpecifierSeq"), ToUtf32("TypeSpecifierSeq"), 1),
                                new soulng::parsing::ActionParser(ToUtf32("A2"),
                                    new soulng::parsing::NonterminalParser(ToUtf32("TypeName"), ToUtf32("TypeName"), 0)))),
                        new soulng::parsing::OptionalParser(
                            new soulng::parsing::GroupingParser(
                                new soulng::parsing::ActionParser(ToUtf32("A3"),
                                    new soulng::parsing::NonterminalParser(ToUtf32("AbstractDeclarator"), ToUtf32("AbstractDeclarator"), 0))))))))));
    AddRule(new TypeRule(ToUtf32("Type"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::EmptyParser()),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::AlternativeParser(
                        new soulng::parsing::PositiveParser(
                            new soulng::parsing::GroupingParser(
                                new soulng::parsing::ActionParser(ToUtf32("A2"),
                                    new soulng::parsing::NonterminalParser(ToUtf32("TypeSpecifier"), ToUtf32("TypeSpecifier"), 0)))),
                        new soulng::parsing::ActionParser(ToUtf32("A3"),
                            new soulng::parsing::NonterminalParser(ToUtf32("TypeName"), ToUtf32("TypeName"), 0))))))));
    AddRule(new TypeSpecifierSeqRule(ToUtf32("TypeSpecifierSeq"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::PositiveParser(
            new soulng::parsing::GroupingParser(
                new soulng::parsing::ActionParser(ToUtf32("A0"),
                    new soulng::parsing::NonterminalParser(ToUtf32("TypeSpecifier"), ToUtf32("TypeSpecifier"), 0))))));
    AddRule(new AbstractDeclaratorRule(ToUtf32("AbstractDeclarator"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("PtrOperator"), ToUtf32("PtrOperator"), 0),
                        new soulng::parsing::OptionalParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("AbstractDeclarator"), ToUtf32("AbstractDeclarator"), 0))),
                    new soulng::parsing::NonterminalParser(ToUtf32("DirectAbstractDeclarator"), ToUtf32("DirectAbstractDeclarator"), 0))))));
    AddRule(new DirectAbstractDeclaratorRule(ToUtf32("DirectAbstractDeclarator"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::PositiveParser(
            new soulng::parsing::GroupingParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::CharParser('['),
                            new soulng::parsing::OptionalParser(
                                new soulng::parsing::GroupingParser(
                                    new soulng::parsing::ActionParser(ToUtf32("A0"),
                                        new soulng::parsing::NonterminalParser(ToUtf32("ConstantExpression"), ToUtf32("ConstantExpression"), 0))))),
                        new soulng::parsing::CharParser(']')),
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::CharParser('('),
                            new soulng::parsing::NonterminalParser(ToUtf32("AbstractDeclarator"), ToUtf32("AbstractDeclarator"), 0)),
                        new soulng::parsing::CharParser(')')))))));
    AddRule(new soulng::parsing::Rule(ToUtf32("PtrOperator"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::CharParser('*'),
                new soulng::parsing::OptionalParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("CVQualifierSeq"), ToUtf32("CVQualifierSeq"), 0))),
            new soulng::parsing::CharParser('&'))));
    AddRule(new CVQualifierSeqRule(ToUtf32("CVQualifierSeq"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::PositiveParser(
            new soulng::parsing::GroupingParser(
                new soulng::parsing::ActionParser(ToUtf32("A0"),
                    new soulng::parsing::NonterminalParser(ToUtf32("CVQualifier"), ToUtf32("CVQualifier"), 0))))));
    AddRule(new InitializerRule(ToUtf32("Initializer"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::CharParser('='),
                new soulng::parsing::ActionParser(ToUtf32("A0"),
                    new soulng::parsing::NonterminalParser(ToUtf32("InitializerClause"), ToUtf32("InitializerClause"), 0))),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::CharParser('(')),
                        new soulng::parsing::NonterminalParser(ToUtf32("ExpressionList"), ToUtf32("ExpressionList"), 1)),
                    new soulng::parsing::CharParser(')'))))));
    AddRule(new InitializerClauseRule(ToUtf32("InitializerClause"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::ActionParser(ToUtf32("A0"),
                    new soulng::parsing::NonterminalParser(ToUtf32("AssignmentExpression"), ToUtf32("AssignmentExpression"), 0)),
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::CharParser('{')),
                        new soulng::parsing::NonterminalParser(ToUtf32("InitializerList"), ToUtf32("InitializerList"), 1)),
                    new soulng::parsing::CharParser('}'))),
            new soulng::parsing::SequenceParser(
                new soulng::parsing::CharParser('{'),
                new soulng::parsing::ActionParser(ToUtf32("A2"),
                    new soulng::parsing::CharParser('}'))))));
    AddRule(new InitializerListRule(ToUtf32("InitializerList"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ListParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("InitializerClause"), ToUtf32("InitializerClause"), 0)),
            new soulng::parsing::CharParser(','))));
}

} } // namespace soulng.code
