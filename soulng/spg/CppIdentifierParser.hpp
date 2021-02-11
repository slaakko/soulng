#ifndef CPPIDENTIFIERPARSER_HPP
#define CPPIDENTIFIERPARSER_HPP
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/soulng/spg/CppIdentifierParser.parser' using soulng parser generator spg version 3.10.0

class ParserFileLexer;

struct CppIdentifierParser
{
    static soulng::parser::Match CppIdentifier(ParserFileLexer& lexer);
    static soulng::parser::Match QualifiedCppId(ParserFileLexer& lexer);
};

#endif // CPPIDENTIFIERPARSER_HPP
