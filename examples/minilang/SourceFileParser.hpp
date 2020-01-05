#ifndef SOURCEFILEPARSER_HPP
#define SOURCEFILEPARSER_HPP
#include <minilang/Tree.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/SourceFileParser.parser' using soulng parser generator spg version 3.0.0

class MinilangLexer;

struct SourceFileParser
{
    static std::unique_ptr<minilang::SourceFileNode> Parse(MinilangLexer& lexer);
    static soulng::parser::Match SourceFile(MinilangLexer& lexer);
};

#endif // SOURCEFILEPARSER_HPP
