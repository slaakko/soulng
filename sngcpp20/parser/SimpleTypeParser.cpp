#include "SimpleTypeParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <sngcpp20/lexer/CppLexer.hpp>
#include <sngcpp20/lexer/CppTokens.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/SimpleTypeParser.parser' using soulng parser generator spg version 4.0.0

using namespace soulng::unicode;
using namespace sngcpp::par;
using namespace sngcpp::ast;
using namespace CppTokens;
using namespace soulng::lexer;

soulng::parser::Match SimpleTypeParser::SimpleType(CppLexer& lexer, sngcpp::par::Context* ctx)
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
    soulng::parser::Match match(false);
    int64_t pos = lexer.GetPos();
    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case CHAR:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleType"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new CharNode(sourcePos));
                }
            }
            break;
        }
        case CHAR8_T:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleType"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new Char8Node(sourcePos));
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
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleType"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new Char16Node(sourcePos));
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
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleType"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new Char32Node(sourcePos));
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
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleType"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new WCharNode(sourcePos));
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
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleType"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new BoolNode(sourcePos));
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
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleType"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new ShortNode(sourcePos));
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
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleType"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new IntNode(sourcePos));
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
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleType"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new LongNode(sourcePos));
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
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleType"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new SignedNode(sourcePos));
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
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleType"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new FloatNode(sourcePos));
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
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleType"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new DoubleNode(sourcePos));
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
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleType"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new VoidNode(sourcePos));
                }
            }
            break;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SimpleType"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("SimpleType"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}
