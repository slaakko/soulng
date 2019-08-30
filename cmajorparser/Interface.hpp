#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <soulng/cmajorast/Interface.hpp>
#include <cmajorparser/ParsingContext.hpp>
#include <soulng/cmajorast/Class.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/cmajorparser/Interface.parser' using soulng parser generator spg version 1.0.0

class CmajorLexer;

struct InterfaceParser
{
    static soulng::parser::Match Interface(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match InterfaceContent(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::InterfaceNode* intf);
    static soulng::parser::Match InterfaceMemFun(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match InterfaceFunctionGroupId(CmajorLexer& lexer);
};

#endif // INTERFACE_HPP
