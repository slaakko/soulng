// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_TEMPLATE_INCLUDED
#define SNGCPP_SYMBOLS_TEMPLATE_INCLUDED
#include <sngcpp20/symbols/SymbolsApi.hpp>
#include <sngcpp20/ast/Node.hpp>
#include <sngcpp20/symbols/Context.hpp>

namespace sngcpp::symbols {

using namespace sngcpp::ast;

SYMBOLS_API void BeginTemplateDeclaration(Node* templateHeadNode, Context* context);
SYMBOLS_API void EndTemplateDeclaration(Context* context);
SYMBOLS_API void RemoveTemplateDeclaration(Context* context);
SYMBOLS_API void AddTemplateParameter(Node* templateParameterNode, int index, Context* context);

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_TEMPLATE_INCLUDED
