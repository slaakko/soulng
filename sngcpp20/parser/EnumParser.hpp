#ifndef ENUMPARSER_HPP
#define ENUMPARSER_HPP
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/symbols/Context.hpp>
#include <sngcpp20/ast/Enum.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/EnumParser.parser' using soulng parser generator spg version 3.1.0

class CppLexer;

struct PARSER_API EnumParser
{
    static soulng::parser::Match EnumName(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match EnumSpecifier(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match EnumHead(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match EnumKey(CppLexer& lexer);
    static soulng::parser::Match EnumHeadName(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match EnumBase(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match EnumeratorList(CppLexer& lexer, sngcpp::symbols::Context* ctx, sngcpp::ast::Node* container);
    static soulng::parser::Match EnumeratorDefinition(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match Enumerator(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ElaboratedEnumSpecifier(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match OpaqueEnumDeclaration(CppLexer& lexer, sngcpp::symbols::Context* ctx);
};

#endif // ENUMPARSER_HPP
