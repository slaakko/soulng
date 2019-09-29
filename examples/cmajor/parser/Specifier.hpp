#ifndef SPECIFIER_HPP
#define SPECIFIER_HPP
#include <cmajor/parser/ParserApi.hpp>
#include <cmajor/ast/Specifier.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/Specifier.parser' using soulng parser generator spg version 1.2.0

class CmajorLexer;

struct CMAJOR_PARSER_API SpecifierParser
{
    static soulng::parser::Match Specifiers(CmajorLexer& lexer);
    static soulng::parser::Match Specifier(CmajorLexer& lexer);
};

#endif // SPECIFIER_HPP
