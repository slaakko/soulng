#ifndef IDENTIFIER_HPP
#define IDENTIFIER_HPP
#include <soulng/cmajorast/Identifier.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/cmajorparser/Identifier.parser' using soulng parser generator spg version 1.0.0

class CmajorLexer;

struct IdentifierParser
{
    static soulng::parser::Match Identifier(CmajorLexer& lexer);
    static soulng::parser::Match QualifiedId(CmajorLexer& lexer);
};

#endif // IDENTIFIER_HPP
