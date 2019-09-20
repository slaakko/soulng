#include "Expression.hpp"
#include <soulng/util/Unicode.hpp>
#include <cmajor/parser/BasicType.hpp>
#include <cmajor/parser/Literal.hpp>
#include <cmajor/parser/Template.hpp>
#include <cmajor/parser/Operator.hpp>
#include <cmajor/parser/TypeExpr.hpp>
#include <cmajor/parser/Identifier.hpp>
#include <cmajor/lexer/CmajorLexer.hpp>
#include <cmajor/lexer/CmajorTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/Expression.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace cmajor::ast;
using namespace CmajorTokens;

soulng::parser::Match ExpressionParser::Expression(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> equivalence;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match = ExpressionParser::Equivalence(lexer, ctx);
        equivalence.reset(static_cast<Node*>(match.value));
        if (match.hit)
        {
            return soulng::parser::Match(true, equivalence.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::Equivalence(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> expr = std::unique_ptr<Node>();
    Span s = Span();
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ExpressionParser::Implication(lexer, ctx);
                left.reset(static_cast<Node*>(match.value));
                if (match.hit)
                {
                    s = span;
                    expr.reset(left.release());
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
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    bool pass = true;
                                    soulng::parser::Match match(false);
                                    if (*lexer == EQUIVALENCE)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        if (!ctx->parsingConcept || ctx->parsingTemplateId) pass = false;
                                    }
                                    if (match.hit && !pass)
                                    {
                                        match = soulng::parser::Match(false);
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
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match(true);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = ExpressionParser::Implication(lexer, ctx);
                                            right.reset(static_cast<Node*>(match.value));
                                            if (match.hit)
                                            {
                                                *parentMatch9 = match;
                                            }
                                            else
                                            {
                                                lexer.ThrowExpectationFailure(pos, U"implication expression");
                                            }
                                        }
                                        if (match.hit)
                                        {
                                            s.end = span.end;
                                            expr.reset(new EquivalenceNode(s, expr.release(), right.release()));
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
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
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::Implication(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> expr = std::unique_ptr<Node>();
    Span s = Span();
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ExpressionParser::Disjunction(lexer, ctx);
                left.reset(static_cast<Node*>(match.value));
                if (match.hit)
                {
                    s = span;
                    expr.reset(left.release());
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
                int save = lexer.GetPos();
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            int pos = lexer.GetPos();
                            bool pass = true;
                            soulng::parser::Match match(false);
                            if (*lexer == IMPLICATION)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                if (!ctx->parsingConcept || ctx->parsingTemplateId) pass = false;
                            }
                            if (match.hit && !pass)
                            {
                                match = soulng::parser::Match(false);
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
                            soulng::parser::Match* parentMatch8 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match(true);
                                soulng::parser::Match* parentMatch9 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = ExpressionParser::Implication(lexer, ctx);
                                    right.reset(static_cast<Node*>(match.value));
                                    if (match.hit)
                                    {
                                        *parentMatch9 = match;
                                    }
                                    else
                                    {
                                        lexer.ThrowExpectationFailure(pos, U"implication expression");
                                    }
                                }
                                if (match.hit)
                                {
                                    s.end = span.end;
                                    expr.reset(new ImplicationNode(s, expr.release(), right.release()));
                                }
                                *parentMatch8 = match;
                            }
                            *parentMatch7 = match;
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
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::Disjunction(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> expr = std::unique_ptr<Node>();
    Span s = Span();
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ExpressionParser::Conjunction(lexer, ctx);
                left.reset(static_cast<Node*>(match.value));
                if (match.hit)
                {
                    s = span;
                    expr.reset(left.release());
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
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    bool pass = true;
                                    soulng::parser::Match match(false);
                                    if (*lexer == DISJUNCTION)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        if (ctx->parsingLvalue || ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                    }
                                    if (match.hit && !pass)
                                    {
                                        match = soulng::parser::Match(false);
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
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match(true);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = ExpressionParser::Conjunction(lexer, ctx);
                                            right.reset(static_cast<Node*>(match.value));
                                            if (match.hit)
                                            {
                                                *parentMatch9 = match;
                                            }
                                            else
                                            {
                                                lexer.ThrowExpectationFailure(pos, U"conjunctive expression");
                                            }
                                        }
                                        if (match.hit)
                                        {
                                            s.end = span.end;
                                            expr.reset(new DisjunctionNode(s, expr.release(), right.release()));
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
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
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::Conjunction(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> expr = std::unique_ptr<Node>();
    Span s = Span();
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ExpressionParser::BitOr(lexer, ctx);
                left.reset(static_cast<Node*>(match.value));
                if (match.hit)
                {
                    s = span;
                    expr.reset(left.release());
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
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    bool pass = true;
                                    soulng::parser::Match match(false);
                                    if (*lexer == AMPAMP)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        if (ctx->parsingLvalue || ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                    }
                                    if (match.hit && !pass)
                                    {
                                        match = soulng::parser::Match(false);
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
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match(true);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = ExpressionParser::BitOr(lexer, ctx);
                                            right.reset(static_cast<Node*>(match.value));
                                            if (match.hit)
                                            {
                                                *parentMatch9 = match;
                                            }
                                            else
                                            {
                                                lexer.ThrowExpectationFailure(pos, U"bitwise or expression ");
                                            }
                                        }
                                        if (match.hit)
                                        {
                                            s.end = span.end;
                                            expr.reset(new ConjunctionNode(s, expr.release(), right.release()));
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
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
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::BitOr(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> expr = std::unique_ptr<Node>();
    Span s = Span();
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ExpressionParser::BitXor(lexer, ctx);
                left.reset(static_cast<Node*>(match.value));
                if (match.hit)
                {
                    s = span;
                    expr.reset(left.release());
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
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    bool pass = true;
                                    soulng::parser::Match match(false);
                                    if (*lexer == BITOR)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        if (ctx->parsingLvalue || ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                    }
                                    if (match.hit && !pass)
                                    {
                                        match = soulng::parser::Match(false);
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
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match(true);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = ExpressionParser::BitXor(lexer, ctx);
                                            right.reset(static_cast<Node*>(match.value));
                                            if (match.hit)
                                            {
                                                *parentMatch9 = match;
                                            }
                                            else
                                            {
                                                lexer.ThrowExpectationFailure(pos, U"bitwise exclusive or expression");
                                            }
                                        }
                                        if (match.hit)
                                        {
                                            s.end = span.end;
                                            expr.reset(new BitOrNode(s, expr.release(), right.release()));
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
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
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::BitXor(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> expr = std::unique_ptr<Node>();
    Span s = Span();
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ExpressionParser::BitAnd(lexer, ctx);
                left.reset(static_cast<Node*>(match.value));
                if (match.hit)
                {
                    s = span;
                    expr.reset(left.release());
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
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    bool pass = true;
                                    soulng::parser::Match match(false);
                                    if (*lexer == BITXOR)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        if (ctx->parsingLvalue || ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                    }
                                    if (match.hit && !pass)
                                    {
                                        match = soulng::parser::Match(false);
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
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match(true);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = ExpressionParser::BitAnd(lexer, ctx);
                                            right.reset(static_cast<Node*>(match.value));
                                            if (match.hit)
                                            {
                                                *parentMatch9 = match;
                                            }
                                            else
                                            {
                                                lexer.ThrowExpectationFailure(pos, U"bitwise and expression");
                                            }
                                        }
                                        if (match.hit)
                                        {
                                            s.end = span.end;
                                            expr.reset(new BitXorNode(s, expr.release(), right.release()));
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
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
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::BitAnd(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> expr = std::unique_ptr<Node>();
    Span s = Span();
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ExpressionParser::Equality(lexer, ctx);
                left.reset(static_cast<Node*>(match.value));
                if (match.hit)
                {
                    s = span;
                    expr.reset(left.release());
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
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    bool pass = true;
                                    soulng::parser::Match match(false);
                                    if (*lexer == AMP)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        if (ctx->parsingLvalue || ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                    }
                                    if (match.hit && !pass)
                                    {
                                        match = soulng::parser::Match(false);
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
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match(true);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = ExpressionParser::Equality(lexer, ctx);
                                            right.reset(static_cast<Node*>(match.value));
                                            if (match.hit)
                                            {
                                                *parentMatch9 = match;
                                            }
                                            else
                                            {
                                                lexer.ThrowExpectationFailure(pos, U"equality expression");
                                            }
                                        }
                                        if (match.hit)
                                        {
                                            s.end = span.end;
                                            expr.reset(new BitAndNode(s, expr.release(), right.release()));
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
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
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::Equality(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> expr = std::unique_ptr<Node>();
    Span s = Span();
    Operator op = Operator();
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ExpressionParser::Relational(lexer, ctx);
                left.reset(static_cast<Node*>(match.value));
                if (match.hit)
                {
                    s = span;
                    expr.reset(left.release());
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
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    int save = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        bool pass = true;
                                        soulng::parser::Match match(false);
                                        if (*lexer == EQ)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            if (ctx->parsingLvalue || ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                            else op = Operator::eq;
                                        }
                                        if (match.hit && !pass)
                                        {
                                            match = soulng::parser::Match(false);
                                        }
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
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
                                                bool pass = true;
                                                soulng::parser::Match match(false);
                                                if (*lexer == NEQ)
                                                {
                                                    ++lexer;
                                                    match.hit = true;
                                                }
                                                if (match.hit)
                                                {
                                                    if (ctx->parsingLvalue || ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                                    else op = Operator::neq;
                                                }
                                                if (match.hit && !pass)
                                                {
                                                    match = soulng::parser::Match(false);
                                                }
                                                *parentMatch9 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                        *parentMatch6 = match;
                                    }
                                }
                                *parentMatch5 = match;
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
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match(true);
                                        soulng::parser::Match* parentMatch12 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = ExpressionParser::Relational(lexer, ctx);
                                            right.reset(static_cast<Node*>(match.value));
                                            if (match.hit)
                                            {
                                                *parentMatch12 = match;
                                            }
                                            else
                                            {
                                                lexer.ThrowExpectationFailure(pos, U"relational expression");
                                            }
                                        }
                                        if (match.hit)
                                        {
                                            switch (op)
                                            {
                                                case Operator::eq: s.end = span.end;
                                                expr.reset(new EqualNode(s, expr.release(), right.release()));
                                                break;
                                                case Operator::neq: s.end = span.end;
                                                expr.reset(new NotEqualNode(s, expr.release(), right.release()));
                                                break;
                                            }
                                        }
                                        *parentMatch11 = match;
                                    }
                                    *parentMatch10 = match;
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
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::Relational(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> expr = std::unique_ptr<Node>();
    Span s = Span();
    Operator op = Operator();
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> isType;
    std::unique_ptr<Node> asType;
    std::unique_ptr<Node> right;
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ExpressionParser::Shift(lexer, ctx);
                left.reset(static_cast<Node*>(match.value));
                if (match.hit)
                {
                    s = span;
                    expr.reset(left.release());
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
                                                        int pos = lexer.GetPos();
                                                        bool pass = true;
                                                        soulng::parser::Match match(false);
                                                        if (*lexer == LEQ)
                                                        {
                                                            ++lexer;
                                                            match.hit = true;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            if (ctx->parsingLvalue || ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                                            else
                                                            {
                                                                op = Operator::lessOrEq;
                                                                ctx->PushParsingIsOrAs(false);
                                                            }
                                                        }
                                                        if (match.hit && !pass)
                                                        {
                                                            match = soulng::parser::Match(false);
                                                        }
                                                        *parentMatch11 = match;
                                                    }
                                                    *parentMatch10 = match;
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
                                                                bool pass = true;
                                                                soulng::parser::Match match(false);
                                                                if (*lexer == GEQ)
                                                                {
                                                                    ++lexer;
                                                                    match.hit = true;
                                                                }
                                                                if (match.hit)
                                                                {
                                                                    if (ctx->parsingLvalue || ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                                                    else
                                                                    {
                                                                        op = Operator::greaterOrEq;
                                                                        ctx->PushParsingIsOrAs(false);
                                                                    }
                                                                }
                                                                if (match.hit && !pass)
                                                                {
                                                                    match = soulng::parser::Match(false);
                                                                }
                                                                *parentMatch13 = match;
                                                            }
                                                            *parentMatch12 = match;
                                                        }
                                                        *parentMatch10 = match;
                                                    }
                                                }
                                                *parentMatch9 = match;
                                                if (!match.hit)
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch14 = &match;
                                                    lexer.SetPos(save);
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch15 = &match;
                                                        {
                                                            int pos = lexer.GetPos();
                                                            bool pass = true;
                                                            soulng::parser::Match match(false);
                                                            if (*lexer == LANGLE)
                                                            {
                                                                ++lexer;
                                                                match.hit = true;
                                                            }
                                                            if (match.hit)
                                                            {
                                                                if (ctx->parsingLvalue || ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                                                else
                                                                {
                                                                    op = Operator::less;
                                                                    ctx->PushParsingIsOrAs(false);
                                                                }
                                                            }
                                                            if (match.hit && !pass)
                                                            {
                                                                match = soulng::parser::Match(false);
                                                            }
                                                            *parentMatch15 = match;
                                                        }
                                                        *parentMatch14 = match;
                                                    }
                                                    *parentMatch9 = match;
                                                }
                                            }
                                            *parentMatch8 = match;
                                            if (!match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch16 = &match;
                                                lexer.SetPos(save);
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch17 = &match;
                                                    {
                                                        int pos = lexer.GetPos();
                                                        bool pass = true;
                                                        soulng::parser::Match match(false);
                                                        if (*lexer == RANGLE)
                                                        {
                                                            ++lexer;
                                                            match.hit = true;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            if (ctx->parsingLvalue || ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                                            else
                                                            {
                                                                op = Operator::greater;
                                                                ctx->PushParsingIsOrAs(false);
                                                            }
                                                        }
                                                        if (match.hit && !pass)
                                                        {
                                                            match = soulng::parser::Match(false);
                                                        }
                                                        *parentMatch17 = match;
                                                    }
                                                    *parentMatch16 = match;
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
                                                    soulng::parser::Match* parentMatch20 = &match;
                                                    {
                                                        int pos = lexer.GetPos();
                                                        bool pass = true;
                                                        soulng::parser::Match match(false);
                                                        if (*lexer == IS)
                                                        {
                                                            ++lexer;
                                                            match.hit = true;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            if (ctx->parsingLvalue || ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                                            else
                                                            {
                                                                op = Operator::is;
                                                                ctx->PushParsingIsOrAs(true);
                                                            }
                                                        }
                                                        if (match.hit && !pass)
                                                        {
                                                            match = soulng::parser::Match(false);
                                                        }
                                                        *parentMatch20 = match;
                                                    }
                                                    *parentMatch19 = match;
                                                }
                                                if (match.hit)
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch21 = &match;
                                                    {
                                                        soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                                                        isType.reset(static_cast<Node*>(match.value));
                                                        *parentMatch21 = match;
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
                                        soulng::parser::Match* parentMatch22 = &match;
                                        lexer.SetPos(save);
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch23 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch24 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    bool pass = true;
                                                    soulng::parser::Match match(false);
                                                    if (*lexer == AS)
                                                    {
                                                        ++lexer;
                                                        match.hit = true;
                                                    }
                                                    if (match.hit)
                                                    {
                                                        if (ctx->parsingLvalue || ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                                        else
                                                        {
                                                            op = Operator::as;
                                                            ctx->PushParsingIsOrAs(true);
                                                        }
                                                    }
                                                    if (match.hit && !pass)
                                                    {
                                                        match = soulng::parser::Match(false);
                                                    }
                                                    *parentMatch24 = match;
                                                }
                                                *parentMatch23 = match;
                                            }
                                            if (match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch25 = &match;
                                                {
                                                    soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                                                    asType.reset(static_cast<Node*>(match.value));
                                                    *parentMatch25 = match;
                                                }
                                                *parentMatch23 = match;
                                            }
                                            *parentMatch22 = match;
                                        }
                                        *parentMatch6 = match;
                                    }
                                }
                                *parentMatch5 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch26 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch27 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch28 = &match;
                                        {
                                            int save = lexer.GetPos();
                                            soulng::parser::Match match = ExpressionParser::Shift(lexer, ctx);
                                            right.reset(static_cast<Node*>(match.value));
                                            *parentMatch28 = match;
                                            if (!match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch29 = &match;
                                                lexer.SetPos(save);
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch30 = &match;
                                                    {
                                                        int pos = lexer.GetPos();
                                                        bool pass = true;
                                                        soulng::parser::Match match(true);
                                                        if (match.hit)
                                                        {
                                                            if (!ctx->parsingIsOrAs) pass = false;
                                                        }
                                                        if (match.hit && !pass)
                                                        {
                                                            match = soulng::parser::Match(false);
                                                        }
                                                        *parentMatch30 = match;
                                                    }
                                                    *parentMatch29 = match;
                                                }
                                                *parentMatch28 = match;
                                            }
                                        }
                                        if (match.hit)
                                        {
                                            ctx->PopParsingIsOrAs();
                                            switch (op)
                                            {
                                                case Operator::lessOrEq: s.end = span.end;
                                                expr.reset(new LessOrEqualNode(s, expr.release(), right.release()));
                                                break;
                                                case Operator::greaterOrEq: s.end = span.end;
                                                expr.reset(new GreaterOrEqualNode(s, expr.release(), right.release()));
                                                break;
                                                case Operator::less: s.end = span.end;
                                                expr.reset(new LessNode(s, expr.release(), right.release()));
                                                break;
                                                case Operator::greater: s.end = span.end;
                                                expr.reset(new GreaterNode(s, expr.release(), right.release()));
                                                break;
                                                case Operator::is: s.end = span.end;
                                                expr.reset(new IsNode(s, expr.release(), isType.release()));
                                                break;
                                                case Operator::as: s.end = span.end;
                                                expr.reset(new AsNode(s, expr.release(), asType.release()));
                                                break;
                                            }
                                        }
                                        *parentMatch27 = match;
                                    }
                                    *parentMatch26 = match;
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
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::Shift(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> expr = std::unique_ptr<Node>();
    Span s = Span();
    Operator op = Operator();
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ExpressionParser::Additive(lexer, ctx);
                left.reset(static_cast<Node*>(match.value));
                if (match.hit)
                {
                    s = span;
                    expr.reset(left.release());
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
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        int save = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            bool pass = true;
                                            soulng::parser::Match match(false);
                                            if (*lexer == SHIFTLEFT)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            if (match.hit)
                                            {
                                                if (ctx->parsingLvalue) pass = false;
                                                else op = Operator::shiftLeft;
                                            }
                                            if (match.hit && !pass)
                                            {
                                                match = soulng::parser::Match(false);
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
                                                    bool pass = true;
                                                    soulng::parser::Match match(false);
                                                    if (*lexer == SHIFTRIGHT)
                                                    {
                                                        ++lexer;
                                                        match.hit = true;
                                                    }
                                                    if (match.hit)
                                                    {
                                                        if (ctx->parsingLvalue) pass = false;
                                                        else op = Operator::shiftRight;
                                                    }
                                                    if (match.hit && !pass)
                                                    {
                                                        match = soulng::parser::Match(false);
                                                    }
                                                    *parentMatch10 = match;
                                                }
                                                *parentMatch9 = match;
                                            }
                                            *parentMatch7 = match;
                                        }
                                    }
                                    *parentMatch6 = match;
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
                                            if (match.hit)
                                            {
                                                ctx->BeginParsingArguments();
                                            }
                                            *parentMatch12 = match;
                                        }
                                        *parentMatch11 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                                *parentMatch5 = match;
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
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match(true);
                                        soulng::parser::Match* parentMatch15 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = ExpressionParser::Additive(lexer, ctx);
                                            right.reset(static_cast<Node*>(match.value));
                                            if (match.hit)
                                            {
                                                *parentMatch15 = match;
                                            }
                                            else
                                            {
                                                lexer.ThrowExpectationFailure(pos, U"additive expression");
                                            }
                                        }
                                        if (match.hit)
                                        {
                                            switch (op)
                                            {
                                                case Operator::shiftLeft: s.end = span.end;
                                                expr.reset(new ShiftLeftNode(s, expr.release(), right.release()));
                                                break;
                                                case Operator::shiftRight: s.end = span.end;
                                                expr.reset(new ShiftRightNode(s, expr.release(), right.release()));
                                                break;
                                            }
                                            ctx->EndParsingArguments();
                                        }
                                        else
                                        {
                                            ctx->EndParsingArguments();
                                        }
                                        *parentMatch14 = match;
                                    }
                                    *parentMatch13 = match;
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
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::Additive(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> expr = std::unique_ptr<Node>();
    Span s = Span();
    Operator op = Operator();
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ExpressionParser::Multiplicative(lexer, ctx);
                left.reset(static_cast<Node*>(match.value));
                if (match.hit)
                {
                    s = span;
                    expr.reset(left.release());
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
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    int save = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        bool pass = true;
                                        soulng::parser::Match match(false);
                                        if (*lexer == PLUS)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            if (ctx->parsingLvalue || ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                            else op = Operator::plus;
                                        }
                                        if (match.hit && !pass)
                                        {
                                            match = soulng::parser::Match(false);
                                        }
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
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
                                                bool pass = true;
                                                soulng::parser::Match match(false);
                                                if (*lexer == MINUS)
                                                {
                                                    ++lexer;
                                                    match.hit = true;
                                                }
                                                if (match.hit)
                                                {
                                                    if (ctx->parsingLvalue || ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                                    else op = Operator::minus;
                                                }
                                                if (match.hit && !pass)
                                                {
                                                    match = soulng::parser::Match(false);
                                                }
                                                *parentMatch9 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                        *parentMatch6 = match;
                                    }
                                }
                                *parentMatch5 = match;
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
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match(true);
                                        soulng::parser::Match* parentMatch12 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = ExpressionParser::Multiplicative(lexer, ctx);
                                            right.reset(static_cast<Node*>(match.value));
                                            if (match.hit)
                                            {
                                                *parentMatch12 = match;
                                            }
                                            else
                                            {
                                                lexer.ThrowExpectationFailure(pos, U"multiplicative expression");
                                            }
                                        }
                                        if (match.hit)
                                        {
                                            switch (op)
                                            {
                                                case Operator::plus: s.end = span.end;
                                                expr.reset(new AddNode(s, expr.release(), right.release()));
                                                break;
                                                case Operator::minus: s.end = span.end;
                                                expr.reset(new SubNode(s, expr.release(), right.release()));
                                                break;
                                            }
                                        }
                                        *parentMatch11 = match;
                                    }
                                    *parentMatch10 = match;
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
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::Multiplicative(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> expr = std::unique_ptr<Node>();
    Span s = Span();
    Operator op = Operator();
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ExpressionParser::Prefix(lexer, ctx);
                left.reset(static_cast<Node*>(match.value));
                if (match.hit)
                {
                    s = span;
                    expr.reset(left.release());
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
                                            bool pass = true;
                                            soulng::parser::Match match(false);
                                            if (*lexer == STAR)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            if (match.hit)
                                            {
                                                if (ctx->parsingLvalue || ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                                else op = Operator::mul;
                                            }
                                            if (match.hit && !pass)
                                            {
                                                match = soulng::parser::Match(false);
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
                                                    bool pass = true;
                                                    soulng::parser::Match match(false);
                                                    if (*lexer == DIV)
                                                    {
                                                        ++lexer;
                                                        match.hit = true;
                                                    }
                                                    if (match.hit)
                                                    {
                                                        if (ctx->parsingLvalue || ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                                        else op = Operator::div;
                                                    }
                                                    if (match.hit && !pass)
                                                    {
                                                        match = soulng::parser::Match(false);
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
                                                bool pass = true;
                                                soulng::parser::Match match(false);
                                                if (*lexer == REM)
                                                {
                                                    ++lexer;
                                                    match.hit = true;
                                                }
                                                if (match.hit)
                                                {
                                                    if (ctx->parsingLvalue || ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                                    else op = Operator::rem;
                                                }
                                                if (match.hit && !pass)
                                                {
                                                    match = soulng::parser::Match(false);
                                                }
                                                *parentMatch12 = match;
                                            }
                                            *parentMatch11 = match;
                                        }
                                        *parentMatch6 = match;
                                    }
                                }
                                *parentMatch5 = match;
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
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match(true);
                                        soulng::parser::Match* parentMatch15 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = ExpressionParser::Prefix(lexer, ctx);
                                            right.reset(static_cast<Node*>(match.value));
                                            if (match.hit)
                                            {
                                                *parentMatch15 = match;
                                            }
                                            else
                                            {
                                                lexer.ThrowExpectationFailure(pos, U"prefix expression");
                                            }
                                        }
                                        if (match.hit)
                                        {
                                            switch (op)
                                            {
                                                case Operator::mul: s.end = span.end;
                                                expr.reset(new MulNode(s, expr.release(), right.release()));
                                                break;
                                                case Operator::div: s.end = span.end;
                                                expr.reset(new DivNode(s, expr.release(), right.release()));
                                                break;
                                                case Operator::rem: s.end = span.end;
                                                expr.reset(new RemNode(s, expr.release(), right.release()));
                                                break;
                                            }
                                        }
                                        *parentMatch14 = match;
                                    }
                                    *parentMatch13 = match;
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
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::Prefix(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> prefix = std::unique_ptr<Node>();
    Span s = Span();
    Operator op = Operator();
    std::unique_ptr<Node> p;
    std::unique_ptr<Node> postfix;
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
                                            int pos = lexer.GetPos();
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
                                                op = Operator::plusplus;
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
                                                        op = Operator::minusminus;
                                                    }
                                                    *parentMatch11 = match;
                                                }
                                                *parentMatch10 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                    }
                                    *parentMatch7 = match;
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
                                                bool pass = true;
                                                soulng::parser::Match match(false);
                                                if (*lexer == PLUS)
                                                {
                                                    ++lexer;
                                                    match.hit = true;
                                                }
                                                if (match.hit)
                                                {
                                                    if (ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                                    else
                                                    {
                                                        s = span;
                                                        op = Operator::plus;
                                                    }
                                                }
                                                if (match.hit && !pass)
                                                {
                                                    match = soulng::parser::Match(false);
                                                }
                                                *parentMatch13 = match;
                                            }
                                            *parentMatch12 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                }
                                *parentMatch6 = match;
                                if (!match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch14 = &match;
                                    lexer.SetPos(save);
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch15 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::lexer::Span span = lexer.GetSpan();
                                            bool pass = true;
                                            soulng::parser::Match match(false);
                                            if (*lexer == MINUS)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            if (match.hit)
                                            {
                                                if (ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                                else
                                                {
                                                    s = span;
                                                    op = Operator::minus;
                                                }
                                            }
                                            if (match.hit && !pass)
                                            {
                                                match = soulng::parser::Match(false);
                                            }
                                            *parentMatch15 = match;
                                        }
                                        *parentMatch14 = match;
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
                                        int pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        bool pass = true;
                                        soulng::parser::Match match(false);
                                        if (*lexer == EXCLAMATION)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            if (ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                            else
                                            {
                                                s = span;
                                                op = Operator::not_;
                                            }
                                        }
                                        if (match.hit && !pass)
                                        {
                                            match = soulng::parser::Match(false);
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
                            soulng::parser::Match* parentMatch18 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch19 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::lexer::Span span = lexer.GetSpan();
                                    bool pass = true;
                                    soulng::parser::Match match(false);
                                    if (*lexer == CPL)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        if (ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                        else
                                        {
                                            s = span;
                                            op = Operator::complement;
                                        }
                                    }
                                    if (match.hit && !pass)
                                    {
                                        match = soulng::parser::Match(false);
                                    }
                                    *parentMatch19 = match;
                                }
                                *parentMatch18 = match;
                            }
                            *parentMatch4 = match;
                        }
                    }
                    *parentMatch3 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch20 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch21 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                bool pass = true;
                                soulng::parser::Match match(false);
                                if (*lexer == STAR)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    if (ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                    else
                                    {
                                        s = span;
                                        op = Operator::deref;
                                    }
                                }
                                if (match.hit && !pass)
                                {
                                    match = soulng::parser::Match(false);
                                }
                                *parentMatch21 = match;
                            }
                            *parentMatch20 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch22 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch23 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::lexer::Span span = lexer.GetSpan();
                            bool pass = true;
                            soulng::parser::Match match(false);
                            if (*lexer == AMP)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                if (ctx->parsingExpressionStatement && !ctx->parsingArguments) pass = false;
                                else
                                {
                                    s = span;
                                    op = Operator::addrOf;
                                }
                            }
                            if (match.hit && !pass)
                            {
                                match = soulng::parser::Match(false);
                            }
                            *parentMatch23 = match;
                        }
                        *parentMatch22 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch24 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch25 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = ExpressionParser::Prefix(lexer, ctx);
                    p.reset(static_cast<Node*>(match.value));
                    if (match.hit)
                    {
                        prefix.reset(p.release());
                        s.end = span.end;
                        switch (op)
                        {
                            case Operator::plusplus: return soulng::parser::Match(true, new PrefixIncrementNode(s, prefix.release()));
                            case Operator::minusminus: return soulng::parser::Match(true, new PrefixDecrementNode(s, prefix.release()));
                            case Operator::plus: return soulng::parser::Match(true, new UnaryPlusNode(s, prefix.release()));
                            case Operator::minus: return soulng::parser::Match(true, new UnaryMinusNode(s, prefix.release()));
                            case Operator::not_: return soulng::parser::Match(true, new NotNode(s, prefix.release()));
                            case Operator::complement: return soulng::parser::Match(true, new ComplementNode(s, prefix.release()));
                            case Operator::deref: return soulng::parser::Match(true, new DerefNode(s, prefix.release()));
                            case Operator::addrOf: return soulng::parser::Match(true, new AddrOfNode(s, prefix.release()));
                        }
                    }
                    *parentMatch25 = match;
                }
                *parentMatch24 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch26 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch27 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ExpressionParser::Postfix(lexer, ctx);
                    postfix.reset(static_cast<Node*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, postfix.release());
                    }
                    *parentMatch27 = match;
                }
                *parentMatch26 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match ExpressionParser::Postfix(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> expr = std::unique_ptr<Node>();
    Span s = Span();
    std::unique_ptr<Node> primary;
    std::unique_ptr<IdentifierNode> dotMember;
    std::unique_ptr<IdentifierNode> arrowMember;
    std::unique_ptr<Node> index;
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ExpressionParser::Primary(lexer, ctx);
                primary.reset(static_cast<Node*>(match.value));
                if (match.hit)
                {
                    s = span;
                    expr.reset(primary.release());
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
                                                        expr.reset(new PostfixIncrementNode(s, expr.release()));
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
                                                                expr.reset(new PostfixDecrementNode(s, expr.release()));
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
                                                        if (*lexer == DOT)
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
                                                                soulng::lexer::Span span = lexer.GetSpan();
                                                                soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                                                dotMember.reset(static_cast<IdentifierNode*>(match.value));
                                                                if (match.hit)
                                                                {
                                                                    s.end = span.end;
                                                                    expr.reset(new DotNode(s, expr.release(), dotMember.release()));
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
                                            soulng::parser::Match* parentMatch17 = &match;
                                            lexer.SetPos(save);
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch18 = &match;
                                                {
                                                    soulng::parser::Match match(false);
                                                    if (*lexer == ARROW)
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
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch20 = &match;
                                                        {
                                                            int pos = lexer.GetPos();
                                                            soulng::lexer::Span span = lexer.GetSpan();
                                                            soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                                            arrowMember.reset(static_cast<IdentifierNode*>(match.value));
                                                            if (match.hit)
                                                            {
                                                                s.end = span.end;
                                                                expr.reset(new ArrowNode(s, expr.release(), arrowMember.release()));
                                                            }
                                                            *parentMatch20 = match;
                                                        }
                                                        *parentMatch19 = match;
                                                    }
                                                    *parentMatch18 = match;
                                                }
                                                *parentMatch17 = match;
                                            }
                                            *parentMatch7 = match;
                                        }
                                    }
                                    *parentMatch6 = match;
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
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch24 = &match;
                                                    {
                                                        int pos = lexer.GetPos();
                                                        soulng::parser::Match match(false);
                                                        if (*lexer == LBRACKET)
                                                        {
                                                            ++lexer;
                                                            match.hit = true;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            ctx->PushParsingLvalue(false);
                                                            ctx->PushParsingExpressionStatement(false);
                                                        }
                                                        *parentMatch24 = match;
                                                    }
                                                    *parentMatch23 = match;
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
                                                            soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                                                            index.reset(static_cast<Node*>(match.value));
                                                            if (match.hit)
                                                            {
                                                                ctx->PopParsingExpressionStatement();
                                                                ctx->PopParsingLvalue();
                                                            }
                                                            *parentMatch26 = match;
                                                        }
                                                        *parentMatch25 = match;
                                                    }
                                                    *parentMatch23 = match;
                                                }
                                                *parentMatch22 = match;
                                            }
                                            if (match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch27 = &match;
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch28 = &match;
                                                    {
                                                        int pos = lexer.GetPos();
                                                        soulng::lexer::Span span = lexer.GetSpan();
                                                        soulng::parser::Match match(true);
                                                        soulng::parser::Match* parentMatch29 = &match;
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
                                                                *parentMatch29 = match;
                                                            }
                                                            else
                                                            {
                                                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RBRACKET)));
                                                            }
                                                        }
                                                        if (match.hit)
                                                        {
                                                            s.end = span.end;
                                                            expr.reset(new IndexingNode(s, expr.release(), index.release()));
                                                        }
                                                        *parentMatch28 = match;
                                                    }
                                                    *parentMatch27 = match;
                                                }
                                                *parentMatch22 = match;
                                            }
                                            *parentMatch21 = match;
                                        }
                                        *parentMatch6 = match;
                                    }
                                }
                                *parentMatch5 = match;
                                if (!match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch30 = &match;
                                    lexer.SetPos(save);
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch31 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch32 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch33 = &match;
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
                                                        expr.reset(new InvokeNode(s, expr.release()));
                                                    }
                                                    *parentMatch33 = match;
                                                }
                                                *parentMatch32 = match;
                                            }
                                            if (match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch34 = &match;
                                                {
                                                    soulng::parser::Match match = ExpressionParser::ArgumentList(lexer, ctx, expr.get());
                                                    *parentMatch34 = match;
                                                }
                                                *parentMatch32 = match;
                                            }
                                            *parentMatch31 = match;
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
                                                    soulng::lexer::Span span = lexer.GetSpan();
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
                                                        expr->SetSpanEnd(span.end);
                                                    }
                                                    *parentMatch36 = match;
                                                }
                                                *parentMatch35 = match;
                                            }
                                            *parentMatch31 = match;
                                        }
                                        *parentMatch30 = match;
                                    }
                                    *parentMatch5 = match;
                                }
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
        if (match.hit)
        {
            return soulng::parser::Match(true, expr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::Primary(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<Node> expr;
    std::unique_ptr<LiteralNode> literal;
    std::unique_ptr<Node> basicType;
    std::unique_ptr<Node> templateId;
    std::unique_ptr<IdentifierNode> id;
    std::unique_ptr<Node> sizeOf;
    std::unique_ptr<Node> typeName;
    std::unique_ptr<Node> typeId;
    std::unique_ptr<Node> cast;
    std::unique_ptr<Node> construct;
    std::unique_ptr<Node> newExpr;
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
                                                        int pos = lexer.GetPos();
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
                                                                    *parentMatch15 = match;
                                                                }
                                                                *parentMatch14 = match;
                                                            }
                                                            if (match.hit)
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch16 = &match;
                                                                {
                                                                    soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                                                                    expr.reset(static_cast<Node*>(match.value));
                                                                    *parentMatch16 = match;
                                                                }
                                                                *parentMatch14 = match;
                                                            }
                                                            *parentMatch13 = match;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch17 = &match;
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch18 = &match;
                                                                {
                                                                    int pos = lexer.GetPos();
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
                                                                    *parentMatch18 = match;
                                                                }
                                                                *parentMatch17 = match;
                                                            }
                                                            *parentMatch13 = match;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            return soulng::parser::Match(true, new ParenthesizedExpressionNode(s, expr.release()));
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
                                                                int pos = lexer.GetPos();
                                                                soulng::parser::Match match = LiteralParser::Literal(lexer, ctx);
                                                                literal.reset(static_cast<LiteralNode*>(match.value));
                                                                if (match.hit)
                                                                {
                                                                    return soulng::parser::Match(true, literal.release());
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
                                                    soulng::parser::Match* parentMatch21 = &match;
                                                    lexer.SetPos(save);
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch22 = &match;
                                                        {
                                                            int pos = lexer.GetPos();
                                                            soulng::parser::Match match = BasicTypeParser::BasicType(lexer);
                                                            basicType.reset(static_cast<Node*>(match.value));
                                                            if (match.hit)
                                                            {
                                                                return soulng::parser::Match(true, basicType.release());
                                                            }
                                                            *parentMatch22 = match;
                                                        }
                                                        *parentMatch21 = match;
                                                    }
                                                    *parentMatch10 = match;
                                                }
                                            }
                                            *parentMatch9 = match;
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
                                                        soulng::parser::Match match = TemplateParser::TemplateId(lexer, ctx);
                                                        templateId.reset(static_cast<Node*>(match.value));
                                                        if (match.hit)
                                                        {
                                                            return soulng::parser::Match(true, templateId.release());
                                                        }
                                                        *parentMatch24 = match;
                                                    }
                                                    *parentMatch23 = match;
                                                }
                                                *parentMatch9 = match;
                                            }
                                        }
                                        *parentMatch8 = match;
                                        if (!match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch25 = &match;
                                            lexer.SetPos(save);
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch26 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                                    id.reset(static_cast<IdentifierNode*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        return soulng::parser::Match(true, id.release());
                                                    }
                                                    *parentMatch26 = match;
                                                }
                                                *parentMatch25 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                    }
                                    *parentMatch7 = match;
                                    if (!match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch27 = &match;
                                        lexer.SetPos(save);
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch28 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                soulng::parser::Match match(false);
                                                if (*lexer == THIS)
                                                {
                                                    ++lexer;
                                                    match.hit = true;
                                                }
                                                if (match.hit)
                                                {
                                                    return soulng::parser::Match(true, new ThisNode(span));
                                                }
                                                *parentMatch28 = match;
                                            }
                                            *parentMatch27 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                }
                                *parentMatch6 = match;
                                if (!match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch29 = &match;
                                    lexer.SetPos(save);
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch30 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::lexer::Span span = lexer.GetSpan();
                                            soulng::parser::Match match(false);
                                            if (*lexer == BASE)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            if (match.hit)
                                            {
                                                return soulng::parser::Match(true, new BaseNode(span));
                                            }
                                            *parentMatch30 = match;
                                        }
                                        *parentMatch29 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                            }
                            *parentMatch5 = match;
                            if (!match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch31 = &match;
                                lexer.SetPos(save);
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch32 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match = ExpressionParser::SizeOfExpr(lexer, ctx);
                                        sizeOf.reset(static_cast<Node*>(match.value));
                                        if (match.hit)
                                        {
                                            return soulng::parser::Match(true, sizeOf.release());
                                        }
                                        *parentMatch32 = match;
                                    }
                                    *parentMatch31 = match;
                                }
                                *parentMatch5 = match;
                            }
                        }
                        *parentMatch4 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch33 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch34 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = ExpressionParser::TypeNameExpr(lexer, ctx);
                                    typeName.reset(static_cast<Node*>(match.value));
                                    if (match.hit)
                                    {
                                        return soulng::parser::Match(true, typeName.release());
                                    }
                                    *parentMatch34 = match;
                                }
                                *parentMatch33 = match;
                            }
                            *parentMatch4 = match;
                        }
                    }
                    *parentMatch3 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch35 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch36 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = ExpressionParser::TypeIdExpr(lexer, ctx);
                                typeId.reset(static_cast<Node*>(match.value));
                                if (match.hit)
                                {
                                    return soulng::parser::Match(true, typeId.release());
                                }
                                *parentMatch36 = match;
                            }
                            *parentMatch35 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
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
                            soulng::parser::Match match = ExpressionParser::CastExpr(lexer, ctx);
                            cast.reset(static_cast<Node*>(match.value));
                            if (match.hit)
                            {
                                return soulng::parser::Match(true, cast.release());
                            }
                            *parentMatch38 = match;
                        }
                        *parentMatch37 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
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
                        soulng::parser::Match match = ExpressionParser::ConstructExpr(lexer, ctx);
                        construct.reset(static_cast<Node*>(match.value));
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, construct.release());
                        }
                        *parentMatch40 = match;
                    }
                    *parentMatch39 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch41 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch42 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ExpressionParser::NewExpr(lexer, ctx);
                    newExpr.reset(static_cast<Node*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, newExpr.release());
                    }
                    *parentMatch42 = match;
                }
                *parentMatch41 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match ExpressionParser::SizeOfExpr(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<Node> expr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::lexer::Span span = lexer.GetSpan();
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
                        int pos = lexer.GetPos();
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
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == LPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                *parentMatch6 = match;
                            }
                            else
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                            }
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
                soulng::parser::Match* parentMatch7 = &match;
                {
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch8 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                        expr.reset(static_cast<Node*>(match.value));
                        if (match.hit)
                        {
                            *parentMatch8 = match;
                        }
                        else
                        {
                            lexer.ThrowExpectationFailure(pos, U"expression");
                        }
                    }
                    *parentMatch7 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch9 = &match;
            {
                soulng::parser::Match match(true);
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
                        *parentMatch10 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                    }
                }
                *parentMatch9 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            s.end = span.end;
            return soulng::parser::Match(true, new SizeOfNode(s, expr.release()));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::TypeNameExpr(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<Node> expr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::lexer::Span span = lexer.GetSpan();
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
                        int pos = lexer.GetPos();
                        soulng::lexer::Span span = lexer.GetSpan();
                        soulng::parser::Match match(false);
                        if (*lexer == TYPENAME)
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
                        soulng::parser::Match match(true);
                        soulng::parser::Match* parentMatch6 = &match;
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
                                *parentMatch6 = match;
                            }
                            else
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                            }
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
                soulng::parser::Match* parentMatch7 = &match;
                {
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch8 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                        expr.reset(static_cast<Node*>(match.value));
                        if (match.hit)
                        {
                            *parentMatch8 = match;
                        }
                        else
                        {
                            lexer.ThrowExpectationFailure(pos, U"expression");
                        }
                    }
                    *parentMatch7 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch9 = &match;
            {
                soulng::parser::Match match(true);
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
                        *parentMatch10 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                    }
                }
                *parentMatch9 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            s.end = span.end;
            return soulng::parser::Match(true, new TypeNameNode(s, expr.release()));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::TypeIdExpr(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<Node> expr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::lexer::Span span = lexer.GetSpan();
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
                        int pos = lexer.GetPos();
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
                        soulng::parser::Match match(true);
                        soulng::parser::Match* parentMatch6 = &match;
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
                                *parentMatch6 = match;
                            }
                            else
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                            }
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
                soulng::parser::Match* parentMatch7 = &match;
                {
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch8 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                        expr.reset(static_cast<Node*>(match.value));
                        if (match.hit)
                        {
                            *parentMatch8 = match;
                        }
                        else
                        {
                            lexer.ThrowExpectationFailure(pos, U"expression");
                        }
                    }
                    *parentMatch7 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch9 = &match;
            {
                soulng::parser::Match match(true);
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
                        *parentMatch10 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                    }
                }
                *parentMatch9 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            s.end = span.end;
            return soulng::parser::Match(true, new TypeIdNode(s, expr.release()));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::CastExpr(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<Node> typeExpr;
    std::unique_ptr<Node> expr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::lexer::Span span = lexer.GetSpan();
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
                                    int pos = lexer.GetPos();
                                    soulng::lexer::Span span = lexer.GetSpan();
                                    soulng::parser::Match match(false);
                                    if (*lexer == CAST)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        s = span;
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
                                    soulng::parser::Match* parentMatch9 = &match;
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
                                            *parentMatch9 = match;
                                        }
                                        else
                                        {
                                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LANGLE)));
                                        }
                                    }
                                    *parentMatch8 = match;
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
                                soulng::parser::Match* parentMatch11 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                                    typeExpr.reset(static_cast<Node*>(match.value));
                                    if (match.hit)
                                    {
                                        *parentMatch11 = match;
                                    }
                                    else
                                    {
                                        lexer.ThrowExpectationFailure(pos, U"type expression");
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
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch12 = &match;
                        {
                            soulng::parser::Match match(true);
                            soulng::parser::Match* parentMatch13 = &match;
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
                                    *parentMatch13 = match;
                                }
                                else
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RANGLE)));
                                }
                            }
                            *parentMatch12 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch14 = &match;
                    {
                        soulng::parser::Match match(true);
                        soulng::parser::Match* parentMatch15 = &match;
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
                                *parentMatch15 = match;
                            }
                            else
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                            }
                        }
                        *parentMatch14 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch16 = &match;
                {
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch17 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                        expr.reset(static_cast<Node*>(match.value));
                        if (match.hit)
                        {
                            *parentMatch17 = match;
                        }
                        else
                        {
                            lexer.ThrowExpectationFailure(pos, U"expression");
                        }
                    }
                    *parentMatch16 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch18 = &match;
            {
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch19 = &match;
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
                        *parentMatch19 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                    }
                }
                *parentMatch18 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            s.end = span.end;
            return soulng::parser::Match(true, new CastNode(s, typeExpr.release(), expr.release()));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::ConstructExpr(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> expr = std::unique_ptr<Node>();
    Span s = Span();
    std::unique_ptr<Node> typeExpr;
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
                                    int pos = lexer.GetPos();
                                    soulng::lexer::Span span = lexer.GetSpan();
                                    soulng::parser::Match match(false);
                                    if (*lexer == CONSTRUCT)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        s = span;
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
                                    soulng::parser::Match* parentMatch9 = &match;
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
                                            *parentMatch9 = match;
                                        }
                                        else
                                        {
                                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LANGLE)));
                                        }
                                    }
                                    *parentMatch8 = match;
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
                                soulng::parser::Match* parentMatch11 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                                    typeExpr.reset(static_cast<Node*>(match.value));
                                    if (match.hit)
                                    {
                                        *parentMatch11 = match;
                                    }
                                    else
                                    {
                                        lexer.ThrowExpectationFailure(pos, U"type expression");
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
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch12 = &match;
                        {
                            soulng::parser::Match match(true);
                            soulng::parser::Match* parentMatch13 = &match;
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
                                    *parentMatch13 = match;
                                }
                                else
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RANGLE)));
                                }
                            }
                            *parentMatch12 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        expr.reset(new ConstructNode(s, typeExpr.release()));
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch14 = &match;
                {
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch15 = &match;
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
                            *parentMatch15 = match;
                        }
                        else
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                        }
                    }
                    *parentMatch14 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch16 = &match;
            {
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch17 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ExpressionParser::ExpressionList(lexer, ctx, expr.get());
                    if (match.hit)
                    {
                        *parentMatch17 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, U"expression list");
                    }
                }
                *parentMatch16 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch18 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch19 = &match;
            {
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch20 = &match;
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
                        *parentMatch20 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                    }
                }
                if (match.hit)
                {
                    expr->SetSpanEnd(span.end);
                    return soulng::parser::Match(true, expr.release());
                }
                *parentMatch19 = match;
            }
            *parentMatch18 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::NewExpr(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> expr = std::unique_ptr<Node>();
    Span s = Span();
    std::unique_ptr<Node> typeExpr;
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
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::lexer::Span span = lexer.GetSpan();
                        soulng::parser::Match match(true);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                            typeExpr.reset(static_cast<Node*>(match.value));
                            if (match.hit)
                            {
                                *parentMatch6 = match;
                            }
                            else
                            {
                                lexer.ThrowExpectationFailure(pos, U"type expression");
                            }
                        }
                        if (match.hit)
                        {
                            s.end = span.end;
                            expr.reset(new NewNode(s, typeExpr.release()));
                        }
                        *parentMatch5 = match;
                    }
                    *parentMatch4 = match;
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
                soulng::parser::Match match(true);
                int save = lexer.GetPos();
                soulng::parser::Match* parentMatch8 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch9 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch10 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == LPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch10 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch11 = &match;
                            {
                                soulng::parser::Match match = ExpressionParser::ArgumentList(lexer, ctx, expr.get());
                                *parentMatch11 = match;
                            }
                            *parentMatch10 = match;
                        }
                        *parentMatch9 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch12 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch13 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match(false);
                                if (*lexer == RPAREN)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    expr->SetSpanEnd(span.end);
                                }
                                *parentMatch13 = match;
                            }
                            *parentMatch12 = match;
                        }
                        *parentMatch9 = match;
                    }
                    if (match.hit)
                    {
                        *parentMatch8 = match;
                    }
                    else
                    {
                        lexer.SetPos(save);
                    }
                }
                *parentMatch7 = match;
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

