// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Class.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Writer.hpp>
#include <sngcpp20/ast/Reader.hpp>

namespace sngcpp::ast {

ClassSpecifierNode::ClassSpecifierNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::classSpecifierNode, sourcePos_)
{
}

ClassSpecifierNode::ClassSpecifierNode(const SourcePos& sourcePos_, Node* classHead_) : SequenceNode(NodeKind::classSpecifierNode, sourcePos_), classHead(classHead_)
{
}

void ClassSpecifierNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ClassSpecifierNode::Write(Writer& writer)
{
    SequenceNode::Write(writer);
    writer.Write(classHead.get());
    writer.Write(lbPos);
    writer.Write(rbPos);
}

void ClassSpecifierNode::Read(Reader& reader)
{
    SequenceNode::Read(reader);
    classHead.reset(reader.ReadNode());
    lbPos = reader.ReadSourcePos();
    rbPos = reader.ReadSourcePos();
}

ClassHeadNode::ClassHeadNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::classHeadNode, sourcePos_)
{
}

ClassHeadNode::ClassHeadNode(const SourcePos& sourcePos_, Node* classKey_, Node* classHeadName_, Node* classVirtSpecifier_, Node* baseClause_, Node* attributes_) :
    CompoundNode(NodeKind::classHeadNode, sourcePos_), classKey(classKey_), classHeadName(classHeadName_), classVirtSpecifier(classVirtSpecifier_), baseClause(baseClause_), attributes(attributes_)
{
}

void ClassHeadNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ClassHeadNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(classKey.get());
    writer.Write(classHeadName.get());
    writer.Write(classVirtSpecifier.get());
    writer.Write(baseClause.get());
    writer.Write(attributes.get());
}

void ClassHeadNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    classKey.reset(reader.ReadNode()); 
    classHeadName.reset(reader.ReadNode());
    classVirtSpecifier.reset(reader.ReadNode());
    baseClause.reset(reader.ReadNode());
    attributes.reset(reader.ReadNode());
}

BaseClauseNode::BaseClauseNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::baseClauseNode, sourcePos_, nullptr)
{
}

BaseClauseNode::BaseClauseNode(const SourcePos& sourcePos_, Node* baseSpecifierList_) : UnaryNode(NodeKind::baseClauseNode, sourcePos_, baseSpecifierList_)
{
}

void BaseClauseNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

BaseSpecifierListNode::BaseSpecifierListNode(const SourcePos& sourcePos_) : ListNode(NodeKind::baseSpecifierListNode, sourcePos_)
{
}

void BaseSpecifierListNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

BaseSpecifierNode::BaseSpecifierNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::baseSpecifierNode, sourcePos_), virtualFirst(false)
{
}

BaseSpecifierNode::BaseSpecifierNode(const SourcePos& sourcePos_, Node* classOrDeclType_, Node* accessSpecifier_, Node* virtualSpecifier_, Node* attributes_, bool virtualFirst_) :
    CompoundNode(NodeKind::baseSpecifierNode, sourcePos_), classOrDeclType(classOrDeclType_), accessSpecifier(accessSpecifier_), virtualSpecifier(virtualSpecifier_), attributes(attributes_),
    virtualFirst(virtualFirst_)
{
}

void BaseSpecifierNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void BaseSpecifierNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(classOrDeclType.get());
    writer.Write(accessSpecifier.get());
    writer.Write(virtualSpecifier.get());
    writer.Write(attributes.get());
    writer.Write(virtualFirst);
}

void BaseSpecifierNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    classOrDeclType.reset(reader.ReadNode());
    accessSpecifier.reset(reader.ReadNode());
    virtualSpecifier.reset(reader.ReadNode());
    attributes.reset(reader.ReadNode());
    virtualFirst = reader.ReadBool();
}

BeginAccessGroupNode::BeginAccessGroupNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::beginAccessGroupNode, sourcePos_, nullptr)
{
}

BeginAccessGroupNode::BeginAccessGroupNode(const SourcePos& sourcePos_, Node* accessSpecifier_, const SourcePos& colonPos_) : 
    UnaryNode(NodeKind::beginAccessGroupNode, sourcePos_, accessSpecifier_), colonPos(colonPos_)
{
}

void BeginAccessGroupNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void BeginAccessGroupNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(colonPos);
}

void BeginAccessGroupNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    colonPos = reader.ReadSourcePos();
}

MemberDeclarationNode::MemberDeclarationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::memberDeclarationNode, sourcePos_)
{
}

