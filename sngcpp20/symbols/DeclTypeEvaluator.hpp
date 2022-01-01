// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_DECLTYPE_EVALUATOR_INCLUDED
#define SNGCPP_SYMBOLS_DECLTYPE_EVALUATOR_INCLUDED
#include <sngcpp20/symbols/Context.hpp>
#include <sngcpp20/ast/Node.hpp>

namespace sngcpp::symbols {

using namespace sngcpp::ast;

class TypeSymbol;

SYMBOLS_API TypeSymbol* EvaluateDeclTypeNode(Node* declTypeNode, Context* context);

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_DECLTYPE_EVALUATOR_INCLUDED
