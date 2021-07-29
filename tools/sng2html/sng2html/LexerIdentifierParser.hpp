#ifndef LEXERIDENTIFIERPARSER_HPP
#define LEXERIDENTIFIERPARSER_HPP
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/tools/sng2html/sng2html/LexerIdentifierParser.parser' using soulng parser generator spg version 4.0.0

class LexerFileLexer;

struct LexerIdentifierParser
{
    static soulng::parser::Match CppIdentifier(LexerFileLexer& lexer);
    static soulng::parser::Match QualifiedCppId(LexerFileLexer& lexer);
};

#endif // LEXERIDENTIFIERPARSER_HPP
