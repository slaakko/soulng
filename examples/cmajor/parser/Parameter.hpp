#ifndef PARAMETER_HPP
#define PARAMETER_HPP
#include <cmajor/parser/ParserApi.hpp>
#include <cmajor/ast/Parameter.hpp>
#include <cmajor/parser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/Parameter.parser' using soulng parser generator spg version 2.0.0

class CmajorLexer;

struct CMAJOR_PARSER_API ParameterParser
{
    static soulng::parser::Match ParameterList(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::Node* owner);
    static soulng::parser::Match Parameter(CmajorLexer& lexer, ParsingContext* ctx);
};

#endif // PARAMETER_HPP
