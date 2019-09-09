#ifndef TYPEDEF_HPP
#define TYPEDEF_HPP
#include <soulng/cmajorast/Typedef.hpp>
#include <soulng/cmajorparser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/cmajorparser/Typedef.parser' using soulng parser generator spg version 1.0.0

class CmajorLexer;

struct TypedefParser
{
    static soulng::parser::Match Typedef(CmajorLexer& lexer, ParsingContext* ctx);
};

#endif // TYPEDEF_HPP
