#ifndef STATEMENTPARSER_HPP
#define STATEMENTPARSER_HPP
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/symbols/Context.hpp>
#include <sngcpp20/ast/Identifier.hpp>
#include <sngcpp20/ast/Statement.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/StatementParser.parser' using soulng parser generator spg version 4.0.0

class CppLexer;

struct PARSER_API StatementParser
{
    static soulng::parser::Match Statement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match LabeledStatement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match CompoundStatementUnguarded(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match CompoundStatementGuarded(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match CompoundStatementSaved(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match CompoundStatement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match SelectionStatement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match IfStatement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match SwitchStatement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match IterationStatement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match WhileStatement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match DoStatement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match RangeForStatement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ForRangeDeclaration(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ForRangeInitializer(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ForStatement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match JumpStatement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match BreakStatement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ContinueStatement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ReturnStatement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match CoroutineReturnStatement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match GotoStatement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match TryStatement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match HandlerSeq(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match Handler(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ExceptionDeclaration(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match DeclarationStatement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ExpressionStatement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match InitStatement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match Condition(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match Semicolon(CppLexer& lexer);
};

#endif // STATEMENTPARSER_HPP
