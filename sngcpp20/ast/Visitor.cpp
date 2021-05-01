// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Attribute.hpp>
#include <sngcpp20/ast/Statement.hpp>

namespace sngcpp::ast {

Visitor::~Visitor()
{
}

void Visitor::VisitSingleNode(Node& node)
{
    BeginVisit(node);
    EndVisit(node);
}

void Visitor::VisitUnaryNode(UnaryNode& unaryNode)
{
    BeginVisit(unaryNode);
    unaryNode.Child()->Accept(*this);
    EndVisit(unaryNode);
}

void Visitor::VisitBinaryNode(BinaryNode& binaryNode)
{
    BeginVisit(binaryNode);
    binaryNode.Left()->Accept(*this);
    binaryNode.Right()->Accept(*this);
    EndVisit(binaryNode);
}

void Visitor::VisitSequence(SequenceNode& sequenceNode)
{
    BeginVisit(sequenceNode);
    int n = sequenceNode.Nodes().Count();
    for (int i = 0; i < n; ++i)
    {
        Node* node = sequenceNode.Nodes()[i];
        node->Accept(*this);
    }
    EndVisit(sequenceNode);
}

void Visitor::VisitList(ListNode& listNode)
{
    BeginVisit(listNode);
    int n = listNode.Nodes().Count();
    for (int i = 0; i < n; ++i)
    {
        Node* node = listNode.Nodes()[i];
        node->Accept(*this);
    }
    EndVisit(listNode);
}

void DefaultVisitor::Visit(AttributeSpecifierSequenceNode& node)
{
    VisitSequence(node);
}

void DefaultVisitor::Visit(LabeledStatementNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    if (node.Label())
    {
        node.Label()->Accept(*this);
    }
    VisitColon(node.ColonPos());
    if (node.Statement())
    {
        node.Statement()->Accept(*this);
    }
    EndVisit(node);
}

} // namespace sngcpp::ast
