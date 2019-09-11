#include "ExpressionParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <minilang/LiteralParser.hpp>
#include <minilang/IdentifierParser.hpp>
#include <minilang/MinilangLexer.hpp>
#include <minilang/MinilangTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/ExpressionParser.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace MinilangTokens;

soulng::parser::Match ExpressionParser::Expression(MinilangLexer& lexer)
{
    soulng::parser::Match match = ExpressionParser::EqualityExpression(lexer);
    return match;
}

soulng::parser::Match ExpressionParser::PrimaryExpression(MinilangLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int save = lexer.GetPos();
            soulng::parser::Match match = LiteralParser::Literal(lexer);
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch2 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                    *parentMatch2 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            lexer.SetPos(save);
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
                            soulng::parser::Match match = ExpressionParser::Expression(lexer);
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
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match ExpressionParser::PostfixExpression(MinilangLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match = ExpressionParser::PrimaryExpression(lexer);
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(true);
            soulng::parser::Match* parentMatch2 = &match;
            {
                while (true)
                {
                    int save = lexer.GetPos();
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch3 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch4 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == LPAREN)
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
                                    soulng::parser::Match match(true);
                                    int save = lexer.GetPos();
                                    soulng::parser::Match* parentMatch6 = &match;
                                    {
                                        soulng::parser::Match match = ExpressionParser::ExpressionList(lexer);
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
                                *parentMatch7 = match;
                            }
                            *parentMatch3 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch2 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                            break;
                        }
                    }
                }
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::ExpressionList(MinilangLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match = ExpressionParser::Expression(lexer);
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(true);
            soulng::parser::Match* parentMatch2 = &match;
            {
                while (true)
                {
                    int save = lexer.GetPos();
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch3 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == COMMA)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch3 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch4 = &match;
                            {
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = ExpressionParser::Expression(lexer);
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, U"Expression");
                                    }
                                }
                                *parentMatch4 = match;
                            }
                            *parentMatch3 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch2 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                            break;
                        }
                    }
                }
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::UnaryExpression(MinilangLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match = ExpressionParser::UnaryOperator(lexer);
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ExpressionParser::UnaryExpression(lexer);
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, U"UnaryExpression");
                    }
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match = ExpressionParser::PostfixExpression(lexer);
                *parentMatch3 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match ExpressionParser::UnaryOperator(MinilangLexer& lexer)
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
            if (*lexer == PLUS)
            {
                ++lexer;
                match.hit = true;
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch2 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    if (*lexer == MINUS)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch2 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                if (*lexer == NOT)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch3 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match ExpressionParser::MultiplicativeExpression(MinilangLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match = ExpressionParser::UnaryExpression(lexer);
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(true);
            soulng::parser::Match* parentMatch2 = &match;
            {
                while (true)
                {
                    int save = lexer.GetPos();
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch3 = &match;
                        {
                            soulng::parser::Match match = ExpressionParser::MultiplicativeOperator(lexer);
                            *parentMatch3 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch4 = &match;
                            {
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = ExpressionParser::UnaryExpression(lexer);
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, U"UnaryExpression");
                                    }
                                }
                                *parentMatch4 = match;
                            }
                            *parentMatch3 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch2 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                            break;
                        }
                    }
                }
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::MultiplicativeOperator(MinilangLexer& lexer)
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
            if (*lexer == MUL)
            {
                ++lexer;
                match.hit = true;
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch2 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    if (*lexer == DIV)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch2 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                if (*lexer == MOD)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch3 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match ExpressionParser::AdditiveExpression(MinilangLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match = ExpressionParser::MultiplicativeExpression(lexer);
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(true);
            soulng::parser::Match* parentMatch2 = &match;
            {
                while (true)
                {
                    int save = lexer.GetPos();
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch3 = &match;
                        {
                            soulng::parser::Match match = ExpressionParser::AdditiveOperator(lexer);
                            *parentMatch3 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch4 = &match;
                            {
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = ExpressionParser::MultiplicativeExpression(lexer);
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, U"MultiplicativeExpression");
                                    }
                                }
                                *parentMatch4 = match;
                            }
                            *parentMatch3 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch2 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                            break;
                        }
                    }
                }
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::AdditiveOperator(MinilangLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        if (*lexer == PLUS)
        {
            ++lexer;
            match.hit = true;
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch1 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                if (*lexer == MINUS)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch1 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match ExpressionParser::RelationalExpression(MinilangLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match = ExpressionParser::AdditiveExpression(lexer);
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(true);
            soulng::parser::Match* parentMatch2 = &match;
            {
                while (true)
                {
                    int save = lexer.GetPos();
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch3 = &match;
                        {
                            soulng::parser::Match match = ExpressionParser::RelationalOperator(lexer);
                            *parentMatch3 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch4 = &match;
                            {
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = ExpressionParser::AdditiveExpression(lexer);
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, U"AdditiveExpression");
                                    }
                                }
                                *parentMatch4 = match;
                            }
                            *parentMatch3 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch2 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                            break;
                        }
                    }
                }
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::RelationalOperator(MinilangLexer& lexer)
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
                if (*lexer == LESS)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch3 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        if (*lexer == GREATER)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        *parentMatch3 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    if (*lexer == LEQ)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch4 = match;
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
                if (*lexer == GEQ)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch5 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match ExpressionParser::EqualityExpression(MinilangLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match = ExpressionParser::RelationalExpression(lexer);
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(true);
            soulng::parser::Match* parentMatch2 = &match;
            {
                while (true)
                {
                    int save = lexer.GetPos();
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch3 = &match;
                        {
                            soulng::parser::Match match = ExpressionParser::EqualityOperator(lexer);
                            *parentMatch3 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch4 = &match;
                            {
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = ExpressionParser::RelationalExpression(lexer);
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, U"RelationalExpression");
                                    }
                                }
                                *parentMatch4 = match;
                            }
                            *parentMatch3 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch2 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                            break;
                        }
                    }
                }
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExpressionParser::EqualityOperator(MinilangLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        if (*lexer == EQ)
        {
            ++lexer;
            match.hit = true;
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch1 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                if (*lexer == NEQ)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch1 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}
