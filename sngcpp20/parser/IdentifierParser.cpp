#include "IdentifierParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/parser/FunctionParser.hpp>
#include <sngcpp20/parser/LiteralParser.hpp>
#include <sngcpp20/parser/TemplateParser.hpp>
#include <sngcpp20/lexer/CppLexer.hpp>
#include <sngcpp20/lexer/CppTokens.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/IdentifierParser.parser' using soulng parser generator spg version 4.0.0

using namespace soulng::unicode;
using namespace sngcpp::par;
using namespace sngcpp::ast;
using namespace sngcpp::symbols;
using namespace CppTokens;
using namespace soulng::lexer;

soulng::parser::Match IdentifierParser::Identifier(CppLexer& lexer, sngcpp::par::Context* ctx)
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
        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
        soulng::parser::Match match(false);
        if (*lexer == ID)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Identifier"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new IdentifierNode(sourcePos, lexer.GetMatch(pos)));
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

soulng::parser::Match IdentifierParser::TypeIdentifier(CppLexer& lexer, sngcpp::par::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("TypeIdentifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
        bool pass = true;
        soulng::parser::Match match(false);
        if (*lexer == ID)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            std::u32string id = lexer.GetMatch(pos);
            Symbol * symbol = ctx->GetSymbolTable()->Lookup(id);
            if (symbol && symbol->IsTypeSymbol())
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("TypeIdentifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new IdentifierNode(sourcePos, id));
                }
            }
            else
            {
                pass = false;
            }
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
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("TypeIdentifier"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("TypeIdentifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match IdentifierParser::UnqualifiedId(CppLexer& lexer, sngcpp::par::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("UnqualifiedId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<Node> templateId;
    std::unique_ptr<Node> identifier;
    std::unique_ptr<Node> operatorFnId;
    std::unique_ptr<Node> conversionFnId;
    std::unique_ptr<Node> literalOperatorId;
    std::unique_ptr<Node> destructorId;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int64_t save = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int64_t save = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int64_t save = lexer.GetPos();
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int64_t pos = lexer.GetPos();
                            soulng::parser::Match match = TemplateParser::TemplateId(lexer, ctx);
                            templateId.reset(static_cast<Node*>(match.value));
                            if (match.hit)
                            {
                                {
                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnqualifiedId"));
                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                    return soulng::parser::Match(true, templateId.release());
                                }
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    int64_t pos = lexer.GetPos();
                                    soulng::parser::Match match = IdentifierParser::Identifier(lexer, ctx);
                                    identifier.reset(static_cast<Node*>(match.value));
                                    if (match.hit)
                                    {
                                        {
                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnqualifiedId"));
                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                            return soulng::parser::Match(true, identifier.release());
                                        }
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch4 = match;
                        }
                    }
                    *parentMatch3 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch8 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch9 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::parser::Match match = FunctionParser::OperatorFunctionId(lexer, ctx);
                                operatorFnId.reset(static_cast<Node*>(match.value));
                                if (match.hit)
                                {
                                    {
                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnqualifiedId"));
                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                        return soulng::parser::Match(true, operatorFnId.release());
                                    }
                                }
                                *parentMatch9 = match;
                            }
                            *parentMatch8 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch10 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch11 = &match;
                        {
                            int64_t pos = lexer.GetPos();
                            soulng::parser::Match match = FunctionParser::ConversionFunctionId(lexer, ctx);
                            conversionFnId.reset(static_cast<Node*>(match.value));
                            if (match.hit)
                            {
                                {
                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnqualifiedId"));
                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                    return soulng::parser::Match(true, conversionFnId.release());
                                }
                            }
                            *parentMatch11 = match;
                        }
                        *parentMatch10 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch12 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch13 = &match;
                    {
                        int64_t pos = lexer.GetPos();
                        soulng::parser::Match match = LiteralParser::LiteralOperatorId(lexer, ctx);
                        literalOperatorId.reset(static_cast<Node*>(match.value));
                        if (match.hit)
                        {
                            {
                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnqualifiedId"));
                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                return soulng::parser::Match(true, literalOperatorId.release());
                            }
                        }
                        *parentMatch13 = match;
                    }
                    *parentMatch12 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch14 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch15 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::parser::Match match = FunctionParser::DestructorId(lexer, ctx);
                    destructorId.reset(static_cast<Node*>(match.value));
                    if (match.hit)
                    {
                        {
                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnqualifiedId"));
                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                            return soulng::parser::Match(true, destructorId.release());
                        }
                    }
                    *parentMatch15 = match;
                }
                *parentMatch14 = match;
            }
            *parentMatch0 = match;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("UnqualifiedId"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("UnqualifiedId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match IdentifierParser::QualifiedId(CppLexer& lexer, sngcpp::par::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("QualifiedId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    SourcePos s = SourcePos();
    SourcePos tmpPos = SourcePos();
    std::unique_ptr<Node> nns;
    std::unique_ptr<Node> tmp;
    std::unique_ptr<Node> unqualifiedId;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int64_t pos = lexer.GetPos();
                soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                soulng::parser::Match match = IdentifierParser::NestedNameSpecifier(lexer, ctx);
                nns.reset(static_cast<Node*>(match.value));
                if (match.hit)
                {
                    s = sourcePos;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
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
                        int64_t save = lexer.GetPos();
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                soulng::parser::Match match = IdentifierParser::Template(lexer);
                                tmp.reset(static_cast<Node*>(match.value));
                                if (match.hit)
                                {
                                    tmpPos = sourcePos;
                                }
                                *parentMatch7 = match;
                            }
                            *parentMatch6 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch8 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch9 = &match;
                                {
                                    int64_t pos = lexer.GetPos();
                                    soulng::parser::Match match = IdentifierParser::UnqualifiedId(lexer, ctx);
                                    unqualifiedId.reset(static_cast<Node*>(match.value));
                                    if (match.hit)
                                    {
                                        {
                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("QualifiedId"));
                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                            return soulng::parser::Match(true, new QualifiedIdNode(s, nns.release(), new PrefixNode(tmpPos, tmp.release(), unqualifiedId.release())));
                                        }
                                    }
                                    *parentMatch9 = match;
                                }
                                *parentMatch8 = match;
                            }
                            *parentMatch6 = match;
                        }
                        *parentMatch5 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch10 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch11 = &match;
                                {
                                    int64_t pos = lexer.GetPos();
                                    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                    soulng::parser::Match match = IdentifierParser::UnqualifiedId(lexer, ctx);
                                    unqualifiedId.reset(static_cast<Node*>(match.value));
                                    if (match.hit)
                                    {
                                        {
                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("QualifiedId"));
                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                            return soulng::parser::Match(true, new QualifiedIdNode(sourcePos, nns.release(), unqualifiedId.release()));
                                        }
                                    }
                                    *parentMatch11 = match;
                                }
                                *parentMatch10 = match;
                            }
                            *parentMatch5 = match;
                        }
                    }
                    *parentMatch4 = match;
                }
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("QualifiedId"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("QualifiedId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match IdentifierParser::Template(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("Template"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
        soulng::parser::Match match(false);
        if (*lexer == TEMPLATE)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Template"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new TemplateNode(sourcePos));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Template"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("Template"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match IdentifierParser::NestedNameSpecifier(CppLexer& lexer, sngcpp::par::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("NestedNameSpecifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<NestedNameSpecifierNode> nnsNode = std::unique_ptr<NestedNameSpecifierNode>();
    std::unique_ptr<Node> idNode = std::unique_ptr<Node>();
    std::unique_ptr<Node> simpleTemplateId;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        bool pass = true;
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
                        int64_t pos = lexer.GetPos();
                        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                        soulng::parser::Match match(true);
                        if (match.hit)
                        {
                            nnsNode.reset(new NestedNameSpecifierNode(sourcePos));
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        soulng::parser::Match match(true);
                        int64_t save = lexer.GetPos();
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch8 = &match;
                                {
                                    int64_t pos = lexer.GetPos();
                                    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                    soulng::parser::Match match(false);
                                    if (*lexer == COLONCOLON)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        nnsNode->AddNode(new ColonColonNode(sourcePos));
                                    }
                                    *parentMatch8 = match;
                                }
                                *parentMatch7 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch6 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                            }
                        }
                        *parentMatch5 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch9 = &match;
                {
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch10 = &match;
                    {
                        while (true)
                        {
                            int64_t save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch11 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch12 = &match;
                                    {
                                        int64_t save = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch13 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch14 = &match;
                                            {
                                                int64_t pos = lexer.GetPos();
                                                soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                soulng::parser::Match match(false);
                                                if (*lexer == ID)
                                                {
                                                    ++lexer;
                                                    match.hit = true;
                                                }
                                                if (match.hit)
                                                {
                                                    idNode.reset(new IdentifierNode(sourcePos, lexer.GetMatch(pos)));
                                                }
                                                *parentMatch14 = match;
                                            }
                                            *parentMatch13 = match;
                                        }
                                        if (match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch15 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch16 = &match;
                                                {
                                                    int64_t pos = lexer.GetPos();
                                                    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                    soulng::parser::Match match(false);
                                                    if (*lexer == COLONCOLON)
                                                    {
                                                        ++lexer;
                                                        match.hit = true;
                                                    }
                                                    if (match.hit)
                                                    {
                                                        nnsNode->AddNode(idNode.release());
                                                        nnsNode->AddNode(new ColonColonNode(sourcePos));
                                                    }
                                                    *parentMatch16 = match;
                                                }
                                                *parentMatch15 = match;
                                            }
                                            *parentMatch13 = match;
                                        }
                                        *parentMatch12 = match;
                                        if (!match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch17 = &match;
                                            lexer.SetPos(save);
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch18 = &match;
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch19 = &match;
                                                    {
                                                        soulng::parser::Match match(true);
                                                        int64_t save = lexer.GetPos();
                                                        soulng::parser::Match* parentMatch20 = &match;
                                                        {
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch21 = &match;
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch22 = &match;
                                                                {
                                                                    int64_t pos = lexer.GetPos();
                                                                    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                    soulng::parser::Match match(false);
                                                                    if (*lexer == TEMPLATE)
                                                                    {
                                                                        ++lexer;
                                                                        match.hit = true;
                                                                    }
                                                                    if (match.hit)
                                                                    {
                                                                        nnsNode->AddNode(new TemplateNode(sourcePos));
                                                                    }
                                                                    *parentMatch22 = match;
                                                                }
                                                                *parentMatch21 = match;
                                                            }
                                                            if (match.hit)
                                                            {
                                                                *parentMatch20 = match;
                                                            }
                                                            else
                                                            {
                                                                lexer.SetPos(save);
                                                            }
                                                        }
                                                        *parentMatch19 = match;
                                                    }
                                                    if (match.hit)
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch23 = &match;
                                                        {
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch24 = &match;
                                                            {
                                                                int64_t pos = lexer.GetPos();
                                                                soulng::parser::Match match = TemplateParser::SimpleTemplateId(lexer, ctx);
                                                                simpleTemplateId.reset(static_cast<Node*>(match.value));
                                                                if (match.hit)
                                                                {
                                                                    idNode.reset(simpleTemplateId.release());
                                                                }
                                                                *parentMatch24 = match;
                                                            }
                                                            *parentMatch23 = match;
                                                        }
                                                        *parentMatch19 = match;
                                                    }
                                                    *parentMatch18 = match;
                                                }
                                                if (match.hit)
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch25 = &match;
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch26 = &match;
                                                        {
                                                            int64_t pos = lexer.GetPos();
                                                            soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                            soulng::parser::Match match(false);
                                                            if (*lexer == COLONCOLON)
                                                            {
                                                                ++lexer;
                                                                match.hit = true;
                                                            }
                                                            if (match.hit)
                                                            {
                                                                nnsNode->AddNode(idNode.release());
                                                                nnsNode->AddNode(new ColonColonNode(sourcePos));
                                                            }
                                                            *parentMatch26 = match;
                                                        }
                                                        *parentMatch25 = match;
                                                    }
                                                    *parentMatch18 = match;
                                                }
                                                *parentMatch17 = match;
                                            }
                                            *parentMatch12 = match;
                                        }
                                    }
                                    *parentMatch11 = match;
                                }
                                if (match.hit)
                                {
                                    *parentMatch10 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                    break;
                                }
                            }
                        }
                    }
                    *parentMatch9 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            if (nnsNode->Nodes().IsEmpty())
            {
                pass = false;
            }
            else
            {
                nnsNode->SetSourcePos(nnsNode->Nodes()[0]->GetSourcePos());
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("NestedNameSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, nnsNode.release());
                }
            }
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
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("NestedNameSpecifier"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("NestedNameSpecifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match IdentifierParser::IdentifierList(CppLexer& lexer, sngcpp::par::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("IdentifierList"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<Node> identifierListNode = std::unique_ptr<Node>();
    std::unique_ptr<Node> first;
    std::unique_ptr<Node> comma;
    std::unique_ptr<Node> next;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                    soulng::parser::Match match = IdentifierParser::Identifier(lexer, ctx);
                    first.reset(static_cast<Node*>(match.value));
                    if (match.hit)
                    {
                        identifierListNode.reset(new IdentifierListNode(sourcePos));
                        identifierListNode->AddNode(first.release());
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        while (true)
                        {
                            int64_t save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            int64_t pos = lexer.GetPos();
                                            soulng::parser::Match match = FunctionParser::Comma(lexer);
                                            comma.reset(static_cast<Node*>(match.value));
                                            if (match.hit)
                                            {
                                                identifierListNode->AddNode(comma.release());
                                            }
                                            *parentMatch8 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch10 = &match;
                                            {
                                                int64_t pos = lexer.GetPos();
                                                soulng::parser::Match match = IdentifierParser::Identifier(lexer, ctx);
                                                next.reset(static_cast<Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    identifierListNode->AddNode(next.release());
                                                }
                                                *parentMatch10 = match;
                                            }
                                            *parentMatch9 = match;
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
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("IdentifierList"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, identifierListNode.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("IdentifierList"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("IdentifierList"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match IdentifierParser::Unnamed(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("Unnamed"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
        soulng::parser::Match match(true);
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Unnamed"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new UnnamedNode(sourcePos));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Unnamed"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("Unnamed"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match IdentifierParser::Dot(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("Dot"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
        soulng::parser::Match match(false);
        if (*lexer == DOT)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Dot"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new DotNode(sourcePos));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Dot"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("Dot"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match IdentifierParser::ColonColon(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ColonColon"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
        soulng::parser::Match match(false);
        if (*lexer == COLONCOLON)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ColonColon"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new ColonColonNode(sourcePos));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ColonColon"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ColonColon"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}
