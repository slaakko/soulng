#ifndef IDENTIFIERPARSER_HPP
#define IDENTIFIERPARSER_HPP
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/IdentifierParser.parser' using soulng parser generator spg version 1.1.0

class MinilangLexer;

struct IdentifierParser
{
    static soulng::parser::Match Identifier(MinilangLexer& lexer);
};

#endif // IDENTIFIERPARSER_HPP
