#include "Literal.hpp"
#include <soulng/util/Unicode.hpp>
#include <cmajor/parser/Expression.hpp>
#include <cmajor/lexer/CmajorLexer.hpp>
#include <cmajor/lexer/CmajorTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/Literal.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace cmajor::ast;
using namespace CmajorTokens;

soulng::parser::Match LiteralParser::Literal(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<LiteralNode> simpleLiteral;
    std::unique_ptr<LiteralNode> complexLiteral;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match = LiteralParser::SimpleLiteral(lexer);
            simpleLiteral.reset(static_cast<LiteralNode*>(match.value));
            if (match.hit)
            {
                return soulng::parser::Match(true, simpleLiteral.release());
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
                    soulng::parser::Match match = LiteralParser::ComplexLiteral(lexer, ctx);
                    complexLiteral.reset(static_cast<LiteralNode*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, complexLiteral.release());
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

soulng::parser::Match LiteralParser::SimpleLiteral(CmajorLexer& lexer)
{
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case TRUE:
        {
            ++lexer;
            {
                LiteralNode * value = new BooleanLiteralNode(span, true);
                value->SetText(lexer.GetMatch(span));
                return soulng::parser::Match(true, value);
            }
            break;
        }
        case FALSE:
        {
            ++lexer;
            {
                LiteralNode * value = new BooleanLiteralNode(span, false);
                value->SetText(lexer.GetMatch(span));
                return soulng::parser::Match(true, value);
            }
            break;
        }
        case FLOATINGLIT:
        {
            ++lexer;
            {
                ParseFloatingLiteral(lexer.FileName(), lexer.GetToken(pos), lexer.floatingLit, lexer.floatingLitFloat);
                LiteralNode * value = CreateFloatingLiteralNode(span, lexer.floatingLit, lexer.floatingLitFloat);
                value->SetText(lexer.GetMatch(span));
                return soulng::parser::Match(true, value);
            }
            break;
        }
        case INTLIT:
        {
            ++lexer;
            {
                ParseIntegerLiteral(lexer.FileName(), lexer.GetToken(pos), lexer.intLit, lexer.intLitUnsigned);
                LiteralNode * value = CreateIntegerLiteralNode(span, lexer.intLit, lexer.intLitUnsigned);
                value->SetText(lexer.GetMatch(span));
                return soulng::parser::Match(true, value);
            }
            break;
        }
        case CHARLIT:
        {
            ++lexer;
            {
                ParseCharacterLiteral(lexer.FileName(), lexer.GetToken(pos), lexer.chrLit, lexer.chrLitPrefix);
                LiteralNode * value = CreateCharacterLiteralNode(span, lexer.chrLit, lexer.chrLitPrefix);
                value->SetText(lexer.GetMatch(span));
                return soulng::parser::Match(true, value);
            }
            break;
        }
        case STRINGLIT:
        {
            ++lexer;
            {
                ParseStringLiteral(lexer.FileName(), lexer.GetToken(pos), lexer.strLit, lexer.strLitPrefix);
                LiteralNode * value = CreateStringLiteralNode(span, lexer.strLit, lexer.strLitPrefix);
                value->SetText(lexer.GetMatch(span));
                return soulng::parser::Match(true, value);
            }
            break;
        }
        case NULL:
        {
            ++lexer;
            {
                LiteralNode * value = new NullLiteralNode(span);
                value->SetText(lexer.GetMatch(span));
                return soulng::parser::Match(true, value);
            }
            break;
        }
    }
    return match;
}

soulng::parser::Match LiteralParser::ComplexLiteral(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<ArrayLiteralNode> arrayLiteral;
    std::unique_ptr<StructuredLiteralNode> structuredLiteral;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match = LiteralParser::ArrayLiteral(lexer, ctx);
            arrayLiteral.reset(static_cast<ArrayLiteralNode*>(match.value));
            if (match.hit)
            {
                return soulng::parser::Match(true, arrayLiteral.release());
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
                    soulng::parser::Match match = LiteralParser::StructuredLiteral(lexer, ctx);
                    structuredLiteral.reset(static_cast<StructuredLiteralNode*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, structuredLiteral.release());
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

soulng::parser::Match LiteralParser::ArrayLiteral(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<ArrayLiteralNode> arrayLiteral = std::unique_ptr<ArrayLiteralNode>();
    std::unique_ptr<Node> expr;
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
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                if (*lexer == LBRACKET)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    arrayLiteral.reset(new ArrayLiteralNode(span));
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
                            soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                            expr.reset(static_cast<Node*>(match.value));
                            if (match.hit)
                            {
                                arrayLiteral->AddValue(expr.release());
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
                            soulng::parser::Match match(true);
                            soulng::parser::Match* parentMatch8 = &match;
                            {
                                while (true)
                                {
                                    int save = lexer.GetPos();
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            if (*lexer == COMMA)
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
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch11 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                                                    expr.reset(static_cast<Node*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        arrayLiteral->AddValue(expr.release());
                                                    }
                                                    *parentMatch11 = match;
                                                }
                                                *parentMatch10 = match;
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
                                            break;
                                        }
                                    }
                                }
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RBRACKET)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RBRACKET)));
                    }
                }
                if (match.hit)
                {
                    arrayLiteral->SetSpanEnd(span.end);
                    return soulng::parser::Match(true, arrayLiteral.release());
                }
                *parentMatch13 = match;
            }
            *parentMatch12 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match LiteralParser::StructuredLiteral(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<StructuredLiteralNode> structuredLiteral = std::unique_ptr<StructuredLiteralNode>();
    std::unique_ptr<Node> expr;
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
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                if (*lexer == LBRACE)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    structuredLiteral.reset(new StructuredLiteralNode(span));
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
                            soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                            expr.reset(static_cast<Node*>(match.value));
                            if (match.hit)
                            {
                                structuredLiteral->AddMember(expr.release());
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
                            soulng::parser::Match match(true);
                            soulng::parser::Match* parentMatch8 = &match;
                            {
                                while (true)
                                {
                                    int save = lexer.GetPos();
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            if (*lexer == COMMA)
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
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch11 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                                                    expr.reset(static_cast<Node*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        structuredLiteral->AddMember(expr.release());
                                                    }
                                                    *parentMatch11 = match;
                                                }
                                                *parentMatch10 = match;
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
                                            break;
                                        }
                                    }
                                }
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
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
                    structuredLiteral->SetSpanEnd(span.end);
                    return soulng::parser::Match(true, structuredLiteral.release());
                }
                *parentMatch13 = match;
            }
            *parentMatch12 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}
