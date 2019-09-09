#include "IdentifierParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <soulng/minilang/MinilangLexer.hpp>
#include <soulng/minilang/MinilangTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng/minilang/IdentifierParser.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace MinilangTokens;

soulng::parser::Match MinilangIdentifierParser::Identifier(MinilangLexer& lexer)
{
    soulng::parser::Match match(false);
    if (*lexer == ID)
    {
        ++lexer;
        match.hit = true;
    }
    return match;
}
