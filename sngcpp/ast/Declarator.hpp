// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_DECLARATOR_INCLUDED
#define SNGCPP_AST_DECLARATOR_INCLUDED
#include <sngcpp/ast/Statement.hpp>
#include <sngcpp/ast/Specifier.hpp>

namespace sngcpp { namespace ast {

class SNGCPP_AST_API IdDeclaratorNode : public Node
{
public:
    IdDeclaratorNode();
    IdDeclaratorNode(const Span& span_, Node* idNode_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* IdNode() const { return idNode.get(); }
private:
    std::unique_ptr<Node> idNode;
};

class SNGCPP_AST_API ArrayDeclaratorNode : public Node
{
public:
    ArrayDeclaratorNode();
    ArrayDeclaratorNode(const Span& span_, Node* declarator_, Node* size_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Declarator() { return declarator.get(); }
    Node* Size() { return size.get(); }
private:
    std::unique_ptr<Node> declarator;
    std::unique_ptr<Node> size;
};

class SNGCPP_AST_API FunctionDeclaratorNode : public Node
{
public:
    FunctionDeclaratorNode();
    FunctionDeclaratorNode(const Span& span_, Node* declarator_, Node* parameters_, Specifier cvSpecifiers_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    bool IsFunctionDeclaratorNode() const override { return true; }
    Node* Declarator() { return declarator.get(); }
    Node* Parameters() { return parameters.get(); }
    Specifier CVSpecifiers() const { return cvSpecifiers; }
private:
    std::unique_ptr<Node> declarator;
    std::unique_ptr<Node> parameters;
    Specifier cvSpecifiers;
};

class SNGCPP_AST_API FunctionPtrIdNode : public Node
{
public:
    FunctionPtrIdNode();
    FunctionPtrIdNode(const Span& span_, const std::u32string& id_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const std::u32string& Id() const { return id; }
private:
    std::u32string id;
};

class SNGCPP_AST_API MemberFunctionPtrIdNode : public Node
{
public:
    MemberFunctionPtrIdNode();
    MemberFunctionPtrIdNode(const Span& span_, Node* classNameNode_, const std::u32string& id_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* ClassNameNode() { return classNameNode.get(); }
    const std::u32string& Id() const { return id; }
private:
    std::unique_ptr<Node> classNameNode;
    std::u32string id;
};

class SNGCPP_AST_API InitDeclaratorNode : public Node
{
public:
    InitDeclaratorNode();
    InitDeclaratorNode(const Span& span_, Node* declarator_, Node* initializer_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Declarator() { return declarator.get(); }
    Node* Initializer() { return initializer.get(); }
private:
    std::unique_ptr<Node> declarator;
    std::unique_ptr<Node> initializer;
};

class SNGCPP_AST_API AssignmentInitializerNode : public UnaryNode
{
public:
    AssignmentInitializerNode();
    AssignmentInitializerNode(const Span& span_, Node* initializer_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API ExpressionListInitializerNode : public UnaryNode
{
public:
    ExpressionListInitializerNode();
    ExpressionListInitializerNode(const Span& span_, Node* initializer_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API ExpressionInitializerNode : public UnaryNode
{
public:
    ExpressionInitializerNode();
    ExpressionInitializerNode(const Span& span_, Node* expr_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API BracedInitializerListNode : public UnaryNode
{
public:
    BracedInitializerListNode();
    BracedInitializerListNode(const Span& span_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    void AddInitializer(const Span& span, Node* initializer);
    void SetEndBraceSpan(const Span& endBraceSpan_) { endBraceSpan = endBraceSpan_; }
    const Span& EndBraceSpan() const { return endBraceSpan; }
private:
    Span endBraceSpan;
};

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_DECLARATOR_INCLUDED
