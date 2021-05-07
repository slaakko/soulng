#ifndef DECLARATIONPARSER_HPP
#define DECLARATIONPARSER_HPP
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/symbols/Context.hpp>
#include <sngcpp20/ast/Declaration.hpp>
#include <sngcpp20/ast/Qualifier.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/DeclarationParser.parser' using soulng parser generator spg version 4.0.0

class CppLexer;

struct PARSER_API DeclarationParser
{
    static soulng::parser::Match DeclarationSeq(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match Declaration(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match BlockDeclaration(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match SimpleDeclaration(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match AsmDeclaration(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match Asm(CppLexer& lexer);
    static soulng::parser::Match LinkageSpecification(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match NamespaceDefinition(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match NamedNamespaceDefinition(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match UnnamedNamespaceDefinition(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match NestedNamespaceDefinition(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match NamespaceBody(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match EnclosingNamespaceSpecifier(CppLexer& lexer, sngcpp::symbols::Context* ctx, sngcpp::ast::Node* container);
    static soulng::parser::Match NamespaceAliasDefinition(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match Namespace(CppLexer& lexer);
    static soulng::parser::Match QualifiedNamespaceSpecifier(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match UsingDeclaration(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match Using(CppLexer& lexer);
    static soulng::parser::Match UsingDeclaratorList(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match UsingDeclarator(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match UsingEnumDeclaration(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match UsingDirective(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match NamespaceName(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match StaticAssertDeclaration(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match StaticAssert(CppLexer& lexer);
    static soulng::parser::Match AliasDeclaration(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match EmptyDeclaration(CppLexer& lexer);
    static soulng::parser::Match AttributeDeclaration(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match DeclSpecifierSeq(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match Inline(CppLexer& lexer);
    static soulng::parser::Match DeclSpecifier(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match StorageClassSpecifier(CppLexer& lexer);
    static soulng::parser::Match FunctionSpecifier(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ExplicitSpecifier(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match InitDeclaratorList(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match InitDeclarator(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match Declarator(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match PtrDeclarator(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match NoPtrDeclarator(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ParametersAndQualifiers(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match TrailingReturnType(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match PtrOperator(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match AbstractDeclarator(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match NoPtrAbstractDeclarator(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match PtrAbstractDeclarator(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match AbstractPackDeclarator(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match NoPtrAbstractPackDeclarator(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match DeclaratorId(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match Ptr(CppLexer& lexer);
    static soulng::parser::Match LvalueRef(CppLexer& lexer);
    static soulng::parser::Match RvalueRef(CppLexer& lexer);
    static soulng::parser::Match RefQualifier(CppLexer& lexer);
    static soulng::parser::Match CVQualifierSeq(CppLexer& lexer);
    static soulng::parser::Match CVQualifier(CppLexer& lexer);
    static soulng::parser::Match NoexceptSpecifier(CppLexer& lexer, sngcpp::symbols::Context* ctx);
};

#endif // DECLARATIONPARSER_HPP
