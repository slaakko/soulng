#ifndef CONSTANT_HPP
#define CONSTANT_HPP
#include <cmajor/parser/ParserApi.hpp>
#include <cmajor/ast/Constant.hpp>
#include <cmajor/parser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/Constant.parser' using soulng parser generator spg version 2.0.0

class CmajorLexer;

struct CMAJOR_PARSER_API ConstantParser
{
    static soulng::parser::Match Constant(CmajorLexer& lexer, ParsingContext* ctx);
};

#endif // CONSTANT_HPP
