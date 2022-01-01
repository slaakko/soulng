// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_CONCEPT_INCLUDED
#define SNGCPP_SYMBOLS_CONCEPT_INCLUDED
#include <sngcpp20/symbols/SymbolsApi.hpp>
#include <sngcpp20/ast/Node.hpp>
#include <sngcpp20/symbols/Context.hpp>

namespace sngcpp::symbols {

using namespace sngcpp::ast;

SYMBOLS_API void AddConcept(Node* node, Context* context);

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_CLASS_INCLUDED
