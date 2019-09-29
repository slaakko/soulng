#ifndef TYPEEXPR_HPP
#define TYPEEXPR_HPP
#include <cmajor/parser/ParserApi.hpp>
#include <cmajor/ast/Identifier.hpp>
#include <cmajor/ast/Expression.hpp>
#include <cmajor/ast/TypeExpr.hpp>
#include <cmajor/parser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/TypeExpr.parser' using soulng parser generator spg version 1.2.0

class CmajorLexer;

struct CMAJOR_PARSER_API TypeExprParser
{
    static soulng::parser::Match TypeExpr(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match PrefixTypeExpr(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match PostfixTypeExpr(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match PrimaryTypeExpr(CmajorLexer& lexer, ParsingContext* ctx);
};

#endif // TYPEEXPR_HPP
