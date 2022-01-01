// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_TYPE_INCLUDED
#define SNGCPP_AST_TYPE_INCLUDED
#include <sngcpp20/ast/Node.hpp>

namespace sngcpp::ast {

class AST_API TypeSpecifierSequenceNode : public SequenceNode
{
public:
    TypeSpecifierSequenceNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API TypenameSpecifierNode : public CompoundNode
{
public:
    TypenameSpecifierNode(const SourcePos& sourcePos_);
    TypenameSpecifierNode(const SourcePos& sourcePos_, Node* nns_, Node* id_, Node* templateNode_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* NestedNameSpecifier() const { return nns.get(); }
    Node* Id() const { return id.get(); }
    Node* TemplateNode() const { return templateNode.get(); }
private:
    std::unique_ptr<Node> nns;
    std::unique_ptr<Node> id;
    std::unique_ptr<Node> templateNode;
};

class AST_API TypeIdNode : public CompoundNode
{
public:
    TypeIdNode(const SourcePos& sourcePos_);
    TypeIdNode(const SourcePos& sourcePos_, Node* typeSpecifiers_, Node* declarator_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* TypeSpecifiers() const { return typeSpecifiers.get(); }
    Node* Declarator() const { return declarator.get(); }
private:
    std::unique_ptr<Node> typeSpecifiers;
    std::unique_ptr<Node> declarator;
};

class AST_API DefiningTypeIdNode : public CompoundNode
{
public:
    DefiningTypeIdNode(const SourcePos& sourcePos_);
    DefiningTypeIdNode(const SourcePos& sourcePos_, Node* definingTypeSpecifiers_, Node* abstractDeclarator_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* DefiningTypeSpecifiers() const { return definingTypeSpecifiers.get(); }
    Node* AbstractDeclarator() const { return abstractDeclarator.get(); }
private:
    std::unique_ptr<Node> definingTypeSpecifiers;
    std::unique_ptr<Node> abstractDeclarator;
};

class AST_API DefiningTypeSpecifierSequenceNode : public SequenceNode
{
public:
    DefiningTypeSpecifierSequenceNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API TrailingReturnTypeNode : public UnaryNode
{
public:
    TrailingReturnTypeNode(const SourcePos& sourcePos_);
    TrailingReturnTypeNode(const SourcePos& sourcePos_, Node* typeId_);
    void Accept(Visitor& visitor) override;
};

class AST_API ElaboratedTypeSpecifierNode : public CompoundNode
{
public:
    ElaboratedTypeSpecifierNode(const SourcePos& sourcePos_);
    ElaboratedTypeSpecifierNode(const SourcePos& sourcePos_, Node* classKey_, Node* id_, Node* attributes_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* ClassKey() const { return classKey.get(); }
    Node* Id() const { return id.get(); }
    Node* Attributes() const { return attributes.get(); }
private:
    std::unique_ptr<Node> classKey;
    std::unique_ptr<Node> id;
    std::unique_ptr<Node> attributes;
};

class AST_API DeclTypeSpecifierNode : public CompoundNode
{
public:
    DeclTypeSpecifierNode(const SourcePos& sourcePos_);
    DeclTypeSpecifierNode(const SourcePos& sourcePos_, Node* expr_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Expression() const { return expr.get(); }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    std::unique_ptr<Node> expr;
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API PlaceholderTypeSpecifierNode : public CompoundNode
{
public:
    PlaceholderTypeSpecifierNode(const SourcePos& sourcePos_);
    PlaceholderTypeSpecifierNode(const SourcePos& sourcePos_, Node* typeConstraint_, const SourcePos& dtPos_, const SourcePos& autoPos_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* TypeConstraint() const { return typeConstraint.get(); }
    const SourcePos& DeclTypePos() const { return dtPos; }
    const SourcePos& AutoPos() const { return autoPos; }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
    bool IsDeclType() const { return dtPos.IsValid(); };
private:
    std::unique_ptr<Node> typeConstraint;
    SourcePos dtPos;
    SourcePos autoPos;
    SourcePos lpPos;
    SourcePos rpPos;
};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_TYPE_INCLUDED
