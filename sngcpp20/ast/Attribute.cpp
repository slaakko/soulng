// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Attribute.hpp>
#include <sngcpp20/ast/Visitor.hpp>

namespace sngcpp::ast {

AttributeSpecifierSequenceNode::AttributeSpecifierSequenceNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::attributeSpecifierSequenceNode, sourcePos_)
{
}

void AttributeSpecifierSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

AttributeSpecifierNode::AttributeSpecifierNode(const SourcePos& sourcePos_) : ListNode(NodeKind::attributeSpecifierNode, sourcePos_)
{
}

void AttributeSpecifierNode::SetBracketPositions(const SourcePos& lbPos1_, const SourcePos& lbPos2_, const SourcePos& rbPos1_, const SourcePos& rbPos2_)
{
    lbPos1 = lbPos1_;
    lbPos2 = lbPos2_;
    rbPos1 = rbPos1_;
    rbPos2 = rbPos2_;
}

AttributeUsingPrefixNode::AttributeUsingPrefixNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::attributeUsingPrefixNode, sourcePos_, nullptr)
{
}

AttributeUsingPrefixNode::AttributeUsingPrefixNode(const SourcePos& sourcePos_, Node* atttributeNamespace_, const SourcePos& colonPos_) : 
    UnaryNode(NodeKind::attributeUsingPrefixNode, sourcePos_, atttributeNamespace_), colonPos(colonPos_)
{
}

AttributeNode::AttributeNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::attrbuteNode, sourcePos_)
{
}

AttributeNode::AttributeNode(const SourcePos& sourcePos_, Node* attributeToken_, Node* attributeArgs_) :
    CompoundNode(NodeKind::attrbuteNode, sourcePos_), attributeToken(attributeToken_), attributeArgs(attributeArgs_)
{
}

AttributeScopedTokenNode::AttributeScopedTokenNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::attributeScopedTokenNode, sourcePos_)
{
}

AttributeScopedTokenNode::AttributeScopedTokenNode(const SourcePos& sourcePos_, Node* ns_, Node* colonColon_, Node* identifier_) :
    CompoundNode(NodeKind::attributeScopedTokenNode, sourcePos_), ns(ns_), colonColon(colonColon_), identifier(identifier_)
{
}

AttributeArgumentsNode::AttributeArgumentsNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::attributeArgumentsNode, sourcePos_)
{
}

AttributeArgumentsNode::AttributeArgumentsNode(const SourcePos& sourcePos_, Node* balancedTokenSequence_, const SourcePos& lpPos_, const SourcePos& rpPos_) :
    CompoundNode(NodeKind::attributeArgumentsNode, sourcePos_), balancedTokenSequence(balancedTokenSequence_), lpPos(lpPos_), rpPos(rpPos_)
{
}

BalancedTokenSequenceNode::BalancedTokenSequenceNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::balancedTokenSequenceNode, sourcePos_)
{
}

TokenNode::TokenNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::tokenNode, sourcePos_)
{
}

TokenNode::TokenNode(const SourcePos& sourcePos_, const std::u32string& str_) : CompoundNode(NodeKind::tokenNode, sourcePos_), str(str_)
{
}

AlignmentSpecifierNode::AlignmentSpecifierNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::alignmentSpecifierNode, sourcePos_)
{
}

AlignmentSpecifierNode::AlignmentSpecifierNode(const SourcePos& sourcePos_, Node* alignment_, Node* ellipses_, const SourcePos& lpPos_, const SourcePos& rpPos_) :
    CompoundNode(NodeKind::alignmentSpecifierNode, sourcePos_), alignment(alignment_), ellipses(ellipses_), lpPos(lpPos_), rpPos(rpPos_)
{
}

LParenNode::LParenNode(const SourcePos& sourcePos_) : Node(NodeKind::lparenNode, sourcePos_)
{
}

RParenNode::RParenNode(const SourcePos& sourcePos_) : Node(NodeKind::rparenNode, sourcePos_)
{
}

LBracketNode::LBracketNode(const SourcePos& sourcePos_) : Node(NodeKind::lbracketNode, sourcePos_)
{
}

RBracketNode::RBracketNode(const SourcePos& sourcePos_) : Node(NodeKind::rbracketNode, sourcePos_)
{
}

LBraceNode::LBraceNode(const SourcePos& sourcePos_) : Node(NodeKind::lbraceNode, sourcePos_)
{
}

RBraceNode::RBraceNode(const SourcePos& sourcePos_) : Node(NodeKind::rbraceNode, sourcePos_)
{
}

} // sngcpp::ast
