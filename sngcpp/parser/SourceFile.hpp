#ifndef SOURCEFILE_HPP
#define SOURCEFILE_HPP
#include <sngcpp/parser/ParserApi.hpp>
#include <sngcpp/parser/ParsingContext.hpp>
#include <sngcpp/parser/Declaration.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/parser/SourceFile.parser' using soulng parser generator spg version 3.0.0

class CppLexer;

struct SNGCPP_PARSER_API SourceFileParser
{
    static void Parse(CppLexer& lexer, sngcpp::ast::SourceFileNode* sourceFile);
    static soulng::parser::Match SourceFile(CppLexer& lexer, sngcpp::ast::SourceFileNode* sourceFile);
    static soulng::parser::Match Declarations(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx, sngcpp::ast::NamespaceNode* ns);
};

#endif // SOURCEFILE_HPP
