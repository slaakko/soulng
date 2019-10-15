// =================================
// Copyright (c) 2019 Seppo Laakko
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
    ExpressionSequenceNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API CommaExpressionNode : public BinaryNode
{
public:
    CommaExpressionNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API AssignmentExpressionNode : public BinaryNode
{
public:
    AssignmentExpressionNode(const Span& span_, Node* left_, Operator op_, Node* right_);
    void Accept(Visitor& visitor) override;
    Operator Op() const { return op; }
private:
    Operator op;
};

class SNGCPP_AST_API ConditionalExpressionNode : public Node
{
public:
    ConditionalExpressionNode(const Span& span_, Node* condition_, Node* thenExpr_, Node* elseExpr_);
    void Accept(Visitor& visitor) override;
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
    ThrowExpressionNode(const Span& span_, Node* exceptionExpr_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API LogicalOrExpressionNode : public BinaryNode
{
public:
    LogicalOrExpressionNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API LogicalAndExpressionNode : public BinaryNode
{
public:
    LogicalAndExpressionNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API InclusiveOrExpressionNode : public BinaryNode
{
public:
    InclusiveOrExpressionNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API ExclusiveOrExpressionNode : public BinaryNode
{
public:
    ExclusiveOrExpressionNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API AndExpressionNode : public BinaryNode
{
public:
    AndExpressionNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API EqualityExpressionNode : public BinaryNode
{
public:
    EqualityExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_);
    void Accept(Visitor& visitor) override;
    Operator Op() const { return op; }
private:
    Operator op;
};

class SNGCPP_AST_API RelationalExpressionNode : public BinaryNode
{
public:
    RelationalExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_);
    void Accept(Visitor& visitor) override;
    Operator Op() const { return op; }
private:
    Operator op;
};

class SNGCPP_AST_API ShiftExpressionNode : public BinaryNode
{
public:
    ShiftExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_);
    void Accept(Visitor& visitor) override;
    Operator Op() const { return op; }
private:
    Operator op;
};

class SNGCPP_AST_API AdditiveExpressionNode : public BinaryNode
{
public:
    AdditiveExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_);
    void Accept(Visitor& visitor) override;
    Operator Op() const { return op; }
private:
    Operator op;
};

class SNGCPP_AST_API MultiplicativeExpressionNode : public BinaryNode
{
public:
    MultiplicativeExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_);
    void Accept(Visitor& visitor) override;
    Operator Op() const { return op; }
private:
    Operator op;
};

class SNGCPP_AST_API PMExpressionNode : public BinaryNode
{
public:
    PMExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_);
    void Accept(Visitor& visitor) override;
    Operator Op() const { return op; }
private:
    Operator op;
};

class SNGCPP_AST_API CastExpressionNode : public Node
{
public:
    CastExpressionNode(const Span& span_, Node* typeExpr_, Node* expr_);
    void Accept(Visitor& visitor) override;
    Node* TypeExpr() { return typeExpr.get(); }
    Node* Expr() { return expr.get(); }
private:
    std::unique_ptr<Node> typeExpr;
    std::unique_ptr<Node> expr;
};

class SNGCPP_AST_API UnaryExpressionNode : public UnaryNode
{
public:
    UnaryExpressionNode(const Span& span_, Operator op_, Node* expr_);
    void Accept(Visitor& visitor) override;
    Operator Op() const { return op; }
private:
    Operator op;
};

class SNGCPP_AST_API NewExpressionNode : public Node
{
public:
    NewExpressionNode(const Span& span_, Node* placement_, Node* typeExpr_, Node* initializer_);
    void Accept(Visitor& visitor) override;
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
    DeleteExpressionNode(const Span& span_, bool array__, Node* ptr_);
    void Accept(Visitor& visitor) override;
    bool Array() const { return array_; }
private:
    bool array_;
};

class SNGCPP_AST_API SubscriptExpressionNode : public UnaryNode
{
public:
    SubscriptExpressionNode(const Span& span_, Node* subject_, Node* index_);
    void Accept(Visitor& visitor) override;
    Node* Index() { return index.get(); }
private:
    std::unique_ptr<Node> index;
};

class SNGCPP_AST_API InvokeExpressionNode : public UnaryNode
{
public:
    InvokeExpressionNode(const Span& span_, Node* subject_, Node* arguments_);
    void Accept(Visitor& visitor) override;
    Node* Arguments() { return arguments.get(); }
private:
    std::unique_ptr<Node> arguments;
};

class SNGCPP_AST_API DotNode : public UnaryNode
{
public:
    DotNode(const Span& span_, Node* subject_, Node* id_);
    void Accept(Visitor& visitor) override;
    Node* Id() { return id.get(); }
private:
    std::unique_ptr<Node> id;
};

class SNGCPP_AST_API ArrowNode : public UnaryNode
{
public:
    ArrowNode(const Span& span_, Node* subject_, Node* id_);
    void Accept(Visitor& visitor) override;
    Node* Id() { return id.get(); }
private:
    std::unique_ptr<Node> id;
};

class SNGCPP_AST_API PostfixIncNode : public UnaryNode
{
public:
    PostfixIncNode(const Span& span_, Node* subject_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API PostfixDecNode : public UnaryNode
{
public:
    PostfixDecNode(const Span& span_, Node* subject_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API CppCastExpressionNode : public Node
{
public:
    CppCastExpressionNode(const Span& span_, Node* typeExpr_, Node* expr_, Operator op_);
    void Accept(Visitor& visitor) override;
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
    TypeIdExpressionNode(const Span& span_, Node* subject_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API ThisNode : public Node
{
public:
    ThisNode(const Span& span_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API IdentifierNode : public Node
{
public:
    IdentifierNode(const Span& span_, const std::u32string& identifier_);
    void Accept(Visitor& visitor) override;
    bool IsIdentifierNode() const override { return true; }
    const std::u32string& Identifier() const { return identifier; }
private:
    std::u32string identifier;
};

class SNGCPP_AST_API OperatorFunctionIdNode : public IdentifierNode
{
public:
    OperatorFunctionIdNode(const Span& span_, Operator op_);
    bool IsOperatorFunctionIdNode() const override { return true; }
    void Accept(Visitor& visitor) override;
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
    ConversionFunctionIdNode(const Span& span_, Node* typeExpr_);
    bool IsConversionFunctionIdNode() const override { return true; }
    void Accept(Visitor& visitor) override;
    Node* TypeExpr() { return typeExpr.get(); }
private:
    std::unique_ptr<Node> typeExpr;
};

class SNGCPP_AST_API DtorIdNode : public IdentifierNode
{
public:
    DtorIdNode(const Span& span_, const std::u32string& identifier_);
    bool IsDtorIdNode() const override { return true; }
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API NestedIdNode : public BinaryNode
{
public:
    NestedIdNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API ParenthesizedExprNode : public UnaryNode
{
public:
    ParenthesizedExprNode(const Span& span_, Node* expr_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API LambdaExpressionNode : public Node
{
public:
    LambdaExpressionNode(const Span& span_);
    void AddCapture(Node* capture);
    void SetParameters(Node* parameters_);
    void SetBody(CompoundStatementNode* body_);
    void Accept(Visitor& visitor) override;
private:
    std::unique_ptr<Node> captures;
    std::unique_ptr<Node> parameters;
    std::unique_ptr<CompoundStatementNode> body;
};

class SNGCPP_AST_API CaptureSequenceNode : public BinaryNode
{
public:
    CaptureSequenceNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API AssignCapture : public Node
{
public:
    AssignCapture(const Span& span_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API RefCapture : public Node
{
public:
    RefCapture(const Span& span_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API ThisCapture : public Node
{
public:
    ThisCapture(const Span& span_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API IdentifierCapture : public UnaryNode
{
public:
    IdentifierCapture(const Span& span_, IdentifierNode* id_);
    void Accept(Visitor& visitor) override;
};

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_EXPRESSION_INCLUDED
