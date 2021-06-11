// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Block.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>

namespace sngcpp::symbols {

void BeginBlock(const SourcePos& sourcePos, Context* context)
{
    context->GetSymbolTable()->BeginBlock(sourcePos, context);
}

void EndBlock(Context* context)
{
    context->GetSymbolTable()->EndBlock();
}

void RemoveBlock(Context* context)
{
    context->GetSymbolTable()->RemoveBlock();
}

void MapNode(Node* node, Context* context)
{
    context->GetSymbolTable()->MapNode(node);
}

} // sngcpp::symbols
