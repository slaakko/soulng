#ifndef IDENTIFIER_HPP
#define IDENTIFIER_HPP
#include <sngcpp/parser/ParserApi.hpp>
#include <sngcpp/ast/Expression.hpp>
#include <sngcpp/parser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/parser/Identifier.parser' using soulng parser generator spg version 3.0.0

class CppLexer;

struct SNGCPP_PARSER_API IdentifierParser
{
    static soulng::parser::Match Identifier(CppLexer& lexer);
    static soulng::parser::Match IdNode(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match NestedNameSpecifier(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match QualifiedIdNode(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
};

#endif // IDENTIFIER_HPP
