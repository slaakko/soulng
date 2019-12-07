#ifndef LITERAL_HPP
#define LITERAL_HPP
#include <sngcpp/parser/ParserApi.hpp>
#include <sngcpp/parser/TokenValueParsers.hpp>
#include <sngcpp/ast/Literal.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/parser/Literal.parser' using soulng parser generator spg version 3.0.0

class CppLexer;

struct SNGCPP_PARSER_API LiteralParser
{
    static soulng::parser::Match Literal(CppLexer& lexer);
    static soulng::parser::Match StringLiteral(CppLexer& lexer);
    static soulng::parser::Match IntegerLiteral(CppLexer& lexer);
};

#endif // LITERAL_HPP
