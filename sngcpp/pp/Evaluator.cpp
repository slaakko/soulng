// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/pp/Evaluator.hpp>
#include <sngcpp/ast/Expression.hpp>
#include <sngcpp/ast/Enumeration.hpp>
#include <sngcpp/ast/Literal.hpp>
#include <functional>
#include <stdexcept>

namespace sngcpp { namespace pp {

template<class T>
struct shift_left
{
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef T result_type;
    constexpr T operator()(const T& left, const T& right) const
    {	
        return left << right;
    }
};

template<class T>
struct shift_right
{
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef T result_type;
    constexpr T operator()(const T& left, const T& right) const
    {
        return left >> right;
    }
};

template<class T>
struct unary_plus
{
    typedef T argument_type;
    typedef T result_type;
    constexpr T operator()(const T& arg) const
    {
        return arg;
    }
};

void ThrowCannotEvaluateStatically(const std::string& fileName, int line)
{
    throw std::runtime_error("error: " + fileName + ":" + std::to_string(line) + ": cannot evaluate statically");
}

void ThrowInvalidOperation(const std::string& fileName, int line)
{
    throw std::runtime_error("error: " + fileName + ":" + std::to_string(line) + ": invalid operation");
}

ValueType CommonType(ValueType left, ValueType right)
{
    switch (left)
    {
        case ValueType::boolValue:
        {
            switch (right)
            {
                case ValueType::boolValue:
                {
                    return ValueType::boolValue;
                }
                case ValueType::intValue:
                {
                    return ValueType::intValue;
                }
                case ValueType::doubleValue:
                {
                    return ValueType::doubleValue;
                }
            }
            break;
        }
        case ValueType::intValue:
        {
            switch (right)
            {
                case ValueType::boolValue:
                case ValueType::intValue:
                {
                    return ValueType::intValue;
                }
                case ValueType::doubleValue:
                {
                    return ValueType::doubleValue;
                }
            }
            break;
        }
        case ValueType::doubleValue:
        {
            return ValueType::doubleValue;
        }
    }
    return ValueType::none;
}

template<class ValueT, class Predicate>
Value* EvaluateBinaryPredicate(Value* left, Value* right, Predicate predicate, EvaluationContext& context)
{
    ValueT* leftCasted = static_cast<ValueT*>(left);
    ValueT* rightCasted = static_cast<ValueT*>(right);
    return context.MakeValue(predicate(leftCasted->GetValue(), rightCasted->GetValue()));
}

template<class ValueT, class Op>
Value* EvaluateBinaryOperation(Value* left, Value* right, Op op, EvaluationContext& context)
{
    ValueT* leftCasted = static_cast<ValueT*>(left);
    ValueT* rightCasted = static_cast<ValueT*>(right);
    return context.MakeValue(op(leftCasted->GetValue(), rightCasted->GetValue()));
}

template<class ValueT, class Op>
Value* EvaluateUnaryOperation(Value* operand, Op op, EvaluationContext& context)
{
    ValueT* operandCasted = static_cast<ValueT*>(operand);
    return context.MakeValue(op(operandCasted->GetValue()));
}

using BinaryOperatorFun = Value* (*)(Value*, Value*, EvaluationContext&, const std::string&, int);

using UnaryOperatorFun = Value* (*)(Value*, EvaluationContext&, const std::string&, int);

Value* NotDefined(Value* left, Value* right, EvaluationContext&, const std::string& fileName, int line)
{
    throw std::runtime_error(fileName + ":" + std::to_string(line) + ": invalid operation for " + left->TypeName() + " type");
}

Value* NotDefined(Value* operand, EvaluationContext&, const std::string& fileName, int line)
{
    throw std::runtime_error(fileName + ":" + std::to_string(line) + ": invalid operation for " + operand->TypeName() + " type");
}

template<class ValueT>
Value* Equal(Value* left, Value* right, EvaluationContext& context, const std::string& fileName, int line)
{
    return EvaluateBinaryPredicate<ValueT>(left, right, std::equal_to<typename ValueT::operandType>(), context);
};

BinaryOperatorFun equal[] =
{
    Equal<BoolValue>, Equal<IntValue>, Equal<DoubleValue>
};

template<class ValueT>
Value* NotEqual(Value* left, Value* right, EvaluationContext& context, const std::string& fileName, int line)
{
    return EvaluateBinaryPredicate<ValueT>(left, right, std::not_equal_to<typename ValueT::operandType>(), context);
};

BinaryOperatorFun notEqual[] =
{
    NotEqual<BoolValue>, NotEqual<IntValue>, NotEqual<DoubleValue>
};

template<class ValueT>
Value* Less(Value* left, Value* right, EvaluationContext& context, const std::string& fileName, int line)
{
    return EvaluateBinaryPredicate<ValueT>(left, right, std::less<typename ValueT::operandType>(), context);
};

BinaryOperatorFun less[] =
{
    NotDefined, Less<IntValue>, Less<DoubleValue>
};

template<class ValueT>
Value* Greater(Value* left, Value* right, EvaluationContext& context, const std::string& fileName, int line)
{
    return EvaluateBinaryPredicate<ValueT>(left, right, std::greater<typename ValueT::operandType>(), context);
};

BinaryOperatorFun greater[] =
{
    NotDefined, Greater<IntValue>, Greater<DoubleValue>
};

template<class ValueT>
Value* LessEqual(Value* left, Value* right, EvaluationContext& context, const std::string& fileName, int line)
{
    return EvaluateBinaryPredicate<ValueT>(left, right, std::less_equal<typename ValueT::operandType>(), context);
};

BinaryOperatorFun lessEqual[] =
{
    NotDefined, LessEqual<IntValue>, LessEqual<DoubleValue>
};

template<class ValueT>
Value* GreaterEqual(Value* left, Value* right, EvaluationContext& context, const std::string& fileName, int line)
{
    return EvaluateBinaryPredicate<ValueT>(left, right, std::greater_equal<typename ValueT::operandType>(), context);
};

BinaryOperatorFun greaterEqual[] =
{
    NotDefined, GreaterEqual<IntValue>, GreaterEqual<DoubleValue>
};

template<class ValueT>
Value* BitOr(Value* left, Value* right, EvaluationContext& context, const std::string& fileName, int line)
{
    return EvaluateBinaryOperation<ValueT>(left, right, std::bit_or<typename ValueT::operandType>(), context);
}

BinaryOperatorFun bitOr[] =
{
    NotDefined, BitOr<IntValue>, NotDefined
};

template<class ValueT>
Value* BitXor(Value* left, Value* right, EvaluationContext& context, const std::string& fileName, int line)
{
    return EvaluateBinaryOperation<ValueT>(left, right, std::bit_xor<typename ValueT::operandType>(), context);
}

BinaryOperatorFun bitXor[] =
{
    NotDefined, BitXor<IntValue>, NotDefined
};

template<class ValueT>
Value* BitAnd(Value* left, Value* right, EvaluationContext& context, const std::string& fileName, int line)
{
    return EvaluateBinaryOperation<ValueT>(left, right, std::bit_and<typename ValueT::operandType>(), context);
}

BinaryOperatorFun bitAnd[] =
{
    NotDefined, BitAnd<IntValue>, NotDefined
};

template<class ValueT>
Value* ShiftLeft(Value* left, Value* right, EvaluationContext& context, const std::string& fileName, int line)
{
    return EvaluateBinaryOperation<ValueT>(left, right, shift_left<typename ValueT::operandType>(), context);
};

BinaryOperatorFun shiftLeft[] =
{
    NotDefined, ShiftLeft<IntValue>, NotDefined
};

template<class ValueT>
Value* ShiftRight(Value* left, Value* right, EvaluationContext& context, const std::string& fileName, int line)
{
    return EvaluateBinaryOperation<ValueT>(left, right, shift_right<typename ValueT::operandType>(), context);
};

BinaryOperatorFun shiftRight[] =
{
    NotDefined, ShiftRight<IntValue>, NotDefined
};

template<class ValueT>
Value* Add(Value* left, Value* right, EvaluationContext& context, const std::string& fileName, int line)
{
    return EvaluateBinaryOperation<ValueT>(left, right, std::plus<typename ValueT::operandType>(), context);
}

BinaryOperatorFun add[] =
{
    NotDefined, Add<IntValue>, Add<DoubleValue>
};

template<class ValueT>
Value* Sub(Value* left, Value* right, EvaluationContext& context, const std::string& fileName, int line)
{
    return EvaluateBinaryOperation<ValueT>(left, right, std::minus<typename ValueT::operandType>(), context);
}

BinaryOperatorFun sub[] =
{
    NotDefined, Sub<IntValue>, Sub<DoubleValue>
};

template<class ValueT>
Value* Mul(Value* left, Value* right, EvaluationContext& context, const std::string& fileName, int line)
{
    return EvaluateBinaryOperation<ValueT>(left, right, std::multiplies<typename ValueT::operandType>(), context);
}

BinaryOperatorFun mul[] =
{
    NotDefined, Mul<IntValue>, Mul<DoubleValue>
};

template<class ValueT>
Value* Div(Value* left, Value* right, EvaluationContext& context, const std::string& fileName, int line)
{
    return EvaluateBinaryOperation<ValueT>(left, right, std::divides<typename ValueT::operandType>(), context);
}

BinaryOperatorFun div[] =
{
    NotDefined, Div<IntValue>, Div<DoubleValue>
};

template<class ValueT>
Value* Mod(Value* left, Value* right, EvaluationContext& context, const std::string& fileName, int line)
{
    return EvaluateBinaryOperation<ValueT>(left, right, std::modulus<typename ValueT::operandType>(), context);
}

BinaryOperatorFun mod[] =
{
    NotDefined, Mod<IntValue>, NotDefined
};

template<class ValueT>
Value* UnaryPlus(Value* operand, EvaluationContext& context, const std::string& fileName, int line)
{
    return EvaluateUnaryOperation<ValueT>(operand, unary_plus<typename ValueT::operandType>(), context);
}

UnaryOperatorFun unaryPlus[] =
{
    NotDefined, UnaryPlus<IntValue>, UnaryPlus<DoubleValue>
};

template<class ValueT>
Value* UnaryMinus(Value* operand, EvaluationContext& context, const std::string& fileName, int line)
{
    return EvaluateUnaryOperation<ValueT>(operand, std::negate<typename ValueT::operandType>(), context);
}

UnaryOperatorFun unaryMinus[] =
{
    NotDefined, UnaryMinus<IntValue>, UnaryMinus<DoubleValue>
};

template<class ValueT>
Value* Complement(Value* operand, EvaluationContext& context, const std::string& fileName, int line)
{
    return EvaluateUnaryOperation<ValueT>(operand, std::bit_not<typename ValueT::operandType>(), context);
}

UnaryOperatorFun complement[] =
{
    NotDefined, Complement<IntValue>, NotDefined
};

template <class ValueT>
Value* Not(Value* operand, EvaluationContext& context, const std::string& fileName, int line)
{
    return EvaluateUnaryOperation<ValueT>(operand, std::logical_not<typename ValueT::operandType>(), context);
}

UnaryOperatorFun not_[] =
{
    Not<BoolValue>, NotDefined, NotDefined
};

Value::Value(ValueType valueType_) : valueType(valueType_)
{
}

Value::~Value()
{
}

BoolValue::BoolValue(bool value_) : Value(ValueType::boolValue), value(value_)
{
}

BoolValue* BoolValue::ToBool(EvaluationContext& context)
{
    return this;
}

IntValue* BoolValue::ToInt(EvaluationContext& context)
{
    return context.MakeValue(int64_t(value));
}

DoubleValue* BoolValue::ToDouble(EvaluationContext& context)
{
    return context.MakeValue(double(value));
}

IntValue::IntValue(int64_t value_) : Value(ValueType::intValue), value(value_)
{
}

BoolValue* IntValue::ToBool(EvaluationContext& context)
{
    return context.MakeValue(value != 0);
}

IntValue* IntValue::ToInt(EvaluationContext& context)
{
    return this;
}

DoubleValue* IntValue::ToDouble(EvaluationContext& context)
{
    return context.MakeValue(double(value));
}

DoubleValue::DoubleValue(double value_) : Value(ValueType::doubleValue), value(value_)
{
}

BoolValue* DoubleValue::ToBool(EvaluationContext& context)
{
    return context.MakeValue(value != 0);
}

IntValue* DoubleValue::ToInt(EvaluationContext& context)
{
    return context.MakeValue(int64_t(value));
}

DoubleValue* DoubleValue::ToDouble(EvaluationContext& context)
{
    return this;
}

EvaluationContext::EvaluationContext() : trueValue(true), falseValue(false), intZero(0), intOne(1), doubleZero(0), doubleOne(1)
{
}

EvaluationContext::~EvaluationContext()
{
    for (Value* value : values)
    {
        delete value;
    }
}

BoolValue* EvaluationContext::MakeValue(bool value)
{
    if (value) return &trueValue;
    else return &falseValue;
}

IntValue* EvaluationContext::MakeValue(int64_t value)
{
    if (value == 0)
    {
        return &intZero;
    }
    else if (value == 1)
    {
        return &intOne;
    }
    else
    {
        auto it = intValueMap.find(value);
        if (it != intValueMap.cend())
        {
            return it->second;
        }
        else
        {
            IntValue* intValue = new IntValue(value);
            values.push_back(intValue);
            intValueMap[value] = intValue;
            return intValue;
        }
    }
}

DoubleValue* EvaluationContext::MakeValue(double value)
{
    if (value == 0)
    {
        return &doubleZero;
    }
    else if (value == 1)
    {
        return &doubleOne;
    }
    else
    {
        auto it = doubleValueMap.find(value);
        if (it != doubleValueMap.cend())
        {
            return it->second;
        }
        else
        {
            DoubleValue* doubleValue = new DoubleValue(value);
            values.push_back(doubleValue);
            doubleValueMap[value] = doubleValue;
            return doubleValue;
        }
    }
}

Evaluator::Evaluator(const std::string& fileName_, int line_, EvaluationContext& context_) : fileName(fileName_), line(line_), context(context_), value()
{
}

Value* Evaluator::GetValue()
{
    if (!value)
    {
        ThrowInvalidOperation(fileName, line);
    }
    return value;
}

void Evaluator::Visit(BaseClassSpecifierNode& baseClassSpecifierNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(BaseClassSpecifierSequenceNode& baseClassSpecifierSequenceNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ForwardClassDeclarationNode& forwardClassDeclarationNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ElaborateClassNameNode& elaborateClassNameNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ClassNode& classNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(MemberAccessDeclarationNode& memberAccessDeclarationNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(MemberDeclarationNode& memberDeclarationNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(SpecialMemberFunctionNode& specialMemberFunctionNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(CtorInitializerNode& ctorInitializerNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(MemberInitializerNode& memberInitializerNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(MemberInitializerSequenceNode& memberInitializerSequenceNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(SourceFileNode& sourceFileNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(SourceFileSequenceNode& sourceFileSequenceNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(SimpleDeclarationNode& simpleDeclarationNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(AliasDeclarationNode& aliasDeclarationNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(UsingDirectiveNode& usingDirectiveNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(UsingDeclarationNode& usingDeclarationNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(TypedefNode& typedefNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(DeclarationSequenceNode& declarationSequenceNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(LinkageSpecificationNode& linkageSpecificationNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(IdDeclaratorNode& idDeclaratorNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ArrayDeclaratorNode& arrayDeclaratorNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(FunctionDeclaratorNode& functionDeclaratorNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(FunctionPtrIdNode& functionPtrIdNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(MemberFunctionPtrIdNode& memberFunctionPtrIdNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(InitDeclaratorNode& initDeclaratorNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(AssignmentInitializerNode& assignmentInitializerNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ExpressionListInitializerNode& expressionListInitializerNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ExpressionInitializerNode& expressionInitializerNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(BracedInitializerListNode& bracedInitializerListNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(EnumTypeNode& enumTypeNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(EnumeratorNode& enumeratorNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(EnumeratorSequenceNode& enumeratorSequenceNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ExpressionSequenceNode& expressionSequenceNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(CommaExpressionNode& commaExpressionNode)
{
    commaExpressionNode.Right()->Accept(*this);
}

void Evaluator::Visit(AssignmentExpressionNode& assignmentExpressionNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ConditionalExpressionNode& conditionalExpressionNode)
{
    conditionalExpressionNode.Condition()->Accept(*this);
    if (value->ToBool(context)->GetValue())
    {
        conditionalExpressionNode.ThenExpr()->Accept(*this);
    }
    else
    {
        conditionalExpressionNode.ElseExpr()->Accept(*this);
    }
}

void Evaluator::Visit(ThrowExpressionNode& throwExpressionNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(LogicalOrExpressionNode& logicalOrExpressionNode)
{
    logicalOrExpressionNode.Left()->Accept(*this);
    BoolValue* boolValue = value->ToBool(context);
    if (boolValue->GetValue())
    {
        value = boolValue;
    }
    else
    {
        logicalOrExpressionNode.Right()->Accept(*this);
        value = value->ToBool(context);
    }
}

void Evaluator::Visit(LogicalAndExpressionNode& logicalAndExpressionNode)
{
    logicalAndExpressionNode.Left()->Accept(*this);
    BoolValue* boolValue = value->ToBool(context);
    if (!boolValue->GetValue())
    {
        value = boolValue;
    }
    else
    {
        logicalAndExpressionNode.Right()->Accept(*this);
        value = value->ToBool(context);
    }
}

void Evaluator::Visit(InclusiveOrExpressionNode& inclusiveOrExpressionNode)
{
    inclusiveOrExpressionNode.Left()->Accept(*this);
    Value* left = value;
    inclusiveOrExpressionNode.Right()->Accept(*this);
    Value* right = value;
    ValueType commonType = CommonType(left->Type(), right->Type());
    value = bitOr[static_cast<int>(commonType)](left, right, context, fileName, line);
}

void Evaluator::Visit(ExclusiveOrExpressionNode& exclusiveOrExpressionNode)
{
    exclusiveOrExpressionNode.Left()->Accept(*this);
    Value* left = value;
    exclusiveOrExpressionNode.Right()->Accept(*this);
    Value* right = value;
    ValueType commonType = CommonType(left->Type(), right->Type());
    value = bitXor[static_cast<int>(commonType)](left, right, context, fileName, line);
}

void Evaluator::Visit(AndExpressionNode& andExpressionNode)
{
    andExpressionNode.Left()->Accept(*this);
    Value* left = value;
    andExpressionNode.Right()->Accept(*this);
    Value* right = value;
    ValueType commonType = CommonType(left->Type(), right->Type());
    value = bitAnd[static_cast<int>(commonType)](left, right, context, fileName, line);
}

void Evaluator::Visit(EqualityExpressionNode& equalityExpressionNode)
{
    equalityExpressionNode.Left()->Accept(*this);
    Value* left = value;
    equalityExpressionNode.Right()->Accept(*this);
    Value* right = value;
    ValueType commonType = CommonType(left->Type(), right->Type());
    switch (equalityExpressionNode.Op())
    {
        case Operator::equal:
        {
            value = equal[static_cast<int>(commonType)](left, right, context, fileName, line);
            break;
        }
        case Operator::notEqual:
        {
            value = notEqual[static_cast<int>(commonType)](left, right, context, fileName, line);
        }
    }
}

void Evaluator::Visit(RelationalExpressionNode& relationalExpressionNode)
{
    relationalExpressionNode.Left()->Accept(*this);
    Value* left = value;
    relationalExpressionNode.Right()->Accept(*this);
    Value* right = value;
    ValueType commonType = CommonType(left->Type(), right->Type());
    switch (relationalExpressionNode.Op())
    {
        case Operator::less:
        {
            value = less[static_cast<int>(commonType)](left, right, context, fileName, line);
            break;
        }
        case Operator::greater:
        {
            value = greater[static_cast<int>(commonType)](left, right, context, fileName, line);
            break;
        }
        case Operator::lessOrEqual:
        {
            value = lessEqual[static_cast<int>(commonType)](left, right, context, fileName, line);
            break;
        }
        case Operator::greaterOrEqual:
        {
            value = greaterEqual[static_cast<int>(commonType)](left, right, context, fileName, line);
            break;
        }
    }
}

void Evaluator::Visit(ShiftExpressionNode& shiftExpressionNode)
{
    shiftExpressionNode.Left()->Accept(*this);
    Value* left = value;
    shiftExpressionNode.Right()->Accept(*this);
    Value* right = value;
    ValueType commonType = CommonType(left->Type(), right->Type());
    switch (shiftExpressionNode.Op())
    {
        case Operator::shiftLeft:
        {
            value = shiftLeft[static_cast<int>(commonType)](left, right, context, fileName, line);
            break;
        }
        case Operator::shiftRight:
        {
            value = shiftRight[static_cast<int>(commonType)](left, right, context, fileName, line);
            break;
        }
    }
}

void Evaluator::Visit(AdditiveExpressionNode& additiveExpressionNode)
{
    additiveExpressionNode.Left()->Accept(*this);
    Value* left = value;
    additiveExpressionNode.Right()->Accept(*this);
    Value* right = value;
    ValueType commonType = CommonType(left->Type(), right->Type());
    switch (additiveExpressionNode.Op())
    {
        case Operator::add:
        {
            value = add[static_cast<int>(commonType)](left, right, context, fileName, line);
            break;
        }
        case Operator::sub:
        {
            value = sub[static_cast<int>(commonType)](left, right, context, fileName, line);
            break;
        }
    }
}

void Evaluator::Visit(MultiplicativeExpressionNode& multiplicativeExpressionNode)
{
    multiplicativeExpressionNode.Left()->Accept(*this);
    Value* left = value;
    multiplicativeExpressionNode.Right()->Accept(*this);
    Value* right = value;
    ValueType commonType = CommonType(left->Type(), right->Type());
    switch (multiplicativeExpressionNode.Op())
    {
        case Operator::mul:
        {
            value = mul[static_cast<int>(commonType)](left, right, context, fileName, line);
            break;
        }
        case Operator::div:
        {
            value = div[static_cast<int>(commonType)](left, right, context, fileName, line);
            break;
        }
        case Operator::rem:
        {
            value = mod[static_cast<int>(commonType)](left, right, context, fileName, line);
            break;
        }
    }
}

void Evaluator::Visit(PMExpressionNode& pmExpressionNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(CastExpressionNode& castExpressionNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(UnaryExpressionNode& unaryExpressionNode)
{
    unaryExpressionNode.Child()->Accept(*this);
    Value* operand = value;
    ValueType valueType = operand->Type();
    switch (unaryExpressionNode.Op())
    {
        case Operator::unaryPlus:
        {
            value = unaryPlus[static_cast<int>(valueType)](operand, context, fileName, line);
            break;
        }
        case Operator::unaryMinus:
        {
            value = unaryMinus[static_cast<int>(valueType)](operand, context, fileName, line);
            break;
        }
        case Operator::complement:
        {
            value = complement[static_cast<int>(valueType)](operand, context, fileName, line);
            break;
        }
        case Operator::not_:
        {
            value = not_[static_cast<int>(valueType)](operand, context, fileName, line);
            break;
        }
        default:
        {
            ThrowCannotEvaluateStatically(fileName, line);
            break;
        }
    }
}

void Evaluator::Visit(NewExpressionNode& newExpressionNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(DeleteExpressionNode& deleteExpressionNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(SubscriptExpressionNode& subscriptExpressionNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(InvokeExpressionNode& invokeExpressionNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(DotNode& dotNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ArrowNode& arrowNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(PostfixIncNode& postfixIncNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(PostfixDecNode& postfixDecNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(CppCastExpressionNode& cppCastExpressionNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(TypeIdExpressionNode& typeIdExpressionNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ThisNode& thisNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ParenthesizedExprNode& parenthesizedExprNode)
{
    parenthesizedExprNode.Child()->Accept(*this);
}

void Evaluator::Visit(LambdaExpressionNode& lambdaExpressionNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(CaptureSequenceNode& captureSequenceNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(AssignCaptureNode& assignCaptureNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(RefCaptureNode& refCaptureNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ThisCaptureNode& thisCaptureNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(IdentifierCaptureNode& identifierCaptureNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(IdentifierNode& identifierNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(OperatorFunctionIdNode& operatorFunctionIdNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ConversionFunctionIdNode& conversionFunctionIdNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(DtorIdNode& dDtorIdNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(NestedIdNode& nestedIdNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ParameterNode& parameterNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ParameterSequenceNode& parameterSequenceNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(FunctionNode& functionNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(FloatingLiteralNode& floatingLiteralNode)
{
    value = context.MakeValue(floatingLiteralNode.Value());
}

void Evaluator::Visit(IntegerLiteralNode& integerLiteralNode)
{
    value = context.MakeValue(static_cast<int64_t>(integerLiteralNode.Value()));
}

void Evaluator::Visit(CharacterLiteralNode& characterLiteralNode)
{
    value = context.MakeValue(static_cast<int64_t>(characterLiteralNode.Chr()));
}

void Evaluator::Visit(StringLiteralNode& stringLiteralNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(BooleanLiteralNode& booleanLiteralNode)
{
    value = context.MakeValue(booleanLiteralNode.Value());
}

void Evaluator::Visit(NullPtrLiteralNode& nullPtrLiteralNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(NamespaceNode& namespaceNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(SimpleTypeNode& simpleTypeNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(LabeledStatementNode& labeledStatementNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(CaseStatementNode& caseStatementNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(DefaultStatementNode& defaultStatementNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ExpressionStatementNode& expressionStatementNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(CompoundStatementNode& compoundStatementNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(StatementSequenceNode& statementSequenceNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(IfStatementNode& ifStatementNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(SwitchStatementNode& switchStatementNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(WhileStatementNode& whileStatementNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(DoStatementNode& doStatementNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(RangeForStatementNode& rangeForStatementNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ForStatementNode& forStatementNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(BreakStatementNode& breakStatementNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ContinueStatementNode& continueStatementNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ReturnStatementNode& returnStatementNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(GotoStatementNode& gotoStatementNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(DeclarationStatementNode& declarationStatementNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(TryStatementNode& tryStatementNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(HandlerNode& handlerNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(HandlerSequenceNode& handlerSequenceNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(CatchAllNode& catchAllNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(TypeParameterNode& typeParameterNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(TemplateParameterSequenceNode& templateParameterSequenceNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(TemplateDeclarationNode& templateDeclarationNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(TemplateArgumentSequenceNode& templateArgumentSequenceNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(TemplateIdNode& templateIdNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(TemplateArgumentNode& templateArgumentNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ExplicitInstantiationNode& explicitInstantiationNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ExplicitSpecializationNode& explicitSpecializationNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(ConstNode& constNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(VolatileNode& volatileNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(PointerNode& pointerNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(RValueRefNode& rValueRefNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

void Evaluator::Visit(LValueRefNode& lValueRefNode)
{
    ThrowCannotEvaluateStatically(fileName, line);
}

} } // namespace sngcpp::pp
