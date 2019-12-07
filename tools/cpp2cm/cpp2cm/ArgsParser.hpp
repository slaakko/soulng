#ifndef ARGSPARSER_HPP
#define ARGSPARSER_HPP
#include <cpp2cm/cpp2cm/Args.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/tools/cpp2cm/cpp2cm/ArgsParser.parser' using soulng parser generator spg version 3.0.0

class TrivialLexer;

struct ArgsParser
{
    static void Parse(TrivialLexer& lexer, std::vector<int>* args);
    static soulng::parser::Match Args(TrivialLexer& lexer, std::vector<int>* args);
    static soulng::parser::Match Arg(TrivialLexer& lexer);
    static soulng::parser::Match S(TrivialLexer& lexer);
};

#endif // ARGSPARSER_HPP
