#ifndef PARSERFILEPARSER_HPP
#define PARSERFILEPARSER_HPP
#include <sng2html/sng2html/ParserFile.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/tools/sng2html/sng2html/ParserFileParser.parser' using soulng parser generator spg version 4.0.0

class ParserFileLexer;

struct ParserFileParser
{
    static std::unique_ptr<sng2html::sng2html::ParserFile> Parse(ParserFileLexer& lexer);
    static soulng::parser::Match ParserFile(ParserFileLexer& lexer);
    static soulng::parser::Match Declaration(ParserFileLexer& lexer, sng2html::sng2html::ParserFile* parserFile);
    static soulng::parser::Match IncludeDeclaration(ParserFileLexer& lexer);
    static soulng::parser::Match IncludePrefix(ParserFileLexer& lexer);
    static soulng::parser::Match UsingNamespaceDeclaration(ParserFileLexer& lexer);
    static soulng::parser::Match ParserDeclaration(ParserFileLexer& lexer);
    static soulng::parser::Match Api(ParserFileLexer& lexer);
    static soulng::parser::Match Statement(ParserFileLexer& lexer, sng2html::sng2html::GrammarParser* grammarParser);
    static soulng::parser::Match MainStatement(ParserFileLexer& lexer, sng2html::sng2html::GrammarParser* grammarParser);
    static soulng::parser::Match UsingStatement(ParserFileLexer& lexer, sng2html::sng2html::GrammarParser* grammarParser);
    static soulng::parser::Match UsingQualifiedId(ParserFileLexer& lexer);
    static soulng::parser::Match LexerStatement(ParserFileLexer& lexer, sng2html::sng2html::GrammarParser* grammarParser);
    static soulng::parser::Match RuleInfoStatement(ParserFileLexer& lexer, sng2html::sng2html::GrammarParser* grammarParser);
    static soulng::parser::Match RuleInfo(ParserFileLexer& lexer, sng2html::sng2html::GrammarParser* grammarParser);
    static soulng::parser::Match RuleStatement(ParserFileLexer& lexer, sng2html::sng2html::GrammarParser* grammarParser);
    static soulng::parser::Match ParametersAndVariables(ParserFileLexer& lexer, sng2html::sng2html::RuleParser* rule);
    static soulng::parser::Match ParamOrVariable(ParserFileLexer& lexer);
    static soulng::parser::Match ReturnType(ParserFileLexer& lexer);
    static soulng::parser::Match RuleBody(ParserFileLexer& lexer);
    static soulng::parser::Match Alternative(ParserFileLexer& lexer);
    static soulng::parser::Match Sequence(ParserFileLexer& lexer);
    static soulng::parser::Match Difference(ParserFileLexer& lexer);
    static soulng::parser::Match List(ParserFileLexer& lexer);
    static soulng::parser::Match Prefix(ParserFileLexer& lexer);
    static soulng::parser::Match Postfix(ParserFileLexer& lexer);
    static soulng::parser::Match Primary(ParserFileLexer& lexer);
    static soulng::parser::Match RuleCall(ParserFileLexer& lexer);
    static soulng::parser::Match Nonterminal(ParserFileLexer& lexer);
    static soulng::parser::Match Primitive(ParserFileLexer& lexer);
    static soulng::parser::Match Grouping(ParserFileLexer& lexer);
};

#endif // PARSERFILEPARSER_HPP
