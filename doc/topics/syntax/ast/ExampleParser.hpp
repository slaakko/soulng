#ifndef EXAMPLEPARSER_HPP
#define EXAMPLEPARSER_HPP
#include <ExampleAST.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/doc/topics/syntax/ast/ExampleParser.parser' using soulng parser generator spg version 1.0.0

class ExampleLexer;

struct ExampleParser
{
    static std::unique_ptr<Node> Parse(ExampleLexer& lexer, SymbolTable* symbolTable);
    static soulng::parser::Match Statement(ExampleLexer& lexer, SymbolTable* symbolTable);
    static soulng::parser::Match WhileStatement(ExampleLexer& lexer, SymbolTable* symbolTable);
    static soulng::parser::Match EmptyStatement(ExampleLexer& lexer);
    static soulng::parser::Match Expression(ExampleLexer& lexer);
};

#endif // EXAMPLEPARSER_HPP
