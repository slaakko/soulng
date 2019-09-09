#include "Expression.hpp"
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
#include <soulng/code/Declaration.hpp>
#include <soulng/code/Declarator.hpp>
#include <soulng/code/Literal.hpp>
#include <soulng/code/Identifier.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/codedom/Type.hpp>

namespace soulng { namespace code {

using namespace soulng::codedom;
using soulng::util::Trim;
using namespace soulng::parsing;
using namespace soulng::util;
using namespace soulng::unicode;

Expression* Expression::Create()
{
    return Create(new soulng::parsing::ParsingDomain());
}

Expression* Expression::Create(soulng::parsing::ParsingDomain* parsingDomain)
{
    RegisterParsingDomain(parsingDomain);
    Expression* grammar(new Expression(parsingDomain));
    parsingDomain->AddGrammar(grammar);
    grammar->CreateRules();
    grammar->Link();
    return grammar;
}

Expression::Expression(soulng::parsing::ParsingDomain* parsingDomain_): soulng::parsing::Grammar(ToUtf32("Expression"), parsingDomain_->GetNamespaceScope(ToUtf32("soulng.code")), parsingDomain_)
{
    SetOwner(0);
}

soulng::codedom::CppObject* Expression::Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName)
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
    soulng::codedom::CppObject* result = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(value.get());
    stack.pop();
    return result;
}

class Expression::ExpressionRule : public soulng::parsing::Rule
{
public:
    ExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ExpressionRule>(this, &ExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ExpressionRule>(this, &ExpressionRule::A1Action));
        soulng::parsing::NonterminalParser* leftNonterminalParser = GetNonterminal(ToUtf32("left"));
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ExpressionRule>(this, &ExpressionRule::Postleft));
        soulng::parsing::NonterminalParser* rightNonterminalParser = GetNonterminal(ToUtf32("right"));
        rightNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ExpressionRule>(this, &ExpressionRule::Postright));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromleft;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new BinaryOpExpr(context->value, Operator::comma, 0, context->fromright);
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromleft_value.get());
            stack.pop();
        }
    }
    void Postright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromright_value = std::move(stack.top());
            context->fromright = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromright_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromleft(), fromright() {}
        soulng::codedom::CppObject* value;
        soulng::codedom::CppObject* fromleft;
        soulng::codedom::CppObject* fromright;
    };
};

class Expression::ConstantExpressionRule : public soulng::parsing::Rule
{
public:
    ConstantExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ConstantExpressionRule>(this, &ConstantExpressionRule::A0Action));
        soulng::parsing::NonterminalParser* expressionNonterminalParser = GetNonterminal(ToUtf32("Expression"));
        expressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ConstantExpressionRule>(this, &ConstantExpressionRule::PostExpression));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromExpression;
    }
    void PostExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromExpression_value = std::move(stack.top());
            context->fromExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromExpression_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromExpression() {}
        soulng::codedom::CppObject* value;
        soulng::codedom::CppObject* fromExpression;
    };
};

class Expression::AssignmentExpressionRule : public soulng::parsing::Rule
{
public:
    AssignmentExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
        AddLocalVariable(AttrOrVariable(ToUtf32("std::unique_ptr<CppObject>"), ToUtf32("lor")));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<AssignmentExpressionRule>(this, &AssignmentExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<AssignmentExpressionRule>(this, &AssignmentExpressionRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<AssignmentExpressionRule>(this, &AssignmentExpressionRule::A2Action));
        soulng::parsing::ActionParser* a3ActionParser = GetAction(ToUtf32("A3"));
        a3ActionParser->SetAction(new soulng::parsing::MemberParsingAction<AssignmentExpressionRule>(this, &AssignmentExpressionRule::A3Action));
        soulng::parsing::NonterminalParser* logicalOrExpressionNonterminalParser = GetNonterminal(ToUtf32("LogicalOrExpression"));
        logicalOrExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<AssignmentExpressionRule>(this, &AssignmentExpressionRule::PostLogicalOrExpression));
        soulng::parsing::NonterminalParser* assingmentOpNonterminalParser = GetNonterminal(ToUtf32("AssingmentOp"));
        assingmentOpNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<AssignmentExpressionRule>(this, &AssignmentExpressionRule::PostAssingmentOp));
        soulng::parsing::NonterminalParser* assignmentExpressionNonterminalParser = GetNonterminal(ToUtf32("AssignmentExpression"));
        assignmentExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<AssignmentExpressionRule>(this, &AssignmentExpressionRule::PostAssignmentExpression));
        soulng::parsing::NonterminalParser* conditionalExpressionNonterminalParser = GetNonterminal(ToUtf32("ConditionalExpression"));
        conditionalExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<AssignmentExpressionRule>(this, &AssignmentExpressionRule::PostConditionalExpression));
        soulng::parsing::NonterminalParser* throwExpressionNonterminalParser = GetNonterminal(ToUtf32("ThrowExpression"));
        throwExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<AssignmentExpressionRule>(this, &AssignmentExpressionRule::PostThrowExpression));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new BinaryOpExpr(context->lor.release(), context->fromAssingmentOp, 1, context->fromAssignmentExpression);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->lor.reset(context->fromLogicalOrExpression);
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromConditionalExpression;
    }
    void A3Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromThrowExpression;
    }
    void PostLogicalOrExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromLogicalOrExpression_value = std::move(stack.top());
            context->fromLogicalOrExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromLogicalOrExpression_value.get());
            stack.pop();
        }
    }
    void PostAssingmentOp(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromAssingmentOp_value = std::move(stack.top());
            context->fromAssingmentOp = *static_cast<soulng::parsing::ValueObject<Operator>*>(fromAssingmentOp_value.get());
            stack.pop();
        }
    }
    void PostAssignmentExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromAssignmentExpression_value = std::move(stack.top());
            context->fromAssignmentExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromAssignmentExpression_value.get());
            stack.pop();
        }
    }
    void PostConditionalExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromConditionalExpression_value = std::move(stack.top());
            context->fromConditionalExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromConditionalExpression_value.get());
            stack.pop();
        }
    }
    void PostThrowExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromThrowExpression_value = std::move(stack.top());
            context->fromThrowExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromThrowExpression_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), lor(), fromLogicalOrExpression(), fromAssingmentOp(), fromAssignmentExpression(), fromConditionalExpression(), fromThrowExpression() {}
        soulng::codedom::CppObject* value;
        std::unique_ptr<CppObject> lor;
        soulng::codedom::CppObject* fromLogicalOrExpression;
        Operator fromAssingmentOp;
        soulng::codedom::CppObject* fromAssignmentExpression;
        soulng::codedom::CppObject* fromConditionalExpression;
        soulng::codedom::CppObject* fromThrowExpression;
    };
};

class Expression::AssingmentOpRule : public soulng::parsing::Rule
{
public:
    AssingmentOpRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("Operator"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Operator>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<AssingmentOpRule>(this, &AssingmentOpRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = GetOperator(std::u32string(matchBegin, matchEnd));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        Operator value;
    };
};

class Expression::ThrowExpressionRule : public soulng::parsing::Rule
{
public:
    ThrowExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ThrowExpressionRule>(this, &ThrowExpressionRule::A0Action));
        soulng::parsing::NonterminalParser* assignmentExpressionNonterminalParser = GetNonterminal(ToUtf32("AssignmentExpression"));
        assignmentExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ThrowExpressionRule>(this, &ThrowExpressionRule::PostAssignmentExpression));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new ThrowExpr(context->fromAssignmentExpression);
    }
    void PostAssignmentExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromAssignmentExpression_value = std::move(stack.top());
            context->fromAssignmentExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromAssignmentExpression_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromAssignmentExpression() {}
        soulng::codedom::CppObject* value;
        soulng::codedom::CppObject* fromAssignmentExpression;
    };
};

class Expression::ConditionalExpressionRule : public soulng::parsing::Rule
{
public:
    ConditionalExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ConditionalExpressionRule>(this, &ConditionalExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ConditionalExpressionRule>(this, &ConditionalExpressionRule::A1Action));
        soulng::parsing::NonterminalParser* leftNonterminalParser = GetNonterminal(ToUtf32("left"));
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ConditionalExpressionRule>(this, &ConditionalExpressionRule::Postleft));
        soulng::parsing::NonterminalParser* expressionNonterminalParser = GetNonterminal(ToUtf32("Expression"));
        expressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ConditionalExpressionRule>(this, &ConditionalExpressionRule::PostExpression));
        soulng::parsing::NonterminalParser* assignmentExpressionNonterminalParser = GetNonterminal(ToUtf32("AssignmentExpression"));
        assignmentExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ConditionalExpressionRule>(this, &ConditionalExpressionRule::PostAssignmentExpression));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromleft;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new ConditionalExpr(context->value, context->fromExpression, context->fromAssignmentExpression);
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromleft_value.get());
            stack.pop();
        }
    }
    void PostExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromExpression_value = std::move(stack.top());
            context->fromExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromExpression_value.get());
            stack.pop();
        }
    }
    void PostAssignmentExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromAssignmentExpression_value = std::move(stack.top());
            context->fromAssignmentExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromAssignmentExpression_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromleft(), fromExpression(), fromAssignmentExpression() {}
        soulng::codedom::CppObject* value;
        soulng::codedom::CppObject* fromleft;
        soulng::codedom::CppObject* fromExpression;
        soulng::codedom::CppObject* fromAssignmentExpression;
    };
};

class Expression::LogicalOrExpressionRule : public soulng::parsing::Rule
{
public:
    LogicalOrExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<LogicalOrExpressionRule>(this, &LogicalOrExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<LogicalOrExpressionRule>(this, &LogicalOrExpressionRule::A1Action));
        soulng::parsing::NonterminalParser* leftNonterminalParser = GetNonterminal(ToUtf32("left"));
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<LogicalOrExpressionRule>(this, &LogicalOrExpressionRule::Postleft));
        soulng::parsing::NonterminalParser* rightNonterminalParser = GetNonterminal(ToUtf32("right"));
        rightNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<LogicalOrExpressionRule>(this, &LogicalOrExpressionRule::Postright));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromleft;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new BinaryOpExpr(context->value, Operator::or_, 2, context->fromright);
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromleft_value.get());
            stack.pop();
        }
    }
    void Postright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromright_value = std::move(stack.top());
            context->fromright = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromright_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromleft(), fromright() {}
        soulng::codedom::CppObject* value;
        soulng::codedom::CppObject* fromleft;
        soulng::codedom::CppObject* fromright;
    };
};

class Expression::LogicalAndExpressionRule : public soulng::parsing::Rule
{
public:
    LogicalAndExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<LogicalAndExpressionRule>(this, &LogicalAndExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<LogicalAndExpressionRule>(this, &LogicalAndExpressionRule::A1Action));
        soulng::parsing::NonterminalParser* leftNonterminalParser = GetNonterminal(ToUtf32("left"));
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<LogicalAndExpressionRule>(this, &LogicalAndExpressionRule::Postleft));
        soulng::parsing::NonterminalParser* rightNonterminalParser = GetNonterminal(ToUtf32("right"));
        rightNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<LogicalAndExpressionRule>(this, &LogicalAndExpressionRule::Postright));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromleft;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new BinaryOpExpr(context->value, Operator::and_, 3, context->fromright);
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromleft_value.get());
            stack.pop();
        }
    }
    void Postright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromright_value = std::move(stack.top());
            context->fromright = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromright_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromleft(), fromright() {}
        soulng::codedom::CppObject* value;
        soulng::codedom::CppObject* fromleft;
        soulng::codedom::CppObject* fromright;
    };
};

class Expression::InclusiveOrExpressionRule : public soulng::parsing::Rule
{
public:
    InclusiveOrExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<InclusiveOrExpressionRule>(this, &InclusiveOrExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<InclusiveOrExpressionRule>(this, &InclusiveOrExpressionRule::A1Action));
        soulng::parsing::NonterminalParser* leftNonterminalParser = GetNonterminal(ToUtf32("left"));
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<InclusiveOrExpressionRule>(this, &InclusiveOrExpressionRule::Postleft));
        soulng::parsing::NonterminalParser* rightNonterminalParser = GetNonterminal(ToUtf32("right"));
        rightNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<InclusiveOrExpressionRule>(this, &InclusiveOrExpressionRule::Postright));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromleft;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new BinaryOpExpr(context->value, Operator::bitor_, 4, context->fromright);
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromleft_value.get());
            stack.pop();
        }
    }
    void Postright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromright_value = std::move(stack.top());
            context->fromright = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromright_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromleft(), fromright() {}
        soulng::codedom::CppObject* value;
        soulng::codedom::CppObject* fromleft;
        soulng::codedom::CppObject* fromright;
    };
};

