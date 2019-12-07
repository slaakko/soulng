#ifndef CLASS_HPP
#define CLASS_HPP
#include <sngcpp/parser/ParserApi.hpp>
#include <sngcpp/parser/ParsingContext.hpp>
#include <sngcpp/ast/Class.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/parser/Class.parser' using soulng parser generator spg version 3.0.0

class CppLexer;

struct SNGCPP_PARSER_API ClassParser
{
    static soulng::parser::Match ClassDeclaration(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match ClassSpecifier(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match MemberSpecifications(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx, sngcpp::ast::ClassNode* classNode);
    static soulng::parser::Match MemberSpecification(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx, sngcpp::ast::ClassNode* classNode);
    static soulng::parser::Match MemberDeclaration(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match SpecialMemberFunctionDeclaration(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match ClassHead(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match ForwardClassDeclaration(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match ClassKey(CppLexer& lexer);
    static soulng::parser::Match ClassName(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match ClassVirtSpecifiers(CppLexer& lexer);
    static soulng::parser::Match ClassVirtSpecifier(CppLexer& lexer);
    static soulng::parser::Match BaseClause(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match BaseClassSpecifierList(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match BaseClassSpecifier(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match BaseSpecifiers(CppLexer& lexer);
    static soulng::parser::Match BaseSpecifier(CppLexer& lexer);
    static soulng::parser::Match AccessSpecifier(CppLexer& lexer);
    static soulng::parser::Match VirtPureSpecifiers(CppLexer& lexer, bool functionMember);
    static soulng::parser::Match VirtSpecifier(CppLexer& lexer, bool functionMember);
    static soulng::parser::Match PureSpecifier(CppLexer& lexer, bool functionMember);
    static soulng::parser::Match SpecialMemberFunctionDefinition(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match CtorInitializer(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match MemberInitializerList(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match MemberInitializer(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
    static soulng::parser::Match MemberInitializerId(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx);
};

#endif // CLASS_HPP
