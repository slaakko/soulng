#include "Expression.hpp"
#include <soulng/util/Unicode.hpp>
#include <sngcpp/parser/Declarator.hpp>
#include <sngcpp/parser/Function.hpp>
#include <sngcpp/parser/Identifier.hpp>
#include <sngcpp/parser/Literal.hpp>
#include <sngcpp/parser/SimpleType.hpp>
#include <sngcpp/parser/Statement.hpp>
#include <sngcpp/parser/Template.hpp>
#include <sngcpp/parser/TypeExpr.hpp>
#include <sngcpp/lexer/CppLexer.hpp>
#include <sngcpp/lexer/CppTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/parser/Expression.parser' using soulng parser generator spg version 3.0.0

using namespace soulng::unicode;
using namespace CppTokens;
using namespace soulng::lexer;

std::unique_ptr<sngcpp::ast::Node> ExpressionParser::Parse(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    std::unique_ptr<sngcpp::ast::Node> value;
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (lexer.Log())
    {
        lexer.Log()->WriteBeginRule(soulng::unicode::ToUtf32("parse"));
        lexer.Log()->IncIndent();
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    ++lexer;
    int64_t pos = lexer.GetPos();
    soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
    value.reset(static_cast<sngcpp::ast::Node*>(match.value));
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (lexer.Log())
    {
        lexer.Log()->DecIndent();
        lexer.Log()->WriteEndRule(soulng::unicode::ToUtf32("parse"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (match.hit)
    {
        if (*lexer == soulng::lexer::END_TOKEN)
        {
            return value;
        }
        else
        {
            lexer.ThrowExpectationFailure(lexer.GetPos(), ToUtf32(soulng::lexer::GetEndTokenInfo()));
        }
    }
    else
    {
        lexer.ThrowExpectationFailure(pos, U"Expression");
    }
    return value;
}

soulng::parser::Match ExpressionParser::Expression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("Expression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> expr = std::unique_ptr<sngcpp::ast::Node>();
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> left;
    std::unique_ptr<sngcpp::ast::Node> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = ExpressionParser::AssignmentExpression(lexer, ctx);
                    left.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
                        s = span;
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
                            int64_t save = lexer.GetPos();
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
                                                int64_t pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                soulng::parser::Match match = ExpressionParser::AssignmentExpression(lexer, ctx);
                                                right.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    s.end = span.end;
                                                    expr.reset(new sngcpp::ast::CommaExpressionNode(s, expr.release(), right.release()));
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
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Expression"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, expr.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Expression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("Expression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::ConstantExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ConstantExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> expr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match = ExpressionParser::ConditionalExpression(lexer, ctx);
        expr.reset(static_cast<sngcpp::ast::Node*>(match.value));
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ConstantExpression"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, expr.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ConstantExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ConstantExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::AssignmentExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("AssignmentExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> expr = std::unique_ptr<sngcpp::ast::Node>();
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> logicalOrExpression;
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Operator>> op;
    std::unique_ptr<sngcpp::ast::Node> initializerClause;
    std::unique_ptr<sngcpp::ast::Node> conditionalExpression;
    std::unique_ptr<sngcpp::ast::Node> throwExpression;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int64_t pos = lexer.GetPos();
            soulng::parser::Match match(true);
            if (match.hit)
            {
                ctx->BeginParsingLvalue();
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
                int64_t pos = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        int64_t save = lexer.GetPos();
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            int64_t save = lexer.GetPos();
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch8 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch9 = &match;
                                    {
                                        int64_t pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match = ExpressionParser::LogicalOrExpression(lexer, ctx);
                                        logicalOrExpression.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                        if (match.hit)
                                        {
                                            s = span;
                                            ctx->EndParsingLvalue();
                                            expr.reset(logicalOrExpression.release());
                                        }
                                        else
                                        {
                                            ctx->EndParsingLvalue();
                                        }
                                        *parentMatch9 = match;
                                    }
                                    *parentMatch8 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch10 = &match;
                                    {
                                        soulng::parser::Match match = ExpressionParser::AssignmentOperator(lexer);
                                        op.reset(static_cast<soulng::parser::Value<sngcpp::ast::Operator>*>(match.value));
                                        *parentMatch10 = match;
                                    }
                                    *parentMatch8 = match;
                                }
                                *parentMatch7 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch11 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch12 = &match;
                                    {
                                        int64_t pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match = DeclaratorParser::InitializerClause(lexer, ctx);
                                        initializerClause.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                        if (match.hit)
                                        {
                                            s.end = span.end;
                                            expr.reset(new sngcpp::ast::AssignmentExpressionNode(s, expr.release(), op->value, initializerClause.release()));
                                        }
                                        *parentMatch12 = match;
                                    }
                                    *parentMatch11 = match;
                                }
                                *parentMatch7 = match;
                            }
                            *parentMatch6 = match;
                            if (!match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch13 = &match;
                                lexer.SetPos(save);
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch14 = &match;
                                    {
                                        int64_t pos = lexer.GetPos();
                                        soulng::parser::Match match = ExpressionParser::ConditionalExpression(lexer, ctx);
                                        conditionalExpression.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                        if (match.hit)
                                        {
                                            expr.reset(conditionalExpression.release());
                                        }
                                        *parentMatch14 = match;
                                    }
                                    *parentMatch13 = match;
                                }
                                *parentMatch6 = match;
                            }
                        }
                        *parentMatch5 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch15 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch16 = &match;
                                {
                                    int64_t pos = lexer.GetPos();
                                    soulng::parser::Match match = ExpressionParser::ThrowExpression(lexer, ctx);
                                    throwExpression.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                    if (match.hit)
                                    {
                                        expr.reset(throwExpression.release());
                                    }
                                    *parentMatch16 = match;
                                }
                                *parentMatch15 = match;
                            }
                            *parentMatch5 = match;
                        }
                    }
                    *parentMatch4 = match;
                }
                if (match.hit)
                {
                    {
                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AssignmentExpression"));
                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                        return soulng::parser::Match(true, expr.release());
                    }
                }
                *parentMatch3 = match;
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AssignmentExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("AssignmentExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::AssignmentOperator(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("AssignmentOperator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    int64_t pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case ASSIGN:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AssignmentOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::assign));
                }
            }
            break;
        }
        case MULASSIGN:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AssignmentOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::mulAssign));
                }
            }
            break;
        }
        case DIVASSIGN:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AssignmentOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::divAssign));
                }
            }
            break;
        }
        case REMASSIGN:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AssignmentOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::remAssign));
                }
            }
            break;
        }
        case ADDASSIGN:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AssignmentOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::addAssign));
                }
            }
            break;
        }
        case SUBASSIGN:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AssignmentOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::subAssign));
                }
            }
            break;
        }
        case SHIFTRIGHTASSIGN:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AssignmentOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::shiftRightAssign));
                }
            }
            break;
        }
        case SHIFTLEFTASSIGN:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AssignmentOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::shiftLeftAssign));
                }
            }
            break;
        }
        case ANDASSIGN:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AssignmentOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::andAssign));
                }
            }
            break;
        }
        case XORASSIGN:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AssignmentOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::xorAssign));
                }
            }
            break;
        }
        case ORASSIGN:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AssignmentOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::orAssign));
                }
            }
            break;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AssignmentOperator"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("AssignmentOperator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::ConditionalExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ConditionalExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> expr = std::unique_ptr<sngcpp::ast::Node>();
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> logicalOrExpression;
    std::unique_ptr<sngcpp::ast::Node> thenExpr;
    std::unique_ptr<sngcpp::ast::Node> elseExpr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = ExpressionParser::LogicalOrExpression(lexer, ctx);
                    logicalOrExpression.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(logicalOrExpression.release());
                        s = span;
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
                    int64_t save = lexer.GetPos();
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
                                            soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                                            thenExpr.reset(static_cast<sngcpp::ast::Node*>(match.value));
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
                                        if (*lexer == COLON)
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
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch12 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch13 = &match;
                                    {
                                        int64_t pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match = ExpressionParser::AssignmentExpression(lexer, ctx);
                                        elseExpr.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                        if (match.hit)
                                        {
                                            s.end = span.end;
                                            expr.reset(new sngcpp::ast::ConditionalExpressionNode(s, expr.release(), thenExpr.release(), elseExpr.release()));
                                        }
                                        *parentMatch13 = match;
                                    }
                                    *parentMatch12 = match;
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
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ConditionalExpression"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, expr.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ConditionalExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ConditionalExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::ThrowExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ThrowExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> exception;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match(false);
                    if (*lexer == THROW)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        s = span;
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
                    int64_t save = lexer.GetPos();
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match = ExpressionParser::AssignmentExpression(lexer, ctx);
                                exception.reset(static_cast<sngcpp::ast::Node*>(match.value));
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
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ThrowExpression"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new sngcpp::ast::ThrowExpressionNode(s, exception.release()));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ThrowExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ThrowExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::LogicalOrExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("LogicalOrExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> expr = std::unique_ptr<sngcpp::ast::Node>();
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> left;
    std::unique_ptr<sngcpp::ast::Node> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = ExpressionParser::LogicalAndExpression(lexer, ctx);
                    left.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
                        s = span;
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
                            int64_t save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == OROR)
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
                                                int64_t pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                bool pass = true;
                                                soulng::parser::Match match = ExpressionParser::LogicalAndExpression(lexer, ctx);
                                                right.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    if (ctx->ParsingTemplateIdOrLvalueAndNotArguments()) pass = false;
                                                    else
                                                    {
                                                        s.end = span.end;
                                                        expr.reset(new sngcpp::ast::LogicalOrExpressionNode(s, expr.release(), right.release()));
                                                    }
                                                }
                                                if (match.hit && !pass)
                                                {
                                                    match = soulng::parser::Match(false);
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
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("LogicalOrExpression"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, expr.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("LogicalOrExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("LogicalOrExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::LogicalAndExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("LogicalAndExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> expr = std::unique_ptr<sngcpp::ast::Node>();
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> left;
    std::unique_ptr<sngcpp::ast::Node> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = ExpressionParser::InclusiveOrExpression(lexer, ctx);
                    left.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
                        s = span;
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
                            int64_t save = lexer.GetPos();
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
                                                int64_t pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                bool pass = true;
                                                soulng::parser::Match match = ExpressionParser::InclusiveOrExpression(lexer, ctx);
                                                right.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    if (ctx->ParsingTemplateIdOrLvalueAndNotArguments()) pass = false;
                                                    else
                                                    {
                                                        s.end = span.end;
                                                        expr.reset(new sngcpp::ast::LogicalAndExpressionNode(s, expr.release(), right.release()));
                                                    }
                                                }
                                                if (match.hit && !pass)
                                                {
                                                    match = soulng::parser::Match(false);
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
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("LogicalAndExpression"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, expr.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("LogicalAndExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("LogicalAndExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::InclusiveOrExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("InclusiveOrExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> expr = std::unique_ptr<sngcpp::ast::Node>();
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> left;
    std::unique_ptr<sngcpp::ast::Node> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = ExpressionParser::ExclusiveOrExpression(lexer, ctx);
                    left.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
                        s = span;
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
                            int64_t save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == OR)
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
                                                int64_t pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                bool pass = true;
                                                soulng::parser::Match match = ExpressionParser::ExclusiveOrExpression(lexer, ctx);
                                                right.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    if (ctx->ParsingLvalueAndNotArguments()) pass = false;
                                                    else
                                                    {
                                                        s.end = span.end;
                                                        expr.reset(new sngcpp::ast::InclusiveOrExpressionNode(s, expr.release(), right.release()));
                                                    }
                                                }
                                                if (match.hit && !pass)
                                                {
                                                    match = soulng::parser::Match(false);
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
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("InclusiveOrExpression"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, expr.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("InclusiveOrExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("InclusiveOrExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::ExclusiveOrExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ExclusiveOrExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> expr = std::unique_ptr<sngcpp::ast::Node>();
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> left;
    std::unique_ptr<sngcpp::ast::Node> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = ExpressionParser::AndExpression(lexer, ctx);
                    left.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
                        s = span;
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
                            int64_t save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == XOR)
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
                                                int64_t pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                bool pass = true;
                                                soulng::parser::Match match = ExpressionParser::AndExpression(lexer, ctx);
                                                right.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    if (ctx->ParsingLvalueAndNotArguments()) pass = false;
                                                    else
                                                    {
                                                        s.end = span.end;
                                                        expr.reset(new sngcpp::ast::ExclusiveOrExpressionNode(s, expr.release(), right.release()));
                                                    }
                                                }
                                                if (match.hit && !pass)
                                                {
                                                    match = soulng::parser::Match(false);
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
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ExclusiveOrExpression"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, expr.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ExclusiveOrExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ExclusiveOrExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::AndExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("AndExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> expr = std::unique_ptr<sngcpp::ast::Node>();
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> left;
    std::unique_ptr<sngcpp::ast::Node> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = ExpressionParser::EqualityExpression(lexer, ctx);
                    left.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
                        s = span;
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
                            int64_t save = lexer.GetPos();
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
                                                int64_t pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                bool pass = true;
                                                soulng::parser::Match match = ExpressionParser::EqualityExpression(lexer, ctx);
                                                right.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    if (ctx->ParsingLvalueAndNotArguments()) pass = false;
                                                    else
                                                    {
                                                        s.end = span.end;
                                                        expr.reset(new sngcpp::ast::AndExpressionNode(s, expr.release(), right.release()));
                                                    }
                                                }
                                                if (match.hit && !pass)
                                                {
                                                    match = soulng::parser::Match(false);
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
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AndExpression"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, expr.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AndExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("AndExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::EqualityExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("EqualityExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> expr = std::unique_ptr<sngcpp::ast::Node>();
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> left;
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Operator>> op;
    std::unique_ptr<sngcpp::ast::Node> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = ExpressionParser::RelationalExpression(lexer, ctx);
                    left.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
                        s = span;
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
                            int64_t save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match = ExpressionParser::EqualityOperator(lexer);
                                        op.reset(static_cast<soulng::parser::Value<sngcpp::ast::Operator>*>(match.value));
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
                                                int64_t pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                bool pass = true;
                                                soulng::parser::Match match = ExpressionParser::RelationalExpression(lexer, ctx);
                                                right.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    if (ctx->ParsingLvalueAndNotArguments()) pass = false;
                                                    else
                                                    {
                                                        s.end = span.end;
                                                        expr.reset(new sngcpp::ast::EqualityExpressionNode(s, expr.release(), right.release(), op->value));
                                                    }
                                                }
                                                if (match.hit && !pass)
                                                {
                                                    match = soulng::parser::Match(false);
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
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("EqualityExpression"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, expr.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("EqualityExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("EqualityExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::EqualityOperator(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("EqualityOperator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    int64_t pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case EQ:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("EqualityOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::equal));
                }
            }
            break;
        }
        case NEQ:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("EqualityOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::notEqual));
                }
            }
            break;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("EqualityOperator"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("EqualityOperator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::RelationalExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("RelationalExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> expr = std::unique_ptr<sngcpp::ast::Node>();
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> left;
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Operator>> op;
    std::unique_ptr<sngcpp::ast::Node> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = ExpressionParser::ShiftExpression(lexer, ctx);
                    left.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
                        s = span;
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
                            int64_t save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match = ExpressionParser::RelationalOperator(lexer);
                                        op.reset(static_cast<soulng::parser::Value<sngcpp::ast::Operator>*>(match.value));
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
                                                int64_t pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                bool pass = true;
                                                soulng::parser::Match match = ExpressionParser::ShiftExpression(lexer, ctx);
                                                right.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    if (ctx->ParsingTemplateIdOrLvalueAndNotArguments()) pass = false;
                                                    else
                                                    {
                                                        s.end = span.end;
                                                        expr.reset(new sngcpp::ast::RelationalExpressionNode(s, expr.release(), right.release(), op->value));
                                                    }
                                                }
                                                if (match.hit && !pass)
                                                {
                                                    match = soulng::parser::Match(false);
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
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("RelationalExpression"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, expr.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("RelationalExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("RelationalExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::RelationalOperator(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("RelationalOperator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    int64_t pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case LEQ:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("RelationalOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::lessOrEqual));
                }
            }
            break;
        }
        case GEQ:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("RelationalOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::greaterOrEqual));
                }
            }
            break;
        }
        case LANGLE:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("RelationalOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::less));
                }
            }
            break;
        }
        case RANGLE:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("RelationalOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::greater));
                }
            }
            break;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("RelationalOperator"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("RelationalOperator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::ShiftExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ShiftExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> expr = std::unique_ptr<sngcpp::ast::Node>();
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> left;
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Operator>> op;
    std::unique_ptr<sngcpp::ast::Node> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = ExpressionParser::AdditiveExpression(lexer, ctx);
                    left.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
                        s = span;
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
                            int64_t save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match = ExpressionParser::ShiftOperator(lexer);
                                        op.reset(static_cast<soulng::parser::Value<sngcpp::ast::Operator>*>(match.value));
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
                                                int64_t pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                bool pass = true;
                                                soulng::parser::Match match = ExpressionParser::AdditiveExpression(lexer, ctx);
                                                right.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    if (ctx->ParsingTemplateIdOrLvalueAndNotArguments()) pass = false;
                                                    else
                                                    {
                                                        s.end = span.end;
                                                        expr.reset(new sngcpp::ast::ShiftExpressionNode(s, expr.release(), right.release(), op->value));
                                                    }
                                                }
                                                if (match.hit && !pass)
                                                {
                                                    match = soulng::parser::Match(false);
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
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ShiftExpression"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, expr.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ShiftExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ShiftExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::ShiftOperator(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ShiftOperator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    int64_t pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case SHIFTLEFT:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ShiftOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::shiftLeft));
                }
            }
            break;
        }
        case SHIFTRIGHT:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ShiftOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::shiftRight));
                }
            }
            break;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ShiftOperator"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ShiftOperator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::AdditiveExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("AdditiveExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> expr = std::unique_ptr<sngcpp::ast::Node>();
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> left;
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Operator>> op;
    std::unique_ptr<sngcpp::ast::Node> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = ExpressionParser::MultiplicativeExpression(lexer, ctx);
                    left.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
                        s = span;
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
                            int64_t save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match = ExpressionParser::AdditiveOperator(lexer);
                                        op.reset(static_cast<soulng::parser::Value<sngcpp::ast::Operator>*>(match.value));
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
                                                int64_t pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                bool pass = true;
                                                soulng::parser::Match match = ExpressionParser::MultiplicativeExpression(lexer, ctx);
                                                right.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    if (ctx->ParsingLvalueAndNotArguments()) pass = false;
                                                    else
                                                    {
                                                        s.end = span.end;
                                                        expr.reset(new sngcpp::ast::AdditiveExpressionNode(s, expr.release(), right.release(), op->value));
                                                    }
                                                }
                                                if (match.hit && !pass)
                                                {
                                                    match = soulng::parser::Match(false);
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
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AdditiveExpression"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, expr.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AdditiveExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("AdditiveExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::AdditiveOperator(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("AdditiveOperator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    int64_t pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case PLUS:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AdditiveOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::add));
                }
            }
            break;
        }
        case MINUS:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AdditiveOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::sub));
                }
            }
            break;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AdditiveOperator"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("AdditiveOperator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::MultiplicativeExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("MultiplicativeExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> expr = std::unique_ptr<sngcpp::ast::Node>();
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> left;
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Operator>> op;
    std::unique_ptr<sngcpp::ast::Node> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = ExpressionParser::PMExpression(lexer, ctx);
                    left.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
                        s = span;
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
                            int64_t save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match = ExpressionParser::MultiplicativeOperator(lexer);
                                        op.reset(static_cast<soulng::parser::Value<sngcpp::ast::Operator>*>(match.value));
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
                                                int64_t pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                bool pass = true;
                                                soulng::parser::Match match = ExpressionParser::PMExpression(lexer, ctx);
                                                right.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    if (ctx->ParsingLvalueAndNotArguments()) pass = false;
                                                    else
                                                    {
                                                        s.end = span.end;
                                                        expr.reset(new sngcpp::ast::MultiplicativeExpressionNode(s, expr.release(), right.release(), op->value));
                                                    }
                                                }
                                                if (match.hit && !pass)
                                                {
                                                    match = soulng::parser::Match(false);
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
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MultiplicativeExpression"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, expr.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MultiplicativeExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("MultiplicativeExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::MultiplicativeOperator(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("MultiplicativeOperator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    int64_t pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case STAR:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MultiplicativeOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::mul));
                }
            }
            break;
        }
        case DIV:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MultiplicativeOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::div));
                }
            }
            break;
        }
        case MOD:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MultiplicativeOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::rem));
                }
            }
            break;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MultiplicativeOperator"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("MultiplicativeOperator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::PMExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("PMExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> expr = std::unique_ptr<sngcpp::ast::Node>();
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> left;
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Operator>> op;
    std::unique_ptr<sngcpp::ast::Node> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = ExpressionParser::CastExpression(lexer, ctx);
                    left.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(left.release());
                        s = span;
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
                            int64_t save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match = ExpressionParser::PMOperator(lexer);
                                        op.reset(static_cast<soulng::parser::Value<sngcpp::ast::Operator>*>(match.value));
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
                                                int64_t pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                soulng::parser::Match match = ExpressionParser::CastExpression(lexer, ctx);
                                                right.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    s.end = span.end;
                                                    expr.reset(new sngcpp::ast::PMExpressionNode(s, expr.release(), right.release(), op->value));
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
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("PMExpression"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, expr.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("PMExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("PMExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::PMOperator(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("PMOperator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    int64_t pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case DOTSTAR:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("PMOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::dotStar));
                }
            }
            break;
        }
        case ARROWSTAR:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("PMOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::arrowStar));
                }
            }
            break;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("PMOperator"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("PMOperator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::CastExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("CastExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> typeExpr;
    std::unique_ptr<sngcpp::ast::Node> castExpr;
    std::unique_ptr<sngcpp::ast::Node> unaryExpression;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t save = lexer.GetPos();
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
                        int64_t pos = lexer.GetPos();
                        soulng::lexer::Span span = lexer.GetSpan();
                        soulng::parser::Match match(false);
                        if (*lexer == LPAREN)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (match.hit)
                        {
                            s = span;
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
                        soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                        typeExpr.reset(static_cast<sngcpp::ast::Node*>(match.value));
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
                    if (*lexer == RPAREN)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch6 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch7 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch8 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = ExpressionParser::CastExpression(lexer, ctx);
                    castExpr.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        s.end = span.end;
                        {
                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("CastExpression"));
                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                            return soulng::parser::Match(true, new sngcpp::ast::CastExpressionNode(s, typeExpr.release(), castExpr.release()));
                        }
                    }
                    *parentMatch8 = match;
                }
                *parentMatch7 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch9 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch10 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::parser::Match match = ExpressionParser::UnaryExpression(lexer, ctx);
                    unaryExpression.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        {
                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("CastExpression"));
                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                            return soulng::parser::Match(true, unaryExpression.release());
                        }
                    }
                    *parentMatch10 = match;
                }
                *parentMatch9 = match;
            }
            *parentMatch0 = match;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("CastExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("CastExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::UnaryExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("UnaryExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> c1;
    std::unique_ptr<sngcpp::ast::Node> c2;
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Operator>> op;
    std::unique_ptr<sngcpp::ast::Node> c3;
    std::unique_ptr<sngcpp::ast::Node> u4;
    std::unique_ptr<sngcpp::ast::Node> t5;
    std::unique_ptr<sngcpp::ast::Node> newExpr;
    std::unique_ptr<sngcpp::ast::Node> deleteExpr;
    std::unique_ptr<sngcpp::ast::Node> postfixExpr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int64_t save = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int64_t save = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int64_t save = lexer.GetPos();
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int64_t save = lexer.GetPos();
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                int64_t save = lexer.GetPos();
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int64_t pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match(false);
                                        if (*lexer == PLUSPLUS)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            s = span;
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch9 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch10 = &match;
                                        {
                                            int64_t pos = lexer.GetPos();
                                            soulng::lexer::Span span = lexer.GetSpan();
                                            soulng::parser::Match match = ExpressionParser::CastExpression(lexer, ctx);
                                            c1.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                            if (match.hit)
                                            {
                                                s.end = span.end;
                                                {
                                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnaryExpression"));
                                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                    return soulng::parser::Match(true, new sngcpp::ast::UnaryExpressionNode(s, sngcpp::ast::Operator::inc, c1.release()));
                                                }
                                            }
                                            *parentMatch10 = match;
                                        }
                                        *parentMatch9 = match;
                                    }
                                    *parentMatch7 = match;
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
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch13 = &match;
                                            {
                                                int64_t pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                soulng::parser::Match match(false);
                                                if (*lexer == MINUSMINUS)
                                                {
                                                    ++lexer;
                                                    match.hit = true;
                                                }
                                                if (match.hit)
                                                {
                                                    s = span;
                                                }
                                                *parentMatch13 = match;
                                            }
                                            *parentMatch12 = match;
                                        }
                                        if (match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch14 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch15 = &match;
                                                {
                                                    int64_t pos = lexer.GetPos();
                                                    soulng::lexer::Span span = lexer.GetSpan();
                                                    soulng::parser::Match match = ExpressionParser::CastExpression(lexer, ctx);
                                                    c2.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        s.end = span.end;
                                                        {
                                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnaryExpression"));
                                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                            return soulng::parser::Match(true, new sngcpp::ast::UnaryExpressionNode(s, sngcpp::ast::Operator::dec, c2.release()));
                                                        }
                                                    }
                                                    *parentMatch15 = match;
                                                }
                                                *parentMatch14 = match;
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
                                soulng::parser::Match* parentMatch16 = &match;
                                lexer.SetPos(save);
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch17 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch18 = &match;
                                        {
                                            int64_t pos = lexer.GetPos();
                                            soulng::lexer::Span span = lexer.GetSpan();
                                            soulng::parser::Match match = ExpressionParser::UnaryOperator(lexer);
                                            op.reset(static_cast<soulng::parser::Value<sngcpp::ast::Operator>*>(match.value));
                                            if (match.hit)
                                            {
                                                s = span;
                                            }
                                            *parentMatch18 = match;
                                        }
                                        *parentMatch17 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch19 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch20 = &match;
                                            {
                                                int64_t pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                soulng::parser::Match match = ExpressionParser::CastExpression(lexer, ctx);
                                                c3.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    s.end = span.end;
                                                    {
                                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnaryExpression"));
                                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                        return soulng::parser::Match(true, new sngcpp::ast::UnaryExpressionNode(s, op->value, c3.release()));
                                                    }
                                                }
                                                *parentMatch20 = match;
                                            }
                                            *parentMatch19 = match;
                                        }
                                        *parentMatch17 = match;
                                    }
                                    *parentMatch16 = match;
                                }
                                *parentMatch5 = match;
                            }
                        }
                        *parentMatch4 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch21 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch22 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch23 = &match;
                                    {
                                        int64_t pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match(false);
                                        if (*lexer == SIZEOF)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            s = span;
                                        }
                                        *parentMatch23 = match;
                                    }
                                    *parentMatch22 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch24 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch25 = &match;
                                        {
                                            int64_t pos = lexer.GetPos();
                                            soulng::lexer::Span span = lexer.GetSpan();
                                            soulng::parser::Match match = ExpressionParser::UnaryExpression(lexer, ctx);
                                            u4.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                            if (match.hit)
                                            {
                                                s.end = span.end;
                                                {
                                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnaryExpression"));
                                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                    return soulng::parser::Match(true, new sngcpp::ast::UnaryExpressionNode(s, sngcpp::ast::Operator::sizeOf, u4.release()));
                                                }
                                            }
                                            *parentMatch25 = match;
                                        }
                                        *parentMatch24 = match;
                                    }
                                    *parentMatch22 = match;
                                }
                                *parentMatch21 = match;
                            }
                            *parentMatch4 = match;
                        }
                    }
                    *parentMatch3 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch26 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch27 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch28 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch29 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch30 = &match;
                                        {
                                            int64_t pos = lexer.GetPos();
                                            soulng::lexer::Span span = lexer.GetSpan();
                                            soulng::parser::Match match(false);
                                            if (*lexer == ALIGNOF)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            if (match.hit)
                                            {
                                                s = span;
                                            }
                                            *parentMatch30 = match;
                                        }
                                        *parentMatch29 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch31 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            if (*lexer == LPAREN)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            *parentMatch31 = match;
                                        }
                                        *parentMatch29 = match;
                                    }
                                    *parentMatch28 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch32 = &match;
                                    {
                                        soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                                        t5.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                        *parentMatch32 = match;
                                    }
                                    *parentMatch28 = match;
                                }
                                *parentMatch27 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch33 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch34 = &match;
                                    {
                                        int64_t pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match(false);
                                        if (*lexer == RPAREN)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            s.end = span.end;
                                            {
                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnaryExpression"));
                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                return soulng::parser::Match(true, new sngcpp::ast::UnaryExpressionNode(s, sngcpp::ast::Operator::alignOf, t5.release()));
                                            }
                                        }
                                        *parentMatch34 = match;
                                    }
                                    *parentMatch33 = match;
                                }
                                *parentMatch27 = match;
                            }
                            *parentMatch26 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch35 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch36 = &match;
                        {
                            int64_t pos = lexer.GetPos();
                            soulng::parser::Match match = ExpressionParser::NewExpression(lexer, ctx);
                            newExpr.reset(static_cast<sngcpp::ast::Node*>(match.value));
                            if (match.hit)
                            {
                                {
                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnaryExpression"));
                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                    return soulng::parser::Match(true, newExpr.release());
                                }
                            }
                            *parentMatch36 = match;
                        }
                        *parentMatch35 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch37 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch38 = &match;
                    {
                        int64_t pos = lexer.GetPos();
                        soulng::parser::Match match = ExpressionParser::DeleteExpression(lexer, ctx);
                        deleteExpr.reset(static_cast<sngcpp::ast::Node*>(match.value));
                        if (match.hit)
                        {
                            {
                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnaryExpression"));
                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                return soulng::parser::Match(true, deleteExpr.release());
                            }
                        }
                        *parentMatch38 = match;
                    }
                    *parentMatch37 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch39 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch40 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::parser::Match match = ExpressionParser::PostfixExpression(lexer, ctx);
                    postfixExpr.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        {
                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnaryExpression"));
                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                            return soulng::parser::Match(true, postfixExpr.release());
                        }
                    }
                    *parentMatch40 = match;
                }
                *parentMatch39 = match;
            }
            *parentMatch0 = match;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnaryExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("UnaryExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::UnaryOperator(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("UnaryOperator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    int64_t pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case STAR:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnaryOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::deref));
                }
            }
            break;
        }
        case AMP:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnaryOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::addrOf));
                }
            }
            break;
        }
        case PLUS:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnaryOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::unaryPlus));
                }
            }
            break;
        }
        case MINUS:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnaryOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::unaryMinus));
                }
            }
            break;
        }
        case EXCLAMATION:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnaryOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::not_));
                }
            }
            break;
        }
        case TILDE:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnaryOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::complement));
                }
            }
            break;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnaryOperator"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("UnaryOperator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::NewExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("NewExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> placement;
    std::unique_ptr<sngcpp::ast::Node> typeExpr;
    std::unique_ptr<sngcpp::ast::Node> initializer;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
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
                            int64_t pos = lexer.GetPos();
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match(false);
                            if (*lexer == NEW)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                s = span;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match(true);
                            int64_t save = lexer.GetPos();
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                soulng::parser::Match match = ExpressionParser::NewPlacement(lexer, ctx);
                                placement.reset(static_cast<sngcpp::ast::Node*>(match.value));
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
                            int64_t pos = lexer.GetPos();
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                            typeExpr.reset(static_cast<sngcpp::ast::Node*>(match.value));
                            if (match.hit)
                            {
                                s.end = span.end;
                            }
                            *parentMatch9 = match;
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
                soulng::parser::Match* parentMatch10 = &match;
                {
                    soulng::parser::Match match(true);
                    int64_t save = lexer.GetPos();
                    soulng::parser::Match* parentMatch11 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch12 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch13 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match = ExpressionParser::NewInitializer(lexer, ctx);
                                initializer.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                if (match.hit)
                                {
                                    s.end = span.end;
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
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("NewExpression"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new sngcpp::ast::NewExpressionNode(s, placement.release(), typeExpr.release(), initializer.release()));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("NewExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("NewExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::NewPlacement(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("NewPlacement"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> exprList;
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
                soulng::parser::Match match = ExpressionParser::ExpressionList(lexer, ctx);
                exprList.reset(static_cast<sngcpp::ast::Node*>(match.value));
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
            soulng::parser::Match* parentMatch4 = &match;
            {
                int64_t pos = lexer.GetPos();
                soulng::parser::Match match(false);
                if (*lexer == RPAREN)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    {
                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("NewPlacement"));
                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                        return soulng::parser::Match(true, exprList.release());
                    }
                }
                *parentMatch4 = match;
            }
            *parentMatch3 = match;
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("NewPlacement"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("NewPlacement"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::NewInitializer(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("NewInitializer"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> args;
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
                soulng::parser::Match match = ExpressionParser::ArgumentList(lexer, ctx);
                args.reset(static_cast<sngcpp::ast::Node*>(match.value));
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
            soulng::parser::Match* parentMatch4 = &match;
            {
                int64_t pos = lexer.GetPos();
                soulng::parser::Match match(false);
                if (*lexer == RPAREN)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    {
                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("NewInitializer"));
                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                        return soulng::parser::Match(true, args.release());
                    }
                }
                *parentMatch4 = match;
            }
            *parentMatch3 = match;
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("NewInitializer"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("NewInitializer"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::ExpressionList(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ExpressionList"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> initializerList;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match = DeclaratorParser::InitializerList(lexer, ctx);
        initializerList.reset(static_cast<sngcpp::ast::Node*>(match.value));
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ExpressionList"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, initializerList.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ExpressionList"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ExpressionList"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::ArgumentList(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ArgumentList"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> exprList;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int64_t pos = lexer.GetPos();
            soulng::parser::Match match = ExpressionParser::ExpressionList(lexer, ctx);
            exprList.reset(static_cast<sngcpp::ast::Node*>(match.value));
            if (match.hit)
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ArgumentList"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, exprList.release());
                }
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
                    int64_t pos = lexer.GetPos();
                    soulng::parser::Match match(true);
                    if (match.hit)
                    {
                        {
                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ArgumentList"));
                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                            return soulng::parser::Match(true, nullptr);
                        }
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch0 = match;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ArgumentList"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ArgumentList"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::DeleteExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("DeleteExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    bool array = bool();
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> castExpr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int64_t pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                if (*lexer == DELETE)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    s = span;
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
                int64_t save = lexer.GetPos();
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == LBRACKET)
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
                                soulng::parser::Match* parentMatch8 = &match;
                                {
                                    int64_t pos = lexer.GetPos();
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
                                    *parentMatch8 = match;
                                }
                                *parentMatch7 = match;
                            }
                            *parentMatch6 = match;
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
        soulng::parser::Match* parentMatch9 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch10 = &match;
            {
                int64_t pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ExpressionParser::CastExpression(lexer, ctx);
                castExpr.reset(static_cast<sngcpp::ast::Node*>(match.value));
                if (match.hit)
                {
                    s.end = span.end;
                    {
                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("DeleteExpression"));
                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                        return soulng::parser::Match(true, new sngcpp::ast::DeleteExpressionNode(s, array, castExpr.release()));
                    }
                }
                *parentMatch10 = match;
            }
            *parentMatch9 = match;
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("DeleteExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("DeleteExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::PostfixExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("PostfixExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> expr = std::unique_ptr<sngcpp::ast::Node>();
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> primaryExpr;
    std::unique_ptr<sngcpp::ast::Node> index;
    std::unique_ptr<sngcpp::ast::Node> args;
    std::unique_ptr<sngcpp::ast::Node> id1;
    std::unique_ptr<sngcpp::ast::Node> id2;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = ExpressionParser::PrimaryExpression(lexer, ctx);
                    primaryExpr.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(primaryExpr.release());
                        s = span;
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
                            int64_t save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        int64_t save = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            int64_t save = lexer.GetPos();
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch9 = &match;
                                            {
                                                int64_t save = lexer.GetPos();
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch10 = &match;
                                                {
                                                    int64_t save = lexer.GetPos();
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch11 = &match;
                                                    {
                                                        int64_t save = lexer.GetPos();
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch12 = &match;
                                                        {
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch13 = &match;
                                                            {
                                                                int64_t pos = lexer.GetPos();
                                                                soulng::parser::Match match(false);
                                                                if (*lexer == LBRACKET)
                                                                {
                                                                    ++lexer;
                                                                    match.hit = true;
                                                                }
                                                                if (match.hit)
                                                                {
                                                                    ctx->BeginParsingArguments();
                                                                }
                                                                *parentMatch13 = match;
                                                            }
                                                            *parentMatch12 = match;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch14 = &match;
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch15 = &match;
                                                                {
                                                                    int64_t pos = lexer.GetPos();
                                                                    soulng::lexer::Span span = lexer.GetSpan();
                                                                    soulng::parser::Match match(false);
                                                                    soulng::parser::Match* parentMatch16 = &match;
                                                                    {
                                                                        soulng::parser::Match match(false);
                                                                        soulng::parser::Match* parentMatch17 = &match;
                                                                        {
                                                                            soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                                                                            index.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                                            *parentMatch17 = match;
                                                                        }
                                                                        if (match.hit)
                                                                        {
                                                                            soulng::parser::Match match(false);
                                                                            soulng::parser::Match* parentMatch18 = &match;
                                                                            {
                                                                                soulng::parser::Match match(false);
                                                                                if (*lexer == RBRACKET)
                                                                                {
                                                                                    ++lexer;
                                                                                    match.hit = true;
                                                                                }
                                                                                *parentMatch18 = match;
                                                                            }
                                                                            *parentMatch17 = match;
                                                                        }
                                                                        *parentMatch16 = match;
                                                                    }
                                                                    if (match.hit)
                                                                    {
                                                                        s.end = span.end;
                                                                        ctx->EndParsingArguments();
                                                                        expr.reset(new sngcpp::ast::SubscriptExpressionNode(s, expr.release(), index.release()));
                                                                    }
                                                                    else
                                                                    {
                                                                        ctx->EndParsingArguments();
                                                                    }
                                                                    *parentMatch15 = match;
                                                                }
                                                                *parentMatch14 = match;
                                                            }
                                                            *parentMatch12 = match;
                                                        }
                                                        *parentMatch11 = match;
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
                                                                        int64_t pos = lexer.GetPos();
                                                                        soulng::parser::Match match(false);
                                                                        if (*lexer == LPAREN)
                                                                        {
                                                                            ++lexer;
                                                                            match.hit = true;
                                                                        }
                                                                        if (match.hit)
                                                                        {
                                                                            ctx->BeginParsingArguments();
                                                                        }
                                                                        *parentMatch21 = match;
                                                                    }
                                                                    *parentMatch20 = match;
                                                                }
                                                                if (match.hit)
                                                                {
                                                                    soulng::parser::Match match(false);
                                                                    soulng::parser::Match* parentMatch22 = &match;
                                                                    {
                                                                        soulng::parser::Match match(false);
                                                                        soulng::parser::Match* parentMatch23 = &match;
                                                                        {
                                                                            int64_t pos = lexer.GetPos();
                                                                            soulng::lexer::Span span = lexer.GetSpan();
                                                                            soulng::parser::Match match(false);
                                                                            soulng::parser::Match* parentMatch24 = &match;
                                                                            {
                                                                                soulng::parser::Match match(false);
                                                                                soulng::parser::Match* parentMatch25 = &match;
                                                                                {
                                                                                    soulng::parser::Match match = ExpressionParser::ArgumentList(lexer, ctx);
                                                                                    args.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                                                    *parentMatch25 = match;
                                                                                }
                                                                                if (match.hit)
                                                                                {
                                                                                    soulng::parser::Match match(false);
                                                                                    soulng::parser::Match* parentMatch26 = &match;
                                                                                    {
                                                                                        soulng::parser::Match match(false);
                                                                                        if (*lexer == RPAREN)
                                                                                        {
                                                                                            ++lexer;
                                                                                            match.hit = true;
                                                                                        }
                                                                                        *parentMatch26 = match;
                                                                                    }
                                                                                    *parentMatch25 = match;
                                                                                }
                                                                                *parentMatch24 = match;
                                                                            }
                                                                            if (match.hit)
                                                                            {
                                                                                s.end = span.end;
                                                                                ctx->EndParsingArguments();
                                                                                expr.reset(new sngcpp::ast::InvokeExpressionNode(s, expr.release(), args.release()));
                                                                            }
                                                                            else
                                                                            {
                                                                                ctx->EndParsingArguments();
                                                                            }
                                                                            *parentMatch23 = match;
                                                                        }
                                                                        *parentMatch22 = match;
                                                                    }
                                                                    *parentMatch20 = match;
                                                                }
                                                                *parentMatch19 = match;
                                                            }
                                                            *parentMatch11 = match;
                                                        }
                                                    }
                                                    *parentMatch10 = match;
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
                                                                        int64_t pos = lexer.GetPos();
                                                                        soulng::lexer::Span span = lexer.GetSpan();
                                                                        soulng::parser::Match match = ExpressionParser::IdExpression(lexer, ctx);
                                                                        id1.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                                        if (match.hit)
                                                                        {
                                                                            s.end = span.end;
                                                                            expr.reset(new sngcpp::ast::DotNode(s, expr.release(), id1.release()));
                                                                        }
                                                                        *parentMatch30 = match;
                                                                    }
                                                                    *parentMatch29 = match;
                                                                }
                                                                *parentMatch28 = match;
                                                            }
                                                            *parentMatch27 = match;
                                                        }
                                                        *parentMatch10 = match;
                                                    }
                                                }
                                                *parentMatch9 = match;
                                                if (!match.hit)
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch31 = &match;
                                                    lexer.SetPos(save);
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch32 = &match;
                                                        {
                                                            soulng::parser::Match match(false);
                                                            if (*lexer == ARROW)
                                                            {
                                                                ++lexer;
                                                                match.hit = true;
                                                            }
                                                            *parentMatch32 = match;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch33 = &match;
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch34 = &match;
                                                                {
                                                                    int64_t pos = lexer.GetPos();
                                                                    soulng::lexer::Span span = lexer.GetSpan();
                                                                    soulng::parser::Match match = ExpressionParser::IdExpression(lexer, ctx);
                                                                    id2.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                                    if (match.hit)
                                                                    {
                                                                        s.end = span.end;
                                                                        expr.reset(new sngcpp::ast::ArrowNode(s, expr.release(), id2.release()));
                                                                    }
                                                                    *parentMatch34 = match;
                                                                }
                                                                *parentMatch33 = match;
                                                            }
                                                            *parentMatch32 = match;
                                                        }
                                                        *parentMatch31 = match;
                                                    }
                                                    *parentMatch9 = match;
                                                }
                                            }
                                            *parentMatch8 = match;
                                            if (!match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch35 = &match;
                                                lexer.SetPos(save);
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch36 = &match;
                                                    {
                                                        int64_t pos = lexer.GetPos();
                                                        soulng::lexer::Span span = lexer.GetSpan();
                                                        soulng::parser::Match match(false);
                                                        if (*lexer == PLUSPLUS)
                                                        {
                                                            ++lexer;
                                                            match.hit = true;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            s.end = span.end;
                                                            expr.reset(new sngcpp::ast::PostfixIncNode(s, expr.release()));
                                                        }
                                                        *parentMatch36 = match;
                                                    }
                                                    *parentMatch35 = match;
                                                }
                                                *parentMatch8 = match;
                                            }
                                        }
                                        *parentMatch7 = match;
                                        if (!match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch37 = &match;
                                            lexer.SetPos(save);
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch38 = &match;
                                                {
                                                    int64_t pos = lexer.GetPos();
                                                    soulng::lexer::Span span = lexer.GetSpan();
                                                    soulng::parser::Match match(false);
                                                    if (*lexer == MINUSMINUS)
                                                    {
                                                        ++lexer;
                                                        match.hit = true;
                                                    }
                                                    if (match.hit)
                                                    {
                                                        s.end = span.end;
                                                        expr.reset(new sngcpp::ast::PostfixDecNode(s, expr.release()));
                                                    }
                                                    *parentMatch38 = match;
                                                }
                                                *parentMatch37 = match;
                                            }
                                            *parentMatch7 = match;
                                        }
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
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("PostfixExpression"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, expr.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("PostfixExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("PostfixExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::PrimaryExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("PrimaryExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> expr = std::unique_ptr<sngcpp::ast::Node>();
    Span s = Span();
    std::unique_ptr<sngcpp::ast::LiteralNode> literal;
    std::unique_ptr<sngcpp::ast::Node> e;
    std::unique_ptr<sngcpp::ast::Node> cppCastExpr;
    std::unique_ptr<sngcpp::ast::Node> typeIdExpr;
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>> s1;
    std::unique_ptr<sngcpp::ast::Node> args1;
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>> s2;
    std::unique_ptr<sngcpp::ast::Node> bracedInitializerList1;
    std::unique_ptr<sngcpp::ast::Node> t1;
    std::unique_ptr<sngcpp::ast::Node> args2;
    std::unique_ptr<sngcpp::ast::Node> t2;
    std::unique_ptr<sngcpp::ast::Node> bracedInitializerList2;
    std::unique_ptr<sngcpp::ast::Node> idExpr;
    std::unique_ptr<sngcpp::ast::Node> lambdaExpr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int64_t save = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int64_t save = lexer.GetPos();
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int64_t save = lexer.GetPos();
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                int64_t save = lexer.GetPos();
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    int64_t save = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int64_t save = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            int64_t save = lexer.GetPos();
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch10 = &match;
                                            {
                                                int64_t save = lexer.GetPos();
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch11 = &match;
                                                {
                                                    int64_t save = lexer.GetPos();
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch12 = &match;
                                                    {
                                                        int64_t pos = lexer.GetPos();
                                                        soulng::parser::Match match = LiteralParser::Literal(lexer);
                                                        literal.reset(static_cast<sngcpp::ast::LiteralNode*>(match.value));
                                                        if (match.hit)
                                                        {
                                                            expr.reset(literal.release());
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
                                                                int64_t pos = lexer.GetPos();
                                                                soulng::lexer::Span span = lexer.GetSpan();
                                                                soulng::parser::Match match(false);
                                                                if (*lexer == THIS)
                                                                {
                                                                    ++lexer;
                                                                    match.hit = true;
                                                                }
                                                                if (match.hit)
                                                                {
                                                                    expr.reset(new sngcpp::ast::ThisNode(span));
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
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch17 = &match;
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch18 = &match;
                                                                {
                                                                    int64_t pos = lexer.GetPos();
                                                                    soulng::lexer::Span span = lexer.GetSpan();
                                                                    soulng::parser::Match match(false);
                                                                    if (*lexer == LPAREN)
                                                                    {
                                                                        ++lexer;
                                                                        match.hit = true;
                                                                    }
                                                                    if (match.hit)
                                                                    {
                                                                        s = span;
                                                                    }
                                                                    *parentMatch18 = match;
                                                                }
                                                                *parentMatch17 = match;
                                                            }
                                                            if (match.hit)
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch19 = &match;
                                                                {
                                                                    soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                                                                    e.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                                    *parentMatch19 = match;
                                                                }
                                                                *parentMatch17 = match;
                                                            }
                                                            *parentMatch16 = match;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch20 = &match;
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch21 = &match;
                                                                {
                                                                    int64_t pos = lexer.GetPos();
                                                                    soulng::lexer::Span span = lexer.GetSpan();
                                                                    soulng::parser::Match match(false);
                                                                    if (*lexer == RPAREN)
                                                                    {
                                                                        ++lexer;
                                                                        match.hit = true;
                                                                    }
                                                                    if (match.hit)
                                                                    {
                                                                        s.end = span.end;
                                                                        expr.reset(new sngcpp::ast::ParenthesizedExprNode(s, e.release()));
                                                                    }
                                                                    *parentMatch21 = match;
                                                                }
                                                                *parentMatch20 = match;
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
                                                soulng::parser::Match* parentMatch22 = &match;
                                                lexer.SetPos(save);
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch23 = &match;
                                                    {
                                                        int64_t pos = lexer.GetPos();
                                                        soulng::parser::Match match = ExpressionParser::CppCastExpression(lexer, ctx);
                                                        cppCastExpr.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                        if (match.hit)
                                                        {
                                                            expr.reset(cppCastExpr.release());
                                                        }
                                                        *parentMatch23 = match;
                                                    }
                                                    *parentMatch22 = match;
                                                }
                                                *parentMatch9 = match;
                                            }
                                        }
                                        *parentMatch8 = match;
                                        if (!match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch24 = &match;
                                            lexer.SetPos(save);
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch25 = &match;
                                                {
                                                    int64_t pos = lexer.GetPos();
                                                    soulng::parser::Match match = ExpressionParser::TypeIdExpression(lexer, ctx);
                                                    typeIdExpr.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        expr.reset(typeIdExpr.release());
                                                    }
                                                    *parentMatch25 = match;
                                                }
                                                *parentMatch24 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                    }
                                    *parentMatch7 = match;
                                    if (!match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch26 = &match;
                                        lexer.SetPos(save);
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch27 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch28 = &match;
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch29 = &match;
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch30 = &match;
                                                        {
                                                            int64_t pos = lexer.GetPos();
                                                            soulng::lexer::Span span = lexer.GetSpan();
                                                            soulng::parser::Match match = SimpleTypeParser::SimpleTypeSpecifier(lexer);
                                                            s1.reset(static_cast<soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>*>(match.value));
                                                            if (match.hit)
                                                            {
                                                                s = span;
                                                            }
                                                            *parentMatch30 = match;
                                                        }
                                                        *parentMatch29 = match;
                                                    }
                                                    if (match.hit)
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch31 = &match;
                                                        {
                                                            soulng::parser::Match match(false);
                                                            if (*lexer == LPAREN)
                                                            {
                                                                ++lexer;
                                                                match.hit = true;
                                                            }
                                                            *parentMatch31 = match;
                                                        }
                                                        *parentMatch29 = match;
                                                    }
                                                    *parentMatch28 = match;
                                                }
                                                if (match.hit)
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch32 = &match;
                                                    {
                                                        soulng::parser::Match match = ExpressionParser::ArgumentList(lexer, ctx);
                                                        args1.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                        *parentMatch32 = match;
                                                    }
                                                    *parentMatch28 = match;
                                                }
                                                *parentMatch27 = match;
                                            }
                                            if (match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch33 = &match;
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch34 = &match;
                                                    {
                                                        int64_t pos = lexer.GetPos();
                                                        soulng::lexer::Span span = lexer.GetSpan();
                                                        soulng::parser::Match match(false);
                                                        if (*lexer == RPAREN)
                                                        {
                                                            ++lexer;
                                                            match.hit = true;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            s.end = span.end;
                                                            expr.reset(new sngcpp::ast::InvokeExpressionNode(s, new sngcpp::ast::SimpleTypeNode(s, std::vector < sngcpp::ast::SimpleTypeSpecifier > (1 , s1->value)), args1.release()));
                                                        }
                                                        *parentMatch34 = match;
                                                    }
                                                    *parentMatch33 = match;
                                                }
                                                *parentMatch27 = match;
                                            }
                                            *parentMatch26 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                }
                                *parentMatch6 = match;
                                if (!match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch35 = &match;
                                    lexer.SetPos(save);
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch36 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch37 = &match;
                                            {
                                                int64_t pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                soulng::parser::Match match = SimpleTypeParser::SimpleTypeSpecifier(lexer);
                                                s2.reset(static_cast<soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>*>(match.value));
                                                if (match.hit)
                                                {
                                                    s = span;
                                                }
                                                *parentMatch37 = match;
                                            }
                                            *parentMatch36 = match;
                                        }
                                        if (match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch38 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch39 = &match;
                                                {
                                                    int64_t pos = lexer.GetPos();
                                                    soulng::lexer::Span span = lexer.GetSpan();
                                                    soulng::parser::Match match = DeclaratorParser::BracedInitializerList(lexer, ctx);
                                                    bracedInitializerList1.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        s.end = span.end;
                                                        expr.reset(new sngcpp::ast::InvokeExpressionNode(s, new sngcpp::ast::SimpleTypeNode(s, std::vector < sngcpp::ast::SimpleTypeSpecifier > (1 , s2->value)), bracedInitializerList1.release()));
                                                    }
                                                    *parentMatch39 = match;
                                                }
                                                *parentMatch38 = match;
                                            }
                                            *parentMatch36 = match;
                                        }
                                        *parentMatch35 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                            }
                            *parentMatch5 = match;
                            if (!match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch40 = &match;
                                lexer.SetPos(save);
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch41 = &match;
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
                                                    int64_t pos = lexer.GetPos();
                                                    soulng::lexer::Span span = lexer.GetSpan();
                                                    soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                                                    t1.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        s = span;
                                                    }
                                                    *parentMatch44 = match;
                                                }
                                                *parentMatch43 = match;
                                            }
                                            if (match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch45 = &match;
                                                {
                                                    soulng::parser::Match match(false);
                                                    if (*lexer == LPAREN)
                                                    {
                                                        ++lexer;
                                                        match.hit = true;
                                                    }
                                                    *parentMatch45 = match;
                                                }
                                                *parentMatch43 = match;
                                            }
                                            *parentMatch42 = match;
                                        }
                                        if (match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch46 = &match;
                                            {
                                                soulng::parser::Match match = ExpressionParser::ArgumentList(lexer, ctx);
                                                args2.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                *parentMatch46 = match;
                                            }
                                            *parentMatch42 = match;
                                        }
                                        *parentMatch41 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch47 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch48 = &match;
                                            {
                                                int64_t pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                soulng::parser::Match match(false);
                                                if (*lexer == RPAREN)
                                                {
                                                    ++lexer;
                                                    match.hit = true;
                                                }
                                                if (match.hit)
                                                {
                                                    s.end = span.end;
                                                    expr.reset(new sngcpp::ast::InvokeExpressionNode(s, t1.release(), args2.release()));
                                                }
                                                *parentMatch48 = match;
                                            }
                                            *parentMatch47 = match;
                                        }
                                        *parentMatch41 = match;
                                    }
                                    *parentMatch40 = match;
                                }
                                *parentMatch5 = match;
                            }
                        }
                        *parentMatch4 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch49 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch50 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch51 = &match;
                                    {
                                        int64_t pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                                        t2.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                        if (match.hit)
                                        {
                                            s = span;
                                        }
                                        *parentMatch51 = match;
                                    }
                                    *parentMatch50 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch52 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch53 = &match;
                                        {
                                            int64_t pos = lexer.GetPos();
                                            soulng::lexer::Span span = lexer.GetSpan();
                                            soulng::parser::Match match = DeclaratorParser::BracedInitializerList(lexer, ctx);
                                            bracedInitializerList2.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                            if (match.hit)
                                            {
                                                s.end = span.end;
                                                expr.reset(new sngcpp::ast::InvokeExpressionNode(s, t2.release(), bracedInitializerList2.release()));
                                            }
                                            *parentMatch53 = match;
                                        }
                                        *parentMatch52 = match;
                                    }
                                    *parentMatch50 = match;
                                }
                                *parentMatch49 = match;
                            }
                            *parentMatch4 = match;
                        }
                    }
                    *parentMatch3 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch54 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch55 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::parser::Match match = ExpressionParser::IdExpression(lexer, ctx);
                                idExpr.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                if (match.hit)
                                {
                                    expr.reset(idExpr.release());
                                }
                                *parentMatch55 = match;
                            }
                            *parentMatch54 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch56 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch57 = &match;
                        {
                            int64_t pos = lexer.GetPos();
                            soulng::parser::Match match = ExpressionParser::LambdaExpression(lexer, ctx);
                            lambdaExpr.reset(static_cast<sngcpp::ast::Node*>(match.value));
                            if (match.hit)
                            {
                                {
                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("PrimaryExpression"));
                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                    return soulng::parser::Match(true, lambdaExpr.release());
                                }
                            }
                            *parentMatch57 = match;
                        }
                        *parentMatch56 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("PrimaryExpression"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, expr.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("PrimaryExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("PrimaryExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::CppCastExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("CppCastExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    sngcpp::ast::Operator op = sngcpp::ast::Operator();
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> typeExpr;
    std::unique_ptr<sngcpp::ast::Node> exprList;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
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
                                            int64_t save = lexer.GetPos();
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch10 = &match;
                                            {
                                                int64_t save = lexer.GetPos();
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch11 = &match;
                                                {
                                                    int64_t save = lexer.GetPos();
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch12 = &match;
                                                    {
                                                        int64_t pos = lexer.GetPos();
                                                        soulng::lexer::Span span = lexer.GetSpan();
                                                        soulng::parser::Match match(false);
                                                        if (*lexer == DYNAMIC_CAST)
                                                        {
                                                            ++lexer;
                                                            match.hit = true;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            s = span;
                                                            op = sngcpp::ast::Operator::dynamicCast;
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
                                                                int64_t pos = lexer.GetPos();
                                                                soulng::lexer::Span span = lexer.GetSpan();
                                                                soulng::parser::Match match(false);
                                                                if (*lexer == STATIC_CAST)
                                                                {
                                                                    ++lexer;
                                                                    match.hit = true;
                                                                }
                                                                if (match.hit)
                                                                {
                                                                    s = span;
                                                                    op = sngcpp::ast::Operator::staticCast;
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
                                                            int64_t pos = lexer.GetPos();
                                                            soulng::lexer::Span span = lexer.GetSpan();
                                                            soulng::parser::Match match(false);
                                                            if (*lexer == REINTERPRET_CAST)
                                                            {
                                                                ++lexer;
                                                                match.hit = true;
                                                            }
                                                            if (match.hit)
                                                            {
                                                                s = span;
                                                                op = sngcpp::ast::Operator::reinterpretCast;
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
                                                        int64_t pos = lexer.GetPos();
                                                        soulng::lexer::Span span = lexer.GetSpan();
                                                        soulng::parser::Match match(false);
                                                        if (*lexer == CONST_CAST)
                                                        {
                                                            ++lexer;
                                                            match.hit = true;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            s = span;
                                                            op = sngcpp::ast::Operator::constCast;
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
                                        soulng::parser::Match match(false);
                                        if (*lexer == LANGLE)
                                        {
                                            ++lexer;
                                            match.hit = true;
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
                                soulng::parser::Match* parentMatch20 = &match;
                                {
                                    soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                                    typeExpr.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                    *parentMatch20 = match;
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
                                if (*lexer == RANGLE)
                                {
                                    ++lexer;
                                    match.hit = true;
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
                        soulng::parser::Match* parentMatch22 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == LPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch22 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch23 = &match;
                    {
                        soulng::parser::Match match = ExpressionParser::ExpressionList(lexer, ctx);
                        exprList.reset(static_cast<sngcpp::ast::Node*>(match.value));
                        *parentMatch23 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch24 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch25 = &match;
                    {
                        int64_t pos = lexer.GetPos();
                        soulng::lexer::Span span = lexer.GetSpan();
                        soulng::parser::Match match(false);
                        if (*lexer == RPAREN)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (match.hit)
                        {
                            s.end = span.end;
                        }
                        *parentMatch25 = match;
                    }
                    *parentMatch24 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("CppCastExpression"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new sngcpp::ast::CppCastExpressionNode(s, typeExpr.release(), exprList.release(), op));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("CppCastExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("CppCastExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::TypeIdExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("TypeIdExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> typeExpr;
    std::unique_ptr<sngcpp::ast::Node> expr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t save = lexer.GetPos();
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
                        int64_t pos = lexer.GetPos();
                        soulng::lexer::Span span = lexer.GetSpan();
                        soulng::parser::Match match(false);
                        if (*lexer == TYPEID)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (match.hit)
                        {
                            s = span;
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
                        if (*lexer == LPAREN)
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
                    soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                    typeExpr.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    *parentMatch6 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch7 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch8 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match(false);
                    if (*lexer == RPAREN)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        s.end = span.end;
                        {
                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("TypeIdExpression"));
                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                            return soulng::parser::Match(true, new sngcpp::ast::TypeIdExpressionNode(s, typeExpr.release()));
                        }
                    }
                    *parentMatch8 = match;
                }
                *parentMatch7 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch9 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch10 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch11 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch12 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch13 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match(false);
                                if (*lexer == TYPEID)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    s = span;
                                }
                                *parentMatch13 = match;
                            }
                            *parentMatch12 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch14 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == LPAREN)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch14 = match;
                            }
                            *parentMatch12 = match;
                        }
                        *parentMatch11 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch15 = &match;
                        {
                            soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                            expr.reset(static_cast<sngcpp::ast::Node*>(match.value));
                            *parentMatch15 = match;
                        }
                        *parentMatch11 = match;
                    }
                    *parentMatch10 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch16 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch17 = &match;
                        {
                            int64_t pos = lexer.GetPos();
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match(false);
                            if (*lexer == RPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                s.end = span.end;
                                {
                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("TypeIdExpression"));
                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                    return soulng::parser::Match(true, new sngcpp::ast::TypeIdExpressionNode(s, expr.release()));
                                }
                            }
                            *parentMatch17 = match;
                        }
                        *parentMatch16 = match;
                    }
                    *parentMatch10 = match;
                }
                *parentMatch9 = match;
            }
            *parentMatch0 = match;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("TypeIdExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("TypeIdExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::IdExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("IdExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> qualifiedId;
    std::unique_ptr<sngcpp::ast::Node> unqualifiedId;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int64_t pos = lexer.GetPos();
            soulng::parser::Match match = ExpressionParser::QualifiedId(lexer, ctx);
            qualifiedId.reset(static_cast<sngcpp::ast::Node*>(match.value));
            if (match.hit)
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("IdExpression"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, qualifiedId.release());
                }
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
                    int64_t pos = lexer.GetPos();
                    soulng::parser::Match match = ExpressionParser::UnqualifiedId(lexer, ctx);
                    unqualifiedId.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        {
                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("IdExpression"));
                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                            return soulng::parser::Match(true, unqualifiedId.release());
                        }
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch0 = match;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("IdExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("IdExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::UnqualifiedId(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("UnqualifiedId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> templateId;
    std::unique_ptr<soulng::parser::Value<std::u32string>> id1;
    std::unique_ptr<sngcpp::ast::Node> operatorFunctionId;
    std::unique_ptr<sngcpp::ast::Node> conversionFunctionId;
    std::unique_ptr<soulng::parser::Value<std::u32string>> id2;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int64_t save = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int64_t save = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int64_t pos = lexer.GetPos();
                        soulng::parser::Match match = TemplateParser::TemplateId(lexer, ctx);
                        templateId.reset(static_cast<sngcpp::ast::Node*>(match.value));
                        if (match.hit)
                        {
                            {
                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnqualifiedId"));
                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                return soulng::parser::Match(true, templateId.release());
                            }
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                id1.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                                if (match.hit)
                                {
                                    {
                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnqualifiedId"));
                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                        return soulng::parser::Match(true, new sngcpp::ast::IdentifierNode(span, id1->value));
                                    }
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch7 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch8 = &match;
                        {
                            int64_t pos = lexer.GetPos();
                            soulng::parser::Match match = ExpressionParser::OperatorFunctionId(lexer);
                            operatorFunctionId.reset(static_cast<sngcpp::ast::Node*>(match.value));
                            if (match.hit)
                            {
                                {
                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnqualifiedId"));
                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                    return soulng::parser::Match(true, operatorFunctionId.release());
                                }
                            }
                            *parentMatch8 = match;
                        }
                        *parentMatch7 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch9 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch10 = &match;
                    {
                        int64_t pos = lexer.GetPos();
                        soulng::parser::Match match = ExpressionParser::ConversionFunctionId(lexer, ctx);
                        conversionFunctionId.reset(static_cast<sngcpp::ast::Node*>(match.value));
                        if (match.hit)
                        {
                            {
                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnqualifiedId"));
                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                return soulng::parser::Match(true, conversionFunctionId.release());
                            }
                        }
                        *parentMatch10 = match;
                    }
                    *parentMatch9 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch11 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch12 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch13 = &match;
                    {
                        int64_t pos = lexer.GetPos();
                        soulng::lexer::Span span = lexer.GetSpan();
                        soulng::parser::Match match(false);
                        if (*lexer == TILDE)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (match.hit)
                        {
                            s = span;
                        }
                        *parentMatch13 = match;
                    }
                    *parentMatch12 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch14 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch15 = &match;
                        {
                            int64_t pos = lexer.GetPos();
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                            id2.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                            if (match.hit)
                            {
                                s.end = span.end;
                                {
                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnqualifiedId"));
                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                    return soulng::parser::Match(true, new sngcpp::ast::DtorIdNode(s, id2->value));
                                }
                            }
                            *parentMatch15 = match;
                        }
                        *parentMatch14 = match;
                    }
                    *parentMatch12 = match;
                }
                *parentMatch11 = match;
            }
            *parentMatch0 = match;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnqualifiedId"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("UnqualifiedId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::QualifiedId(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("QualifiedId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> templateId;
    std::unique_ptr<sngcpp::ast::Node> ns1;
    std::unique_ptr<sngcpp::ast::Node> uid1;
    std::unique_ptr<soulng::parser::Value<std::u32string>> id1;
    std::unique_ptr<sngcpp::ast::Node> operatorFunctionId;
    std::unique_ptr<sngcpp::ast::Node> ns2;
    std::unique_ptr<sngcpp::ast::Node> uid2;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int64_t save = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int64_t save = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int64_t pos = lexer.GetPos();
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match(false);
                            if (*lexer == COLONCOLON)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                s = span;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match = TemplateParser::TemplateId(lexer, ctx);
                                templateId.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                if (match.hit)
                                {
                                    s.end = span.end;
                                    {
                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("QualifiedId"));
                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                        return soulng::parser::Match(true, new sngcpp::ast::NestedIdNode(s, nullptr, templateId.release()));
                                    }
                                }
                                *parentMatch7 = match;
                            }
                            *parentMatch6 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
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
                                        int64_t pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match(false);
                                        if (*lexer == COLONCOLON)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            s = span;
                                        }
                                        *parentMatch11 = match;
                                    }
                                    *parentMatch10 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch12 = &match;
                                    {
                                        soulng::parser::Match match = IdentifierParser::NestedNameSpecifier(lexer, ctx);
                                        ns1.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                        *parentMatch12 = match;
                                    }
                                    *parentMatch10 = match;
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
                                        int64_t pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match = ExpressionParser::UnqualifiedId(lexer, ctx);
                                        uid1.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                        if (match.hit)
                                        {
                                            s.end = span.end;
                                            {
                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("QualifiedId"));
                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                return soulng::parser::Match(true, new sngcpp::ast::NestedIdNode(s, new sngcpp::ast::NestedIdNode(s, nullptr, ns1.release()), uid1.release()));
                                            }
                                        }
                                        *parentMatch14 = match;
                                    }
                                    *parentMatch13 = match;
                                }
                                *parentMatch9 = match;
                            }
                            *parentMatch8 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch15 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch16 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch17 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match(false);
                                if (*lexer == COLONCOLON)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    s = span;
                                }
                                *parentMatch17 = match;
                            }
                            *parentMatch16 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch18 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch19 = &match;
                                {
                                    int64_t pos = lexer.GetPos();
                                    soulng::lexer::Span span = lexer.GetSpan();
                                    soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                    id1.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                                    if (match.hit)
                                    {
                                        s.end = span.end;
                                        {
                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("QualifiedId"));
                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                            return soulng::parser::Match(true, new sngcpp::ast::NestedIdNode(s, nullptr, new sngcpp::ast::IdentifierNode(s, id1->value)));
                                        }
                                    }
                                    *parentMatch19 = match;
                                }
                                *parentMatch18 = match;
                            }
                            *parentMatch16 = match;
                        }
                        *parentMatch15 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch20 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch21 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch22 = &match;
                        {
                            int64_t pos = lexer.GetPos();
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match(false);
                            if (*lexer == COLONCOLON)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                s = span;
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
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch24 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match = ExpressionParser::OperatorFunctionId(lexer);
                                operatorFunctionId.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                if (match.hit)
                                {
                                    s.end = span.end;
                                    {
                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("QualifiedId"));
                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                        return soulng::parser::Match(true, new sngcpp::ast::NestedIdNode(s, nullptr, operatorFunctionId.release()));
                                    }
                                }
                                *parentMatch24 = match;
                            }
                            *parentMatch23 = match;
                        }
                        *parentMatch21 = match;
                    }
                    *parentMatch20 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
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
                        int64_t pos = lexer.GetPos();
                        soulng::lexer::Span span = lexer.GetSpan();
                        soulng::parser::Match match = IdentifierParser::NestedNameSpecifier(lexer, ctx);
                        ns2.reset(static_cast<sngcpp::ast::Node*>(match.value));
                        if (match.hit)
                        {
                            s = span;
                        }
                        *parentMatch27 = match;
                    }
                    *parentMatch26 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch28 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch29 = &match;
                        {
                            int64_t pos = lexer.GetPos();
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match = ExpressionParser::UnqualifiedId(lexer, ctx);
                            uid2.reset(static_cast<sngcpp::ast::Node*>(match.value));
                            if (match.hit)
                            {
                                s.end = span.end;
                                {
                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("QualifiedId"));
                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                    return soulng::parser::Match(true, new sngcpp::ast::NestedIdNode(s, ns2.release(), uid2.release()));
                                }
                            }
                            *parentMatch29 = match;
                        }
                        *parentMatch28 = match;
                    }
                    *parentMatch26 = match;
                }
                *parentMatch25 = match;
            }
            *parentMatch0 = match;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("QualifiedId"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("QualifiedId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::OperatorFunctionId(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("OperatorFunctionId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    Span s = Span();
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Operator>> op;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int64_t pos = lexer.GetPos();
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
                int64_t pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ExpressionParser::Operator(lexer);
                op.reset(static_cast<soulng::parser::Value<sngcpp::ast::Operator>*>(match.value));
                if (match.hit)
                {
                    s.end = span.end;
                    {
                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("OperatorFunctionId"));
                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                        return soulng::parser::Match(true, new sngcpp::ast::OperatorFunctionIdNode(s, op->value));
                    }
                }
                *parentMatch3 = match;
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("OperatorFunctionId"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("OperatorFunctionId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::Operator(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("Operator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Operator>> assignmentOp;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int64_t save = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int64_t save = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int64_t save = lexer.GetPos();
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int64_t save = lexer.GetPos();
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                int64_t save = lexer.GetPos();
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    int64_t save = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int64_t save = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            int64_t save = lexer.GetPos();
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch10 = &match;
                                            {
                                                int64_t save = lexer.GetPos();
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch11 = &match;
                                                {
                                                    int64_t save = lexer.GetPos();
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch12 = &match;
                                                    {
                                                        int64_t save = lexer.GetPos();
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch13 = &match;
                                                        {
                                                            int64_t save = lexer.GetPos();
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch14 = &match;
                                                            {
                                                                int64_t save = lexer.GetPos();
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch15 = &match;
                                                                {
                                                                    int64_t save = lexer.GetPos();
                                                                    soulng::parser::Match match(false);
                                                                    soulng::parser::Match* parentMatch16 = &match;
                                                                    {
                                                                        int64_t save = lexer.GetPos();
                                                                        soulng::parser::Match match(false);
                                                                        soulng::parser::Match* parentMatch17 = &match;
                                                                        {
                                                                            int64_t save = lexer.GetPos();
                                                                            soulng::parser::Match match(false);
                                                                            soulng::parser::Match* parentMatch18 = &match;
                                                                            {
                                                                                int64_t save = lexer.GetPos();
                                                                                soulng::parser::Match match(false);
                                                                                soulng::parser::Match* parentMatch19 = &match;
                                                                                {
                                                                                    int64_t save = lexer.GetPos();
                                                                                    soulng::parser::Match match(false);
                                                                                    soulng::parser::Match* parentMatch20 = &match;
                                                                                    {
                                                                                        int64_t save = lexer.GetPos();
                                                                                        soulng::parser::Match match(false);
                                                                                        soulng::parser::Match* parentMatch21 = &match;
                                                                                        {
                                                                                            int64_t save = lexer.GetPos();
                                                                                            soulng::parser::Match match(false);
                                                                                            soulng::parser::Match* parentMatch22 = &match;
                                                                                            {
                                                                                                int64_t save = lexer.GetPos();
                                                                                                soulng::parser::Match match(false);
                                                                                                soulng::parser::Match* parentMatch23 = &match;
                                                                                                {
                                                                                                    int64_t save = lexer.GetPos();
                                                                                                    soulng::parser::Match match(false);
                                                                                                    soulng::parser::Match* parentMatch24 = &match;
                                                                                                    {
                                                                                                        int64_t save = lexer.GetPos();
                                                                                                        soulng::parser::Match match(false);
                                                                                                        soulng::parser::Match* parentMatch25 = &match;
                                                                                                        {
                                                                                                            int64_t save = lexer.GetPos();
                                                                                                            soulng::parser::Match match(false);
                                                                                                            soulng::parser::Match* parentMatch26 = &match;
                                                                                                            {
                                                                                                                int64_t save = lexer.GetPos();
                                                                                                                soulng::parser::Match match(false);
                                                                                                                soulng::parser::Match* parentMatch27 = &match;
                                                                                                                {
                                                                                                                    int64_t save = lexer.GetPos();
                                                                                                                    soulng::parser::Match match(false);
                                                                                                                    soulng::parser::Match* parentMatch28 = &match;
                                                                                                                    {
                                                                                                                        int64_t save = lexer.GetPos();
                                                                                                                        soulng::parser::Match match(false);
                                                                                                                        soulng::parser::Match* parentMatch29 = &match;
                                                                                                                        {
                                                                                                                            int64_t save = lexer.GetPos();
                                                                                                                            soulng::parser::Match match(false);
                                                                                                                            soulng::parser::Match* parentMatch30 = &match;
                                                                                                                            {
                                                                                                                                int64_t save = lexer.GetPos();
                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                soulng::parser::Match* parentMatch31 = &match;
                                                                                                                                {
                                                                                                                                    int64_t save = lexer.GetPos();
                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                    soulng::parser::Match* parentMatch32 = &match;
                                                                                                                                    {
                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                        soulng::parser::Match* parentMatch33 = &match;
                                                                                                                                        {
                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                            if (*lexer == NEW)
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
                                                                                                                                                if (*lexer == LBRACKET)
                                                                                                                                                {
                                                                                                                                                    ++lexer;
                                                                                                                                                    match.hit = true;
                                                                                                                                                }
                                                                                                                                                *parentMatch34 = match;
                                                                                                                                            }
                                                                                                                                            *parentMatch33 = match;
                                                                                                                                        }
                                                                                                                                        *parentMatch32 = match;
                                                                                                                                    }
                                                                                                                                    if (match.hit)
                                                                                                                                    {
                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                        soulng::parser::Match* parentMatch35 = &match;
                                                                                                                                        {
                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                            soulng::parser::Match* parentMatch36 = &match;
                                                                                                                                            {
                                                                                                                                                int64_t pos = lexer.GetPos();
                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                if (*lexer == RBRACKET)
                                                                                                                                                {
                                                                                                                                                    ++lexer;
                                                                                                                                                    match.hit = true;
                                                                                                                                                }
                                                                                                                                                if (match.hit)
                                                                                                                                                {
                                                                                                                                                    {
                                                                                                                                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                        return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::newArray));
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                                *parentMatch36 = match;
                                                                                                                                            }
                                                                                                                                            *parentMatch35 = match;
                                                                                                                                        }
                                                                                                                                        *parentMatch32 = match;
                                                                                                                                    }
                                                                                                                                    *parentMatch31 = match;
                                                                                                                                    if (!match.hit)
                                                                                                                                    {
                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                        soulng::parser::Match* parentMatch37 = &match;
                                                                                                                                        lexer.SetPos(save);
                                                                                                                                        {
                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                            soulng::parser::Match* parentMatch38 = &match;
                                                                                                                                            {
                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                soulng::parser::Match* parentMatch39 = &match;
                                                                                                                                                {
                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                    if (*lexer == DELETE)
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
                                                                                                                                                        if (*lexer == LBRACKET)
                                                                                                                                                        {
                                                                                                                                                            ++lexer;
                                                                                                                                                            match.hit = true;
                                                                                                                                                        }
                                                                                                                                                        *parentMatch40 = match;
                                                                                                                                                    }
                                                                                                                                                    *parentMatch39 = match;
                                                                                                                                                }
                                                                                                                                                *parentMatch38 = match;
                                                                                                                                            }
                                                                                                                                            if (match.hit)
                                                                                                                                            {
                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                soulng::parser::Match* parentMatch41 = &match;
                                                                                                                                                {
                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                    soulng::parser::Match* parentMatch42 = &match;
                                                                                                                                                    {
                                                                                                                                                        int64_t pos = lexer.GetPos();
                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                        if (*lexer == RBRACKET)
                                                                                                                                                        {
                                                                                                                                                            ++lexer;
                                                                                                                                                            match.hit = true;
                                                                                                                                                        }
                                                                                                                                                        if (match.hit)
                                                                                                                                                        {
                                                                                                                                                            {
                                                                                                                                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::deleteArray));
                                                                                                                                                            }
                                                                                                                                                        }
                                                                                                                                                        *parentMatch42 = match;
                                                                                                                                                    }
                                                                                                                                                    *parentMatch41 = match;
                                                                                                                                                }
                                                                                                                                                *parentMatch38 = match;
                                                                                                                                            }
                                                                                                                                            *parentMatch37 = match;
                                                                                                                                        }
                                                                                                                                        *parentMatch31 = match;
                                                                                                                                    }
                                                                                                                                }
                                                                                                                                *parentMatch30 = match;
                                                                                                                                if (!match.hit)
                                                                                                                                {
                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                    soulng::parser::Match* parentMatch43 = &match;
                                                                                                                                    lexer.SetPos(save);
                                                                                                                                    {
                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                        soulng::parser::Match* parentMatch44 = &match;
                                                                                                                                        {
                                                                                                                                            int64_t pos = lexer.GetPos();
                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                            if (*lexer == NEW)
                                                                                                                                            {
                                                                                                                                                ++lexer;
                                                                                                                                                match.hit = true;
                                                                                                                                            }
                                                                                                                                            if (match.hit)
                                                                                                                                            {
                                                                                                                                                {
                                                                                                                                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::new_));
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                            *parentMatch44 = match;
                                                                                                                                        }
                                                                                                                                        *parentMatch43 = match;
                                                                                                                                    }
                                                                                                                                    *parentMatch30 = match;
                                                                                                                                }
                                                                                                                            }
                                                                                                                            *parentMatch29 = match;
                                                                                                                            if (!match.hit)
                                                                                                                            {
                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                soulng::parser::Match* parentMatch45 = &match;
                                                                                                                                lexer.SetPos(save);
                                                                                                                                {
                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                    soulng::parser::Match* parentMatch46 = &match;
                                                                                                                                    {
                                                                                                                                        int64_t pos = lexer.GetPos();
                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                        if (*lexer == DELETE)
                                                                                                                                        {
                                                                                                                                            ++lexer;
                                                                                                                                            match.hit = true;
                                                                                                                                        }
                                                                                                                                        if (match.hit)
                                                                                                                                        {
                                                                                                                                            {
                                                                                                                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::delete_));
                                                                                                                                            }
                                                                                                                                        }
                                                                                                                                        *parentMatch46 = match;
                                                                                                                                    }
                                                                                                                                    *parentMatch45 = match;
                                                                                                                                }
                                                                                                                                *parentMatch29 = match;
                                                                                                                            }
                                                                                                                        }
                                                                                                                        *parentMatch28 = match;
                                                                                                                        if (!match.hit)
                                                                                                                        {
                                                                                                                            soulng::parser::Match match(false);
                                                                                                                            soulng::parser::Match* parentMatch47 = &match;
                                                                                                                            lexer.SetPos(save);
                                                                                                                            {
                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                soulng::parser::Match* parentMatch48 = &match;
                                                                                                                                {
                                                                                                                                    int64_t pos = lexer.GetPos();
                                                                                                                                    soulng::parser::Match match = ExpressionParser::AssignmentOperator(lexer);
                                                                                                                                    assignmentOp.reset(static_cast<soulng::parser::Value<sngcpp::ast::Operator>*>(match.value));
                                                                                                                                    if (match.hit)
                                                                                                                                    {
                                                                                                                                        {
                                                                                                                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                            return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(assignmentOp->value));
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                    *parentMatch48 = match;
                                                                                                                                }
                                                                                                                                *parentMatch47 = match;
                                                                                                                            }
                                                                                                                            *parentMatch28 = match;
                                                                                                                        }
                                                                                                                    }
                                                                                                                    *parentMatch27 = match;
                                                                                                                    if (!match.hit)
                                                                                                                    {
                                                                                                                        soulng::parser::Match match(false);
                                                                                                                        soulng::parser::Match* parentMatch49 = &match;
                                                                                                                        lexer.SetPos(save);
                                                                                                                        {
                                                                                                                            soulng::parser::Match match(false);
                                                                                                                            soulng::parser::Match* parentMatch50 = &match;
                                                                                                                            {
                                                                                                                                int64_t pos = lexer.GetPos();
                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                if (*lexer == PLUSPLUS)
                                                                                                                                {
                                                                                                                                    ++lexer;
                                                                                                                                    match.hit = true;
                                                                                                                                }
                                                                                                                                if (match.hit)
                                                                                                                                {
                                                                                                                                    {
                                                                                                                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                        return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::inc));
                                                                                                                                    }
                                                                                                                                }
                                                                                                                                *parentMatch50 = match;
                                                                                                                            }
                                                                                                                            *parentMatch49 = match;
                                                                                                                        }
                                                                                                                        *parentMatch27 = match;
                                                                                                                    }
                                                                                                                }
                                                                                                                *parentMatch26 = match;
                                                                                                                if (!match.hit)
                                                                                                                {
                                                                                                                    soulng::parser::Match match(false);
                                                                                                                    soulng::parser::Match* parentMatch51 = &match;
                                                                                                                    lexer.SetPos(save);
                                                                                                                    {
                                                                                                                        soulng::parser::Match match(false);
                                                                                                                        soulng::parser::Match* parentMatch52 = &match;
                                                                                                                        {
                                                                                                                            int64_t pos = lexer.GetPos();
                                                                                                                            soulng::parser::Match match(false);
                                                                                                                            if (*lexer == MINUSMINUS)
                                                                                                                            {
                                                                                                                                ++lexer;
                                                                                                                                match.hit = true;
                                                                                                                            }
                                                                                                                            if (match.hit)
                                                                                                                            {
                                                                                                                                {
                                                                                                                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::dec));
                                                                                                                                }
                                                                                                                            }
                                                                                                                            *parentMatch52 = match;
                                                                                                                        }
                                                                                                                        *parentMatch51 = match;
                                                                                                                    }
                                                                                                                    *parentMatch26 = match;
                                                                                                                }
                                                                                                            }
                                                                                                            *parentMatch25 = match;
                                                                                                            if (!match.hit)
                                                                                                            {
                                                                                                                soulng::parser::Match match(false);
                                                                                                                soulng::parser::Match* parentMatch53 = &match;
                                                                                                                lexer.SetPos(save);
                                                                                                                {
                                                                                                                    soulng::parser::Match match(false);
                                                                                                                    soulng::parser::Match* parentMatch54 = &match;
                                                                                                                    {
                                                                                                                        int64_t pos = lexer.GetPos();
                                                                                                                        soulng::parser::Match match(false);
                                                                                                                        if (*lexer == SHIFTLEFT)
                                                                                                                        {
                                                                                                                            ++lexer;
                                                                                                                            match.hit = true;
                                                                                                                        }
                                                                                                                        if (match.hit)
                                                                                                                        {
                                                                                                                            {
                                                                                                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::shiftLeft));
                                                                                                                            }
                                                                                                                        }
                                                                                                                        *parentMatch54 = match;
                                                                                                                    }
                                                                                                                    *parentMatch53 = match;
                                                                                                                }
                                                                                                                *parentMatch25 = match;
                                                                                                            }
                                                                                                        }
                                                                                                        *parentMatch24 = match;
                                                                                                        if (!match.hit)
                                                                                                        {
                                                                                                            soulng::parser::Match match(false);
                                                                                                            soulng::parser::Match* parentMatch55 = &match;
                                                                                                            lexer.SetPos(save);
                                                                                                            {
                                                                                                                soulng::parser::Match match(false);
                                                                                                                soulng::parser::Match* parentMatch56 = &match;
                                                                                                                {
                                                                                                                    int64_t pos = lexer.GetPos();
                                                                                                                    soulng::parser::Match match(false);
                                                                                                                    if (*lexer == SHIFTRIGHT)
                                                                                                                    {
                                                                                                                        ++lexer;
                                                                                                                        match.hit = true;
                                                                                                                    }
                                                                                                                    if (match.hit)
                                                                                                                    {
                                                                                                                        {
                                                                                                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                            return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::shiftRight));
                                                                                                                        }
                                                                                                                    }
                                                                                                                    *parentMatch56 = match;
                                                                                                                }
                                                                                                                *parentMatch55 = match;
                                                                                                            }
                                                                                                            *parentMatch24 = match;
                                                                                                        }
                                                                                                    }
                                                                                                    *parentMatch23 = match;
                                                                                                    if (!match.hit)
                                                                                                    {
                                                                                                        soulng::parser::Match match(false);
                                                                                                        soulng::parser::Match* parentMatch57 = &match;
                                                                                                        lexer.SetPos(save);
                                                                                                        {
                                                                                                            soulng::parser::Match match(false);
                                                                                                            soulng::parser::Match* parentMatch58 = &match;
                                                                                                            {
                                                                                                                int64_t pos = lexer.GetPos();
                                                                                                                soulng::parser::Match match(false);
                                                                                                                if (*lexer == AMPAMP)
                                                                                                                {
                                                                                                                    ++lexer;
                                                                                                                    match.hit = true;
                                                                                                                }
                                                                                                                if (match.hit)
                                                                                                                {
                                                                                                                    {
                                                                                                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                        return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::logicalAnd));
                                                                                                                    }
                                                                                                                }
                                                                                                                *parentMatch58 = match;
                                                                                                            }
                                                                                                            *parentMatch57 = match;
                                                                                                        }
                                                                                                        *parentMatch23 = match;
                                                                                                    }
                                                                                                }
                                                                                                *parentMatch22 = match;
                                                                                                if (!match.hit)
                                                                                                {
                                                                                                    soulng::parser::Match match(false);
                                                                                                    soulng::parser::Match* parentMatch59 = &match;
                                                                                                    lexer.SetPos(save);
                                                                                                    {
                                                                                                        soulng::parser::Match match(false);
                                                                                                        soulng::parser::Match* parentMatch60 = &match;
                                                                                                        {
                                                                                                            int64_t pos = lexer.GetPos();
                                                                                                            soulng::parser::Match match(false);
                                                                                                            if (*lexer == OROR)
                                                                                                            {
                                                                                                                ++lexer;
                                                                                                                match.hit = true;
                                                                                                            }
                                                                                                            if (match.hit)
                                                                                                            {
                                                                                                                {
                                                                                                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::logicalOr));
                                                                                                                }
                                                                                                            }
                                                                                                            *parentMatch60 = match;
                                                                                                        }
                                                                                                        *parentMatch59 = match;
                                                                                                    }
                                                                                                    *parentMatch22 = match;
                                                                                                }
                                                                                            }
                                                                                            *parentMatch21 = match;
                                                                                            if (!match.hit)
                                                                                            {
                                                                                                soulng::parser::Match match(false);
                                                                                                soulng::parser::Match* parentMatch61 = &match;
                                                                                                lexer.SetPos(save);
                                                                                                {
                                                                                                    soulng::parser::Match match(false);
                                                                                                    soulng::parser::Match* parentMatch62 = &match;
                                                                                                    {
                                                                                                        int64_t pos = lexer.GetPos();
                                                                                                        soulng::parser::Match match(false);
                                                                                                        if (*lexer == EQ)
                                                                                                        {
                                                                                                            ++lexer;
                                                                                                            match.hit = true;
                                                                                                        }
                                                                                                        if (match.hit)
                                                                                                        {
                                                                                                            {
                                                                                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::equal));
                                                                                                            }
                                                                                                        }
                                                                                                        *parentMatch62 = match;
                                                                                                    }
                                                                                                    *parentMatch61 = match;
                                                                                                }
                                                                                                *parentMatch21 = match;
                                                                                            }
                                                                                        }
                                                                                        *parentMatch20 = match;
                                                                                        if (!match.hit)
                                                                                        {
                                                                                            soulng::parser::Match match(false);
                                                                                            soulng::parser::Match* parentMatch63 = &match;
                                                                                            lexer.SetPos(save);
                                                                                            {
                                                                                                soulng::parser::Match match(false);
                                                                                                soulng::parser::Match* parentMatch64 = &match;
                                                                                                {
                                                                                                    int64_t pos = lexer.GetPos();
                                                                                                    soulng::parser::Match match(false);
                                                                                                    if (*lexer == NEQ)
                                                                                                    {
                                                                                                        ++lexer;
                                                                                                        match.hit = true;
                                                                                                    }
                                                                                                    if (match.hit)
                                                                                                    {
                                                                                                        {
                                                                                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                            return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::notEqual));
                                                                                                        }
                                                                                                    }
                                                                                                    *parentMatch64 = match;
                                                                                                }
                                                                                                *parentMatch63 = match;
                                                                                            }
                                                                                            *parentMatch20 = match;
                                                                                        }
                                                                                    }
                                                                                    *parentMatch19 = match;
                                                                                    if (!match.hit)
                                                                                    {
                                                                                        soulng::parser::Match match(false);
                                                                                        soulng::parser::Match* parentMatch65 = &match;
                                                                                        lexer.SetPos(save);
                                                                                        {
                                                                                            soulng::parser::Match match(false);
                                                                                            soulng::parser::Match* parentMatch66 = &match;
                                                                                            {
                                                                                                int64_t pos = lexer.GetPos();
                                                                                                soulng::parser::Match match(false);
                                                                                                if (*lexer == LEQ)
                                                                                                {
                                                                                                    ++lexer;
                                                                                                    match.hit = true;
                                                                                                }
                                                                                                if (match.hit)
                                                                                                {
                                                                                                    {
                                                                                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                        return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::lessOrEqual));
                                                                                                    }
                                                                                                }
                                                                                                *parentMatch66 = match;
                                                                                            }
                                                                                            *parentMatch65 = match;
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
                                                                                        soulng::parser::Match* parentMatch68 = &match;
                                                                                        {
                                                                                            int64_t pos = lexer.GetPos();
                                                                                            soulng::parser::Match match(false);
                                                                                            if (*lexer == GEQ)
                                                                                            {
                                                                                                ++lexer;
                                                                                                match.hit = true;
                                                                                            }
                                                                                            if (match.hit)
                                                                                            {
                                                                                                {
                                                                                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::greaterOrEqual));
                                                                                                }
                                                                                            }
                                                                                            *parentMatch68 = match;
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
                                                                                soulng::parser::Match* parentMatch69 = &match;
                                                                                lexer.SetPos(save);
                                                                                {
                                                                                    soulng::parser::Match match(false);
                                                                                    soulng::parser::Match* parentMatch70 = &match;
                                                                                    {
                                                                                        int64_t pos = lexer.GetPos();
                                                                                        soulng::parser::Match match(false);
                                                                                        if (*lexer == LANGLE)
                                                                                        {
                                                                                            ++lexer;
                                                                                            match.hit = true;
                                                                                        }
                                                                                        if (match.hit)
                                                                                        {
                                                                                            {
                                                                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::less));
                                                                                            }
                                                                                        }
                                                                                        *parentMatch70 = match;
                                                                                    }
                                                                                    *parentMatch69 = match;
                                                                                }
                                                                                *parentMatch17 = match;
                                                                            }
                                                                        }
                                                                        *parentMatch16 = match;
                                                                        if (!match.hit)
                                                                        {
                                                                            soulng::parser::Match match(false);
                                                                            soulng::parser::Match* parentMatch71 = &match;
                                                                            lexer.SetPos(save);
                                                                            {
                                                                                soulng::parser::Match match(false);
                                                                                soulng::parser::Match* parentMatch72 = &match;
                                                                                {
                                                                                    int64_t pos = lexer.GetPos();
                                                                                    soulng::parser::Match match(false);
                                                                                    if (*lexer == RANGLE)
                                                                                    {
                                                                                        ++lexer;
                                                                                        match.hit = true;
                                                                                    }
                                                                                    if (match.hit)
                                                                                    {
                                                                                        {
                                                                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                            return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::greater));
                                                                                        }
                                                                                    }
                                                                                    *parentMatch72 = match;
                                                                                }
                                                                                *parentMatch71 = match;
                                                                            }
                                                                            *parentMatch16 = match;
                                                                        }
                                                                    }
                                                                    *parentMatch15 = match;
                                                                    if (!match.hit)
                                                                    {
                                                                        soulng::parser::Match match(false);
                                                                        soulng::parser::Match* parentMatch73 = &match;
                                                                        lexer.SetPos(save);
                                                                        {
                                                                            soulng::parser::Match match(false);
                                                                            soulng::parser::Match* parentMatch74 = &match;
                                                                            {
                                                                                int64_t pos = lexer.GetPos();
                                                                                soulng::parser::Match match(false);
                                                                                if (*lexer == DOTSTAR)
                                                                                {
                                                                                    ++lexer;
                                                                                    match.hit = true;
                                                                                }
                                                                                if (match.hit)
                                                                                {
                                                                                    {
                                                                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                        return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::dotStar));
                                                                                    }
                                                                                }
                                                                                *parentMatch74 = match;
                                                                            }
                                                                            *parentMatch73 = match;
                                                                        }
                                                                        *parentMatch15 = match;
                                                                    }
                                                                }
                                                                *parentMatch14 = match;
                                                                if (!match.hit)
                                                                {
                                                                    soulng::parser::Match match(false);
                                                                    soulng::parser::Match* parentMatch75 = &match;
                                                                    lexer.SetPos(save);
                                                                    {
                                                                        soulng::parser::Match match(false);
                                                                        soulng::parser::Match* parentMatch76 = &match;
                                                                        {
                                                                            int64_t pos = lexer.GetPos();
                                                                            soulng::parser::Match match(false);
                                                                            if (*lexer == ARROWSTAR)
                                                                            {
                                                                                ++lexer;
                                                                                match.hit = true;
                                                                            }
                                                                            if (match.hit)
                                                                            {
                                                                                {
                                                                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::arrowStar));
                                                                                }
                                                                            }
                                                                            *parentMatch76 = match;
                                                                        }
                                                                        *parentMatch75 = match;
                                                                    }
                                                                    *parentMatch14 = match;
                                                                }
                                                            }
                                                            *parentMatch13 = match;
                                                            if (!match.hit)
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch77 = &match;
                                                                lexer.SetPos(save);
                                                                {
                                                                    soulng::parser::Match match(false);
                                                                    soulng::parser::Match* parentMatch78 = &match;
                                                                    {
                                                                        int64_t pos = lexer.GetPos();
                                                                        soulng::parser::Match match(false);
                                                                        if (*lexer == ARROW)
                                                                        {
                                                                            ++lexer;
                                                                            match.hit = true;
                                                                        }
                                                                        if (match.hit)
                                                                        {
                                                                            {
                                                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::arrow));
                                                                            }
                                                                        }
                                                                        *parentMatch78 = match;
                                                                    }
                                                                    *parentMatch77 = match;
                                                                }
                                                                *parentMatch13 = match;
                                                            }
                                                        }
                                                        *parentMatch12 = match;
                                                        if (!match.hit)
                                                        {
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch79 = &match;
                                                            lexer.SetPos(save);
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch80 = &match;
                                                                {
                                                                    soulng::parser::Match match(false);
                                                                    if (*lexer == LPAREN)
                                                                    {
                                                                        ++lexer;
                                                                        match.hit = true;
                                                                    }
                                                                    *parentMatch80 = match;
                                                                }
                                                                if (match.hit)
                                                                {
                                                                    soulng::parser::Match match(false);
                                                                    soulng::parser::Match* parentMatch81 = &match;
                                                                    {
                                                                        soulng::parser::Match match(false);
                                                                        soulng::parser::Match* parentMatch82 = &match;
                                                                        {
                                                                            int64_t pos = lexer.GetPos();
                                                                            soulng::parser::Match match(false);
                                                                            if (*lexer == RPAREN)
                                                                            {
                                                                                ++lexer;
                                                                                match.hit = true;
                                                                            }
                                                                            if (match.hit)
                                                                            {
                                                                                {
                                                                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::apply));
                                                                                }
                                                                            }
                                                                            *parentMatch82 = match;
                                                                        }
                                                                        *parentMatch81 = match;
                                                                    }
                                                                    *parentMatch80 = match;
                                                                }
                                                                *parentMatch79 = match;
                                                            }
                                                            *parentMatch12 = match;
                                                        }
                                                    }
                                                    *parentMatch11 = match;
                                                    if (!match.hit)
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch83 = &match;
                                                        lexer.SetPos(save);
                                                        {
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch84 = &match;
                                                            {
                                                                soulng::parser::Match match(false);
                                                                if (*lexer == LBRACKET)
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
                                                                    soulng::parser::Match* parentMatch86 = &match;
                                                                    {
                                                                        int64_t pos = lexer.GetPos();
                                                                        soulng::parser::Match match(false);
                                                                        if (*lexer == RBRACKET)
                                                                        {
                                                                            ++lexer;
                                                                            match.hit = true;
                                                                        }
                                                                        if (match.hit)
                                                                        {
                                                                            {
                                                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::subscript));
                                                                            }
                                                                        }
                                                                        *parentMatch86 = match;
                                                                    }
                                                                    *parentMatch85 = match;
                                                                }
                                                                *parentMatch84 = match;
                                                            }
                                                            *parentMatch83 = match;
                                                        }
                                                        *parentMatch11 = match;
                                                    }
                                                }
                                                *parentMatch10 = match;
                                                if (!match.hit)
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch87 = &match;
                                                    lexer.SetPos(save);
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch88 = &match;
                                                        {
                                                            int64_t pos = lexer.GetPos();
                                                            soulng::parser::Match match(false);
                                                            if (*lexer == PLUS)
                                                            {
                                                                ++lexer;
                                                                match.hit = true;
                                                            }
                                                            if (match.hit)
                                                            {
                                                                {
                                                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::add));
                                                                }
                                                            }
                                                            *parentMatch88 = match;
                                                        }
                                                        *parentMatch87 = match;
                                                    }
                                                    *parentMatch10 = match;
                                                }
                                            }
                                            *parentMatch9 = match;
                                            if (!match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch89 = &match;
                                                lexer.SetPos(save);
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch90 = &match;
                                                    {
                                                        int64_t pos = lexer.GetPos();
                                                        soulng::parser::Match match(false);
                                                        if (*lexer == MINUS)
                                                        {
                                                            ++lexer;
                                                            match.hit = true;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            {
                                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::sub));
                                                            }
                                                        }
                                                        *parentMatch90 = match;
                                                    }
                                                    *parentMatch89 = match;
                                                }
                                                *parentMatch9 = match;
                                            }
                                        }
                                        *parentMatch8 = match;
                                        if (!match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch91 = &match;
                                            lexer.SetPos(save);
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch92 = &match;
                                                {
                                                    int64_t pos = lexer.GetPos();
                                                    soulng::parser::Match match(false);
                                                    if (*lexer == STAR)
                                                    {
                                                        ++lexer;
                                                        match.hit = true;
                                                    }
                                                    if (match.hit)
                                                    {
                                                        {
                                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                            return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::mul));
                                                        }
                                                    }
                                                    *parentMatch92 = match;
                                                }
                                                *parentMatch91 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                    }
                                    *parentMatch7 = match;
                                    if (!match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch93 = &match;
                                        lexer.SetPos(save);
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch94 = &match;
                                            {
                                                int64_t pos = lexer.GetPos();
                                                soulng::parser::Match match(false);
                                                if (*lexer == DIV)
                                                {
                                                    ++lexer;
                                                    match.hit = true;
                                                }
                                                if (match.hit)
                                                {
                                                    {
                                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                        return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::div));
                                                    }
                                                }
                                                *parentMatch94 = match;
                                            }
                                            *parentMatch93 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                }
                                *parentMatch6 = match;
                                if (!match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch95 = &match;
                                    lexer.SetPos(save);
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch96 = &match;
                                        {
                                            int64_t pos = lexer.GetPos();
                                            soulng::parser::Match match(false);
                                            if (*lexer == MOD)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            if (match.hit)
                                            {
                                                {
                                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::rem));
                                                }
                                            }
                                            *parentMatch96 = match;
                                        }
                                        *parentMatch95 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                            }
                            *parentMatch5 = match;
                            if (!match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch97 = &match;
                                lexer.SetPos(save);
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch98 = &match;
                                    {
                                        int64_t pos = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        if (*lexer == XOR)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            {
                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::xor_));
                                            }
                                        }
                                        *parentMatch98 = match;
                                    }
                                    *parentMatch97 = match;
                                }
                                *parentMatch5 = match;
                            }
                        }
                        *parentMatch4 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch99 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch100 = &match;
                                {
                                    int64_t pos = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    if (*lexer == AMP)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        {
                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                            return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::and_));
                                        }
                                    }
                                    *parentMatch100 = match;
                                }
                                *parentMatch99 = match;
                            }
                            *parentMatch4 = match;
                        }
                    }
                    *parentMatch3 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch101 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch102 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == OR)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    {
                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                        return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::or_));
                                    }
                                }
                                *parentMatch102 = match;
                            }
                            *parentMatch101 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch103 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch104 = &match;
                        {
                            int64_t pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == TILDE)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                {
                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::complement));
                                }
                            }
                            *parentMatch104 = match;
                        }
                        *parentMatch103 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch105 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch106 = &match;
                    {
                        int64_t pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == EXCLAMATION)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (match.hit)
                        {
                            {
                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::not_));
                            }
                        }
                        *parentMatch106 = match;
                    }
                    *parentMatch105 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch107 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch108 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == COMMA)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        {
                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                            return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Operator>(sngcpp::ast::Operator::comma));
                        }
                    }
                    *parentMatch108 = match;
                }
                *parentMatch107 = match;
            }
            *parentMatch0 = match;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("Operator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::ConversionFunctionId(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ConversionFunctionId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> typeExpr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int64_t pos = lexer.GetPos();
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
                int64_t pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                typeExpr.reset(static_cast<sngcpp::ast::Node*>(match.value));
                if (match.hit)
                {
                    s.end = span.end;
                    {
                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ConversionFunctionId"));
                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                        return soulng::parser::Match(true, new sngcpp::ast::ConversionFunctionIdNode(s, typeExpr.release()));
                    }
                }
                *parentMatch3 = match;
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ConversionFunctionId"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ConversionFunctionId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::LambdaExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("LambdaExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::LambdaExpressionNode> node = std::unique_ptr<sngcpp::ast::LambdaExpressionNode>();
    std::unique_ptr<sngcpp::ast::Node> params;
    std::unique_ptr<sngcpp::ast::CompoundStatementNode> body;
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
                        int64_t pos = lexer.GetPos();
                        soulng::lexer::Span span = lexer.GetSpan();
                        soulng::parser::Match match(false);
                        if (*lexer == LBRACKET)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (match.hit)
                        {
                            node.reset(new sngcpp::ast::LambdaExpressionNode(span));
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
                        soulng::parser::Match match = ExpressionParser::LambdaCaptures(lexer, node.get());
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
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch7 = &match;
                    {
                        int64_t pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == RBRACKET)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (match.hit)
                        {
                            *parentMatch7 = match;
                        }
                        else
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RBRACKET)));
                        }
                    }
                    *parentMatch6 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch8 = &match;
            {
                soulng::parser::Match match(true);
                int64_t save = lexer.GetPos();
                soulng::parser::Match* parentMatch9 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch10 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch11 = &match;
                        {
                            int64_t pos = lexer.GetPos();
                            soulng::parser::Match match = FunctionParser::ParameterList(lexer, ctx);
                            params.reset(static_cast<sngcpp::ast::Node*>(match.value));
                            if (match.hit)
                            {
                                node->SetParameters(params.release());
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
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch12 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch13 = &match;
            {
                int64_t pos = lexer.GetPos();
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch14 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::parser::Match match = StatementParser::CompoundStatement(lexer, ctx);
                    body.reset(static_cast<sngcpp::ast::CompoundStatementNode*>(match.value));
                    if (match.hit)
                    {
                        *parentMatch14 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, U"CompoundStatement");
                    }
                }
                if (match.hit)
                {
                    node->SetBody(body.release());
                    {
                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("LambdaExpression"));
                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                        return soulng::parser::Match(true, node.release());
                    }
                }
                *parentMatch13 = match;
            }
            *parentMatch12 = match;
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("LambdaExpression"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("LambdaExpression"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::LambdaCaptures(CppLexer& lexer, sngcpp::ast::LambdaExpressionNode* lambdaExpression)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("LambdaCaptures"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> captureDefault;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(true);
        int64_t save = lexer.GetPos();
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::parser::Match match = ExpressionParser::CaptureDefault(lexer);
                    captureDefault.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        lambdaExpression->AddCapture(captureDefault.release());
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                *parentMatch1 = match;
            }
            else
            {
                lexer.SetPos(save);
            }
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch4 = &match;
        {
            soulng::parser::Match match(true);
            int64_t save = lexer.GetPos();
            soulng::parser::Match* parentMatch5 = &match;
            {
                soulng::parser::Match match = ExpressionParser::Captures(lexer, lambdaExpression);
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
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("LambdaCaptures"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("LambdaCaptures"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::CaptureDefault(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("CaptureDefault"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    int64_t pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case ASSIGN:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("CaptureDefault"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new sngcpp::ast::AssignCaptureNode(span));
                }
            }
            break;
        }
        case AMP:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("CaptureDefault"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new sngcpp::ast::RefCaptureNode(span));
                }
            }
            break;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("CaptureDefault"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("CaptureDefault"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::Captures(CppLexer& lexer, sngcpp::ast::LambdaExpressionNode* lambdaExpression)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("Captures"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> left;
    std::unique_ptr<sngcpp::ast::Node> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int64_t pos = lexer.GetPos();
            soulng::parser::Match match = ExpressionParser::Capture(lexer);
            left.reset(static_cast<sngcpp::ast::Node*>(match.value));
            if (match.hit)
            {
                lambdaExpression->AddCapture(left.release());
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
                    int64_t save = lexer.GetPos();
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch4 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch5 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == COMMA)
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
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        int64_t pos = lexer.GetPos();
                                        soulng::parser::Match match = ExpressionParser::Capture(lexer);
                                        right.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                        if (match.hit)
                                        {
                                            lambdaExpression->AddCapture(right.release());
                                        }
                                        *parentMatch7 = match;
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
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Captures"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("Captures"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::Capture(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("Capture"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<soulng::parser::Value<std::u32string>> id;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int64_t pos = lexer.GetPos();
            soulng::lexer::Span span = lexer.GetSpan();
            soulng::parser::Match match = IdentifierParser::Identifier(lexer);
            id.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
            if (match.hit)
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Capture"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new sngcpp::ast::IdentifierCaptureNode(span, new sngcpp::ast::IdentifierNode(span, id->value)));
                }
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
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match(false);
                    if (*lexer == THIS)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        {
                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Capture"));
                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                            return soulng::parser::Match(true, new sngcpp::ast::ThisCaptureNode(span));
                        }
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch0 = match;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Capture"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("Capture"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}
