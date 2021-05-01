// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Concept.hpp>

namespace sngcpp::ast {

ConceptDefinitioNode::ConceptDefinitioNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::conceptDefinitionNode, sourcePos_)
{
}

ConceptDefinitioNode::ConceptDefinitioNode(const SourcePos& sourcePos_, Node* conceptName_, Node* assign_, Node* constraintExpr_) :
    CompoundNode(NodeKind::conceptDefinitionNode, sourcePos_), conceptName(conceptName_), assign(assign_), constraintExpr(constraintExpr_)
{
}

RequiresExprNode::RequiresExprNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::requiresExprNode, sourcePos_)
{
}

RequiresExprNode::RequiresExprNode(const SourcePos& sourcePos_, Node* params_, Node* body_) : CompoundNode(NodeKind::requiresExprNode, sourcePos_), params(params_), body(body_)
{
}

RequirementBodyNode::RequirementBodyNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::requirementBodyNode, sourcePos_)
{
}

void RequirementBodyNode::SetLBracePos(const SourcePos& lbPos_)
{
    lbPos = lbPos_;
}

void RequirementBodyNode::SetRBracePos(const SourcePos& rbPos_)
{
    rbPos = rbPos_;
}

SimpleRequirementNode::SimpleRequirementNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::simpleRequirementNode, sourcePos_, nullptr, nullptr)
{
}

SimpleRequirementNode::SimpleRequirementNode(const SourcePos& sourcePos_, Node* expr_, Node* semicolon_) : BinaryNode(NodeKind::simpleRequirementNode, sourcePos_, expr_, semicolon_)
{
}

TypeRequirementNode::TypeRequirementNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::typeRequirementNode, sourcePos_)
{
}

TypeRequirementNode::TypeRequirementNode(const SourcePos& sourcePos_, Node* nns_, Node* typeName_, Node* semicolon_) : 
    CompoundNode(NodeKind::typeRequirementNode, sourcePos_), nns(nns_), typeName(typeName_), semicolon(semicolon_)
{
}

CompoundRequirementNode::CompoundRequirementNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::compoundRequirementNode, sourcePos_)
{
}

CompoundRequirementNode::CompoundRequirementNode(const SourcePos& sourcePos_, Node* expr_, Node* noexcept_, Node* returnTypeRequirement_, Node* semicolon_, 
    const SourcePos& lbPos_, const SourcePos& rbPos_) :
    CompoundNode(NodeKind::compoundRequirementNode, sourcePos_), expr(expr_), noexceptNode(noexcept_), returnTypeRequirement(returnTypeRequirement_), semicolon(semicolon_), lbPos(lbPos_), rbPos(rbPos_)
{
}

ReturnTypeRequirementNode::ReturnTypeRequirementNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::returnTypeRequirementNode, sourcePos_, nullptr)
{
}

ReturnTypeRequirementNode::ReturnTypeRequirementNode(const SourcePos& sourcePos_, Node* typeConstraint_) : UnaryNode(NodeKind::returnTypeRequirementNode, sourcePos_, typeConstraint_)
{
}

NestedRequirementNode::NestedRequirementNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::nestedRequirementNode, sourcePos_, nullptr, nullptr)
{
}

NestedRequirementNode::NestedRequirementNode(const SourcePos& sourcePos_, Node* constraintExpression_, Node* semicolon_) : 
    BinaryNode(NodeKind::nestedRequirementNode, sourcePos_, constraintExpression_, semicolon_)
{
}

TypeConstraintNode::TypeConstraintNode(const SourcePos& sourcePos_) : ListNode(NodeKind::typeConstraintNode, sourcePos_), hasTemplateArgumentList(false)
{
}

TypeConstraintNode::TypeConstraintNode(const SourcePos& sourcePos_, Node* conceptName_) : ListNode(NodeKind::typeConstraintNode, sourcePos_), conceptName(conceptName_), hasTemplateArgumentList(false)
{
}

void TypeConstraintNode::SetLAnglePos(const SourcePos& laPos_)
{
    laPos = laPos_;
}

void TypeConstraintNode::SetRAnglePos(const SourcePos& raPos_)
{
    raPos = raPos_;
}

RequiresClauseNode::RequiresClauseNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::requiresClauseNode, sourcePos_, nullptr)
{
}

RequiresClauseNode::RequiresClauseNode(const SourcePos& sourcePos_, Node* constraintLogicalOrExpr_) : UnaryNode(NodeKind::requiresClauseNode, sourcePos_, constraintLogicalOrExpr_)
{
}

} // sngcpp::ast
