#ifndef COMPILEUNIT_HPP
#define COMPILEUNIT_HPP
#include <cmajor/parser/ParserApi.hpp>
#include <cmajor/ast/CompileUnit.hpp>
#include <cmajor/parser/ParsingContext.hpp>
#include <memory>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/CompileUnit.parser' using soulng parser generator spg version 1.1.0

class CmajorLexer;

struct CMAJOR_PARSER_API CompileUnitParser
{
    static std::unique_ptr<cmajor::ast::CompileUnitNode> Parse(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match CompileUnit(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match NamespaceContent(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::CompileUnitNode* cu, cmajor::ast::NamespaceNode* ns);
    static soulng::parser::Match UsingDirectives(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::NamespaceNode* ns);
    static soulng::parser::Match UsingDirective(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::NamespaceNode* ns);
    static soulng::parser::Match UsingAliasDirective(CmajorLexer& lexer);
    static soulng::parser::Match UsingNamespaceDirective(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match Definitions(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::CompileUnitNode* cu, cmajor::ast::NamespaceNode* ns);
    static soulng::parser::Match Definition(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::CompileUnitNode* cu, cmajor::ast::NamespaceNode* ns);
    static soulng::parser::Match NamespaceDefinition(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::CompileUnitNode* cu, cmajor::ast::NamespaceNode* ns);
    static soulng::parser::Match TypedefDeclaration(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match ConceptDefinition(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match FunctionDefinition(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match ClassDefinition(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match InterfaceDefinition(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match EnumTypeDefinition(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match ConstantDefinition(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match DelegateDefinition(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match ClassDelegateDefinition(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match GlobalVariableDefinition(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::CompileUnitNode* cu);
};

#endif // COMPILEUNIT_HPP
