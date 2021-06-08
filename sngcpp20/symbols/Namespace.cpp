// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Namespace.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/ast/Visitor.hpp>

namespace sngcpp::symbols {

class NamespaceCreatorVisitor : public DefaultVisitor
{
public:
    NamespaceCreatorVisitor(Context* context_);
    void Visit(ColonColonNode& node) override;
    void Visit(IdentifierNode& node) override;
private:
    Context* context;
    Scope* currentScope;
    bool first;
};

NamespaceCreatorVisitor::NamespaceCreatorVisitor(Context* context_) : context(context_), first(true), currentScope(context->GetSymbolTable()->CurrentScope())
{
}

void NamespaceCreatorVisitor::Visit(ColonColonNode& node)
{
    if (first)
    {
        currentScope = &context->GetSymbolTable()->GlobalNs().GetScope();
        first = false;
    }
}

void NamespaceCreatorVisitor::Visit(IdentifierNode& node)
{
    first = false;
    context->GetSymbolTable()->BeginNamespace(&node, context);
    currentScope = context->GetSymbolTable()->CurrentScope();
}

void BeginNamespace(Node* node, Context* context)
{
    NamespaceCreatorVisitor visitor(context);
    node->Accept(visitor);
}

void EndNamespace(int level, Context* context)
{
    context->GetSymbolTable()->EndNamespace(level);
}

} // sngcpp::symbols
