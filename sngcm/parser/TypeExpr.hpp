#ifndef TYPEEXPR_HPP
#define TYPEEXPR_HPP
#include <sngcm/parser/ParserApi.hpp>
#include <sngcm/ast/Identifier.hpp>
#include <sngcm/ast/Expression.hpp>
#include <sngcm/ast/TypeExpr.hpp>
#include <sngcm/parser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcm/parser/TypeExpr.parser' using soulng parser generator spg version 2.0.0

class CmajorLexer;

struct SNGCM_PARSER_API TypeExprParser
{
    static soulng::parser::Match TypeExpr(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match PrefixTypeExpr(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match PostfixTypeExpr(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match PrimaryTypeExpr(CmajorLexer& lexer, ParsingContext* ctx);
};

#endif // TYPEEXPR_HPP
