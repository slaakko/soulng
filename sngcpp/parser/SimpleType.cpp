#include "SimpleType.hpp"
#include <soulng/util/Unicode.hpp>
#include <sngcpp/lexer/CppLexer.hpp>
#include <sngcpp/lexer/CppLexerTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/parser/SimpleType.parser' using soulng parser generator spg version 1.2.0

using namespace soulng::unicode;
using namespace CppLexerTokens;

soulng::parser::Match SimpleTypeParser::SimpleType(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("SimpleType"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::vector<sngcpp::ast::SimpleTypeSpecifier> specifiers = std::vector<sngcpp::ast::SimpleTypeSpecifier>();
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>> s;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::lexer::Span span = lexer.GetSpan();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = SimpleTypeParser::SimpleTypeSpecifier(lexer);
                        s.reset(static_cast<soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>*>(match.value));
                        if (match.hit)
                        {
                            specifiers.push_back(s->value);
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch5 = &match;
                while (true)
                {
                    int save = lexer.GetPos();
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = SimpleTypeParser::SimpleTypeSpecifier(lexer);
                                s.reset(static_cast<soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>*>(match.value));
                                if (match.hit)
                                {
                                    specifiers.push_back(s->value);
                                }
                                *parentMatch7 = match;
                            }
                            *parentMatch6 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch5 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                            break;
                        }
                    }
                }
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleType"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new sngcpp::ast::SimpleTypeNode(span, specifiers));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleType"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("SimpleType"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match SimpleTypeParser::SimpleTypeSpecifier(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("SimpleTypeSpecifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case CHAR:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleTypeSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>(sngcpp::ast::SimpleTypeSpecifier::char_));
                }
            }
            break;
        }
        case CHAR16_T:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleTypeSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>(sngcpp::ast::SimpleTypeSpecifier::char16));
                }
            }
            break;
        }
        case CHAR32_T:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleTypeSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>(sngcpp::ast::SimpleTypeSpecifier::char32));
                }
            }
            break;
        }
        case WCHAR_T:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleTypeSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>(sngcpp::ast::SimpleTypeSpecifier::wchar));
                }
            }
            break;
        }
        case BOOL:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleTypeSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>(sngcpp::ast::SimpleTypeSpecifier::bool_));
                }
            }
            break;
        }
        case SHORT:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleTypeSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>(sngcpp::ast::SimpleTypeSpecifier::short_));
                }
            }
            break;
        }
        case INT:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleTypeSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>(sngcpp::ast::SimpleTypeSpecifier::int_));
                }
            }
            break;
        }
        case LONG:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleTypeSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>(sngcpp::ast::SimpleTypeSpecifier::long_));
                }
            }
            break;
        }
        case SIGNED:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleTypeSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>(sngcpp::ast::SimpleTypeSpecifier::signed_));
                }
            }
            break;
        }
        case UNSIGNED:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleTypeSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>(sngcpp::ast::SimpleTypeSpecifier::unsigned_));
                }
            }
            break;
        }
        case FLOAT:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleTypeSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>(sngcpp::ast::SimpleTypeSpecifier::float_));
                }
            }
            break;
        }
        case DOUBLE:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleTypeSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>(sngcpp::ast::SimpleTypeSpecifier::double_));
                }
            }
            break;
        }
        case VOID:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleTypeSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>(sngcpp::ast::SimpleTypeSpecifier::void_));
                }
            }
            break;
        }
        case AUTO:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleTypeSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::SimpleTypeSpecifier>(sngcpp::ast::SimpleTypeSpecifier::auto_));
                }
            }
            break;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleTypeSpecifier"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("SimpleTypeSpecifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}
