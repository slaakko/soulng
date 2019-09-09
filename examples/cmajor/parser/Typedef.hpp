#ifndef TYPEDEF_HPP
#define TYPEDEF_HPP
#include <cmajor/parser/ParserApi.hpp>
#include <cmajor/ast/Typedef.hpp>
#include <cmajor/parser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/Typedef.parser' using soulng parser generator spg version 1.0.0

class CmajorLexer;

struct CMAJOR_PARSER_API TypedefParser
{
    static soulng::parser::Match Typedef(CmajorLexer& lexer, ParsingContext* ctx);
};

#endif // TYPEDEF_HPP
