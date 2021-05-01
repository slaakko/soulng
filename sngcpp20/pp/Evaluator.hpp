// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_PP_EVALUATOR_INCLUDED
#define SNGCPP_PP_EVALUATOR_INCLUDED
#include <sngcpp20/pp/PPApi.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <string>
#include <map>
#include <memory>
#include <vector>
#include <stdint.h>

namespace sngcpp::pp {

enum class ValueType
{
    none, boolValue, intValue, doubleValue
};

PP_API ValueType CommonType(ValueType left, ValueType right);

class EvaluationContext;
class BoolValue;
class IntValue;
class DoubleValue;

class PP_API Value
{
public:
    Value(ValueType valueType_);
    virtual ~Value();
    ValueType Type() const { return valueType; }
    virtual BoolValue* ToBool(EvaluationContext& context) = 0;
    virtual IntValue* ToInt(EvaluationContext& context) = 0;
    virtual DoubleValue* ToDouble(EvaluationContext& context) = 0;
    virtual std::string TypeName() const = 0;
private:
    ValueType valueType;
};

class PP_API BoolValue : public Value
{
public:
    using operandType = bool;
    BoolValue(bool value_);
    bool GetValue() const { return value;  }
    BoolValue* ToBool(EvaluationContext& context) override;
    IntValue* ToInt(EvaluationContext& context) override;
    DoubleValue* ToDouble(EvaluationContext& context) override;
    std::string TypeName() const override { return "bool"; }
private:
    bool value;
};

class PP_API IntValue : public Value
{
public:
    using operandType = int64_t;
    IntValue(int64_t value_);
    int64_t GetValue() const { return value; }
    BoolValue* ToBool(EvaluationContext& context) override;
    IntValue* ToInt(EvaluationContext& context) override;
    DoubleValue* ToDouble(EvaluationContext& context) override;
    std::string TypeName() const override { return "int"; }
private:
    int64_t value;
};

class PP_API DoubleValue : public Value
{
public:
    using operandType = double;
    DoubleValue(double value_);
    double GetValue() const { return value; }
    BoolValue* ToBool(EvaluationContext& context) override;
    IntValue* ToInt(EvaluationContext& context) override;
    DoubleValue* ToDouble(EvaluationContext& context) override;
    std::string TypeName() const override { return "double"; }
private:
    double value;
};

class PP_API EvaluationContext
{
public:
    EvaluationContext();
    ~EvaluationContext();
    BoolValue* MakeValue(bool value);
    IntValue* MakeValue(int64_t value);
    DoubleValue* MakeValue(double value);
private:
    BoolValue trueValue;
    BoolValue falseValue;
    IntValue intZero;
    IntValue intOne;
    DoubleValue doubleZero;
    DoubleValue doubleOne;
    std::map<int64_t, IntValue*> intValueMap;
    std::map<double, DoubleValue*> doubleValueMap;
    std::vector<Value*> values;
};

using namespace sngcpp::ast;

PP_API void ThrowCannotEvaluateStatically(const std::string& fileName, int line);
PP_API void ThrowInvalidOperation(const std::string& fileName, int line);

class PP_API Evaluator : public sngcpp::ast::Visitor
{
public:
    Evaluator(const std::string& fileName_, int line_, EvaluationContext& context_);
    Value* GetValue();
private:
    std::string fileName;
    int line;
    EvaluationContext& context;
    Value* value;
};

} // namespace sngcpp::pp

#endif // SNGCPP_PP_EVALUATOR_INCLUDED
