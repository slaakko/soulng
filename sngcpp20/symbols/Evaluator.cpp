// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Evaluator.hpp>
#include <sngcpp20/ast/Expression.hpp>
#include <sngcpp20/ast/Literal.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <stack>

namespace sngcpp::symbols {

class Evaluator : public DefaultVisitor
{
public:
    Evaluator(EvaluationContext& context_);
    Value* GetValue();
    void BeginVisit(Node& node) override;
    Value* EvaluateBinaryExpression(Value* left, Value* right, NodeKind op);
    Value* EvaluateBooleanBinaryExpression(Value* left, Value* right, NodeKind op);
    Value* EvaluateIntegerBinaryExpression(Value* left, Value* right, NodeKind op);
    Value* EvaluateFloatingBinaryExpression(Value* left, Value* right, NodeKind op);
    Value* EvaluateUnaryExpression(Value* operand, NodeKind op);
    Value* EvaluateBooleanUnaryExpression(Value* operand, NodeKind op);
    Value* EvaluateIntegerUnaryExpression(Value* operand, NodeKind op);
    Value* EvaluateFloatingUnaryExpression(Value* operand, NodeKind op);
    // Literal:
    void Visit(IntegerLiteralNode& node);
    void Visit(FloatingLiteralNode& node);
    void Visit(BooleanLiteralNode& node);
    // Expression:
    void Visit(BinaryExprNode& node);
    void Visit(UnaryExprNode& node);
    void Visit(ConditionalExprNode& node);
    void Visit(CastExprNode& node);
    void Visit(CppCastExprNode& node);
    void Visit(ParenthesizedExprNode& node);
private:
    EvaluationContext& context;
    Value* value;
    std::stack<Value*> valueStack;
};

Evaluator::Evaluator(EvaluationContext& context_) : context(context_), value(nullptr)
{
}

void Evaluator::BeginVisit(Node& node)
{
    valueStack.push(nullptr);
}

Value* Evaluator::GetValue()
{
    Value* result = valueStack.top();
    valueStack.pop();
    return result;
}

Value* Evaluator::EvaluateBinaryExpression(Value* left, Value* right, NodeKind op)
{
    if (!left || !right) return nullptr;
    ValueKind kind = CommonValueKind(left->Kind(), right->Kind());
    left = left->Convert(kind, context);
    right = right->Convert(kind, context);
    switch (kind)
    {
        case ValueKind::boolValue:
        {
            return EvaluateBooleanBinaryExpression(left, right, op);
        }
        case ValueKind::integerValue:
        {
            return EvaluateIntegerBinaryExpression(left, right, op);
        }
        case ValueKind::floatingValue:
        {
            return EvaluateFloatingBinaryExpression(left, right, op);
        }
    }
    return nullptr;
}

Value* Evaluator::EvaluateBooleanBinaryExpression(Value* left, Value* right, NodeKind op)
{
    BoolValue* l = static_cast<BoolValue*>(left);
    BoolValue* r = static_cast<BoolValue*>(right);
    bool leftValue = l->GetValue();
    bool rightValue = r->GetValue();
    switch (op)
    {
        case NodeKind::disjunctionNode:
        {
            return context.GetBoolValue(leftValue || rightValue);
        }
        case NodeKind::conjunctionNode:
        {
            return context.GetBoolValue(leftValue && rightValue);
        }
    }
    return nullptr;
}

Value* Evaluator::EvaluateIntegerBinaryExpression(Value* left, Value* right, NodeKind op)
{
    IntegerValue* l = static_cast<IntegerValue*>(left);
    IntegerValue* r = static_cast<IntegerValue*>(right);
    int64_t leftValue = l->GetValue();
    int64_t rightValue = r->GetValue();
    switch (op)
    {
        case NodeKind::disjunctionNode:
        {
            return context.GetBoolValue(leftValue != 0 || rightValue != 0);
        }
        case NodeKind::conjunctionNode:
        {
            return context.GetBoolValue(leftValue != 0 && rightValue != 0);
        }
        case NodeKind::inclusiveOrNode:
        {
            return context.GetIntegerValue(leftValue | rightValue);
        }
        case NodeKind::exclusiveOrNode:
        {
            return context.GetIntegerValue(leftValue ^ rightValue);
        }
        case NodeKind::andNode:
        {
            return context.GetIntegerValue(leftValue & rightValue);
        }
        case NodeKind::equalNode:
        {
            return context.GetBoolValue(leftValue == rightValue);
        }
        case NodeKind::notEqualNode:
        {
            return context.GetBoolValue(leftValue != rightValue);
        }
        case NodeKind::lessNode:
        {
            return context.GetBoolValue(leftValue < rightValue);
        }
        case NodeKind::greaterNode:
        {
            return context.GetBoolValue(leftValue > rightValue);
        }
        case NodeKind::lessOrEqualNode:
        {
            return context.GetBoolValue(leftValue <= rightValue);
        }
        case NodeKind::greaterOrEqualNode:
        {
            return context.GetBoolValue(leftValue >= rightValue);
        }
        case NodeKind::shiftLeftNode:
        {
            return context.GetIntegerValue(leftValue << rightValue);
        }
        case NodeKind::shiftRightNode:
        {
            return context.GetIntegerValue(leftValue >> rightValue);
        }
        case NodeKind::plusNode:
        {
            return context.GetIntegerValue(leftValue + rightValue);
        }
        case NodeKind::minusNode:
        {
            return context.GetIntegerValue(leftValue - rightValue);
        }
        case NodeKind::mulNode:
        {
            return context.GetIntegerValue(leftValue * rightValue);
        }
        case NodeKind::divNode:
        {
            return context.GetIntegerValue(leftValue / rightValue);
        }
        case NodeKind::modNode:
        {
            return context.GetIntegerValue(leftValue % rightValue);
        }
    }
    return nullptr;
}

Value* Evaluator::EvaluateFloatingBinaryExpression(Value* left, Value* right, NodeKind op)
{
    FloatingValue* l = static_cast<FloatingValue*>(left);
    FloatingValue* r = static_cast<FloatingValue*>(right);
    double leftValue = l->GetValue();
    double rightValue = r->GetValue();
    switch (op)
    {
        case NodeKind::disjunctionNode:
        {
            return context.GetBoolValue(leftValue != 0.0 || rightValue != 0.0);
        }
        case NodeKind::conjunctionNode:
        {
            return context.GetBoolValue(leftValue != 0.0 && rightValue != 0.0);
        }
        case NodeKind::equalNode:
        {
            return context.GetBoolValue(leftValue == rightValue);
        }
        case NodeKind::notEqualNode:
        {
            return context.GetBoolValue(leftValue != rightValue);
        }
        case NodeKind::lessNode:
        {
            return context.GetBoolValue(leftValue < rightValue);
        }
        case NodeKind::greaterNode:
        {
            return context.GetBoolValue(leftValue > rightValue);
        }
        case NodeKind::lessOrEqualNode:
        {
            return context.GetBoolValue(leftValue <= rightValue);
        }
        case NodeKind::greaterOrEqualNode:
        {
            return context.GetBoolValue(leftValue >= rightValue);
        }
        case NodeKind::plusNode:
        {
            return context.GetIntegerValue(leftValue + rightValue);
        }
        case NodeKind::minusNode:
        {
            return context.GetIntegerValue(leftValue - rightValue);
        }
        case NodeKind::mulNode:
        {
            return context.GetIntegerValue(leftValue * rightValue);
        }
        case NodeKind::divNode:
        {
            return context.GetIntegerValue(leftValue / rightValue);
        }
    }
    return nullptr;
}

void Evaluator::Visit(IntegerLiteralNode& node)
{
    valueStack.push(context.GetIntegerValue(node.Value()));
}

void Evaluator::Visit(FloatingLiteralNode& node)
{
    valueStack.push(context.GetFloatingValue(node.Value()));
}

void Evaluator::Visit(BooleanLiteralNode& node)
{
    valueStack.push(context.GetBoolValue(node.Value()));
}

void Evaluator::Visit(BinaryExprNode& node)
{
    node.Left()->Accept(*this);
    Value* left = valueStack.top();
    valueStack.pop();
    node.Right()->Accept(*this);
    Value* right = valueStack.top();
    valueStack.pop();
    Value* result = EvaluateBinaryExpression(left, right, node.Op()->Kind());
    valueStack.push(result);
}

Value* Evaluator::EvaluateUnaryExpression(Value* operand, NodeKind op)
{
    if (!operand) return nullptr;
    switch (operand->Kind())
    {
        case ValueKind::boolValue:
        {
            return EvaluateBooleanUnaryExpression(operand, op);
        }
        case ValueKind::integerValue:
        {
            return EvaluateIntegerUnaryExpression(operand, op);
        }
        case ValueKind::floatingValue:
        {
            return EvaluateFloatingUnaryExpression(operand, op);
        }
    }
    return nullptr;
}

Value* Evaluator::EvaluateBooleanUnaryExpression(Value* operand, NodeKind op)
{
    BoolValue* v = static_cast<BoolValue*>(operand);
    bool value = v->GetValue();
    switch (op)
    {
        case NodeKind::notNode:
        {
            return context.GetBoolValue(!value);
        }
    }
    return nullptr;
}

Value* Evaluator::EvaluateIntegerUnaryExpression(Value* operand, NodeKind op)
{
    IntegerValue* v = static_cast<IntegerValue*>(operand);
    int64_t value = v->GetValue();
    switch (op)
    {
        case NodeKind::notNode:
        {
            return context.GetBoolValue(!value);
        }
        case NodeKind::complementNode:
        {
            return context.GetIntegerValue(~value);
        }
        case NodeKind::plusNode:
        {
            return context.GetIntegerValue(+value);
        }
        case NodeKind::minusNode:
        {
            return context.GetIntegerValue(-value);
        }
    }
    return nullptr;
}

Value* Evaluator::EvaluateFloatingUnaryExpression(Value* operand, NodeKind op)
{
    FloatingValue* v = static_cast<FloatingValue*>(operand);
    double value = v->GetValue();
    switch (op)
    {
        case NodeKind::notNode:
        {
            return context.GetBoolValue(!value);
        }
        case NodeKind::plusNode:
        {
            return context.GetFloatingValue(+value);
        }
        case NodeKind::minusNode:
        {
            return context.GetFloatingValue(-value);
        }
    }
    return nullptr;
}

void Evaluator::Visit(UnaryExprNode& node)
{
    node.Child()->Accept(*this);
    Value* operand = valueStack.top();
    valueStack.pop();
    Value* result = EvaluateUnaryExpression(operand, node.Op()->Kind());
    valueStack.push(result);
}

void Evaluator::Visit(ConditionalExprNode& node)
{
    node.Condition()->Accept(*this);
    Value* cond = valueStack.top();
    valueStack.pop();
    if (cond)
    {
        BoolValue* boolValue = cond->ToBoolValue(context);
        bool value = boolValue->GetValue();
        if (value)
        {
            node.ThenExpr()->Accept(*this);
        }
        else
        {
            node.ElseExpr()->Accept(*this);
        }
    }
    else
    {
        valueStack.push(nullptr);
    }
}

void Evaluator::Visit(CastExprNode& node)
{
    NodeKind typeIdKind = node.TypeId()->Kind();
    switch (typeIdKind)
    {
        case NodeKind::boolNode:
        {
            node.Child()->Accept(*this);
            Value* value = valueStack.top();
            valueStack.pop();
            valueStack.push(value->ToBoolValue(context));
            return;
        }
        case NodeKind::intNode:
        {
            node.Child()->Accept(*this);
            Value* value = valueStack.top();
            valueStack.pop();
            valueStack.push(value->Convert(ValueKind::integerValue, context));
            return;
        }
        case NodeKind::doubleNode:
        {
            node.Child()->Accept(*this);
            Value* value = valueStack.top();
            valueStack.pop();
            valueStack.push(value->Convert(ValueKind::floatingValue, context));
            return;
        }
    }
    valueStack.push(nullptr);
}

void Evaluator::Visit(CppCastExprNode& node)
{
    NodeKind op = node.Op()->Kind();
    if (op == NodeKind::staticCastNode)
    {
        NodeKind typeIdKind = node.TypeId()->Kind();
        switch (typeIdKind)
        {
            case NodeKind::boolNode:
            {
                node.Child()->Accept(*this);
                Value* value = valueStack.top();
                valueStack.pop();
                valueStack.push(value->ToBoolValue(context));
                return;
            }
            case NodeKind::intNode:
            {
                node.Child()->Accept(*this);
                Value* value = valueStack.top();
                valueStack.pop();
                valueStack.push(value->Convert(ValueKind::integerValue, context));
                return;
            }
            case NodeKind::doubleNode:
            {
                node.Child()->Accept(*this);
                Value* value = valueStack.top();
                valueStack.pop();
                valueStack.push(value->Convert(ValueKind::floatingValue, context));
                return;
            }
        }
    }
    valueStack.push(nullptr);
}

void Evaluator::Visit(ParenthesizedExprNode& node)
{
    node.Child()->Accept(*this);
}

Value* EvaluateConstantExpression(Node* constantExpression, EvaluationContext& context)
{
    Evaluator evaluator(context);
    constantExpression->Accept(evaluator);
    return evaluator.GetValue();
}

} // namespace sngcpp::symbols
