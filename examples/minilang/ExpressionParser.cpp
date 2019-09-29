#include "ExpressionParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <minilang/LiteralParser.hpp>
#include <minilang/IdentifierParser.hpp>
#include <minilang/MinilangLexer.hpp>
#include <minilang/MinilangTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/ExpressionParser.parser' using soulng parser generator spg version 1.2.0

using namespace soulng::unicode;
using namespace MinilangTokens;

soulng::parser::Match ExpressionParser::Expression(MinilangLexer& lexer)
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
    std::unique_ptr<minilang::Node> expr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match = ExpressionParser::EqualityExpression(lexer);
        expr.reset(static_cast<minilang::Node*>(match.value));
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

soulng::parser::Match ExpressionParser::PrimaryExpression(MinilangLexer& lexer)
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
    std::unique_ptr<minilang::Node> literal;
    std::unique_ptr<minilang::IdentifierNode> identifier;
    std::unique_ptr<minilang::Node> expression;
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
                soulng::parser::Match match = LiteralParser::Literal(lexer);
                literal.reset(static_cast<minilang::Node*>(match.value));
                if (match.hit)
                {
                    {
                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("PrimaryExpression"));
                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                        return soulng::parser::Match(true, literal.release());
                    }
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
                        soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                        identifier.reset(static_cast<minilang::IdentifierNode*>(match.value));
                        if (match.hit)
                        {
                            {
                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("PrimaryExpression"));
                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                return soulng::parser::Match(true, identifier.release());
                            }
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
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch8 = &match;
                        {
                            soulng::parser::Match match = ExpressionParser::Expression(lexer);
                            expression.reset(static_cast<minilang::Node*>(match.value));
                            *parentMatch8 = match;
                        }
                        *parentMatch7 = match;
                    }
                    *parentMatch6 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch9 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch10 = &match;
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
                                {
                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("PrimaryExpression"));
                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                    return soulng::parser::Match(true, new minilang::ParenthesizedExpressionNode(expression.release()));
                                }
                            }
                            *parentMatch10 = match;
                        }
                        *parentMatch9 = match;
                    }
                    *parentMatch6 = match;
                }
                *parentMatch5 = match;
            }
            *parentMatch0 = match;
        }
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

soulng::parser::Match ExpressionParser::PostfixExpression(MinilangLexer& lexer)
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
    std::unique_ptr<minilang::Node> expr = std::unique_ptr<minilang::Node>();
    std::unique_ptr<minilang::Node> primary;
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
                    soulng::parser::Match match = ExpressionParser::PrimaryExpression(lexer);
                    primary.reset(static_cast<minilang::Node*>(match.value));
                    if (match.hit)
                    {
                        expr.reset(primary.release());
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
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch9 = &match;
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
                                                    expr.reset(new minilang::InvokeNode(expr.release()));
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
                                                soulng::parser::Match match(true);
                                                int save = lexer.GetPos();
                                                soulng::parser::Match* parentMatch11 = &match;
                                                {
                                                    soulng::parser::Match match = ExpressionParser::ExpressionList(lexer, expr.get());
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
                                            *parentMatch8 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch12 = &match;
                                        {
                                            soulng::parser::Match match(true);
                                            soulng::parser::Match* parentMatch13 = &match;
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
                                                    *parentMatch13 = match;
                                                }
                                                else
                                                {
                                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                                                }
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

soulng::parser::Match ExpressionParser::ExpressionList(MinilangLexer& lexer, minilang::Node* owner)
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
    std::unique_ptr<minilang::Node> left;
    std::unique_ptr<minilang::Node> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match = ExpressionParser::Expression(lexer);
            left.reset(static_cast<minilang::Node*>(match.value));
            if (match.hit)
            {
                owner->AddArgument(left.release());
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
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match(true);
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = ExpressionParser::Expression(lexer);
                                            right.reset(static_cast<minilang::Node*>(match.value));
                                            if (match.hit)
                                            {
                                                *parentMatch8 = match;
                                            }
                                            else
                                            {
                                                lexer.ThrowExpectationFailure(pos, U"Expression");
                                            }
                                        }
                                        if (match.hit)
                                        {
                                            owner->AddArgument(right.release());
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
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ExpressionList"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ExpressionList"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ExpressionParser::UnaryExpression(MinilangLexer& lexer)
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
    std::unique_ptr<soulng::parser::Value<minilang::Operator>> op;
    std::unique_ptr<minilang::Node> unaryExpr;
    std::unique_ptr<minilang::Node> postfixExpr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match = ExpressionParser::UnaryOperator(lexer);
            op.reset(static_cast<soulng::parser::Value<minilang::Operator>*>(match.value));
            *parentMatch1 = match;
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
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = ExpressionParser::UnaryExpression(lexer);
                        unaryExpr.reset(static_cast<minilang::Node*>(match.value));
                        if (match.hit)
                        {
                            *parentMatch4 = match;
                        }
                        else
                        {
                            lexer.ThrowExpectationFailure(pos, U"UnaryExpression");
                        }
                    }
                    if (match.hit)
                    {
                        {
                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnaryExpression"));
                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                            return soulng::parser::Match(true, new minilang::UnaryOpExprNode(op->value, unaryExpr.release()));
                        }
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
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
                    soulng::parser::Match match = ExpressionParser::PostfixExpression(lexer);
                    postfixExpr.reset(static_cast<minilang::Node*>(match.value));
                    if (match.hit)
                    {
                        {
                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnaryExpression"));
                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                            return soulng::parser::Match(true, postfixExpr.release());
                        }
                    }
                    *parentMatch6 = match;
                }
                *parentMatch5 = match;
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

soulng::parser::Match ExpressionParser::UnaryOperator(MinilangLexer& lexer)
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
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case PLUS:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnaryOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<minilang::Operator>(minilang::Operator::unaryPlus));
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
                    return soulng::parser::Match(true, new soulng::parser::Value<minilang::Operator>(minilang::Operator::unaryMinus));
                }
            }
            break;
        }
        case NOT:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnaryOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<minilang::Operator>(minilang::Operator::not_));
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

