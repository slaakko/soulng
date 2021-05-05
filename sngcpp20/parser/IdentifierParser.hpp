#ifndef IDENTIFIERPARSER_HPP
#define IDENTIFIERPARSER_HPP
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/parser/Context.hpp>
#include <sngcpp20/ast/Expression.hpp>
#include <sngcpp20/ast/Identifier.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/IdentifierParser.parser' using soulng parser generator spg version 4.0.0

class CppLexer;

struct PARSER_API IdentifierParser
{
    static soulng::parser::Match Identifier(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match TypeIdentifier(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match UnqualifiedId(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match QualifiedId(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match Template(CppLexer& lexer);
    static soulng::parser::Match NestedNameSpecifier(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match IdentifierList(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match Unnamed(CppLexer& lexer);
    static soulng::parser::Match Dot(CppLexer& lexer);
    static soulng::parser::Match ColonColon(CppLexer& lexer);
};

#endif // IDENTIFIERPARSER_HPP
