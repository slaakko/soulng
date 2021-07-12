#include "GuardParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <sngcpp20/lexer/CppLexer.hpp>
#include <sngcpp20/lexer/CppTokens.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/GuardParser.parser' using soulng parser generator spg version 4.0.0

using namespace soulng::unicode;
using namespace sngcpp::ast;
using namespace CppTokens;
using namespace soulng::lexer;

soulng::parser::Match GuardParser::MemberFunctionTemplateGuard(CppLexer& lexer, sngcpp::symbols::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("MemberFunctionTemplateGuard"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::RuleGuard ruleGuard(lexer, 207);
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        bool pass = true;
        soulng::parser::Match match(true);
        if (match.hit)
        {
            pass = ctx->GetFlag(sngcpp::symbols::ContextFlags::parseMemberFunction | sngcpp::symbols::ContextFlags::parsingTemplateDeclaration);
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
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberFunctionTemplateGuard"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("MemberFunctionTemplateGuard"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match GuardParser::SavedMemberFunctionBodyGuard(CppLexer& lexer, sngcpp::symbols::Context* ctx)
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
    soulng::lexer::RuleGuard ruleGuard(lexer, 208);
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        bool pass = true;
        soulng::parser::Match match(true);
        if (match.hit)
        {
            pass = ctx->GetFlag(sngcpp::symbols::ContextFlags::parseSavedMemberFunctionBody);
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

soulng::parser::Match GuardParser::AssumeTypeGuard(CppLexer& lexer, sngcpp::symbols::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("AssumeTypeGuard"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::RuleGuard ruleGuard(lexer, 209);
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        bool pass = true;
        soulng::parser::Match match(true);
        if (match.hit)
        {
            pass = ctx->GetFlag(sngcpp::symbols::ContextFlags::assumeType);
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
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AssumeTypeGuard"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("AssumeTypeGuard"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match GuardParser::NotDefiningTypeSpecifierGuard(CppLexer& lexer, sngcpp::symbols::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("NotDefiningTypeSpecifierGuard"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::RuleGuard ruleGuard(lexer, 210);
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        bool pass = true;
        soulng::parser::Match match(true);
        if (match.hit)
        {
            pass = !ctx->GetFlag(sngcpp::symbols::ContextFlags::hasDefiningTypeSpecifier);
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
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("NotDefiningTypeSpecifierGuard"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("NotDefiningTypeSpecifierGuard"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match GuardParser::MSVCModeGuard(CppLexer& lexer, sngcpp::symbols::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("MSVCModeGuard"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::RuleGuard ruleGuard(lexer, 211);
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        bool pass = true;
        soulng::parser::Match match(true);
        if (match.hit)
        {
            pass = ctx->GetFlag(sngcpp::symbols::ContextFlags::msvcMode);
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
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MSVCModeGuard"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("MSVCModeGuard"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}
