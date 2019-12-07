#ifndef DECLARATION_HPP
#define DECLARATION_HPP
#include <sngcpp/parser/ParserApi.hpp>
#include <sngcpp/parser/ParsingContext.hpp>
#include <sngcpp/ast/Declaration.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/parser/Declaration.parser' using soulng parser generator spg version 3.0.0

class CppLexer;

struct SNGCPP_PARSER_API DeclarationParser
{
    static soulng::parser::Match Declaration(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match NamespaceDefinition(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match NamedNamespaceDefinition(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match UnnamedNamespaceDefinition(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match BlockDeclaration(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match SimpleDeclaration(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match DeclSpecifiers(CppLexer& lexer);
    static soulng::parser::Match DeclSpecifier(CppLexer& lexer);
    static soulng::parser::Match StorageClassSpecifier(CppLexer& lexer);
    static soulng::parser::Match FunctionSpecifier(CppLexer& lexer);
    static soulng::parser::Match AliasDeclaration(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match UsingDirective(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match UsingDeclaration(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match TypedefDeclaration(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match LinkageSpecification(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
};

#endif // DECLARATION_HPP
