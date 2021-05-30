// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Template.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Template.hpp>

namespace sngcpp::symbols {

class TemplateCreatorVisitor : public DefaultVisitor
{
public:
    TemplateCreatorVisitor(Context* context_);
    void Visit(TemplateHeadNode& node);
    void Visit(TypeParameterNode& node) override;
private:
    Context* context;
};

TemplateCreatorVisitor::TemplateCreatorVisitor(Context* context_) : context(context_)
{
}

void TemplateCreatorVisitor::Visit(TemplateHeadNode& node)
{
    context->GetSymbolTable()->BeginTemplateDeclaration(&node, context);
    DefaultVisitor::Visit(node);
}

void TemplateCreatorVisitor::Visit(TypeParameterNode& node)
{
    if (node.Identifier())
    {
        context->GetSymbolTable()->AddTemplateParameter(node.Identifier(), context);
    }
}

void BeginTemplateDeclaration(Node* templateHeadNode, Context* context)
{
    TemplateCreatorVisitor visitor(context);
    templateHeadNode->Accept(visitor);
}

void EndTemplateDeclaration(Context* context)
{
    context->GetSymbolTable()->EndTemplateDeclaration();
}

} // sngcpp::symbols
