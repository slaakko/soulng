#ifndef CLASSPARSER_HPP
#define CLASSPARSER_HPP
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/symbols/Context.hpp>
#include <sngcpp20/ast/Class.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/ClassParser.parser' using soulng parser generator spg version 4.0.0

class CppLexer;

struct PARSER_API ClassParser
{
    static soulng::parser::Match ClassSpecifier(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ClassHead(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ClassHeadName(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ClassName(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ClassKey(CppLexer& lexer);
    static soulng::parser::Match BaseClause(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match BaseSpecifierList(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match BaseSpecifier(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ClassOrDeclType(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match AccessSpecifier(CppLexer& lexer);
    static soulng::parser::Match Private(CppLexer& lexer);
    static soulng::parser::Match VirtualSpecifier(CppLexer& lexer);
    static soulng::parser::Match ClassVirtSpecifier(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match VirtSpecifierSeq(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match VirtSpecifier(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match OverrideKeyword(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match FinalKeyword(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match PureSpecifier(CppLexer& lexer);
    static soulng::parser::Match MemberSpecification(CppLexer& lexer, sngcpp::symbols::Context* ctx, sngcpp::ast::Node* container);
    static soulng::parser::Match MemberDeclaration(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match MemberDeclaratorList(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match MemberDeclarator(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match CtorInitializer(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match MemberInitializerList(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match MemberInitializer(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match MemberInitializerId(CppLexer& lexer, sngcpp::symbols::Context* ctx);
};

#endif // CLASSPARSER_HPP
