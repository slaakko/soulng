#ifndef CPPEXPRESSIONPARSER_HPP
#define CPPEXPRESSIONPARSER_HPP
#include <soulng/cppcode/Expression.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/soulng/slg/CppExpressionParser.parser' using soulng parser generator spg version 4.0.0

class LexerFileLexer;

struct CppExpressionParser
{
    static soulng::parser::Match CppExpression(LexerFileLexer& lexer);
    static soulng::parser::Match ConstantExpression(LexerFileLexer& lexer);
    static soulng::parser::Match AssignmentExpression(LexerFileLexer& lexer);
    static soulng::parser::Match AssignmentOp(LexerFileLexer& lexer);
    static soulng::parser::Match ConditionalExpression(LexerFileLexer& lexer);
    static soulng::parser::Match ThrowExpression(LexerFileLexer& lexer);
    static soulng::parser::Match LogicalOrExpression(LexerFileLexer& lexer);
    static soulng::parser::Match LogicalAndExpression(LexerFileLexer& lexer);
    static soulng::parser::Match InclusiveOrExpression(LexerFileLexer& lexer);
    static soulng::parser::Match ExclusiveOrExpression(LexerFileLexer& lexer);
    static soulng::parser::Match AndExpression(LexerFileLexer& lexer);
    static soulng::parser::Match EqualityExpression(LexerFileLexer& lexer);
    static soulng::parser::Match EqOp(LexerFileLexer& lexer);
    static soulng::parser::Match RelationalExpression(LexerFileLexer& lexer);
    static soulng::parser::Match RelOp(LexerFileLexer& lexer);
    static soulng::parser::Match ShiftExpression(LexerFileLexer& lexer);
    static soulng::parser::Match ShiftOp(LexerFileLexer& lexer);
    static soulng::parser::Match AdditiveExpression(LexerFileLexer& lexer);
    static soulng::parser::Match AddOp(LexerFileLexer& lexer);
    static soulng::parser::Match MultiplicativeExpression(LexerFileLexer& lexer);
    static soulng::parser::Match MulOp(LexerFileLexer& lexer);
    static soulng::parser::Match PmExpression(LexerFileLexer& lexer);
    static soulng::parser::Match PmOp(LexerFileLexer& lexer);
    static soulng::parser::Match CastExpression(LexerFileLexer& lexer);
    static soulng::parser::Match UnaryExpression(LexerFileLexer& lexer);
    static soulng::parser::Match UnaryOperator(LexerFileLexer& lexer);
    static soulng::parser::Match PostfixExpression(LexerFileLexer& lexer);
    static soulng::parser::Match PostCastExpression(LexerFileLexer& lexer);
    static soulng::parser::Match ExpressionList(LexerFileLexer& lexer, soulng::cppcode::CppObject* owner);
    static soulng::parser::Match PrimaryExpression(LexerFileLexer& lexer);
    static soulng::parser::Match IdExpression(LexerFileLexer& lexer);
    static soulng::parser::Match TypeSpecifierOrTypeName(LexerFileLexer& lexer);
    static soulng::parser::Match NewExpression(LexerFileLexer& lexer);
    static soulng::parser::Match NewPlacement(LexerFileLexer& lexer, soulng::cppcode::CppObject* owner);
    static soulng::parser::Match NewTypeId(LexerFileLexer& lexer);
    static soulng::parser::Match NewDeclarator(LexerFileLexer& lexer);
    static soulng::parser::Match NewInitializer(LexerFileLexer& lexer, soulng::cppcode::CppObject* owner);
    static soulng::parser::Match DirectNewDeclarator(LexerFileLexer& lexer);
    static soulng::parser::Match DeleteExpression(LexerFileLexer& lexer);
    static soulng::parser::Match OperatorFunctionId(LexerFileLexer& lexer);
    static soulng::parser::Match Operator(LexerFileLexer& lexer);
};

#endif // CPPEXPRESSIONPARSER_HPP
