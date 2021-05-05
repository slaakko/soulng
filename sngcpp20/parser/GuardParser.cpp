#include "GuardParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <sngcpp20/lexer/CppLexer.hpp>
#include <sngcpp20/lexer/CppTokens.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/GuardParser.parser' using soulng parser generator spg version 4.0.0

using namespace soulng::unicode;
using namespace sngcpp::par;
using namespace sngcpp::ast;
using namespace CppTokens;
using namespace soulng::lexer;

soulng::parser::Match GuardParser::MemberFunctionGuard(CppLexer& lexer, sngcpp::par::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("MemberFunctionGuard"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        bool pass = true;
        soulng::parser::Match match(true);
        if (match.hit)
        {
            pass = ctx->GetFlag(ContextFlags::parseMemberFunction);
        }
        if (match.hit && !pass)
        {
            match = soulng::parser::Match(false);
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberFunctionGuard"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("MemberFunctionGuard"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match GuardParser::SavedMemberFunctionBodyGuard(CppLexer& lexer, sngcpp::par::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("SavedMemberFunctionBodyGuard"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        bool pass = true;
        soulng::parser::Match match(true);
        if (match.hit)
        {
            pass = ctx->GetFlag(ContextFlags::parseSavedMemberFunctionBody);
        }
        if (match.hit && !pass)
        {
            match = soulng::parser::Match(false);
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SavedMemberFunctionBodyGuard"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("SavedMemberFunctionBodyGuard"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}
