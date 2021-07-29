#ifndef PARSERIDENTIFIERPARSER_HPP
#define PARSERIDENTIFIERPARSER_HPP
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/tools/sng2html/sng2html/ParserIdentifierParser.parser' using soulng parser generator spg version 4.0.0

class ParserFileLexer;

struct ParserIdentifierParser
{
    static soulng::parser::Match CppIdentifier(ParserFileLexer& lexer);
    static soulng::parser::Match QualifiedCppId(ParserFileLexer& lexer);
};

#endif // PARSERIDENTIFIERPARSER_HPP
