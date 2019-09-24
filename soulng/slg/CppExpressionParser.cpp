#include "CppExpressionParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/slg/CppDeclaratorParser.hpp>
#include <soulng/slg/CppDeclarationParser.hpp>
#include <soulng/slg/CppLiteralParser.hpp>
#include <soulng/slg/CppIdentifierParser.hpp>
#include <soulng/slg/LexerFileLexer.hpp>
#include <soulng/slg/LexerFileTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/soulng/slg/CppExpressionParser.parser' using soulng parser generator spg version 1.2.0

using namespace soulng::unicode;
using namespace soulng::lexer;
using namespace LexerFileTokens;

soulng::parser::Match CppExpressionParser::CppExpression(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr = std::unique_ptr<soulng::cppcode::CppObject>();
    std::unique_ptr<soulng::cppcode::CppObject> left;
    std::unique_ptr<soulng::cppcode::CppObject> right;
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
                    soulng::parser::Match match = CppExpressionParser::AssignmentExpression(lexer);
                    left.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
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
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        while (true)
                        {
                            int save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == COMMA)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch9 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match = CppExpressionParser::AssignmentExpression(lexer);
                                                right.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                                if (match.hit)
                                                {
                                                    expr.reset(new soulng::cppcode::BinaryOpExpr(expr.release(), soulng::cppcode::Operator::comma, right.release()));
                                                }
                                                *parentMatch9 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                                if (match.hit)
                                {
                                    *parentMatch5 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                    break;
                                }
                            }
                        }
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::ConstantExpression(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match = CppExpressionParser::CppExpression(lexer);
        expr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::AssignmentExpression(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> left;
    std::unique_ptr<soulng::parser::Value<soulng::cppcode::Operator>> op;
    std::unique_ptr<soulng::cppcode::CppObject> right;
    std::unique_ptr<soulng::cppcode::CppObject> conditionalExpr;
    std::unique_ptr<soulng::cppcode::CppObject> throwExpr;
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
                    soulng::parser::Match match = CppExpressionParser::LogicalOrExpression(lexer);
                    left.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match = CppExpressionParser::AssignmentOp(lexer);
                        op.reset(static_cast<soulng::parser::Value<soulng::cppcode::Operator>*>(match.value));
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
                    soulng::parser::Match* parentMatch6 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(true);
                        soulng::parser::Match* parentMatch7 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = CppExpressionParser::AssignmentExpression(lexer);
                            right.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                            if (match.hit)
                            {
                                *parentMatch7 = match;
                            }
                            else
                            {
                                lexer.ThrowExpectationFailure(pos, U"assignment expression");
                            }
                        }
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, new soulng::cppcode::BinaryOpExpr(left.release(), op->value, right.release()));
                        }
                        *parentMatch6 = match;
                    }
                    *parentMatch5 = match;
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
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = CppExpressionParser::ConditionalExpression(lexer);
                        conditionalExpr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, conditionalExpr.release());
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
            soulng::parser::Match* parentMatch10 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch11 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppExpressionParser::ThrowExpression(lexer);
                    throwExpr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, throwExpr.release());
                    }
                    *parentMatch11 = match;
                }
                *parentMatch10 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match CppExpressionParser::AssignmentOp(LexerFileLexer& lexer)
{
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case ASSIGN:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::assign));
            }
            break;
        }
        case MULASSIGN:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::mulAssign));
            }
            break;
        }
        case DIVASSIGN:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::divAssign));
            }
            break;
        }
        case REMASSIGN:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::remAssign));
            }
            break;
        }
        case PLUSASSIGN:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::plusAssign));
            }
            break;
        }
        case MINUSASSIGN:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::minusAssign));
            }
            break;
        }
        case SHIFTLEFTASSIGN:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::shiftLeftAssign));
            }
            break;
        }
        case SHIFTRIGHTASSIGN:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::shiftRightAssign));
            }
            break;
        }
        case ANDASSIGN:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::andAssign));
            }
            break;
        }
        case XORASSIGN:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::xorAssign));
            }
            break;
        }
        case ORASSIGN:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::orAssign));
            }
            break;
        }
    }
    return match;
}

soulng::parser::Match CppExpressionParser::ConditionalExpression(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr = std::unique_ptr<soulng::cppcode::CppObject>();
    std::unique_ptr<soulng::cppcode::CppObject> left;
    std::unique_ptr<soulng::cppcode::CppObject> ifExpr;
    std::unique_ptr<soulng::cppcode::CppObject> thenExpr;
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
                    soulng::parser::Match match = CppExpressionParser::LogicalOrExpression(lexer);
                    left.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
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
                    soulng::parser::Match match(true);
                    int save = lexer.GetPos();
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch8 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch9 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == QUEST)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        *parentMatch9 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch10 = &match;
                                        {
                                            soulng::parser::Match match(true);
                                            soulng::parser::Match* parentMatch11 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match = CppExpressionParser::CppExpression(lexer);
                                                ifExpr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                                if (match.hit)
                                                {
                                                    *parentMatch11 = match;
                                                }
                                                else
                                                {
                                                    lexer.ThrowExpectationFailure(pos, U"C++ expression");
                                                }
                                            }
                                            *parentMatch10 = match;
                                        }
                                        *parentMatch9 = match;
                                    }
                                    *parentMatch8 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch12 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == COLON)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        *parentMatch12 = match;
                                    }
                                    *parentMatch8 = match;
                                }
                                *parentMatch7 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch13 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch14 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match(true);
                                        soulng::parser::Match* parentMatch15 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = CppExpressionParser::AssignmentExpression(lexer);
                                            thenExpr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                            if (match.hit)
                                            {
                                                *parentMatch15 = match;
                                            }
                                            else
                                            {
                                                lexer.ThrowExpectationFailure(pos, U"assignment expression");
                                            }
                                        }
                                        if (match.hit)
                                        {
                                            expr.reset(new soulng::cppcode::ConditionalExpr(expr.release(), ifExpr.release(), thenExpr.release()));
                                        }
                                        *parentMatch14 = match;
                                    }
                                    *parentMatch13 = match;
                                }
                                *parentMatch7 = match;
                            }
                            *parentMatch6 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch5 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                        }
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::ThrowExpression(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> exception;
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
                if (*lexer == THROW)
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
                        soulng::parser::Match match = CppExpressionParser::AssignmentExpression(lexer);
                        exception.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
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
            return soulng::parser::Match(true, new soulng::cppcode::ThrowExpr(exception.release()));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::LogicalOrExpression(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr = std::unique_ptr<soulng::cppcode::CppObject>();
    std::unique_ptr<soulng::cppcode::CppObject> left;
    std::unique_ptr<soulng::cppcode::CppObject> right;
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
                    soulng::parser::Match match = CppExpressionParser::LogicalAndExpression(lexer);
                    left.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
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
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        while (true)
                        {
                            int save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == DISJUNCTION)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch9 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match(true);
                                                soulng::parser::Match* parentMatch10 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = CppExpressionParser::LogicalAndExpression(lexer);
                                                    right.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        *parentMatch10 = match;
                                                    }
                                                    else
                                                    {
                                                        lexer.ThrowExpectationFailure(pos, U"logical AND-expression");
                                                    }
                                                }
                                                if (match.hit)
                                                {
                                                    expr.reset(new soulng::cppcode::BinaryOpExpr(expr.release(), soulng::cppcode::Operator::or_, right.release()));
                                                }
                                                *parentMatch9 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                                if (match.hit)
                                {
                                    *parentMatch5 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                    break;
                                }
                            }
                        }
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::LogicalAndExpression(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr = std::unique_ptr<soulng::cppcode::CppObject>();
    std::unique_ptr<soulng::cppcode::CppObject> left;
    std::unique_ptr<soulng::cppcode::CppObject> right;
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
                    soulng::parser::Match match = CppExpressionParser::InclusiveOrExpression(lexer);
                    left.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
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
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        while (true)
                        {
                            int save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == AMPAMP)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch9 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match(true);
                                                soulng::parser::Match* parentMatch10 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = CppExpressionParser::InclusiveOrExpression(lexer);
                                                    right.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        *parentMatch10 = match;
                                                    }
                                                    else
                                                    {
                                                        lexer.ThrowExpectationFailure(pos, U"inclusive OR-expression");
                                                    }
                                                }
                                                if (match.hit)
                                                {
                                                    expr.reset(new soulng::cppcode::BinaryOpExpr(expr.release(), soulng::cppcode::Operator::and_, right.release()));
                                                }
                                                *parentMatch9 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                                if (match.hit)
                                {
                                    *parentMatch5 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                    break;
                                }
                            }
                        }
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::InclusiveOrExpression(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr = std::unique_ptr<soulng::cppcode::CppObject>();
    std::unique_ptr<soulng::cppcode::CppObject> left;
    std::unique_ptr<soulng::cppcode::CppObject> right;
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
                    soulng::parser::Match match = CppExpressionParser::ExclusiveOrExpression(lexer);
                    left.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
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
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        while (true)
                        {
                            int save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == BITOR)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch9 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match(true);
                                                soulng::parser::Match* parentMatch10 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = CppExpressionParser::ExclusiveOrExpression(lexer);
                                                    right.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        *parentMatch10 = match;
                                                    }
                                                    else
                                                    {
                                                        lexer.ThrowExpectationFailure(pos, U"exclusive OR-expression");
                                                    }
                                                }
                                                if (match.hit)
                                                {
                                                    expr.reset(new soulng::cppcode::BinaryOpExpr(expr.release(), soulng::cppcode::Operator::bitor_, right.release()));
                                                }
                                                *parentMatch9 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                                if (match.hit)
                                {
                                    *parentMatch5 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                    break;
                                }
                            }
                        }
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::ExclusiveOrExpression(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr = std::unique_ptr<soulng::cppcode::CppObject>();
    std::unique_ptr<soulng::cppcode::CppObject> left;
    std::unique_ptr<soulng::cppcode::CppObject> right;
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
                    soulng::parser::Match match = CppExpressionParser::AndExpression(lexer);
                    left.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
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
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        while (true)
                        {
                            int save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == BITXOR)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch9 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match(true);
                                                soulng::parser::Match* parentMatch10 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = CppExpressionParser::AndExpression(lexer);
                                                    right.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        *parentMatch10 = match;
                                                    }
                                                    else
                                                    {
                                                        lexer.ThrowExpectationFailure(pos, U"AND-expression");
                                                    }
                                                }
                                                if (match.hit)
                                                {
                                                    expr.reset(new soulng::cppcode::BinaryOpExpr(expr.release(), soulng::cppcode::Operator::bitxor, right.release()));
                                                }
                                                *parentMatch9 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                                if (match.hit)
                                {
                                    *parentMatch5 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                    break;
                                }
                            }
                        }
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::AndExpression(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr = std::unique_ptr<soulng::cppcode::CppObject>();
    std::unique_ptr<soulng::cppcode::CppObject> left;
    std::unique_ptr<soulng::cppcode::CppObject> right;
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
                    soulng::parser::Match match = CppExpressionParser::EqualityExpression(lexer);
                    left.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
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
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        while (true)
                        {
                            int save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == AMP)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch9 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match(true);
                                                soulng::parser::Match* parentMatch10 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = CppExpressionParser::EqualityExpression(lexer);
                                                    right.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        *parentMatch10 = match;
                                                    }
                                                    else
                                                    {
                                                        lexer.ThrowExpectationFailure(pos, U"equality expression");
                                                    }
                                                }
                                                if (match.hit)
                                                {
                                                    expr.reset(new soulng::cppcode::BinaryOpExpr(expr.release(), soulng::cppcode::Operator::bitand_, right.release()));
                                                }
                                                *parentMatch9 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                                if (match.hit)
                                {
                                    *parentMatch5 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                    break;
                                }
                            }
                        }
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::EqualityExpression(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr = std::unique_ptr<soulng::cppcode::CppObject>();
    std::unique_ptr<soulng::cppcode::CppObject> left;
    std::unique_ptr<soulng::parser::Value<soulng::cppcode::Operator>> op;
    std::unique_ptr<soulng::cppcode::CppObject> right;
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
                    soulng::parser::Match match = CppExpressionParser::RelationalExpression(lexer);
                    left.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
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
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        while (true)
                        {
                            int save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match = CppExpressionParser::EqOp(lexer);
                                        op.reset(static_cast<soulng::parser::Value<soulng::cppcode::Operator>*>(match.value));
                                        *parentMatch7 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch9 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match(true);
                                                soulng::parser::Match* parentMatch10 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = CppExpressionParser::RelationalExpression(lexer);
                                                    right.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        *parentMatch10 = match;
                                                    }
                                                    else
                                                    {
                                                        lexer.ThrowExpectationFailure(pos, U"relational expression");
                                                    }
                                                }
                                                if (match.hit)
                                                {
                                                    expr.reset(new soulng::cppcode::BinaryOpExpr(expr.release(), op->value, right.release()));
                                                }
                                                *parentMatch9 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                                if (match.hit)
                                {
                                    *parentMatch5 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                    break;
                                }
                            }
                        }
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::EqOp(LexerFileLexer& lexer)
{
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case EQ:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::eq));
            }
            break;
        }
        case NEQ:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::notEq));
            }
            break;
        }
    }
    return match;
}

