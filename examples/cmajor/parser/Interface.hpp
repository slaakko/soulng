#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <cmajor/parser/ParserApi.hpp>
#include <cmajor/ast/Interface.hpp>
#include <cmajor/parser/ParsingContext.hpp>
#include <cmajor/ast/Class.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/Interface.parser' using soulng parser generator spg version 2.0.0

class CmajorLexer;

struct CMAJOR_PARSER_API InterfaceParser
{
    static soulng::parser::Match Interface(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match InterfaceContent(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::InterfaceNode* intf);
    static soulng::parser::Match InterfaceMemFun(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match InterfaceFunctionGroupId(CmajorLexer& lexer);
};

#endif // INTERFACE_HPP
