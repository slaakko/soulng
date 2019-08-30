#ifndef CONSTANT_HPP
#define CONSTANT_HPP
#include <soulng/cmajorast/Constant.hpp>
#include <soulng/cmajorparser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/cmajorparser/Constant.parser' using soulng parser generator spg version 1.0.0

class CmajorLexer;

struct ConstantParser
{
    static soulng::parser::Match Constant(CmajorLexer& lexer, ParsingContext* ctx);
};

#endif // CONSTANT_HPP
