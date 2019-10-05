#ifndef SIMPLETYPE_HPP
#define SIMPLETYPE_HPP
#include <sngcpp/parser/ParserApi.hpp>
#include <sngcpp/ast/SimpleType.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/parser/SimpleType.parser' using soulng parser generator spg version 1.2.0

class CppLexer;

struct SNGCPP_PARSER_API SimpleTypeParser
{
    static soulng::parser::Match SimpleType(CppLexer& lexer);
    static soulng::parser::Match SimpleTypeSpecifier(CppLexer& lexer);
};

#endif // SIMPLETYPE_HPP
