// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/SimpleType.hpp>

namespace sngcpp::ast {

CharNode::CharNode(const SourcePos& sourcePos_) : Node(NodeKind::charNode, sourcePos_)
{
}

Char8Node::Char8Node(const SourcePos& sourcePos_) : Node(NodeKind::char8Node, sourcePos_)
{
}

Char16Node::Char16Node(const SourcePos& sourcePos_) : Node(NodeKind::char16Node, sourcePos_)
{
}

Char32Node::Char32Node(const SourcePos& sourcePos_) : Node(NodeKind::char32Node, sourcePos_)
{
}

WCharNode::WCharNode(const SourcePos& sourcePos_) : Node(NodeKind::wcharNode, sourcePos_)
{
}

BoolNode::BoolNode(const SourcePos& sourcePos_) : Node(NodeKind::boolNode, sourcePos_)
{
}

ShortNode::ShortNode(const SourcePos& sourcePos_) : Node(NodeKind::shortNode, sourcePos_)
{
}

IntNode::IntNode(const SourcePos& sourcePos_) : Node(NodeKind::intNode, sourcePos_)
{
}

LongNode::LongNode(const SourcePos& sourcePos_) : Node(NodeKind::longNode, sourcePos_)
{
}

SignedNode::SignedNode(const SourcePos& sourcePos_) : Node(NodeKind::signedNode, sourcePos_)
{
}

UnsignedNode::UnsignedNode(const SourcePos& sourcePos_) : Node(NodeKind::unsignedNode, sourcePos_)
{
}

FloatNode::FloatNode(const SourcePos& sourcePos_) : Node(NodeKind::floatNode, sourcePos_)
{
}

DoubleNode::DoubleNode(const SourcePos& sourcePos_) : Node(NodeKind::doubleNode, sourcePos_)
{
}

VoidNode::VoidNode(const SourcePos& sourcePos_) : Node(NodeKind::voidNode, sourcePos_)
{
}

} // namespace sngcpp::ast