class Expression::ExclusiveOrExpressionRule : public soulng::parsing::Rule
{
public:
    ExclusiveOrExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ExclusiveOrExpressionRule>(this, &ExclusiveOrExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ExclusiveOrExpressionRule>(this, &ExclusiveOrExpressionRule::A1Action));
        soulng::parsing::NonterminalParser* leftNonterminalParser = GetNonterminal(ToUtf32("left"));
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ExclusiveOrExpressionRule>(this, &ExclusiveOrExpressionRule::Postleft));
        soulng::parsing::NonterminalParser* rightNonterminalParser = GetNonterminal(ToUtf32("right"));
        rightNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ExclusiveOrExpressionRule>(this, &ExclusiveOrExpressionRule::Postright));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromleft;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new BinaryOpExpr(context->value, Operator::bitxor, 5, context->fromright);
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromleft_value.get());
            stack.pop();
        }
    }
    void Postright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromright_value = std::move(stack.top());
            context->fromright = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromright_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromleft(), fromright() {}
        soulng::codedom::CppObject* value;
        soulng::codedom::CppObject* fromleft;
        soulng::codedom::CppObject* fromright;
    };
};

class Expression::AndExpressionRule : public soulng::parsing::Rule
{
public:
    AndExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<AndExpressionRule>(this, &AndExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<AndExpressionRule>(this, &AndExpressionRule::A1Action));
        soulng::parsing::NonterminalParser* leftNonterminalParser = GetNonterminal(ToUtf32("left"));
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<AndExpressionRule>(this, &AndExpressionRule::Postleft));
        soulng::parsing::NonterminalParser* rightNonterminalParser = GetNonterminal(ToUtf32("right"));
        rightNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<AndExpressionRule>(this, &AndExpressionRule::Postright));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromleft;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new BinaryOpExpr(context->value, Operator::bitand_, 6, context->fromright);
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromleft_value.get());
            stack.pop();
        }
    }
    void Postright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromright_value = std::move(stack.top());
            context->fromright = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromright_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromleft(), fromright() {}
        soulng::codedom::CppObject* value;
        soulng::codedom::CppObject* fromleft;
        soulng::codedom::CppObject* fromright;
    };
};

class Expression::EqualityExpressionRule : public soulng::parsing::Rule
{
public:
    EqualityExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<EqualityExpressionRule>(this, &EqualityExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<EqualityExpressionRule>(this, &EqualityExpressionRule::A1Action));
        soulng::parsing::NonterminalParser* leftNonterminalParser = GetNonterminal(ToUtf32("left"));
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<EqualityExpressionRule>(this, &EqualityExpressionRule::Postleft));
        soulng::parsing::NonterminalParser* eqOpNonterminalParser = GetNonterminal(ToUtf32("EqOp"));
        eqOpNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<EqualityExpressionRule>(this, &EqualityExpressionRule::PostEqOp));
        soulng::parsing::NonterminalParser* rightNonterminalParser = GetNonterminal(ToUtf32("right"));
        rightNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<EqualityExpressionRule>(this, &EqualityExpressionRule::Postright));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromleft;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new BinaryOpExpr(context->value, context->fromEqOp, 7, context->fromright);
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromleft_value.get());
            stack.pop();
        }
    }
    void PostEqOp(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromEqOp_value = std::move(stack.top());
            context->fromEqOp = *static_cast<soulng::parsing::ValueObject<Operator>*>(fromEqOp_value.get());
            stack.pop();
        }
    }
    void Postright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromright_value = std::move(stack.top());
            context->fromright = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromright_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromleft(), fromEqOp(), fromright() {}
        soulng::codedom::CppObject* value;
        soulng::codedom::CppObject* fromleft;
        Operator fromEqOp;
        soulng::codedom::CppObject* fromright;
    };
};

class Expression::EqOpRule : public soulng::parsing::Rule
{
public:
    EqOpRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("Operator"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Operator>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<EqOpRule>(this, &EqOpRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<EqOpRule>(this, &EqOpRule::A1Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::eq;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::notEq;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        Operator value;
    };
};

class Expression::RelationalExpressionRule : public soulng::parsing::Rule
{
public:
    RelationalExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RelationalExpressionRule>(this, &RelationalExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RelationalExpressionRule>(this, &RelationalExpressionRule::A1Action));
        soulng::parsing::NonterminalParser* leftNonterminalParser = GetNonterminal(ToUtf32("left"));
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RelationalExpressionRule>(this, &RelationalExpressionRule::Postleft));
        soulng::parsing::NonterminalParser* relOpNonterminalParser = GetNonterminal(ToUtf32("RelOp"));
        relOpNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RelationalExpressionRule>(this, &RelationalExpressionRule::PostRelOp));
        soulng::parsing::NonterminalParser* rightNonterminalParser = GetNonterminal(ToUtf32("right"));
        rightNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RelationalExpressionRule>(this, &RelationalExpressionRule::Postright));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromleft;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new BinaryOpExpr(context->value, context->fromRelOp, 8, context->fromright);
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromleft_value.get());
            stack.pop();
        }
    }
    void PostRelOp(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromRelOp_value = std::move(stack.top());
            context->fromRelOp = *static_cast<soulng::parsing::ValueObject<Operator>*>(fromRelOp_value.get());
            stack.pop();
        }
    }
    void Postright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromright_value = std::move(stack.top());
            context->fromright = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromright_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromleft(), fromRelOp(), fromright() {}
        soulng::codedom::CppObject* value;
        soulng::codedom::CppObject* fromleft;
        Operator fromRelOp;
        soulng::codedom::CppObject* fromright;
    };
};

class Expression::RelOpRule : public soulng::parsing::Rule
{
public:
    RelOpRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("Operator"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Operator>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RelOpRule>(this, &RelOpRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RelOpRule>(this, &RelOpRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RelOpRule>(this, &RelOpRule::A2Action));
        soulng::parsing::ActionParser* a3ActionParser = GetAction(ToUtf32("A3"));
        a3ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RelOpRule>(this, &RelOpRule::A3Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::lessOrEq;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::greaterOrEq;
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::less;
    }
    void A3Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::greater;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        Operator value;
    };
};

class Expression::ShiftExpressionRule : public soulng::parsing::Rule
{
public:
    ShiftExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ShiftExpressionRule>(this, &ShiftExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ShiftExpressionRule>(this, &ShiftExpressionRule::A1Action));
        soulng::parsing::NonterminalParser* leftNonterminalParser = GetNonterminal(ToUtf32("left"));
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ShiftExpressionRule>(this, &ShiftExpressionRule::Postleft));
        soulng::parsing::NonterminalParser* shiftOpNonterminalParser = GetNonterminal(ToUtf32("ShiftOp"));
        shiftOpNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ShiftExpressionRule>(this, &ShiftExpressionRule::PostShiftOp));
        soulng::parsing::NonterminalParser* rightNonterminalParser = GetNonterminal(ToUtf32("right"));
        rightNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ShiftExpressionRule>(this, &ShiftExpressionRule::Postright));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromleft;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new BinaryOpExpr(context->value, context->fromShiftOp, 9, context->fromright);
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromleft_value.get());
            stack.pop();
        }
    }
    void PostShiftOp(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromShiftOp_value = std::move(stack.top());
            context->fromShiftOp = *static_cast<soulng::parsing::ValueObject<Operator>*>(fromShiftOp_value.get());
            stack.pop();
        }
    }
    void Postright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromright_value = std::move(stack.top());
            context->fromright = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromright_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromleft(), fromShiftOp(), fromright() {}
        soulng::codedom::CppObject* value;
        soulng::codedom::CppObject* fromleft;
        Operator fromShiftOp;
        soulng::codedom::CppObject* fromright;
    };
};

class Expression::ShiftOpRule : public soulng::parsing::Rule
{
public:
    ShiftOpRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("Operator"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Operator>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ShiftOpRule>(this, &ShiftOpRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ShiftOpRule>(this, &ShiftOpRule::A1Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::shiftLeft;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::shiftRight;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        Operator value;
    };
};

class Expression::AdditiveExpressionRule : public soulng::parsing::Rule
{
public:
    AdditiveExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<AdditiveExpressionRule>(this, &AdditiveExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<AdditiveExpressionRule>(this, &AdditiveExpressionRule::A1Action));
        soulng::parsing::NonterminalParser* leftNonterminalParser = GetNonterminal(ToUtf32("left"));
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<AdditiveExpressionRule>(this, &AdditiveExpressionRule::Postleft));
        soulng::parsing::NonterminalParser* addOpNonterminalParser = GetNonterminal(ToUtf32("AddOp"));
        addOpNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<AdditiveExpressionRule>(this, &AdditiveExpressionRule::PostAddOp));
        soulng::parsing::NonterminalParser* rightNonterminalParser = GetNonterminal(ToUtf32("right"));
        rightNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<AdditiveExpressionRule>(this, &AdditiveExpressionRule::Postright));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromleft;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new BinaryOpExpr(context->value, context->fromAddOp, 10, context->fromright);
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromleft_value.get());
            stack.pop();
        }
    }
    void PostAddOp(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromAddOp_value = std::move(stack.top());
            context->fromAddOp = *static_cast<soulng::parsing::ValueObject<Operator>*>(fromAddOp_value.get());
            stack.pop();
        }
    }
    void Postright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromright_value = std::move(stack.top());
            context->fromright = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromright_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromleft(), fromAddOp(), fromright() {}
        soulng::codedom::CppObject* value;
        soulng::codedom::CppObject* fromleft;
        Operator fromAddOp;
        soulng::codedom::CppObject* fromright;
    };
};

class Expression::AddOpRule : public soulng::parsing::Rule
{
public:
    AddOpRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("Operator"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Operator>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<AddOpRule>(this, &AddOpRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<AddOpRule>(this, &AddOpRule::A1Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::plus;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::minus;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        Operator value;
    };
};

class Expression::MultiplicativeExpressionRule : public soulng::parsing::Rule
{
public:
    MultiplicativeExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<MultiplicativeExpressionRule>(this, &MultiplicativeExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<MultiplicativeExpressionRule>(this, &MultiplicativeExpressionRule::A1Action));
        soulng::parsing::NonterminalParser* leftNonterminalParser = GetNonterminal(ToUtf32("left"));
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<MultiplicativeExpressionRule>(this, &MultiplicativeExpressionRule::Postleft));
        soulng::parsing::NonterminalParser* mulOpNonterminalParser = GetNonterminal(ToUtf32("MulOp"));
        mulOpNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<MultiplicativeExpressionRule>(this, &MultiplicativeExpressionRule::PostMulOp));
        soulng::parsing::NonterminalParser* rightNonterminalParser = GetNonterminal(ToUtf32("right"));
        rightNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<MultiplicativeExpressionRule>(this, &MultiplicativeExpressionRule::Postright));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromleft;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new BinaryOpExpr(context->value, context->fromMulOp, 11, context->fromright);
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromleft_value.get());
            stack.pop();
        }
    }
    void PostMulOp(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromMulOp_value = std::move(stack.top());
            context->fromMulOp = *static_cast<soulng::parsing::ValueObject<Operator>*>(fromMulOp_value.get());
            stack.pop();
        }
    }
    void Postright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromright_value = std::move(stack.top());
            context->fromright = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromright_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromleft(), fromMulOp(), fromright() {}
        soulng::codedom::CppObject* value;
        soulng::codedom::CppObject* fromleft;
        Operator fromMulOp;
        soulng::codedom::CppObject* fromright;
    };
};

class Expression::MulOpRule : public soulng::parsing::Rule
{
public:
    MulOpRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("Operator"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Operator>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<MulOpRule>(this, &MulOpRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<MulOpRule>(this, &MulOpRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<MulOpRule>(this, &MulOpRule::A2Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::mul;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::div;
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::rem;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        Operator value;
    };
};

class Expression::PmExpressionRule : public soulng::parsing::Rule
{
public:
    PmExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PmExpressionRule>(this, &PmExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PmExpressionRule>(this, &PmExpressionRule::A1Action));
        soulng::parsing::NonterminalParser* leftNonterminalParser = GetNonterminal(ToUtf32("left"));
        leftNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PmExpressionRule>(this, &PmExpressionRule::Postleft));
        soulng::parsing::NonterminalParser* pmOpNonterminalParser = GetNonterminal(ToUtf32("PmOp"));
        pmOpNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PmExpressionRule>(this, &PmExpressionRule::PostPmOp));
        soulng::parsing::NonterminalParser* rightNonterminalParser = GetNonterminal(ToUtf32("right"));
        rightNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PmExpressionRule>(this, &PmExpressionRule::Postright));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromleft;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new BinaryOpExpr(context->value, context->fromPmOp, 12, context->fromright);
    }
    void Postleft(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromleft_value = std::move(stack.top());
            context->fromleft = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromleft_value.get());
            stack.pop();
        }
    }
    void PostPmOp(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromPmOp_value = std::move(stack.top());
            context->fromPmOp = *static_cast<soulng::parsing::ValueObject<Operator>*>(fromPmOp_value.get());
            stack.pop();
        }
    }
    void Postright(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromright_value = std::move(stack.top());
            context->fromright = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromright_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromleft(), fromPmOp(), fromright() {}
        soulng::codedom::CppObject* value;
        soulng::codedom::CppObject* fromleft;
        Operator fromPmOp;
        soulng::codedom::CppObject* fromright;
    };
};

