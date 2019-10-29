// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/TypeExpr.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <sngcpp/ast/Expression.hpp>

namespace sngcpp { namespace ast {

ConstNode::ConstNode() : UnaryNode(NodeType::constNode)
{
}

ConstNode::ConstNode(const Span& span_, Node* subject_) : UnaryNode(NodeType::constNode, span_, subject_)
{
}

void ConstNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

VolatileNode::VolatileNode() : UnaryNode(NodeType::volatileNode)
{
}

VolatileNode::VolatileNode(const Span& span_, Node* subject_) : UnaryNode(NodeType::volatileNode, span_, subject_)
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

PointerNode::PointerNode() : UnaryNode(NodeType::pointerNode)
{
}

PointerNode::PointerNode(const Span& span_, Node* subject_) : UnaryNode(NodeType::pointerNode, span_, subject_)
{
}

void PointerNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

RValueRefNode::RValueRefNode() : UnaryNode(NodeType::rValueRefNode)
{
}

RValueRefNode::RValueRefNode(const Span& span_, Node* subject_) : UnaryNode(NodeType::rValueRefNode, span_, subject_)
{
}

void RValueRefNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

LValueRefNode::LValueRefNode() : UnaryNode(NodeType::lValueRefNode)
{
}

LValueRefNode::LValueRefNode(const Span& span_, Node* subject_) : UnaryNode(NodeType::lValueRefNode, span_, subject_)
{
}

void LValueRefNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

TypeExprNode::TypeExprNode() : UnaryNode(NodeType::typeExprNode)
{
}

TypeExprNode::TypeExprNode(const Span& span_, Node* typeExpr_) : UnaryNode(NodeType::typeExprNode, span_, typeExpr_)
{
}

void TypeExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

bool IsConstructorName(Node* node)
{
    if (node->GetNodeType() == NodeType::nestedIdNode)
    {
        NestedIdNode* nestedIdNode = static_cast<NestedIdNode*>(node);
        if (nestedIdNode->Left()->GetNodeType() == NodeType::identifierNode && nestedIdNode->Right()->GetNodeType() == NodeType::identifierNode)
        {
            IdentifierNode* left = static_cast<IdentifierNode*>(nestedIdNode->Left());
            IdentifierNode* right = static_cast<IdentifierNode*>(nestedIdNode->Right());
            if (left->Identifier() == right->Identifier())
            {
                return true;
            }
        }
    }
    return false;
}

} } // namespace sngcpp::ast
