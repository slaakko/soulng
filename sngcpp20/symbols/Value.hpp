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
#include <string>
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
    Value(ValueKind kind_, const std::u32string& rep_);
    virtual ~Value();
    virtual BoolValue* ToBoolValue(EvaluationContext& context) = 0;
    virtual Value* Convert(ValueKind kind, EvaluationContext& context) = 0;
    ValueKind Kind() const { return kind; }
    const std::u32string& Rep() const { return rep; }
private:
    ValueKind kind;
    std::u32string rep;
};

class SYMBOLS_API BoolValue : public Value
{
public:
    BoolValue();
    BoolValue(bool value_, const std::u32string& rep_);
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
    IntegerValue(int64_t value_, const std::u32string& rep_);
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
    FloatingValue(double value_, const std::u32string& rep_);
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
    IntegerValue* GetIntegerValue(int64_t value, const std::u32string& rep);
    FloatingValue* GetFloatingValue(double value, const std::u32string& rep);
private:
    BoolValue trueValue;
    BoolValue falseValue;
    std::map<std::pair<int64_t, std::u32string>, IntegerValue*> integerValueMap;
    std::map<std::pair<double, std::u32string>, FloatingValue*> floatingValueMap;
    std::vector<std::unique_ptr<Value>> values;
};

} // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_VALUE_INCLUDED

