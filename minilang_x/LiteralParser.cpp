#include "LiteralParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <soulng/minilang/MinilangLexer.hpp>
#include <soulng/minilang/MinilangTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng/minilang/LiteralParser.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace MinilangTokens;

soulng::parser::Match MinilangLiteralParser::Literal(MinilangLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match = MinilangLiteralParser::BooleanLiteral(lexer);
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch1 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match = MinilangLiteralParser::IntegerLiteral(lexer);
                *parentMatch1 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match MinilangLiteralParser::BooleanLiteral(MinilangLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        if (*lexer == TRUE)
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
                if (*lexer == FALSE)
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

soulng::parser::Match MinilangLiteralParser::IntegerLiteral(MinilangLexer& lexer)
{
    soulng::parser::Match match(false);
    if (*lexer == INTLIT)
    {
        ++lexer;
        match.hit = true;
    }
    return match;
}
