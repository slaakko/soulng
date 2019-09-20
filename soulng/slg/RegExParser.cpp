#include "RegExParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <soulng/slg/RegExLexer.hpp>
#include <soulng/slg/RegExTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/soulng/slg/RegExParser.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace soulng::lexer;
using namespace RegExTokens;

soulng::slg::Nfa RegExParser::Parse(RegExLexer& lexer, soulng::slg::LexerContext* lexerContext)
{
    std::unique_ptr<soulng::parser::Value<soulng::slg::Nfa>> value;
    ++lexer;
    int pos = lexer.GetPos();
    soulng::parser::Match match = RegExParser::RegularExpression(lexer, lexerContext);
    value.reset(static_cast<soulng::parser::Value<soulng::slg::Nfa>*>(match.value));
    if (match.hit)
    {
        if (*lexer == soulng::lexer::END)
        {
            return value->value;
        }
        else
        {
            lexer.ThrowExpectationFailure(lexer.GetPos(), ToUtf32(GetTokenInfo(soulng::lexer::END)));
        }
    }
    else
    {
        lexer.ThrowExpectationFailure(pos, U"regular expression");
    }
    return value->value;
}

soulng::parser::Match RegExParser::RegularExpression(RegExLexer& lexer, soulng::slg::LexerContext* lexerContext)
{
    std::unique_ptr<soulng::parser::Value<soulng::slg::Nfa>> alternative;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match = RegExParser::Alternative(lexer, lexerContext);
        alternative.reset(static_cast<soulng::parser::Value<soulng::slg::Nfa>*>(match.value));
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::parser::Value<soulng::slg::Nfa>(alternative->value));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match RegExParser::Alternative(RegExLexer& lexer, soulng::slg::LexerContext* lexerContext)
{
    soulng::slg::Nfa value = soulng::slg::Nfa();
    std::unique_ptr<soulng::parser::Value<soulng::slg::Nfa>> left;
    std::unique_ptr<soulng::parser::Value<soulng::slg::Nfa>> right;
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
                soulng::parser::Match match = RegExParser::Catenation(lexer, lexerContext);
                left.reset(static_cast<soulng::parser::Value<soulng::slg::Nfa>*>(match.value));
                if (match.hit)
                {
                    value = left->value;
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
                                if (*lexer == ALT)
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
                                            soulng::parser::Match match = RegExParser::Catenation(lexer, lexerContext);
                                            right.reset(static_cast<soulng::parser::Value<soulng::slg::Nfa>*>(match.value));
                                            if (match.hit)
                                            {
                                                *parentMatch8 = match;
                                            }
                                            else
                                            {
                                                lexer.ThrowExpectationFailure(pos, U"catenation");
                                            }
                                        }
                                        if (match.hit)
                                        {
                                            value = soulng::slg::Alt(*lexerContext, value, right->value);
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
            return soulng::parser::Match(true, new soulng::parser::Value<soulng::slg::Nfa>(value));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match RegExParser::Catenation(RegExLexer& lexer, soulng::slg::LexerContext* lexerContext)
{
    soulng::slg::Nfa value = soulng::slg::Nfa();
    std::unique_ptr<soulng::parser::Value<soulng::slg::Nfa>> left;
    std::unique_ptr<soulng::parser::Value<soulng::slg::Nfa>> right;
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
                soulng::parser::Match match = RegExParser::Repetition(lexer, lexerContext);
                left.reset(static_cast<soulng::parser::Value<soulng::slg::Nfa>*>(match.value));
                if (match.hit)
                {
                    value = left->value;
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
                                soulng::parser::Match match = RegExParser::Repetition(lexer, lexerContext);
                                right.reset(static_cast<soulng::parser::Value<soulng::slg::Nfa>*>(match.value));
                                if (match.hit)
                                {
                                    value = soulng::slg::Cat(value, right->value);
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
            return soulng::parser::Match(true, new soulng::parser::Value<soulng::slg::Nfa>(value));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match RegExParser::Repetition(RegExLexer& lexer, soulng::slg::LexerContext* lexerContext)
{
    soulng::slg::Nfa value = soulng::slg::Nfa();
    std::unique_ptr<soulng::parser::Value<soulng::slg::Nfa>> left;
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
                soulng::parser::Match match = RegExParser::Primary(lexer, lexerContext);
                left.reset(static_cast<soulng::parser::Value<soulng::slg::Nfa>*>(match.value));
                if (match.hit)
                {
                    value = left->value;
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
                        int save = lexer.GetPos();
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            int save = lexer.GetPos();
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == STAR)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    value = soulng::slg::Kleene(*lexerContext, value);
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
                                        soulng::parser::Match match(false);
                                        if (*lexer == PLUS)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            value = soulng::slg::Pos(*lexerContext, value);
                                        }
                                        *parentMatch9 = match;
                                    }
                                    *parentMatch8 = match;
                                }
                                *parentMatch6 = match;
                            }
                        }
                        *parentMatch5 = match;
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
                                    if (*lexer == QUEST)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        value = soulng::slg::Opt(*lexerContext, value);
                                    }
                                    *parentMatch11 = match;
                                }
                                *parentMatch10 = match;
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
                    }
                }
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::parser::Value<soulng::slg::Nfa>(value));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match RegExParser::Primary(RegExLexer& lexer, soulng::slg::LexerContext* lexerContext)
{
    soulng::slg::Nfa value = soulng::slg::Nfa();
    std::unique_ptr<soulng::parser::Value<soulng::slg::Nfa>> alt;
    std::unique_ptr<soulng::slg::Class> cls;
    std::unique_ptr<soulng::parser::Value<std::u32string>> ref;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
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
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            if (*lexer == LPAREN)
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
                                                    soulng::parser::Match match(true);
                                                    soulng::parser::Match* parentMatch12 = &match;
                                                    {
                                                        int pos = lexer.GetPos();
                                                        soulng::parser::Match match = RegExParser::Alternative(lexer, lexerContext);
                                                        alt.reset(static_cast<soulng::parser::Value<soulng::slg::Nfa>*>(match.value));
                                                        if (match.hit)
                                                        {
                                                            *parentMatch12 = match;
                                                        }
                                                        else
                                                        {
                                                            lexer.ThrowExpectationFailure(pos, U"alternative");
                                                        }
                                                    }
                                                    if (match.hit)
                                                    {
                                                        value = alt->value;
                                                    }
                                                    *parentMatch11 = match;
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
                                        soulng::parser::Match* parentMatch13 = &match;
                                        {
                                            soulng::parser::Match match(true);
                                            soulng::parser::Match* parentMatch14 = &match;
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
                                                    *parentMatch14 = match;
                                                }
                                                else
                                                {
                                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                                                }
                                            }
                                            *parentMatch13 = match;
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
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
                                                if (*lexer == ESCAPE)
                                                {
                                                    ++lexer;
                                                    match.hit = true;
                                                }
                                                if (match.hit)
                                                {
                                                    value = MakeNfa(*lexerContext, lexerContext->MakeChar(soulng::slg::MakeEscapeValue(lexer.FileName(), lexer.GetToken(pos))));
                                                }
                                                *parentMatch16 = match;
                                            }
                                            *parentMatch15 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                }
                                *parentMatch6 = match;
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
                                            if (*lexer == INVERSE)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            if (match.hit)
                                            {
                                                value = MakeNfa(*lexerContext, lexerContext->MakeChar('^'));
                                            }
                                            *parentMatch18 = match;
                                        }
                                        *parentMatch17 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                            }
                            *parentMatch5 = match;
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
                                        soulng::parser::Match match(false);
                                        if (*lexer == MINUS)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            value = MakeNfa(*lexerContext, lexerContext->MakeChar('-'));
                                        }
                                        *parentMatch20 = match;
                                    }
                                    *parentMatch19 = match;
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
                                    int pos = lexer.GetPos();
                                    soulng::lexer::Span span = lexer.GetSpan();
                                    soulng::parser::Match match(false);
                                    if (*lexer == CHAR)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        std::u32string match = lexer.GetMatch(span);
                                        value = MakeNfa(*lexerContext, lexerContext->MakeChar(match.front()));
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
                        soulng::parser::Match* parentMatch23 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch24 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == DOT)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    value = MakeNfa(*lexerContext, lexerContext->MakeAny());
                                }
                                *parentMatch24 = match;
                            }
                            *parentMatch23 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
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
                            soulng::parser::Match match = RegExParser::Class(lexer, lexerContext);
                            cls.reset(static_cast<soulng::slg::Class*>(match.value));
                            if (match.hit)
                            {
                                value = MakeNfa(*lexerContext, cls.release());
                            }
                            *parentMatch26 = match;
                        }
                        *parentMatch25 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
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
                        soulng::parser::Match match = RegExParser::ExpressionReference(lexer);
                        ref.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                        if (match.hit)
                        {
                            value = lexerContext->MakeExpr(ref->value);
                        }
                        *parentMatch28 = match;
                    }
                    *parentMatch27 = match;
                }
                *parentMatch1 = match;
            }
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::parser::Value<soulng::slg::Nfa>(value));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match RegExParser::Class(RegExLexer& lexer, soulng::slg::LexerContext* lexerContext)
{
    soulng::slg::Class* cls = nullptr;
    std::unique_ptr<soulng::slg::Symbol> r;
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
                    soulng::parser::Match match(false);
                    if (*lexer == LBRACKET)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        cls = lexerContext->MakeClass();
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
                        soulng::parser::Match match(true);
                        int save = lexer.GetPos();
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == INVERSE)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    cls->SetInverse();
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
                            }
                        }
                        *parentMatch5 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch8 = &match;
                        {
                            soulng::parser::Match match(true);
                            soulng::parser::Match* parentMatch9 = &match;
                            {
                                while (true)
                                {
                                    int save = lexer.GetPos();
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch10 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = RegExParser::Range(lexer, lexerContext);
                                            r.reset(static_cast<soulng::slg::Symbol*>(match.value));
                                            if (match.hit)
                                            {
                                                cls->AddSymbol(r.release());
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
                                            break;
                                        }
                                    }
                                }
                            }
                            *parentMatch8 = match;
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
            soulng::parser::Match* parentMatch11 = &match;
            {
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch12 = &match;
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
                        *parentMatch12 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RBRACKET)));
                    }
                }
                *parentMatch11 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, cls);
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match RegExParser::Range(RegExLexer& lexer, soulng::slg::LexerContext* lexerContext)
{
    soulng::slg::Symbol* symbol = nullptr;
    std::unique_ptr<soulng::parser::Value<char32_t>> s;
    std::unique_ptr<soulng::parser::Value<char32_t>> e;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match = RegExParser::Char(lexer);
            s.reset(static_cast<soulng::parser::Value<char32_t>*>(match.value));
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
                    int save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        if (*lexer == MINUS)
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
                                soulng::parser::Match match = RegExParser::Char(lexer);
                                e.reset(static_cast<soulng::parser::Value<char32_t>*>(match.value));
                                if (match.hit)
                                {
                                    symbol = lexerContext->MakeRange(s->value, e->value);
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
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
                                soulng::parser::Match match(true);
                                if (match.hit)
                                {
                                    symbol = lexerContext->MakeChar(s->value);
                                }
                                *parentMatch8 = match;
                            }
                            *parentMatch7 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, symbol);
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match RegExParser::Char(RegExLexer& lexer)
{
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case LPAREN:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<char32_t>('('));
            }
            break;
        }
        case RPAREN:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<char32_t>(')'));
            }
            break;
        }
        case LBRACKET:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<char32_t>('['));
            }
            break;
        }
        case LBRACE:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<char32_t>('{'));
            }
            break;
        }
        case RBRACE:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<char32_t>('}'));
            }
            break;
        }
        case ALT:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<char32_t>('|'));
            }
            break;
        }
        case STAR:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<char32_t>('*'));
            }
            break;
        }
        case PLUS:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<char32_t>('+'));
            }
            break;
        }
        case QUEST:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<char32_t>('?'));
            }
            break;
        }
        case DOT:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<char32_t>('.'));
            }
            break;
        }
        case ESCAPE:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<char32_t>(soulng::slg::MakeEscapeValue(lexer.FileName(), lexer.GetToken(pos))));
            }
            break;
        }
        case INVERSE:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<char32_t>('^'));
            }
            break;
        }
        case MINUS:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<char32_t>('-'));
            }
            break;
        }
        case CHAR:
        {
            ++lexer;
            {
                std::u32string match = lexer.GetMatch(span);
                return soulng::parser::Match(true, new soulng::parser::Value<char32_t>(match.front()));
            }
            break;
        }
    }
    return match;
}

soulng::parser::Match RegExParser::ExpressionReference(RegExLexer& lexer)
{
    Span s = Span();
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
                    soulng::parser::Match match(false);
                    if (*lexer == CHAR)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch4 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch5 = &match;
                    while (true)
                    {
                        int save = lexer.GetPos();
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == CHAR)
                            {
                                ++lexer;
                                match.hit = true;
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
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                if (*lexer == RBRACE)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    s.end = span.end;
                    return soulng::parser::Match(true, new soulng::parser::Value<std::u32string>(soulng::slg::MakeExprRefId(lexer.FileName(), lexer.GetMatch(s), lexer.GetToken(pos).line)));
                }
                *parentMatch7 = match;
            }
            *parentMatch6 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}
