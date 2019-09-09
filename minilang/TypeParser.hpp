#ifndef TYPEPARSER_HPP
#define TYPEPARSER_HPP
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/minilang/TypeParser.parser' using soulng parser generator spg version 1.0.0

class MinilangLexer;

struct MinilangTypeParser
{
    static soulng::parser::Match Type(MinilangLexer& lexer);
};

#endif // TYPEPARSER_HPP
