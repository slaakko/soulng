// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_VISITOR_INCLUDED
#define SNGCPP_AST_VISITOR_INCLUDED
#include <sngcpp20/ast/AstApi.hpp>
#include <soulng/lexer/SourcePos.hpp>

namespace sngcpp::ast {

using soulng::lexer::SourcePos;

class Node;
class CompoundNode;
class UnaryNode;
class BinaryNode;
class SequenceNode;
class ListNode;
class AttributeSpecifierSequenceNode;
class LabeledStatementNode;

class AST_API Visitor
{
public:
    virtual ~Visitor();
    virtual void BeginVisit(Node& node) {}
    virtual void EndVisit(Node& node) {}
    virtual void VisitColon(const SourcePos& colonPos) {}
    virtual void Visit(AttributeSpecifierSequenceNode& node) {}
    virtual void Visit(LabeledStatementNode& node) {}
    void VisitSingleNode(Node& node);
    void VisitUnaryNode(UnaryNode& unaryNode);
    void VisitBinaryNode(BinaryNode& binaryNode);
    void VisitSequence(SequenceNode& sequenceNode);
    void VisitList(ListNode& listNode);
};

class AST_API DefaultVisitor : public Visitor
{
public:
    void Visit(AttributeSpecifierSequenceNode& node) override;
    void Visit(LabeledStatementNode& node) override;

};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_VISITOR_INCLUDED
