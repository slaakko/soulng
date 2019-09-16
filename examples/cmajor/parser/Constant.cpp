#include "Constant.hpp"
#include <soulng/util/Unicode.hpp>
#include <cmajor/parser/Specifier.hpp>
#include <cmajor/parser/TypeExpr.hpp>
#include <cmajor/parser/Identifier.hpp>
#include <cmajor/parser/Expression.hpp>
#include <cmajor/lexer/CmajorLexer.hpp>
#include <cmajor/lexer/CmajorTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/Constant.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace cmajor::ast;
using namespace CmajorTokens;

soulng::parser::Match ConstantParser::Constant(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<soulng::parser::Value<cmajor::ast::Specifiers>> specifiers;
    std::unique_ptr<Node> type;
    std::unique_ptr<IdentifierNode> id;
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
                                soulng::parser::Match match = SpecifierParser::Specifiers(lexer);
                                specifiers.reset(static_cast<soulng::parser::Value<cmajor::ast::Specifiers>*>(match.value));
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
                                if (*lexer == CONST)
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
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                                type.reset(static_cast<Node*>(match.value));
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, U"type expression");
                                }
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
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                            id.reset(static_cast<IdentifierNode*>(match.value));
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, U"identifier");
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
                soulng::parser::Match* parentMatch10 = &match;
                {
                    soulng::parser::Match match(false);
                    if (*lexer == ASSIGN)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch10 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch11 = &match;
            {
                soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                expr.reset(static_cast<Node*>(match.value));
                *parentMatch11 = match;
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
                soulng::parser::Match match(false);
                if (*lexer == SEMICOLON)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    s.end = span.end;
                    ConstantNode * value = new ConstantNode(s, specifiers->value, type.release(), id.release(), expr.release());
                    value->SetStrValue(lexer.GetMatch(s));
                    return soulng::parser::Match(true, value);
                }
                *parentMatch13 = match;
            }
            *parentMatch12 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}
