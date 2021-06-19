// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Template.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/symbols/DeclarationProcessor.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Template.hpp>

namespace sngcpp::symbols {

class TemplateCreatorVisitor : public DefaultVisitor
{
public:
    TemplateCreatorVisitor(Context* context_);
    void Visit(TemplateHeadNode& node) override;
    void Visit(TypenameNode& node) override;
    void Visit(ClassNode& node) override;
    void Visit(ParameterNode& node) override;
    void Visit(TypeParameterNode& node) override;
private:
    Context* context;
    Symbol* constraint;
    int index;
};

TemplateCreatorVisitor::TemplateCreatorVisitor(Context* context_) : context(context_), constraint(nullptr), index(0)
{
}

void TemplateCreatorVisitor::Visit(TemplateHeadNode& node)
{
    context->GetSymbolTable()->BeginTemplateDeclaration(&node, context);
    DefaultVisitor::Visit(node);
}

void TemplateCreatorVisitor::Visit(TypenameNode& node)
{
    constraint = context->GetSymbolTable()->MakeTypeNameConstraintSymbol();
}

void TemplateCreatorVisitor::Visit(ClassNode& node)
{
    constraint = context->GetSymbolTable()->MakeTypeNameConstraintSymbol();
}

void TemplateCreatorVisitor::Visit(ParameterNode& node)
{
    std::unique_ptr<ParameterSymbol> parameterSymbol(ProcessParameter(&node, context));
    context->GetSymbolTable()->AddTemplateParameter(&node, parameterSymbol->Name(), parameterSymbol->Type(), index++, context);
}

void TemplateCreatorVisitor::Visit(TypeParameterNode& node)
{
    node.TypeConstraint()->Accept(*this);
    if (node.Identifier())
    {
        context->GetSymbolTable()->AddTemplateParameter(node.Identifier(), node.Identifier()->Str(), constraint, index++, context);
    }
}

void BeginTemplateDeclaration(Node* templateHeadNode, Context* context)
{
    TemplateCreatorVisitor visitor(context);
    templateHeadNode->Accept(visitor);
    context->PushSetFlag(ContextFlags::parsingTemplateDeclaration);
}

void EndTemplateDeclaration(Context* context)
{
    context->PopFlags();
    context->GetSymbolTable()->EndTemplateDeclaration();
}

} // sngcpp::symbols
