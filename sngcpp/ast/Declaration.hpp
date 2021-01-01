// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_DECLARATION_INCLUDED
#define SNGCPP_AST_DECLARATION_INCLUDED
#include <sngcpp/ast/Declarator.hpp>
#include <sngcpp/ast/Specifier.hpp>
#include <sngcpp/ast/Literal.hpp>

namespace sngcpp { namespace ast {

class SNGCPP_AST_API SimpleDeclarationNode : public Node
{
public:
    SimpleDeclarationNode();
    SimpleDeclarationNode(const Span& span_, Specifier specifiers_, Node* typeExpr_, Node* declarator_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Specifier Specifiers() const { return specifiers; }
    Node* TypeExpr() { return typeExpr.get(); }
    Node* Declarator() { return declarator.get(); }
private:
    Specifier specifiers;
    std::unique_ptr<Node> typeExpr;
    std::unique_ptr<Node> declarator;
};

class SNGCPP_AST_API AliasDeclarationNode : public Node
{
public:
    AliasDeclarationNode();
    AliasDeclarationNode(const Span& span_, const std::u32string& id_, Node* typeExpr_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const std::u32string& Id() const { return id; }
    Node* TypeExpr() { return typeExpr.get(); }
private:
    std::u32string id;
    std::unique_ptr<Node> typeExpr;
};

class SNGCPP_AST_API UsingDirectiveNode : public Node
{
public:
    UsingDirectiveNode();
    UsingDirectiveNode(const Span& span_, Node* namespaceName_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* NamespaceName() { return namespaceName.get(); }
private:
    std::unique_ptr<Node> namespaceName;
};

class SNGCPP_AST_API UsingDeclarationNode : public Node
{
public:
    UsingDeclarationNode();
    UsingDeclarationNode(const Span& span_, Node* qualifiedId_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* QualifiedId() { return qualifiedId.get(); }
private:
    std::unique_ptr<Node> qualifiedId;
};

class SNGCPP_AST_API TypedefNode : public Node
{
public:
    TypedefNode();
    TypedefNode(const Span& span_, Node* typeExpr_, Node* declarator_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* TypeExpr() { return typeExpr.get(); }
    Node* Declarator() { return declarator.get(); }
private:
    std::unique_ptr<Node> typeExpr;
    std::unique_ptr<Node> declarator;
};

class SNGCPP_AST_API DeclarationSequenceNode : public BinaryNode
{
public:
    DeclarationSequenceNode();
    DeclarationSequenceNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API LinkageSpecificationNode : public Node
{
public:
    LinkageSpecificationNode();
    LinkageSpecificationNode(const Span& span_, StringLiteralNode* language_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    StringLiteralNode* Language() { return language.get(); }
    Node* Declarations() { return declarations.get(); }
    void AddDeclaration(const Span& span_, Node* declaration);
private:
    std::unique_ptr<StringLiteralNode> language;
    std::unique_ptr<Node> declarations;
};

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_DECLARATION_INCLUDED
