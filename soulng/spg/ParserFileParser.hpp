#ifndef PARSERFILEPARSER_HPP
#define PARSERFILEPARSER_HPP
#include <soulng/spg/ParserFile.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/soulng/spg/ParserFileParser.parser' using soulng parser generator spg version 4.0.0

class ParserFileLexer;

struct ParserFileParser
{
    static std::unique_ptr<soulng::spg::ParserFile> Parse(ParserFileLexer& lexer);
    static soulng::parser::Match ParserFile(ParserFileLexer& lexer);
    static soulng::parser::Match Declaration(ParserFileLexer& lexer, soulng::spg::ParserFile* parserFile);
    static soulng::parser::Match IncludeDeclaration(ParserFileLexer& lexer);
    static soulng::parser::Match IncludePrefix(ParserFileLexer& lexer);
    static soulng::parser::Match UsingNamespaceDeclaration(ParserFileLexer& lexer);
    static soulng::parser::Match ParserDeclaration(ParserFileLexer& lexer);
    static soulng::parser::Match Api(ParserFileLexer& lexer);
    static soulng::parser::Match Statement(ParserFileLexer& lexer, soulng::spg::GrammarParser* grammarParser);
    static soulng::parser::Match MainStatement(ParserFileLexer& lexer, soulng::spg::GrammarParser* grammarParser);
    static soulng::parser::Match StartStatement(ParserFileLexer& lexer, soulng::spg::GrammarParser* grammarParser);
    static soulng::parser::Match NothrowStatement(ParserFileLexer& lexer, soulng::spg::GrammarParser* grammarParser);
    static soulng::parser::Match FarthestErrorStatement(ParserFileLexer& lexer, soulng::spg::GrammarParser* grammarParser);
    static soulng::parser::Match StateStatement(ParserFileLexer& lexer, soulng::spg::GrammarParser* grammarParser);
    static soulng::parser::Match UsingStatement(ParserFileLexer& lexer, soulng::spg::GrammarParser* grammarParser);
    static soulng::parser::Match UsingQualifiedId(ParserFileLexer& lexer);
    static soulng::parser::Match LexerStatement(ParserFileLexer& lexer, soulng::spg::GrammarParser* grammarParser);
    static soulng::parser::Match RuleInfoStatement(ParserFileLexer& lexer, soulng::spg::GrammarParser* grammarParser);
    static soulng::parser::Match RuleInfo(ParserFileLexer& lexer, soulng::spg::GrammarParser* grammarParser);
    static soulng::parser::Match RuleStatement(ParserFileLexer& lexer, soulng::spg::GrammarParser* grammarParser);
    static soulng::parser::Match ParametersAndVariables(ParserFileLexer& lexer, soulng::spg::RuleParser* rule);
    static soulng::parser::Match ParamOrVariable(ParserFileLexer& lexer);
    static soulng::parser::Match ReturnType(ParserFileLexer& lexer);
    static soulng::parser::Match RuleBody(ParserFileLexer& lexer);
    static soulng::parser::Match Alternative(ParserFileLexer& lexer);
    static soulng::parser::Match Sequence(ParserFileLexer& lexer);
    static soulng::parser::Match Difference(ParserFileLexer& lexer);
    static soulng::parser::Match List(ParserFileLexer& lexer);
    static soulng::parser::Match Postfix(ParserFileLexer& lexer);
    static soulng::parser::Match Primary(ParserFileLexer& lexer);
    static soulng::parser::Match RuleCall(ParserFileLexer& lexer);
    static soulng::parser::Match Nonterminal(ParserFileLexer& lexer);
    static soulng::parser::Match Primitive(ParserFileLexer& lexer);
    static soulng::parser::Match Grouping(ParserFileLexer& lexer);
};

#endif // PARSERFILEPARSER_HPP
