// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_PP_EVALUATOR_INCLUDED
#define SNGCPP_PP_EVALUATOR_INCLUDED
#include <sngcpp20/pp/PPApi.hpp>
#include <sngcpp20/symbols/Value.hpp>
#include <sngcpp20/ast/Node.hpp>

namespace sngcpp::pp {

class PP;

using namespace sngcpp::ast;
using namespace sngcpp::symbols;

PP_API bool EvaluateBooleanConstantExpression(Node* constantExpression, EvaluationContext& context, PP* pp);

} // namespace sngcpp::pp

#endif // SNGCPP_PP_EVALUATOR_INCLUDED
