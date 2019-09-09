#include "Parameter.hpp"
#include <soulng/util/Unicode.hpp>
#include <soulng/cmajorparser/TypeExpr.hpp>
#include <soulng/cmajorparser/Identifier.hpp>
#include <soulng/cmajorlexer/CmajorLexer.hpp>
#include <soulng/cmajorlexer/CmajorTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng/cmajorparser/Parameter.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace cmajor::ast;
using namespace CmajorTokens;

soulng::parser::Match ParameterParser::ParameterList(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::Node* owner)
{
    std::unique_ptr<ParameterNode> param;
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
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = ParameterParser::Parameter(lexer, ctx);
                            param.reset(static_cast<ParameterNode*>(match.value));
                            if (match.hit)
                            {
                                owner->AddParameter(param.release());
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
                                                    soulng::parser::Match match = ParameterParser::Parameter(lexer, ctx);
                                                    param.reset(static_cast<ParameterNode*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        owner->AddParameter(param.release());
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
        soulng::parser::Match* parentMatch11 = &match;
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
            *parentMatch11 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParameterParser::Parameter(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<Node> type;
    std::unique_ptr<IdentifierNode> id;
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
                Span span = lexer.GetSpan();
                soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                type.reset(static_cast<Node*>(match.value));
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
                int save = lexer.GetPos();
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        int pos = lexer.GetPos();
                        Span span = lexer.GetSpan();
                        soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                        id.reset(static_cast<IdentifierNode*>(match.value));
                        if (match.hit)
                        {
                            s.end = span.end;
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
            return soulng::parser::Match(true, new ParameterNode(s, type.release(), id.release()));
        }
        *parentMatch0 = match;
    }
    return match;
}
