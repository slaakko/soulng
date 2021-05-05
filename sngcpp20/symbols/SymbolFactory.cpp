// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/SymbolFactory.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/ast/Visitor.hpp>

namespace sngcpp::symbols {

class SYMBOLS_API ClassCreatorVisitor : public DefaultVisitor
{
public:
    ClassCreatorVisitor(Context* context_);
    void Visit(IdentifierNode& node) override;
    void Visit(UnnamedNode& node) override;
private:
    Context* context;
};

ClassCreatorVisitor::ClassCreatorVisitor(Context* context_) : context(context_)
{
}

void ClassCreatorVisitor::Visit(IdentifierNode& node)
{
    context->GetSymbolTable()->BeginClass(&node);
}

void ClassCreatorVisitor::Visit(UnnamedNode& node)
{
    context->GetSymbolTable()->BeginClass(&node);
}

void BeginClass(Node* node, Context* context)
{
    ClassCreatorVisitor visitor(context);
    node->Accept(visitor);
}

void EndClass(Context* context)
{
    context->GetSymbolTable()->EndClass();
}

} // sngcpp::symbols
