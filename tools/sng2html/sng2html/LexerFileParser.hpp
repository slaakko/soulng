#ifndef LEXERFILEPARSER_HPP
#define LEXERFILEPARSER_HPP
#include <sng2html/sng2html/LexerFile.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/tools/sng2html/sng2html/LexerFileParser.parser' using soulng parser generator spg version 4.0.0

class LexerFileLexer;

struct LexerFileParser
{
    static std::unique_ptr<sng2html::sng2html::LexerFile> Parse(LexerFileLexer& lexer);
    static soulng::parser::Match LexerFile(LexerFileLexer& lexer);
    static soulng::parser::Match Declaration(LexerFileLexer& lexer);
    static soulng::parser::Match ClassMap(LexerFileLexer& lexer);
    static soulng::parser::Match Prefix(LexerFileLexer& lexer);
    static soulng::parser::Match Include(LexerFileLexer& lexer);
    static soulng::parser::Match Tokens(LexerFileLexer& lexer);
    static soulng::parser::Match Token(LexerFileLexer& lexer);
    static soulng::parser::Match Keywords(LexerFileLexer& lexer);
    static soulng::parser::Match Keyword(LexerFileLexer& lexer);
    static soulng::parser::Match Expressions(LexerFileLexer& lexer);
    static soulng::parser::Match Expression(LexerFileLexer& lexer, int index);
    static soulng::parser::Match ExprString(LexerFileLexer& lexer);
    static soulng::parser::Match Lexer(LexerFileLexer& lexer);
    static soulng::parser::Match Api(LexerFileLexer& lexer);
    static soulng::parser::Match LexerClause(LexerFileLexer& lexer, sng2html::sng2html::Lexer* currentLexer);
    static soulng::parser::Match Variables(LexerFileLexer& lexer, sng2html::sng2html::Lexer* currentLexer);
    static soulng::parser::Match Variable(LexerFileLexer& lexer);
    static soulng::parser::Match Actions(LexerFileLexer& lexer, sng2html::sng2html::Lexer* currentLexer);
    static soulng::parser::Match Action(LexerFileLexer& lexer);
};

#endif // LEXERFILEPARSER_HPP
