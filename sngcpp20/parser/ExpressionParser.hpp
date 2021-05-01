#ifndef EXPRESSIONPARSER_HPP
#define EXPRESSIONPARSER_HPP
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/parser/Context.hpp>
#include <sngcpp20/ast/Expression.hpp>
#include <sngcpp20/ast/Identifier.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/ExpressionParser.parser' using soulng parser generator spg version 3.11.0

class CppLexer;

struct PARSER_API ExpressionParser
{
    static soulng::parser::Match Expression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match ConstantExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match AssignmentExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match AssignmentOp(CppLexer& lexer);
    static soulng::parser::Match ConditionalExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match Quest(CppLexer& lexer);
    static soulng::parser::Match Colon(CppLexer& lexer);
    static soulng::parser::Match YieldExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match ThrowExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match LogicalOrExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match LogicalAndExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match InclusiveOrExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match ExclusiveOrExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match AndExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match EqualityExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match EqualityOp(CppLexer& lexer);
    static soulng::parser::Match RelationalExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match RelationalOp(CppLexer& lexer);
    static soulng::parser::Match CompareExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match ShiftExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match ShiftOp(CppLexer& lexer);
    static soulng::parser::Match AdditiveExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match AdditiveOp(CppLexer& lexer);
    static soulng::parser::Match MultiplicativeExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match MultiplicativeOp(CppLexer& lexer);
    static soulng::parser::Match PmExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match PmOp(CppLexer& lexer);
    static soulng::parser::Match CastExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match UnaryExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match UnaryOp(CppLexer& lexer);
    static soulng::parser::Match AwaitExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match SizeOfExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match AlignOfExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match NoexceptEpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match NewExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match NewPlacement(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match NewTypeId(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match DeleteExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match PostfixExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match DotOp(CppLexer& lexer);
    static soulng::parser::Match ArrowOp(CppLexer& lexer);
    static soulng::parser::Match TypeIdExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match CppCastExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match PrimaryExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match ParenthesizedExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match IdExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match FoldExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match Ellipses(CppLexer& lexer);
    static soulng::parser::Match FoldOp(CppLexer& lexer);
    static soulng::parser::Match NewDeclarator(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match NoPtrNewDeclarator(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match NewInitializer(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match ExpressionList(CppLexer& lexer, sngcpp::par::Context* ctx, sngcpp::ast::Node* container);
};

#endif // EXPRESSIONPARSER_HPP
