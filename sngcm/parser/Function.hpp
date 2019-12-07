#ifndef FUNCTION_HPP
#define FUNCTION_HPP
#include <sngcm/parser/ParserApi.hpp>
#include <sngcm/ast/Function.hpp>
#include <sngcm/parser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcm/parser/Function.parser' using soulng parser generator spg version 3.0.0

class CmajorLexer;

struct SNGCM_PARSER_API FunctionParser
{
    static soulng::parser::Match Function(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match FunctionGroupId(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match OperatorFunctionGroupId(CmajorLexer& lexer, ParsingContext* ctx);
};

#endif // FUNCTION_HPP
