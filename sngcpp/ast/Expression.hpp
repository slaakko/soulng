// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_EXPRESSION_INCLUDED
#define SNGCPP_AST_EXPRESSION_INCLUDED
#include <sngcpp/ast/SimpleType.hpp>
#include <sngcpp/ast/Statement.hpp>

namespace sngcpp { namespace ast {

class CompoundStatementNode;

enum class Operator : uint8_t
{
    assign, mulAssign, divAssign, remAssign, addAssign, subAssign, shiftRightAssign, shiftLeftAssign, andAssign, xorAssign, orAssign,
    equal, notEqual, lessOrEqual, greaterOrEqual, less, greater, shiftLeft, shiftRight, add, sub, mul, div, rem, dotStar, arrowStar, arrow, 
    inc, dec, deref, addrOf, unaryPlus, unaryMinus, not_, complement, sizeOf, alignOf, dynamicCast, staticCast, reinterpretCast, constCast,
    logicalAnd, logicalOr, xor_, and_, or_, apply, subscript, comma, newArray, deleteArray, new_, delete_
};

SNGCPP_AST_API std::u32string OpStr(Operator op);

class SNGCPP_AST_API ExpressionSequenceNode : public BinaryNode
{
public:
    ExpressionSequenceNode();
    ExpressionSequenceNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API CommaExpressionNode : public BinaryNode
{
public:
    CommaExpressionNode();
    CommaExpressionNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API AssignmentExpressionNode : public BinaryNode
{
public:
    AssignmentExpressionNode();
    AssignmentExpressionNode(const Span& span_, Node* left_, Operator op_, Node* right_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Operator Op() const { return op; }
private:
    Operator op;
};

class SNGCPP_AST_API ConditionalExpressionNode : public Node
{
public:
    ConditionalExpressionNode();
    ConditionalExpressionNode(const Span& span_, Node* condition_, Node* thenExpr_, Node* elseExpr_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Condition() { return condition.get(); }
    Node* ThenExpr() { return thenExpr.get(); }
    Node* ElseExpr() { return elseExpr.get(); }
private:
    std::unique_ptr<Node> condition;
    std::unique_ptr<Node> thenExpr;
    std::unique_ptr<Node> elseExpr;
};

class SNGCPP_AST_API ThrowExpressionNode : public UnaryNode
{
public:
    ThrowExpressionNode();
    ThrowExpressionNode(const Span& span_, Node* exceptionExpr_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API LogicalOrExpressionNode : public BinaryNode
{
public:
    LogicalOrExpressionNode();
    LogicalOrExpressionNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API LogicalAndExpressionNode : public BinaryNode
{
public:
    LogicalAndExpressionNode();
    LogicalAndExpressionNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API InclusiveOrExpressionNode : public BinaryNode
{
public:
    InclusiveOrExpressionNode();
    InclusiveOrExpressionNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API ExclusiveOrExpressionNode : public BinaryNode
{
public:
    ExclusiveOrExpressionNode();
    ExclusiveOrExpressionNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API AndExpressionNode : public BinaryNode
{
public:
    AndExpressionNode();
    AndExpressionNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API EqualityExpressionNode : public BinaryNode
{
public:
    EqualityExpressionNode();
    EqualityExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Operator Op() const { return op; }
private:
    Operator op;
};

class SNGCPP_AST_API RelationalExpressionNode : public BinaryNode
{
public:
    RelationalExpressionNode();
    RelationalExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Operator Op() const { return op; }
private:
    Operator op;
};

class SNGCPP_AST_API ShiftExpressionNode : public BinaryNode
{
public:
    ShiftExpressionNode();
    ShiftExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Operator Op() const { return op; }
private:
    Operator op;
};

class SNGCPP_AST_API AdditiveExpressionNode : public BinaryNode
{
public:
    AdditiveExpressionNode();
    AdditiveExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Operator Op() const { return op; }
private:
    Operator op;
};

class SNGCPP_AST_API MultiplicativeExpressionNode : public BinaryNode
{
public:
    MultiplicativeExpressionNode();
    MultiplicativeExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Operator Op() const { return op; }
private:
    Operator op;
};

class SNGCPP_AST_API PMExpressionNode : public BinaryNode
{
public:
    PMExpressionNode();
    PMExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Operator Op() const { return op; }
private:
    Operator op;
};

class SNGCPP_AST_API CastExpressionNode : public Node
{
public:
    CastExpressionNode();
    CastExpressionNode(const Span& span_, Node* typeExpr_, Node* expr_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* TypeExpr() { return typeExpr.get(); }
    Node* Expr() { return expr.get(); }
private:
    std::unique_ptr<Node> typeExpr;
    std::unique_ptr<Node> expr;
};

class SNGCPP_AST_API UnaryExpressionNode : public UnaryNode
{
public:
    UnaryExpressionNode();
    UnaryExpressionNode(const Span& span_, Operator op_, Node* expr_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Operator Op() const { return op; }
private:
    Operator op;
};

class SNGCPP_AST_API NewExpressionNode : public Node
{
public:
    NewExpressionNode();
    NewExpressionNode(const Span& span_, Node* placement_, Node* typeExpr_, Node* initializer_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Placement() { return placement.get(); }
    Node* TypeExpr() { return typeExpr.get(); }
    Node* Initializer() { return initializer.get(); }
private:
    std::unique_ptr<Node> placement;
    std::unique_ptr<Node> typeExpr;
    std::unique_ptr<Node> initializer;
};

class SNGCPP_AST_API DeleteExpressionNode : public UnaryNode
{
public:
    DeleteExpressionNode();
    DeleteExpressionNode(const Span& span_, bool array__, Node* ptr_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    bool Array() const { return array_; }
private:
    bool array_;
};

class SNGCPP_AST_API SubscriptExpressionNode : public UnaryNode
{
public:
    SubscriptExpressionNode();
    SubscriptExpressionNode(const Span& span_, Node* subject_, Node* index_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Index() { return index.get(); }
private:
    std::unique_ptr<Node> index;
};

class SNGCPP_AST_API InvokeExpressionNode : public UnaryNode
{
public:
    InvokeExpressionNode();
    InvokeExpressionNode(const Span& span_, Node* subject_, Node* arguments_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Arguments() { return arguments.get(); }
private:
    std::unique_ptr<Node> arguments;
};

class SNGCPP_AST_API DotNode : public UnaryNode
{
public:
    DotNode();
    DotNode(const Span& span_, Node* subject_, Node* id_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Id() { return id.get(); }
private:
    std::unique_ptr<Node> id;
};

class SNGCPP_AST_API ArrowNode : public UnaryNode
{
public:
    ArrowNode();
    ArrowNode(const Span& span_, Node* subject_, Node* id_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Id() { return id.get(); }
private:
    std::unique_ptr<Node> id;
};

class SNGCPP_AST_API PostfixIncNode : public UnaryNode
{
public:
    PostfixIncNode();
    PostfixIncNode(const Span& span_, Node* subject_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API PostfixDecNode : public UnaryNode
{
public:
    PostfixDecNode();
    PostfixDecNode(const Span& span_, Node* subject_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API CppCastExpressionNode : public Node
{
public:
    CppCastExpressionNode();
    CppCastExpressionNode(const Span& span_, Node* typeExpr_, Node* expr_, Operator op_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* TypeExpr() { return typeExpr.get(); }
    Node* Expr() { return expr.get(); }
    Operator Op() const { return op; }
private:
    std::unique_ptr<Node> typeExpr;
    std::unique_ptr<Node> expr;
    Operator op;
};

class SNGCPP_AST_API TypeIdExpressionNode : public UnaryNode
{
public:
    TypeIdExpressionNode();
    TypeIdExpressionNode(const Span& span_, Node* subject_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API ThisNode : public Node
{
public:
    ThisNode();
    ThisNode(const Span& span_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API IdentifierNode : public Node
{
public:
    IdentifierNode();
    IdentifierNode(NodeType nodeType_);
    IdentifierNode(const Span& span_, const std::u32string& identifier_);
    IdentifierNode(NodeType nodeType_, const Span& span_, const std::u32string& identifier_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    bool IsIdentifierNode() const override { return true; }
    const std::u32string& Identifier() const { return identifier; }
private:
    std::u32string identifier;
};

class SNGCPP_AST_API OperatorFunctionIdNode : public IdentifierNode
{
public:
    OperatorFunctionIdNode();
    OperatorFunctionIdNode(const Span& span_, Operator op_);
    bool IsOperatorFunctionIdNode() const override { return true; }
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Operator Op() const { return op; }
    std::u32string OpStr() const;
    std::u32string Str() const;
    std::u32string GroupName() const;
private:
    Operator op;
};

class SNGCPP_AST_API ConversionFunctionIdNode : public IdentifierNode
{
public:
    ConversionFunctionIdNode();
    ConversionFunctionIdNode(const Span& span_, Node* typeExpr_);
    bool IsConversionFunctionIdNode() const override { return true; }
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* TypeExpr() { return typeExpr.get(); }
private:
    std::unique_ptr<Node> typeExpr;
};

class SNGCPP_AST_API DtorIdNode : public IdentifierNode
{
public:
    DtorIdNode();
    DtorIdNode(const Span& span_, const std::u32string& identifier_);
    bool IsDtorIdNode() const override { return true; }
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API NestedIdNode : public BinaryNode
{
public:
    NestedIdNode();
    NestedIdNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API ParenthesizedExprNode : public UnaryNode
{
public:
    ParenthesizedExprNode();
    ParenthesizedExprNode(const Span& span_, Node* expr_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API LambdaExpressionNode : public Node
{
public:
    LambdaExpressionNode();
    LambdaExpressionNode(const Span& span_);
    void AddCapture(Node* capture);
    Node* Captures() { return captures.get(); }
    void SetParameters(Node* parameters_);
    Node* Parameters() { return parameters.get(); }
    void SetBody(CompoundStatementNode* body_);
    CompoundStatementNode* Body() { return body.get(); }
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
private:
    std::unique_ptr<Node> captures;
    std::unique_ptr<Node> parameters;
    std::unique_ptr<CompoundStatementNode> body;
};

class SNGCPP_AST_API CaptureSequenceNode : public BinaryNode
{
public:
    CaptureSequenceNode();
    CaptureSequenceNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API AssignCaptureNode : public Node
{
public:
    AssignCaptureNode();
    AssignCaptureNode(const Span& span_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API RefCaptureNode : public Node
{
public:
    RefCaptureNode();
    RefCaptureNode(const Span& span_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API ThisCaptureNode : public Node
{
public:
    ThisCaptureNode();
    ThisCaptureNode(const Span& span_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API IdentifierCaptureNode : public UnaryNode
{
public:
    IdentifierCaptureNode();
    IdentifierCaptureNode(const Span& span_, IdentifierNode* id_);
    void Accept(Visitor& visitor) override;
};

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_EXPRESSION_INCLUDED
