#include "IdentifierParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <minilang/MinilangLexer.hpp>
#include <minilang/MinilangTokens.hpp>
#include <minilang/Tree.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/IdentifierParser.parser' using soulng parser generator spg version 3.0.0

using namespace soulng::unicode;
using namespace MinilangTokens;

soulng::parser::Match IdentifierParser::Identifier(MinilangLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("Identifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match(false);
        if (*lexer == ID)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            soulng::lexer::Token token = lexer.GetToken(pos);
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Identifier"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new minilang::IdentifierNode(token.match.ToString()));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Identifier"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("Identifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}
