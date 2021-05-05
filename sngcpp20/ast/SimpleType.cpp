// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/SimpleType.hpp>
#include <sngcpp20/ast/Visitor.hpp>

namespace sngcpp::ast {

CharNode::CharNode(const SourcePos& sourcePos_) : Node(NodeKind::charNode, sourcePos_)
{
}

void CharNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

Char8Node::Char8Node(const SourcePos& sourcePos_) : Node(NodeKind::char8Node, sourcePos_)
{
}

void Char8Node::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

Char16Node::Char16Node(const SourcePos& sourcePos_) : Node(NodeKind::char16Node, sourcePos_)
{
}

void Char16Node::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

Char32Node::Char32Node(const SourcePos& sourcePos_) : Node(NodeKind::char32Node, sourcePos_)
{
}

void Char32Node::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

WCharNode::WCharNode(const SourcePos& sourcePos_) : Node(NodeKind::wcharNode, sourcePos_)
{
}

void WCharNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

BoolNode::BoolNode(const SourcePos& sourcePos_) : Node(NodeKind::boolNode, sourcePos_)
{
}

void BoolNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ShortNode::ShortNode(const SourcePos& sourcePos_) : Node(NodeKind::shortNode, sourcePos_)
{
}

void ShortNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

IntNode::IntNode(const SourcePos& sourcePos_) : Node(NodeKind::intNode, sourcePos_)
{
}

void IntNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

LongNode::LongNode(const SourcePos& sourcePos_) : Node(NodeKind::longNode, sourcePos_)
{
}

void LongNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

SignedNode::SignedNode(const SourcePos& sourcePos_) : Node(NodeKind::signedNode, sourcePos_)
{
}

void SignedNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

UnsignedNode::UnsignedNode(const SourcePos& sourcePos_) : Node(NodeKind::unsignedNode, sourcePos_)
{
}

void UnsignedNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

FloatNode::FloatNode(const SourcePos& sourcePos_) : Node(NodeKind::floatNode, sourcePos_)
{
}

void FloatNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

DoubleNode::DoubleNode(const SourcePos& sourcePos_) : Node(NodeKind::doubleNode, sourcePos_)
{
}

void DoubleNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

VoidNode::VoidNode(const SourcePos& sourcePos_) : Node(NodeKind::voidNode, sourcePos_)
{
}

void VoidNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} // namespace sngcpp::ast
