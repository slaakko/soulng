#ifndef ENUMERATION_HPP
#define ENUMERATION_HPP
#include <sngcpp/parser/ParserApi.hpp>
#include <sngcpp/parser/ParsingContext.hpp>
#include <sngcpp/ast/Enumeration.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/parser/Enumeration.parser' using soulng parser generator spg version 2.0.0

class CppLexer;

struct SNGCPP_PARSER_API EnumerationParser
{
    static soulng::parser::Match EnumDeclaration(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match EnumSpecifier(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match EnumHead(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match OpaqueEnumDeclaration(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match EnumKey(CppLexer& lexer);
    static soulng::parser::Match EnumName(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match EnumBase(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match Enumerators(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx, sngcpp::ast::EnumTypeNode* enumTypeNode);
    static soulng::parser::Match EnumeratorDefinition(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match Enumerator(CppLexer& lexer);
};

#endif // ENUMERATION_HPP
