#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP
#include <soulng/cmajorast/Template.hpp>
#include <soulng/cmajorparser/Identifier.hpp>
#include <soulng/cmajorparser/TypeExpr.hpp>
#include <soulng/cmajorparser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/cmajorparser/Template.parser' using soulng parser generator spg version 1.0.0

class CmajorLexer;

struct TemplateParser
{
    static soulng::parser::Match TemplateId(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match TemplateParameter(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match TemplateParameterList(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::Node* owner);
};

#endif // TEMPLATE_HPP
