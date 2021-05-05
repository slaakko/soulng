#ifndef GUARDPARSER_HPP
#define GUARDPARSER_HPP
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/parser/Context.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/GuardParser.parser' using soulng parser generator spg version 4.0.0

class CppLexer;

struct PARSER_API GuardParser
{
    static soulng::parser::Match MemberFunctionGuard(CppLexer& lexer, sngcpp::par::Context* ctx);
    static soulng::parser::Match SavedMemberFunctionBodyGuard(CppLexer& lexer, sngcpp::par::Context* ctx);
};

#endif // GUARDPARSER_HPP
