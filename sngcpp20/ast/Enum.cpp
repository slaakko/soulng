// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Enum.hpp>

namespace sngcpp::ast {

EnumSpecifierNode::EnumSpecifierNode(const SourcePos& sourcePos_) : ListNode(NodeKind::enumSpecifierNode, sourcePos_)
{
}

EnumSpecifierNode::EnumSpecifierNode(const SourcePos& sourcePos_, Node* enumHead_) : ListNode(NodeKind::enumSpecifierNode, sourcePos_), enumHead(enumHead_)
{
}

EnumHeadNode::EnumHeadNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::enumHeadNode, sourcePos_)
{
}

EnumHeadNode::EnumHeadNode(const SourcePos& sourcePos_, Node* enumKey_, Node* enumHeadName_, Node* enumBase_, Node* attributes_) :
    CompoundNode(NodeKind::enumHeadNode, sourcePos_), enumKey(enumKey_), enumHeadName(enumHeadName_), enumBase(enumBase_), attributes(attributes_)
{
}

EnumBaseNode::EnumBaseNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::enumBaseNode, sourcePos_, nullptr)
{
}

EnumBaseNode::EnumBaseNode(const SourcePos& sourcePos_, Node* typeSpecifiers_) : UnaryNode(NodeKind::enumBaseNode, sourcePos_, typeSpecifiers_)
{
}

EnumClassNode::EnumClassNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::enumClassNode, sourcePos_)
{
}

EnumClassNode::EnumClassNode(const SourcePos& sourcePos_, const SourcePos& classPos_) : CompoundNode(NodeKind::enumClassNode, sourcePos_), classPos(classPos_)
{
}

EnumStructNode::EnumStructNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::enumStructNode, sourcePos_)
{
}

EnumStructNode::EnumStructNode(const SourcePos& sourcePos_, const SourcePos& structPos_) : CompoundNode(NodeKind::enumStructNode, sourcePos_), structPos(structPos_)
{
}

EnumNode::EnumNode(const SourcePos& sourcePos_) : Node(NodeKind::enumNode, sourcePos_)
{
}

EnumeratorDefinitionNode::EnumeratorDefinitionNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::enumeratorDefinitionNode, sourcePos_)
{
}

EnumeratorDefinitionNode::EnumeratorDefinitionNode(const SourcePos& sourcePos_, Node* enumerator_, Node* value_, const SourcePos& assignPos_) :
    CompoundNode(NodeKind::enumeratorDefinitionNode, sourcePos_), enumerator(enumerator_), value(value_), assignPos(assignPos_)
{
}

EnumeratorNode::EnumeratorNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::enumeratorNode, sourcePos_)
{
}

EnumeratorNode::EnumeratorNode(const SourcePos& sourcePos_, Node* identifier_, Node* attributes_) :
    CompoundNode(NodeKind::enumeratorNode, sourcePos_), identifier(identifier_), attributes(attributes_)
{
}

ElaboratedEnumSpecifierNode::ElaboratedEnumSpecifierNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::elaboratedEnumSpecifierNode, sourcePos_, nullptr)
{
}

ElaboratedEnumSpecifierNode::ElaboratedEnumSpecifierNode(const SourcePos& sourcePos_, Node* enumName_) : 
    UnaryNode(NodeKind::elaboratedEnumSpecifierNode, sourcePos_, enumName_)
{
}

OpaqueEnumDeclarationNode::OpaqueEnumDeclarationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::opaqueEnumDeclarationNode, sourcePos_)
{
}

OpaqueEnumDeclarationNode::OpaqueEnumDeclarationNode(const SourcePos& sourcePos_, Node* enumKey_, Node* enumHeadName_, Node* enumBase_, Node* attributes_, Node* semicolon_) :
    CompoundNode(NodeKind::opaqueEnumDeclarationNode, sourcePos_), enumKey(enumKey_), enumHeadName(enumHeadName_), enumBase(enumBase_), attributes(attributes_), semicolon(semicolon_)
{
}

} // sngcpp::ast
