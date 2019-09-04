#ifndef CPPEXPRESSIONPARSER_HPP
#define CPPEXPRESSIONPARSER_HPP
#include <soulng/cppcode/Expression.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/spg/CppExpressionParser.parser' using soulng parser generator spg version 1.0.0

class ParserFileLexer;

struct CppExpressionParser
{
    static soulng::parser::Match CppExpression(ParserFileLexer& lexer);
    static soulng::parser::Match ConstantExpression(ParserFileLexer& lexer);
    static soulng::parser::Match AssignmentExpression(ParserFileLexer& lexer);
    static soulng::parser::Match AssignmentOp(ParserFileLexer& lexer);
    static soulng::parser::Match ConditionalExpression(ParserFileLexer& lexer);
    static soulng::parser::Match ThrowExpression(ParserFileLexer& lexer);
    static soulng::parser::Match LogicalOrExpression(ParserFileLexer& lexer);
    static soulng::parser::Match LogicalAndExpression(ParserFileLexer& lexer);
    static soulng::parser::Match InclusiveOrExpression(ParserFileLexer& lexer);
    static soulng::parser::Match ExclusiveOrExpression(ParserFileLexer& lexer);
    static soulng::parser::Match AndExpression(ParserFileLexer& lexer);
    static soulng::parser::Match EqualityExpression(ParserFileLexer& lexer);
    static soulng::parser::Match EqOp(ParserFileLexer& lexer);
    static soulng::parser::Match RelationalExpression(ParserFileLexer& lexer);
    static soulng::parser::Match RelOp(ParserFileLexer& lexer);
    static soulng::parser::Match ShiftExpression(ParserFileLexer& lexer);
    static soulng::parser::Match ShiftOp(ParserFileLexer& lexer);
    static soulng::parser::Match AdditiveExpression(ParserFileLexer& lexer);
    static soulng::parser::Match AddOp(ParserFileLexer& lexer);
    static soulng::parser::Match MultiplicativeExpression(ParserFileLexer& lexer);
    static soulng::parser::Match MulOp(ParserFileLexer& lexer);
    static soulng::parser::Match PmExpression(ParserFileLexer& lexer);
    static soulng::parser::Match PmOp(ParserFileLexer& lexer);
    static soulng::parser::Match CastExpression(ParserFileLexer& lexer);
    static soulng::parser::Match UnaryExpression(ParserFileLexer& lexer);
    static soulng::parser::Match UnaryOperator(ParserFileLexer& lexer);
    static soulng::parser::Match PostfixExpression(ParserFileLexer& lexer);
    static soulng::parser::Match PostCastExpression(ParserFileLexer& lexer);
    static soulng::parser::Match ExpressionList(ParserFileLexer& lexer, soulng::cppcode::CppObject* owner);
    static soulng::parser::Match PrimaryExpression(ParserFileLexer& lexer);
    static soulng::parser::Match IdExpression(ParserFileLexer& lexer);
    static soulng::parser::Match TypeSpecifierOrTypeName(ParserFileLexer& lexer);
    static soulng::parser::Match NewExpression(ParserFileLexer& lexer);
    static soulng::parser::Match NewPlacement(ParserFileLexer& lexer, soulng::cppcode::CppObject* owner);
    static soulng::parser::Match NewTypeId(ParserFileLexer& lexer);
    static soulng::parser::Match NewDeclarator(ParserFileLexer& lexer);
    static soulng::parser::Match NewInitializer(ParserFileLexer& lexer, soulng::cppcode::CppObject* owner);
    static soulng::parser::Match DirectNewDeclarator(ParserFileLexer& lexer);
    static soulng::parser::Match DeleteExpression(ParserFileLexer& lexer);
    static soulng::parser::Match OperatorFunctionId(ParserFileLexer& lexer);
    static soulng::parser::Match Operator(ParserFileLexer& lexer);
};

#endif // CPPEXPRESSIONPARSER_HPP
