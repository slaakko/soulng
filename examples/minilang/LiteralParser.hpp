#ifndef LITERALPARSER_HPP
#define LITERALPARSER_HPP
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/LiteralParser.parser' using soulng parser generator spg version 1.1.0

class MinilangLexer;

struct LiteralParser
{
    static soulng::parser::Match Literal(MinilangLexer& lexer);
    static soulng::parser::Match BooleanLiteral(MinilangLexer& lexer);
    static soulng::parser::Match IntegerLiteral(MinilangLexer& lexer);
};

#endif // LITERALPARSER_HPP
