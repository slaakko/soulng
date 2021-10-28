#ifndef CPPLITERALPARSER_HPP
#define CPPLITERALPARSER_HPP
#include <soulng/cppcode/Literal.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/soulng/spg/CppLiteralParser.parser' using soulng parser generator spg version 3.1.0

class ParserFileLexer;

struct CppLiteralParser
{
    static soulng::parser::Match CppLiteral(ParserFileLexer& lexer);
};

#endif // CPPLITERALPARSER_HPP
