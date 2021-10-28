// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_CLASS_INCLUDED
#define SNGCPP_SYMBOLS_CLASS_INCLUDED
#include <sngcpp20/symbols/SymbolsApi.hpp>
#include <sngcpp20/ast/Statement.hpp>
#include <sngcpp20/symbols/Context.hpp>

namespace sngcpp::symbols {

using namespace sngcpp::ast;

using RecordedParseFn = void (*)(sngcpp::ast::CompoundStatementNode* compoundStatementNode, Context* context);

SYMBOLS_API void SetRecordedParseFn(RecordedParseFn fn);
SYMBOLS_API void BeginClass(Node* node, Context* context);
SYMBOLS_API void EndClass(Context* context);
SYMBOLS_API void ParseInlineMemberFunctions(Node* classSpecifierNode, Context* context);
SYMBOLS_API bool IsConstructorName(Node* node, Context* context);
SYMBOLS_API bool IsQualifiedConstructorName(Node* node, Context* context);

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_CLASS_INCLUDED
