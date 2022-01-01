// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/cppcode/Statement.hpp>
#include <soulng/cppcode/Visitor.hpp>
#include <soulng/cppcode/Type.hpp>
#include <soulng/util/Unicode.hpp>

namespace soulng { namespace cppcode  {

using namespace soulng::util;
using namespace soulng::unicode;

Statement::Statement(const std::u32string& name_): CppObject(name_), parent(nullptr)
{
}

void Statement::Replace(Statement* oldS, Statement* newS)
{
    throw std::runtime_error(ToUtf8(Name()) + ": cannot replace statement");
}

LabeledStatement::LabeledStatement(const std::u32string& label_, Statement* statement_): Statement(U"labeledStatement"), label(label_), statement(statement_) 
{
    statement->SetParent(this);
    Own(statement);
}

void LabeledStatement::Replace(Statement* oldS, Statement* newS)
{
    if (statement == oldS)
    {
        Own(newS);
        statement = newS;
    }
    else
    {
        Statement::Replace(oldS, newS);
    }
}

void LabeledStatement::Print(CodeFormatter& formatter)
{
    formatter.Write(ToUtf8(label));
    formatter.Write(" : ");
    statement->Print(formatter);
}

void LabeledStatement::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
    statement->Accept(visitor);
}

CaseStatement::CaseStatement(CppObject* expression_, Statement* statement_): Statement(U"case"), expression(expression_), statement(statement_) 
{
    statement->SetParent(this);
    Own(expression);
    Own(statement);
}

void CaseStatement::Replace(Statement* oldS, Statement* newS)
{
    if (statement == oldS)
    {
        Own(newS);
        statement = newS;
    }
    else
    {
        Statement::Replace(oldS, newS);
    }
}

void CaseStatement::Print(CodeFormatter& formatter)
{
    formatter.Write("case ");
    expression->Print(formatter);
    formatter.Write(": ");
    statement->Print(formatter);
}

void CaseStatement::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
    expression->Accept(visitor);
    statement->Accept(visitor);
}

DefaultStatement::DefaultStatement(Statement* statement_): Statement(U"default"), statement(statement_) 
{
    statement->SetParent(this);
    Own(statement);
}

void DefaultStatement::Replace(Statement* oldS, Statement* newS)
{
    if (statement == oldS)
    {
        Own(newS);
        statement = newS;
    }
    else
    {
        Statement::Replace(oldS, newS);
    }
}

void DefaultStatement::Print(CodeFormatter& formatter)
{
    formatter.Write("default: ");
    statement->Print(formatter);
}

void DefaultStatement::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
    statement->Accept(visitor);
}

EmptyStatement::EmptyStatement(): Statement(U"empty") 
{
}

void EmptyStatement::Print(CodeFormatter& formatter)
{
    formatter.Write(";");
}

void EmptyStatement::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ExpressionStatement::ExpressionStatement(CppObject* expression_): Statement(U"expression"), expression(expression_) 
{
    Own(expression);
}

void ExpressionStatement::Print(CodeFormatter& formatter)
{
    expression->Print(formatter);
    formatter.WriteLine(";");
}

void ExpressionStatement::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
    expression->Accept(visitor);
}

CompoundStatement::CompoundStatement(): Statement(U"compound") 
{
}

void CompoundStatement::InsertFront(Statement* statement, bool own)
{
    statement->SetParent(this);
    if (own)
    {
        Own(statement);
    }
    statements.insert(statements.begin(), 1, statement);
}

void CompoundStatement::Add(Statement* statement) 
{
    statement->SetParent(this);
    Own(statement);
    statements.push_back(statement); 
}

void CompoundStatement::Replace(Statement* oldS, Statement* newS)
{
    std::vector<Statement*>::iterator it = statements.begin();
    for (std::vector<Statement*>::iterator it = statements.begin(); it != statements.end(); ++it)
    {
        if (*it == oldS)
        {
            Own(newS);
            it = statements.insert(it, newS);
            ++it;
            statements.erase(it);
            return;
        }
    }
    Statement::Replace(oldS, newS);
}

