// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_CPPCODE_EXPRESSION_INCLUDED
#define SOULNG_CPPCODE_EXPRESSION_INCLUDED
#include <soulng/cppcode/Object.hpp>
#include <soulng/cppcode/Operator.hpp>

namespace soulng { namespace cppcode  {

void PrintExprs(const std::vector<CppObject*>& expressions, CodeFormatter& formatter);

class CPPCODE_API Expression : public CppObject
{
public:
    Expression(const std::u32string& name_);
};

class CPPCODE_API ThisAccess : public Expression
{
public:
    ThisAccess();
    void Accept(Visitor& visitor) override;
};

class CPPCODE_API IdExpr : public Expression
{
public:
    IdExpr(const std::u32string& value_);
    void Accept(Visitor& visitor) override;
};

class CPPCODE_API UnaryExpression : public Expression
{
public:
    UnaryExpression(const std::u32string& name_, CppObject* child_);
    CppObject* Child() const { return child; }
private:
    CppObject* child;
};

class CPPCODE_API PostfixExpression : public UnaryExpression
{
public:
    PostfixExpression(const std::u32string& name_, CppObject* child_);
};

class CPPCODE_API IndexExpr : public PostfixExpression
{
public:
    IndexExpr(CppObject* child_, CppObject* index_);
    CppObject* Index() const { return index; }
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    CppObject* index;
};

class CPPCODE_API ExpressionList : public CppObject
{
public:
    ExpressionList();
    void AddExpr(CppObject* arg) override;
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
    const std::vector<CppObject*>& Args() const { return arguments; }
private:
    std::vector<CppObject*> arguments;
};

class CPPCODE_API InvokeExpr : public PostfixExpression
{
public:
    InvokeExpr(CppObject* child_);
    void AddExpr(CppObject* arg) override;
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    std::vector<CppObject*> arguments;
};

class CPPCODE_API MemberAccessExpr : public PostfixExpression
{
public:
    MemberAccessExpr(CppObject* child_, CppObject* member_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    CppObject* member;
};

class CPPCODE_API PtrMemberAccessExpr : public PostfixExpression
{
public:
    PtrMemberAccessExpr(CppObject* child_, CppObject* member_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    CppObject* member;
};

class CPPCODE_API PostIncrementExpr : public PostfixExpression
{
public:
    PostIncrementExpr(CppObject* child_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
};

class CPPCODE_API PostDecrementExpr : public PostfixExpression
{
public:
    PostDecrementExpr(CppObject* child_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
};

class CPPCODE_API PostCastExpr: public PostfixExpression
{
public:
    PostCastExpr(const std::u32string& name_, CppObject* type_, CppObject* child_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    CppObject* type;
};

class CPPCODE_API TypeIdExpr : public PostfixExpression
{
public:
    TypeIdExpr(CppObject* child_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
};

class CPPCODE_API PreIncrementExpr : public UnaryExpression
{
public:
    PreIncrementExpr(CppObject* child_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
};

class CPPCODE_API PreDecrementExpr : public UnaryExpression
{
public:
    PreDecrementExpr(CppObject* child_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
};

class CPPCODE_API UnaryOpExpr : public UnaryExpression
{
public:
    UnaryOpExpr(Operator op_, CppObject* child_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
    Operator Op() const { return op; }
private:
    Operator op;
};

class CPPCODE_API SizeOfExpr : public UnaryExpression
{
public:
    SizeOfExpr(CppObject* child_, bool parens_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    bool parens;
};

class CPPCODE_API CastExpr : public Expression
{
public:
    CastExpr(CppObject* typeId_, CppObject* expr_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    CppObject* typeId;
    CppObject* expr;
};

class CPPCODE_API BinaryExpression : public Expression
{
public:
    BinaryExpression(const std::u32string& name_, CppObject* left_, CppObject* right_);
    CppObject* Left() const { return left; }
    CppObject* Right() const { return right; }
private:
    CppObject* left;
    CppObject* right;
};

class CPPCODE_API BinaryOpExpr : public BinaryExpression
{
public:
    BinaryOpExpr(CppObject* left_, Operator op_, CppObject* right_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
    Operator Op() const { return op; }
private:
    Operator op;
};

class CPPCODE_API ConditionalExpr : public Expression
{
public:
    ConditionalExpr(CppObject* condition_, CppObject* thenExpr_, CppObject* elseExpr_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    CppObject* condition;
    CppObject* thenExpr;
    CppObject* elseExpr;
};

class CPPCODE_API ThrowExpr : public Expression
{
public:
    ThrowExpr(CppObject* exception_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    CppObject* exception;
};

class TypeId;

class CPPCODE_API NewExpr : public Expression
{
public:
    NewExpr(bool global_);
    void BeginAddPlacement() { addPlacement = true; }
    void EndAddPlacement() { addPlacement = false; }
    void BeginAddInitializer() { addInitializer = true; }
    void EndAddInitializer() { addInitializer = false; }
    void AddExpr(CppObject* expr) override;
    void SetTypeId(TypeId* typeId_);
    void SetParens(bool parens_) { parens = parens_; }
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    bool global;
    bool addPlacement;
    bool addInitializer;
    std::vector<CppObject*> placement;
    TypeId* typeId;
    bool parens;
    std::vector<CppObject*> initializer;
};

class CPPCODE_API DeleteExpr : public Expression
{
public:
    DeleteExpr(bool global_, bool isArray_, CppObject* expr_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    bool global;
    bool isArray;
    CppObject* expr;
};

class CPPCODE_API ParenExpr : public Expression
{
public:
    ParenExpr(CppObject* expr_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    CppObject* expr;
};

} } // namespace soulng::cppcode

#endif // SOULNG_CPPCODE_EXPRESSION_INCLUDED

