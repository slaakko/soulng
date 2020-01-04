#ifndef LEXERLITERALPARSER_HPP
#define LEXERLITERALPARSER_HPP
#include <soulng/cppcode/Literal.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/tools/sng2html/sng2html/LexerLiteralParser.parser' using soulng parser generator spg version 3.0.0

class LexerFileLexer;

struct LexerLiteralParser
{
    static soulng::parser::Match CppLiteral(LexerFileLexer& lexer);
};

#endif // LEXERLITERALPARSER_HPP
