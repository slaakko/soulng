// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_SYMBOL_FACTORY_INCLUDED
#define SNGCPP_SYMBOLS_SYMBOL_FACTORY_INCLUDED
#include <sngcpp20/symbols/SymbolsApi.hpp>
#include <sngcpp20/ast/Node.hpp>
#include <sngcpp20/parser/Context.hpp>

namespace sngcpp::symbols {

using namespace sngcpp::ast;
using namespace sngcpp::par;

SYMBOLS_API void BeginClass(Node* node, Context* context);
SYMBOLS_API void EndClass(Context* context);

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_SYMBOL_FACTORY_INCLUDED
