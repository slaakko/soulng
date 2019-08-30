#ifndef SPECIFIER_HPP
#define SPECIFIER_HPP
#include <soulng/cmajorast/Specifier.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/cmajorparser/Specifier.parser' using soulng parser generator spg version 1.0.0

class CmajorLexer;

struct SpecifierParser
{
    static soulng::parser::Match Specifiers(CmajorLexer& lexer);
    static soulng::parser::Match Specifier(CmajorLexer& lexer);
};

#endif // SPECIFIER_HPP
