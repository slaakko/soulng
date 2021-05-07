#ifndef TRANSLATIONUNITPARSER_HPP
#define TRANSLATIONUNITPARSER_HPP
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/symbols/Context.hpp>
#include <sngcpp20/ast/TranslationUnit.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/TranslationUnitParser.parser' using soulng parser generator spg version 4.0.0

class CppLexer;

struct PARSER_API TranslationUnitParser
{
    static std::unique_ptr<sngcpp::ast::Node> Parse(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match TranslationUnit(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ModuleUnit(CppLexer& lexer, sngcpp::symbols::Context* ctx);
};

#endif // TRANSLATIONUNITPARSER_HPP
