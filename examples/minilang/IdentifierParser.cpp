#include "IdentifierParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <minilang/MinilangLexer.hpp>
#include <minilang/MinilangTokens.hpp>
#include <minilang/Tree.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/IdentifierParser.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace MinilangTokens;

soulng::parser::Match IdentifierParser::Identifier(MinilangLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        if (*lexer == ID)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            soulng::lexer::Token token = lexer.GetToken(pos);
            return soulng::parser::Match(true, new minilang::IdentifierNode(token.match.ToString()));
        }
        *parentMatch0 = match;
    }
    return match;
}
