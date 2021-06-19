// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Value.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp::symbols {

using namespace soulng::unicode;

ValueKind CommonValueKind(ValueKind left, ValueKind right)
{
    if (left == right) return left;
    if (left == ValueKind::floatingValue || right == ValueKind::floatingValue) return ValueKind::floatingValue;
    if (left == ValueKind::integerValue || right == ValueKind::integerValue) return ValueKind::integerValue;
    return ValueKind::boolValue;
}

Value::Value(ValueKind kind_, const std::u32string& rep_) : Symbol(std::u32string(), SymbolKind::valueSymbol), kind(kind_), rep(rep_)
{
}

BoolValue::BoolValue() : Value(ValueKind::boolValue, U"false"), value(false)
{
}

BoolValue::BoolValue(bool value_, const std::u32string& rep_) : Value(ValueKind::boolValue, rep_), value(value_)
{
}

Value* BoolValue::Convert(ValueKind kind, EvaluationContext& context)
{
    switch (kind)
    {
        case ValueKind::boolValue: return this;
        case ValueKind::integerValue: return context.GetIntegerValue(static_cast<int64_t>(value), ToUtf32(std::to_string(value)));
        case ValueKind::floatingValue: return context.GetFloatingValue(static_cast<double>(value), ToUtf32(std::to_string(value)));
    }
    return this;
}

IntegerValue::IntegerValue() : Value(ValueKind::integerValue, U"0"), value(0)
{
}

IntegerValue::IntegerValue(int64_t value_, const std::u32string& rep_) : Value(ValueKind::integerValue, rep_), value(value_)
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
        case ValueKind::floatingValue: return context.GetFloatingValue(static_cast<double>(value), ToUtf32(std::to_string(value)));
    }
    return this;
}

FloatingValue::FloatingValue() : Value(ValueKind::floatingValue, U"0.0"), value(0.0)
{
}

FloatingValue::FloatingValue(double value_, const std::u32string& rep_) : Value(ValueKind::floatingValue, rep_), value(value_)
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
        case ValueKind::integerValue: return context.GetIntegerValue(static_cast<int64_t>(value), ToUtf32(std::to_string(value)));
        case ValueKind::floatingValue: return this;
    }
    return this;
}

EvaluationContext::EvaluationContext() : trueValue(true, U"true"), falseValue(false, U"false")
{
}

BoolValue* EvaluationContext::GetBoolValue(bool value) 
{
    if (value) return &trueValue; else return &falseValue;
}

IntegerValue* EvaluationContext::GetIntegerValue(int64_t value, const std::u32string& rep)
{
    auto it = integerValueMap.find(std::make_pair(value, rep));
    if (it != integerValueMap.cend())
    {
        return it->second;
    }
    else
    {
        IntegerValue* integerValue = new IntegerValue(value, rep);
        integerValueMap[std::make_pair(value, rep)] = integerValue;
        values.push_back(std::unique_ptr<Value>(integerValue));
        return integerValue;
    }
}

FloatingValue* EvaluationContext::GetFloatingValue(double value, const std::u32string& rep)
{
    auto it = floatingValueMap.find(std::make_pair(value, rep));
    if (it != floatingValueMap.cend())
    {
        return it->second;
    }
    else
    {
        FloatingValue* floatingValue = new FloatingValue(value, rep);
        floatingValueMap[std::make_pair(value, rep)] = floatingValue;
        values.push_back(std::unique_ptr<Value>(floatingValue));
        return floatingValue;
    }
}

} // sngcpp::symbols