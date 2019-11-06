#ifndef CONSTANT_HPP
#define CONSTANT_HPP
#include <sngcm/parser/ParserApi.hpp>
#include <sngcm/ast/Constant.hpp>
#include <sngcm/parser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcm/parser/Constant.parser' using soulng parser generator spg version 2.0.0

class CmajorLexer;

struct SNGCM_PARSER_API ConstantParser
{
    static soulng::parser::Match Constant(CmajorLexer& lexer, ParsingContext* ctx);
};

#endif // CONSTANT_HPP
