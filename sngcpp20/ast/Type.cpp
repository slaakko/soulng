// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Type.hpp>

namespace sngcpp::ast {

TypeSpecifierSequenceNode::TypeSpecifierSequenceNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::typeSpecifierSequenceNode, sourcePos_)
{
}

TypenameSpecifierNode::TypenameSpecifierNode(const SourcePos& sourcePos_, Node* nns_, Node* id_, Node* templateNode_) :
    CompoundNode(NodeKind::typenameSpecifierNode, sourcePos_), nns(nns_), id(id_), templateNode(templateNode_)
{
}

TypeIdNode::TypeIdNode(const SourcePos& sourcePos_, Node* typeSpecifiers_, Node* declarator_) :
    CompoundNode(NodeKind::typeIdNode, sourcePos_), typeSpecifiers(typeSpecifiers_), declarator(declarator_)
{
}

DefiningTypeIdNode::DefiningTypeIdNode(const SourcePos& sourcePos_, Node* definingTypeSpecifiers_, Node* abstractDeclarator_) :
    CompoundNode(NodeKind::definingTypeIdNode, sourcePos_), definingTypeSpecifiers(definingTypeSpecifiers_), abstractDeclarator(abstractDeclarator_)
{
}

DefiningTypeSpecifierSequenceNode::DefiningTypeSpecifierSequenceNode(const SourcePos& sourcePos_) :
    SequenceNode(NodeKind::definingTypeSpecifierSequenceNode, sourcePos_)
{
}

TrailingReturnTypeNode::TrailingReturnTypeNode(const SourcePos& sourcePos_, Node* typeId_) : UnaryNode(NodeKind::trailingReturnTypeNode, sourcePos_, typeId_)
{
}

ElaboratedTypeSpecifierNode::ElaboratedTypeSpecifierNode(const SourcePos& sourcePos_, Node* classKey_, Node* id_, Node* attributes_) :
    CompoundNode(NodeKind::elaboratedTypeSpecifierNode, sourcePos_), classKey(classKey_), id(id_), attributes(attributes_)
{
}

DeclTypeSpecifierNode::DeclTypeSpecifierNode(const SourcePos& sourcePos_, Node* expr_, const SourcePos& lpPos_, const SourcePos& rpPos_) :
    CompoundNode(NodeKind::declTypeSpecifierNode, sourcePos_), expr(expr_), lpPos(lpPos_), rpPos(rpPos_)
{
}

PlaceholderTypeSpecifierNode::PlaceholderTypeSpecifierNode(const SourcePos& sourcePos_, Node* typeConstraint_, 
    const SourcePos& dtPos_, const SourcePos& autoPos_, const SourcePos& lpPos_, const SourcePos& rpPos_) :
    CompoundNode(NodeKind::placeholderTypeSpecifierNode, sourcePos_), typeConstraint(typeConstraint_), dtPos(dtPos_), autoPos(autoPos_), lpPos(lpPos_), rpPos(rpPos_)
{
}

} // namespace sngcpp::ast
