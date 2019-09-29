#include "LiteralParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <minilang/MinilangLexer.hpp>
#include <minilang/MinilangTokens.hpp>
#include <minilang/Tree.hpp>
#include <minilang/TokenValueParser.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/LiteralParser.parser' using soulng parser generator spg version 1.2.0

using namespace soulng::unicode;
using namespace MinilangTokens;

soulng::parser::Match LiteralParser::Literal(MinilangLexer& lexer)
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
    std::unique_ptr<minilang::Node> booleanLiteral;
    std::unique_ptr<minilang::Node> integerLiteral;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match = LiteralParser::BooleanLiteral(lexer);
            booleanLiteral.reset(static_cast<minilang::Node*>(match.value));
            if (match.hit)
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Literal"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, booleanLiteral.release());
                }
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = LiteralParser::IntegerLiteral(lexer);
                    integerLiteral.reset(static_cast<minilang::Node*>(match.value));
                    if (match.hit)
                    {
                        {
                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Literal"));
                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                            return soulng::parser::Match(true, integerLiteral.release());
                        }
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch0 = match;
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

soulng::parser::Match LiteralParser::BooleanLiteral(MinilangLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("BooleanLiteral"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case TRUE:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("BooleanLiteral"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new minilang::BooleanLiteralNode(true));
                }
            }
            break;
        }
        case FALSE:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("BooleanLiteral"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new minilang::BooleanLiteralNode(false));
                }
            }
            break;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("BooleanLiteral"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("BooleanLiteral"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match LiteralParser::IntegerLiteral(MinilangLexer& lexer)
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
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        if (*lexer == INTLIT)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("IntegerLiteral"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new minilang::IntegerLiteralNode(minilang::ParseIntegerLiteral(lexer.FileName(), lexer.GetToken(pos))));
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
