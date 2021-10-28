#ifndef FUNCTIONPARSER_HPP
#define FUNCTIONPARSER_HPP
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/symbols/Context.hpp>
#include <sngcpp20/ast/Function.hpp>
#include <sngcpp20/ast/Expression.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/FunctionParser.parser' using soulng parser generator spg version 3.1.0

class CppLexer;

struct PARSER_API FunctionParser
{
    static soulng::parser::Match FunctionDefinition(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match FunctionBody(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match Default(CppLexer& lexer);
    static soulng::parser::Match Delete(CppLexer& lexer);
    static soulng::parser::Match NoDeclSpecFunctionDeclaration(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ParameterDeclarationClause(CppLexer& lexer, sngcpp::symbols::Context* ctx, sngcpp::ast::Node* container);
    static soulng::parser::Match ParameterDeclarationList(CppLexer& lexer, sngcpp::symbols::Context* ctx, sngcpp::ast::Node* container);
    static soulng::parser::Match Comma(CppLexer& lexer);
    static soulng::parser::Match ParameterDeclaration(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match Assign(CppLexer& lexer);
    static soulng::parser::Match OperatorFunctionId(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ConversionFunctionId(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match DestructorId(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ConversionTypeId(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ConversionDeclarator(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match OperatorKw(CppLexer& lexer);
    static soulng::parser::Match Operator(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match Noexcept(CppLexer& lexer);
    static soulng::parser::Match FunctionTryBlock(CppLexer& lexer, sngcpp::symbols::Context* ctx);
};

#endif // FUNCTIONPARSER_HPP
