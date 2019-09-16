#include "TypeExpr.hpp"
#include <soulng/util/Unicode.hpp>
#include <cmajor/parser/BasicType.hpp>
#include <cmajor/parser/Expression.hpp>
#include <cmajor/parser/Template.hpp>
#include <cmajor/lexer/CmajorLexer.hpp>
#include <cmajor/lexer/CmajorTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/TypeExpr.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace cmajor::ast;
using namespace CmajorTokens;

soulng::parser::Match TypeExprParser::TypeExpr(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> prefixTypeExpr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match = TypeExprParser::PrefixTypeExpr(lexer, ctx);
        prefixTypeExpr.reset(static_cast<Node*>(match.value));
        if (match.hit)
        {
            return soulng::parser::Match(true, prefixTypeExpr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match TypeExprParser::PrefixTypeExpr(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<Node> constTypeExpr;
    std::unique_ptr<Node> postfixTypeExpr;
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                if (*lexer == CONST)
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
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = TypeExprParser::PostfixTypeExpr(lexer, ctx);
                    constTypeExpr.reset(static_cast<Node*>(match.value));
                    if (match.hit)
                    {
                        s.end = span.end;
                        return soulng::parser::Match(true, new ConstNode(s, constTypeExpr.release()));
                    }
                    *parentMatch4 = match;
                }
                *parentMatch3 = match;
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
                    soulng::parser::Match match = TypeExprParser::PostfixTypeExpr(lexer, ctx);
                    postfixTypeExpr.reset(static_cast<Node*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, postfixTypeExpr.release());
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

soulng::parser::Match TypeExprParser::PostfixTypeExpr(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> typeExpr = std::unique_ptr<Node>();
    Span s = Span();
    std::unique_ptr<Node> primaryTypeExpr;
    std::unique_ptr<Node> size;
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
                soulng::parser::Match match = TypeExprParser::PrimaryTypeExpr(lexer, ctx);
                primaryTypeExpr.reset(static_cast<Node*>(match.value));
                if (match.hit)
                {
                    s = span;
                    typeExpr.reset(primaryTypeExpr.release());
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
                                                soulng::parser::Match match(false);
                                                if (*lexer == DOT)
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
                                                        soulng::lexer::Span span = lexer.GetSpan();
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
                                                            s.end = span.end;
                                                            typeExpr.reset(new DotNode(s, typeExpr.release(), new IdentifierNode(span, lexer.GetToken(pos))));
                                                        }
                                                        *parentMatch11 = match;
                                                    }
                                                    *parentMatch10 = match;
                                                }
                                                *parentMatch9 = match;
                                            }
                                            *parentMatch8 = match;
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
                                                        soulng::parser::Match match(false);
                                                        if (*lexer == STAR)
                                                        {
                                                            ++lexer;
                                                            match.hit = true;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            s.end = span.end;
                                                            typeExpr.reset(new PointerNode(s, typeExpr.release()));
                                                        }
                                                        *parentMatch13 = match;
                                                    }
                                                    *parentMatch12 = match;
                                                }
                                                *parentMatch8 = match;
                                            }
                                        }
                                        *parentMatch7 = match;
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
                                                    soulng::parser::Match match(false);
                                                    if (*lexer == AMPAMP)
                                                    {
                                                        ++lexer;
                                                        match.hit = true;
                                                    }
                                                    if (match.hit)
                                                    {
                                                        s.end = span.end;
                                                        typeExpr.reset(new RValueRefNode(s, typeExpr.release()));
                                                    }
                                                    *parentMatch15 = match;
                                                }
                                                *parentMatch14 = match;
                                            }
                                            *parentMatch7 = match;
                                        }
                                    }
                                    *parentMatch6 = match;
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
                                                soulng::parser::Match match(false);
                                                if (*lexer == AMP)
                                                {
                                                    ++lexer;
                                                    match.hit = true;
                                                }
                                                if (match.hit)
                                                {
                                                    s.end = span.end;
                                                    typeExpr.reset(new LValueRefNode(s, typeExpr.release()));
                                                }
                                                *parentMatch17 = match;
                                            }
                                            *parentMatch16 = match;
                                        }
                                        *parentMatch6 = match;
                                    }
                                }
                                *parentMatch5 = match;
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
                                                soulng::parser::Match match(false);
                                                if (*lexer == LBRACKET)
                                                {
                                                    ++lexer;
                                                    match.hit = true;
                                                }
                                                *parentMatch20 = match;
                                            }
                                            if (match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch21 = &match;
                                                {
                                                    soulng::parser::Match match(true);
                                                    int save = lexer.GetPos();
                                                    soulng::parser::Match* parentMatch22 = &match;
                                                    {
                                                        soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                                                        size.reset(static_cast<Node*>(match.value));
                                                        if (match.hit)
                                                        {
                                                            *parentMatch22 = match;
                                                        }
                                                        else
                                                        {
                                                            lexer.SetPos(save);
                                                        }
                                                    }
                                                    *parentMatch21 = match;
                                                }
                                                *parentMatch20 = match;
                                            }
                                            *parentMatch19 = match;
                                        }
                                        if (match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch23 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch24 = &match;
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
                                                        s.end = span.end;
                                                        typeExpr.reset(new ArrayNode(s, typeExpr.release(), size.release()));
                                                    }
                                                    *parentMatch24 = match;
                                                }
                                                *parentMatch23 = match;
                                            }
                                            *parentMatch19 = match;
                                        }
                                        *parentMatch18 = match;
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
            return soulng::parser::Match(true, typeExpr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match TypeExprParser::PrimaryTypeExpr(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> basicType;
    std::unique_ptr<Node> templateId;
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
                soulng::parser::Match match = BasicTypeParser::BasicType(lexer);
                basicType.reset(static_cast<Node*>(match.value));
                if (match.hit)
                {
                    return soulng::parser::Match(true, basicType.release());
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
                        soulng::parser::Match match = TemplateParser::TemplateId(lexer, ctx);
                        templateId.reset(static_cast<Node*>(match.value));
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, templateId.release());
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
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match(false);
                    if (*lexer == ID)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, new IdentifierNode(span, lexer.GetToken(pos)));
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
