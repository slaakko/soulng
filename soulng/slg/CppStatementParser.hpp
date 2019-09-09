#ifndef CPPSTATEMENTPARSER_HPP
#define CPPSTATEMENTPARSER_HPP
#include <soulng/cppcode/Statement.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/soulng/slg/CppStatementParser.parser' using soulng parser generator spg version 1.0.0

class LexerFileLexer;

struct CppStatementParser
{
    static soulng::parser::Match Statement(LexerFileLexer& lexer);
    static soulng::parser::Match LabeledStatement(LexerFileLexer& lexer);
    static soulng::parser::Match EmptyStatement(LexerFileLexer& lexer);
    static soulng::parser::Match CompoundStatement(LexerFileLexer& lexer);
    static soulng::parser::Match SelectionStatement(LexerFileLexer& lexer);
    static soulng::parser::Match IfStatement(LexerFileLexer& lexer);
    static soulng::parser::Match SwitchStatement(LexerFileLexer& lexer);
    static soulng::parser::Match IterationStatement(LexerFileLexer& lexer);
    static soulng::parser::Match WhileStatement(LexerFileLexer& lexer);
    static soulng::parser::Match DoStatement(LexerFileLexer& lexer);
    static soulng::parser::Match RangeForStatement(LexerFileLexer& lexer);
    static soulng::parser::Match ForRangeDeclaration(LexerFileLexer& lexer);
    static soulng::parser::Match ForStatement(LexerFileLexer& lexer);
    static soulng::parser::Match ForInitStatement(LexerFileLexer& lexer);
    static soulng::parser::Match JumpStatement(LexerFileLexer& lexer);
    static soulng::parser::Match BreakStatement(LexerFileLexer& lexer);
    static soulng::parser::Match ContinueStatement(LexerFileLexer& lexer);
    static soulng::parser::Match ReturnStatement(LexerFileLexer& lexer);
    static soulng::parser::Match GotoStatement(LexerFileLexer& lexer);
    static soulng::parser::Match DeclarationStatement(LexerFileLexer& lexer);
    static soulng::parser::Match Condition(LexerFileLexer& lexer);
    static soulng::parser::Match TryStatement(LexerFileLexer& lexer);
    static soulng::parser::Match HandlerSeq(LexerFileLexer& lexer, soulng::cppcode::TryStatement* tryStatement);
    static soulng::parser::Match Handler(LexerFileLexer& lexer);
    static soulng::parser::Match ExceptionDeclaration(LexerFileLexer& lexer);
    static soulng::parser::Match ExpressionStatement(LexerFileLexer& lexer);
};

#endif // CPPSTATEMENTPARSER_HPP