soulng::parser::Match ExpressionParser::ArgumentList(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::Node* node)
{
    soulng::parser::Match match(true);
    int save = lexer.GetPos();
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match = ExpressionParser::ExpressionList(lexer, ctx, node);
        if (match.hit)
        {
            *parentMatch0 = match;
        }
        else
        {
            lexer.SetPos(save);
        }
    }
    return match;
}

soulng::parser::Match ExpressionParser::ExpressionList(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::Node* node)
{
    std::unique_ptr<Node> arg;
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
                ctx->BeginParsingArguments();
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
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                        arg.reset(static_cast<Node*>(match.value));
                        if (match.hit)
                        {
                            node->AddArgument(arg.release());
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
                        soulng::parser::Match* parentMatch7 = &match;
                        {
                            while (true)
                            {
                                int save = lexer.GetPos();
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == COMMA)
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
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch10 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                                                arg.reset(static_cast<Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    node->AddArgument(arg.release());
                                                }
                                                *parentMatch10 = match;
                                            }
                                            *parentMatch9 = match;
                                        }
                                        *parentMatch8 = match;
                                    }
                                    if (match.hit)
                                    {
                                        *parentMatch7 = match;
                                    }
                                    else
                                    {
                                        lexer.SetPos(save);
                                        break;
                                    }
                                }
                            }
                        }
                        *parentMatch6 = match;
                    }
                    *parentMatch4 = match;
                }
                if (match.hit)
                {
                    ctx->EndParsingArguments();
                }
                else
                {
                    ctx->EndParsingArguments();
                }
                *parentMatch3 = match;
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::InvokeExpr(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> expr = std::unique_ptr<Node>();
    Span s = Span();
    std::unique_ptr<Node> templateId;
    std::unique_ptr<IdentifierNode> id;
    std::unique_ptr<IdentifierNode> dotMemberId;
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
                            int save = lexer.GetPos();
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match = TemplateParser::TemplateId(lexer, ctx);
                                templateId.reset(static_cast<Node*>(match.value));
                                if (match.hit)
                                {
                                    s = span;
                                    expr.reset(templateId.release());
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                            if (!match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                lexer.SetPos(save);
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                        id.reset(static_cast<IdentifierNode*>(match.value));
                                        if (match.hit)
                                        {
                                            s = span;
                                            expr.reset(id.release());
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch5 = match;
                            }
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch9 = &match;
                        {
                            soulng::parser::Match match(true);
                            soulng::parser::Match* parentMatch10 = &match;
                            {
                                while (true)
                                {
                                    int save = lexer.GetPos();
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch11 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            if (*lexer == DOT)
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
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch13 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::lexer::Span span = lexer.GetSpan();
                                                    soulng::parser::Match match(true);
                                                    soulng::parser::Match* parentMatch14 = &match;
                                                    {
                                                        int pos = lexer.GetPos();
                                                        soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                                        dotMemberId.reset(static_cast<IdentifierNode*>(match.value));
                                                        if (match.hit)
                                                        {
                                                            *parentMatch14 = match;
                                                        }
                                                        else
                                                        {
                                                            lexer.ThrowExpectationFailure(pos, U"identifier");
                                                        }
                                                    }
                                                    if (match.hit)
                                                    {
                                                        s.end = span.end;
                                                        expr.reset(new DotNode(s, expr.release(), dotMemberId.release()));
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
                                            break;
                                        }
                                    }
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
                    soulng::parser::Match* parentMatch15 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch16 = &match;
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
                                expr.reset(new InvokeNode(s, expr.release()));
                            }
                            *parentMatch16 = match;
                        }
                        *parentMatch15 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch17 = &match;
                {
                    soulng::parser::Match match = ExpressionParser::ArgumentList(lexer, ctx, expr.get());
                    *parentMatch17 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch18 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch19 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch20 = &match;
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
                            *parentMatch20 = match;
                        }
                        else
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                        }
                    }
                    if (match.hit)
                    {
                        expr->SetSpanEnd(span.end);
                    }
                    *parentMatch19 = match;
                }
                *parentMatch18 = match;
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
