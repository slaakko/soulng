#ifndef BASICTYPE_HPP
#define BASICTYPE_HPP
#include <sngcm/parser/ParserApi.hpp>
#include <sngcm/ast/BasicType.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcm/parser/BasicType.parser' using soulng parser generator spg version 2.0.0

class CmajorLexer;

struct SNGCM_PARSER_API BasicTypeParser
{
    static soulng::parser::Match BasicType(CmajorLexer& lexer);
};

#endif // BASICTYPE_HPP
