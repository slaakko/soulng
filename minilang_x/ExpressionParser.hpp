#ifndef EXPRESSIONPARSER_HPP
#define EXPRESSIONPARSER_HPP
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/minilang/ExpressionParser.parser' using soulng parser generator spg version 1.0.0

class MinilangLexer;

struct MinilangExpressionParser
{
    static soulng::parser::Match Expression(MinilangLexer& lexer);
    static soulng::parser::Match PrimaryExpression(MinilangLexer& lexer);
    static soulng::parser::Match PostfixExpression(MinilangLexer& lexer);
    static soulng::parser::Match ExpressionList(MinilangLexer& lexer);
    static soulng::parser::Match UnaryExpression(MinilangLexer& lexer);
    static soulng::parser::Match UnaryOperator(MinilangLexer& lexer);
    static soulng::parser::Match MultiplicativeExpression(MinilangLexer& lexer);
    static soulng::parser::Match MultiplicativeOperator(MinilangLexer& lexer);
    static soulng::parser::Match AdditiveExpression(MinilangLexer& lexer);
    static soulng::parser::Match AdditiveOperator(MinilangLexer& lexer);
    static soulng::parser::Match RelationalExpression(MinilangLexer& lexer);
    static soulng::parser::Match RelationalOperator(MinilangLexer& lexer);
    static soulng::parser::Match EqualityExpression(MinilangLexer& lexer);
    static soulng::parser::Match EqualityOperator(MinilangLexer& lexer);
};

#endif // EXPRESSIONPARSER_HPP
