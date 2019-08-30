#ifndef ATTRIBUTE_HPP
#define ATTRIBUTE_HPP
#include <soulng/cmajorast/Attribute.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/cmajorparser/Attribute.parser' using soulng parser generator spg version 1.0.0

class CmajorLexer;

struct AttributeParser
{
    static soulng::parser::Match Attributes(CmajorLexer& lexer);
    static soulng::parser::Match Attribute(CmajorLexer& lexer, cmajor::ast::Attributes* attributes);
};

#endif // ATTRIBUTE_HPP
