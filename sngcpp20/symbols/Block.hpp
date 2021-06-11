// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_BLOCK_INCLUDED
#define SNGCPP_SYMBOLS_BLOCK_INCLUDED
#include <sngcpp20/symbols/SymbolsApi.hpp>
#include <sngcpp20/ast/Node.hpp>
#include <sngcpp20/symbols/Context.hpp>

namespace sngcpp::symbols {

using namespace sngcpp::ast;

SYMBOLS_API void BeginBlock(const SourcePos& sourcePos, Context* context);
SYMBOLS_API void EndBlock(Context* context);
SYMBOLS_API void RemoveBlock(Context* context);
SYMBOLS_API void MapNode(Node* node, Context* context);

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_BLOCK_INCLUDED
