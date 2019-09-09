#include "CppStatement.hpp"
#include <soulng/util/Unicode.hpp>
#include <soulng/slg/CppDeclaration.hpp>
#include <soulng/slg/CppDeclarator.hpp>
#include <soulng/slg/CppExpression.hpp>
#include <soulng/slg/LexerFileLexer.hpp>
#include <soulng/slg/LexerFileTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng/slg/CppStatement.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace soulng::lexer;
using namespace LexerFileTokens;

soulng::parser::Match CppStatementParser::Statement(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::Statement> labeledStatement;
    std::unique_ptr<soulng::cppcode::Statement> emptyStatement;
    std::unique_ptr<soulng::cppcode::CompoundStatement> compoundStatement;
    std::unique_ptr<soulng::cppcode::Statement> selectionStatement;
    std::unique_ptr<soulng::cppcode::Statement> iterationStatement;
    std::unique_ptr<soulng::cppcode::Statement> jumpStatement;
    std::unique_ptr<soulng::cppcode::Statement> declarationStatement;
    std::unique_ptr<soulng::cppcode::Statement> tryStatement;
    std::unique_ptr<soulng::cppcode::Statement> expressionStatement;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int save = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int save = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int save = lexer.GetPos();
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int save = lexer.GetPos();
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                int save = lexer.GetPos();
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    int save = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match = CppStatementParser::LabeledStatement(lexer);
                                        labeledStatement.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                                        if (match.hit)
                                        {
                                            return soulng::parser::Match(true, labeledStatement.release());
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
                                    if (!match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        lexer.SetPos(save);
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch10 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match = CppStatementParser::EmptyStatement(lexer);
                                                emptyStatement.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                                                if (match.hit)
                                                {
                                                    return soulng::parser::Match(true, emptyStatement.release());
                                                }
                                                *parentMatch10 = match;
                                            }
                                            *parentMatch9 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                }
                                *parentMatch6 = match;
                                if (!match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch11 = &match;
                                    lexer.SetPos(save);
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch12 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = CppStatementParser::CompoundStatement(lexer);
                                            compoundStatement.reset(static_cast<soulng::cppcode::CompoundStatement*>(match.value));
                                            if (match.hit)
                                            {
                                                return soulng::parser::Match(true, compoundStatement.release());
                                            }
                                            *parentMatch12 = match;
                                        }
                                        *parentMatch11 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                            }
                            *parentMatch5 = match;
                            if (!match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch13 = &match;
                                lexer.SetPos(save);
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch14 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match = CppStatementParser::SelectionStatement(lexer);
                                        selectionStatement.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                                        if (match.hit)
                                        {
                                            return soulng::parser::Match(true, selectionStatement.release());
                                        }
                                        *parentMatch14 = match;
                                    }
                                    *parentMatch13 = match;
                                }
                                *parentMatch5 = match;
                            }
                        }
                        *parentMatch4 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch15 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch16 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = CppStatementParser::IterationStatement(lexer);
                                    iterationStatement.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                                    if (match.hit)
                                    {
                                        return soulng::parser::Match(true, iterationStatement.release());
                                    }
                                    *parentMatch16 = match;
                                }
                                *parentMatch15 = match;
                            }
                            *parentMatch4 = match;
                        }
                    }
                    *parentMatch3 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch17 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch18 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = CppStatementParser::JumpStatement(lexer);
                                jumpStatement.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                                if (match.hit)
                                {
                                    return soulng::parser::Match(true, jumpStatement.release());
                                }
                                *parentMatch18 = match;
                            }
                            *parentMatch17 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch19 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch20 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = CppStatementParser::DeclarationStatement(lexer);
                            declarationStatement.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                            if (match.hit)
                            {
                                return soulng::parser::Match(true, declarationStatement.release());
                            }
                            *parentMatch20 = match;
                        }
                        *parentMatch19 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch21 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch22 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = CppStatementParser::TryStatement(lexer);
                        tryStatement.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, tryStatement.release());
                        }
                        *parentMatch22 = match;
                    }
                    *parentMatch21 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch23 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch24 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppStatementParser::ExpressionStatement(lexer);
                    expressionStatement.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, expressionStatement.release());
                    }
                    *parentMatch24 = match;
                }
                *parentMatch23 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match CppStatementParser::LabeledStatement(LexerFileLexer& lexer)
{
    std::u32string label = std::u32string();
    std::unique_ptr<soulng::cppcode::Statement> stmt1;
    std::unique_ptr<soulng::cppcode::CppObject> caseExpr;
    std::unique_ptr<soulng::cppcode::Statement> stmt2;
    std::unique_ptr<soulng::cppcode::Statement> stmt3;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int save = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int pos = lexer.GetPos();
                        Span span = lexer.GetSpan();
                        soulng::parser::Match match(false);
                        if (*lexer == ID)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (match.hit)
                        {
                            label = lexer.GetMatch(span);
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        soulng::parser::Match match(false);
                        if (*lexer == COLON)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        *parentMatch5 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch7 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = CppStatementParser::Statement(lexer);
                            stmt1.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, U"Statement");
                            }
                        }
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, new soulng::cppcode::LabeledStatement(label, stmt1.release()));
                        }
                        *parentMatch7 = match;
                    }
                    *parentMatch6 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch8 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch9 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch10 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch11 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == CASE)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch11 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch12 = &match;
                                {
                                    soulng::parser::Match match(true);
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match = CppExpressionParser::ConstantExpression(lexer);
                                        caseExpr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                        if (!match.hit)
                                        {
                                            lexer.ThrowExpectationFailure(pos, U"ConstantExpression");
                                        }
                                    }
                                    *parentMatch12 = match;
                                }
                                *parentMatch11 = match;
                            }
                            *parentMatch10 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch13 = &match;
                            {
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    if (*lexer == COLON)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(COLON)));
                                    }
                                }
                                *parentMatch13 = match;
                            }
                            *parentMatch10 = match;
                        }
                        *parentMatch9 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch14 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch15 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = CppStatementParser::Statement(lexer);
                                    stmt2.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, U"Statement");
                                    }
                                }
                                if (match.hit)
                                {
                                    return soulng::parser::Match(true, new soulng::cppcode::CaseStatement(caseExpr.release(), stmt2.release()));
                                }
                                *parentMatch15 = match;
                            }
                            *parentMatch14 = match;
                        }
                        *parentMatch9 = match;
                    }
                    *parentMatch8 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch16 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch17 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch18 = &match;
                    {
                        soulng::parser::Match match(false);
                        if (*lexer == DEFAULT)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        *parentMatch18 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch19 = &match;
                        {
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == COLON)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(COLON)));
                                }
                            }
                            *parentMatch19 = match;
                        }
                        *parentMatch18 = match;
                    }
                    *parentMatch17 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch20 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch21 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = CppStatementParser::Statement(lexer);
                                stmt3.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, U"Statement");
                                }
                            }
                            if (match.hit)
                            {
                                return soulng::parser::Match(true, new soulng::cppcode::DefaultStatement(stmt3.release()));
                            }
                            *parentMatch21 = match;
                        }
                        *parentMatch20 = match;
                    }
                    *parentMatch17 = match;
                }
                *parentMatch16 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match CppStatementParser::EmptyStatement(LexerFileLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        if (*lexer == SEMICOLON)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::cppcode::EmptyStatement);
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppStatementParser::CompoundStatement(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CompoundStatement> compoundStatement = std::unique_ptr<soulng::cppcode::CompoundStatement>();
    std::unique_ptr<soulng::cppcode::Statement> stmt;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(false);
                if (*lexer == LBRACE)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    compoundStatement.reset(new soulng::cppcode::CompoundStatement);
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    while (true)
                    {
                        int save = lexer.GetPos();
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch5 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = CppStatementParser::Statement(lexer);
                                stmt.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                                if (match.hit)
                                {
                                    compoundStatement->Add(stmt.release());
                                }
                                *parentMatch5 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch4 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                                break;
                            }
                        }
                    }
                }
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch6 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch7 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RBRACE)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RBRACE)));
                    }
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, compoundStatement.release());
                }
                *parentMatch7 = match;
            }
            *parentMatch6 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppStatementParser::SelectionStatement(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::Statement> ifStatement;
    std::unique_ptr<soulng::cppcode::Statement> switchStatement;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match = CppStatementParser::IfStatement(lexer);
            ifStatement.reset(static_cast<soulng::cppcode::Statement*>(match.value));
            if (match.hit)
            {
                return soulng::parser::Match(true, ifStatement.release());
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppStatementParser::SwitchStatement(lexer);
                    switchStatement.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, switchStatement.release());
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match CppStatementParser::IfStatement(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> cond;
    std::unique_ptr<soulng::cppcode::Statement> thenS;
    std::unique_ptr<soulng::cppcode::Statement> elseS;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == IF)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    if (*lexer == LPAREN)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                                    }
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch7 = &match;
                        {
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = CppStatementParser::Condition(lexer);
                                cond.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, U"Condition");
                                }
                            }
                            *parentMatch7 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch8 = &match;
                    {
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == RPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                            }
                        }
                        *parentMatch8 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch9 = &match;
                {
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = CppStatementParser::Statement(lexer);
                        thenS.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, U"Statement");
                        }
                    }
                    *parentMatch9 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch10 = &match;
            {
                soulng::parser::Match match(true);
                int save = lexer.GetPos();
                soulng::parser::Match* parentMatch11 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch12 = &match;
                    {
                        soulng::parser::Match match(false);
                        if (*lexer == ELSE)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        *parentMatch12 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch13 = &match;
                        {
                            soulng::parser::Match match = CppStatementParser::Statement(lexer);
                            elseS.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                            *parentMatch13 = match;
                        }
                        *parentMatch12 = match;
                    }
                    if (match.hit)
                    {
                        *parentMatch11 = match;
                    }
                    else
                    {
                        lexer.SetPos(save);
                    }
                }
                *parentMatch10 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::cppcode::IfStatement(cond.release(), thenS.release(), elseS.release()));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppStatementParser::SwitchStatement(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> cond;
    std::unique_ptr<soulng::cppcode::Statement> stmt;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    if (*lexer == SWITCH)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == LPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                            }
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch5 = &match;
                {
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = CppStatementParser::Condition(lexer);
                        cond.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, U"Condition");
                        }
                    }
                    *parentMatch5 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch6 = &match;
            {
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RPAREN)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                    }
                }
                *parentMatch6 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch7 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch8 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppStatementParser::Statement(lexer);
                    stmt.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, U"Statement");
                    }
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, new soulng::cppcode::SwitchStatement(cond.release(), stmt.release()));
                }
                *parentMatch8 = match;
            }
            *parentMatch7 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppStatementParser::IterationStatement(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::Statement> whileStatement;
    std::unique_ptr<soulng::cppcode::Statement> doStatement;
    std::unique_ptr<soulng::cppcode::Statement> rangeForStatement;
    std::unique_ptr<soulng::cppcode::Statement> forStatement;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int save = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int save = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppStatementParser::WhileStatement(lexer);
                    whileStatement.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, whileStatement.release());
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = CppStatementParser::DoStatement(lexer);
                            doStatement.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                            if (match.hit)
                            {
                                return soulng::parser::Match(true, doStatement.release());
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch7 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = CppStatementParser::RangeForStatement(lexer);
                        rangeForStatement.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, rangeForStatement.release());
                        }
                        *parentMatch7 = match;
                    }
                    *parentMatch6 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch8 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch9 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppStatementParser::ForStatement(lexer);
                    forStatement.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, forStatement.release());
                    }
                    *parentMatch9 = match;
                }
                *parentMatch8 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match CppStatementParser::WhileStatement(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> cond;
    std::unique_ptr<soulng::cppcode::Statement> stmt;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    if (*lexer == WHILE)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == LPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                            }
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch5 = &match;
                {
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = CppStatementParser::Condition(lexer);
                        cond.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, U"Condition");
                        }
                    }
                    *parentMatch5 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch6 = &match;
            {
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RPAREN)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                    }
                }
                *parentMatch6 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch7 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch8 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppStatementParser::Statement(lexer);
                    stmt.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, U"Statement");
                    }
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, new soulng::cppcode::WhileStatement(cond.release(), stmt.release()));
                }
                *parentMatch8 = match;
            }
            *parentMatch7 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppStatementParser::DoStatement(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::Statement> stmt;
    std::unique_ptr<soulng::cppcode::CppObject> cond;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == DO)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = CppStatementParser::Statement(lexer);
                                    stmt.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, U"Statement");
                                    }
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch7 = &match;
                        {
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == WHILE)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(WHILE)));
                                }
                            }
                            *parentMatch7 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch8 = &match;
                    {
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == LPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                            }
                        }
                        *parentMatch8 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch9 = &match;
                {
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = CppExpressionParser::CppExpression(lexer);
                        cond.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, U"CppExpression");
                        }
                    }
                    *parentMatch9 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch10 = &match;
            {
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RPAREN)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                    }
                }
                *parentMatch10 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch11 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch12 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, new soulng::cppcode::DoStatement(stmt.release(), cond.release()));
                }
                *parentMatch12 = match;
            }
            *parentMatch11 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppStatementParser::RangeForStatement(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::ForRangeDeclaration> forRangeDeclaration;
    std::unique_ptr<soulng::cppcode::CppObject> container;
    std::unique_ptr<soulng::cppcode::Statement> stmt;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == FOR)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == LPAREN)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch7 = &match;
                        {
                            soulng::parser::Match match = CppStatementParser::ForRangeDeclaration(lexer);
                            forRangeDeclaration.reset(static_cast<soulng::cppcode::ForRangeDeclaration*>(match.value));
                            *parentMatch7 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch8 = &match;
                    {
                        soulng::parser::Match match(false);
                        if (*lexer == COLON)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        *parentMatch8 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch9 = &match;
                {
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = CppExpressionParser::CppExpression(lexer);
                        container.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, U"CppExpression");
                        }
                    }
                    *parentMatch9 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch10 = &match;
            {
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RPAREN)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                    }
                }
                *parentMatch10 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch11 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch12 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppStatementParser::Statement(lexer);
                    stmt.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, U"Statement");
                    }
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, new soulng::cppcode::RangeForStatement(forRangeDeclaration.release(), container.release(), stmt.release()));
                }
                *parentMatch12 = match;
            }
            *parentMatch11 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppStatementParser::ForRangeDeclaration(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::ForRangeDeclaration> forRangeDeclaration = std::unique_ptr<soulng::cppcode::ForRangeDeclaration>();
    std::unique_ptr<soulng::parser::Value<std::u32string>> declarator;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(true);
                    if (match.hit)
                    {
                        forRangeDeclaration.reset(new soulng::cppcode::ForRangeDeclaration);
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match = CppDeclaratorParser::TypeSpecifierSeq(lexer, forRangeDeclaration->GetTypeId());
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppDeclaratorParser::Declarator(lexer);
                    declarator.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                    if (match.hit)
                    {
                        forRangeDeclaration->SetDeclarator(declarator->value);
                    }
                    *parentMatch6 = match;
                }
                *parentMatch5 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, forRangeDeclaration.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppStatementParser::ForStatement(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> forInitStatement;
    std::unique_ptr<soulng::cppcode::CppObject> cond;
    std::unique_ptr<soulng::cppcode::CppObject> loopExpr;
    std::unique_ptr<soulng::cppcode::Statement> stmt;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == FOR)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch6 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    if (*lexer == LPAREN)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch8 = &match;
                            {
                                soulng::parser::Match match = CppStatementParser::ForInitStatement(lexer);
                                forInitStatement.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                *parentMatch8 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch9 = &match;
                        {
                            soulng::parser::Match match(true);
                            int save = lexer.GetPos();
                            soulng::parser::Match* parentMatch10 = &match;
                            {
                                soulng::parser::Match match = CppStatementParser::Condition(lexer);
                                cond.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                if (match.hit)
                                {
                                    *parentMatch10 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                }
                            }
                            *parentMatch9 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch11 = &match;
                    {
                        soulng::parser::Match match(false);
                        if (*lexer == SEMICOLON)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        *parentMatch11 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch12 = &match;
                {
                    soulng::parser::Match match(true);
                    int save = lexer.GetPos();
                    soulng::parser::Match* parentMatch13 = &match;
                    {
                        soulng::parser::Match match = CppExpressionParser::CppExpression(lexer);
                        loopExpr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                        if (match.hit)
                        {
                            *parentMatch13 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                        }
                    }
                    *parentMatch12 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch14 = &match;
            {
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RPAREN)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                    }
                }
                *parentMatch14 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch15 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch16 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppStatementParser::Statement(lexer);
                    stmt.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, U"Statement");
                    }
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, new soulng::cppcode::ForStatement(forInitStatement.release(), cond.release(), loopExpr.release(), stmt.release()));
                }
                *parentMatch16 = match;
            }
            *parentMatch15 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppStatementParser::ForInitStatement(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::Statement> emptyStatement;
    std::unique_ptr<soulng::cppcode::Statement> expressionStatement;
    std::unique_ptr<soulng::cppcode::SimpleDeclaration> simpleDeclaration;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int save = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match = CppStatementParser::EmptyStatement(lexer);
                emptyStatement.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                if (match.hit)
                {
                    return soulng::parser::Match(true, emptyStatement.release());
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = CppStatementParser::ExpressionStatement(lexer);
                        expressionStatement.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, expressionStatement.release());
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppDeclarationParser::SimpleDeclaration(lexer);
                    simpleDeclaration.reset(static_cast<soulng::cppcode::SimpleDeclaration*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, simpleDeclaration.release());
                    }
                    *parentMatch6 = match;
                }
                *parentMatch5 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match CppStatementParser::JumpStatement(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::Statement> breakStatement;
    std::unique_ptr<soulng::cppcode::Statement> continueStatement;
    std::unique_ptr<soulng::cppcode::Statement> returnStatement;
    std::unique_ptr<soulng::cppcode::Statement> gotoStatement;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int save = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int save = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppStatementParser::BreakStatement(lexer);
                    breakStatement.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, breakStatement.release());
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = CppStatementParser::ContinueStatement(lexer);
                            continueStatement.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                            if (match.hit)
                            {
                                return soulng::parser::Match(true, continueStatement.release());
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch7 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = CppStatementParser::ReturnStatement(lexer);
                        returnStatement.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, returnStatement.release());
                        }
                        *parentMatch7 = match;
                    }
                    *parentMatch6 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch8 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch9 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppStatementParser::GotoStatement(lexer);
                    gotoStatement.reset(static_cast<soulng::cppcode::Statement*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, gotoStatement.release());
                    }
                    *parentMatch9 = match;
                }
                *parentMatch8 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match CppStatementParser::BreakStatement(LexerFileLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            if (*lexer == BREAK)
            {
                ++lexer;
                match.hit = true;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::cppcode::BreakStatement);
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppStatementParser::ContinueStatement(LexerFileLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            if (*lexer == CONTINUE)
            {
                ++lexer;
                match.hit = true;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::cppcode::ContinueStatement);
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppStatementParser::ReturnStatement(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> returnValue;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                if (*lexer == RETURN)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(true);
                    int save = lexer.GetPos();
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match = CppExpressionParser::CppExpression(lexer);
                        returnValue.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                        if (match.hit)
                        {
                            *parentMatch4 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                        }
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            {
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                *parentMatch5 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::cppcode::ReturnStatement(returnValue.release()));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppStatementParser::GotoStatement(LexerFileLexer& lexer)
{
    std::u32string target = std::u32string();
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                if (*lexer == GOTO)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int pos = lexer.GetPos();
                        Span span = lexer.GetSpan();
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == ID)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(ID)));
                            }
                        }
                        if (match.hit)
                        {
                            target = lexer.GetMatch(span);
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            {
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                *parentMatch5 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::cppcode::GotoStatement(target));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppStatementParser::DeclarationStatement(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> declaration;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match = CppDeclarationParser::BlockDeclaration(lexer);
        declaration.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::cppcode::DeclarationStatement(declaration.release()));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppStatementParser::Condition(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::TypeId> typeId;
    std::unique_ptr<soulng::parser::Value<std::u32string>> declarator;
    std::unique_ptr<soulng::cppcode::CppObject> assignmentExpr;
    std::unique_ptr<soulng::cppcode::CppObject> expr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match = CppDeclaratorParser::TypeId(lexer);
                    typeId.reset(static_cast<soulng::cppcode::TypeId*>(match.value));
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match = CppDeclaratorParser::Declarator(lexer);
                        declarator.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch5 = &match;
                {
                    soulng::parser::Match match(false);
                    if (*lexer == ASSIGN)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch5 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch6 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch7 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppExpressionParser::AssignmentExpression(lexer);
                    assignmentExpr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, new soulng::cppcode::ConditionWithDeclarator(typeId.release(), declarator->value, assignmentExpr.release()));
                    }
                    *parentMatch7 = match;
                }
                *parentMatch6 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch8 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch9 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppExpressionParser::CppExpression(lexer);
                    expr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, expr.release());
                    }
                    *parentMatch9 = match;
                }
                *parentMatch8 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match CppStatementParser::TryStatement(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::TryStatement> tryStatement = std::unique_ptr<soulng::cppcode::TryStatement>();
    std::unique_ptr<soulng::cppcode::CompoundStatement> tryBlock;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                if (*lexer == TRY)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = CppStatementParser::CompoundStatement(lexer);
                        tryBlock.reset(static_cast<soulng::cppcode::CompoundStatement*>(match.value));
                        if (match.hit)
                        {
                            tryStatement.reset(new soulng::cppcode::TryStatement(tryBlock.release()));
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            {
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppStatementParser::HandlerSeq(lexer, tryStatement.get());
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, U"HandlerSeq");
                    }
                }
                *parentMatch5 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, tryStatement.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppStatementParser::HandlerSeq(LexerFileLexer& lexer, soulng::cppcode::TryStatement* tryStatement)
{
    std::unique_ptr<soulng::cppcode::Handler> handler;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match(true);
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match = CppStatementParser::Handler(lexer);
                handler.reset(static_cast<soulng::cppcode::Handler*>(match.value));
                if (!match.hit)
                {
                    lexer.ThrowExpectationFailure(pos, U"Handler");
                }
            }
            if (match.hit)
            {
                tryStatement->Add(handler.release());
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch2 = &match;
        {
            soulng::parser::Match match(true);
            int save = lexer.GetPos();
            soulng::parser::Match* parentMatch3 = &match;
            {
                soulng::parser::Match match = CppStatementParser::HandlerSeq(lexer, tryStatement);
                if (match.hit)
                {
                    *parentMatch3 = match;
                }
                else
                {
                    lexer.SetPos(save);
                }
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppStatementParser::Handler(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::ExceptionDeclaration> exceptionDeclaration;
    std::unique_ptr<soulng::cppcode::CompoundStatement> catchBlock;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    if (*lexer == CATCH)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == LPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                            }
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch5 = &match;
                {
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = CppStatementParser::ExceptionDeclaration(lexer);
                        exceptionDeclaration.reset(static_cast<soulng::cppcode::ExceptionDeclaration*>(match.value));
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, U"ExceptionDeclaration");
                        }
                    }
                    *parentMatch5 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch6 = &match;
            {
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RPAREN)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                    }
                }
                *parentMatch6 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch7 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch8 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppStatementParser::CompoundStatement(lexer);
                    catchBlock.reset(static_cast<soulng::cppcode::CompoundStatement*>(match.value));
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, U"CompoundStatement");
                    }
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, new soulng::cppcode::Handler(exceptionDeclaration.release(), catchBlock.release()));
                }
                *parentMatch8 = match;
            }
            *parentMatch7 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppStatementParser::ExceptionDeclaration(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::ExceptionDeclaration> exceptionDeclaration = std::unique_ptr<soulng::cppcode::ExceptionDeclaration>();
    std::unique_ptr<soulng::parser::Value<std::u32string>> declarator;
    std::unique_ptr<soulng::parser::Value<std::u32string>> abstractDeclarator;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match(true);
            if (match.hit)
            {
                exceptionDeclaration.reset(new soulng::cppcode::ExceptionDeclaration);
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch2 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    int save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        soulng::parser::Match match = CppDeclaratorParser::TypeSpecifierSeq(lexer, exceptionDeclaration->GetTypeId());
                        *parentMatch5 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match(true);
                            int save = lexer.GetPos();
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch8 = &match;
                                {
                                    int save = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch9 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match = CppDeclaratorParser::Declarator(lexer);
                                        declarator.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                                        if (match.hit)
                                        {
                                            exceptionDeclaration->GetTypeId()->Declarator() = declarator->value;
                                        }
                                        *parentMatch9 = match;
                                    }
                                    *parentMatch8 = match;
                                    if (!match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch10 = &match;
                                        lexer.SetPos(save);
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch11 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match = CppDeclaratorParser::AbstractDeclarator(lexer);
                                                abstractDeclarator.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                                                if (match.hit)
                                                {
                                                    exceptionDeclaration->GetTypeId()->Declarator() = abstractDeclarator->value;
                                                }
                                                *parentMatch11 = match;
                                            }
                                            *parentMatch10 = match;
                                        }
                                        *parentMatch8 = match;
                                    }
                                }
                                if (match.hit)
                                {
                                    *parentMatch7 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                }
                            }
                            *parentMatch6 = match;
                        }
                        *parentMatch5 = match;
                    }
                    *parentMatch4 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch12 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch13 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == ELLIPSIS)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    exceptionDeclaration->CatchAll() = true;
                                }
                                *parentMatch13 = match;
                            }
                            *parentMatch12 = match;
                        }
                        *parentMatch4 = match;
                    }
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, exceptionDeclaration.release());
                }
                *parentMatch3 = match;
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppStatementParser::ExpressionStatement(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match = CppExpressionParser::CppExpression(lexer);
            expr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::cppcode::ExpressionStatement(expr.release()));
        }
        *parentMatch0 = match;
    }
    return match;
}
