#ifndef BASICTYPE_HPP
#define BASICTYPE_HPP
#include <soulng/cmajorast/BasicType.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/cmajorparser/BasicType.parser' using soulng parser generator spg version 1.0.0

class CmajorLexer;

struct BasicTypeParser
{
    static soulng::parser::Match BasicType(CmajorLexer& lexer);
};

#endif // BASICTYPE_HPP
