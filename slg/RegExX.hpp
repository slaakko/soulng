#ifndef REGEX_HPP
#define REGEX_HPP
#include <soulng/slg/LexerContext.hpp>
#include <soulng/slg/TokenValueParsers.hpp>
#include <soulng/slg/Nfa.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/slg/RegEx.parser' using soulng parser generator spg version 1.0.0

class RegExLexer;

struct RegExParser
{
    static soulng::slg::Nfa Parse(RegExLexer& lexer, soulng::slg::LexerContext* lexerContext);
    static soulng::parser::Match RegularExpression(RegExLexer& lexer, soulng::slg::LexerContext* lexerContext);
    static soulng::parser::Match Alternative(RegExLexer& lexer, soulng::slg::LexerContext* lexerContext);
    static soulng::parser::Match Catenation(RegExLexer& lexer, soulng::slg::LexerContext* lexerContext);
    static soulng::parser::Match Repetition(RegExLexer& lexer, soulng::slg::LexerContext* lexerContext);
    static soulng::parser::Match Primary(RegExLexer& lexer, soulng::slg::LexerContext* lexerContext);
    static soulng::parser::Match Class(RegExLexer& lexer, soulng::slg::LexerContext* lexerContext);
    static soulng::parser::Match Range(RegExLexer& lexer, soulng::slg::LexerContext* lexerContext);
    static soulng::parser::Match Char(RegExLexer& lexer);
    static soulng::parser::Match ExpressionReference(RegExLexer& lexer);
};

#endif // REGEX_HPP
