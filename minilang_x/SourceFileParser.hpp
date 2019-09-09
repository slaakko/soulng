#ifndef SOURCEFILEPARSER_HPP
#define SOURCEFILEPARSER_HPP
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/minilang/SourceFileParser.parser' using soulng parser generator spg version 1.0.0

class MinilangLexer;

struct MinilangSourceFileParser
{
    static soulng::parser::Match SourceFile(MinilangLexer& lexer);
};

#endif // SOURCEFILEPARSER_HPP
