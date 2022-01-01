// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Qualifier.hpp>
#include <sngcpp20/ast/Visitor.hpp>

namespace sngcpp::ast {

ConstNode::ConstNode(const SourcePos& sourcePos_) : Node(NodeKind::constNode, sourcePos_)
{
}

void ConstNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

VolatileNode::VolatileNode(const SourcePos& sourcePos_) : Node(NodeKind::volatileNode, sourcePos_)
{
}

void VolatileNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

LvalueRefNode::LvalueRefNode(const SourcePos& sourcePos_) : Node(NodeKind::lvalueRefNode, sourcePos_)
{
}

void LvalueRefNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

RvalueRefNode::RvalueRefNode(const SourcePos& sourcePos_) : Node(NodeKind::rvalueRefNode, sourcePos_)
{
}

void RvalueRefNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

PtrNode::PtrNode(const SourcePos& sourcePos_) : Node(NodeKind::ptrNode, sourcePos_)
{
}

void PtrNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

CVQualifierSequenceNode::CVQualifierSequenceNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::cvQualifierSequenceNode, sourcePos_)
{
}

void CVQualifierSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} // namespace sngcpp::ast
