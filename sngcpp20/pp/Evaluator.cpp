// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/pp/Evaluator.hpp>
#include <functional>
#include <stdexcept>

namespace sngcpp::pp {

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

} // namespace sngcpp::pp
