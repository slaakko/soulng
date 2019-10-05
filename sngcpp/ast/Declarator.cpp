// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Declarator.hpp>
#include <sngcpp/ast/Expression.hpp>
#include <sngcpp/ast/Visitor.hpp>

namespace sngcpp { namespace ast {

IdDeclaratorNode::IdDeclaratorNode(const Span& span_, Node* idNode_) : Node(span_), idNode(idNode_)
{
}

void IdDeclaratorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ArrayDeclaratorNode::ArrayDeclaratorNode(const Span& span_, Node* declarator_, Node* size_) : Node(span_), declarator(declarator_), size(size_)
{
}

void ArrayDeclaratorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

FunctionDeclaratorNode::FunctionDeclaratorNode(const Span& span_, Node* declarator_, Node* parameters_, Specifier cvSpecifiers_) :
    Node(span_), declarator(declarator_), parameters(parameters_), cvSpecifiers(cvSpecifiers_)
{
}

void FunctionDeclaratorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

FunctionPtrIdNode::FunctionPtrIdNode(const Span& span_, const std::u32string& id_) : Node(span_), id(id_)
{
}

void FunctionPtrIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

MemberFunctionPtrIdNode::MemberFunctionPtrIdNode(const Span& span_, Node* classNameNode_, const std::u32string& id_) : Node(span_), classNameNode(classNameNode_), id(id_)
{
}

void MemberFunctionPtrIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

InitDeclaratorNode::InitDeclaratorNode(const Span& span_, Node* declarator_, Node* initializer_) : Node(span_), declarator(declarator_), initializer(initializer_)
{
}

void InitDeclaratorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

AssignmentInitializerNode::AssignmentInitializerNode(const Span& span_, Node* initializer_) : UnaryNode(span_, initializer_)
{
}

void AssignmentInitializerNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ExpressionListInitializerNode::ExpressionListInitializerNode(const Span& span_, Node* initializer_) : UnaryNode(span_, initializer_)
{
}

void ExpressionListInitializerNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ExpressionInitializerNode::ExpressionInitializerNode(const Span& span_, Node* expr_) : UnaryNode(span_, expr_)
{
}

void ExpressionInitializerNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

BracedInitializerListNode::BracedInitializerListNode(const Span& span_) : UnaryNode(span_)
{
}

void BracedInitializerListNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void BracedInitializerListNode::AddInitializer(const Span& span, Node* initializer)
{
    if (Child())
    {
        SetChild(new ExpressionSequenceNode(span, ReleaseChild(), initializer));
    }
    else
    {
        SetChild(initializer);
    }
}

} } // namespace sngcpp::ast
