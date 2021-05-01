#ifndef ATTRIBUTEPARSER_HPP
#define ATTRIBUTEPARSER_HPP
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/parser/Context.hpp>
#include <sngcpp20/ast/Attribute.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/AttributeParser.parser' using soulng parser generator spg version 3.11.0

class CppLexer;

struct PARSER_API AttributeParser
{
    static soulng::parser::Match AttributeSpecifierSeq(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match AttributeSpecifier(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match AttributeList(CppLexer& lexer, sngcpp::par::Context* ctx, sngcpp::ast::Node* container);
    static soulng::parser::Match AttributeUsingPrefix(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match AttributeNamespace(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match Attribute(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match AttributeToken(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match AttributeScopedToken(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match AttributeArgumentClause(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match BalancedTokenSeq(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match BalancedToken(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match AlignmentSpecifier(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match LParen(CppLexer& lexer);
    static soulng::parser::Match RParen(CppLexer& lexer);
    static soulng::parser::Match LBracket(CppLexer& lexer);
    static soulng::parser::Match RBracket(CppLexer& lexer);
    static soulng::parser::Match LBrace(CppLexer& lexer);
    static soulng::parser::Match RBrace(CppLexer& lexer);
};

#endif // ATTRIBUTEPARSER_HPP