class Expression::PmOpRule : public soulng::parsing::Rule
{
public:
    PmOpRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("Operator"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Operator>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PmOpRule>(this, &PmOpRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PmOpRule>(this, &PmOpRule::A1Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::dotStar;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::arrowStar;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        Operator value;
    };
};

class Expression::CastExpressionRule : public soulng::parsing::Rule
{
public:
    CastExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
        AddLocalVariable(AttrOrVariable(ToUtf32("std::unique_ptr<CppObject>"), ToUtf32("ce")));
        AddLocalVariable(AttrOrVariable(ToUtf32("std::unique_ptr<CppObject>"), ToUtf32("ti")));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CastExpressionRule>(this, &CastExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CastExpressionRule>(this, &CastExpressionRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CastExpressionRule>(this, &CastExpressionRule::A2Action));
        soulng::parsing::ActionParser* a3ActionParser = GetAction(ToUtf32("A3"));
        a3ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CastExpressionRule>(this, &CastExpressionRule::A3Action));
        soulng::parsing::NonterminalParser* typeIdNonterminalParser = GetNonterminal(ToUtf32("TypeId"));
        typeIdNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<CastExpressionRule>(this, &CastExpressionRule::PostTypeId));
        soulng::parsing::NonterminalParser* castExpressionNonterminalParser = GetNonterminal(ToUtf32("CastExpression"));
        castExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<CastExpressionRule>(this, &CastExpressionRule::PostCastExpression));
        soulng::parsing::NonterminalParser* unaryExpressionNonterminalParser = GetNonterminal(ToUtf32("UnaryExpression"));
        unaryExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<CastExpressionRule>(this, &CastExpressionRule::PostUnaryExpression));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->ce.release();
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->ce.reset(new CastExpr(context->ti.release(), context->fromCastExpression));
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->ti.reset(context->fromTypeId);
    }
    void A3Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->ce.reset(context->fromUnaryExpression);
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
    void PostCastExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromCastExpression_value = std::move(stack.top());
            context->fromCastExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromCastExpression_value.get());
            stack.pop();
        }
    }
    void PostUnaryExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromUnaryExpression_value = std::move(stack.top());
            context->fromUnaryExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromUnaryExpression_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), ce(), ti(), fromTypeId(), fromCastExpression(), fromUnaryExpression() {}
        soulng::codedom::CppObject* value;
        std::unique_ptr<CppObject> ce;
        std::unique_ptr<CppObject> ti;
        soulng::codedom::TypeId* fromTypeId;
        soulng::codedom::CppObject* fromCastExpression;
        soulng::codedom::CppObject* fromUnaryExpression;
    };
};

class Expression::UnaryExpressionRule : public soulng::parsing::Rule
{
public:
    UnaryExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
        AddLocalVariable(AttrOrVariable(ToUtf32("std::unique_ptr<CppObject>"), ToUtf32("ue")));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UnaryExpressionRule>(this, &UnaryExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UnaryExpressionRule>(this, &UnaryExpressionRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UnaryExpressionRule>(this, &UnaryExpressionRule::A2Action));
        soulng::parsing::ActionParser* a3ActionParser = GetAction(ToUtf32("A3"));
        a3ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UnaryExpressionRule>(this, &UnaryExpressionRule::A3Action));
        soulng::parsing::ActionParser* a4ActionParser = GetAction(ToUtf32("A4"));
        a4ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UnaryExpressionRule>(this, &UnaryExpressionRule::A4Action));
        soulng::parsing::ActionParser* a5ActionParser = GetAction(ToUtf32("A5"));
        a5ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UnaryExpressionRule>(this, &UnaryExpressionRule::A5Action));
        soulng::parsing::ActionParser* a6ActionParser = GetAction(ToUtf32("A6"));
        a6ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UnaryExpressionRule>(this, &UnaryExpressionRule::A6Action));
        soulng::parsing::ActionParser* a7ActionParser = GetAction(ToUtf32("A7"));
        a7ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UnaryExpressionRule>(this, &UnaryExpressionRule::A7Action));
        soulng::parsing::ActionParser* a8ActionParser = GetAction(ToUtf32("A8"));
        a8ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UnaryExpressionRule>(this, &UnaryExpressionRule::A8Action));
        soulng::parsing::ActionParser* a9ActionParser = GetAction(ToUtf32("A9"));
        a9ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UnaryExpressionRule>(this, &UnaryExpressionRule::A9Action));
        soulng::parsing::NonterminalParser* postfixExpressionNonterminalParser = GetNonterminal(ToUtf32("PostfixExpression"));
        postfixExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<UnaryExpressionRule>(this, &UnaryExpressionRule::PostPostfixExpression));
        soulng::parsing::NonterminalParser* postCastExpressionNonterminalParser = GetNonterminal(ToUtf32("PostCastExpression"));
        postCastExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<UnaryExpressionRule>(this, &UnaryExpressionRule::PostPostCastExpression));
        soulng::parsing::NonterminalParser* e1NonterminalParser = GetNonterminal(ToUtf32("e1"));
        e1NonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<UnaryExpressionRule>(this, &UnaryExpressionRule::Poste1));
        soulng::parsing::NonterminalParser* e2NonterminalParser = GetNonterminal(ToUtf32("e2"));
        e2NonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<UnaryExpressionRule>(this, &UnaryExpressionRule::Poste2));
        soulng::parsing::NonterminalParser* unaryOperatorNonterminalParser = GetNonterminal(ToUtf32("UnaryOperator"));
        unaryOperatorNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<UnaryExpressionRule>(this, &UnaryExpressionRule::PostUnaryOperator));
        soulng::parsing::NonterminalParser* castExpressionNonterminalParser = GetNonterminal(ToUtf32("CastExpression"));
        castExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<UnaryExpressionRule>(this, &UnaryExpressionRule::PostCastExpression));
        soulng::parsing::NonterminalParser* typeIdNonterminalParser = GetNonterminal(ToUtf32("TypeId"));
        typeIdNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<UnaryExpressionRule>(this, &UnaryExpressionRule::PostTypeId));
        soulng::parsing::NonterminalParser* e3NonterminalParser = GetNonterminal(ToUtf32("e3"));
        e3NonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<UnaryExpressionRule>(this, &UnaryExpressionRule::Poste3));
        soulng::parsing::NonterminalParser* newExpressionNonterminalParser = GetNonterminal(ToUtf32("NewExpression"));
        newExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<UnaryExpressionRule>(this, &UnaryExpressionRule::PostNewExpression));
        soulng::parsing::NonterminalParser* deleteExpressionNonterminalParser = GetNonterminal(ToUtf32("DeleteExpression"));
        deleteExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<UnaryExpressionRule>(this, &UnaryExpressionRule::PostDeleteExpression));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->ue.release();
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->ue.reset(context->fromPostfixExpression);
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->ue.reset(context->fromPostCastExpression);
    }
    void A3Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->ue.reset(new PreIncrementExpr(context->frome1));
    }
    void A4Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->ue.reset(new PreDecrementExpr(context->frome2));
    }
    void A5Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->ue.reset(new UnaryOpExpr(context->fromUnaryOperator, context->fromCastExpression));
    }
    void A6Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->ue.reset(new SizeOfExpr(context->fromTypeId, true));
    }
    void A7Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->ue.reset(new SizeOfExpr(context->frome3, false));
    }
    void A8Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->ue.reset(context->fromNewExpression);
    }
    void A9Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->ue.reset(context->fromDeleteExpression);
    }
    void PostPostfixExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromPostfixExpression_value = std::move(stack.top());
            context->fromPostfixExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromPostfixExpression_value.get());
            stack.pop();
        }
    }
    void PostPostCastExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromPostCastExpression_value = std::move(stack.top());
            context->fromPostCastExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromPostCastExpression_value.get());
            stack.pop();
        }
    }
    void Poste1(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> frome1_value = std::move(stack.top());
            context->frome1 = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(frome1_value.get());
            stack.pop();
        }
    }
    void Poste2(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> frome2_value = std::move(stack.top());
            context->frome2 = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(frome2_value.get());
            stack.pop();
        }
    }
    void PostUnaryOperator(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromUnaryOperator_value = std::move(stack.top());
            context->fromUnaryOperator = *static_cast<soulng::parsing::ValueObject<Operator>*>(fromUnaryOperator_value.get());
            stack.pop();
        }
    }
    void PostCastExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromCastExpression_value = std::move(stack.top());
            context->fromCastExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromCastExpression_value.get());
            stack.pop();
        }
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
    void Poste3(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> frome3_value = std::move(stack.top());
            context->frome3 = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(frome3_value.get());
            stack.pop();
        }
    }
    void PostNewExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromNewExpression_value = std::move(stack.top());
            context->fromNewExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromNewExpression_value.get());
            stack.pop();
        }
    }
    void PostDeleteExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromDeleteExpression_value = std::move(stack.top());
            context->fromDeleteExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromDeleteExpression_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), ue(), fromPostfixExpression(), fromPostCastExpression(), frome1(), frome2(), fromUnaryOperator(), fromCastExpression(), fromTypeId(), frome3(), fromNewExpression(), fromDeleteExpression() {}
        soulng::codedom::CppObject* value;
        std::unique_ptr<CppObject> ue;
        soulng::codedom::CppObject* fromPostfixExpression;
        soulng::codedom::CppObject* fromPostCastExpression;
        soulng::codedom::CppObject* frome1;
        soulng::codedom::CppObject* frome2;
        Operator fromUnaryOperator;
        soulng::codedom::CppObject* fromCastExpression;
        soulng::codedom::TypeId* fromTypeId;
        soulng::codedom::CppObject* frome3;
        soulng::codedom::CppObject* fromNewExpression;
        soulng::codedom::CppObject* fromDeleteExpression;
    };
};

class Expression::UnaryOperatorRule : public soulng::parsing::Rule
{
public:
    UnaryOperatorRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("Operator"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Operator>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UnaryOperatorRule>(this, &UnaryOperatorRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UnaryOperatorRule>(this, &UnaryOperatorRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UnaryOperatorRule>(this, &UnaryOperatorRule::A2Action));
        soulng::parsing::ActionParser* a3ActionParser = GetAction(ToUtf32("A3"));
        a3ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UnaryOperatorRule>(this, &UnaryOperatorRule::A3Action));
        soulng::parsing::ActionParser* a4ActionParser = GetAction(ToUtf32("A4"));
        a4ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UnaryOperatorRule>(this, &UnaryOperatorRule::A4Action));
        soulng::parsing::ActionParser* a5ActionParser = GetAction(ToUtf32("A5"));
        a5ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UnaryOperatorRule>(this, &UnaryOperatorRule::A5Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::deref;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::addrOf;
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::plus;
    }
    void A3Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::minus;
    }
    void A4Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::not_;
    }
    void A5Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Operator::neg;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        Operator value;
    };
};

