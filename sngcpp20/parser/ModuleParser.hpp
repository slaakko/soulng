#ifndef MODULEPARSER_HPP
#define MODULEPARSER_HPP
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/symbols/Context.hpp>
#include <sngcpp20/ast/Module.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/ModuleParser.parser' using soulng parser generator spg version 3.1.0

class CppLexer;

struct PARSER_API ModuleParser
{
    static soulng::parser::Match ModuleDeclaration(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ExportDeclaration(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ExportKeyword(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ImportKeyword(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ModuleKeyword(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ImportDeclaration(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ModuleName(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ModulePartition(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match GlobalModuleFragment(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match PrivateModuleFragment(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match HeaderName(CppLexer& lexer, sngcpp::symbols::Context* ctx);
};

#endif // MODULEPARSER_HPP
