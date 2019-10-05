#include "TypeExpr.hpp"
#include <soulng/util/Unicode.hpp>
#include <sngcpp/lexer/CppLexer.hpp>
#include <sngcpp/lexer/CppLexerTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/parser/TypeExpr.parser' using soulng parser generator spg version 1.2.0

using namespace soulng::unicode;
using namespace CppLexerTokens;

soulng::parser::Match TypeExprParser::TypeExpr(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("TypeExpr"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(true);
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("TypeExpr"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("TypeExpr"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}