soulng::parser::Match CppExpressionParser::RelationalExpression(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr = std::unique_ptr<soulng::cppcode::CppObject>();
    std::unique_ptr<soulng::cppcode::CppObject> left;
    std::unique_ptr<soulng::parser::Value<soulng::cppcode::Operator>> op;
    std::unique_ptr<soulng::cppcode::CppObject> right;
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
                    soulng::parser::Match match = CppExpressionParser::ShiftExpression(lexer);
                    left.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
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
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        while (true)
                        {
                            int save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match = CppExpressionParser::RelOp(lexer);
                                        op.reset(static_cast<soulng::parser::Value<soulng::cppcode::Operator>*>(match.value));
                                        *parentMatch7 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch9 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match(true);
                                                soulng::parser::Match* parentMatch10 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = CppExpressionParser::ShiftExpression(lexer);
                                                    right.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        *parentMatch10 = match;
                                                    }
                                                    else
                                                    {
                                                        lexer.ThrowExpectationFailure(pos, U"shift expression");
                                                    }
                                                }
                                                if (match.hit)
                                                {
                                                    expr.reset(new soulng::cppcode::BinaryOpExpr(expr.release(), op->value, right.release()));
                                                }
                                                *parentMatch9 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                                if (match.hit)
                                {
                                    *parentMatch5 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                    break;
                                }
                            }
                        }
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::RelOp(LexerFileLexer& lexer)
{
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case LANGLE:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::less));
            }
            break;
        }
        case RANGLE:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::greater));
            }
            break;
        }
        case LEQ:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::lessOrEq));
            }
            break;
        }
        case GEQ:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::greaterOrEq));
            }
            break;
        }
    }
    return match;
}

soulng::parser::Match CppExpressionParser::ShiftExpression(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr = std::unique_ptr<soulng::cppcode::CppObject>();
    std::unique_ptr<soulng::cppcode::CppObject> left;
    std::unique_ptr<soulng::parser::Value<soulng::cppcode::Operator>> op;
    std::unique_ptr<soulng::cppcode::CppObject> right;
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
                    soulng::parser::Match match = CppExpressionParser::AdditiveExpression(lexer);
                    left.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
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
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        while (true)
                        {
                            int save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match = CppExpressionParser::ShiftOp(lexer);
                                        op.reset(static_cast<soulng::parser::Value<soulng::cppcode::Operator>*>(match.value));
                                        *parentMatch7 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch9 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match(true);
                                                soulng::parser::Match* parentMatch10 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = CppExpressionParser::AdditiveExpression(lexer);
                                                    right.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        *parentMatch10 = match;
                                                    }
                                                    else
                                                    {
                                                        lexer.ThrowExpectationFailure(pos, U"additive expression");
                                                    }
                                                }
                                                if (match.hit)
                                                {
                                                    expr.reset(new soulng::cppcode::BinaryOpExpr(expr.release(), op->value, right.release()));
                                                }
                                                *parentMatch9 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                                if (match.hit)
                                {
                                    *parentMatch5 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                    break;
                                }
                            }
                        }
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::ShiftOp(LexerFileLexer& lexer)
{
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case SHIFTLEFT:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::shiftLeft));
            }
            break;
        }
        case SHIFTRIGHT:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::shiftRight));
            }
            break;
        }
    }
    return match;
}

soulng::parser::Match CppExpressionParser::AdditiveExpression(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr = std::unique_ptr<soulng::cppcode::CppObject>();
    std::unique_ptr<soulng::cppcode::CppObject> left;
    std::unique_ptr<soulng::parser::Value<soulng::cppcode::Operator>> op;
    std::unique_ptr<soulng::cppcode::CppObject> right;
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
                    soulng::parser::Match match = CppExpressionParser::MultiplicativeExpression(lexer);
                    left.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
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
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        while (true)
                        {
                            int save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match = CppExpressionParser::AddOp(lexer);
                                        op.reset(static_cast<soulng::parser::Value<soulng::cppcode::Operator>*>(match.value));
                                        *parentMatch7 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch9 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match(true);
                                                soulng::parser::Match* parentMatch10 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = CppExpressionParser::MultiplicativeExpression(lexer);
                                                    right.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        *parentMatch10 = match;
                                                    }
                                                    else
                                                    {
                                                        lexer.ThrowExpectationFailure(pos, U"multiplicative expression");
                                                    }
                                                }
                                                if (match.hit)
                                                {
                                                    expr.reset(new soulng::cppcode::BinaryOpExpr(expr.release(), op->value, right.release()));
                                                }
                                                *parentMatch9 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                                if (match.hit)
                                {
                                    *parentMatch5 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                    break;
                                }
                            }
                        }
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::AddOp(LexerFileLexer& lexer)
{
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case PLUS:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::plus));
            }
            break;
        }
        case MINUS:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::minus));
            }
            break;
        }
    }
    return match;
}

soulng::parser::Match CppExpressionParser::MultiplicativeExpression(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr = std::unique_ptr<soulng::cppcode::CppObject>();
    std::unique_ptr<soulng::cppcode::CppObject> left;
    std::unique_ptr<soulng::parser::Value<soulng::cppcode::Operator>> op;
    std::unique_ptr<soulng::cppcode::CppObject> right;
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
                    soulng::parser::Match match = CppExpressionParser::PmExpression(lexer);
                    left.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
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
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        while (true)
                        {
                            int save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match = CppExpressionParser::MulOp(lexer);
                                        op.reset(static_cast<soulng::parser::Value<soulng::cppcode::Operator>*>(match.value));
                                        *parentMatch7 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch9 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match(true);
                                                soulng::parser::Match* parentMatch10 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = CppExpressionParser::PmExpression(lexer);
                                                    right.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        *parentMatch10 = match;
                                                    }
                                                    else
                                                    {
                                                        lexer.ThrowExpectationFailure(pos, U"pointer-to-member expression");
                                                    }
                                                }
                                                if (match.hit)
                                                {
                                                    expr.reset(new soulng::cppcode::BinaryOpExpr(expr.release(), op->value, right.release()));
                                                }
                                                *parentMatch9 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                                if (match.hit)
                                {
                                    *parentMatch5 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                    break;
                                }
                            }
                        }
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::MulOp(LexerFileLexer& lexer)
{
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case STAR:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::mul));
            }
            break;
        }
        case DIV:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::div));
            }
            break;
        }
        case REM:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::rem));
            }
            break;
        }
    }
    return match;
}

soulng::parser::Match CppExpressionParser::PmExpression(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr = std::unique_ptr<soulng::cppcode::CppObject>();
    std::unique_ptr<soulng::cppcode::CppObject> left;
    std::unique_ptr<soulng::parser::Value<soulng::cppcode::Operator>> op;
    std::unique_ptr<soulng::cppcode::CppObject> right;
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
                    soulng::parser::Match match = CppExpressionParser::CastExpression(lexer);
                    left.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
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
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        while (true)
                        {
                            int save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match = CppExpressionParser::PmOp(lexer);
                                        op.reset(static_cast<soulng::parser::Value<soulng::cppcode::Operator>*>(match.value));
                                        *parentMatch7 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch9 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match(true);
                                                soulng::parser::Match* parentMatch10 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = CppExpressionParser::CastExpression(lexer);
                                                    right.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        *parentMatch10 = match;
                                                    }
                                                    else
                                                    {
                                                        lexer.ThrowExpectationFailure(pos, U"cast-expression");
                                                    }
                                                }
                                                if (match.hit)
                                                {
                                                    expr.reset(new soulng::cppcode::BinaryOpExpr(expr.release(), op->value, right.release()));
                                                }
                                                *parentMatch9 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                                if (match.hit)
                                {
                                    *parentMatch5 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                    break;
                                }
                            }
                        }
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::PmOp(LexerFileLexer& lexer)
{
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case DOTSTAR:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::dotStar));
            }
            break;
        }
        case ARROWSTAR:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::arrowStar));
            }
            break;
        }
    }
    return match;
}

