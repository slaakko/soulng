#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP
#include <sngcpp/parser/ParserApi.hpp>
#include <sngcpp/parser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/parser/Template.parser' using soulng parser generator spg version 1.2.0

class CppLexer;

struct SNGCPP_PARSER_API TemplateParser
{
    static soulng::parser::Match TemplateId(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match SimpleTemplateId(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
};

#endif // TEMPLATE_HPP
