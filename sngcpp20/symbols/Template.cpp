// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Template.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/symbols/DeclarationProcessor.hpp>
#include <sngcpp20/symbols/ClassGroupSymbol.hpp>
#include <sngcpp20/symbols/ClassTypeSymbol.hpp>
#include <sngcpp20/symbols/AliasGroupSymbol.hpp>
#include <sngcpp20/symbols/AliasTypeSymbol.hpp>
#include <sngcpp20/symbols/VariableGroupSymbol.hpp>
#include <sngcpp20/symbols/VariableSymbol.hpp>
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
    context->GetSymbolTable()->RemoveTemplateDeclaration();
}

void AddTemplateParameter(Node* templateParameterNode, int index, Context* context)
{
    TemplateParameterCreatorVisitor visitor(index, context);
    templateParameterNode->Accept(visitor);
}

class SetTemplateArgKindVisitor : public DefaultVisitor
{
public:
    SetTemplateArgKindVisitor(Context* context_);
    void Visit(TemplateIdNode& node) override;
    void Visit(IdentifierNode& node) override;
    void Visit(TemplateParameterListNode& node) override;
    void Visit(TypeParameterNode& node) override;
    void Visit(ParameterNode& node) override;
private:
    Context* context;
    bool visitingTemplateParameters;
    std::vector<bool> templateArgKinds;
};

SetTemplateArgKindVisitor::SetTemplateArgKindVisitor(Context* context_) : context(context_), visitingTemplateParameters(false)
{
}

void SetTemplateArgKindVisitor::Visit(TemplateIdNode& node)
{
    node.TemplateName()->Accept(*this);
    node.SetTemplateArgKinds(templateArgKinds);
}

void SetTemplateArgKindVisitor::Visit(IdentifierNode& node)
{
    Symbol* symbol = context->GetSymbolTable()->Lookup(node.Str(), SymbolGroupKind::typeSymbolGroup | SymbolGroupKind::variableSymbolGroup, node.GetSourcePos(), context);
    if (symbol)
    {
        if (symbol->Kind() == SymbolKind::classGroupSymbol)
        {
            ClassGroupSymbol* classGroup = static_cast<ClassGroupSymbol*>(symbol);
            ClassTypeSymbol* classTemplate = classGroup->GetClassTemplate();
            if (classTemplate)
            {
                TemplateDeclarationSymbol* templateDeclarationSymbol = classTemplate->GetTemplateDeclarationSymbol();
                if (templateDeclarationSymbol)
                {
                    Node* n = context->GetSymbolTable()->GetNodeNothrow(templateDeclarationSymbol);
                    if (n)
                    {
                        if (n->Kind() == NodeKind::templateHeadNode)
                        {
                            TemplateHeadNode* templateHeadNode = static_cast<TemplateHeadNode*>(n);
                            templateHeadNode->TemplateParamList()->Accept(*this);
                        }
                    }
                }
            }
        }
        else if (symbol->Kind() == SymbolKind::aliasGroupSymbol)
        {
            AliasGroupSymbol* aliasGroup = static_cast<AliasGroupSymbol*>(symbol);
            AliasTypeSymbol* aliasTemplate = aliasGroup->AliasTypeTemplate();
            if (aliasTemplate)
            {
                TemplateDeclarationSymbol* templateDeclarationSymbol = aliasTemplate->GetTemplateDeclarationSymbol();
                if (templateDeclarationSymbol)
                {
                    Node* n = context->GetSymbolTable()->GetNodeNothrow(templateDeclarationSymbol);
                    if (n)
                    {
                        if (n->Kind() == NodeKind::templateHeadNode)
                        {
                            TemplateHeadNode* templateHeadNode = static_cast<TemplateHeadNode*>(n);
                            templateHeadNode->TemplateParamList()->Accept(*this);
                        }
                    }
                }
            }
        }
        else if (symbol->Kind() == SymbolKind::variableGroupSymbol)
        {
            VariableGroupSymbol* variableGroup = static_cast<VariableGroupSymbol*>(symbol);
            VariableSymbol* variableTemplate = variableGroup->GetVariableTemplate();
            if (variableTemplate)
            {
                TemplateDeclarationSymbol* templateDeclarationSymbol = variableTemplate->GetTemplateDeclarationSymbol();
                if (templateDeclarationSymbol)
                {
                    Node* n = context->GetSymbolTable()->GetNodeNothrow(templateDeclarationSymbol);
                    if (n)
                    {
                        if (n->Kind() == NodeKind::templateHeadNode)
                        {
                            TemplateHeadNode* templateHeadNode = static_cast<TemplateHeadNode*>(n);
                            templateHeadNode->TemplateParamList()->Accept(*this);
                        }
                    }
                }
            }
        }
    }
}

void SetTemplateArgKindVisitor::Visit(TemplateParameterListNode& node)
{
    visitingTemplateParameters = true;
    VisitListContent(node);
    visitingTemplateParameters = false;
}

void SetTemplateArgKindVisitor::Visit(TypeParameterNode& node)
{
    if (visitingTemplateParameters)
    {
        templateArgKinds.push_back(true);
    }
}

void SetTemplateArgKindVisitor::Visit(ParameterNode& node)
{
    if (visitingTemplateParameters)
    {
        templateArgKinds.push_back(false);
    }
}

void SetTemplateArgKinds(Node* templateIdNode, Context* context)
{
    SetTemplateArgKindVisitor visitor(context);
    templateIdNode->Accept(visitor);
}

class GetTemplateArgKindVisitor : public DefaultVisitor
{
public:
    GetTemplateArgKindVisitor(int index_);
    void Visit(TemplateIdNode& node) override;
    bool CanBeTypeid() const { return canBeTypeId; }
private:
    int index;
    bool canBeTypeId;
};

GetTemplateArgKindVisitor::GetTemplateArgKindVisitor(int index_) : index(index_), canBeTypeId(true)
{
}

void GetTemplateArgKindVisitor::Visit(TemplateIdNode& node)
{
    if (index >= 0 && index < node.TemplateArgKinds().size())
    {
        canBeTypeId = node.TemplateArgKinds()[index];
    }
}

bool TemplateArgCanBeTypeId(Node* templateIdNode, int index)
{
    GetTemplateArgKindVisitor visitor(index);
    templateIdNode->Accept(visitor);
    return visitor.CanBeTypeid();
}

} // sngcpp::symbols
