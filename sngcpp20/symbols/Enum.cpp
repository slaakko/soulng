// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Enum.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Enum.hpp>

namespace sngcpp::symbols {

class EnumCreatorVisitor : public DefaultVisitor
{
public:
    EnumCreatorVisitor(Context* context_);
    void Visit(EnumSpecifierNode& node);
    void Visit(IdentifierNode& node) override;
    void Visit(UnnamedNode& node) override;
private:
    Context* context;
    EnumSpecifierNode* specifierNode;
};

EnumCreatorVisitor::EnumCreatorVisitor(Context* context_) : context(context_), specifierNode(nullptr)
{
}

void EnumCreatorVisitor::Visit(EnumSpecifierNode& node)
{
    specifierNode = &node;
    node.EnumHead()->Accept(*this);
}

void EnumCreatorVisitor::Visit(IdentifierNode& node)
{
    context->GetSymbolTable()->BeginEnumType(specifierNode, &node, context);
}

void EnumCreatorVisitor::Visit(UnnamedNode& node)
{
    context->GetSymbolTable()->BeginEnumType(specifierNode, &node, context);
}

void BeginEnumType(Node* node, Context* context)
{
    EnumCreatorVisitor visitor(context);
    node->Accept(visitor);
}

void EndEnumType(Context* context)
{
    context->GetSymbolTable()->EndEnumType();
}

} // sngcpp::symbols
