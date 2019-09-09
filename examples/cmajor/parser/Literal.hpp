#ifndef LITERAL_HPP
#define LITERAL_HPP
#include <cmajor/parser/ParserApi.hpp>
#include <cmajor/ast/Literal.hpp>
#include <cmajor/parser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/Literal.parser' using soulng parser generator spg version 1.0.0

class CmajorLexer;

struct CMAJOR_PARSER_API LiteralParser
{
    static soulng::parser::Match Literal(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match SimpleLiteral(CmajorLexer& lexer);
    static soulng::parser::Match ComplexLiteral(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match ArrayLiteral(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match StructuredLiteral(CmajorLexer& lexer, ParsingContext* ctx);
};

#endif // LITERAL_HPP
