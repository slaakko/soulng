#ifndef TEMPLATEPARSER_HPP
#define TEMPLATEPARSER_HPP
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/symbols/Context.hpp>
#include <sngcpp20/ast/Class.hpp>
#include <sngcpp20/ast/Template.hpp>
#include <sngcpp20/ast/Identifier.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/TemplateParser.parser' using soulng parser generator spg version 3.1.0

class CppLexer;

struct PARSER_API TemplateParser
{
    static soulng::parser::Match TemplateDeclaration(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match TemplateHead(CppLexer& lexer, sngcpp::symbols::Context* ctx, bool begin);
    static soulng::parser::Match TemplateParameterList(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match TemplateParameter(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match TypeParameter(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match TypeParameterKey(CppLexer& lexer);
    static soulng::parser::Match Typename(CppLexer& lexer);
    static soulng::parser::Match TemplateId(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match SimpleTemplateId(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match TemplateName(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match TemplateArgumentList(CppLexer& lexer, sngcpp::symbols::Context* ctx, sngcpp::ast::Node* templateIdNode);
    static soulng::parser::Match TemplateArgument(CppLexer& lexer, sngcpp::symbols::Context* ctx, sngcpp::ast::Node* templateIdNode, int index);
    static soulng::parser::Match TemplateArgNext(CppLexer& lexer);
    static soulng::parser::Match DeductionGuide(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match Arrow(CppLexer& lexer);
    static soulng::parser::Match ExplicitInstantiation(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match Extern(CppLexer& lexer);
    static soulng::parser::Match Template(CppLexer& lexer);
    static soulng::parser::Match ExplicitSpecialization(CppLexer& lexer, sngcpp::symbols::Context* ctx);
};

#endif // TEMPLATEPARSER_HPP
