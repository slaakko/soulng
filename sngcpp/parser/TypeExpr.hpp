#ifndef TYPEEXPR_HPP
#define TYPEEXPR_HPP
#include <sngcpp/parser/ParserApi.hpp>
#include <sngcpp/parser/ParsingContext.hpp>
#include <sngcpp/ast/TypeExpr.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/parser/TypeExpr.parser' using soulng parser generator spg version 3.0.0

class CppLexer;

struct SNGCPP_PARSER_API TypeExprParser
{
    static soulng::parser::Match TypeExpr(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match PrefixTypeExpr(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match CVSpecifierSequence(CppLexer& lexer);
    static soulng::parser::Match CVSpecifier(CppLexer& lexer);
    static soulng::parser::Match PostfixTypeExpr(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match PrimaryTypeExpr(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
};

#endif // TYPEEXPR_HPP
