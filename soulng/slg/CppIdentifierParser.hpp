#ifndef CPPIDENTIFIERPARSER_HPP
#define CPPIDENTIFIERPARSER_HPP
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/soulng/slg/CppIdentifierParser.parser' using soulng parser generator spg version 1.0.0

class LexerFileLexer;

struct CppIdentifierParser
{
    static soulng::parser::Match CppIdentifier(LexerFileLexer& lexer);
    static soulng::parser::Match QualifiedCppId(LexerFileLexer& lexer);
};

#endif // CPPIDENTIFIERPARSER_HPP
