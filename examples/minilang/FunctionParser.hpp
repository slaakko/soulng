#ifndef FUNCTIONPARSER_HPP
#define FUNCTIONPARSER_HPP
#include <minilang/Tree.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/FunctionParser.parser' using soulng parser generator spg version 1.1.0

class MinilangLexer;

struct FunctionParser
{
    static soulng::parser::Match Function(MinilangLexer& lexer);
    static soulng::parser::Match ParameterList(MinilangLexer& lexer, minilang::FunctionNode* function);
    static soulng::parser::Match Parameter(MinilangLexer& lexer);
};

#endif // FUNCTIONPARSER_HPP
