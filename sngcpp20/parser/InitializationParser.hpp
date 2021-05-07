#ifndef INITIALIZATIONPARSER_HPP
#define INITIALIZATIONPARSER_HPP
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/symbols/Context.hpp>
#include <sngcpp20/ast/Expression.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/InitializationParser.parser' using soulng parser generator spg version 4.0.0

class CppLexer;

struct PARSER_API InitializationParser
{
    static soulng::parser::Match Initializer(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match InitializerClause(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match DesignatedInitializerClause(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match Designator(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match InitializerList(CppLexer& lexer, sngcpp::symbols::Context* ctx, sngcpp::ast::Node* container);
    static soulng::parser::Match DesignatedInitializerList(CppLexer& lexer, sngcpp::symbols::Context* ctx, sngcpp::ast::Node* container);
    static soulng::parser::Match ExprOrBracedInitList(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match BraceOrEqualInitializer(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match BracedInitList(CppLexer& lexer, sngcpp::symbols::Context* ctx);
};

#endif // INITIALIZATIONPARSER_HPP
