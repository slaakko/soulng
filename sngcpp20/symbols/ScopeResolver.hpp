// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_SCOPE_RESOLVER_INCLUDED
#define SNGCPP_SYMBOLS_SCOPE_RESOLVER_INCLUDED
#include <sngcpp20/symbols/Scope.hpp>
#include <sngcpp20/ast/Node.hpp>
#include <sngcpp20/symbols/Context.hpp>

namespace sngcpp::symbols {

using namespace sngcpp::ast;

SYMBOLS_API Scope* ResolveScope(Node* nnsNode, Context* context);

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_SCOPE_RESOLVER_INCLUDED
