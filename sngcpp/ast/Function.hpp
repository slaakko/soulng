// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_FUNCTION_INCLUDED
#define SNGCPP_AST_FUNCTION_INCLUDED
#include <sngcpp/ast/Statement.hpp>
#include <sngcpp/ast/Specifier.hpp>

namespace sngcpp { namespace ast {

class SNGCPP_AST_API ParameterNode : public Node
{
public:
    ParameterNode();
    ParameterNode(const Span& span_, Node* typeExpr_, Node* declarator_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* TypeExpr() { return typeExpr.get(); }
    Node* Declarator() { return declarator.get(); }
private:
    std::unique_ptr<Node> typeExpr;
    std::unique_ptr<Node> declarator;
};

class SNGCPP_AST_API ParameterSequenceNode : public BinaryNode
{
public:
    ParameterSequenceNode();
    ParameterSequenceNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API FunctionNode : public Node
{
public:
    FunctionNode();
    FunctionNode(const Span& span_, Specifier specifiers_, Node* typeExpr_, Node* declarator_, CompoundStatementNode* body_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Specifier Specifiers() const { return specifiers; }
    Node* TypeExpr() { return typeExpr.get(); }
    Node* Declarator() { return declarator.get(); }
    CompoundStatementNode* Body() { return body.get(); }
private:
    Specifier specifiers;
    std::unique_ptr<Node> typeExpr;
    std::unique_ptr<Node> declarator;
    std::unique_ptr<CompoundStatementNode> body;
};

SNGCPP_AST_API bool IsFunctionDeclarator(Node* declaratorNode);
SNGCPP_AST_API bool HasPureSpecifier(Specifier specifiers);

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_FUNCTION_INCLUDED
