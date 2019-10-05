// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_NODE_INCLUDED
#define SNGCPP_AST_NODE_INCLUDED
#include <sngcpp/ast/AstApi.hpp>
#include <soulng/lexer/Span.hpp>
#include <memory>

namespace sngcpp { namespace ast {

using soulng::lexer::Span;

class Visitor;

class SNGCPP_AST_API Node
{
public:
    Node(const Span& span_);
    virtual ~Node();
    virtual void Accept(Visitor& visitor) = 0;
    const Span& GetSpan() const { return span; }
    void SetSpanEnd(int32_t spanEnd) { span.end = spanEnd;  }
    virtual bool IsFunctionDeclaratorNode() const { return false; }
    virtual bool IsTemplateArgumentSequenceNode() const { return false; }
    virtual bool IsIdentifierNode() const { return false; }
    virtual bool IsOperatorFunctionIdNode() const { return false; }
    virtual bool IsConversionFunctionIdNode() const { return false; }
    virtual bool IsDtorIdNode() const { return false; }
    virtual bool IsTemplateIdNode() const { return false; }
private:
    Span span;
};

class SNGCPP_AST_API UnaryNode : public Node
{
public:
    UnaryNode(const Span& span_);
    UnaryNode(const Span& span_, Node* child_);
    Node* Child() { return child.get(); }
    void SetChild(Node* child_) { child.reset(child_); }
    Node* ReleaseChild() { return child.release(); }
private:
    std::unique_ptr<Node> child;
};

class SNGCPP_AST_API BinaryNode : public Node
{
public:
    BinaryNode(const Span& span_, Node* left_, Node* right_);
    Node* Left() { return left.get(); }
    Node* Right() { return right.get(); }
private:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
};

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_NODE_INCLUDED
