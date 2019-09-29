#include "FunctionParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <minilang/TypeParser.hpp>
#include <minilang/IdentifierParser.hpp>
#include <minilang/StatementParser.hpp>
#include <minilang/MinilangLexer.hpp>
#include <minilang/MinilangTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/FunctionParser.parser' using soulng parser generator spg version 1.2.0

using namespace soulng::unicode;
using namespace MinilangTokens;

soulng::parser::Match FunctionParser::Function(MinilangLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("Function"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<minilang::FunctionNode> function = std::unique_ptr<minilang::FunctionNode>();
    std::unique_ptr<minilang::Node> returnType;
    std::unique_ptr<minilang::IdentifierNode> functionName;
    std::unique_ptr<minilang::CompoundStatementNode> functionBody;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
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
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                soulng::parser::Match match = TypeParser::Type(lexer);
                                returnType.reset(static_cast<minilang::Node*>(match.value));
                                *parentMatch6 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    soulng::parser::Match match(true);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                        functionName.reset(static_cast<minilang::IdentifierNode*>(match.value));
                                        if (match.hit)
                                        {
                                            *parentMatch8 = match;
                                        }
                                        else
                                        {
                                            lexer.ThrowExpectationFailure(pos, U"Identifier");
                                        }
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch9 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch10 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(true);
                                    soulng::parser::Match* parentMatch11 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        if (*lexer == LPAREN)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            *parentMatch11 = match;
                                        }
                                        else
                                        {
                                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                                        }
                                    }
                                    if (match.hit)
                                    {
                                        function.reset(new minilang::FunctionNode(returnType.release(), functionName.release()));
                                    }
                                    *parentMatch10 = match;
                                }
                                *parentMatch9 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch12 = &match;
                        {
                            soulng::parser::Match match(true);
                            int save = lexer.GetPos();
                            soulng::parser::Match* parentMatch13 = &match;
                            {
                                soulng::parser::Match match = FunctionParser::ParameterList(lexer, function.get());
                                if (match.hit)
                                {
                                    *parentMatch13 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                }
                            }
                            *parentMatch12 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch14 = &match;
                    {
                        soulng::parser::Match match(true);
                        soulng::parser::Match* parentMatch15 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == RPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                *parentMatch15 = match;
                            }
                            else
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                            }
                        }
                        *parentMatch14 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch16 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch17 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(true);
                        soulng::parser::Match* parentMatch18 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = StatementParser::CompoundStatement(lexer);
                            functionBody.reset(static_cast<minilang::CompoundStatementNode*>(match.value));
                            if (match.hit)
                            {
                                *parentMatch18 = match;
                            }
                            else
                            {
                                lexer.ThrowExpectationFailure(pos, U"CompoundStatement");
                            }
                        }
                        if (match.hit)
                        {
                            function->SetBody(functionBody.release());
                        }
                        *parentMatch17 = match;
                    }
                    *parentMatch16 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Function"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, function.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Function"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("Function"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match FunctionParser::ParameterList(MinilangLexer& lexer, minilang::FunctionNode* function)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ParameterList"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<minilang::ParameterNode> left;
    std::unique_ptr<minilang::ParameterNode> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match = FunctionParser::Parameter(lexer);
            left.reset(static_cast<minilang::ParameterNode*>(match.value));
            if (match.hit)
            {
                function->AddParam(left.release());
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch2 = &match;
        {
            soulng::parser::Match match(true);
            soulng::parser::Match* parentMatch3 = &match;
            {
                while (true)
                {
                    int save = lexer.GetPos();
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch4 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch5 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == COMMA)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch5 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match(true);
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = FunctionParser::Parameter(lexer);
                                            right.reset(static_cast<minilang::ParameterNode*>(match.value));
                                            if (match.hit)
                                            {
                                                *parentMatch8 = match;
                                            }
                                            else
                                            {
                                                lexer.ThrowExpectationFailure(pos, U"Parameter");
                                            }
                                        }
                                        if (match.hit)
                                        {
                                            function->AddParam(right.release());
                                        }
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                                *parentMatch5 = match;
                            }
                            *parentMatch4 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch3 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                            break;
                        }
                    }
                }
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ParameterList"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ParameterList"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match FunctionParser::Parameter(MinilangLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("Parameter"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<minilang::Node> type;
    std::unique_ptr<minilang::IdentifierNode> name;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match = TypeParser::Type(lexer);
        type.reset(static_cast<minilang::Node*>(match.value));
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                name.reset(static_cast<minilang::IdentifierNode*>(match.value));
                if (match.hit)
                {
                    {
                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Parameter"));
                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                        return soulng::parser::Match(true, new minilang::ParameterNode(type.release(), name.release()));
                    }
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Parameter"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("Parameter"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}
