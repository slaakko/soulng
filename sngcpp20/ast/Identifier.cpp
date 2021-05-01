// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Identifier.hpp>

namespace sngcpp::ast {

IdentifierNode::IdentifierNode(const SourcePos& sourcePos_, const std::u32string& id_) : Node(NodeKind::identifierNode, sourcePos_), id(id_)
{
}

ColonColonNode::ColonColonNode(const SourcePos& sourcePos_) : Node(NodeKind::colonColonNode, sourcePos_)
{
}

NestedNameSpecifierNode::NestedNameSpecifierNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::nestedNameSpecifierNode, sourcePos_)
{
}

QualifiedIdNode::QualifiedIdNode(const SourcePos& sourcePos_, Node* nns_, Node* unqualifiedId_) : BinaryNode(NodeKind::qualifiedIdNode, sourcePos_, nns_, unqualifiedId_)
{
}

IdentifierListNode::IdentifierListNode(const SourcePos& sourcePos_) : ListNode(NodeKind::identifierListNode, sourcePos_)
{
}

QualifiedModuleIdNode::QualifiedModuleIdNode(const SourcePos& sourcePos_, Node* left_, Node* right_, const SourcePos& dotPos_) : 
    BinaryNode(NodeKind::qualifiedModuleIdNode, sourcePos_, left_, right_), dotPos(dotPos_)
{
}

DotNode::DotNode(const SourcePos& sourcePos_) : Node(NodeKind::dotNode, sourcePos_)
{
}

} // namespace sngcpp::ast