MemberDeclarationNode::MemberDeclarationNode(const SourcePos& sourcePos_, Node* attributes_, Node* declSpecifiers_, Node* memberDeclarators_, Node* semicolon_) : 
    CompoundNode(NodeKind::memberDeclarationNode, sourcePos_), attributes(attributes_), declSpecifiers(declSpecifiers_), memberDeclarators(memberDeclarators_), semicolon(semicolon_)
{
}

void MemberDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void MemberDeclarationNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(attributes.get());
    writer.Write(declSpecifiers.get());
    writer.Write(memberDeclarators.get());
    writer.Write(semicolon.get());
}

void MemberDeclarationNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    attributes.reset(reader.ReadNode());
    declSpecifiers.reset(reader.ReadNode());
    memberDeclarators.reset(reader.ReadNode());
    semicolon.reset(reader.ReadNode());
}

MemberDeclaratorListNode::MemberDeclaratorListNode(const SourcePos& sourcePos_) : ListNode(NodeKind::memberDeclaratorListNode, sourcePos_)
{
}

void MemberDeclaratorListNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ConstructorNode::ConstructorNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::constructorNode, sourcePos_, nullptr, nullptr)
{
}

ConstructorNode::ConstructorNode(const SourcePos& sourcePos_, Node* constructorInitializer_, Node* compoundStatement_) : 
    BinaryNode(NodeKind::constructorNode, sourcePos_, constructorInitializer_, compoundStatement_)
{
}

void ConstructorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ConstructorInitializerNode::ConstructorInitializerNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::constructorInitializerNode, sourcePos_, nullptr)
{
}

ConstructorInitializerNode::ConstructorInitializerNode(const SourcePos& sourcePos_, Node* memberInitializerList_) :
    UnaryNode(NodeKind::constructorInitializerNode, sourcePos_, memberInitializerList_)
{
}

void ConstructorInitializerNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

MemberInitializerListNode::MemberInitializerListNode(const SourcePos& sourcePos_) : ListNode(NodeKind::memberInitializerListNode, sourcePos_)
{
}

void MemberInitializerListNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

MemberInitializerNode::MemberInitializerNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::memberInitializerNode, sourcePos_, nullptr, nullptr)
{
}

MemberInitializerNode::MemberInitializerNode(const SourcePos& sourcePos_, Node* id_, Node* initializer_) : BinaryNode(NodeKind::memberInitializerNode, sourcePos_, id_, initializer_)
{
}

void MemberInitializerNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

VirtSpecifierSequenceNode::VirtSpecifierSequenceNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::virtSpecifierSequenceNode, sourcePos_)
{
}

void VirtSpecifierSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ClassNode::ClassNode(const SourcePos& sourcePos_) : Node(NodeKind::classNode, sourcePos_)
{
}

void ClassNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

StructNode::StructNode(const SourcePos& sourcePos_) : Node(NodeKind::structNode, sourcePos_)
{
}

void StructNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

UnionNode::UnionNode(const SourcePos& sourcePos_) : Node(NodeKind::unionNode, sourcePos_)
{
}

void UnionNode::Accept(Visitor& visitor) 
{
    visitor.Visit(*this);
}

PublicNode::PublicNode(const SourcePos& sourcePos_) : Node(NodeKind::publicNode, sourcePos_)
{
}

void PublicNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ProtectedNode::ProtectedNode(const SourcePos& sourcePos_) : Node(NodeKind::protectedNode, sourcePos_)
{
}

void ProtectedNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

PrivateNode::PrivateNode(const SourcePos& sourcePos_) : Node(NodeKind::privateNode, sourcePos_)
{
}

void PrivateNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

VirtualNode::VirtualNode(const SourcePos& sourcePos_) : Node(NodeKind::virtualNode, sourcePos_)
{
}

void VirtualNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

OverrideNode::OverrideNode(const SourcePos& sourcePos_) : Node(NodeKind::overrideNode, sourcePos_)
{
}

void OverrideNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

FinalNode::FinalNode(const SourcePos& sourcePos_) : Node(NodeKind::finalNode, sourcePos_)
{
}

void FinalNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

PureSpecifierNode::PureSpecifierNode(const SourcePos& sourcePos_) : Node(NodeKind::pureSpecifierNode, sourcePos_)
{
}

PureSpecifierNode::PureSpecifierNode(const SourcePos& sourcePos_, const SourcePos& zeroPos_) : Node(NodeKind::pureSpecifierNode, sourcePos_), zeroPos(zeroPos_)
{
}

void PureSpecifierNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void PureSpecifierNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.Write(zeroPos);
}

void PureSpecifierNode::Read(Reader& reader)
{
    Node::Read(reader);
    zeroPos = reader.ReadSourcePos();
}

} // sngcpp::ast