soulng::parser::Match CppExpressionParser::CastExpression(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr = std::unique_ptr<soulng::cppcode::CppObject>();
    std::unique_ptr<soulng::cppcode::TypeId> typeId;
    std::unique_ptr<soulng::cppcode::CppObject> castExpr;
    std::unique_ptr<soulng::cppcode::CppObject> unaryExpr;
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
                int save = lexer.GetPos();
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
                            if (*lexer == LPAREN)
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
                                soulng::parser::Match match = CppDeclaratorParser::TypeId(lexer);
                                typeId.reset(static_cast<soulng::cppcode::TypeId*>(match.value));
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
                            soulng::parser::Match match(false);
                            if (*lexer == RPAREN)
                            {
                                ++lexer;
                                match.hit = true;
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
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch9 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = CppExpressionParser::CastExpression(lexer);
                            castExpr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                            if (match.hit)
                            {
                                expr.reset(new soulng::cppcode::CastExpr(typeId.release(), castExpr.release()));
                            }
                            *parentMatch9 = match;
                        }
                        *parentMatch8 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
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
                            soulng::parser::Match match = CppExpressionParser::UnaryExpression(lexer);
                            unaryExpr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                            if (match.hit)
                            {
                                expr.reset(unaryExpr.release());
                            }
                            *parentMatch11 = match;
                        }
                        *parentMatch10 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::UnaryExpression(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr = std::unique_ptr<soulng::cppcode::CppObject>();
    std::unique_ptr<soulng::cppcode::CppObject> postfixExpr;
    std::unique_ptr<soulng::cppcode::CppObject> postCastExpr;
    std::unique_ptr<soulng::cppcode::CppObject> u1;
    std::unique_ptr<soulng::cppcode::CppObject> u2;
    std::unique_ptr<soulng::parser::Value<soulng::cppcode::Operator>> op;
    std::unique_ptr<soulng::cppcode::CppObject> castExpr;
    std::unique_ptr<soulng::cppcode::TypeId> typeId;
    std::unique_ptr<soulng::cppcode::CppObject> u3;
    std::unique_ptr<soulng::cppcode::CppObject> newExpr;
    std::unique_ptr<soulng::cppcode::CppObject> deleteExpr;
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
                                        int save = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            int save = lexer.GetPos();
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch10 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match = CppExpressionParser::PostfixExpression(lexer);
                                                postfixExpr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                                if (match.hit)
                                                {
                                                    expr.reset(postfixExpr.release());
                                                }
                                                *parentMatch10 = match;
                                            }
                                            *parentMatch9 = match;
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
                                                        soulng::parser::Match match = CppExpressionParser::PostCastExpression(lexer);
                                                        postCastExpr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                                        if (match.hit)
                                                        {
                                                            expr.reset(postCastExpr.release());
                                                        }
                                                        *parentMatch12 = match;
                                                    }
                                                    *parentMatch11 = match;
                                                }
                                                *parentMatch9 = match;
                                            }
                                        }
                                        *parentMatch8 = match;
                                        if (!match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch13 = &match;
                                            lexer.SetPos(save);
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch14 = &match;
                                                {
                                                    soulng::parser::Match match(false);
                                                    if (*lexer == PLUSPLUS)
                                                    {
                                                        ++lexer;
                                                        match.hit = true;
                                                    }
                                                    *parentMatch14 = match;
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
                                                            soulng::parser::Match* parentMatch17 = &match;
                                                            {
                                                                int pos = lexer.GetPos();
                                                                soulng::parser::Match match = CppExpressionParser::UnaryExpression(lexer);
                                                                u1.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                                                if (match.hit)
                                                                {
                                                                    *parentMatch17 = match;
                                                                }
                                                                else
                                                                {
                                                                    lexer.ThrowExpectationFailure(pos, U"unary expression");
                                                                }
                                                            }
                                                            if (match.hit)
                                                            {
                                                                expr.reset(new soulng::cppcode::PreIncrementExpr(u1.release()));
                                                            }
                                                            *parentMatch16 = match;
                                                        }
                                                        *parentMatch15 = match;
                                                    }
                                                    *parentMatch14 = match;
                                                }
                                                *parentMatch13 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                    }
                                    *parentMatch7 = match;
                                    if (!match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch18 = &match;
                                        lexer.SetPos(save);
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch19 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                if (*lexer == MINUSMINUS)
                                                {
                                                    ++lexer;
                                                    match.hit = true;
                                                }
                                                *parentMatch19 = match;
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
                                                        soulng::parser::Match* parentMatch22 = &match;
                                                        {
                                                            int pos = lexer.GetPos();
                                                            soulng::parser::Match match = CppExpressionParser::UnaryExpression(lexer);
                                                            u2.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                                            if (match.hit)
                                                            {
                                                                *parentMatch22 = match;
                                                            }
                                                            else
                                                            {
                                                                lexer.ThrowExpectationFailure(pos, U"unary expression");
                                                            }
                                                        }
                                                        if (match.hit)
                                                        {
                                                            expr.reset(new soulng::cppcode::PreDecrementExpr(u2.release()));
                                                        }
                                                        *parentMatch21 = match;
                                                    }
                                                    *parentMatch20 = match;
                                                }
                                                *parentMatch19 = match;
                                            }
                                            *parentMatch18 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                }
                                *parentMatch6 = match;
                                if (!match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch23 = &match;
                                    lexer.SetPos(save);
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch24 = &match;
                                        {
                                            soulng::parser::Match match = CppExpressionParser::UnaryOperator(lexer);
                                            op.reset(static_cast<soulng::parser::Value<soulng::cppcode::Operator>*>(match.value));
                                            *parentMatch24 = match;
                                        }
                                        if (match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch25 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch26 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match(true);
                                                    soulng::parser::Match* parentMatch27 = &match;
                                                    {
                                                        int pos = lexer.GetPos();
                                                        soulng::parser::Match match = CppExpressionParser::CastExpression(lexer);
                                                        castExpr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                                        if (match.hit)
                                                        {
                                                            *parentMatch27 = match;
                                                        }
                                                        else
                                                        {
                                                            lexer.ThrowExpectationFailure(pos, U"cast-expression");
                                                        }
                                                    }
                                                    if (match.hit)
                                                    {
                                                        expr.reset(new soulng::cppcode::UnaryOpExpr(op->value, castExpr.release()));
                                                    }
                                                    *parentMatch26 = match;
                                                }
                                                *parentMatch25 = match;
                                            }
                                            *parentMatch24 = match;
                                        }
                                        *parentMatch23 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                            }
                            *parentMatch5 = match;
                            if (!match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch28 = &match;
                                lexer.SetPos(save);
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch29 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch30 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch31 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                if (*lexer == SIZEOF)
                                                {
                                                    ++lexer;
                                                    match.hit = true;
                                                }
                                                *parentMatch31 = match;
                                            }
                                            if (match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch32 = &match;
                                                {
                                                    soulng::parser::Match match(false);
                                                    if (*lexer == LPAREN)
                                                    {
                                                        ++lexer;
                                                        match.hit = true;
                                                    }
                                                    *parentMatch32 = match;
                                                }
                                                *parentMatch31 = match;
                                            }
                                            *parentMatch30 = match;
                                        }
                                        if (match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch33 = &match;
                                            {
                                                soulng::parser::Match match(true);
                                                soulng::parser::Match* parentMatch34 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = CppDeclaratorParser::TypeId(lexer);
                                                    typeId.reset(static_cast<soulng::cppcode::TypeId*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        *parentMatch34 = match;
                                                    }
                                                    else
                                                    {
                                                        lexer.ThrowExpectationFailure(pos, U"type identifier");
                                                    }
                                                }
                                                *parentMatch33 = match;
                                            }
                                            *parentMatch30 = match;
                                        }
                                        *parentMatch29 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch35 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch36 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match(true);
                                                soulng::parser::Match* parentMatch37 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match(false);
                                                    if (*lexer == RPAREN)
                                                    {
                                                        ++lexer;
                                                        match.hit = true;
                                                    }
                                                    if (match.hit)
                                                    {
                                                        *parentMatch37 = match;
                                                    }
                                                    else
                                                    {
                                                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                                                    }
                                                }
                                                if (match.hit)
                                                {
                                                    expr.reset(new soulng::cppcode::SizeOfExpr(typeId.release(), true));
                                                }
                                                *parentMatch36 = match;
                                            }
                                            *parentMatch35 = match;
                                        }
                                        *parentMatch29 = match;
                                    }
                                    *parentMatch28 = match;
                                }
                                *parentMatch5 = match;
                            }
                        }
                        *parentMatch4 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch38 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch39 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    if (*lexer == SIZEOF)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    *parentMatch39 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch40 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch41 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match(true);
                                            soulng::parser::Match* parentMatch42 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match = CppExpressionParser::UnaryExpression(lexer);
                                                u3.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                                if (match.hit)
                                                {
                                                    *parentMatch42 = match;
                                                }
                                                else
                                                {
                                                    lexer.ThrowExpectationFailure(pos, U"unary expression");
                                                }
                                            }
                                            if (match.hit)
                                            {
                                                expr.reset(new soulng::cppcode::SizeOfExpr(u3.release(), false));
                                            }
                                            *parentMatch41 = match;
                                        }
                                        *parentMatch40 = match;
                                    }
                                    *parentMatch39 = match;
                                }
                                *parentMatch38 = match;
                            }
                            *parentMatch4 = match;
                        }
                    }
                    *parentMatch3 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch43 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch44 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = CppExpressionParser::NewExpression(lexer);
                                newExpr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                if (match.hit)
                                {
                                    expr.reset(newExpr.release());
                                }
                                *parentMatch44 = match;
                            }
                            *parentMatch43 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch45 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch46 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = CppExpressionParser::DeleteExpression(lexer);
                            deleteExpr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                            if (match.hit)
                            {
                                expr.reset(deleteExpr.release());
                            }
                            *parentMatch46 = match;
                        }
                        *parentMatch45 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::UnaryOperator(LexerFileLexer& lexer)
{
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case STAR:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::deref));
            }
            break;
        }
        case AMP:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::addrOf));
            }
            break;
        }
        case PLUS:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::plus));
            }
            break;
        }
        case MINUS:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::minus));
            }
            break;
        }
        case EXCLAMATION:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::not_));
            }
            break;
        }
        case CPL:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<soulng::cppcode::Operator>(soulng::cppcode::Operator::cpl));
            }
            break;
        }
    }
    return match;
}

