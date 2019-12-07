#ifndef DELEGATE_HPP
#define DELEGATE_HPP
#include <sngcm/parser/ParserApi.hpp>
#include <sngcm/ast/Delegate.hpp>
#include <sngcm/parser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcm/parser/Delegate.parser' using soulng parser generator spg version 3.0.0

class CmajorLexer;

struct SNGCM_PARSER_API DelegateParser
{
    static soulng::parser::Match Delegate(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match ClassDelegate(CmajorLexer& lexer, ParsingContext* ctx);
};

#endif // DELEGATE_HPP