void CompoundStatement::Print(CodeFormatter& formatter)
{
    formatter.WriteLine("{");
    formatter.IncIndent();
    if (formatter.Start())
    {
        formatter.WriteLine(formatter.StartText());
        formatter.ResetStart();
    }
    int n = int(statements.size());
    for (int i = 0; i < n; ++i)
    {
        statements[i]->Print(formatter);
    }
    formatter.DecIndent();
    formatter.WriteLine("}");
}

void CompoundStatement::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
    int n = int(statements.size());
    for (int i = 0; i < n; ++i)
    {
        statements[i]->Accept(visitor);
    }
}

SelectionStatement::SelectionStatement(const std::u32string& name_): Statement(name_) 
{
}

IfStatement::IfStatement(CppObject* condition_, Statement* thenStatement_, Statement* elseStatement_):
    SelectionStatement(U"if"), condition(condition_), thenStatement(thenStatement_), elseStatement(elseStatement_) 
{
    thenStatement->SetParent(this);
    if (elseStatement)
    {
        elseStatement->SetParent(this);
    }
    Own(condition);
    Own(thenStatement);
    Own(elseStatement);
}

void IfStatement::Replace(Statement* oldS, Statement* newS)
{
    if (thenStatement == oldS)
    {
        Own(newS);
        thenStatement = newS;
    }
    else if (elseStatement == oldS)
    {
        Own(newS);
        elseStatement = newS;
    }
    else
    {
        Statement::Replace(oldS, newS);
    }
}

void IfStatement::Print(CodeFormatter& formatter)
{
    formatter.Write("if (");
    condition->Print(formatter);
    formatter.Write(")");
    if (thenStatement->IsCompoundStatement())
    {
        formatter.NewLine();
    }
    else
    {
        formatter.Write(" ");
    }
    thenStatement->Print(formatter);
    if (elseStatement)
    {
        formatter.Write("else");
        if (elseStatement->IsCompoundStatement())
        {
            formatter.NewLine();
        }
        else
        {
            formatter.Write(" ");
        }
        elseStatement->Print(formatter);
    }
}

void IfStatement::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
    condition->Accept(visitor);
    thenStatement->Accept(visitor);
    if (elseStatement)
    {
        elseStatement->Accept(visitor);
    }
}

SwitchStatement::SwitchStatement(CppObject* condition_, Statement* statement_):
    SelectionStatement(U"switch"), condition(condition_), statement(statement_) 
{
    statement->SetParent(this);
    Own(condition);
    Own(statement);
}

void SwitchStatement::Replace(Statement* oldS, Statement* newS)
{
    if (statement == oldS)
    {
        Own(newS);
        statement = newS;
    }
    else
    {
        Statement::Replace(oldS, newS);
    }
}

void SwitchStatement::Print(CodeFormatter& formatter)
{
    formatter.Write("switch (");
    condition->Print(formatter);
    formatter.WriteLine(")");
    statement->Print(formatter);
}

void SwitchStatement::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
    condition->Accept(visitor);
    statement->Accept(visitor);
}

IterationStatement::IterationStatement(const std::u32string& name_): Statement(name_) 
{
}

WhileStatement::WhileStatement(CppObject* condition_, Statement* statement_):
    IterationStatement(U"while"), condition(condition_), statement(statement_) 
{
    statement->SetParent(this);
    Own(condition);
    Own(statement);
}

void WhileStatement::Replace(Statement* oldS, Statement* newS)
{
    if (statement == oldS)
    {
        Own(newS);
        statement = newS;
    }
    else
    {
        Statement::Replace(oldS, newS);
    }
}

void WhileStatement::Print(CodeFormatter& formatter)
{
    formatter.Write("while (");
    condition->Print(formatter);
    formatter.Write(")");
    if (statement->IsCompoundStatement())
    {
        formatter.NewLine();
    }
    else
    {
        formatter.Write(" ");
    }
    statement->Print(formatter);
}

void WhileStatement::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
    condition->Accept(visitor);
    statement->Accept(visitor);
}

DoStatement::DoStatement(Statement* statement_, CppObject* condition_):
    IterationStatement(U"do"), statement(statement_), condition(condition_) 
{
    statement->SetParent(this);
    Own(statement);
    Own(condition);
}