soulng::parser::Match ExpressionParser::MultiplicativeExpression(MinilangLexer& lexer)
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
    std::unique_ptr<minilang::Node> expr = std::unique_ptr<minilang::Node>();
    std::unique_ptr<minilang::Node> left;
    std::unique_ptr<soulng::parser::Value<minilang::Operator>> op;
    std::unique_ptr<minilang::Node> right;
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
                    soulng::parser::Match match = ExpressionParser::UnaryExpression(lexer);
                    left.reset(static_cast<minilang::Node*>(match.value));
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
                                        soulng::parser::Match match = ExpressionParser::MultiplicativeOperator(lexer);
                                        op.reset(static_cast<soulng::parser::Value<minilang::Operator>*>(match.value));
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
                                                    soulng::parser::Match match = ExpressionParser::UnaryExpression(lexer);
                                                    right.reset(static_cast<minilang::Node*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        *parentMatch10 = match;
                                                    }
                                                    else
                                                    {
                                                        lexer.ThrowExpectationFailure(pos, U"UnaryExpression");
                                                    }
                                                }
                                                if (match.hit)
                                                {
                                                    expr.reset(new minilang::BinaryOpExprNode(op->value, expr.release(), right.release()));
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

soulng::parser::Match ExpressionParser::MultiplicativeOperator(MinilangLexer& lexer)
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
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case MUL:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MultiplicativeOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<minilang::Operator>(minilang::Operator::mul));
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
                    return soulng::parser::Match(true, new soulng::parser::Value<minilang::Operator>(minilang::Operator::div));
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
                    return soulng::parser::Match(true, new soulng::parser::Value<minilang::Operator>(minilang::Operator::mod));
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

