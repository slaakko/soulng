// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Function.hpp>
#include <sngcpp/ast/Visitor.hpp>

namespace sngcpp { namespace ast {

ParameterNode::ParameterNode(const Span& span_, Node* typeExpr_, Node* declarator_) : Node(span_), typeExpr(typeExpr_), declarator(declarator_)
{
}

void ParameterNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ParameterSequenceNode::ParameterSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(span_, left_, right_)
{
}

void ParameterSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

FunctionNode::FunctionNode(const Span& span_, Specifier specifiers_, Node* typeExpr_, Node* declarator_, CompoundStatementNode* body_) : 
    Node(span_), specifiers(specifiers_), typeExpr(typeExpr_), declarator(declarator_), body(body_)
{
}

void FunctionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

bool IsFunctionDeclarator(Node* declaratorNode)
{
    return declaratorNode->IsFunctionDeclaratorNode();
}

bool HasPureSpecifier(Specifier specifiers)
{
    return (specifiers & Specifier::pure_) != Specifier::none;
}

} } // namespace sngcpp::ast
