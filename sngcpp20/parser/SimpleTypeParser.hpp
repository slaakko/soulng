#ifndef SIMPLETYPEPARSER_HPP
#define SIMPLETYPEPARSER_HPP
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/symbols/Context.hpp>
#include <sngcpp20/ast/SimpleType.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/SimpleTypeParser.parser' using soulng parser generator spg version 3.1.0

class CppLexer;

struct PARSER_API SimpleTypeParser
{
    static soulng::parser::Match SimpleType(CppLexer& lexer, sngcpp::symbols::Context* ctx);
};

#endif // SIMPLETYPEPARSER_HPP
