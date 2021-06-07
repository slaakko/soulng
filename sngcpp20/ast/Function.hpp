// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_FUNCTION_INCLUDED
#define SNGCPP_AST_FUNCTION_INCLUDED
#include <sngcpp20/ast/Node.hpp>

namespace sngcpp::ast {

class AST_API FunctionDefinitionNode : public CompoundNode
{
public:
    FunctionDefinitionNode(const SourcePos& sourcePos_);
    FunctionDefinitionNode(const SourcePos& sourcePos_, Node* attributes_, Node* declSpecifiers_, Node* declarator_, Node* specifiers_, Node* functionBody_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Attributes() const { return attributes.get(); }
    Node* DeclSpecifiers() const { return declSpecifiers.get(); }
    Node* Declarator() const { return declarator.get(); }
    Node* Specifiers() const { return specifiers.get(); }
    Node* FunctionBody() const { return functionBody.get(); }
    void ResetFunctionBody(Node* functionBody_);
private:
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> declSpecifiers;
    std::unique_ptr<Node> declarator;
    std::unique_ptr<Node> specifiers;
    std::unique_ptr<Node> functionBody;
};

class AST_API FunctionBodyNode : public UnaryNode
{
public:
    FunctionBodyNode(const SourcePos& sourcePos_);
    FunctionBodyNode(const SourcePos& sourcePos_, Node* compoundStatement_);
    void Accept(Visitor& visitor) override;
};

class AST_API DefaultNode : public Node
{
public:
    DefaultNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API DeleteNode : public Node
{
public:
    DeleteNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API DefaultedOrDeletedFunctionNode : public CompoundNode
{
public:
    DefaultedOrDeletedFunctionNode(const SourcePos& sourcePos_);
    DefaultedOrDeletedFunctionNode(const SourcePos& sourcePos_, Node* assign_, Node* defaultOrDelete_, Node* semicolon_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Assign() const { return assign.get(); }
    Node* DefaultOrDelete() const { return defaultOrDelete.get(); }
    Node* Semicolon() const { return semicolon.get(); }
private:
    std::unique_ptr<Node> assign;
    std::unique_ptr<Node> defaultOrDelete;
    std::unique_ptr<Node> semicolon;
};

class AST_API FunctionDeclarationNode : public CompoundNode
{
public:
    FunctionDeclarationNode(const SourcePos& sourcePos_);
    FunctionDeclarationNode(const SourcePos& sourcePos_, Node* declarator_, Node* attributes_, Node* semicolon_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Declarator() const { return declarator.get(); }
    Node* Attributes() const { return attributes.get(); }
    Node* Semicolon() const { return semicolon.get(); }
private:
    std::unique_ptr<Node> declarator;
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> semicolon;
};

class AST_API OperatorNode : public Node
{
public:
    OperatorNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API NewArrayOpNode : public CompoundNode
{
public:
    NewArrayOpNode(const SourcePos& sourcePos_);
    NewArrayOpNode(const SourcePos& sourcePos_, const SourcePos& lbPos_, const SourcePos& rbPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const SourcePos& LBracketPos() const { return lbPos; }
    const SourcePos& RBracketPos() const { return rbPos; }
private:
    SourcePos lbPos;
    SourcePos rbPos;
};

class AST_API NewOpNode : public Node
{
public:
    NewOpNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API DeleteArrayOpNode : public CompoundNode
{
public:
    DeleteArrayOpNode(const SourcePos& sourcePos_);
    DeleteArrayOpNode(const SourcePos& sourcePos_, const SourcePos& lbPos_, const SourcePos& rbPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const SourcePos& LBracketPos() const { return lbPos; }
    const SourcePos& RBracketPos() const { return rbPos; }
private:
    SourcePos lbPos;
    SourcePos rbPos;
};

class AST_API DeleteOpNode : public Node
{
public:
    DeleteOpNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API CoAwaitOpNode : public Node
{
public:
    CoAwaitOpNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API InvokeOpNode : public Node
{
public:
    InvokeOpNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API SubscriptOpNode : public Node
{
public:
    SubscriptOpNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API OperatorFunctionIdNode : public BinaryNode
{
public:
    OperatorFunctionIdNode(const SourcePos& sourcePos_);
    OperatorFunctionIdNode(const SourcePos& sourcePos_, Node* operatorKwNode_, Node* op_);
    void Accept(Visitor& visitor) override;
};

class AST_API ConversionFunctionIdNode : public BinaryNode
{
public:
    ConversionFunctionIdNode(const SourcePos& sourcePos_);
    ConversionFunctionIdNode(const SourcePos& sourcePos_, Node* operatorKwNode_, Node* conversionTypeId_);
    void Accept(Visitor& visitor) override;
};

class AST_API ConversionTypeIdNode : public CompoundNode
{
public:
    ConversionTypeIdNode(const SourcePos& sourcePos_);
    ConversionTypeIdNode(const SourcePos& sourcePos_, Node* typeSpecifierSeq_, Node* conversionDeclarator_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* TypeSpecifierSeq() const { return typeSpecifierSeq.get(); }
    Node* ConversionDeclarator() const { return conversionDeclarator.get(); }
private:
    std::unique_ptr<Node> typeSpecifierSeq;
    std::unique_ptr<Node> conversionDeclarator;
};

class AST_API ConversionDeclaratorNode : public CompoundNode
{
public:
    ConversionDeclaratorNode(const SourcePos& sourcePos_);
    ConversionDeclaratorNode(const SourcePos& sourcePos_, Node* ptrOp_, Node* conversionDeclarator_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* PtrOp() const { return ptrOp.get(); }
    Node* ConversionDeclarator() const { return conversionDeclarator.get(); }
private:
    std::unique_ptr<Node> ptrOp;
    std::unique_ptr<Node> conversionDeclarator;
};

class AST_API DestructorIdNode : public UnaryNode
{
public:
    DestructorIdNode(const SourcePos& sourcePos_);
    DestructorIdNode(const SourcePos& sourcePos_, Node* typeName_);
    void Accept(Visitor& visitor) override;
};

class AST_API ParameterNode : public CompoundNode
{
public:
    ParameterNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Attributes() const { return attributes.get(); }
    void SetAttributes(Node* attributes_);
    Node* DeclSpecifiers() const { return declSpecifiers.get(); }
    void SetDeclSpecifiers(Node* declSpecifiers_);
    Node* Declarator() const { return declarator.get(); }
    void SetDeclarator(Node* declarator_);
    Node* Assign() const { return assign.get(); }
    void SetAssign(Node* assign_);
    Node* Initializer() const { return initializer.get(); }
    void SetInitializer(Node* initializer_);
private:
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> declSpecifiers;
    std::unique_ptr<Node> declarator;
    std::unique_ptr<Node> assign;
    std::unique_ptr<Node> initializer;
};

class AST_API ParameterListNode : public ListNode
{
public:
    ParameterListNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    void SetLParenPos(const SourcePos& lpPos_) { lpPos = lpPos_; }
    void SetRParenPos(const SourcePos& rpPos_) { rpPos = rpPos_; }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API NoexceptNode : public Node
{
public:
    NoexceptNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API FunctionTryBlockNode : public CompoundNode
{
public:
    FunctionTryBlockNode(const SourcePos& sourcePos_);
    FunctionTryBlockNode(const SourcePos& sourcePos_, Node* ctorInitializer_, Node* tryBlock_, Node* handlers_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* CtorInitializer() const { return ctorInitializer.get(); }
    Node* TryBlock() const { return tryBlock.get(); }
    Node* Handlers() const { return handlers.get(); }
private:
    std::unique_ptr<Node> ctorInitializer;
    std::unique_ptr<Node> tryBlock;
    std::unique_ptr<Node> handlers;
};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_FUNCTION_INCLUDED
