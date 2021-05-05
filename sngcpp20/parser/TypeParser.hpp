#ifndef TYPEPARSER_HPP
#define TYPEPARSER_HPP
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/parser/Context.hpp>
#include <sngcpp20/ast/Type.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/TypeParser.parser' using soulng parser generator spg version 4.0.0

class CppLexer;

struct PARSER_API TypeParser
{
    static soulng::parser::Match TypeSpecifierSeq(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match DefiningTypeId(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match DefiningTypeSpecifierSeq(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match DefiningTypeSpecifier(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match TypeSpecifier(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match ElaboratedTypeSpecifier(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match SimpleTypeSpecifier(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match TypeName(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match TypeId(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match TypenameSpecifier(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match DeclTypeSpecifier(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match PlaceholderTypeSpecifier(CppLexer& lexer, sngcpp::par::Context* ctx);
};

#endif // TYPEPARSER_HPP