class Expression::NewExpressionRule : public soulng::parsing::Rule
{
public:
    NewExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
        AddLocalVariable(AttrOrVariable(ToUtf32("bool"), ToUtf32("global")));
        AddLocalVariable(AttrOrVariable(ToUtf32("TypeId*"), ToUtf32("typeId")));
        AddLocalVariable(AttrOrVariable(ToUtf32("bool"), ToUtf32("parens")));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NewExpressionRule>(this, &NewExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NewExpressionRule>(this, &NewExpressionRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NewExpressionRule>(this, &NewExpressionRule::A2Action));
        soulng::parsing::ActionParser* a3ActionParser = GetAction(ToUtf32("A3"));
        a3ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NewExpressionRule>(this, &NewExpressionRule::A3Action));
        soulng::parsing::NonterminalParser* newPlacementNonterminalParser = GetNonterminal(ToUtf32("NewPlacement"));
        newPlacementNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<NewExpressionRule>(this, &NewExpressionRule::PostNewPlacement));
        soulng::parsing::NonterminalParser* newTypeIdNonterminalParser = GetNonterminal(ToUtf32("NewTypeId"));
        newTypeIdNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<NewExpressionRule>(this, &NewExpressionRule::PostNewTypeId));
        soulng::parsing::NonterminalParser* typeIdNonterminalParser = GetNonterminal(ToUtf32("TypeId"));
        typeIdNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<NewExpressionRule>(this, &NewExpressionRule::PostTypeId));
        soulng::parsing::NonterminalParser* newInitializerNonterminalParser = GetNonterminal(ToUtf32("NewInitializer"));
        newInitializerNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<NewExpressionRule>(this, &NewExpressionRule::PostNewInitializer));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new NewExpr(context->global, context->fromNewPlacement, context->typeId, context->parens, context->fromNewInitializer);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->global = true;
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->typeId = context->fromNewTypeId;
        context->parens = false;
    }
    void A3Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->typeId = context->fromTypeId;
        context->parens = true;
    }
    void PostNewPlacement(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromNewPlacement_value = std::move(stack.top());
            context->fromNewPlacement = *static_cast<soulng::parsing::ValueObject<std::vector<soulng::codedom::CppObject*>>*>(fromNewPlacement_value.get());
            stack.pop();
        }
    }
    void PostNewTypeId(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromNewTypeId_value = std::move(stack.top());
            context->fromNewTypeId = *static_cast<soulng::parsing::ValueObject<soulng::codedom::TypeId*>*>(fromNewTypeId_value.get());
            stack.pop();
        }
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
    void PostNewInitializer(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromNewInitializer_value = std::move(stack.top());
            context->fromNewInitializer = *static_cast<soulng::parsing::ValueObject<std::vector<soulng::codedom::CppObject*>>*>(fromNewInitializer_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), global(), typeId(), parens(), fromNewPlacement(), fromNewTypeId(), fromTypeId(), fromNewInitializer() {}
        soulng::codedom::CppObject* value;
        bool global;
        TypeId* typeId;
        bool parens;
        std::vector<soulng::codedom::CppObject*> fromNewPlacement;
        soulng::codedom::TypeId* fromNewTypeId;
        soulng::codedom::TypeId* fromTypeId;
        std::vector<soulng::codedom::CppObject*> fromNewInitializer;
    };
};

class Expression::NewTypeIdRule : public soulng::parsing::Rule
{
public:
    NewTypeIdRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::TypeId*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::TypeId*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NewTypeIdRule>(this, &NewTypeIdRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NewTypeIdRule>(this, &NewTypeIdRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NewTypeIdRule>(this, &NewTypeIdRule::A2Action));
        soulng::parsing::ActionParser* a3ActionParser = GetAction(ToUtf32("A3"));
        a3ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NewTypeIdRule>(this, &NewTypeIdRule::A3Action));
        soulng::parsing::NonterminalParser* typeSpecifierSeqNonterminalParser = GetNonterminal(ToUtf32("TypeSpecifierSeq"));
        typeSpecifierSeqNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<NewTypeIdRule>(this, &NewTypeIdRule::PreTypeSpecifierSeq));
        soulng::parsing::NonterminalParser* typeNameNonterminalParser = GetNonterminal(ToUtf32("TypeName"));
        typeNameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<NewTypeIdRule>(this, &NewTypeIdRule::PostTypeName));
        soulng::parsing::NonterminalParser* newDeclaratorNonterminalParser = GetNonterminal(ToUtf32("NewDeclarator"));
        newDeclaratorNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<NewTypeIdRule>(this, &NewTypeIdRule::PostNewDeclarator));
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
        context->ti->Declarator() = context->fromNewDeclarator;
    }
    void PreTypeSpecifierSeq(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::TypeId*>(context->ti.get())));
    }
    void PostTypeName(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromTypeName_value = std::move(stack.top());
            context->fromTypeName = *static_cast<soulng::parsing::ValueObject<soulng::codedom::TypeName*>*>(fromTypeName_value.get());
            stack.pop();
        }
    }
    void PostNewDeclarator(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromNewDeclarator_value = std::move(stack.top());
            context->fromNewDeclarator = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromNewDeclarator_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), ti(), fromTypeName(), fromNewDeclarator() {}
        soulng::codedom::TypeId* value;
        std::unique_ptr<TypeId> ti;
        soulng::codedom::TypeName* fromTypeName;
        std::u32string fromNewDeclarator;
    };
};

class Expression::NewDeclaratorRule : public soulng::parsing::Rule
{
public:
    NewDeclaratorRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
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
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NewDeclaratorRule>(this, &NewDeclaratorRule::A0Action));
        soulng::parsing::NonterminalParser* newDeclaratorNonterminalParser = GetNonterminal(ToUtf32("NewDeclarator"));
        newDeclaratorNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<NewDeclaratorRule>(this, &NewDeclaratorRule::PostNewDeclarator));
        soulng::parsing::NonterminalParser* directNewDeclaratorNonterminalParser = GetNonterminal(ToUtf32("DirectNewDeclarator"));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Trim(std::u32string(matchBegin, matchEnd));
    }
    void PostNewDeclarator(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromNewDeclarator_value = std::move(stack.top());
            context->fromNewDeclarator = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromNewDeclarator_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromNewDeclarator() {}
        std::u32string value;
        std::u32string fromNewDeclarator;
    };
};

class Expression::DirectNewDeclaratorRule : public soulng::parsing::Rule
{
public:
    DirectNewDeclaratorRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddLocalVariable(AttrOrVariable(ToUtf32("std::unique_ptr<CppObject>"), ToUtf32("e")));
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
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DirectNewDeclaratorRule>(this, &DirectNewDeclaratorRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DirectNewDeclaratorRule>(this, &DirectNewDeclaratorRule::A1Action));
        soulng::parsing::NonterminalParser* expressionNonterminalParser = GetNonterminal(ToUtf32("Expression"));
        expressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DirectNewDeclaratorRule>(this, &DirectNewDeclaratorRule::PostExpression));
        soulng::parsing::NonterminalParser* constantExpressionNonterminalParser = GetNonterminal(ToUtf32("ConstantExpression"));
        constantExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DirectNewDeclaratorRule>(this, &DirectNewDeclaratorRule::PostConstantExpression));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->e.reset(context->fromExpression);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->e.reset(context->fromConstantExpression);
    }
    void PostExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromExpression_value = std::move(stack.top());
            context->fromExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromExpression_value.get());
            stack.pop();
        }
    }
    void PostConstantExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromConstantExpression_value = std::move(stack.top());
            context->fromConstantExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromConstantExpression_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): e(), fromExpression(), fromConstantExpression() {}
        std::unique_ptr<CppObject> e;
        soulng::codedom::CppObject* fromExpression;
        soulng::codedom::CppObject* fromConstantExpression;
    };
};

class Expression::NewPlacementRule : public soulng::parsing::Rule
{
public:
    NewPlacementRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("std::vector<soulng::codedom::CppObject*>"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<std::vector<soulng::codedom::CppObject*>>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NewPlacementRule>(this, &NewPlacementRule::A0Action));
        soulng::parsing::NonterminalParser* expressionListNonterminalParser = GetNonterminal(ToUtf32("ExpressionList"));
        expressionListNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<NewPlacementRule>(this, &NewPlacementRule::PostExpressionList));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromExpressionList;
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
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromExpressionList() {}
        std::vector<soulng::codedom::CppObject*> value;
        std::vector<soulng::codedom::CppObject*> fromExpressionList;
    };
};

class Expression::NewInitializerRule : public soulng::parsing::Rule
{
public:
    NewInitializerRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("std::vector<soulng::codedom::CppObject*>"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<std::vector<soulng::codedom::CppObject*>>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NewInitializerRule>(this, &NewInitializerRule::A0Action));
        soulng::parsing::NonterminalParser* expressionListNonterminalParser = GetNonterminal(ToUtf32("ExpressionList"));
        expressionListNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<NewInitializerRule>(this, &NewInitializerRule::PostExpressionList));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromExpressionList;
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
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromExpressionList() {}
        std::vector<soulng::codedom::CppObject*> value;
        std::vector<soulng::codedom::CppObject*> fromExpressionList;
    };
};

class Expression::DeleteExpressionRule : public soulng::parsing::Rule
{
public:
    DeleteExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
        AddLocalVariable(AttrOrVariable(ToUtf32("bool"), ToUtf32("global")));
        AddLocalVariable(AttrOrVariable(ToUtf32("bool"), ToUtf32("array")));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeleteExpressionRule>(this, &DeleteExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeleteExpressionRule>(this, &DeleteExpressionRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeleteExpressionRule>(this, &DeleteExpressionRule::A2Action));
        soulng::parsing::NonterminalParser* castExpressionNonterminalParser = GetNonterminal(ToUtf32("CastExpression"));
        castExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DeleteExpressionRule>(this, &DeleteExpressionRule::PostCastExpression));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new DeleteExpr(context->global, context->array, context->fromCastExpression);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->global = true;
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->array = true;
    }
    void PostCastExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromCastExpression_value = std::move(stack.top());
            context->fromCastExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromCastExpression_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), global(), array(), fromCastExpression() {}
        soulng::codedom::CppObject* value;
        bool global;
        bool array;
        soulng::codedom::CppObject* fromCastExpression;
    };
};

class Expression::PostfixExpressionRule : public soulng::parsing::Rule
{
public:
    PostfixExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
        AddLocalVariable(AttrOrVariable(ToUtf32("std::unique_ptr<CppObject>"), ToUtf32("pe")));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PostfixExpressionRule>(this, &PostfixExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PostfixExpressionRule>(this, &PostfixExpressionRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PostfixExpressionRule>(this, &PostfixExpressionRule::A2Action));
        soulng::parsing::ActionParser* a3ActionParser = GetAction(ToUtf32("A3"));
        a3ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PostfixExpressionRule>(this, &PostfixExpressionRule::A3Action));
        soulng::parsing::ActionParser* a4ActionParser = GetAction(ToUtf32("A4"));
        a4ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PostfixExpressionRule>(this, &PostfixExpressionRule::A4Action));
        soulng::parsing::ActionParser* a5ActionParser = GetAction(ToUtf32("A5"));
        a5ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PostfixExpressionRule>(this, &PostfixExpressionRule::A5Action));
        soulng::parsing::ActionParser* a6ActionParser = GetAction(ToUtf32("A6"));
        a6ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PostfixExpressionRule>(this, &PostfixExpressionRule::A6Action));
        soulng::parsing::ActionParser* a7ActionParser = GetAction(ToUtf32("A7"));
        a7ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PostfixExpressionRule>(this, &PostfixExpressionRule::A7Action));
        soulng::parsing::ActionParser* a8ActionParser = GetAction(ToUtf32("A8"));
        a8ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PostfixExpressionRule>(this, &PostfixExpressionRule::A8Action));
        soulng::parsing::NonterminalParser* primaryExpressionNonterminalParser = GetNonterminal(ToUtf32("PrimaryExpression"));
        primaryExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PostfixExpressionRule>(this, &PostfixExpressionRule::PostPrimaryExpression));
        soulng::parsing::NonterminalParser* indexNonterminalParser = GetNonterminal(ToUtf32("index"));
        indexNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PostfixExpressionRule>(this, &PostfixExpressionRule::Postindex));
        soulng::parsing::NonterminalParser* invokeNonterminalParser = GetNonterminal(ToUtf32("invoke"));
        invokeNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PostfixExpressionRule>(this, &PostfixExpressionRule::Postinvoke));
        soulng::parsing::NonterminalParser* memberNonterminalParser = GetNonterminal(ToUtf32("member"));
        memberNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PostfixExpressionRule>(this, &PostfixExpressionRule::Postmember));
        soulng::parsing::NonterminalParser* ptrmemberNonterminalParser = GetNonterminal(ToUtf32("ptrmember"));
        ptrmemberNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PostfixExpressionRule>(this, &PostfixExpressionRule::Postptrmember));
        soulng::parsing::NonterminalParser* typeSpecifierOrTypeNameNonterminalParser = GetNonterminal(ToUtf32("TypeSpecifierOrTypeName"));
        typeSpecifierOrTypeNameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PostfixExpressionRule>(this, &PostfixExpressionRule::PostTypeSpecifierOrTypeName));
        soulng::parsing::NonterminalParser* typeConstructionNonterminalParser = GetNonterminal(ToUtf32("typeConstruction"));
        typeConstructionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PostfixExpressionRule>(this, &PostfixExpressionRule::PosttypeConstruction));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->pe.release();
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->pe.reset(context->fromPrimaryExpression);
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->pe.reset(new IndexExpr(context->pe.release(), context->fromindex));
    }
    void A3Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->pe.reset(new InvokeExpr(context->pe.release(), context->frominvoke));
    }
    void A4Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->pe.reset(new MemberAccessExpr(context->pe.release(), context->frommember));
    }
    void A5Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->pe.reset(new PtrMemberAccessExpr(context->pe.release(), context->fromptrmember));
    }
    void A6Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->pe.reset(new PostIncrementExpr(context->pe.release()));
    }
    void A7Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->pe.reset(new PostDecrementExpr(context->pe.release()));
    }
    void A8Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->pe.reset(new InvokeExpr(context->fromTypeSpecifierOrTypeName, context->fromtypeConstruction));
    }
    void PostPrimaryExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromPrimaryExpression_value = std::move(stack.top());
            context->fromPrimaryExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromPrimaryExpression_value.get());
            stack.pop();
        }
    }
    void Postindex(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromindex_value = std::move(stack.top());
            context->fromindex = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromindex_value.get());
            stack.pop();
        }
    }
    void Postinvoke(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> frominvoke_value = std::move(stack.top());
            context->frominvoke = *static_cast<soulng::parsing::ValueObject<std::vector<soulng::codedom::CppObject*>>*>(frominvoke_value.get());
            stack.pop();
        }
    }
    void Postmember(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> frommember_value = std::move(stack.top());
            context->frommember = *static_cast<soulng::parsing::ValueObject<soulng::codedom::IdExpr*>*>(frommember_value.get());
            stack.pop();
        }
    }
    void Postptrmember(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromptrmember_value = std::move(stack.top());
            context->fromptrmember = *static_cast<soulng::parsing::ValueObject<soulng::codedom::IdExpr*>*>(fromptrmember_value.get());
            stack.pop();
        }
    }
    void PostTypeSpecifierOrTypeName(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromTypeSpecifierOrTypeName_value = std::move(stack.top());
            context->fromTypeSpecifierOrTypeName = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromTypeSpecifierOrTypeName_value.get());
            stack.pop();
        }
    }
    void PosttypeConstruction(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromtypeConstruction_value = std::move(stack.top());
            context->fromtypeConstruction = *static_cast<soulng::parsing::ValueObject<std::vector<soulng::codedom::CppObject*>>*>(fromtypeConstruction_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), pe(), fromPrimaryExpression(), fromindex(), frominvoke(), frommember(), fromptrmember(), fromTypeSpecifierOrTypeName(), fromtypeConstruction() {}
        soulng::codedom::CppObject* value;
        std::unique_ptr<CppObject> pe;
        soulng::codedom::CppObject* fromPrimaryExpression;
        soulng::codedom::CppObject* fromindex;
        std::vector<soulng::codedom::CppObject*> frominvoke;
        soulng::codedom::IdExpr* frommember;
        soulng::codedom::IdExpr* fromptrmember;
        soulng::codedom::CppObject* fromTypeSpecifierOrTypeName;
        std::vector<soulng::codedom::CppObject*> fromtypeConstruction;
    };
};

