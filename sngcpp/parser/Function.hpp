#ifndef FUNCTION_HPP
#define FUNCTION_HPP
#include <sngcpp/parser/ParserApi.hpp>
#include <sngcpp/parser/ParsingContext.hpp>
#include <sngcpp/ast/Function.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/parser/Function.parser' using soulng parser generator spg version 3.0.0

class CppLexer;

struct SNGCPP_PARSER_API FunctionParser
{
    static soulng::parser::Match FunctionDefinition(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match FunctionBody(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match ParameterList(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match ParameterDeclaration(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
};

#endif // FUNCTION_HPP
