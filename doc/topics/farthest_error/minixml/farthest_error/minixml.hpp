#ifndef MINIXML_HPP
#define MINIXML_HPP
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/doc/topics/syntax/minixml/farthest_error/minixml.parser' using soulng parser generator spg version 3.1.0

class TrivialLexer;

struct minixml
{
    static void Parse(TrivialLexer& lexer);
    static soulng::parser::Match document(TrivialLexer& lexer);
    static soulng::parser::Match element(TrivialLexer& lexer);
    static soulng::parser::Match spaces(TrivialLexer& lexer);
    static soulng::parser::Match name(TrivialLexer& lexer);
    static soulng::parser::Match name_start_char(TrivialLexer& lexer);
    static soulng::parser::Match name_char(TrivialLexer& lexer);
    static soulng::parser::Match element_content(TrivialLexer& lexer);
    static soulng::parser::Match text(TrivialLexer& lexer);
};

#endif // MINIXML_HPP
