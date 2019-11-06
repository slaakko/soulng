#ifndef TYPEDEF_HPP
#define TYPEDEF_HPP
#include <sngcm/parser/ParserApi.hpp>
#include <sngcm/ast/Typedef.hpp>
#include <sngcm/parser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcm/parser/Typedef.parser' using soulng parser generator spg version 2.0.0

class CmajorLexer;

struct SNGCM_PARSER_API TypedefParser
{
    static soulng::parser::Match Typedef(CmajorLexer& lexer, ParsingContext* ctx);
};

#endif // TYPEDEF_HPP
