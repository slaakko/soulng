// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Qualifier.hpp>

namespace sngcpp::ast {

ConstNode::ConstNode(const SourcePos& sourcePos_) : Node(NodeKind::constNode, sourcePos_)
{
}

VolatileNode::VolatileNode(const SourcePos& sourcePos_) : Node(NodeKind::volatileNode, sourcePos_)
{
}

LvalueRefNode::LvalueRefNode(const SourcePos& sourcePos_) : Node(NodeKind::lvalueRefNode, sourcePos_)
{
}

RvalueRefNode::RvalueRefNode(const SourcePos& sourcePos_) : Node(NodeKind::rvalueRefNode, sourcePos_)
{
}

PtrNode::PtrNode(const SourcePos& sourcePos_) : Node(NodeKind::ptrNode, sourcePos_)
{
}

CVQualifierSequenceNode::CVQualifierSequenceNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::cvQualifierSequenceNode, sourcePos_)
{
}

} // namespace sngcpp::ast
