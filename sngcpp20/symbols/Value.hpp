// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_VALUE_INCLUDED
#define SNGCPP_SYMBOLS_VALUE_INCLUDED
#include <sngcpp20/symbols/SymbolsApi.hpp>
#include <stdint.h>
#include <map>
#include <memory>
#include <vector>

namespace sngcpp::symbols {

class BoolValue;
class EvaluationContext;

enum class ValueKind : int
{
    boolValue, integerValue, floatingValue
};

ValueKind CommonValueKind(ValueKind left, ValueKind right);

class SYMBOLS_API Value
{
public:
    Value(ValueKind kind_);
    virtual ~Value();
    virtual BoolValue* ToBoolValue(EvaluationContext& context) = 0;
    virtual Value* Convert(ValueKind kind, EvaluationContext& context) = 0;
    ValueKind Kind() const { return kind; }
private:
    ValueKind kind;
};

class SYMBOLS_API BoolValue : public Value
{
public:
    BoolValue();
    BoolValue(bool value_);
    bool GetValue() const { return value; }
    BoolValue* ToBoolValue(EvaluationContext& context) override { return this; }
    Value* Convert(ValueKind kind, EvaluationContext& context) override;
private:
    bool value;
};

class SYMBOLS_API IntegerValue : public Value
{
public:
    IntegerValue();
    IntegerValue(int64_t value_);
    int64_t GetValue() const { return value; }
    BoolValue* ToBoolValue(EvaluationContext& context) override;
    Value* Convert(ValueKind kind, EvaluationContext& context) override;
private:
    int64_t value;
};

class SYMBOLS_API FloatingValue : public Value
{
public:
    FloatingValue();
    FloatingValue(double value_);
    double GetValue() const { return value; }
    BoolValue* ToBoolValue(EvaluationContext& context) override;
    Value* Convert(ValueKind kind, EvaluationContext& context) override;
private:
    double value;
};

class SYMBOLS_API EvaluationContext
{
public:
    EvaluationContext();
    EvaluationContext(const EvaluationContext&) = delete;
    EvaluationContext& operator=(const EvaluationContext&) = delete;
    BoolValue* GetBoolValue(bool value);
    IntegerValue* GetIntegerValue(int64_t value);
    FloatingValue* GetFloatingValue(double value);
private:
    BoolValue trueValue;
    BoolValue falseValue;
    std::map<int64_t, IntegerValue*> integerValueMap;
    std::map<double, FloatingValue*> floatingValueMap;
    std::vector<std::unique_ptr<Value>> values;
};

} // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_VALUE_INCLUDED

