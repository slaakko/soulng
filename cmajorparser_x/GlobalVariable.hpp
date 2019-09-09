#ifndef GLOBALVARIABLE_HPP
#define GLOBALVARIABLE_HPP
#include <cmajorast/GlobalVariable.hpp>
#include <cmajorparser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/cmajorparser/GlobalVariable.parser' using soulng parser generator spg version 1.0.0

class CmajorLexer;

struct GlobalVariableParser
{
    static soulng::parser::Match GlobalVariable(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::CompileUnitNode* cu);
};

#endif // GLOBALVARIABLE_HPP
