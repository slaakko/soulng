#ifndef TYPEEXPR_HPP
#define TYPEEXPR_HPP
#include <soulng/cmajorast/Identifier.hpp>
#include <soulng/cmajorast/Expression.hpp>
#include <soulng/cmajorast/TypeExpr.hpp>
#include <soulng/cmajorparser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/cmajorparser/TypeExpr.parser' using soulng parser generator spg version 1.0.0

class CmajorLexer;

struct TypeExprParser
{
    static soulng::parser::Match TypeExpr(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match PrefixTypeExpr(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match PostfixTypeExpr(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match PrimaryTypeExpr(CmajorLexer& lexer, ParsingContext* ctx);
};

#endif // TYPEEXPR_HPP
