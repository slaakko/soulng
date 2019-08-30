#ifndef PARAMETER_HPP
#define PARAMETER_HPP
#include <soulng/cmajorast/Parameter.hpp>
#include <soulng/cmajorparser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/cmajorparser/Parameter.parser' using soulng parser generator spg version 1.0.0

class CmajorLexer;

struct ParameterParser
{
    static soulng::parser::Match ParameterList(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::Node* owner);
    static soulng::parser::Match Parameter(CmajorLexer& lexer, ParsingContext* ctx);
};

#endif // PARAMETER_HPP