class Expression::TypeSpecifierOrTypeNameRule : public soulng::parsing::Rule
{
public:
    TypeSpecifierOrTypeNameRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TypeSpecifierOrTypeNameRule>(this, &TypeSpecifierOrTypeNameRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TypeSpecifierOrTypeNameRule>(this, &TypeSpecifierOrTypeNameRule::A1Action));
        soulng::parsing::NonterminalParser* simpleTypeSpecifierNonterminalParser = GetNonterminal(ToUtf32("SimpleTypeSpecifier"));
        simpleTypeSpecifierNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<TypeSpecifierOrTypeNameRule>(this, &TypeSpecifierOrTypeNameRule::PostSimpleTypeSpecifier));
        soulng::parsing::NonterminalParser* typeNameNonterminalParser = GetNonterminal(ToUtf32("TypeName"));
        typeNameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<TypeSpecifierOrTypeNameRule>(this, &TypeSpecifierOrTypeNameRule::PostTypeName));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromSimpleTypeSpecifier;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromTypeName;
    }
    void PostSimpleTypeSpecifier(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromSimpleTypeSpecifier_value = std::move(stack.top());
            context->fromSimpleTypeSpecifier = *static_cast<soulng::parsing::ValueObject<soulng::codedom::TypeSpecifier*>*>(fromSimpleTypeSpecifier_value.get());
            stack.pop();
        }
    }
    void PostTypeName(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromTypeName_value = std::move(stack.top());
            context->fromTypeName = *static_cast<soulng::parsing::ValueObject<soulng::codedom::TypeName*>*>(fromTypeName_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromSimpleTypeSpecifier(), fromTypeName() {}
        soulng::codedom::CppObject* value;
        soulng::codedom::TypeSpecifier* fromSimpleTypeSpecifier;
        soulng::codedom::TypeName* fromTypeName;
    };
};

class Expression::PostCastExpressionRule : public soulng::parsing::Rule
{
public:
    PostCastExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PostCastExpressionRule>(this, &PostCastExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PostCastExpressionRule>(this, &PostCastExpressionRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PostCastExpressionRule>(this, &PostCastExpressionRule::A2Action));
        soulng::parsing::ActionParser* a3ActionParser = GetAction(ToUtf32("A3"));
        a3ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PostCastExpressionRule>(this, &PostCastExpressionRule::A3Action));
        soulng::parsing::ActionParser* a4ActionParser = GetAction(ToUtf32("A4"));
        a4ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PostCastExpressionRule>(this, &PostCastExpressionRule::A4Action));
        soulng::parsing::NonterminalParser* dctNonterminalParser = GetNonterminal(ToUtf32("dct"));
        dctNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PostCastExpressionRule>(this, &PostCastExpressionRule::Postdct));
        soulng::parsing::NonterminalParser* dceNonterminalParser = GetNonterminal(ToUtf32("dce"));
        dceNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PostCastExpressionRule>(this, &PostCastExpressionRule::Postdce));
        soulng::parsing::NonterminalParser* sctNonterminalParser = GetNonterminal(ToUtf32("sct"));
        sctNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PostCastExpressionRule>(this, &PostCastExpressionRule::Postsct));
        soulng::parsing::NonterminalParser* sceNonterminalParser = GetNonterminal(ToUtf32("sce"));
        sceNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PostCastExpressionRule>(this, &PostCastExpressionRule::Postsce));
        soulng::parsing::NonterminalParser* rctNonterminalParser = GetNonterminal(ToUtf32("rct"));
        rctNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PostCastExpressionRule>(this, &PostCastExpressionRule::Postrct));
        soulng::parsing::NonterminalParser* rceNonterminalParser = GetNonterminal(ToUtf32("rce"));
        rceNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PostCastExpressionRule>(this, &PostCastExpressionRule::Postrce));
        soulng::parsing::NonterminalParser* cctNonterminalParser = GetNonterminal(ToUtf32("cct"));
        cctNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PostCastExpressionRule>(this, &PostCastExpressionRule::Postcct));
        soulng::parsing::NonterminalParser* cceNonterminalParser = GetNonterminal(ToUtf32("cce"));
        cceNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PostCastExpressionRule>(this, &PostCastExpressionRule::Postcce));
        soulng::parsing::NonterminalParser* typeidExprNonterminalParser = GetNonterminal(ToUtf32("typeidExpr"));
        typeidExprNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PostCastExpressionRule>(this, &PostCastExpressionRule::PosttypeidExpr));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new PostCastExpr(U"dynamic_cast", context->fromdct, context->fromdce);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new PostCastExpr(U"static_cast", context->fromsct, context->fromsce);
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new PostCastExpr(U"reinterpret_cast", context->fromrct, context->fromrce);
    }
    void A3Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new PostCastExpr(U"const_cast", context->fromcct, context->fromcce);
    }
    void A4Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new TypeIdExpr(context->fromtypeidExpr);
    }
    void Postdct(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromdct_value = std::move(stack.top());
            context->fromdct = *static_cast<soulng::parsing::ValueObject<soulng::codedom::TypeId*>*>(fromdct_value.get());
            stack.pop();
        }
    }
    void Postdce(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromdce_value = std::move(stack.top());
            context->fromdce = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromdce_value.get());
            stack.pop();
        }
    }
    void Postsct(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromsct_value = std::move(stack.top());
            context->fromsct = *static_cast<soulng::parsing::ValueObject<soulng::codedom::TypeId*>*>(fromsct_value.get());
            stack.pop();
        }
    }
    void Postsce(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromsce_value = std::move(stack.top());
            context->fromsce = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromsce_value.get());
            stack.pop();
        }
    }
    void Postrct(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromrct_value = std::move(stack.top());
            context->fromrct = *static_cast<soulng::parsing::ValueObject<soulng::codedom::TypeId*>*>(fromrct_value.get());
            stack.pop();
        }
    }
    void Postrce(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromrce_value = std::move(stack.top());
            context->fromrce = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromrce_value.get());
            stack.pop();
        }
    }
    void Postcct(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromcct_value = std::move(stack.top());
            context->fromcct = *static_cast<soulng::parsing::ValueObject<soulng::codedom::TypeId*>*>(fromcct_value.get());
            stack.pop();
        }
    }
    void Postcce(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromcce_value = std::move(stack.top());
            context->fromcce = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromcce_value.get());
            stack.pop();
        }
    }
    void PosttypeidExpr(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromtypeidExpr_value = std::move(stack.top());
            context->fromtypeidExpr = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromtypeidExpr_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromdct(), fromdce(), fromsct(), fromsce(), fromrct(), fromrce(), fromcct(), fromcce(), fromtypeidExpr() {}
        soulng::codedom::CppObject* value;
        soulng::codedom::TypeId* fromdct;
        soulng::codedom::CppObject* fromdce;
        soulng::codedom::TypeId* fromsct;
        soulng::codedom::CppObject* fromsce;
        soulng::codedom::TypeId* fromrct;
        soulng::codedom::CppObject* fromrce;
        soulng::codedom::TypeId* fromcct;
        soulng::codedom::CppObject* fromcce;
        soulng::codedom::CppObject* fromtypeidExpr;
    };
};

class Expression::ExpressionListRule : public soulng::parsing::Rule
{
public:
    ExpressionListRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("std::vector<soulng::codedom::CppObject*>"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<std::vector<soulng::codedom::CppObject*>>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ExpressionListRule>(this, &ExpressionListRule::A0Action));
        soulng::parsing::NonterminalParser* assignmentExpressionNonterminalParser = GetNonterminal(ToUtf32("AssignmentExpression"));
        assignmentExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ExpressionListRule>(this, &ExpressionListRule::PostAssignmentExpression));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value.push_back(context->fromAssignmentExpression);
    }
    void PostAssignmentExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromAssignmentExpression_value = std::move(stack.top());
            context->fromAssignmentExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromAssignmentExpression_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromAssignmentExpression() {}
        std::vector<soulng::codedom::CppObject*> value;
        soulng::codedom::CppObject* fromAssignmentExpression;
    };
};

class Expression::PrimaryExpressionRule : public soulng::parsing::Rule
{
public:
    PrimaryExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::CppObject*"));
        AddLocalVariable(AttrOrVariable(ToUtf32("std::unique_ptr<CppObject>"), ToUtf32("pe")));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::CppObject*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimaryExpressionRule>(this, &PrimaryExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimaryExpressionRule>(this, &PrimaryExpressionRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimaryExpressionRule>(this, &PrimaryExpressionRule::A2Action));
        soulng::parsing::ActionParser* a3ActionParser = GetAction(ToUtf32("A3"));
        a3ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimaryExpressionRule>(this, &PrimaryExpressionRule::A3Action));
        soulng::parsing::ActionParser* a4ActionParser = GetAction(ToUtf32("A4"));
        a4ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimaryExpressionRule>(this, &PrimaryExpressionRule::A4Action));
        soulng::parsing::NonterminalParser* literalNonterminalParser = GetNonterminal(ToUtf32("Literal"));
        literalNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimaryExpressionRule>(this, &PrimaryExpressionRule::PostLiteral));
        soulng::parsing::NonterminalParser* expressionNonterminalParser = GetNonterminal(ToUtf32("Expression"));
        expressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimaryExpressionRule>(this, &PrimaryExpressionRule::PostExpression));
        soulng::parsing::NonterminalParser* idExpressionNonterminalParser = GetNonterminal(ToUtf32("IdExpression"));
        idExpressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimaryExpressionRule>(this, &PrimaryExpressionRule::PostIdExpression));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->pe.release();
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->pe.reset(context->fromLiteral);
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->pe.reset(new ThisAccess);
    }
    void A3Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->pe.reset(context->fromExpression);
    }
    void A4Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->pe.reset(context->fromIdExpression);
    }
    void PostLiteral(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromLiteral_value = std::move(stack.top());
            context->fromLiteral = *static_cast<soulng::parsing::ValueObject<soulng::codedom::Literal*>*>(fromLiteral_value.get());
            stack.pop();
        }
    }
    void PostExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromExpression_value = std::move(stack.top());
            context->fromExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CppObject*>*>(fromExpression_value.get());
            stack.pop();
        }
    }
    void PostIdExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromIdExpression_value = std::move(stack.top());
            context->fromIdExpression = *static_cast<soulng::parsing::ValueObject<soulng::codedom::IdExpr*>*>(fromIdExpression_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), pe(), fromLiteral(), fromExpression(), fromIdExpression() {}
        soulng::codedom::CppObject* value;
        std::unique_ptr<CppObject> pe;
        soulng::codedom::Literal* fromLiteral;
        soulng::codedom::CppObject* fromExpression;
        soulng::codedom::IdExpr* fromIdExpression;
    };
};

