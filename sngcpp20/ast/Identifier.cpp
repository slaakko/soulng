// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Identifier.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Writer.hpp>
#include <sngcpp20/ast/Reader.hpp>

namespace sngcpp::ast {

IdentifierNode::IdentifierNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::identifierNode, sourcePos_)
{
}

IdentifierNode::IdentifierNode(const SourcePos& sourcePos_, const std::u32string& str_) : CompoundNode(NodeKind::identifierNode, sourcePos_), str(str_)
{
}

void IdentifierNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void IdentifierNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(str);
}

void IdentifierNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    str = reader.ReadStr();
}

UnnamedNode::UnnamedNode(const SourcePos& sourcePos_) : Node(NodeKind::unnamedNode, sourcePos_)
{
}

void UnnamedNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ColonColonNode::ColonColonNode(const SourcePos& sourcePos_) : Node(NodeKind::colonColonNode, sourcePos_)
{
}

void ColonColonNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

NestedNameSpecifierNode::NestedNameSpecifierNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::nestedNameSpecifierNode, sourcePos_)
{
}

void NestedNameSpecifierNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

QualifiedIdNode::QualifiedIdNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::qualifiedIdNode, sourcePos_, nullptr, nullptr)
{
}

QualifiedIdNode::QualifiedIdNode(const SourcePos& sourcePos_, Node* nns_, Node* unqualifiedId_) : BinaryNode(NodeKind::qualifiedIdNode, sourcePos_, nns_, unqualifiedId_)
{
}

void QualifiedIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

IdentifierListNode::IdentifierListNode(const SourcePos& sourcePos_) : ListNode(NodeKind::identifierListNode, sourcePos_)
{
}

void IdentifierListNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

QualifiedModuleIdNode::QualifiedModuleIdNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::qualifiedModuleIdNode, sourcePos_, nullptr, nullptr)
{
}

QualifiedModuleIdNode::QualifiedModuleIdNode(const SourcePos& sourcePos_, Node* left_, Node* right_, const SourcePos& dotPos_) : 
    BinaryNode(NodeKind::qualifiedModuleIdNode, sourcePos_, left_, right_), dotPos(dotPos_)
{
}

void QualifiedModuleIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void QualifiedModuleIdNode::Write(Writer& writer)
{
    BinaryNode::Write(writer);
    writer.Write(dotPos);
}

void QualifiedModuleIdNode::Read(Reader& reader)
{
    BinaryNode::Read(reader);
    dotPos = reader.ReadSourcePos();
}

DotNode::DotNode(const SourcePos& sourcePos_) : Node(NodeKind::dotNode, sourcePos_)
{
}

void DotNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} // namespace sngcpp::ast
