// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Value.hpp>

namespace sngcpp::symbols {

ValueKind CommonValueKind(ValueKind left, ValueKind right)
{
    if (left == right) return left;
    if (left == ValueKind::floatingValue || right == ValueKind::floatingValue) return ValueKind::floatingValue;
    if (left == ValueKind::integerValue || right == ValueKind::integerValue) return ValueKind::integerValue;
    return ValueKind::boolValue;
}

Value::Value(ValueKind kind_) : kind(kind_)
{
}

Value::~Value()
{
}

BoolValue::BoolValue() : Value(ValueKind::boolValue), value(false)
{
}

BoolValue::BoolValue(bool value_) : Value(ValueKind::boolValue), value(value_)
{
}

Value* BoolValue::Convert(ValueKind kind, EvaluationContext& context)
{
    switch (kind)
    {
        case ValueKind::boolValue: return this;
        case ValueKind::integerValue: return context.GetIntegerValue(static_cast<int64_t>(value));
        case ValueKind::floatingValue: return context.GetFloatingValue(static_cast<double>(value));
    }
    return this;
}

IntegerValue::IntegerValue() : Value(ValueKind::integerValue), value(0)
{
}

IntegerValue::IntegerValue(int64_t value_) : Value(ValueKind::integerValue), value(value_)
{
}

BoolValue* IntegerValue::ToBoolValue(EvaluationContext& context)
{
    if (value) return context.GetBoolValue(true); else return context.GetBoolValue(false);
}

Value* IntegerValue::Convert(ValueKind kind, EvaluationContext& context)
{
    switch (kind)
    {
        case ValueKind::boolValue: return ToBoolValue(context);
        case ValueKind::integerValue: return this;
        case ValueKind::floatingValue: return context.GetFloatingValue(static_cast<double>(value));
    }
    return this;
}

FloatingValue::FloatingValue() : Value(ValueKind::floatingValue), value(0.0)
{
}

FloatingValue::FloatingValue(double value_) : Value(ValueKind::floatingValue), value(value_)
{
}

BoolValue* FloatingValue::ToBoolValue(EvaluationContext& context)
{
    if (value) return context.GetBoolValue(true); else return context.GetBoolValue(false);
}

Value* FloatingValue::Convert(ValueKind kind, EvaluationContext& context)
{
    switch (kind)
    {
        case ValueKind::boolValue: return ToBoolValue(context);
        case ValueKind::integerValue: return context.GetIntegerValue(static_cast<int64_t>(value));
        case ValueKind::floatingValue: return this;
    }
    return this;
}

EvaluationContext::EvaluationContext() : trueValue(true), falseValue(false)
{
}

BoolValue* EvaluationContext::GetBoolValue(bool value) 
{
    if (value) return &trueValue; else return &falseValue;
}

IntegerValue* EvaluationContext::GetIntegerValue(int64_t value)
{
    auto it = integerValueMap.find(value);
    if (it != integerValueMap.cend())
    {
        return it->second;
    }
    else
    {
        IntegerValue* integerValue = new IntegerValue(value);
        integerValueMap[value] = integerValue;
        values.push_back(std::unique_ptr<Value>(integerValue));
        return integerValue;
    }
}

FloatingValue* EvaluationContext::GetFloatingValue(double value)
{
    auto it = floatingValueMap.find(value);
    if (it != floatingValueMap.cend())
    {
        return it->second;
    }
    else
    {
        FloatingValue* floatingValue = new FloatingValue(value);
        floatingValueMap[value] = floatingValue;
        values.push_back(std::unique_ptr<Value>(floatingValue));
        return floatingValue;
    }
}

} // sngcpp::symbols