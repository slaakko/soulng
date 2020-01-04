#ifndef REGEXPARSER_HPP
#define REGEXPARSER_HPP
#include <sng2html/sng2html/RegEx.hpp>
#include <sng2html/sng2html/LexerContext.hpp>
#include <sng2html/sng2html/TokenValueParsers.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/tools/sng2html/sng2html/RegExParser.parser' using soulng parser generator spg version 3.0.0

class RegExLexer;

struct RegExParser
{
    static std::unique_ptr<sng2html::sng2html::RegExpression> Parse(RegExLexer& lexer, sng2html::sng2html::LexerContext* lexerContext);
    static soulng::parser::Match RegularExpression(RegExLexer& lexer, sng2html::sng2html::LexerContext* lexerContext);
    static soulng::parser::Match Alternative(RegExLexer& lexer, sng2html::sng2html::LexerContext* lexerContext);
    static soulng::parser::Match Catenation(RegExLexer& lexer, sng2html::sng2html::LexerContext* lexerContext);
    static soulng::parser::Match Repetition(RegExLexer& lexer, sng2html::sng2html::LexerContext* lexerContext);
    static soulng::parser::Match Primary(RegExLexer& lexer, sng2html::sng2html::LexerContext* lexerContext);
    static soulng::parser::Match Class(RegExLexer& lexer, sng2html::sng2html::LexerContext* lexerContext);
    static soulng::parser::Match Range(RegExLexer& lexer, sng2html::sng2html::LexerContext* lexerContext);
    static soulng::parser::Match Char(RegExLexer& lexer);
    static soulng::parser::Match ExpressionReference(RegExLexer& lexer);
};

#endif // REGEXPARSER_HPP
