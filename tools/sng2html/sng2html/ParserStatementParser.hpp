#ifndef PARSERSTATEMENTPARSER_HPP
#define PARSERSTATEMENTPARSER_HPP
#include <soulng/cppcode/Statement.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/tools/sng2html/sng2html/ParserStatementParser.parser' using soulng parser generator spg version 4.0.0

class ParserFileLexer;

struct ParserStatementParser
{
    static soulng::parser::Match Statement(ParserFileLexer& lexer);
    static soulng::parser::Match LabeledStatement(ParserFileLexer& lexer);
    static soulng::parser::Match EmptyStatement(ParserFileLexer& lexer);
    static soulng::parser::Match CompoundStatement(ParserFileLexer& lexer);
    static soulng::parser::Match SelectionStatement(ParserFileLexer& lexer);
    static soulng::parser::Match IfStatement(ParserFileLexer& lexer);
    static soulng::parser::Match SwitchStatement(ParserFileLexer& lexer);
    static soulng::parser::Match IterationStatement(ParserFileLexer& lexer);
    static soulng::parser::Match WhileStatement(ParserFileLexer& lexer);
    static soulng::parser::Match DoStatement(ParserFileLexer& lexer);
    static soulng::parser::Match RangeForStatement(ParserFileLexer& lexer);
    static soulng::parser::Match ForRangeDeclaration(ParserFileLexer& lexer);
    static soulng::parser::Match ForStatement(ParserFileLexer& lexer);
    static soulng::parser::Match ForInitStatement(ParserFileLexer& lexer);
    static soulng::parser::Match JumpStatement(ParserFileLexer& lexer);
    static soulng::parser::Match BreakStatement(ParserFileLexer& lexer);
    static soulng::parser::Match ContinueStatement(ParserFileLexer& lexer);
    static soulng::parser::Match ReturnStatement(ParserFileLexer& lexer);
    static soulng::parser::Match GotoStatement(ParserFileLexer& lexer);
    static soulng::parser::Match DeclarationStatement(ParserFileLexer& lexer);
    static soulng::parser::Match Condition(ParserFileLexer& lexer);
    static soulng::parser::Match TryStatement(ParserFileLexer& lexer);
    static soulng::parser::Match HandlerSeq(ParserFileLexer& lexer, soulng::cppcode::TryStatement* tryStatement);
    static soulng::parser::Match Handler(ParserFileLexer& lexer);
    static soulng::parser::Match ExceptionDeclaration(ParserFileLexer& lexer);
    static soulng::parser::Match ExpressionStatement(ParserFileLexer& lexer);
};

#endif // PARSERSTATEMENTPARSER_HPP