void DoStatement::Replace(Statement* oldS, Statement* newS)
{
    if (statement == oldS)
    {
        Own(newS);
        statement = newS;
    }
    else
    {
        Statement::Replace(oldS, newS);
    }
}

void DoStatement::Print(CodeFormatter& formatter)
{
    formatter.Write("do");
    if (statement->IsCompoundStatement())
    {
        formatter.NewLine();
    }
    else
    {
        formatter.Write(" ");
    }
    statement->Print(formatter);
    formatter.Write("while (");
    condition->Print(formatter);
    formatter.WriteLine(");");
}

void DoStatement::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
    statement->Accept(visitor);
    condition->Accept(visitor);
}

ForStatement::ForStatement(CppObject* initialization_, CppObject* condition_, CppObject* iteration_, Statement* statement_):
    IterationStatement(U"for"), initialization(initialization_), condition(condition_), iteration(iteration_), statement(statement_) 
{
    statement->SetParent(this);
    Own(initialization);
    Own(condition);
    Own(iteration);
    Own(statement);
}

void ForStatement::Print(CodeFormatter& formatter)
{
    formatter.Write("for (");
    if (initialization)
    {
        initialization->Print(formatter);
    }
    formatter.Write("; ");
    if (condition)
    {
        condition->Print(formatter);
    }
    formatter.Write("; ");
    if (iteration)
    {
        iteration->Print(formatter);
    }
    formatter.Write(")");
    if (statement->IsCompoundStatement())
    {
        formatter.NewLine();
    }
    else 
    {
        formatter.Write(" ");
    }
    statement->Print(formatter);
}

void ForStatement::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
    if (initialization)
    {
        initialization->Accept(visitor);
    }
    if (condition)
    {
        condition->Accept(visitor);
    }
    if (iteration)
    {
        iteration->Accept(visitor);
    }
    statement->Accept(visitor);
}

void ForStatement::Replace(Statement* oldS, Statement* newS)
{
    if (statement == oldS)
    {
        Own(newS);
        statement = newS;
    }
    else
    {
        Statement::Replace(oldS, newS);
    }
}

JumpStatement::JumpStatement(const std::u32string& name_): Statement(name_)
{
}

BreakStatement::BreakStatement(): JumpStatement(U"break") 
{
}

void BreakStatement::Print(CodeFormatter& formatter)
{
    formatter.WriteLine("break;");
}

void BreakStatement::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ContinueStatement::ContinueStatement(): JumpStatement(U"continue") 
{
}

void ContinueStatement::Print(CodeFormatter& formatter)
{
    formatter.WriteLine("continue;");
}

void ContinueStatement::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

GotoStatement::GotoStatement(const std::u32string& target_): JumpStatement(U"goto"), target(target_) 
{
}

void GotoStatement::Print(CodeFormatter& formatter)
{
    formatter.WriteLine("goto " + ToUtf8(target) + ";");
}

void GotoStatement::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ReturnStatement::ReturnStatement(CppObject* expression_): JumpStatement(U"return"), expression(expression_) 
{
    Own(expression);
}

void ReturnStatement::Print(CodeFormatter& formatter)
{
    formatter.Write("return");
    if (expression)
    {
        formatter.Write(" ");
        expression->Print(formatter);
    }
    formatter.WriteLine(";");
}

void ReturnStatement::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
    if (expression)
    {
        expression->Accept(visitor);
    }
}

void ReturnStatement::SetExpression(CppObject* expression_)
{
    Own(expression_);
    expression = expression_;
}

ConditionWithDeclarator::ConditionWithDeclarator(TypeId* type_, const std::u32string& declarator_, CppObject* expression_):
    CppObject(U"conditionWithDeclarator"), type(type_), declarator(declarator_), expression(expression_) 
{
    Own(type);
    Own(expression);
}

void ConditionWithDeclarator::Print(CodeFormatter& formatter)
{
    type->Print(formatter);
    formatter.Write(" " + ToUtf8(declarator) + " = ");
    expression->Print(formatter);
}

void ConditionWithDeclarator::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
    type->Accept(visitor);
    expression->Accept(visitor);
}

ForRangeDeclaration::ForRangeDeclaration() : CppObject(U"forRangeDeclaration"), typeId(new TypeId())
{
    Own(typeId);
}

