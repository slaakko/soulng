// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_CLASS_INCLUDED
#define SNGCPP_AST_CLASS_INCLUDED
#include <sngcpp/ast/Statement.hpp>
#include <sngcpp/ast/Specifier.hpp>

namespace sngcpp { namespace ast {

enum class ClassKey : uint8_t
{
    none, class_, struct_, union_, typename_
};

SNGCPP_AST_API std::u32string ToString(ClassKey classKey);

class SNGCPP_AST_API BaseClassSpecifierNode : public Node
{
public:
    BaseClassSpecifierNode();
    BaseClassSpecifierNode(const Span& span_, Specifier baseSpecifiers_, Node* className_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Specifier BaseSpecifiers() const { return baseSpecifiers; }
    Node* ClassName() { return className.get(); }
private:
    Specifier baseSpecifiers;
    std::unique_ptr<Node> className;
};

class SNGCPP_AST_API BaseClassSpecifierSequenceNode : public BinaryNode
{
public:
    BaseClassSpecifierSequenceNode();
    BaseClassSpecifierSequenceNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API ForwardClassDeclarationNode : public Node
{
public:
    ForwardClassDeclarationNode();
    ForwardClassDeclarationNode(const Span& span_, ClassKey classKey_, Node* className_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    ClassKey GetClassKey() const { return classKey; }
    Node* ClassName() { return className.get(); }
private:
    ClassKey classKey;
    std::unique_ptr<Node> className;
};

class SNGCPP_AST_API ElaborateClassNameNode : public Node
{
public:
    ElaborateClassNameNode();
    ElaborateClassNameNode(const Span& span_, ClassKey classKey_, Node* className_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    ClassKey GetClassKey() const { return classKey; }
    Node* ClassName() { return className.get(); }
private:
    ClassKey classKey;
    std::unique_ptr<Node> className;
};

class SNGCPP_AST_API ClassNode : public Node
{
public:
    ClassNode();
    ClassNode(const Span& span_, ClassKey classKey_, Node* className_, Specifier classVirtSpecifiers_, Node* baseClasses_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    void AddDeclaration(const Span& span, Node* declaration);
    Node* ClassName() { return className.get(); }
    ClassKey GetClassKey() const { return classKey; }
    Specifier ClassVirtSpecifiers() const { return classVirtSpecifiers; }
    Node* BaseClasses() { return baseClasses.get(); }
    Node* Declarations() { return declarations.get(); }
    Specifier DefaultAccess() const;
    void SetOpenBraceSpan(const Span& openBraceSpan_) { openBraceSpan = openBraceSpan_; }
    void SetCloseBraceSpan(const Span& closeBraceSpan_) { closeBraceSpan = closeBraceSpan_; }
    const Span& OpenBraceSpan() const { return openBraceSpan; }
    const Span& CloseBraceSpan() const { return closeBraceSpan; }
private:
    ClassKey classKey;
    std::unique_ptr<Node> className;
    Specifier classVirtSpecifiers;
    std::unique_ptr<Node> baseClasses;
    std::unique_ptr<Node> declarations;
    Span openBraceSpan;
    Span closeBraceSpan;
};

class SNGCPP_AST_API MemberAccessDeclarationNode : public Node
{
public:
    MemberAccessDeclarationNode();
    MemberAccessDeclarationNode(const Span& span_, Specifier accessSpecifier_, Node* declaration_, bool explicitAccess_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Specifier AccessSpecifier() const { return accessSpecifier; }
    Node* Declaration() { return declaration.get(); }
    bool ExplicitAccess() const { return explicitAccess; }
private:
    Specifier accessSpecifier;
    std::unique_ptr<Node> declaration;
    bool explicitAccess;
};

class SNGCPP_AST_API MemberDeclarationNode : public Node
{
public:
    MemberDeclarationNode();
    MemberDeclarationNode(const Span& span_, Specifier specifiers_, Node* typeExpr_, Node* declarator_, Node* initializer_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Specifier Specifiers() const { return specifiers; }
    Node* TypeExpr() { return typeExpr.get(); }
    Node* Declarator() { return declarator.get(); }
    Node* Initializer() { return initializer.get(); }
private:
    Specifier specifiers;
    std::unique_ptr<Node> typeExpr;
    std::unique_ptr<Node> declarator;
    std::unique_ptr<Node> initializer;
};

class SNGCPP_AST_API SpecialMemberFunctionNode : public Node
{
public:
    SpecialMemberFunctionNode();
    SpecialMemberFunctionNode(const Span& span_, Specifier specifiers_, Node* declarator_, Node* ctorInitializer_, CompoundStatementNode* functionBody_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Specifier Specifiers() const { return specifiers; }
    Node* Declarator() { return declarator.get(); }
    Node* CtorInitializer() { return ctorInitializer.get(); }
    CompoundStatementNode* FunctionBody() { return functionBody.get(); }
private:
    Specifier specifiers;
    std::unique_ptr<Node> declarator;
    std::unique_ptr<Node> ctorInitializer;
    std::unique_ptr<CompoundStatementNode> functionBody;
};

class SNGCPP_AST_API CtorInitializerNode : public UnaryNode
{
public:
    CtorInitializerNode();
    CtorInitializerNode(const Span& span_, Node* memberInitializers_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API MemberInitializerNode : public Node
{
public:
    MemberInitializerNode();
    MemberInitializerNode(const Span& span_, Node* id_, Node* initializer_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Id() { return id.get(); }
    Node* Initializer() { return initializer.get(); }
private:
    std::unique_ptr<Node> id;
    std::unique_ptr<Node> initializer;
};

class SNGCPP_AST_API MemberInitializerSequenceNode : public BinaryNode
{
public:
    MemberInitializerSequenceNode();
    MemberInitializerSequenceNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_CLASS_INCLUDED
