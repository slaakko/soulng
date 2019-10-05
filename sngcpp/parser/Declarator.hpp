#ifndef DECLARATOR_HPP
#define DECLARATOR_HPP
#include <sngcpp/parser/ParserApi.hpp>
#include <sngcpp/parser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/parser/Declarator.parser' using soulng parser generator spg version 1.2.0

class CppLexer;

struct SNGCPP_PARSER_API DeclaratorParser
{
    static soulng::parser::Match InitializerClause(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match InitializerList(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match BracedInitializerList(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
};

#endif // DECLARATOR_HPP
