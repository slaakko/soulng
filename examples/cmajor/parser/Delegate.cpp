#include "Delegate.hpp"
#include <soulng/util/Unicode.hpp>
#include <cmajor/parser/Specifier.hpp>
#include <cmajor/parser/TypeExpr.hpp>
#include <cmajor/parser/Identifier.hpp>
#include <cmajor/parser/Parameter.hpp>
#include <cmajor/lexer/CmajorLexer.hpp>
#include <cmajor/lexer/CmajorTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/Delegate.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace cmajor::ast;
using namespace CmajorTokens;

soulng::parser::Match DelegateParser::Delegate(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<DelegateNode> dlg = std::unique_ptr<DelegateNode>();
    std::unique_ptr<soulng::parser::Value<cmajor::ast::Specifiers>> specifiers;
    std::unique_ptr<Node> type;
    std::unique_ptr<IdentifierNode> id;
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
                            int pos = lexer.GetPos();
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match = SpecifierParser::Specifiers(lexer);
                            specifiers.reset(static_cast<soulng::parser::Value<cmajor::ast::Specifiers>*>(match.value));
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
                            if (*lexer == DELEGATE)
                            {
                                ++lexer;
                                match.hit = true;
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
                    soulng::parser::Match* parentMatch7 = &match;
                    {
                        soulng::parser::Match match(true);
                        soulng::parser::Match* parentMatch8 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                            type.reset(static_cast<Node*>(match.value));
                            if (match.hit)
                            {
                                *parentMatch8 = match;
                            }
                            else
                            {
                                lexer.ThrowExpectationFailure(pos, U"type expression");
                            }
                        }
                        *parentMatch7 = match;
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
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch10 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(true);
                        soulng::parser::Match* parentMatch11 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                            id.reset(static_cast<IdentifierNode*>(match.value));
                            if (match.hit)
                            {
                                *parentMatch11 = match;
                            }
                            else
                            {
                                lexer.ThrowExpectationFailure(pos, U"identifier");
                            }
                        }
                        if (match.hit)
                        {
                            dlg.reset(new DelegateNode(s, specifiers->value, type.release(), id.release()));
                        }
                        *parentMatch10 = match;
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
            soulng::parser::Match* parentMatch12 = &match;
            {
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch13 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ParameterParser::ParameterList(lexer, ctx, dlg.get());
                    if (match.hit)
                    {
                        *parentMatch13 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, U"parameter list");
                    }
                }
                *parentMatch12 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
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
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch16 = &match;
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
                        *parentMatch16 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    dlg->SetSpanEnd(span.end);
                    return soulng::parser::Match(true, dlg.release());
                }
                *parentMatch15 = match;
            }
            *parentMatch14 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match DelegateParser::ClassDelegate(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<ClassDelegateNode> clsDlg = std::unique_ptr<ClassDelegateNode>();
    std::unique_ptr<soulng::parser::Value<cmajor::ast::Specifiers>> specifiers;
    std::unique_ptr<Node> type;
    std::unique_ptr<IdentifierNode> id;
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
                                if (*lexer == CLASS)
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
                            if (*lexer == DELEGATE)
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
                        soulng::parser::Match* parentMatch10 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                            type.reset(static_cast<Node*>(match.value));
                            if (match.hit)
                            {
                                *parentMatch10 = match;
                            }
                            else
                            {
                                lexer.ThrowExpectationFailure(pos, U"type expression");
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
                soulng::parser::Match* parentMatch11 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch12 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(true);
                        soulng::parser::Match* parentMatch13 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                            id.reset(static_cast<IdentifierNode*>(match.value));
                            if (match.hit)
                            {
                                *parentMatch13 = match;
                            }
                            else
                            {
                                lexer.ThrowExpectationFailure(pos, U"identifier");
                            }
                        }
                        if (match.hit)
                        {
                            clsDlg.reset(new ClassDelegateNode(s, specifiers->value, type.release(), id.release()));
                        }
                        *parentMatch12 = match;
                    }
                    *parentMatch11 = match;
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
                soulng::parser::Match* parentMatch15 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ParameterParser::ParameterList(lexer, ctx, clsDlg.get());
                    if (match.hit)
                    {
                        *parentMatch15 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, U"parameter list");
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
        soulng::parser::Match* parentMatch16 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch17 = &match;
            {
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch18 = &match;
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
                        *parentMatch18 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    clsDlg->SetSpanEnd(span.end);
                    return soulng::parser::Match(true, clsDlg.release());
                }
                *parentMatch17 = match;
            }
            *parentMatch16 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}
