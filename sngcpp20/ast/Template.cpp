// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Template.hpp>

namespace sngcpp::ast {

TemplateHeadNode::TemplateHeadNode(const SourcePos& sourcePos_, Node* templateParamList_, Node* requiresClause_) : 
    CompoundNode(NodeKind::templateHeadNode, sourcePos_)
{
}

TemplateParameterListNode::TemplateParameterListNode(const SourcePos& sourcePos_) : ListNode(NodeKind::templateParameterListNode, sourcePos_)
{
}

TypeParameterNode::TypeParameterNode(const SourcePos& sourcePos_, Node* typeConstraint_, Node* identifier_, Node* assign_, Node* typeId_, Node* ellipses_, Node* templateHead_) :
    CompoundNode(NodeKind::typeParameterNode, sourcePos_), typeConstraint(typeConstraint_), identifier(identifier_), assign(assign_), typeId(typeId_), ellipses(ellipses_), templateHead(templateHead_)
{
}

TemplateIdNode::TemplateIdNode(const SourcePos& sourcePos_, Node* templateName_) : ListNode(NodeKind::templateIdNode, sourcePos_), templateName(templateName_)
{
}

TypenameNode::TypenameNode(const SourcePos& sourcePos_) : Node(NodeKind::typenameNode, sourcePos_)
{
}

DeductionGuideNode::DeductionGuideNode(const SourcePos& sourcePos_, Node* templateName_, Node* params_, Node* arrow_, Node* templateId_, Node* explicitSpecifier_, Node* semicolon_,
    const SourcePos& lpPos_, const SourcePos& rpPos_) :
    CompoundNode(NodeKind::deductionGuideNode, sourcePos_), templateName(templateName_), params(params_), arrow(arrow_), explicitSpecifier(explicitSpecifier_), semicolon(semicolon_), 
    lpPos(lpPos_), rpPos(rpPos_)
{
}

ExplicitInstantiationNode::ExplicitInstantiationNode(const SourcePos& sourcePos_, Node* extrn_, Node* tmp_, Node* declaration_) : 
    CompoundNode(NodeKind::explicitInstantiationNode, sourcePos_), extrn(extrn_), tmp(tmp_), declaration(declaration_)
{
}

TemplateNode::TemplateNode(const SourcePos& sourcePos_) : Node(NodeKind::templateNode, sourcePos_)
{
}

ExplicitSpecializationNode::ExplicitSpecializationNode(const SourcePos& sourcePos_, Node* tmp_, Node* declaration_, const SourcePos& laPos_, const SourcePos& raPos_) :
    CompoundNode(NodeKind::explicitSpecializationNode, sourcePos_), tmp(tmp_), declaration(declaration_), laPos(laPos_), raPos(raPos_)
{
}

} // namespace sngcpp::ast