soulng::parser::Match CppExpressionParser::PostfixExpression(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr = std::unique_ptr<soulng::cppcode::CppObject>();
    std::unique_ptr<soulng::cppcode::CppObject> primaryExpr;
    std::unique_ptr<soulng::cppcode::CppObject> index;
    std::unique_ptr<soulng::cppcode::IdExpr> dotMember;
    std::unique_ptr<soulng::cppcode::IdExpr> arrowMember;
    std::unique_ptr<soulng::cppcode::CppObject> type;
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
                int save = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = CppExpressionParser::PrimaryExpression(lexer);
                        primaryExpr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                        if (match.hit)
                        {
                            expr.reset(primaryExpr.release());
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
                        soulng::parser::Match match(true);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            while (true)
                            {
                                int save = lexer.GetPos();
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            int save = lexer.GetPos();
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch9 = &match;
                                            {
                                                int save = lexer.GetPos();
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch10 = &match;
                                                {
                                                    int save = lexer.GetPos();
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch11 = &match;
                                                    {
                                                        int save = lexer.GetPos();
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch12 = &match;
                                                        {
                                                            int save = lexer.GetPos();
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch13 = &match;
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch14 = &match;
                                                                {
                                                                    soulng::parser::Match match(false);
                                                                    if (*lexer == LBRACKET)
                                                                    {
                                                                        ++lexer;
                                                                        match.hit = true;
                                                                    }
                                                                    *parentMatch14 = match;
                                                                }
                                                                if (match.hit)
                                                                {
                                                                    soulng::parser::Match match(false);
                                                                    soulng::parser::Match* parentMatch15 = &match;
                                                                    {
                                                                        soulng::parser::Match match = CppExpressionParser::CppExpression(lexer);
                                                                        index.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                                                        *parentMatch15 = match;
                                                                    }
                                                                    *parentMatch14 = match;
                                                                }
                                                                *parentMatch13 = match;
                                                            }
                                                            if (match.hit)
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch16 = &match;
                                                                {
                                                                    soulng::parser::Match match(false);
                                                                    soulng::parser::Match* parentMatch17 = &match;
                                                                    {
                                                                        int pos = lexer.GetPos();
                                                                        soulng::parser::Match match(true);
                                                                        soulng::parser::Match* parentMatch18 = &match;
                                                                        {
                                                                            int pos = lexer.GetPos();
                                                                            soulng::parser::Match match(false);
                                                                            if (*lexer == RBRACKET)
                                                                            {
                                                                                ++lexer;
                                                                                match.hit = true;
                                                                            }
                                                                            if (match.hit)
                                                                            {
                                                                                *parentMatch18 = match;
                                                                            }
                                                                            else
                                                                            {
                                                                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RBRACKET)));
                                                                            }
                                                                        }
                                                                        if (match.hit)
                                                                        {
                                                                            expr.reset(new soulng::cppcode::IndexExpr(expr.release(), index.release()));
                                                                        }
                                                                        *parentMatch17 = match;
                                                                    }
                                                                    *parentMatch16 = match;
                                                                }
                                                                *parentMatch13 = match;
                                                            }
                                                            *parentMatch12 = match;
                                                            if (!match.hit)
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch19 = &match;
                                                                lexer.SetPos(save);
                                                                {
                                                                    soulng::parser::Match match(false);
                                                                    soulng::parser::Match* parentMatch20 = &match;
                                                                    {
                                                                        soulng::parser::Match match(false);
                                                                        soulng::parser::Match* parentMatch21 = &match;
                                                                        {
                                                                            soulng::parser::Match match(false);
                                                                            soulng::parser::Match* parentMatch22 = &match;
                                                                            {
                                                                                int pos = lexer.GetPos();
                                                                                soulng::parser::Match match(false);
                                                                                if (*lexer == LPAREN)
                                                                                {
                                                                                    ++lexer;
                                                                                    match.hit = true;
                                                                                }
                                                                                if (match.hit)
                                                                                {
                                                                                    expr.reset(new soulng::cppcode::InvokeExpr(expr.release()));
                                                                                }
                                                                                *parentMatch22 = match;
                                                                            }
                                                                            *parentMatch21 = match;
                                                                        }
                                                                        if (match.hit)
                                                                        {
                                                                            soulng::parser::Match match(false);
                                                                            soulng::parser::Match* parentMatch23 = &match;
                                                                            {
                                                                                soulng::parser::Match match(true);
                                                                                int save = lexer.GetPos();
                                                                                soulng::parser::Match* parentMatch24 = &match;
                                                                                {
                                                                                    soulng::parser::Match match = CppExpressionParser::ExpressionList(lexer, expr.get());
                                                                                    if (match.hit)
                                                                                    {
                                                                                        *parentMatch24 = match;
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        lexer.SetPos(save);
                                                                                    }
                                                                                }
                                                                                *parentMatch23 = match;
                                                                            }
                                                                            *parentMatch21 = match;
                                                                        }
                                                                        *parentMatch20 = match;
                                                                    }
                                                                    if (match.hit)
                                                                    {
                                                                        soulng::parser::Match match(false);
                                                                        soulng::parser::Match* parentMatch25 = &match;
                                                                        {
                                                                            soulng::parser::Match match(true);
                                                                            soulng::parser::Match* parentMatch26 = &match;
                                                                            {
                                                                                int pos = lexer.GetPos();
                                                                                soulng::parser::Match match(false);
                                                                                if (*lexer == RPAREN)
                                                                                {
                                                                                    ++lexer;
                                                                                    match.hit = true;
                                                                                }
                                                                                if (match.hit)
                                                                                {
                                                                                    *parentMatch26 = match;
                                                                                }
                                                                                else
                                                                                {
                                                                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                                                                                }
                                                                            }
                                                                            *parentMatch25 = match;
                                                                        }
                                                                        *parentMatch20 = match;
                                                                    }
                                                                    *parentMatch19 = match;
                                                                }
                                                                *parentMatch12 = match;
                                                            }
                                                        }
                                                        *parentMatch11 = match;
                                                        if (!match.hit)
                                                        {
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch27 = &match;
                                                            lexer.SetPos(save);
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch28 = &match;
                                                                {
                                                                    soulng::parser::Match match(false);
                                                                    if (*lexer == DOT)
                                                                    {
                                                                        ++lexer;
                                                                        match.hit = true;
                                                                    }
                                                                    *parentMatch28 = match;
                                                                }
                                                                if (match.hit)
                                                                {
                                                                    soulng::parser::Match match(false);
                                                                    soulng::parser::Match* parentMatch29 = &match;
                                                                    {
                                                                        soulng::parser::Match match(false);
                                                                        soulng::parser::Match* parentMatch30 = &match;
                                                                        {
                                                                            int pos = lexer.GetPos();
                                                                            soulng::parser::Match match(true);
                                                                            soulng::parser::Match* parentMatch31 = &match;
                                                                            {
                                                                                int pos = lexer.GetPos();
                                                                                soulng::parser::Match match = CppExpressionParser::IdExpression(lexer);
                                                                                dotMember.reset(static_cast<soulng::cppcode::IdExpr*>(match.value));
                                                                                if (match.hit)
                                                                                {
                                                                                    *parentMatch31 = match;
                                                                                }
                                                                                else
                                                                                {
                                                                                    lexer.ThrowExpectationFailure(pos, U"ID-expression");
                                                                                }
                                                                            }
                                                                            if (match.hit)
                                                                            {
                                                                                expr.reset(new soulng::cppcode::MemberAccessExpr(expr.release(), dotMember.release()));
                                                                            }
                                                                            *parentMatch30 = match;
                                                                        }
                                                                        *parentMatch29 = match;
                                                                    }
                                                                    *parentMatch28 = match;
                                                                }
                                                                *parentMatch27 = match;
                                                            }
                                                            *parentMatch11 = match;
                                                        }
                                                    }
                                                    *parentMatch10 = match;
                                                    if (!match.hit)
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch32 = &match;
                                                        lexer.SetPos(save);
                                                        {
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch33 = &match;
                                                            {
                                                                soulng::parser::Match match(false);
                                                                if (*lexer == ARROW)
                                                                {
                                                                    ++lexer;
                                                                    match.hit = true;
                                                                }
                                                                *parentMatch33 = match;
                                                            }
                                                            if (match.hit)
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch34 = &match;
                                                                {
                                                                    soulng::parser::Match match(false);
                                                                    soulng::parser::Match* parentMatch35 = &match;
                                                                    {
                                                                        int pos = lexer.GetPos();
                                                                        soulng::parser::Match match(true);
                                                                        soulng::parser::Match* parentMatch36 = &match;
                                                                        {
                                                                            int pos = lexer.GetPos();
                                                                            soulng::parser::Match match = CppExpressionParser::IdExpression(lexer);
                                                                            arrowMember.reset(static_cast<soulng::cppcode::IdExpr*>(match.value));
                                                                            if (match.hit)
                                                                            {
                                                                                *parentMatch36 = match;
                                                                            }
                                                                            else
                                                                            {
                                                                                lexer.ThrowExpectationFailure(pos, U"ID-expression");
                                                                            }
                                                                        }
                                                                        if (match.hit)
                                                                        {
                                                                            expr.reset(new soulng::cppcode::PtrMemberAccessExpr(expr.release(), arrowMember.release()));
                                                                        }
                                                                        *parentMatch35 = match;
                                                                    }
                                                                    *parentMatch34 = match;
                                                                }
                                                                *parentMatch33 = match;
                                                            }
                                                            *parentMatch32 = match;
                                                        }
                                                        *parentMatch10 = match;
                                                    }
                                                }
                                                *parentMatch9 = match;
                                                if (!match.hit)
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch37 = &match;
                                                    lexer.SetPos(save);
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch38 = &match;
                                                        {
                                                            int pos = lexer.GetPos();
                                                            soulng::parser::Match match(false);
                                                            if (*lexer == PLUSPLUS)
                                                            {
                                                                ++lexer;
                                                                match.hit = true;
                                                            }
                                                            if (match.hit)
                                                            {
                                                                expr.reset(new soulng::cppcode::PostIncrementExpr(expr.release()));
                                                            }
                                                            *parentMatch38 = match;
                                                        }
                                                        *parentMatch37 = match;
                                                    }
                                                    *parentMatch9 = match;
                                                }
                                            }
                                            *parentMatch8 = match;
                                            if (!match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch39 = &match;
                                                lexer.SetPos(save);
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch40 = &match;
                                                    {
                                                        int pos = lexer.GetPos();
                                                        soulng::parser::Match match(false);
                                                        if (*lexer == MINUSMINUS)
                                                        {
                                                            ++lexer;
                                                            match.hit = true;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            expr.reset(new soulng::cppcode::PostDecrementExpr(expr.release()));
                                                        }
                                                        *parentMatch40 = match;
                                                    }
                                                    *parentMatch39 = match;
                                                }
                                                *parentMatch8 = match;
                                            }
                                        }
                                        *parentMatch7 = match;
                                    }
                                    if (match.hit)
                                    {
                                        *parentMatch6 = match;
                                    }
                                    else
                                    {
                                        lexer.SetPos(save);
                                        break;
                                    }
                                }
                            }
                        }
                        *parentMatch5 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch41 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch42 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch43 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch44 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch45 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match = CppExpressionParser::TypeSpecifierOrTypeName(lexer);
                                        type.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                        if (match.hit)
                                        {
                                            expr.reset(new soulng::cppcode::InvokeExpr(expr.release()));
                                        }
                                        *parentMatch45 = match;
                                    }
                                    *parentMatch44 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch46 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == LPAREN)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        *parentMatch46 = match;
                                    }
                                    *parentMatch44 = match;
                                }
                                *parentMatch43 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch47 = &match;
                                {
                                    soulng::parser::Match match(true);
                                    int save = lexer.GetPos();
                                    soulng::parser::Match* parentMatch48 = &match;
                                    {
                                        soulng::parser::Match match = CppExpressionParser::ExpressionList(lexer, expr.get());
                                        if (match.hit)
                                        {
                                            *parentMatch48 = match;
                                        }
                                        else
                                        {
                                            lexer.SetPos(save);
                                        }
                                    }
                                    *parentMatch47 = match;
                                }
                                *parentMatch43 = match;
                            }
                            *parentMatch42 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch49 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == RPAREN)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch49 = match;
                            }
                            *parentMatch42 = match;
                        }
                        *parentMatch41 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::PostCastExpression(LexerFileLexer& lexer)
{
    std::u32string castStr = std::u32string();
    std::unique_ptr<soulng::cppcode::TypeId> typeId;
    std::unique_ptr<soulng::cppcode::CppObject> expr;
    std::unique_ptr<soulng::cppcode::CppObject> typeIdExpr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
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
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            int save = lexer.GetPos();
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch10 = &match;
                                            {
                                                int save = lexer.GetPos();
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch11 = &match;
                                                {
                                                    int save = lexer.GetPos();
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch12 = &match;
                                                    {
                                                        int pos = lexer.GetPos();
                                                        soulng::parser::Match match(false);
                                                        if (*lexer == DYNAMICCAST)
                                                        {
                                                            ++lexer;
                                                            match.hit = true;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            castStr = U"dynamic_cast";
                                                        }
                                                        *parentMatch12 = match;
                                                    }
                                                    *parentMatch11 = match;
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
                                                                soulng::parser::Match match(false);
                                                                if (*lexer == STATICCAST)
                                                                {
                                                                    ++lexer;
                                                                    match.hit = true;
                                                                }
                                                                if (match.hit)
                                                                {
                                                                    castStr = U"static_cast";
                                                                }
                                                                *parentMatch14 = match;
                                                            }
                                                            *parentMatch13 = match;
                                                        }
                                                        *parentMatch11 = match;
                                                    }
                                                }
                                                *parentMatch10 = match;
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
                                                            soulng::parser::Match match(false);
                                                            if (*lexer == REINTERPRETCAST)
                                                            {
                                                                ++lexer;
                                                                match.hit = true;
                                                            }
                                                            if (match.hit)
                                                            {
                                                                castStr = U"reinterpret_cast";
                                                            }
                                                            *parentMatch16 = match;
                                                        }
                                                        *parentMatch15 = match;
                                                    }
                                                    *parentMatch10 = match;
                                                }
                                            }
                                            *parentMatch9 = match;
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
                                                        soulng::parser::Match match(false);
                                                        if (*lexer == CONSTCAST)
                                                        {
                                                            ++lexer;
                                                            match.hit = true;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            castStr = U"const_cast";
                                                        }
                                                        *parentMatch18 = match;
                                                    }
                                                    *parentMatch17 = match;
                                                }
                                                *parentMatch9 = match;
                                            }
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch19 = &match;
                                    {
                                        soulng::parser::Match match(true);
                                        soulng::parser::Match* parentMatch20 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match(false);
                                            if (*lexer == LANGLE)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            if (match.hit)
                                            {
                                                *parentMatch20 = match;
                                            }
                                            else
                                            {
                                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LANGLE)));
                                            }
                                        }
                                        *parentMatch19 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch6 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch21 = &match;
                                {
                                    soulng::parser::Match match(true);
                                    soulng::parser::Match* parentMatch22 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match = CppDeclaratorParser::TypeId(lexer);
                                        typeId.reset(static_cast<soulng::cppcode::TypeId*>(match.value));
                                        if (match.hit)
                                        {
                                            *parentMatch22 = match;
                                        }
                                        else
                                        {
                                            lexer.ThrowExpectationFailure(pos, U"type identifier");
                                        }
                                    }
                                    *parentMatch21 = match;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch23 = &match;
                            {
                                soulng::parser::Match match(true);
                                soulng::parser::Match* parentMatch24 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    if (*lexer == RANGLE)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        *parentMatch24 = match;
                                    }
                                    else
                                    {
                                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RANGLE)));
                                    }
                                }
                                *parentMatch23 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch25 = &match;
                        {
                            soulng::parser::Match match(true);
                            soulng::parser::Match* parentMatch26 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == LPAREN)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    *parentMatch26 = match;
                                }
                                else
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                                }
                            }
                            *parentMatch25 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch27 = &match;
                    {
                        soulng::parser::Match match(true);
                        soulng::parser::Match* parentMatch28 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = CppExpressionParser::CppExpression(lexer);
                            expr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                            if (match.hit)
                            {
                                *parentMatch28 = match;
                            }
                            else
                            {
                                lexer.ThrowExpectationFailure(pos, U"C++ expression");
                            }
                        }
                        *parentMatch27 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch29 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch30 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(true);
                        soulng::parser::Match* parentMatch31 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == RPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                *parentMatch31 = match;
                            }
                            else
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                            }
                        }
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, new soulng::cppcode::PostCastExpr(castStr, typeId.release(), expr.release()));
                        }
                        *parentMatch30 = match;
                    }
                    *parentMatch29 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch32 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch33 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch34 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch35 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == TYPEID)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch35 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch36 = &match;
                                {
                                    soulng::parser::Match match(true);
                                    soulng::parser::Match* parentMatch37 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        if (*lexer == LPAREN)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            *parentMatch37 = match;
                                        }
                                        else
                                        {
                                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                                        }
                                    }
                                    *parentMatch36 = match;
                                }
                                *parentMatch35 = match;
                            }
                            *parentMatch34 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch38 = &match;
                            {
                                soulng::parser::Match match(true);
                                soulng::parser::Match* parentMatch39 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = CppExpressionParser::CppExpression(lexer);
                                    typeIdExpr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                    if (match.hit)
                                    {
                                        *parentMatch39 = match;
                                    }
                                    else
                                    {
                                        lexer.ThrowExpectationFailure(pos, U"C++ expression");
                                    }
                                }
                                *parentMatch38 = match;
                            }
                            *parentMatch34 = match;
                        }
                        *parentMatch33 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch40 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch41 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(true);
                                soulng::parser::Match* parentMatch42 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    if (*lexer == RPAREN)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        *parentMatch42 = match;
                                    }
                                    else
                                    {
                                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                                    }
                                }
                                if (match.hit)
                                {
                                    return soulng::parser::Match(true, new soulng::cppcode::TypeIdExpr(typeIdExpr.release()));
                                }
                                *parentMatch41 = match;
                            }
                            *parentMatch40 = match;
                        }
                        *parentMatch33 = match;
                    }
                    *parentMatch32 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::ExpressionList(LexerFileLexer& lexer, soulng::cppcode::CppObject* owner)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match = CppExpressionParser::AssignmentExpression(lexer);
            expr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
            if (match.hit)
            {
                owner->AddExpr(expr.release());
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
            soulng::parser::Match* parentMatch3 = &match;
            {
                while (true)
                {
                    int save = lexer.GetPos();
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch4 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == COMMA)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch4 = match;
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
                                    soulng::parser::Match match = CppExpressionParser::AssignmentExpression(lexer);
                                    expr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                    if (match.hit)
                                    {
                                        owner->AddExpr(expr.release());
                                    }
                                    *parentMatch6 = match;
                                }
                                *parentMatch5 = match;
                            }
                            *parentMatch4 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch3 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                            break;
                        }
                    }
                }
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::PrimaryExpression(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr = std::unique_ptr<soulng::cppcode::CppObject>();
    std::unique_ptr<soulng::cppcode::Literal> literal;
    std::unique_ptr<soulng::cppcode::CppObject> pexpr;
    std::unique_ptr<soulng::cppcode::IdExpr> idExpr;
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
                    soulng::parser::Match match = CppLiteralParser::CppLiteral(lexer);
                    literal.reset(static_cast<soulng::cppcode::Literal*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, literal.release());
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
                            soulng::parser::Match match(false);
                            if (*lexer == THIS)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                return soulng::parser::Match(true, new soulng::cppcode::ThisAccess);
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
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch8 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == LPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch8 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch9 = &match;
                            {
                                soulng::parser::Match match = CppExpressionParser::CppExpression(lexer);
                                pexpr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                *parentMatch9 = match;
                            }
                            *parentMatch8 = match;
                        }
                        *parentMatch7 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch10 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch11 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(true);
                                soulng::parser::Match* parentMatch12 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    if (*lexer == RPAREN)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        *parentMatch12 = match;
                                    }
                                    else
                                    {
                                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                                    }
                                }
                                if (match.hit)
                                {
                                    return soulng::parser::Match(true, new soulng::cppcode::ParenExpr(pexpr.release()));
                                }
                                *parentMatch11 = match;
                            }
                            *parentMatch10 = match;
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
            soulng::parser::Match* parentMatch13 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch14 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppExpressionParser::IdExpression(lexer);
                    idExpr.reset(static_cast<soulng::cppcode::IdExpr*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, idExpr.release());
                    }
                    *parentMatch14 = match;
                }
                *parentMatch13 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match CppExpressionParser::IdExpression(LexerFileLexer& lexer)
{
    Span s = Span();
    std::unique_ptr<soulng::parser::Value<std::u32string>> id1;
    std::unique_ptr<soulng::parser::Value<std::u32string>> ofId1;
    std::unique_ptr<soulng::parser::Value<std::u32string>> ofid2;
    std::unique_ptr<soulng::parser::Value<std::u32string>> id2;
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
                                int pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match = CppIdentifierParser::QualifiedCppId(lexer);
                                id1.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                                if (match.hit)
                                {
                                    s = span;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == COLONCOLON)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch7 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch8 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch9 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match = CppExpressionParser::OperatorFunctionId(lexer);
                                ofId1.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                                if (match.hit)
                                {
                                    s.end = span.end;
                                }
                                *parentMatch9 = match;
                            }
                            *parentMatch8 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, new soulng::cppcode::IdExpr(lexer.GetMatch(s)));
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
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
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch12 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch13 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch14 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch15 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match(true);
                                        if (match.hit)
                                        {
                                            s = span;
                                        }
                                        *parentMatch15 = match;
                                    }
                                    *parentMatch14 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch16 = &match;
                                    {
                                        soulng::parser::Match match(true);
                                        int save = lexer.GetPos();
                                        soulng::parser::Match* parentMatch17 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch18 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                if (*lexer == COLONCOLON)
                                                {
                                                    ++lexer;
                                                    match.hit = true;
                                                }
                                                *parentMatch18 = match;
                                            }
                                            if (match.hit)
                                            {
                                                *parentMatch17 = match;
                                            }
                                            else
                                            {
                                                lexer.SetPos(save);
                                            }
                                        }
                                        *parentMatch16 = match;
                                    }
                                    *parentMatch14 = match;
                                }
                                *parentMatch13 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch19 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch20 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match = CppExpressionParser::OperatorFunctionId(lexer);
                                        ofid2.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                                        if (match.hit)
                                        {
                                            s.end = span.end;
                                        }
                                        *parentMatch20 = match;
                                    }
                                    *parentMatch19 = match;
                                }
                                *parentMatch13 = match;
                            }
                            *parentMatch12 = match;
                        }
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, new soulng::cppcode::IdExpr(lexer.GetMatch(s)));
                        }
                        *parentMatch11 = match;
                    }
                    *parentMatch10 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
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
                    soulng::parser::Match match = CppIdentifierParser::QualifiedCppId(lexer);
                    id2.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, new soulng::cppcode::IdExpr(id2->value));
                    }
                    *parentMatch22 = match;
                }
                *parentMatch21 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match CppExpressionParser::TypeSpecifierOrTypeName(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::TypeSpecifier> simpleTypeSpecifier;
    std::unique_ptr<soulng::cppcode::TypeName> typeName;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match = CppDeclarationParser::SimpleTypeSpecifier(lexer);
            simpleTypeSpecifier.reset(static_cast<soulng::cppcode::TypeSpecifier*>(match.value));
            if (match.hit)
            {
                return soulng::parser::Match(true, simpleTypeSpecifier.release());
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
                    soulng::parser::Match match = CppDeclarationParser::TypeName(lexer);
                    typeName.reset(static_cast<soulng::cppcode::TypeName*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, typeName.release());
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

soulng::parser::Match CppExpressionParser::NewExpression(LexerFileLexer& lexer)
{
    bool global = bool();
    std::unique_ptr<soulng::cppcode::NewExpr> newExpr = std::unique_ptr<soulng::cppcode::NewExpr>();
    std::unique_ptr<soulng::cppcode::TypeId> newTypeId;
    std::unique_ptr<soulng::cppcode::TypeId> ti;
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
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            soulng::parser::Match match(true);
                                            int save = lexer.GetPos();
                                            soulng::parser::Match* parentMatch10 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch11 = &match;
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch12 = &match;
                                                    {
                                                        int pos = lexer.GetPos();
                                                        soulng::parser::Match match(false);
                                                        if (*lexer == COLONCOLON)
                                                        {
                                                            ++lexer;
                                                            match.hit = true;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            global = true;
                                                        }
                                                        *parentMatch12 = match;
                                                    }
                                                    *parentMatch11 = match;
                                                }
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
                                        if (match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch13 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch14 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match(false);
                                                    if (*lexer == NEW)
                                                    {
                                                        ++lexer;
                                                        match.hit = true;
                                                    }
                                                    if (match.hit)
                                                    {
                                                        newExpr.reset(new soulng::cppcode::NewExpr(global));
                                                    }
                                                    *parentMatch14 = match;
                                                }
                                                *parentMatch13 = match;
                                            }
                                            *parentMatch9 = match;
                                        }
                                        *parentMatch8 = match;
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
                                                if (match.hit)
                                                {
                                                    newExpr->BeginAddPlacement();
                                                }
                                                *parentMatch16 = match;
                                            }
                                            *parentMatch15 = match;
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch17 = &match;
                                    {
                                        soulng::parser::Match match(true);
                                        int save = lexer.GetPos();
                                        soulng::parser::Match* parentMatch18 = &match;
                                        {
                                            soulng::parser::Match match = CppExpressionParser::NewPlacement(lexer, newExpr.get());
                                            if (match.hit)
                                            {
                                                *parentMatch18 = match;
                                            }
                                            else
                                            {
                                                lexer.SetPos(save);
                                            }
                                        }
                                        *parentMatch17 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch6 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch19 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch20 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match(true);
                                        if (match.hit)
                                        {
                                            newExpr->EndAddPlacement();
                                        }
                                        *parentMatch20 = match;
                                    }
                                    *parentMatch19 = match;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch21 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch22 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch23 = &match;
                                    {
                                        int save = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch24 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = CppExpressionParser::NewTypeId(lexer);
                                            newTypeId.reset(static_cast<soulng::cppcode::TypeId*>(match.value));
                                            if (match.hit)
                                            {
                                                newExpr->SetParens(false);
                                                newExpr->SetTypeId(newTypeId.release());
                                            }
                                            *parentMatch24 = match;
                                        }
                                        *parentMatch23 = match;
                                        if (!match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch25 = &match;
                                            lexer.SetPos(save);
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch26 = &match;
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch27 = &match;
                                                    {
                                                        soulng::parser::Match match(false);
                                                        if (*lexer == LPAREN)
                                                        {
                                                            ++lexer;
                                                            match.hit = true;
                                                        }
                                                        *parentMatch27 = match;
                                                    }
                                                    if (match.hit)
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch28 = &match;
                                                        {
                                                            soulng::parser::Match match = CppDeclaratorParser::TypeId(lexer);
                                                            ti.reset(static_cast<soulng::cppcode::TypeId*>(match.value));
                                                            *parentMatch28 = match;
                                                        }
                                                        *parentMatch27 = match;
                                                    }
                                                    *parentMatch26 = match;
                                                }
                                                if (match.hit)
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch29 = &match;
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch30 = &match;
                                                        {
                                                            int pos = lexer.GetPos();
                                                            soulng::parser::Match match(false);
                                                            if (*lexer == RPAREN)
                                                            {
                                                                ++lexer;
                                                                match.hit = true;
                                                            }
                                                            if (match.hit)
                                                            {
                                                                newExpr->SetParens(true);
                                                                newExpr->SetTypeId(ti.release());
                                                            }
                                                            *parentMatch30 = match;
                                                        }
                                                        *parentMatch29 = match;
                                                    }
                                                    *parentMatch26 = match;
                                                }
                                                *parentMatch25 = match;
                                            }
                                            *parentMatch23 = match;
                                        }
                                    }
                                    *parentMatch22 = match;
                                }
                                *parentMatch21 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch31 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch32 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(true);
                                if (match.hit)
                                {
                                    newExpr->BeginAddInitializer();
                                }
                                *parentMatch32 = match;
                            }
                            *parentMatch31 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch33 = &match;
                    {
                        soulng::parser::Match match(true);
                        int save = lexer.GetPos();
                        soulng::parser::Match* parentMatch34 = &match;
                        {
                            soulng::parser::Match match = CppExpressionParser::NewInitializer(lexer, newExpr.get());
                            if (match.hit)
                            {
                                *parentMatch34 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                            }
                        }
                        *parentMatch33 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch35 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch36 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(true);
                        if (match.hit)
                        {
                            newExpr->EndAddInitializer();
                        }
                        *parentMatch36 = match;
                    }
                    *parentMatch35 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, newExpr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::NewPlacement(LexerFileLexer& lexer, soulng::cppcode::CppObject* owner)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            if (*lexer == LPAREN)
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
                soulng::parser::Match match = CppExpressionParser::ExpressionList(lexer, owner);
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch3 = &match;
        {
            soulng::parser::Match match(false);
            if (*lexer == RPAREN)
            {
                ++lexer;
                match.hit = true;
            }
            *parentMatch3 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::NewTypeId(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::TypeId> ti = std::unique_ptr<soulng::cppcode::TypeId>();
    std::unique_ptr<soulng::cppcode::TypeName> typeName;
    std::unique_ptr<soulng::parser::Value<std::u32string>> newDeclarator;
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
                ti.reset(new soulng::cppcode::TypeId);
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
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                int save = lexer.GetPos();
                                soulng::parser::Match match = CppDeclaratorParser::TypeSpecifierSeq(lexer, ti.get());
                                *parentMatch7 = match;
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
                                            soulng::parser::Match match = CppDeclarationParser::TypeName(lexer);
                                            typeName.reset(static_cast<soulng::cppcode::TypeName*>(match.value));
                                            if (match.hit)
                                            {
                                                ti->Add(typeName.release());
                                            }
                                            *parentMatch9 = match;
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                            }
                            *parentMatch6 = match;
                        }
                        *parentMatch5 = match;
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
                                    soulng::parser::Match* parentMatch13 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match = CppExpressionParser::NewDeclarator(lexer);
                                        newDeclarator.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                                        if (match.hit)
                                        {
                                            ti->Declarator() = newDeclarator->value;
                                        }
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
                        *parentMatch5 = match;
                    }
                    *parentMatch4 = match;
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, ti.release());
                }
                *parentMatch3 = match;
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::NewDeclarator(LexerFileLexer& lexer)
{
    Span s = Span();
    std::unique_ptr<soulng::parser::Value<std::u32string>> newDeclarator;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::lexer::Span span = lexer.GetSpan();
            soulng::parser::Match match(true);
            if (match.hit)
            {
                s = span;
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
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        int save = lexer.GetPos();
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match = CppDeclaratorParser::PtrOperator(lexer);
                                if (match.hit)
                                {
                                    s.end = span.end;
                                }
                                *parentMatch7 = match;
                            }
                            *parentMatch6 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch8 = &match;
                            {
                                soulng::parser::Match match(true);
                                int save = lexer.GetPos();
                                soulng::parser::Match* parentMatch9 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch10 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch11 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::lexer::Span span = lexer.GetSpan();
                                            soulng::parser::Match match = CppExpressionParser::NewDeclarator(lexer);
                                            newDeclarator.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                                            if (match.hit)
                                            {
                                                s.end = span.end;
                                            }
                                            *parentMatch11 = match;
                                        }
                                        *parentMatch10 = match;
                                    }
                                    if (match.hit)
                                    {
                                        *parentMatch9 = match;
                                    }
                                    else
                                    {
                                        lexer.SetPos(save);
                                    }
                                }
                                *parentMatch8 = match;
                            }
                            *parentMatch6 = match;
                        }
                        *parentMatch5 = match;
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
                                    soulng::lexer::Span span = lexer.GetSpan();
                                    soulng::parser::Match match = CppExpressionParser::DirectNewDeclarator(lexer);
                                    if (match.hit)
                                    {
                                        s.end = span.end;
                                    }
                                    *parentMatch13 = match;
                                }
                                *parentMatch12 = match;
                            }
                            *parentMatch5 = match;
                        }
                    }
                    *parentMatch4 = match;
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, new soulng::parser::Value<std::u32string>(soulng::util::Trim(lexer.GetMatch(s))));
                }
                *parentMatch3 = match;
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::NewInitializer(LexerFileLexer& lexer, soulng::cppcode::CppObject* owner)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            if (*lexer == LPAREN)
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
                int save = lexer.GetPos();
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match = CppExpressionParser::ExpressionList(lexer, owner);
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
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch4 = &match;
        {
            soulng::parser::Match match(false);
            if (*lexer == RPAREN)
            {
                ++lexer;
                match.hit = true;
            }
            *parentMatch4 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::DirectNewDeclarator(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr;
    std::unique_ptr<soulng::cppcode::CppObject> constantExpr;
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
                if (*lexer == LBRACKET)
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
                    soulng::parser::Match match = CppExpressionParser::CppExpression(lexer);
                    expr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch4 = &match;
            {
                soulng::parser::Match match(false);
                if (*lexer == RBRACKET)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch4 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch5 = &match;
        {
            soulng::parser::Match match(true);
            soulng::parser::Match* parentMatch6 = &match;
            {
                while (true)
                {
                    int save = lexer.GetPos();
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch7 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch8 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch9 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    if (*lexer == LBRACKET)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    *parentMatch9 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch10 = &match;
                                    {
                                        soulng::parser::Match match = CppExpressionParser::ConstantExpression(lexer);
                                        constantExpr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                        *parentMatch10 = match;
                                    }
                                    *parentMatch9 = match;
                                }
                                *parentMatch8 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch11 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    if (*lexer == RBRACKET)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    *parentMatch11 = match;
                                }
                                *parentMatch8 = match;
                            }
                            *parentMatch7 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch6 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                            break;
                        }
                    }
                }
            }
            *parentMatch5 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::DeleteExpression(LexerFileLexer& lexer)
{
    bool global = bool();
    bool array = bool();
    std::unique_ptr<soulng::cppcode::CppObject> ptr;
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
                        soulng::parser::Match match(true);
                        int save = lexer.GetPos();
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    if (*lexer == COLONCOLON)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        global = true;
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch6 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch5 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                            }
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch8 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == DELETE)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch8 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
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
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch11 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch12 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    if (*lexer == LBRACKET)
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
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch14 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match(false);
                                            if (*lexer == RBRACKET)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            if (match.hit)
                                            {
                                                array = true;
                                            }
                                            *parentMatch14 = match;
                                        }
                                        *parentMatch13 = match;
                                    }
                                    *parentMatch12 = match;
                                }
                                *parentMatch11 = match;
                            }
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
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch15 = &match;
                {
                    soulng::parser::Match match = CppExpressionParser::CastExpression(lexer);
                    ptr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    *parentMatch15 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::cppcode::DeleteExpr(global, array, ptr.release()));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::OperatorFunctionId(LexerFileLexer& lexer)
{
    Span s = Span();
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::lexer::Span span = lexer.GetSpan();
            soulng::parser::Match match(false);
            if (*lexer == OPERATOR)
            {
                ++lexer;
                match.hit = true;
            }
            if (match.hit)
            {
                s = span;
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
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = CppExpressionParser::Operator(lexer);
                if (match.hit)
                {
                    s.end = span.end;
                    return soulng::parser::Match(true, new soulng::parser::Value<std::u32string>(lexer.GetMatch(s)));
                }
                *parentMatch3 = match;
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppExpressionParser::Operator(LexerFileLexer& lexer)
{
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
                                        int save = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            int save = lexer.GetPos();
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch10 = &match;
                                            {
                                                int save = lexer.GetPos();
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch11 = &match;
                                                {
                                                    int save = lexer.GetPos();
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch12 = &match;
                                                    {
                                                        int save = lexer.GetPos();
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch13 = &match;
                                                        {
                                                            int save = lexer.GetPos();
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch14 = &match;
                                                            {
                                                                int save = lexer.GetPos();
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch15 = &match;
                                                                {
                                                                    int save = lexer.GetPos();
                                                                    soulng::parser::Match match(false);
                                                                    soulng::parser::Match* parentMatch16 = &match;
                                                                    {
                                                                        int save = lexer.GetPos();
                                                                        soulng::parser::Match match(false);
                                                                        soulng::parser::Match* parentMatch17 = &match;
                                                                        {
                                                                            int save = lexer.GetPos();
                                                                            soulng::parser::Match match(false);
                                                                            soulng::parser::Match* parentMatch18 = &match;
                                                                            {
                                                                                int save = lexer.GetPos();
                                                                                soulng::parser::Match match(false);
                                                                                soulng::parser::Match* parentMatch19 = &match;
                                                                                {
                                                                                    int save = lexer.GetPos();
                                                                                    soulng::parser::Match match(false);
                                                                                    soulng::parser::Match* parentMatch20 = &match;
                                                                                    {
                                                                                        int save = lexer.GetPos();
                                                                                        soulng::parser::Match match(false);
                                                                                        soulng::parser::Match* parentMatch21 = &match;
                                                                                        {
                                                                                            int save = lexer.GetPos();
                                                                                            soulng::parser::Match match(false);
                                                                                            soulng::parser::Match* parentMatch22 = &match;
                                                                                            {
                                                                                                int save = lexer.GetPos();
                                                                                                soulng::parser::Match match(false);
                                                                                                soulng::parser::Match* parentMatch23 = &match;
                                                                                                {
                                                                                                    int save = lexer.GetPos();
                                                                                                    soulng::parser::Match match(false);
                                                                                                    soulng::parser::Match* parentMatch24 = &match;
                                                                                                    {
                                                                                                        int save = lexer.GetPos();
                                                                                                        soulng::parser::Match match(false);
                                                                                                        soulng::parser::Match* parentMatch25 = &match;
                                                                                                        {
                                                                                                            int save = lexer.GetPos();
                                                                                                            soulng::parser::Match match(false);
                                                                                                            soulng::parser::Match* parentMatch26 = &match;
                                                                                                            {
                                                                                                                int save = lexer.GetPos();
                                                                                                                soulng::parser::Match match(false);
                                                                                                                soulng::parser::Match* parentMatch27 = &match;
                                                                                                                {
                                                                                                                    int save = lexer.GetPos();
                                                                                                                    soulng::parser::Match match(false);
                                                                                                                    soulng::parser::Match* parentMatch28 = &match;
                                                                                                                    {
                                                                                                                        int save = lexer.GetPos();
                                                                                                                        soulng::parser::Match match(false);
                                                                                                                        soulng::parser::Match* parentMatch29 = &match;
                                                                                                                        {
                                                                                                                            int save = lexer.GetPos();
                                                                                                                            soulng::parser::Match match(false);
                                                                                                                            soulng::parser::Match* parentMatch30 = &match;
                                                                                                                            {
                                                                                                                                int save = lexer.GetPos();
                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                soulng::parser::Match* parentMatch31 = &match;
                                                                                                                                {
                                                                                                                                    int save = lexer.GetPos();
                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                    soulng::parser::Match* parentMatch32 = &match;
                                                                                                                                    {
                                                                                                                                        int save = lexer.GetPos();
                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                        soulng::parser::Match* parentMatch33 = &match;
                                                                                                                                        {
                                                                                                                                            int save = lexer.GetPos();
                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                            soulng::parser::Match* parentMatch34 = &match;
                                                                                                                                            {
                                                                                                                                                int save = lexer.GetPos();
                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                soulng::parser::Match* parentMatch35 = &match;
                                                                                                                                                {
                                                                                                                                                    int save = lexer.GetPos();
                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                    soulng::parser::Match* parentMatch36 = &match;
                                                                                                                                                    {
                                                                                                                                                        int save = lexer.GetPos();
                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                        soulng::parser::Match* parentMatch37 = &match;
                                                                                                                                                        {
                                                                                                                                                            int save = lexer.GetPos();
                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                            soulng::parser::Match* parentMatch38 = &match;
                                                                                                                                                            {
                                                                                                                                                                int save = lexer.GetPos();
                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                soulng::parser::Match* parentMatch39 = &match;
                                                                                                                                                                {
                                                                                                                                                                    int save = lexer.GetPos();
                                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                                    soulng::parser::Match* parentMatch40 = &match;
                                                                                                                                                                    {
                                                                                                                                                                        int save = lexer.GetPos();
                                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                                        soulng::parser::Match* parentMatch41 = &match;
                                                                                                                                                                        {
                                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                                            if (*lexer == LBRACKET)
                                                                                                                                                                            {
                                                                                                                                                                                ++lexer;
                                                                                                                                                                                match.hit = true;
                                                                                                                                                                            }
                                                                                                                                                                            *parentMatch41 = match;
                                                                                                                                                                        }
                                                                                                                                                                        if (match.hit)
                                                                                                                                                                        {
                                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                                            soulng::parser::Match* parentMatch42 = &match;
                                                                                                                                                                            {
                                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                                if (*lexer == RBRACKET)
                                                                                                                                                                                {
                                                                                                                                                                                    ++lexer;
                                                                                                                                                                                    match.hit = true;
                                                                                                                                                                                }
                                                                                                                                                                                *parentMatch42 = match;
                                                                                                                                                                            }
                                                                                                                                                                            *parentMatch41 = match;
                                                                                                                                                                        }
                                                                                                                                                                        *parentMatch40 = match;
                                                                                                                                                                        if (!match.hit)
                                                                                                                                                                        {
                                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                                            soulng::parser::Match* parentMatch43 = &match;
                                                                                                                                                                            lexer.SetPos(save);
                                                                                                                                                                            {
                                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                                soulng::parser::Match* parentMatch44 = &match;
                                                                                                                                                                                {
                                                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                                                    if (*lexer == LPAREN)
                                                                                                                                                                                    {
                                                                                                                                                                                        ++lexer;
                                                                                                                                                                                        match.hit = true;
                                                                                                                                                                                    }
                                                                                                                                                                                    *parentMatch44 = match;
                                                                                                                                                                                }
                                                                                                                                                                                if (match.hit)
                                                                                                                                                                                {
                                                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                                                    soulng::parser::Match* parentMatch45 = &match;
                                                                                                                                                                                    {
                                                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                                                        if (*lexer == RPAREN)
                                                                                                                                                                                        {
                                                                                                                                                                                            ++lexer;
                                                                                                                                                                                            match.hit = true;
                                                                                                                                                                                        }
                                                                                                                                                                                        *parentMatch45 = match;
                                                                                                                                                                                    }
                                                                                                                                                                                    *parentMatch44 = match;
                                                                                                                                                                                }
                                                                                                                                                                                *parentMatch43 = match;
                                                                                                                                                                            }
                                                                                                                                                                            *parentMatch40 = match;
                                                                                                                                                                        }
                                                                                                                                                                    }
                                                                                                                                                                    *parentMatch39 = match;
                                                                                                                                                                    if (!match.hit)
                                                                                                                                                                    {
                                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                                        soulng::parser::Match* parentMatch46 = &match;
                                                                                                                                                                        lexer.SetPos(save);
                                                                                                                                                                        {
                                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                                            if (*lexer == ARROWSTAR)
                                                                                                                                                                            {
                                                                                                                                                                                ++lexer;
                                                                                                                                                                                match.hit = true;
                                                                                                                                                                            }
                                                                                                                                                                            *parentMatch46 = match;
                                                                                                                                                                        }
                                                                                                                                                                        *parentMatch39 = match;
                                                                                                                                                                    }
                                                                                                                                                                }
                                                                                                                                                                *parentMatch38 = match;
                                                                                                                                                                if (!match.hit)
                                                                                                                                                                {
                                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                                    soulng::parser::Match* parentMatch47 = &match;
                                                                                                                                                                    lexer.SetPos(save);
                                                                                                                                                                    {
                                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                                        if (*lexer == ARROW)
                                                                                                                                                                        {
                                                                                                                                                                            ++lexer;
                                                                                                                                                                            match.hit = true;
                                                                                                                                                                        }
                                                                                                                                                                        *parentMatch47 = match;
                                                                                                                                                                    }
                                                                                                                                                                    *parentMatch38 = match;
                                                                                                                                                                }
                                                                                                                                                            }
                                                                                                                                                            *parentMatch37 = match;
                                                                                                                                                            if (!match.hit)
                                                                                                                                                            {
                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                soulng::parser::Match* parentMatch48 = &match;
                                                                                                                                                                lexer.SetPos(save);
                                                                                                                                                                {
                                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                                    if (*lexer == COMMA)
                                                                                                                                                                    {
                                                                                                                                                                        ++lexer;
                                                                                                                                                                        match.hit = true;
                                                                                                                                                                    }
                                                                                                                                                                    *parentMatch48 = match;
                                                                                                                                                                }
                                                                                                                                                                *parentMatch37 = match;
                                                                                                                                                            }
                                                                                                                                                        }
                                                                                                                                                        *parentMatch36 = match;
                                                                                                                                                        if (!match.hit)
                                                                                                                                                        {
                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                            soulng::parser::Match* parentMatch49 = &match;
                                                                                                                                                            lexer.SetPos(save);
                                                                                                                                                            {
                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                if (*lexer == MINUSMINUS)
                                                                                                                                                                {
                                                                                                                                                                    ++lexer;
                                                                                                                                                                    match.hit = true;
                                                                                                                                                                }
                                                                                                                                                                *parentMatch49 = match;
                                                                                                                                                            }
                                                                                                                                                            *parentMatch36 = match;
                                                                                                                                                        }
                                                                                                                                                    }
                                                                                                                                                    *parentMatch35 = match;
                                                                                                                                                    if (!match.hit)
                                                                                                                                                    {
                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                        soulng::parser::Match* parentMatch50 = &match;
                                                                                                                                                        lexer.SetPos(save);
                                                                                                                                                        {
                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                            if (*lexer == PLUSPLUS)
                                                                                                                                                            {
                                                                                                                                                                ++lexer;
                                                                                                                                                                match.hit = true;
                                                                                                                                                            }
                                                                                                                                                            *parentMatch50 = match;
                                                                                                                                                        }
                                                                                                                                                        *parentMatch35 = match;
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                                *parentMatch34 = match;
                                                                                                                                                if (!match.hit)
                                                                                                                                                {
                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                    soulng::parser::Match* parentMatch51 = &match;
                                                                                                                                                    lexer.SetPos(save);
                                                                                                                                                    {
                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                        if (*lexer == DISJUNCTION)
                                                                                                                                                        {
                                                                                                                                                            ++lexer;
                                                                                                                                                            match.hit = true;
                                                                                                                                                        }
                                                                                                                                                        *parentMatch51 = match;
                                                                                                                                                    }
                                                                                                                                                    *parentMatch34 = match;
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                            *parentMatch33 = match;
                                                                                                                                            if (!match.hit)
                                                                                                                                            {
                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                soulng::parser::Match* parentMatch52 = &match;
                                                                                                                                                lexer.SetPos(save);
                                                                                                                                                {
                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                    if (*lexer == AMPAMP)
                                                                                                                                                    {
                                                                                                                                                        ++lexer;
                                                                                                                                                        match.hit = true;
                                                                                                                                                    }
                                                                                                                                                    *parentMatch52 = match;
                                                                                                                                                }
                                                                                                                                                *parentMatch33 = match;
                                                                                                                                            }
                                                                                                                                        }
                                                                                                                                        *parentMatch32 = match;
                                                                                                                                        if (!match.hit)
                                                                                                                                        {
                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                            soulng::parser::Match* parentMatch53 = &match;
                                                                                                                                            lexer.SetPos(save);
                                                                                                                                            {
                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                if (*lexer == LEQ)
                                                                                                                                                {
                                                                                                                                                    ++lexer;
                                                                                                                                                    match.hit = true;
                                                                                                                                                }
                                                                                                                                                *parentMatch53 = match;
                                                                                                                                            }
                                                                                                                                            *parentMatch32 = match;
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                    *parentMatch31 = match;
                                                                                                                                    if (!match.hit)
                                                                                                                                    {
                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                        soulng::parser::Match* parentMatch54 = &match;
                                                                                                                                        lexer.SetPos(save);
                                                                                                                                        {
                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                            if (*lexer == GEQ)
                                                                                                                                            {
                                                                                                                                                ++lexer;
                                                                                                                                                match.hit = true;
                                                                                                                                            }
                                                                                                                                            *parentMatch54 = match;
                                                                                                                                        }
                                                                                                                                        *parentMatch31 = match;
                                                                                                                                    }
                                                                                                                                }
                                                                                                                                *parentMatch30 = match;
                                                                                                                                if (!match.hit)
                                                                                                                                {
                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                    soulng::parser::Match* parentMatch55 = &match;
                                                                                                                                    lexer.SetPos(save);
                                                                                                                                    {
                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                        if (*lexer == NEQ)
                                                                                                                                        {
                                                                                                                                            ++lexer;
                                                                                                                                            match.hit = true;
                                                                                                                                        }
                                                                                                                                        *parentMatch55 = match;
                                                                                                                                    }
                                                                                                                                    *parentMatch30 = match;
                                                                                                                                }
                                                                                                                            }
                                                                                                                            *parentMatch29 = match;
                                                                                                                            if (!match.hit)
                                                                                                                            {
                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                soulng::parser::Match* parentMatch56 = &match;
                                                                                                                                lexer.SetPos(save);
                                                                                                                                {
                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                    if (*lexer == EQ)
                                                                                                                                    {
                                                                                                                                        ++lexer;
                                                                                                                                        match.hit = true;
                                                                                                                                    }
                                                                                                                                    *parentMatch56 = match;
                                                                                                                                }
                                                                                                                                *parentMatch29 = match;
                                                                                                                            }
                                                                                                                        }
                                                                                                                        *parentMatch28 = match;
                                                                                                                        if (!match.hit)
                                                                                                                        {
                                                                                                                            soulng::parser::Match match(false);
                                                                                                                            soulng::parser::Match* parentMatch57 = &match;
                                                                                                                            lexer.SetPos(save);
                                                                                                                            {
                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                if (*lexer == SHIFTLEFTASSIGN)
                                                                                                                                {
                                                                                                                                    ++lexer;
                                                                                                                                    match.hit = true;
                                                                                                                                }
                                                                                                                                *parentMatch57 = match;
                                                                                                                            }
                                                                                                                            *parentMatch28 = match;
                                                                                                                        }
                                                                                                                    }
                                                                                                                    *parentMatch27 = match;
                                                                                                                    if (!match.hit)
                                                                                                                    {
                                                                                                                        soulng::parser::Match match(false);
                                                                                                                        soulng::parser::Match* parentMatch58 = &match;
                                                                                                                        lexer.SetPos(save);
                                                                                                                        {
                                                                                                                            soulng::parser::Match match(false);
                                                                                                                            if (*lexer == SHIFTRIGHTASSIGN)
                                                                                                                            {
                                                                                                                                ++lexer;
                                                                                                                                match.hit = true;
                                                                                                                            }
                                                                                                                            *parentMatch58 = match;
                                                                                                                        }
                                                                                                                        *parentMatch27 = match;
                                                                                                                    }
                                                                                                                }
                                                                                                                *parentMatch26 = match;
                                                                                                                if (!match.hit)
                                                                                                                {
                                                                                                                    soulng::parser::Match match(false);
                                                                                                                    soulng::parser::Match* parentMatch59 = &match;
                                                                                                                    lexer.SetPos(save);
                                                                                                                    {
                                                                                                                        soulng::parser::Match match(false);
                                                                                                                        if (*lexer == SHIFTLEFT)
                                                                                                                        {
                                                                                                                            ++lexer;
                                                                                                                            match.hit = true;
                                                                                                                        }
                                                                                                                        *parentMatch59 = match;
                                                                                                                    }
                                                                                                                    *parentMatch26 = match;
                                                                                                                }
                                                                                                            }
                                                                                                            *parentMatch25 = match;
                                                                                                            if (!match.hit)
                                                                                                            {
                                                                                                                soulng::parser::Match match(false);
                                                                                                                soulng::parser::Match* parentMatch60 = &match;
                                                                                                                lexer.SetPos(save);
                                                                                                                {
                                                                                                                    soulng::parser::Match match(false);
                                                                                                                    if (*lexer == SHIFTRIGHT)
                                                                                                                    {
                                                                                                                        ++lexer;
                                                                                                                        match.hit = true;
                                                                                                                    }
                                                                                                                    *parentMatch60 = match;
                                                                                                                }
                                                                                                                *parentMatch25 = match;
                                                                                                            }
                                                                                                        }
                                                                                                        *parentMatch24 = match;
                                                                                                        if (!match.hit)
                                                                                                        {
                                                                                                            soulng::parser::Match match(false);
                                                                                                            soulng::parser::Match* parentMatch61 = &match;
                                                                                                            lexer.SetPos(save);
                                                                                                            {
                                                                                                                soulng::parser::Match match(false);
                                                                                                                if (*lexer == ORASSIGN)
                                                                                                                {
                                                                                                                    ++lexer;
                                                                                                                    match.hit = true;
                                                                                                                }
                                                                                                                *parentMatch61 = match;
                                                                                                            }
                                                                                                            *parentMatch24 = match;
                                                                                                        }
                                                                                                    }
                                                                                                    *parentMatch23 = match;
                                                                                                    if (!match.hit)
                                                                                                    {
                                                                                                        soulng::parser::Match match(false);
                                                                                                        soulng::parser::Match* parentMatch62 = &match;
                                                                                                        lexer.SetPos(save);
                                                                                                        {
                                                                                                            soulng::parser::Match match(false);
                                                                                                            if (*lexer == ANDASSIGN)
                                                                                                            {
                                                                                                                ++lexer;
                                                                                                                match.hit = true;
                                                                                                            }
                                                                                                            *parentMatch62 = match;
                                                                                                        }
                                                                                                        *parentMatch23 = match;
                                                                                                    }
                                                                                                }
                                                                                                *parentMatch22 = match;
                                                                                                if (!match.hit)
                                                                                                {
                                                                                                    soulng::parser::Match match(false);
                                                                                                    soulng::parser::Match* parentMatch63 = &match;
                                                                                                    lexer.SetPos(save);
                                                                                                    {
                                                                                                        soulng::parser::Match match(false);
                                                                                                        if (*lexer == XORASSIGN)
                                                                                                        {
                                                                                                            ++lexer;
                                                                                                            match.hit = true;
                                                                                                        }
                                                                                                        *parentMatch63 = match;
                                                                                                    }
                                                                                                    *parentMatch22 = match;
                                                                                                }
                                                                                            }
                                                                                            *parentMatch21 = match;
                                                                                            if (!match.hit)
                                                                                            {
                                                                                                soulng::parser::Match match(false);
                                                                                                soulng::parser::Match* parentMatch64 = &match;
                                                                                                lexer.SetPos(save);
                                                                                                {
                                                                                                    soulng::parser::Match match(false);
                                                                                                    if (*lexer == REMASSIGN)
                                                                                                    {
                                                                                                        ++lexer;
                                                                                                        match.hit = true;
                                                                                                    }
                                                                                                    *parentMatch64 = match;
                                                                                                }
                                                                                                *parentMatch21 = match;
                                                                                            }
                                                                                        }
                                                                                        *parentMatch20 = match;
                                                                                        if (!match.hit)
                                                                                        {
                                                                                            soulng::parser::Match match(false);
                                                                                            soulng::parser::Match* parentMatch65 = &match;
                                                                                            lexer.SetPos(save);
                                                                                            {
                                                                                                soulng::parser::Match match(false);
                                                                                                if (*lexer == DIVASSIGN)
                                                                                                {
                                                                                                    ++lexer;
                                                                                                    match.hit = true;
                                                                                                }
                                                                                                *parentMatch65 = match;
                                                                                            }
                                                                                            *parentMatch20 = match;
                                                                                        }
                                                                                    }
                                                                                    *parentMatch19 = match;
                                                                                    if (!match.hit)
                                                                                    {
                                                                                        soulng::parser::Match match(false);
                                                                                        soulng::parser::Match* parentMatch66 = &match;
                                                                                        lexer.SetPos(save);
                                                                                        {
                                                                                            soulng::parser::Match match(false);
                                                                                            if (*lexer == MULASSIGN)
                                                                                            {
                                                                                                ++lexer;
                                                                                                match.hit = true;
                                                                                            }
                                                                                            *parentMatch66 = match;
                                                                                        }
                                                                                        *parentMatch19 = match;
                                                                                    }
                                                                                }
                                                                                *parentMatch18 = match;
                                                                                if (!match.hit)
                                                                                {
                                                                                    soulng::parser::Match match(false);
                                                                                    soulng::parser::Match* parentMatch67 = &match;
                                                                                    lexer.SetPos(save);
                                                                                    {
                                                                                        soulng::parser::Match match(false);
                                                                                        if (*lexer == MINUSASSIGN)
                                                                                        {
                                                                                            ++lexer;
                                                                                            match.hit = true;
                                                                                        }
                                                                                        *parentMatch67 = match;
                                                                                    }
                                                                                    *parentMatch18 = match;
                                                                                }
                                                                            }
                                                                            *parentMatch17 = match;
                                                                            if (!match.hit)
                                                                            {
                                                                                soulng::parser::Match match(false);
                                                                                soulng::parser::Match* parentMatch68 = &match;
                                                                                lexer.SetPos(save);
                                                                                {
                                                                                    soulng::parser::Match match(false);
                                                                                    if (*lexer == PLUSASSIGN)
                                                                                    {
                                                                                        ++lexer;
                                                                                        match.hit = true;
                                                                                    }
                                                                                    *parentMatch68 = match;
                                                                                }
                                                                                *parentMatch17 = match;
                                                                            }
                                                                        }
                                                                        *parentMatch16 = match;
                                                                        if (!match.hit)
                                                                        {
                                                                            soulng::parser::Match match(false);
                                                                            soulng::parser::Match* parentMatch69 = &match;
                                                                            lexer.SetPos(save);
                                                                            {
                                                                                soulng::parser::Match match(false);
                                                                                if (*lexer == LANGLE)
                                                                                {
                                                                                    ++lexer;
                                                                                    match.hit = true;
                                                                                }
                                                                                *parentMatch69 = match;
                                                                            }
                                                                            *parentMatch16 = match;
                                                                        }
                                                                    }
                                                                    *parentMatch15 = match;
                                                                    if (!match.hit)
                                                                    {
                                                                        soulng::parser::Match match(false);
                                                                        soulng::parser::Match* parentMatch70 = &match;
                                                                        lexer.SetPos(save);
                                                                        {
                                                                            soulng::parser::Match match(false);
                                                                            if (*lexer == RANGLE)
                                                                            {
                                                                                ++lexer;
                                                                                match.hit = true;
                                                                            }
                                                                            *parentMatch70 = match;
                                                                        }
                                                                        *parentMatch15 = match;
                                                                    }
                                                                }
                                                                *parentMatch14 = match;
                                                                if (!match.hit)
                                                                {
                                                                    soulng::parser::Match match(false);
                                                                    soulng::parser::Match* parentMatch71 = &match;
                                                                    lexer.SetPos(save);
                                                                    {
                                                                        soulng::parser::Match match(false);
                                                                        if (*lexer == ASSIGN)
                                                                        {
                                                                            ++lexer;
                                                                            match.hit = true;
                                                                        }
                                                                        *parentMatch71 = match;
                                                                    }
                                                                    *parentMatch14 = match;
                                                                }
                                                            }
                                                            *parentMatch13 = match;
                                                            if (!match.hit)
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch72 = &match;
                                                                lexer.SetPos(save);
                                                                {
                                                                    soulng::parser::Match match(false);
                                                                    if (*lexer == EXCLAMATION)
                                                                    {
                                                                        ++lexer;
                                                                        match.hit = true;
                                                                    }
                                                                    *parentMatch72 = match;
                                                                }
                                                                *parentMatch13 = match;
                                                            }
                                                        }
                                                        *parentMatch12 = match;
                                                        if (!match.hit)
                                                        {
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch73 = &match;
                                                            lexer.SetPos(save);
                                                            {
                                                                soulng::parser::Match match(false);
                                                                if (*lexer == CPL)
                                                                {
                                                                    ++lexer;
                                                                    match.hit = true;
                                                                }
                                                                *parentMatch73 = match;
                                                            }
                                                            *parentMatch12 = match;
                                                        }
                                                    }
                                                    *parentMatch11 = match;
                                                    if (!match.hit)
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch74 = &match;
                                                        lexer.SetPos(save);
                                                        {
                                                            soulng::parser::Match match(false);
                                                            if (*lexer == BITOR)
                                                            {
                                                                ++lexer;
                                                                match.hit = true;
                                                            }
                                                            *parentMatch74 = match;
                                                        }
                                                        *parentMatch11 = match;
                                                    }
                                                }
                                                *parentMatch10 = match;
                                                if (!match.hit)
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch75 = &match;
                                                    lexer.SetPos(save);
                                                    {
                                                        soulng::parser::Match match(false);
                                                        if (*lexer == AMP)
                                                        {
                                                            ++lexer;
                                                            match.hit = true;
                                                        }
                                                        *parentMatch75 = match;
                                                    }
                                                    *parentMatch10 = match;
                                                }
                                            }
                                            *parentMatch9 = match;
                                            if (!match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch76 = &match;
                                                lexer.SetPos(save);
                                                {
                                                    soulng::parser::Match match(false);
                                                    if (*lexer == BITXOR)
                                                    {
                                                        ++lexer;
                                                        match.hit = true;
                                                    }
                                                    *parentMatch76 = match;
                                                }
                                                *parentMatch9 = match;
                                            }
                                        }
                                        *parentMatch8 = match;
                                        if (!match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch77 = &match;
                                            lexer.SetPos(save);
                                            {
                                                soulng::parser::Match match(false);
                                                if (*lexer == REM)
                                                {
                                                    ++lexer;
                                                    match.hit = true;
                                                }
                                                *parentMatch77 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                    }
                                    *parentMatch7 = match;
                                    if (!match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch78 = &match;
                                        lexer.SetPos(save);
                                        {
                                            soulng::parser::Match match(false);
                                            if (*lexer == DIV)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            *parentMatch78 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                }
                                *parentMatch6 = match;
                                if (!match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch79 = &match;
                                    lexer.SetPos(save);
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == STAR)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        *parentMatch79 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                            }
                            *parentMatch5 = match;
                            if (!match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch80 = &match;
                                lexer.SetPos(save);
                                {
                                    soulng::parser::Match match(false);
                                    if (*lexer == MINUS)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    *parentMatch80 = match;
                                }
                                *parentMatch5 = match;
                            }
                        }
                        *parentMatch4 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch81 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == PLUS)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch81 = match;
                            }
                            *parentMatch4 = match;
                        }
                    }
                    *parentMatch3 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch82 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch83 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch84 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    if (*lexer == NEW)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    *parentMatch84 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch85 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == LBRACKET)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        *parentMatch85 = match;
                                    }
                                    *parentMatch84 = match;
                                }
                                *parentMatch83 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch86 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    if (*lexer == RBRACKET)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    *parentMatch86 = match;
                                }
                                *parentMatch83 = match;
                            }
                            *parentMatch82 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch87 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch88 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch89 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == DELETE)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch89 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch90 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    if (*lexer == LBRACKET)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    *parentMatch90 = match;
                                }
                                *parentMatch89 = match;
                            }
                            *parentMatch88 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch91 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == RBRACKET)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch91 = match;
                            }
                            *parentMatch88 = match;
                        }
                        *parentMatch87 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch92 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    if (*lexer == NEW)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch92 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch93 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                if (*lexer == DELETE)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch93 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}
