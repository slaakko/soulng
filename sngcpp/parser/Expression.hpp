#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP
#include <sngcpp/parser/ParserApi.hpp>
#include <sngcpp/ast/Expression.hpp>
#include <sngcpp/parser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/parser/Expression.parser' using soulng parser generator spg version 1.2.0

class CppLexer;

struct SNGCPP_PARSER_API ExpressionParser
{
    static soulng::parser::Match Expression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match AssignmentExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match AssignmentOperator(CppLexer& lexer);
    static soulng::parser::Match ConditionalExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match ThrowExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match LogicalOrExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match LogicalAndExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match InclusiveOrExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match ExclusiveOrExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match AndExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match EqualityExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match EqualityOperator(CppLexer& lexer);
    static soulng::parser::Match RelationalExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match RelationalOperator(CppLexer& lexer);
    static soulng::parser::Match ShiftExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match ShiftOperator(CppLexer& lexer);
    static soulng::parser::Match AdditiveExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match AdditiveOperator(CppLexer& lexer);
    static soulng::parser::Match MultiplicativeExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match MultiplicativeOperator(CppLexer& lexer);
    static soulng::parser::Match PMExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match PMOperator(CppLexer& lexer);
    static soulng::parser::Match CastExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match UnaryExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match UnaryOperator(CppLexer& lexer);
    static soulng::parser::Match NewExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match NewPlacement(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match NewInitializer(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match ExpressionList(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match ArgumentList(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match DeleteExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match PostfixExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match PrimaryExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match CppCastExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match TypeIdExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match IdExpression(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match UnqualifiedId(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match QualifiedId(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match OperatorFunctionId(CppLexer& lexer);
    static soulng::parser::Match Operator(CppLexer& lexer);
    static soulng::parser::Match ConversionFunctionId(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
};

#endif // EXPRESSION_HPP
