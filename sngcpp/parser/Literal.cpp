#include "Literal.hpp"
#include <soulng/util/Unicode.hpp>
#include <sngcpp/lexer/CppLexer.hpp>
#include <sngcpp/lexer/CppTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/parser/Literal.parser' using soulng parser generator spg version 3.0.0

using namespace soulng::unicode;
using namespace CppTokens;

soulng::parser::Match LiteralParser::Literal(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("Literal"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    int64_t pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case FLOATLIT:
        {
            ++lexer;
            {
                soulng::lexer::Token token = lexer.GetToken(pos);
                double value = 0.0;
                sngcpp::ast::Suffix suffix = sngcpp::ast::Suffix::none;
                sngcpp::cppparser::ParseFloatingLiteral(lexer.FileName(), token, value, suffix);
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Literal"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new sngcpp::ast::FloatingLiteralNode(span, value, suffix, token.match.ToString()));
                }
            }
            break;
        }
        case INTLIT:
        {
            ++lexer;
            {
                soulng::lexer::Token token = lexer.GetToken(pos);
                uint64_t value = 0;
                sngcpp::ast::Base base = sngcpp::ast::Base::decimal;
                sngcpp::ast::Suffix suffix = sngcpp::ast::Suffix::none;
                sngcpp::cppparser::ParseIntegerLiteral(lexer.FileName(), token, value, base, suffix);
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Literal"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new sngcpp::ast::IntegerLiteralNode(span, value, suffix, base, token.match.ToString()));
                }
            }
            break;
        }
        case CHARLIT:
        {
            ++lexer;
            {
                soulng::lexer::Token token = lexer.GetToken(pos);
                char32_t value = '\0';
                char32_t prefix = '\0';
                sngcpp::cppparser::ParseCharacterLiteral(lexer.FileName(), token, value, prefix);
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Literal"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new sngcpp::ast::CharacterLiteralNode(span, prefix, value, token.match.ToString()));
                }
            }
            break;
        }
        case STRINGLIT:
        {
            ++lexer;
            {
                soulng::lexer::Token token = lexer.GetToken(pos);
                std::u32string value;
                std::u32string encodingPrefix;
                sngcpp::cppparser::ParseStringLiteral(lexer.FileName(), token, encodingPrefix, value);
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Literal"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new sngcpp::ast::StringLiteralNode(span, encodingPrefix, value, token.match.ToString()));
                }
            }
            break;
        }
        case TRUE:
        {
            ++lexer;
            {
                soulng::lexer::Token token = lexer.GetToken(pos);
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Literal"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new sngcpp::ast::BooleanLiteralNode(span, true, token.match.ToString()));
                }
            }
            break;
        }
        case FALSE:
        {
            ++lexer;
            {
                soulng::lexer::Token token = lexer.GetToken(pos);
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Literal"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new sngcpp::ast::BooleanLiteralNode(span, false, token.match.ToString()));
                }
            }
            break;
        }
        case NULLPTR:
        {
            ++lexer;
            {
                soulng::lexer::Token token = lexer.GetToken(pos);
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Literal"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new sngcpp::ast::NullPtrLiteralNode(span, token.match.ToString()));
                }
            }
            break;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Literal"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("Literal"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match LiteralParser::StringLiteral(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("StringLiteral"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::lexer::Span span = lexer.GetSpan();
        soulng::parser::Match match(false);
        if (*lexer == STRINGLIT)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            soulng::lexer::Token token = lexer.GetToken(pos);
            std::u32string value;
            std::u32string encodingPrefix;
            sngcpp::cppparser::ParseStringLiteral(lexer.FileName(), token, encodingPrefix, value);
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("StringLiteral"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new sngcpp::ast::StringLiteralNode(span, encodingPrefix, value, token.match.ToString()));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("StringLiteral"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("StringLiteral"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match LiteralParser::IntegerLiteral(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("IntegerLiteral"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::lexer::Span span = lexer.GetSpan();
        soulng::parser::Match match(false);
        if (*lexer == INTLIT)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            soulng::lexer::Token token = lexer.GetToken(pos);
            uint64_t value = 0;
            sngcpp::ast::Base base = sngcpp::ast::Base::decimal;
            sngcpp::ast::Suffix suffix = sngcpp::ast::Suffix::none;
            sngcpp::cppparser::ParseIntegerLiteral(lexer.FileName(), token, value, base, suffix);
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("IntegerLiteral"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new sngcpp::ast::IntegerLiteralNode(span, value, suffix, base, token.match.ToString()));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("IntegerLiteral"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("IntegerLiteral"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}
