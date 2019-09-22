#ifndef GLOBALVARIABLE_HPP
#define GLOBALVARIABLE_HPP
#include <cmajor/parser/ParserApi.hpp>
#include <cmajor/ast/GlobalVariable.hpp>
#include <cmajor/parser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/GlobalVariable.parser' using soulng parser generator spg version 1.1.0

class CmajorLexer;

struct CMAJOR_PARSER_API GlobalVariableParser
{
    static soulng::parser::Match GlobalVariable(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::CompileUnitNode* cu);
};

#endif // GLOBALVARIABLE_HPP
