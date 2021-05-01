#ifndef LAMBDAPARSER_HPP
#define LAMBDAPARSER_HPP
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/parser/Context.hpp>
#include <sngcpp20/ast/Lambda.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/LambdaParser.parser' using soulng parser generator spg version 3.11.0

class CppLexer;

struct PARSER_API LambdaParser
{
    static soulng::parser::Match LambdaExpression(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match LambdaIntroducer(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match LambdaCapture(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match CaptureDefault(CppLexer& lexer);
    static soulng::parser::Match CaptureList(CppLexer& lexer, sngcpp::par::Context* ctx, sngcpp::ast::Node* container);
    static soulng::parser::Match Capture(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match InitCapture(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match SimpleCapture(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match LambdaDeclarator(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match LambdaSpecifiers(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match LambdaTemplateParams(CppLexer& lexer, sngcpp::par::Context* ctx);
};

#endif // LAMBDAPARSER_HPP
