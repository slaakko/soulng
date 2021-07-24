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
private:
    Context* context;
};

class TemplateParameterCreatorVisitor : public DefaultVisitor
{
public:
    TemplateParameterCreatorVisitor(int index_, Context* context_);
    void Visit(TypenameNode& node) override;
    void Visit(ClassNode& node) override;
    void Visit(ParameterNode& node) override;
    void Visit(TypeParameterNode& node) override;
private:
    Context* context;
    Symbol* constraint;
    int index;
};

TemplateCreatorVisitor::TemplateCreatorVisitor(Context* context_) : context(context_)
{
}

void TemplateCreatorVisitor::Visit(TemplateHeadNode& node)
{
    context->GetSymbolTable()->BeginTemplateDeclaration(&node, context);
}

TemplateParameterCreatorVisitor::TemplateParameterCreatorVisitor(int index_, Context* context_) : context(context_), constraint(nullptr), index(index_)
{
}

void TemplateParameterCreatorVisitor::Visit(TypenameNode& node)
{
    constraint = context->GetSymbolTable()->MakeTypeNameConstraintSymbol();
}

void TemplateParameterCreatorVisitor::Visit(ClassNode& node)
{
    constraint = context->GetSymbolTable()->MakeTypeNameConstraintSymbol();
}

void TemplateParameterCreatorVisitor::Visit(ParameterNode& node)
{
    std::unique_ptr<ParameterSymbol> parameterSymbol(ProcessParameter(&node, context));
    context->GetSymbolTable()->AddTemplateParameter(&node, parameterSymbol->Name(), parameterSymbol->Type(), index, context);
}

void TemplateParameterCreatorVisitor::Visit(TypeParameterNode& node)
{
    node.TypeConstraint()->Accept(*this);
    if (node.Identifier())
    {
        context->GetSymbolTable()->AddTemplateParameter(node.Identifier(), node.Identifier()->Str(), constraint, index++, context);
    }
    else
    {
        context->GetSymbolTable()->AddTemplateParameter(nullptr, U"", constraint, index++, context);
    }
}

void BeginTemplateDeclaration(Node* templateHeadNode, Context* context)
{
    if (templateHeadNode->GetSourcePos().line == 11717)
    {
        int x = 0;
    }
    TemplateCreatorVisitor visitor(context);
    templateHeadNode->Accept(visitor);
    context->PushSetFlag(ContextFlags::parsingTemplateDeclaration);
}

void EndTemplateDeclaration(Context* context)
{
    context->PopFlags();
    context->GetSymbolTable()->EndTemplateDeclaration();
}

void RemoveTemplateDeclaration(Context* context)
{
    int x = 0;
}

void AddTemplateParameter(Node* templateParameterNode, int index, Context* context)
{
    TemplateParameterCreatorVisitor visitor(index, context);
    templateParameterNode->Accept(visitor);
}

} // sngcpp::symbols
