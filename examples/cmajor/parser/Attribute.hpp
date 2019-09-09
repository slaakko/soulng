#ifndef ATTRIBUTE_HPP
#define ATTRIBUTE_HPP
#include <cmajor/parser/ParserApi.hpp>
#include <cmajor/ast/Attribute.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/Attribute.parser' using soulng parser generator spg version 1.0.0

class CmajorLexer;

struct CMAJOR_PARSER_API AttributeParser
{
    static soulng::parser::Match Attributes(CmajorLexer& lexer);
    static soulng::parser::Match Attribute(CmajorLexer& lexer, cmajor::ast::Attributes* attributes);
};

#endif // ATTRIBUTE_HPP
