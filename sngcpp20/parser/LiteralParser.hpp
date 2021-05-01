#ifndef LITERALPARSER_HPP
#define LITERALPARSER_HPP
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/parser/Context.hpp>
#include <sngcpp20/ast/Literal.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/LiteralParser.parser' using soulng parser generator spg version 3.11.0

class CppLexer;

struct PARSER_API LiteralParser
{
    static soulng::parser::Match Literal(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match UserDefinedLiteral(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match UdSuffix(CppLexer& lexer);
    static soulng::parser::Match LiteralOperatorId(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match StringLiteral(CppLexer& lexer, sngcpp::par::Context* ctx);
};

#endif // LITERALPARSER_HPP
