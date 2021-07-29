#ifndef PARSERLITERALPARSER_HPP
#define PARSERLITERALPARSER_HPP
#include <soulng/cppcode/Literal.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/tools/sng2html/sng2html/ParserLiteralParser.parser' using soulng parser generator spg version 4.0.0

class ParserFileLexer;

struct ParserLiteralParser
{
    static soulng::parser::Match CppLiteral(ParserFileLexer& lexer);
};

#endif // PARSERLITERALPARSER_HPP
