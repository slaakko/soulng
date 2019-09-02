#ifndef LEXERFILE_HPP
#define LEXERFILE_HPP
#include <soulng/slg/Model.hpp>
#include <soulng/slg/TokenValueParsers.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/slg/LexerFile.parser' using soulng parser generator spg version 1.0.0

class LexerFileLexer;

struct LexerFileParser
{
    static std::unique_ptr<soulng::slg::LexerFile> Parse(LexerFileLexer& lexer);
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
    static soulng::parser::Match LexerClause(LexerFileLexer& lexer, soulng::slg::Lexer* currentLexer);
    static soulng::parser::Match Variables(LexerFileLexer& lexer, soulng::slg::Lexer* currentLexer);
    static soulng::parser::Match Variable(LexerFileLexer& lexer);
    static soulng::parser::Match Actions(LexerFileLexer& lexer, soulng::slg::Lexer* currentLexer);
    static soulng::parser::Match Action(LexerFileLexer& lexer);
};

#endif // LEXERFILE_HPP
