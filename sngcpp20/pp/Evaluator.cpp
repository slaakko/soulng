// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/pp/Evaluator.hpp>
#include <sngcpp20/pp/PP.hpp>
#include <sngcpp20/symbols/Evaluator.hpp>

namespace sngcpp::pp {

bool EvaluateBooleanConstantExpression(Node* constantExpression, EvaluationContext& context, PP* pp)
{
    Value* value = EvaluateConstantExpression(constantExpression, context);
    if (!value)
    {
        std::string error = "could not evaluate expression: " + pp->FileName() + ":" + std::to_string(pp->GetLineIndex() + 1);
        pp->AddError(error);
        return false;
    }
    BoolValue* boolValue = value->ToBoolValue(context);
    bool result = boolValue->GetValue();
    return result;
}

} // namespace sngcpp::pp
