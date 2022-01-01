// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_EVALUATOR_INCLUDED
#define SNGCPP_SYMBOLS_EVALUATOR_INCLUDED
#include <sngcpp20/symbols/SymbolsApi.hpp>
#include <sngcpp20/symbols/Value.hpp>
#include <sngcpp20/ast/Node.hpp>

namespace sngcpp::symbols {

using namespace sngcpp::ast;

SYMBOLS_API Value* EvaluateConstantExpression(Node* constantExpression, EvaluationContext& context);

} // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_EVALUATOR_INCLUDED
