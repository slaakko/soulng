#ifndef STATEMENT_HPP
#define STATEMENT_HPP
#include <sngcpp/parser/ParserApi.hpp>
#include <sngcpp/ast/Statement.hpp>
#include <sngcpp/parser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/parser/Statement.parser' using soulng parser generator spg version 3.0.0

class CppLexer;

struct SNGCPP_PARSER_API StatementParser
{
    static soulng::parser::Match Statement(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match LabeledStatement(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match ExpressionStatement(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match CompoundStatement(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match SelectionStatement(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match IterationStatement(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match JumpStatement(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match DeclarationStatement(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match TryStatement(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match HandlerSequence(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx, sngcpp::ast::TryStatementNode* tryStatementNode);
    static soulng::parser::Match Handler(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match Condition(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match ForRangeDeclaration(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match ForRangeInitializer(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match ForInitStatement(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match ExceptionDeclaration(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
};

#endif // STATEMENT_HPP
