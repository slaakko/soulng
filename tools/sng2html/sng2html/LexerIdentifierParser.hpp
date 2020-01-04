#ifndef LEXERIDENTIFIERPARSER_HPP
#define LEXERIDENTIFIERPARSER_HPP
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/tools/sng2html/sng2html/LexerIdentifierParser.parser' using soulng parser generator spg version 3.0.0

class LexerFileLexer;

struct LexerIdentifierParser
{
    static soulng::parser::Match CppIdentifier(LexerFileLexer& lexer);
    static soulng::parser::Match QualifiedCppId(LexerFileLexer& lexer);
};

#endif // LEXERIDENTIFIERPARSER_HPP
