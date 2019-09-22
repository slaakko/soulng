#ifndef BASICTYPE_HPP
#define BASICTYPE_HPP
#include <cmajor/parser/ParserApi.hpp>
#include <cmajor/ast/BasicType.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/BasicType.parser' using soulng parser generator spg version 1.1.0

class CmajorLexer;

struct CMAJOR_PARSER_API BasicTypeParser
{
    static soulng::parser::Match BasicType(CmajorLexer& lexer);
};

#endif // BASICTYPE_HPP
