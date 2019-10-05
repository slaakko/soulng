// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Node.hpp>

namespace sngcpp { namespace ast {

Node::Node(const Span& span_) : span(span_)
{
}

Node::~Node()
{
}

UnaryNode::UnaryNode(const Span& span_) : Node(span_)
{
}

UnaryNode::UnaryNode(const Span& span_, Node* child_) : Node(span_), child(child_)
{
}

BinaryNode::BinaryNode(const Span& span_, Node* left_, Node* right_) : Node(span_), left(left_), right(right_)
{
}

} } // namespace sngcpp::ast
