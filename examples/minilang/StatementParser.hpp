#ifndef STATEMENTPARSER_HPP
#define STATEMENTPARSER_HPP
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/StatementParser.parser' using soulng parser generator spg version 3.0.0

class MinilangLexer;

struct StatementParser
{
    static soulng::parser::Match Statement(MinilangLexer& lexer);
    static soulng::parser::Match IfStatement(MinilangLexer& lexer);
    static soulng::parser::Match WhileStatement(MinilangLexer& lexer);
    static soulng::parser::Match ReturnStatement(MinilangLexer& lexer);
    static soulng::parser::Match ConstructionStatement(MinilangLexer& lexer);
    static soulng::parser::Match AssignmentStatement(MinilangLexer& lexer);
    static soulng::parser::Match CompoundStatement(MinilangLexer& lexer);
};

#endif // STATEMENTPARSER_HPP
