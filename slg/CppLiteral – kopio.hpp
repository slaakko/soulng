#ifndef CPPLITERAL_HPP
#define CPPLITERAL_HPP
#include <soulng/cppcode/Literal.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/slg/CppLiteral.parser' using soulng parser generator spg version 1.0.0

class LexerFileLexer;

struct CppLiteralParser
{
    static soulng::parser::Match CppLiteral(LexerFileLexer& lexer);
};

#endif // CPPLITERAL_HPP
