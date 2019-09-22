#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP
#include <cmajor/parser/ParserApi.hpp>
#include <cmajor/ast/Template.hpp>
#include <cmajor/parser/Identifier.hpp>
#include <cmajor/parser/TypeExpr.hpp>
#include <cmajor/parser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/Template.parser' using soulng parser generator spg version 1.1.0

class CmajorLexer;

struct CMAJOR_PARSER_API TemplateParser
{
    static soulng::parser::Match TemplateId(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match TemplateParameter(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match TemplateParameterList(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::Node* owner);
};

#endif // TEMPLATE_HPP
