#include "LiteralParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <minilang/MinilangLexer.hpp>
#include <minilang/MinilangTokens.hpp>
#include <minilang/Tree.hpp>
#include <minilang/TokenValueParser.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/LiteralParser.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace MinilangTokens;

soulng::parser::Match LiteralParser::Literal(MinilangLexer& lexer)
{
    std::unique_ptr<minilang::Node> booleanLiteral;
    std::unique_ptr<minilang::Node> integerLiteral;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match = LiteralParser::BooleanLiteral(lexer);
            booleanLiteral.reset(static_cast<minilang::Node*>(match.value));
            if (match.hit)
            {
                return soulng::parser::Match(true, booleanLiteral.release());
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
                    soulng::parser::Match match = LiteralParser::IntegerLiteral(lexer);
                    integerLiteral.reset(static_cast<minilang::Node*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, integerLiteral.release());
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

soulng::parser::Match LiteralParser::BooleanLiteral(MinilangLexer& lexer)
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
                return soulng::parser::Match(true, new minilang::BooleanLiteralNode(true));
            }
            break;
        }
        case FALSE:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new minilang::BooleanLiteralNode(false));
            }
            break;
        }
    }
    return match;
}

soulng::parser::Match LiteralParser::IntegerLiteral(MinilangLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        if (*lexer == INTLIT)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new minilang::IntegerLiteralNode(minilang::ParseIntegerLiteral(lexer.FileName(), lexer.GetToken(pos))));
        }
        *parentMatch0 = match;
    }
    return match;
}