class Expression::IdExpressionRule : public soulng::parsing::Rule
{
public:
    IdExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::codedom::IdExpr*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::codedom::IdExpr*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<IdExpressionRule>(this, &IdExpressionRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<IdExpressionRule>(this, &IdExpressionRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<IdExpressionRule>(this, &IdExpressionRule::A2Action));
        soulng::parsing::NonterminalParser* id1NonterminalParser = GetNonterminal(ToUtf32("id1"));
        id1NonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<IdExpressionRule>(this, &IdExpressionRule::Postid1));
        soulng::parsing::NonterminalParser* id2NonterminalParser = GetNonterminal(ToUtf32("id2"));
        id2NonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<IdExpressionRule>(this, &IdExpressionRule::Postid2));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new IdExpr(std::u32string(matchBegin, matchEnd));
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new IdExpr(std::u32string(matchBegin, matchEnd));
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new IdExpr(std::u32string(matchBegin, matchEnd));
    }
    void Postid1(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromid1_value = std::move(stack.top());
            context->fromid1 = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromid1_value.get());
            stack.pop();
        }
    }
    void Postid2(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromid2_value = std::move(stack.top());
            context->fromid2 = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromid2_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromid1(), fromid2() {}
        soulng::codedom::IdExpr* value;
        std::u32string fromid1;
        std::u32string fromid2;
    };
};

void Expression::GetReferencedGrammars()
{
    soulng::parsing::ParsingDomain* pd = GetParsingDomain();
    soulng::parsing::Grammar* grammar0 = pd->GetGrammar(ToUtf32("soulng.code.Literal"));
    if (!grammar0)
    {
        grammar0 = soulng::code::Literal::Create(pd);
    }
    AddGrammarReference(grammar0);
    soulng::parsing::Grammar* grammar1 = pd->GetGrammar(ToUtf32("soulng.code.Identifier"));
    if (!grammar1)
    {
        grammar1 = soulng::code::Identifier::Create(pd);
    }
    AddGrammarReference(grammar1);
    soulng::parsing::Grammar* grammar2 = pd->GetGrammar(ToUtf32("soulng.code.Declarator"));
    if (!grammar2)
    {
        grammar2 = soulng::code::Declarator::Create(pd);
    }
    AddGrammarReference(grammar2);
    soulng::parsing::Grammar* grammar3 = pd->GetGrammar(ToUtf32("soulng.code.Declaration"));
    if (!grammar3)
    {
        grammar3 = soulng::code::Declaration::Create(pd);
    }
    AddGrammarReference(grammar3);
}