void ForRangeDeclaration::SetDeclarator(const std::u32string& declarator_)
{
    declarator = declarator_;
}

void ForRangeDeclaration::Print(CodeFormatter& formatter)
{
    typeId->Print(formatter);
    formatter.Write(" " + ToUtf8(declarator));
}

void ForRangeDeclaration::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
    typeId->Accept(visitor);
}

RangeForStatement::RangeForStatement(ForRangeDeclaration* declaration_, CppObject* container_, Statement* statement_) :
    IterationStatement(U"forRangeStatement"), declaration(declaration_), container(container_), statement(statement_)
{
    statement->SetParent(this);
    Own(declaration);
    Own(container);
    Own(statement);
}

void RangeForStatement::Replace(Statement* oldS, Statement* newS)
{
    if (statement == oldS)
    {
        Own(newS);
        statement = newS;
    }
    else
    {
        Statement::Replace(oldS, newS);
    }
}

void RangeForStatement::Print(CodeFormatter& formatter)
{
    declaration->Print(formatter);
    formatter.Write(" : ");
    container->Print(formatter);
    statement->Print(formatter);
}

void RangeForStatement::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
    declaration->Accept(visitor);
    container->Accept(visitor);
    statement->Accept(visitor);
}

DeclarationStatement::DeclarationStatement(CppObject* declaration_): Statement(U"declaration"), declaration(declaration_) 
{
    Own(declaration);
}

void DeclarationStatement::Print(CodeFormatter& formatter)
{
    declaration->Print(formatter);
    formatter.WriteLine(";");
}

void DeclarationStatement::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
    declaration->Accept(visitor);
}

ExceptionDeclaration::ExceptionDeclaration(): CppObject(U"exceptionDeclaration"), typeId(new TypeId()), catchAll(false) 
{
    Own(typeId);
}

void ExceptionDeclaration::Print(CodeFormatter& formatter)
{
    if (catchAll)
    {
        formatter.Write("...");
    }
    else
    {
        typeId->Print(formatter);
    }
}

void ExceptionDeclaration::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
    typeId->Accept(visitor);
}

Handler::Handler(ExceptionDeclaration* exceptionDeclaration_, CompoundStatement* statement_):
    CppObject(U"handler"), exceptionDeclaration(exceptionDeclaration_), statement(statement_) 
{
}

void Handler::Print(CodeFormatter& formatter)
{
    formatter.Write("catch (");
    exceptionDeclaration->Print(formatter);
    formatter.WriteLine(")");
    statement->Print(formatter);
}

void Handler::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
    exceptionDeclaration->Accept(visitor);
    statement->Accept(visitor);
}

TryStatement::TryStatement(CompoundStatement* statement_): Statement(U"try"), statement(statement_) 
{
    statement->SetParent(this);
}

void TryStatement::Add(Handler* handler)
{
    Own(handler);
    handlers.push_back(handler);
}

void TryStatement::Print(CodeFormatter& formatter)
{
    formatter.WriteLine("try");
    statement->Print(formatter);
    int n = int(handlers.size());
    for (int i = 0; i < n; ++i)
    {
        handlers[i]->Print(formatter);
    }
}

void TryStatement::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
    statement->Accept(visitor);
    int n = int(handlers.size());
    for (int i = 0; i < n; ++i)
    {
        handlers[i]->Accept(visitor);
    }
}

IfDefStatement::IfDefStatement(CppObject* symbol_) : Statement(U"#ifdef"), symbol(symbol_)
{
    Own(symbol);
}

void IfDefStatement::Print(CodeFormatter& formatter)
{
    formatter.Write("#ifdef ");
    symbol->Print(formatter);
    formatter.WriteLine();
}

void IfDefStatement::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

EndIfStatement::EndIfStatement(CppObject* comment_) : Statement(U"#endif"), comment(comment_)
{
    Own(comment);
}

void EndIfStatement::Print(CodeFormatter& formatter)
{
    if (comment)
    {
        formatter.Write("#endif ");
        comment->Print(formatter);
        formatter.WriteLine();
    }
    else
    {
        formatter.WriteLine("#endif");
    }
}

void EndIfStatement::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} } // namespace soulng::cppcode
