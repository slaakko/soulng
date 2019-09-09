#ifndef IDENTIFIER_HPP
#define IDENTIFIER_HPP
#include <cmajor/parser/ParserApi.hpp>
#include <cmajor/ast/Identifier.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/Identifier.parser' using soulng parser generator spg version 1.0.0

class CmajorLexer;

struct CMAJOR_PARSER_API IdentifierParser
{
    static soulng::parser::Match Identifier(CmajorLexer& lexer);
    static soulng::parser::Match QualifiedId(CmajorLexer& lexer);
};

#endif // IDENTIFIER_HPP
