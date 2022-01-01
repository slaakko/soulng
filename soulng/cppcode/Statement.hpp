// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_CPPCODE_STATEMENT_INCLUDED
#define SOULNG_CPPCODE_STATEMENT_INCLUDED
#include <soulng/cppcode/Object.hpp>

namespace soulng { namespace cppcode  {

class CPPCODE_API Statement: public CppObject
{
public:
    Statement(const std::u32string& name_);
    virtual bool IsCompoundStatement() const { return false; }
    void SetParent(Statement* parent_) { parent = parent_; }
    Statement* Parent() const { return parent; }
    virtual void Replace(Statement* oldS, Statement* newS);
private:
    Statement* parent;
};

class CPPCODE_API LabeledStatement: public Statement
{
public:
    LabeledStatement(const std::u32string& label_, Statement* statement_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
    void Replace(Statement* oldS, Statement* newS) override;
private:
    std::u32string label;
    Statement* statement;
};

class CPPCODE_API CaseStatement: public Statement
{
public:
    CaseStatement(CppObject* expression_, Statement* statement_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
    void Replace(Statement* oldS, Statement* newS) override;
private:
    CppObject* expression;
    Statement* statement;
};

class CPPCODE_API DefaultStatement : public Statement
{
public:
    DefaultStatement(Statement* statement_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
    void Replace(Statement* oldS, Statement* newS) override;
private:
    Statement* statement;
};

class CPPCODE_API EmptyStatement : public Statement
{
public:
    EmptyStatement();
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
};

class CPPCODE_API ExpressionStatement : public Statement
{
public:
    ExpressionStatement(CppObject* expression_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    CppObject* expression;
};

class CPPCODE_API CompoundStatement : public Statement
{
public:
    CompoundStatement();
    void InsertFront(Statement* statement, bool own);
    void Add(Statement* statement);
    bool IsCompoundStatement() const override { return true; }
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
    const std::vector<Statement*> Statements() const { return statements; }
    void Replace(Statement* oldS, Statement* newS) override;
private:
    std::vector<Statement*> statements;
};

typedef std::shared_ptr<CompoundStatement> CompoundStatementPtr;

class CPPCODE_API SelectionStatement : public Statement
{
public:
    SelectionStatement(const std::u32string& name_);
};

class CPPCODE_API IfStatement : public SelectionStatement
{
public:
    IfStatement(CppObject* condition_, Statement* thenStatement_, Statement* elseStatement_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
    void Replace(Statement* oldS, Statement* newS) override;
private:
    CppObject* condition;
    Statement* thenStatement;
    Statement* elseStatement;
};

class CPPCODE_API SwitchStatement : public SelectionStatement
{
public:
    SwitchStatement(CppObject* condition_, Statement* statement_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
    void Replace(Statement* oldS, Statement* newS) override;
private:
    CppObject* condition;
    Statement* statement;
};

class CPPCODE_API IterationStatement : public Statement
{
public:
    IterationStatement(const std::u32string& name_);
};

class CPPCODE_API WhileStatement : public IterationStatement
{
public:
    WhileStatement(CppObject* condition_, Statement* statement_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
    void Replace(Statement* oldS, Statement* newS) override;
private:
    CppObject* condition;
    Statement* statement;
};

class CPPCODE_API DoStatement : public IterationStatement
{
public:
    DoStatement(Statement* statement_, CppObject* condition_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
    void Replace(Statement* oldS, Statement* newS) override;
private:
    Statement* statement;
    CppObject* condition;
};

class CPPCODE_API ForStatement : public IterationStatement
{
public:
    ForStatement(CppObject* initialization_, CppObject* condition_, CppObject* iteration_, Statement* statement_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
    void Replace(Statement* oldS, Statement* newS) override;
private:
    CppObject* initialization;
    CppObject* condition;
    CppObject* iteration;
    Statement* statement;
};

class CPPCODE_API JumpStatement : public Statement
{
public:
    JumpStatement(const std::u32string& name_);
};

class CPPCODE_API BreakStatement : public JumpStatement
{
public:
    BreakStatement();
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
};

class CPPCODE_API ContinueStatement : public JumpStatement
{
public:
    ContinueStatement();
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
};

class CPPCODE_API GotoStatement : public JumpStatement
{
public:
    GotoStatement(const std::u32string& target_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    std::u32string target;
};

class CPPCODE_API ReturnStatement : public JumpStatement
{
public:
    ReturnStatement(CppObject* expression_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
    void SetExpression(CppObject* expression_);
    CppObject* GetExpression() const { return expression; }
private:
    CppObject* expression;
};

class TypeId;

class CPPCODE_API ConditionWithDeclarator : public CppObject
{
public:
    ConditionWithDeclarator(TypeId* type_, const std::u32string& declarator_, CppObject* expression_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
    TypeId* Type() const { return type; }
    const std::u32string& Declarator() const { return declarator; }
    CppObject* Expression() const { return expression; }
private:
    TypeId* type;
    std::u32string declarator;
    CppObject* expression;
};

class CPPCODE_API ForRangeDeclaration : public CppObject
{
public:
    ForRangeDeclaration();
    TypeId* GetTypeId() { return typeId; }
    void SetDeclarator(const std::u32string& declarator_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    TypeId* typeId;
    std::u32string declarator;
};

class CPPCODE_API RangeForStatement : public IterationStatement
{
public:
    RangeForStatement(ForRangeDeclaration* declaration_, CppObject* container_, Statement* statement_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
    void Replace(Statement* oldS, Statement* newS) override;
private:
    ForRangeDeclaration* declaration;
    CppObject* container;
    Statement* statement;
};

class CPPCODE_API DeclarationStatement : public Statement
{
public:
    DeclarationStatement(CppObject* declaration_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    CppObject* declaration;
};

class CPPCODE_API ExceptionDeclaration : public CppObject
{
public:
    ExceptionDeclaration();
    TypeId* GetTypeId() const { return typeId; }
    bool CatchAll() const { return catchAll; }
    bool& CatchAll() { return catchAll; }
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    TypeId* typeId;
    bool catchAll;
};

typedef std::shared_ptr<ExceptionDeclaration> ExceptionDeclarationPtr;

class CPPCODE_API Handler : public CppObject
{
public:
    Handler(ExceptionDeclaration* exceptionDeclaration_, CompoundStatement* statement_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    ExceptionDeclaration* exceptionDeclaration;
    CompoundStatement* statement;
};

class CPPCODE_API TryStatement : public Statement
{
public:
    TryStatement(CompoundStatement* statement_);
    void Add(Handler* handler);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
    CompoundStatement* GetStatement() const { return statement; }
private:
    CompoundStatement* statement;
    std::vector<Handler*> handlers;
};

class CPPCODE_API IfDefStatement : public Statement
{
public:
    IfDefStatement(CppObject* symbol_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    CppObject* symbol;
};

class CPPCODE_API EndIfStatement : public Statement
{
public:
    EndIfStatement(CppObject* comment_);
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    CppObject* comment;
};

} } // namespace soulng::cppcode

#endif // SOULNG_CPPCODE_STATEMENT_INCLUDED