soulng::parser::Match ExpressionParser::AdditiveExpression(MinilangLexer& lexer)
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
    std::unique_ptr<minilang::Node> expr = std::unique_ptr<minilang::Node>();
    std::unique_ptr<minilang::Node> left;
    std::unique_ptr<soulng::parser::Value<minilang::Operator>> op;
    std::unique_ptr<minilang::Node> right;
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
                    soulng::parser::Match match = ExpressionParser::MultiplicativeExpression(lexer);
                    left.reset(static_cast<minilang::Node*>(match.value));
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
                                        soulng::parser::Match match = ExpressionParser::AdditiveOperator(lexer);
                                        op.reset(static_cast<soulng::parser::Value<minilang::Operator>*>(match.value));
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
                                                    soulng::parser::Match match = ExpressionParser::MultiplicativeExpression(lexer);
                                                    right.reset(static_cast<minilang::Node*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        *parentMatch10 = match;
                                                    }
                                                    else
                                                    {
                                                        lexer.ThrowExpectationFailure(pos, U"MultiplicativeExpression");
                                                    }
                                                }
                                                if (match.hit)
                                                {
                                                    expr.reset(new minilang::BinaryOpExprNode(op->value, expr.release(), right.release()));
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

soulng::parser::Match ExpressionParser::AdditiveOperator(MinilangLexer& lexer)
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
    int pos = lexer.GetPos();
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
                    return soulng::parser::Match(true, new soulng::parser::Value<minilang::Operator>(minilang::Operator::add));
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
                    return soulng::parser::Match(true, new soulng::parser::Value<minilang::Operator>(minilang::Operator::sub));
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

soulng::parser::Match ExpressionParser::RelationalExpression(MinilangLexer& lexer)
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
    std::unique_ptr<minilang::Node> expr = std::unique_ptr<minilang::Node>();
    std::unique_ptr<minilang::Node> left;
    std::unique_ptr<soulng::parser::Value<minilang::Operator>> op;
    std::unique_ptr<minilang::Node> right;
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
                    soulng::parser::Match match = ExpressionParser::AdditiveExpression(lexer);
                    left.reset(static_cast<minilang::Node*>(match.value));
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
                                        soulng::parser::Match match = ExpressionParser::RelationalOperator(lexer);
                                        op.reset(static_cast<soulng::parser::Value<minilang::Operator>*>(match.value));
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
                                                    soulng::parser::Match match = ExpressionParser::AdditiveExpression(lexer);
                                                    right.reset(static_cast<minilang::Node*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        *parentMatch10 = match;
                                                    }
                                                    else
                                                    {
                                                        lexer.ThrowExpectationFailure(pos, U"AdditiveExpression");
                                                    }
                                                }
                                                if (match.hit)
                                                {
                                                    expr.reset(new minilang::BinaryOpExprNode(op->value, expr.release(), right.release()));
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

soulng::parser::Match ExpressionParser::RelationalOperator(MinilangLexer& lexer)
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
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case LESS:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("RelationalOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<minilang::Operator>(minilang::Operator::less));
                }
            }
            break;
        }
        case GREATER:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("RelationalOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<minilang::Operator>(minilang::Operator::greater));
                }
            }
            break;
        }
        case LEQ:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("RelationalOperator"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<minilang::Operator>(minilang::Operator::lessOrEqual));
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
                    return soulng::parser::Match(true, new soulng::parser::Value<minilang::Operator>(minilang::Operator::greaterOrEqual));
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

soulng::parser::Match ExpressionParser::EqualityExpression(MinilangLexer& lexer)
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
    std::unique_ptr<minilang::Node> expr = std::unique_ptr<minilang::Node>();
    std::unique_ptr<minilang::Node> left;
    std::unique_ptr<soulng::parser::Value<minilang::Operator>> op;
    std::unique_ptr<minilang::Node> right;
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
                    soulng::parser::Match match = ExpressionParser::RelationalExpression(lexer);
                    left.reset(static_cast<minilang::Node*>(match.value));
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
                                        soulng::parser::Match match = ExpressionParser::EqualityOperator(lexer);
                                        op.reset(static_cast<soulng::parser::Value<minilang::Operator>*>(match.value));
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
                                                    soulng::parser::Match match = ExpressionParser::RelationalExpression(lexer);
                                                    right.reset(static_cast<minilang::Node*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        *parentMatch10 = match;
                                                    }
                                                    else
                                                    {
                                                        lexer.ThrowExpectationFailure(pos, U"RelationalExpression");
                                                    }
                                                }
                                                if (match.hit)
                                                {
                                                    expr.reset(new minilang::BinaryOpExprNode(op->value, expr.release(), right.release()));
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

soulng::parser::Match ExpressionParser::EqualityOperator(MinilangLexer& lexer)
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
    int pos = lexer.GetPos();
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
                    return soulng::parser::Match(true, new soulng::parser::Value<minilang::Operator>(minilang::Operator::equal));
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
                    return soulng::parser::Match(true, new soulng::parser::Value<minilang::Operator>(minilang::Operator::notEqual));
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