void Expression::CreateRules()
{
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("Literal"), this, ToUtf32("Literal.Literal")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("QualifiedId"), this, ToUtf32("Identifier.QualifiedId")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("TypeId"), this, ToUtf32("Declarator.TypeId")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("TypeName"), this, ToUtf32("Declaration.TypeName")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("TypeSpecifierSeq"), this, ToUtf32("Declarator.TypeSpecifierSeq")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("PtrOperator"), this, ToUtf32("Declarator.PtrOperator")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("SimpleTypeSpecifier"), this, ToUtf32("Declaration.SimpleTypeSpecifier")));
    AddRule(new ExpressionRule(ToUtf32("Expression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("AssignmentExpression"), 0)),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::CharParser(','),
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::NonterminalParser(ToUtf32("right"), ToUtf32("AssignmentExpression"), 0))))))));
    AddRule(new ConstantExpressionRule(ToUtf32("ConstantExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::NonterminalParser(ToUtf32("Expression"), ToUtf32("Expression"), 0))));
    AddRule(new AssignmentExpressionRule(ToUtf32("AssignmentExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::ActionParser(ToUtf32("A0"),
                    new soulng::parsing::GroupingParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::ActionParser(ToUtf32("A1"),
                                    new soulng::parsing::NonterminalParser(ToUtf32("LogicalOrExpression"), ToUtf32("LogicalOrExpression"), 0)),
                                new soulng::parsing::NonterminalParser(ToUtf32("AssingmentOp"), ToUtf32("AssingmentOp"), 0)),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("AssignmentExpression"), ToUtf32("AssignmentExpression"), 0))))),
                new soulng::parsing::ActionParser(ToUtf32("A2"),
                    new soulng::parsing::NonterminalParser(ToUtf32("ConditionalExpression"), ToUtf32("ConditionalExpression"), 0))),
            new soulng::parsing::ActionParser(ToUtf32("A3"),
                new soulng::parsing::NonterminalParser(ToUtf32("ThrowExpression"), ToUtf32("ThrowExpression"), 0)))));
    AddRule(new AssingmentOpRule(ToUtf32("AssingmentOp"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
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
                                                        new soulng::parsing::CharParser('='),
                                                        new soulng::parsing::StringParser(ToUtf32("*="))),
                                                    new soulng::parsing::StringParser(ToUtf32("/="))),
                                                new soulng::parsing::StringParser(ToUtf32("%="))),
                                            new soulng::parsing::StringParser(ToUtf32("+="))),
                                        new soulng::parsing::StringParser(ToUtf32("-="))),
                                    new soulng::parsing::StringParser(ToUtf32(">>="))),
                                new soulng::parsing::StringParser(ToUtf32("<<="))),
                            new soulng::parsing::StringParser(ToUtf32("&="))),
                        new soulng::parsing::StringParser(ToUtf32("^="))),
                    new soulng::parsing::StringParser(ToUtf32("|=")))))));
    AddRule(new ThrowExpressionRule(ToUtf32("ThrowExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::KeywordParser(ToUtf32("throw")),
                    new soulng::parsing::OptionalParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("AssignmentExpression"), ToUtf32("AssignmentExpression"), 0)))))));
    AddRule(new ConditionalExpressionRule(ToUtf32("ConditionalExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("LogicalOrExpression"), 0)),
            new soulng::parsing::OptionalParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::ActionParser(ToUtf32("A1"),
                        new soulng::parsing::GroupingParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::SequenceParser(
                                    new soulng::parsing::SequenceParser(
                                        new soulng::parsing::CharParser('?'),
                                        new soulng::parsing::ExpectationParser(
                                            new soulng::parsing::NonterminalParser(ToUtf32("Expression"), ToUtf32("Expression"), 0))),
                                    new soulng::parsing::CharParser(':')),
                                new soulng::parsing::ExpectationParser(
                                    new soulng::parsing::NonterminalParser(ToUtf32("AssignmentExpression"), ToUtf32("AssignmentExpression"), 0))))))))));
    AddRule(new LogicalOrExpressionRule(ToUtf32("LogicalOrExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("LogicalAndExpression"), 0)),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::StringParser(ToUtf32("||")),
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("right"), ToUtf32("LogicalAndExpression"), 0)))))))));
    AddRule(new LogicalAndExpressionRule(ToUtf32("LogicalAndExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("InclusiveOrExpression"), 0)),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::StringParser(ToUtf32("&&")),
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("right"), ToUtf32("InclusiveOrExpression"), 0)))))))));
    AddRule(new InclusiveOrExpressionRule(ToUtf32("InclusiveOrExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("ExclusiveOrExpression"), 0)),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::GroupingParser(
                            new soulng::parsing::DifferenceParser(
                                new soulng::parsing::CharParser('|'),
                                new soulng::parsing::StringParser(ToUtf32("||")))),
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("right"), ToUtf32("ExclusiveOrExpression"), 0)))))))));
    AddRule(new ExclusiveOrExpressionRule(ToUtf32("ExclusiveOrExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("AndExpression"), 0)),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::CharParser('^'),
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("right"), ToUtf32("AndExpression"), 0)))))))));
    AddRule(new AndExpressionRule(ToUtf32("AndExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("EqualityExpression"), 0)),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::GroupingParser(
                            new soulng::parsing::DifferenceParser(
                                new soulng::parsing::CharParser('&'),
                                new soulng::parsing::StringParser(ToUtf32("&&")))),
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("right"), ToUtf32("EqualityExpression"), 0)))))))));
    AddRule(new EqualityExpressionRule(ToUtf32("EqualityExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("RelationalExpression"), 0)),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("EqOp"), ToUtf32("EqOp"), 0),
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("right"), ToUtf32("RelationalExpression"), 0)))))))));
    AddRule(new EqOpRule(ToUtf32("EqOp"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::StringParser(ToUtf32("=="))),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::StringParser(ToUtf32("!="))))));
    AddRule(new RelationalExpressionRule(ToUtf32("RelationalExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("ShiftExpression"), 0)),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("RelOp"), ToUtf32("RelOp"), 0),
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("right"), ToUtf32("ShiftExpression"), 0)))))))));
    AddRule(new RelOpRule(ToUtf32("RelOp"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::ActionParser(ToUtf32("A0"),
                        new soulng::parsing::StringParser(ToUtf32("<="))),
                    new soulng::parsing::ActionParser(ToUtf32("A1"),
                        new soulng::parsing::StringParser(ToUtf32(">=")))),
                new soulng::parsing::ActionParser(ToUtf32("A2"),
                    new soulng::parsing::GroupingParser(
                        new soulng::parsing::DifferenceParser(
                            new soulng::parsing::CharParser('<'),
                            new soulng::parsing::StringParser(ToUtf32("<<")))))),
            new soulng::parsing::ActionParser(ToUtf32("A3"),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::DifferenceParser(
                        new soulng::parsing::CharParser('>'),
                        new soulng::parsing::StringParser(ToUtf32(">>"))))))));
    AddRule(new ShiftExpressionRule(ToUtf32("ShiftExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("AdditiveExpression"), 0)),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("ShiftOp"), ToUtf32("ShiftOp"), 0),
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("right"), ToUtf32("AdditiveExpression"), 0)))))))));
    AddRule(new ShiftOpRule(ToUtf32("ShiftOp"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::DifferenceParser(
                        new soulng::parsing::StringParser(ToUtf32("<<")),
                        new soulng::parsing::StringParser(ToUtf32("<<="))))),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::DifferenceParser(
                        new soulng::parsing::StringParser(ToUtf32(">>")),
                        new soulng::parsing::StringParser(ToUtf32(">>="))))))));
    AddRule(new AdditiveExpressionRule(ToUtf32("AdditiveExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("MultiplicativeExpression"), 0)),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("AddOp"), ToUtf32("AddOp"), 0),
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("right"), ToUtf32("MultiplicativeExpression"), 0)))))))));
    AddRule(new AddOpRule(ToUtf32("AddOp"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::DifferenceParser(
                        new soulng::parsing::CharParser('+'),
                        new soulng::parsing::StringParser(ToUtf32("+="))))),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::DifferenceParser(
                        new soulng::parsing::CharParser('-'),
                        new soulng::parsing::GroupingParser(
                            new soulng::parsing::AlternativeParser(
                                new soulng::parsing::StringParser(ToUtf32("-=")),
                                new soulng::parsing::StringParser(ToUtf32("->"))))))))));
    AddRule(new MultiplicativeExpressionRule(ToUtf32("MultiplicativeExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("PmExpression"), 0)),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("MulOp"), ToUtf32("MulOp"), 0),
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("right"), ToUtf32("PmExpression"), 0)))))))));
    AddRule(new MulOpRule(ToUtf32("MulOp"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::ActionParser(ToUtf32("A0"),
                    new soulng::parsing::GroupingParser(
                        new soulng::parsing::DifferenceParser(
                            new soulng::parsing::CharParser('*'),
                            new soulng::parsing::StringParser(ToUtf32("*="))))),
                new soulng::parsing::ActionParser(ToUtf32("A1"),
                    new soulng::parsing::GroupingParser(
                        new soulng::parsing::DifferenceParser(
                            new soulng::parsing::CharParser('/'),
                            new soulng::parsing::StringParser(ToUtf32("/=")))))),
            new soulng::parsing::ActionParser(ToUtf32("A2"),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::DifferenceParser(
                        new soulng::parsing::CharParser('%'),
                        new soulng::parsing::StringParser(ToUtf32("%="))))))));
    AddRule(new PmExpressionRule(ToUtf32("PmExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("left"), ToUtf32("CastExpression"), 0)),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("PmOp"), ToUtf32("PmOp"), 0),
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("right"), ToUtf32("CastExpression"), 0)))))))));
    AddRule(new PmOpRule(ToUtf32("PmOp"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::StringParser(ToUtf32(".*"))),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::StringParser(ToUtf32("->*"))))));
    AddRule(new CastExpressionRule(ToUtf32("CastExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::ActionParser(ToUtf32("A1"),
                        new soulng::parsing::GroupingParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::SequenceParser(
                                    new soulng::parsing::SequenceParser(
                                        new soulng::parsing::CharParser('('),
                                        new soulng::parsing::ActionParser(ToUtf32("A2"),
                                            new soulng::parsing::NonterminalParser(ToUtf32("TypeId"), ToUtf32("TypeId"), 0))),
                                    new soulng::parsing::CharParser(')')),
                                new soulng::parsing::NonterminalParser(ToUtf32("CastExpression"), ToUtf32("CastExpression"), 0)))),
                    new soulng::parsing::ActionParser(ToUtf32("A3"),
                        new soulng::parsing::NonterminalParser(ToUtf32("UnaryExpression"), ToUtf32("UnaryExpression"), 0)))))));
    AddRule(new UnaryExpressionRule(ToUtf32("UnaryExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::AlternativeParser(
                        new soulng::parsing::AlternativeParser(
                            new soulng::parsing::AlternativeParser(
                                new soulng::parsing::AlternativeParser(
                                    new soulng::parsing::AlternativeParser(
                                        new soulng::parsing::AlternativeParser(
                                            new soulng::parsing::GroupingParser(
                                                new soulng::parsing::AlternativeParser(
                                                    new soulng::parsing::ActionParser(ToUtf32("A1"),
                                                        new soulng::parsing::NonterminalParser(ToUtf32("PostfixExpression"), ToUtf32("PostfixExpression"), 0)),
                                                    new soulng::parsing::ActionParser(ToUtf32("A2"),
                                                        new soulng::parsing::NonterminalParser(ToUtf32("PostCastExpression"), ToUtf32("PostCastExpression"), 0)))),
                                            new soulng::parsing::ActionParser(ToUtf32("A3"),
                                                new soulng::parsing::GroupingParser(
                                                    new soulng::parsing::SequenceParser(
                                                        new soulng::parsing::StringParser(ToUtf32("++")),
                                                        new soulng::parsing::ExpectationParser(
                                                            new soulng::parsing::NonterminalParser(ToUtf32("e1"), ToUtf32("UnaryExpression"), 0)))))),
                                        new soulng::parsing::ActionParser(ToUtf32("A4"),
                                            new soulng::parsing::GroupingParser(
                                                new soulng::parsing::SequenceParser(
                                                    new soulng::parsing::StringParser(ToUtf32("--")),
                                                    new soulng::parsing::ExpectationParser(
                                                        new soulng::parsing::NonterminalParser(ToUtf32("e2"), ToUtf32("UnaryExpression"), 0)))))),
                                    new soulng::parsing::ActionParser(ToUtf32("A5"),
                                        new soulng::parsing::GroupingParser(
                                            new soulng::parsing::SequenceParser(
                                                new soulng::parsing::NonterminalParser(ToUtf32("UnaryOperator"), ToUtf32("UnaryOperator"), 0),
                                                new soulng::parsing::ExpectationParser(
                                                    new soulng::parsing::NonterminalParser(ToUtf32("CastExpression"), ToUtf32("CastExpression"), 0)))))),
                                new soulng::parsing::ActionParser(ToUtf32("A6"),
                                    new soulng::parsing::GroupingParser(
                                        new soulng::parsing::SequenceParser(
                                            new soulng::parsing::SequenceParser(
                                                new soulng::parsing::SequenceParser(
                                                    new soulng::parsing::KeywordParser(ToUtf32("sizeof")),
                                                    new soulng::parsing::CharParser('(')),
                                                new soulng::parsing::ExpectationParser(
                                                    new soulng::parsing::NonterminalParser(ToUtf32("TypeId"), ToUtf32("TypeId"), 0))),
                                            new soulng::parsing::ExpectationParser(
                                                new soulng::parsing::CharParser(')')))))),
                            new soulng::parsing::ActionParser(ToUtf32("A7"),
                                new soulng::parsing::GroupingParser(
                                    new soulng::parsing::SequenceParser(
                                        new soulng::parsing::KeywordParser(ToUtf32("sizeof")),
                                        new soulng::parsing::ExpectationParser(
                                            new soulng::parsing::NonterminalParser(ToUtf32("e3"), ToUtf32("UnaryExpression"), 0)))))),
                        new soulng::parsing::ActionParser(ToUtf32("A8"),
                            new soulng::parsing::NonterminalParser(ToUtf32("NewExpression"), ToUtf32("NewExpression"), 0))),
                    new soulng::parsing::ActionParser(ToUtf32("A9"),
                        new soulng::parsing::NonterminalParser(ToUtf32("DeleteExpression"), ToUtf32("DeleteExpression"), 0)))))));
    AddRule(new UnaryOperatorRule(ToUtf32("UnaryOperator"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::AlternativeParser(
                        new soulng::parsing::AlternativeParser(
                            new soulng::parsing::ActionParser(ToUtf32("A0"),
                                new soulng::parsing::GroupingParser(
                                    new soulng::parsing::DifferenceParser(
                                        new soulng::parsing::CharParser('*'),
                                        new soulng::parsing::StringParser(ToUtf32("*="))))),
                            new soulng::parsing::ActionParser(ToUtf32("A1"),
                                new soulng::parsing::GroupingParser(
                                    new soulng::parsing::DifferenceParser(
                                        new soulng::parsing::CharParser('&'),
                                        new soulng::parsing::StringParser(ToUtf32("&=")))))),
                        new soulng::parsing::ActionParser(ToUtf32("A2"),
                            new soulng::parsing::GroupingParser(
                                new soulng::parsing::DifferenceParser(
                                    new soulng::parsing::CharParser('+'),
                                    new soulng::parsing::StringParser(ToUtf32("+=")))))),
                    new soulng::parsing::ActionParser(ToUtf32("A3"),
                        new soulng::parsing::GroupingParser(
                            new soulng::parsing::DifferenceParser(
                                new soulng::parsing::CharParser('-'),
                                new soulng::parsing::StringParser(ToUtf32("-=")))))),
                new soulng::parsing::ActionParser(ToUtf32("A4"),
                    new soulng::parsing::GroupingParser(
                        new soulng::parsing::DifferenceParser(
                            new soulng::parsing::CharParser('!'),
                            new soulng::parsing::StringParser(ToUtf32("!=")))))),
            new soulng::parsing::ActionParser(ToUtf32("A5"),
                new soulng::parsing::CharParser('~')))));
    AddRule(new NewExpressionRule(ToUtf32("NewExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::OptionalParser(
                                    new soulng::parsing::GroupingParser(
                                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                                            new soulng::parsing::StringParser(ToUtf32("::"))))),
                                new soulng::parsing::KeywordParser(ToUtf32("new"))),
                            new soulng::parsing::OptionalParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("NewPlacement"), ToUtf32("NewPlacement"), 0))),
                        new soulng::parsing::GroupingParser(
                            new soulng::parsing::AlternativeParser(
                                new soulng::parsing::ActionParser(ToUtf32("A2"),
                                    new soulng::parsing::NonterminalParser(ToUtf32("NewTypeId"), ToUtf32("NewTypeId"), 0)),
                                new soulng::parsing::SequenceParser(
                                    new soulng::parsing::SequenceParser(
                                        new soulng::parsing::CharParser('('),
                                        new soulng::parsing::ActionParser(ToUtf32("A3"),
                                            new soulng::parsing::NonterminalParser(ToUtf32("TypeId"), ToUtf32("TypeId"), 0))),
                                    new soulng::parsing::CharParser(')'))))),
                    new soulng::parsing::OptionalParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("NewInitializer"), ToUtf32("NewInitializer"), 0)))))));
    AddRule(new NewTypeIdRule(ToUtf32("NewTypeId"), GetScope(), GetParsingDomain()->GetNextRuleId(),
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
                                    new soulng::parsing::NonterminalParser(ToUtf32("NewDeclarator"), ToUtf32("NewDeclarator"), 0))))))))));
    AddRule(new NewDeclaratorRule(ToUtf32("NewDeclarator"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("PtrOperator"), ToUtf32("PtrOperator"), 0),
                        new soulng::parsing::OptionalParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("NewDeclarator"), ToUtf32("NewDeclarator"), 0))),
                    new soulng::parsing::NonterminalParser(ToUtf32("DirectNewDeclarator"), ToUtf32("DirectNewDeclarator"), 0))))));
    AddRule(new DirectNewDeclaratorRule(ToUtf32("DirectNewDeclarator"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::CharParser('['),
                    new soulng::parsing::ActionParser(ToUtf32("A0"),
                        new soulng::parsing::NonterminalParser(ToUtf32("Expression"), ToUtf32("Expression"), 0))),
                new soulng::parsing::CharParser(']')),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::CharParser('['),
                            new soulng::parsing::ActionParser(ToUtf32("A1"),
                                new soulng::parsing::NonterminalParser(ToUtf32("ConstantExpression"), ToUtf32("ConstantExpression"), 0))),
                        new soulng::parsing::CharParser(']')))))));
    AddRule(new NewPlacementRule(ToUtf32("NewPlacement"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::CharParser('('),
                        new soulng::parsing::NonterminalParser(ToUtf32("ExpressionList"), ToUtf32("ExpressionList"), 0)),
                    new soulng::parsing::CharParser(')'))))));
    AddRule(new NewInitializerRule(ToUtf32("NewInitializer"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::CharParser('('),
                        new soulng::parsing::OptionalParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("ExpressionList"), ToUtf32("ExpressionList"), 0))),
                    new soulng::parsing::CharParser(')'))))));
    AddRule(new DeleteExpressionRule(ToUtf32("DeleteExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::OptionalParser(
                                new soulng::parsing::GroupingParser(
                                    new soulng::parsing::ActionParser(ToUtf32("A1"),
                                        new soulng::parsing::StringParser(ToUtf32("::"))))),
                            new soulng::parsing::KeywordParser(ToUtf32("delete"))),
                        new soulng::parsing::OptionalParser(
                            new soulng::parsing::GroupingParser(
                                new soulng::parsing::SequenceParser(
                                    new soulng::parsing::CharParser('['),
                                    new soulng::parsing::ActionParser(ToUtf32("A2"),
                                        new soulng::parsing::CharParser(']')))))),
                    new soulng::parsing::NonterminalParser(ToUtf32("CastExpression"), ToUtf32("CastExpression"), 0))))));
    AddRule(new PostfixExpressionRule(ToUtf32("PostfixExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::NonterminalParser(ToUtf32("PrimaryExpression"), ToUtf32("PrimaryExpression"), 0)),
                        new soulng::parsing::KleeneStarParser(
                            new soulng::parsing::GroupingParser(
                                new soulng::parsing::AlternativeParser(
                                    new soulng::parsing::AlternativeParser(
                                        new soulng::parsing::AlternativeParser(
                                            new soulng::parsing::AlternativeParser(
                                                new soulng::parsing::AlternativeParser(
                                                    new soulng::parsing::ActionParser(ToUtf32("A2"),
                                                        new soulng::parsing::GroupingParser(
                                                            new soulng::parsing::SequenceParser(
                                                                new soulng::parsing::SequenceParser(
                                                                    new soulng::parsing::CharParser('['),
                                                                    new soulng::parsing::ExpectationParser(
                                                                        new soulng::parsing::NonterminalParser(ToUtf32("index"), ToUtf32("Expression"), 0))),
                                                                new soulng::parsing::ExpectationParser(
                                                                    new soulng::parsing::CharParser(']'))))),
                                                    new soulng::parsing::ActionParser(ToUtf32("A3"),
                                                        new soulng::parsing::GroupingParser(
                                                            new soulng::parsing::SequenceParser(
                                                                new soulng::parsing::SequenceParser(
                                                                    new soulng::parsing::CharParser('('),
                                                                    new soulng::parsing::OptionalParser(
                                                                        new soulng::parsing::GroupingParser(
                                                                            new soulng::parsing::NonterminalParser(ToUtf32("invoke"), ToUtf32("ExpressionList"), 0)))),
                                                                new soulng::parsing::ExpectationParser(
                                                                    new soulng::parsing::CharParser(')')))))),
                                                new soulng::parsing::ActionParser(ToUtf32("A4"),
                                                    new soulng::parsing::GroupingParser(
                                                        new soulng::parsing::SequenceParser(
                                                            new soulng::parsing::GroupingParser(
                                                                new soulng::parsing::DifferenceParser(
                                                                    new soulng::parsing::CharParser('.'),
                                                                    new soulng::parsing::StringParser(ToUtf32(".*")))),
                                                            new soulng::parsing::ExpectationParser(
                                                                new soulng::parsing::NonterminalParser(ToUtf32("member"), ToUtf32("IdExpression"), 0)))))),
                                            new soulng::parsing::ActionParser(ToUtf32("A5"),
                                                new soulng::parsing::GroupingParser(
                                                    new soulng::parsing::SequenceParser(
                                                        new soulng::parsing::GroupingParser(
                                                            new soulng::parsing::DifferenceParser(
                                                                new soulng::parsing::StringParser(ToUtf32("->")),
                                                                new soulng::parsing::StringParser(ToUtf32("->*")))),
                                                        new soulng::parsing::ExpectationParser(
                                                            new soulng::parsing::NonterminalParser(ToUtf32("ptrmember"), ToUtf32("IdExpression"), 0)))))),
                                        new soulng::parsing::ActionParser(ToUtf32("A6"),
                                            new soulng::parsing::StringParser(ToUtf32("++")))),
                                    new soulng::parsing::ActionParser(ToUtf32("A7"),
                                        new soulng::parsing::StringParser(ToUtf32("--"))))))),
                    new soulng::parsing::ActionParser(ToUtf32("A8"),
                        new soulng::parsing::GroupingParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::SequenceParser(
                                    new soulng::parsing::SequenceParser(
                                        new soulng::parsing::NonterminalParser(ToUtf32("TypeSpecifierOrTypeName"), ToUtf32("TypeSpecifierOrTypeName"), 0),
                                        new soulng::parsing::CharParser('(')),
                                    new soulng::parsing::OptionalParser(
                                        new soulng::parsing::NonterminalParser(ToUtf32("typeConstruction"), ToUtf32("ExpressionList"), 0))),
                                new soulng::parsing::CharParser(')')))))))));
    AddRule(new TypeSpecifierOrTypeNameRule(ToUtf32("TypeSpecifierOrTypeName"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("SimpleTypeSpecifier"), ToUtf32("SimpleTypeSpecifier"), 0)),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::NonterminalParser(ToUtf32("TypeName"), ToUtf32("TypeName"), 0)))));
    AddRule(new PostCastExpressionRule(ToUtf32("PostCastExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::AlternativeParser(
                        new soulng::parsing::ActionParser(ToUtf32("A0"),
                            new soulng::parsing::GroupingParser(
                                new soulng::parsing::SequenceParser(
                                    new soulng::parsing::SequenceParser(
                                        new soulng::parsing::SequenceParser(
                                            new soulng::parsing::SequenceParser(
                                                new soulng::parsing::SequenceParser(
                                                    new soulng::parsing::SequenceParser(
                                                        new soulng::parsing::KeywordParser(ToUtf32("dynamic_cast")),
                                                        new soulng::parsing::ExpectationParser(
                                                            new soulng::parsing::CharParser('<'))),
                                                    new soulng::parsing::ExpectationParser(
                                                        new soulng::parsing::NonterminalParser(ToUtf32("dct"), ToUtf32("TypeId"), 0))),
                                                new soulng::parsing::ExpectationParser(
                                                    new soulng::parsing::CharParser('>'))),
                                            new soulng::parsing::ExpectationParser(
                                                new soulng::parsing::CharParser('('))),
                                        new soulng::parsing::ExpectationParser(
                                            new soulng::parsing::NonterminalParser(ToUtf32("dce"), ToUtf32("Expression"), 0))),
                                    new soulng::parsing::ExpectationParser(
                                        new soulng::parsing::CharParser(')'))))),
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::GroupingParser(
                                new soulng::parsing::SequenceParser(
                                    new soulng::parsing::SequenceParser(
                                        new soulng::parsing::SequenceParser(
                                            new soulng::parsing::SequenceParser(
                                                new soulng::parsing::SequenceParser(
                                                    new soulng::parsing::SequenceParser(
                                                        new soulng::parsing::KeywordParser(ToUtf32("static_cast")),
                                                        new soulng::parsing::ExpectationParser(
                                                            new soulng::parsing::CharParser('<'))),
                                                    new soulng::parsing::ExpectationParser(
                                                        new soulng::parsing::NonterminalParser(ToUtf32("sct"), ToUtf32("TypeId"), 0))),
                                                new soulng::parsing::ExpectationParser(
                                                    new soulng::parsing::CharParser('>'))),
                                            new soulng::parsing::ExpectationParser(
                                                new soulng::parsing::CharParser('('))),
                                        new soulng::parsing::ExpectationParser(
                                            new soulng::parsing::NonterminalParser(ToUtf32("sce"), ToUtf32("Expression"), 0))),
                                    new soulng::parsing::ExpectationParser(
                                        new soulng::parsing::CharParser(')')))))),
                    new soulng::parsing::ActionParser(ToUtf32("A2"),
                        new soulng::parsing::GroupingParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::SequenceParser(
                                    new soulng::parsing::SequenceParser(
                                        new soulng::parsing::SequenceParser(
                                            new soulng::parsing::SequenceParser(
                                                new soulng::parsing::SequenceParser(
                                                    new soulng::parsing::KeywordParser(ToUtf32("reinterpret_cast")),
                                                    new soulng::parsing::ExpectationParser(
                                                        new soulng::parsing::CharParser('<'))),
                                                new soulng::parsing::ExpectationParser(
                                                    new soulng::parsing::NonterminalParser(ToUtf32("rct"), ToUtf32("TypeId"), 0))),
                                            new soulng::parsing::ExpectationParser(
                                                new soulng::parsing::CharParser('>'))),
                                        new soulng::parsing::ExpectationParser(
                                            new soulng::parsing::CharParser('('))),
                                    new soulng::parsing::ExpectationParser(
                                        new soulng::parsing::NonterminalParser(ToUtf32("rce"), ToUtf32("Expression"), 0))),
                                new soulng::parsing::ExpectationParser(
                                    new soulng::parsing::CharParser(')')))))),
                new soulng::parsing::ActionParser(ToUtf32("A3"),
                    new soulng::parsing::GroupingParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::SequenceParser(
                                    new soulng::parsing::SequenceParser(
                                        new soulng::parsing::SequenceParser(
                                            new soulng::parsing::SequenceParser(
                                                new soulng::parsing::KeywordParser(ToUtf32("const_cast")),
                                                new soulng::parsing::ExpectationParser(
                                                    new soulng::parsing::CharParser('<'))),
                                            new soulng::parsing::ExpectationParser(
                                                new soulng::parsing::NonterminalParser(ToUtf32("cct"), ToUtf32("TypeId"), 0))),
                                        new soulng::parsing::ExpectationParser(
                                            new soulng::parsing::CharParser('>'))),
                                    new soulng::parsing::ExpectationParser(
                                        new soulng::parsing::CharParser('('))),
                                new soulng::parsing::ExpectationParser(
                                    new soulng::parsing::NonterminalParser(ToUtf32("cce"), ToUtf32("Expression"), 0))),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::CharParser(')')))))),
            new soulng::parsing::ActionParser(ToUtf32("A4"),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::KeywordParser(ToUtf32("typeid")),
                                new soulng::parsing::ExpectationParser(
                                    new soulng::parsing::CharParser('('))),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("typeidExpr"), ToUtf32("Expression"), 0))),
                        new soulng::parsing::ExpectationParser(
                            new soulng::parsing::CharParser(')'))))))));
    AddRule(new ExpressionListRule(ToUtf32("ExpressionList"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ListParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::NonterminalParser(ToUtf32("AssignmentExpression"), ToUtf32("AssignmentExpression"), 0)),
            new soulng::parsing::CharParser(','))));
    AddRule(new PrimaryExpressionRule(ToUtf32("PrimaryExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::AlternativeParser(
                        new soulng::parsing::AlternativeParser(
                            new soulng::parsing::ActionParser(ToUtf32("A1"),
                                new soulng::parsing::NonterminalParser(ToUtf32("Literal"), ToUtf32("Literal"), 0)),
                            new soulng::parsing::ActionParser(ToUtf32("A2"),
                                new soulng::parsing::KeywordParser(ToUtf32("this")))),
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::CharParser('('),
                                new soulng::parsing::NonterminalParser(ToUtf32("Expression"), ToUtf32("Expression"), 0)),
                            new soulng::parsing::ActionParser(ToUtf32("A3"),
                                new soulng::parsing::ExpectationParser(
                                    new soulng::parsing::CharParser(')'))))),
                    new soulng::parsing::ActionParser(ToUtf32("A4"),
                        new soulng::parsing::NonterminalParser(ToUtf32("IdExpression"), ToUtf32("IdExpression"), 0)))))));
    AddRule(new IdExpressionRule(ToUtf32("IdExpression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::ActionParser(ToUtf32("A0"),
                    new soulng::parsing::TokenParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("id1"), ToUtf32("QualifiedId"), 0),
                                new soulng::parsing::StringParser(ToUtf32("::"))),
                            new soulng::parsing::NonterminalParser(ToUtf32("OperatorFunctionId"), ToUtf32("OperatorFunctionId"), 0)))),
                new soulng::parsing::ActionParser(ToUtf32("A1"),
                    new soulng::parsing::TokenParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::OptionalParser(
                                new soulng::parsing::StringParser(ToUtf32("::"))),
                            new soulng::parsing::NonterminalParser(ToUtf32("OperatorFunctionId"), ToUtf32("OperatorFunctionId"), 0))))),
            new soulng::parsing::ActionParser(ToUtf32("A2"),
                new soulng::parsing::NonterminalParser(ToUtf32("id2"), ToUtf32("QualifiedId"), 0)))));
    AddRule(new soulng::parsing::Rule(ToUtf32("OperatorFunctionId"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::KeywordParser(ToUtf32("operator")),
            new soulng::parsing::NonterminalParser(ToUtf32("Operator"), ToUtf32("Operator"), 0))));
    AddRule(new soulng::parsing::Rule(ToUtf32("Operator"), GetScope(), GetParsingDomain()->GetNextRuleId(),
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
                                                                                                                                                                        new soulng::parsing::AlternativeParser(
                                                                                                                                                                            new soulng::parsing::SequenceParser(
                                                                                                                                                                                new soulng::parsing::CharParser('['),
                                                                                                                                                                                new soulng::parsing::CharParser(']')),
                                                                                                                                                                            new soulng::parsing::SequenceParser(
                                                                                                                                                                                new soulng::parsing::CharParser('('),
                                                                                                                                                                                new soulng::parsing::CharParser(')'))),
                                                                                                                                                                        new soulng::parsing::StringParser(ToUtf32("->*"))),
                                                                                                                                                                    new soulng::parsing::StringParser(ToUtf32("->"))),
                                                                                                                                                                new soulng::parsing::CharParser(',')),
                                                                                                                                                            new soulng::parsing::StringParser(ToUtf32("--"))),
                                                                                                                                                        new soulng::parsing::StringParser(ToUtf32("++"))),
                                                                                                                                                    new soulng::parsing::StringParser(ToUtf32("||"))),
                                                                                                                                                new soulng::parsing::StringParser(ToUtf32("&&"))),
                                                                                                                                            new soulng::parsing::StringParser(ToUtf32("<="))),
                                                                                                                                        new soulng::parsing::StringParser(ToUtf32(">="))),
                                                                                                                                    new soulng::parsing::StringParser(ToUtf32("!="))),
                                                                                                                                new soulng::parsing::StringParser(ToUtf32("=="))),
                                                                                                                            new soulng::parsing::StringParser(ToUtf32("<<="))),
                                                                                                                        new soulng::parsing::StringParser(ToUtf32(">>="))),
                                                                                                                    new soulng::parsing::StringParser(ToUtf32("<<"))),
                                                                                                                new soulng::parsing::StringParser(ToUtf32(">>"))),
                                                                                                            new soulng::parsing::StringParser(ToUtf32("|="))),
                                                                                                        new soulng::parsing::StringParser(ToUtf32("&="))),
                                                                                                    new soulng::parsing::StringParser(ToUtf32("^="))),
                                                                                                new soulng::parsing::StringParser(ToUtf32("%="))),
                                                                                            new soulng::parsing::StringParser(ToUtf32("/="))),
                                                                                        new soulng::parsing::StringParser(ToUtf32("*="))),
                                                                                    new soulng::parsing::StringParser(ToUtf32("-="))),
                                                                                new soulng::parsing::StringParser(ToUtf32("+="))),
                                                                            new soulng::parsing::CharParser('<')),
                                                                        new soulng::parsing::CharParser('>')),
                                                                    new soulng::parsing::CharParser('=')),
                                                                new soulng::parsing::CharParser('!')),
                                                            new soulng::parsing::CharParser('~')),
                                                        new soulng::parsing::CharParser('|')),
                                                    new soulng::parsing::CharParser('&')),
                                                new soulng::parsing::CharParser('^')),
                                            new soulng::parsing::CharParser('%')),
                                        new soulng::parsing::CharParser('/')),
                                    new soulng::parsing::CharParser('*')),
                                new soulng::parsing::CharParser('-')),
                            new soulng::parsing::CharParser('+')),
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::KeywordParser(ToUtf32("new")),
                                new soulng::parsing::CharParser('[')),
                            new soulng::parsing::CharParser(']'))),
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::KeywordParser(ToUtf32("delete")),
                            new soulng::parsing::CharParser('[')),
                        new soulng::parsing::CharParser(']'))),
                new soulng::parsing::KeywordParser(ToUtf32("new"))),
            new soulng::parsing::KeywordParser(ToUtf32("delete")))));
}

} } // namespace soulng.code
