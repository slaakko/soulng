#ifndef ENUMERATION_HPP
#define ENUMERATION_HPP
#include <cmajorast/Enumeration.hpp>
#include <cmajorparser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/cmajorparser/Enumeration.parser' using soulng parser generator spg version 1.0.0

class CmajorLexer;

struct EnumerationParser
{
    static soulng::parser::Match EnumType(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match UnderlyingType(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match EnumConstants(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::EnumTypeNode* enumType);
    static soulng::parser::Match EnumConstant(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::EnumTypeNode* enumType);
};

#endif // ENUMERATION_HPP
