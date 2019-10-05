// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/TypeExpr.hpp>
#include <sngcpp/ast/Visitor.hpp>

namespace sngcpp { namespace ast {

ConstNode::ConstNode(const Span& span_, Node* subject_) : UnaryNode(span_, subject_)
{
}

void ConstNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

VolatileNode::VolatileNode(const Span& span_, Node* subject_) : UnaryNode(span_, subject_)
{
}

void VolatileNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

Node* CreatePrefixTypeExprNode(const Span& span_, Specifier cvSpecifiers, Node* typeExprNode)
{
    Node* node = typeExprNode;
    Specifier specifier = cvSpecifiers & Specifier::volatile_;
    if (specifier == Specifier::volatile_)
    {
        node = new VolatileNode(span_, node);
    }
    specifier = cvSpecifiers & Specifier::const_;
    if (specifier == Specifier::const_)
    {
        node = new ConstNode(span_, node);
    }
    return node;
}

PointerNode::PointerNode(const Span& span_, Node* subject_) : UnaryNode(span_, subject_)
{
}

void PointerNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

RValueRefNode::RValueRefNode(const Span& span_, Node* subject_) : UnaryNode(span_, subject_)
{
}

void RValueRefNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

LValueRefNode::LValueRefNode(const Span& span_, Node* subject_) : UnaryNode(span_, subject_)
{
}

void LValueRefNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

TypeExprNode::TypeExprNode(const Span& span_, Node* typeExpr_) : UnaryNode(span_, typeExpr_)
{
}

void TypeExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} } // namespace sngcpp::ast
