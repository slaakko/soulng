// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Class.hpp>

namespace sngcpp::ast {

ClassSpecifierNode::ClassSpecifierNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::classSpecifierNode, sourcePos_)
{
}

ClassSpecifierNode::ClassSpecifierNode(const SourcePos& sourcePos_, Node* classHead_) : SequenceNode(NodeKind::classSpecifierNode, sourcePos_), classHead(classHead_)
{
}

ClassHeadNode::ClassHeadNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::classHeadNode, sourcePos_)
{
}

ClassHeadNode::ClassHeadNode(const SourcePos& sourcePos_, Node* classKey_, Node* classHeadName_, Node* classVirtSpecifier_, Node* baseClause_, Node* attributes_) :
    CompoundNode(NodeKind::classHeadNode, sourcePos_), classKey(classKey_), classHeadName(classHeadName_), classVirtSpecifier(classVirtSpecifier_), baseClause(baseClause_), attributes(attributes_)
{
}

BaseClauseNode::BaseClauseNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::baseClauseNode, sourcePos_, nullptr)
{
}

BaseClauseNode::BaseClauseNode(const SourcePos& sourcePos_, Node* baseSpecifierList_) : UnaryNode(NodeKind::baseClauseNode, sourcePos_, baseSpecifierList_)
{
}

BaseSpecifierListNode::BaseSpecifierListNode(const SourcePos& sourcePos_) : ListNode(NodeKind::baseSpecifierListNode, sourcePos_)
{
}

BaseSpecifierNode::BaseSpecifierNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::baseSpecifierNode, sourcePos_)
{
}

BaseSpecifierNode::BaseSpecifierNode(const SourcePos& sourcePos_, Node* classOrDeclType_, Node* accessSpecifier_, Node* virtualSpecifier_, Node* attributes_) :
    CompoundNode(NodeKind::baseSpecifierNode, sourcePos_), classOrDeclType(classOrDeclType_), accessSpecifier(accessSpecifier_), virtualSpecifier(virtualSpecifier_), attributes(attributes_)
{
}

BeginAccessGroupNode::BeginAccessGroupNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::beginAccessGroupNode, sourcePos_, nullptr)
{
}

BeginAccessGroupNode::BeginAccessGroupNode(const SourcePos& sourcePos_, Node* accessSpecifier_, const SourcePos& colonPos_) : 
    UnaryNode(NodeKind::beginAccessGroupNode, sourcePos_, accessSpecifier_), colonPos(colonPos_)
{
}

MemberDeclarationNode::MemberDeclarationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::memberDeclarationNode, sourcePos_)
{
}

MemberDeclarationNode::MemberDeclarationNode(const SourcePos& sourcePos_, Node* attributes_, Node* declSpecifiers_, Node* memberDeclarators_, Node* semicolon_) : 
    CompoundNode(NodeKind::memberDeclarationNode, sourcePos_), attributes(attributes_), declSpecifiers(declSpecifiers_), memberDeclarators(memberDeclarators_), semicolon(semicolon_)
{
}

MemberDeclaratorListNode::MemberDeclaratorListNode(const SourcePos& sourcePos_) : ListNode(NodeKind::memberDeclaratorListNode, sourcePos_)
{
}

ConstructorNode::ConstructorNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::constructorNode, sourcePos_, nullptr, nullptr)
{
}

ConstructorNode::ConstructorNode(const SourcePos& sourcePos_, Node* constructorInitializer_, Node* compoundStatement_) : 
    BinaryNode(NodeKind::constructorNode, sourcePos_, constructorInitializer_, compoundStatement_)
{
}

ConstructorInitializerNode::ConstructorInitializerNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::constructorInitializerNode, sourcePos_, nullptr)
{
}

ConstructorInitializerNode::ConstructorInitializerNode(const SourcePos& sourcePos_, Node* memberInitializerList_) :
    UnaryNode(NodeKind::constructorInitializerNode, sourcePos_, memberInitializerList_)
{
}

MemberInitializerListNode::MemberInitializerListNode(const SourcePos& sourcePos_) : ListNode(NodeKind::memberInitializerListNode, sourcePos_)
{
}

MemberInitializerNode::MemberInitializerNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::memberInitializerNode, sourcePos_, nullptr, nullptr)
{
}

MemberInitializerNode::MemberInitializerNode(const SourcePos& sourcePos_, Node* id_, Node* initializer_) : BinaryNode(NodeKind::memberInitializerNode, sourcePos_, id_, initializer_)
{
}

VirtSpecifierSequenceNode::VirtSpecifierSequenceNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::virtSpecifierSequenceNode, sourcePos_)
{
}

ClassNode::ClassNode(const SourcePos& sourcePos_) : Node(NodeKind::classNode, sourcePos_)
{
}

StructNode::StructNode(const SourcePos& sourcePos_) : Node(NodeKind::structNode, sourcePos_)
{
}

UnionNode::UnionNode(const SourcePos& sourcePos_) : Node(NodeKind::unionNode, sourcePos_)
{
}

PublicNode::PublicNode(const SourcePos& sourcePos_) : Node(NodeKind::publicNode, sourcePos_)
{
}

ProtectedNode::ProtectedNode(const SourcePos& sourcePos_) : Node(NodeKind::protectedNode, sourcePos_)
{
}

PrivateNode::PrivateNode(const SourcePos& sourcePos_) : Node(NodeKind::privateNode, sourcePos_)
{
}

VirtualNode::VirtualNode(const SourcePos& sourcePos_) : Node(NodeKind::virtualNode, sourcePos_)
{
}

OverrideNode::OverrideNode(const SourcePos& sourcePos_) : Node(NodeKind::overrideNode, sourcePos_)
{
}

FinalNode::FinalNode(const SourcePos& sourcePos_) : Node(NodeKind::finalNode, sourcePos_)
{
}

PureSpecifierNode::PureSpecifierNode(const SourcePos& sourcePos_) : Node(NodeKind::pureSpecifierNode, sourcePos_)
{
}

PureSpecifierNode::PureSpecifierNode(const SourcePos& sourcePos_, const SourcePos& zeroPos_) : Node(NodeKind::pureSpecifierNode, sourcePos_), zeroPos(zeroPos_)
{
}

} // sngcpp::ast
