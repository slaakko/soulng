// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Pragma.hpp>
#include <sngcpp20/ast/Visitor.hpp>

namespace sngcpp::ast {

PragmaNode::PragmaNode(const SourcePos& sourcePos_) : Node(NodeKind::pragmaNode, sourcePos_)
{
}

void PragmaNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} // namespace sngcpp::ast
