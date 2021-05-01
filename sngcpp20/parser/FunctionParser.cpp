#include "FunctionParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <sngcpp20/parser/AttributeParser.hpp>
#include <sngcpp20/parser/ClassParser.hpp>
#include <sngcpp20/parser/ConceptParser.hpp>
#include <sngcpp20/parser/DeclarationParser.hpp>
#include <sngcpp20/parser/ExpressionParser.hpp>
#include <sngcpp20/parser/InitializationParser.hpp>
#include <sngcpp20/parser/StatementParser.hpp>
#include <sngcpp20/parser/TypeParser.hpp>
#include <sngcpp20/lexer/CppLexer.hpp>
#include <sngcpp20/lexer/CppTokens.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/FunctionParser.parser' using soulng parser generator spg version 3.11.0

using namespace soulng::unicode;
using namespace sngcpp::par;
using namespace sngcpp::ast;
using namespace CppTokens;
using namespace soulng::lexer;

soulng::parser::Match FunctionParser::FunctionDefinition(CppLexer& lexer, sngcpp::par::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("FunctionDefinition"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    SourcePos s = SourcePos();
    std::unique_ptr<Node> specifierNode = std::unique_ptr<Node>();
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> declSpecifiers;
    std::unique_ptr<Node> declarator;
    std::unique_ptr<Node> virtSpecifiers;
    std::unique_ptr<Node> requiresClause;
    std::unique_ptr<Node> functionBody;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(true);
                    int64_t save = lexer.GetPos();
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                soulng::parser::Match match = AttributeParser::AttributeSpecifierSeq(lexer, ctx);
                                attributes.reset(static_cast<Node*>(match.value));
                                if (match.hit)
                                {
                                    s = sourcePos;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch4 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                        }
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch7 = &match;
                    {
                        soulng::parser::Match match(true);
                        int64_t save = lexer.GetPos();
                        soulng::parser::Match* parentMatch8 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch9 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch10 = &match;
                                {
                                    int64_t pos = lexer.GetPos();
                                    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                    soulng::parser::Match match = DeclarationParser::DeclSpecifierSeq(lexer, ctx);
                                    declSpecifiers.reset(static_cast<Node*>(match.value));
                                    if (match.hit)
                                    {
                                        if (!s.IsValid()) s = sourcePos;
                                    }
                                    *parentMatch10 = match;
                                }
                                *parentMatch9 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch8 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                            }
                        }
                        *parentMatch7 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch11 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch12 = &match;
                    {
                        int64_t pos = lexer.GetPos();
                        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                        soulng::parser::Match match = DeclarationParser::Declarator(lexer, ctx);
                        declarator.reset(static_cast<Node*>(match.value));
                        if (match.hit)
                        {
                            if (!s.IsValid()) s = sourcePos;
                        }
                        *parentMatch12 = match;
                    }
                    *parentMatch11 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch13 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch14 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch15 = &match;
                    {
                        int64_t save = lexer.GetPos();
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch16 = &match;
                        {
                            int64_t save = lexer.GetPos();
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch17 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::parser::Match match = ClassParser::VirtSpecifierSeq(lexer, ctx);
                                virtSpecifiers.reset(static_cast<Node*>(match.value));
                                if (match.hit)
                                {
                                    specifierNode.reset(virtSpecifiers.release());
                                }
                                *parentMatch17 = match;
                            }
                            *parentMatch16 = match;
                            if (!match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch18 = &match;
                                lexer.SetPos(save);
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch19 = &match;
                                    {
                                        int64_t pos = lexer.GetPos();
                                        soulng::parser::Match match = ConceptParser::RequiresClause(lexer, ctx);
                                        requiresClause.reset(static_cast<Node*>(match.value));
                                        if (match.hit)
                                        {
                                            specifierNode.reset(requiresClause.release());
                                        }
                                        *parentMatch19 = match;
                                    }
                                    *parentMatch18 = match;
                                }
                                *parentMatch16 = match;
                            }
                        }
                        *parentMatch15 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch20 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(true);
                                *parentMatch20 = match;
                            }
                            *parentMatch15 = match;
                        }
                    }
                    *parentMatch14 = match;
                }
                *parentMatch13 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch21 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch22 = &match;
            {
                int64_t pos = lexer.GetPos();
                soulng::parser::Match match = FunctionParser::FunctionBody(lexer, ctx);
                functionBody.reset(static_cast<Node*>(match.value));
                if (match.hit)
                {
                    {
                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("FunctionDefinition"));
                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                        return soulng::parser::Match(true, new FunctionDefinitionNode(s, attributes.release(), declSpecifiers.release(), declarator.release(), specifierNode.release(), functionBody.release()));
                    }
                }
                *parentMatch22 = match;
            }
            *parentMatch21 = match;
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("FunctionDefinition"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("FunctionDefinition"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match FunctionParser::FunctionBody(CppLexer& lexer, sngcpp::par::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("FunctionBody"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    SourcePos s = SourcePos();
    std::unique_ptr<Node> assign;
    std::unique_ptr<Node> def;
    std::unique_ptr<Node> semicolon;
    std::unique_ptr<Node> del;
    std::unique_ptr<Node> semicolon2;
    std::unique_ptr<Node> ctorInitializer;
    std::unique_ptr<Node> compoundStatement;
    std::unique_ptr<Node> compoundStatement2;
    std::unique_ptr<Node> functionTryBlock;
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
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int64_t pos = lexer.GetPos();
                        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                        soulng::parser::Match match = FunctionParser::Assign(lexer);
                        assign.reset(static_cast<Node*>(match.value));
                        if (match.hit)
                        {
                            s = sourcePos;
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
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                int64_t save = lexer.GetPos();
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch8 = &match;
                                {
                                    soulng::parser::Match match = FunctionParser::Default(lexer);
                                    def.reset(static_cast<Node*>(match.value));
                                    *parentMatch8 = match;
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
                                            soulng::parser::Match match = StatementParser::Semicolon(lexer);
                                            semicolon.reset(static_cast<Node*>(match.value));
                                            if (match.hit)
                                            {
                                                {
                                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("FunctionBody"));
                                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                    return soulng::parser::Match(true, new GeneratedFunctionBodyNode(s, assign.release(), def.release(), semicolon.release()));
                                                }
                                            }
                                            *parentMatch10 = match;
                                        }
                                        *parentMatch9 = match;
                                    }
                                    *parentMatch8 = match;
                                }
                                *parentMatch7 = match;
                                if (!match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch11 = &match;
                                    lexer.SetPos(save);
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch12 = &match;
                                        {
                                            soulng::parser::Match match = FunctionParser::Delete(lexer);
                                            del.reset(static_cast<Node*>(match.value));
                                            *parentMatch12 = match;
                                        }
                                        if (match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch13 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch14 = &match;
                                                {
                                                    int64_t pos = lexer.GetPos();
                                                    soulng::parser::Match match = StatementParser::Semicolon(lexer);
                                                    semicolon2.reset(static_cast<Node*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        {
                                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("FunctionBody"));
                                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                            return soulng::parser::Match(true, new GeneratedFunctionBodyNode(s, assign.release(), del.release(), semicolon2.release()));
                                                        }
                                                    }
                                                    *parentMatch14 = match;
                                                }
                                                *parentMatch13 = match;
                                            }
                                            *parentMatch12 = match;
                                        }
                                        *parentMatch11 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                            }
                            *parentMatch6 = match;
                        }
                        *parentMatch5 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch15 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch16 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch17 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                soulng::parser::Match match = ClassParser::CtorInitializer(lexer, ctx);
                                ctorInitializer.reset(static_cast<Node*>(match.value));
                                if (match.hit)
                                {
                                    s = sourcePos;
                                }
                                *parentMatch17 = match;
                            }
                            *parentMatch16 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch18 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch19 = &match;
                                {
                                    int64_t pos = lexer.GetPos();
                                    soulng::parser::Match match = StatementParser::CompoundStatement(lexer, ctx);
                                    compoundStatement.reset(static_cast<Node*>(match.value));
                                    if (match.hit)
                                    {
                                        {
                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("FunctionBody"));
                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                            return soulng::parser::Match(true, new ConstructorNode(s, ctorInitializer.release(), compoundStatement.release()));
                                        }
                                    }
                                    *parentMatch19 = match;
                                }
                                *parentMatch18 = match;
                            }
                            *parentMatch16 = match;
                        }
                        *parentMatch15 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch20 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch21 = &match;
                    {
                        int64_t pos = lexer.GetPos();
                        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                        soulng::parser::Match match = StatementParser::CompoundStatement(lexer, ctx);
                        compoundStatement2.reset(static_cast<Node*>(match.value));
                        if (match.hit)
                        {
                            {
                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("FunctionBody"));
                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                return soulng::parser::Match(true, new FunctionBodyNode(sourcePos, compoundStatement2.release()));
                            }
                        }
                        *parentMatch21 = match;
                    }
                    *parentMatch20 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch22 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch23 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::parser::Match match = FunctionParser::FunctionTryBlock(lexer, ctx);
                    functionTryBlock.reset(static_cast<Node*>(match.value));
                    if (match.hit)
                    {
                        {
                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("FunctionBody"));
                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                            return soulng::parser::Match(true, functionTryBlock.release());
                        }
                    }
                    *parentMatch23 = match;
                }
                *parentMatch22 = match;
            }
            *parentMatch0 = match;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("FunctionBody"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("FunctionBody"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match FunctionParser::Default(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("Default"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
        soulng::parser::Match match(false);
        if (*lexer == DEFAULT)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Default"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new DefaultNode(sourcePos));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Default"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("Default"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match FunctionParser::Delete(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("Delete"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
        soulng::parser::Match match(false);
        if (*lexer == DELETE)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Delete"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new DeleteNode(sourcePos));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Delete"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("Delete"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match FunctionParser::NoDeclSpecFunctionDeclaration(CppLexer& lexer, sngcpp::par::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("NoDeclSpecFunctionDeclaration"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    SourcePos s = SourcePos();
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> declarator;
    std::unique_ptr<Node> semicolon;
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
                    soulng::parser::Match match(true);
                    int64_t save = lexer.GetPos();
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                soulng::parser::Match match = AttributeParser::AttributeSpecifierSeq(lexer, ctx);
                                attributes.reset(static_cast<Node*>(match.value));
                                if (match.hit)
                                {
                                    s = sourcePos;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch4 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                        }
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch7 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch8 = &match;
                        {
                            int64_t pos = lexer.GetPos();
                            soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                            soulng::parser::Match match = DeclarationParser::Declarator(lexer, ctx);
                            declarator.reset(static_cast<Node*>(match.value));
                            if (match.hit)
                            {
                                if (!s.IsValid()) s = sourcePos;
                            }
                            *parentMatch8 = match;
                        }
                        *parentMatch7 = match;
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
                    soulng::parser::Match match = StatementParser::Semicolon(lexer);
                    semicolon.reset(static_cast<Node*>(match.value));
                    *parentMatch9 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("NoDeclSpecFunctionDeclaration"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new FunctionDeclarationNode(s, declarator.release(), attributes.release(), semicolon.release()));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("NoDeclSpecFunctionDeclaration"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("NoDeclSpecFunctionDeclaration"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match FunctionParser::ParameterDeclarationClause(CppLexer& lexer, sngcpp::par::Context* ctx, sngcpp::ast::Node* container)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ParameterDeclarationClause"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<Node> comma;
    std::unique_ptr<Node> ellipses;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match = FunctionParser::ParameterDeclarationList(lexer, ctx, container);
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int64_t pos = lexer.GetPos();
                        soulng::parser::Match match = FunctionParser::Comma(lexer);
                        comma.reset(static_cast<Node*>(match.value));
                        if (match.hit)
                        {
                            container->AddNode(comma.release());
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::parser::Match match = ExpressionParser::Ellipses(lexer);
                    ellipses.reset(static_cast<Node*>(match.value));
                    if (match.hit)
                    {
                        container->AddNode(ellipses.release());
                    }
                    *parentMatch6 = match;
                }
                *parentMatch5 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch7 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch8 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch9 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch10 = &match;
                        {
                            int64_t pos = lexer.GetPos();
                            soulng::parser::Match match(true);
                            if (match.hit)
                            {
                                container->Clear();
                            }
                            *parentMatch10 = match;
                        }
                        *parentMatch9 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch11 = &match;
                        {
                            soulng::parser::Match match(true);
                            int64_t save = lexer.GetPos();
                            soulng::parser::Match* parentMatch12 = &match;
                            {
                                soulng::parser::Match match = FunctionParser::ParameterDeclarationList(lexer, ctx, container);
                                if (match.hit)
                                {
                                    *parentMatch12 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                }
                            }
                            *parentMatch11 = match;
                        }
                        *parentMatch9 = match;
                    }
                    *parentMatch8 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch13 = &match;
                    {
                        soulng::parser::Match match(true);
                        int64_t save = lexer.GetPos();
                        soulng::parser::Match* parentMatch14 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch15 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch16 = &match;
                                {
                                    int64_t pos = lexer.GetPos();
                                    soulng::parser::Match match = ExpressionParser::Ellipses(lexer);
                                    ellipses.reset(static_cast<Node*>(match.value));
                                    if (match.hit)
                                    {
                                        container->AddNode(ellipses.release());
                                    }
                                    *parentMatch16 = match;
                                }
                                *parentMatch15 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch14 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                            }
                        }
                        *parentMatch13 = match;
                    }
                    *parentMatch8 = match;
                }
                *parentMatch7 = match;
            }
            *parentMatch0 = match;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ParameterDeclarationClause"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ParameterDeclarationClause"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match FunctionParser::ParameterDeclarationList(CppLexer& lexer, sngcpp::par::Context* ctx, sngcpp::ast::Node* container)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ParameterDeclarationList"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<Node> first;
    std::unique_ptr<Node> comma;
    std::unique_ptr<Node> next;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int64_t pos = lexer.GetPos();
            soulng::parser::Match match = FunctionParser::ParameterDeclaration(lexer, ctx);
            first.reset(static_cast<Node*>(match.value));
            if (match.hit)
            {
                container->AddNode(first.release());
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
                    int64_t save = lexer.GetPos();
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
                                    int64_t pos = lexer.GetPos();
                                    soulng::parser::Match match = FunctionParser::Comma(lexer);
                                    comma.reset(static_cast<Node*>(match.value));
                                    if (match.hit)
                                    {
                                        container->AddNode(comma.release());
                                    }
                                    *parentMatch6 = match;
                                }
                                *parentMatch5 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int64_t pos = lexer.GetPos();
                                        soulng::parser::Match match = FunctionParser::ParameterDeclaration(lexer, ctx);
                                        next.reset(static_cast<Node*>(match.value));
                                        if (match.hit)
                                        {
                                            container->AddNode(next.release());
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
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
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ParameterDeclarationList"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ParameterDeclarationList"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match FunctionParser::Comma(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("Comma"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
        soulng::parser::Match match(false);
        if (*lexer == COMMA)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Comma"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new CommaNode(sourcePos));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Comma"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("Comma"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match FunctionParser::ParameterDeclaration(CppLexer& lexer, sngcpp::par::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ParameterDeclaration"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<ParameterNode> node = std::unique_ptr<ParameterNode>();
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> declSpecifierSeq;
    std::unique_ptr<Node> declarator;
    std::unique_ptr<Node> abstractDeclarator;
    std::unique_ptr<Node> assign;
    std::unique_ptr<Node> initializer;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int64_t pos = lexer.GetPos();
            soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
            soulng::parser::Match match(true);
            if (match.hit)
            {
                node.reset(new ParameterNode(sourcePos));
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
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                int64_t pos = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                soulng::parser::Match match(true);
                                int64_t save = lexer.GetPos();
                                soulng::parser::Match* parentMatch8 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch9 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch10 = &match;
                                        {
                                            int64_t pos = lexer.GetPos();
                                            soulng::parser::Match match = AttributeParser::AttributeSpecifierSeq(lexer, ctx);
                                            attributes.reset(static_cast<Node*>(match.value));
                                            if (match.hit)
                                            {
                                                node->SetAttributes(attributes.release());
                                            }
                                            *parentMatch10 = match;
                                        }
                                        *parentMatch9 = match;
                                    }
                                    if (match.hit)
                                    {
                                        *parentMatch8 = match;
                                    }
                                    else
                                    {
                                        lexer.SetPos(save);
                                    }
                                }
                                *parentMatch7 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch11 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch12 = &match;
                                    {
                                        int64_t pos = lexer.GetPos();
                                        soulng::parser::Match match = DeclarationParser::DeclSpecifierSeq(lexer, ctx);
                                        declSpecifierSeq.reset(static_cast<Node*>(match.value));
                                        if (match.hit)
                                        {
                                            node->SetDeclSpecifiers(declSpecifierSeq.release());
                                        }
                                        *parentMatch12 = match;
                                    }
                                    *parentMatch11 = match;
                                }
                                *parentMatch7 = match;
                            }
                            *parentMatch6 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch13 = &match;
                            {
                                soulng::parser::Match match(true);
                                int64_t save = lexer.GetPos();
                                soulng::parser::Match* parentMatch14 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch15 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch16 = &match;
                                        {
                                            int64_t save = lexer.GetPos();
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch17 = &match;
                                            {
                                                int64_t pos = lexer.GetPos();
                                                soulng::parser::Match match = DeclarationParser::Declarator(lexer, ctx);
                                                declarator.reset(static_cast<Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    node->SetDeclarator(declarator.release());
                                                }
                                                *parentMatch17 = match;
                                            }
                                            *parentMatch16 = match;
                                            if (!match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch18 = &match;
                                                lexer.SetPos(save);
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch19 = &match;
                                                    {
                                                        int64_t pos = lexer.GetPos();
                                                        soulng::parser::Match match = DeclarationParser::AbstractDeclarator(lexer, ctx);
                                                        abstractDeclarator.reset(static_cast<Node*>(match.value));
                                                        if (match.hit)
                                                        {
                                                            node->SetDeclarator(abstractDeclarator.release());
                                                        }
                                                        *parentMatch19 = match;
                                                    }
                                                    *parentMatch18 = match;
                                                }
                                                *parentMatch16 = match;
                                            }
                                        }
                                        *parentMatch15 = match;
                                    }
                                    if (match.hit)
                                    {
                                        *parentMatch14 = match;
                                    }
                                    else
                                    {
                                        lexer.SetPos(save);
                                    }
                                }
                                *parentMatch13 = match;
                            }
                            *parentMatch6 = match;
                        }
                        *parentMatch5 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch20 = &match;
                        {
                            soulng::parser::Match match(true);
                            int64_t save = lexer.GetPos();
                            soulng::parser::Match* parentMatch21 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch22 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch23 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch24 = &match;
                                        {
                                            int64_t pos = lexer.GetPos();
                                            soulng::parser::Match match = FunctionParser::Assign(lexer);
                                            assign.reset(static_cast<Node*>(match.value));
                                            if (match.hit)
                                            {
                                                node->SetAssign(assign.release());
                                            }
                                            *parentMatch24 = match;
                                        }
                                        *parentMatch23 = match;
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
                                                soulng::parser::Match match = InitializationParser::InitializerClause(lexer, ctx);
                                                initializer.reset(static_cast<Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    node->SetInitializer(initializer.release());
                                                }
                                                *parentMatch26 = match;
                                            }
                                            *parentMatch25 = match;
                                        }
                                        *parentMatch23 = match;
                                    }
                                    *parentMatch22 = match;
                                }
                                if (match.hit)
                                {
                                    *parentMatch21 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                }
                            }
                            *parentMatch20 = match;
                        }
                        *parentMatch5 = match;
                    }
                    *parentMatch4 = match;
                }
                if (match.hit)
                {
                    {
                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ParameterDeclaration"));
                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                        return soulng::parser::Match(true, node.release());
                    }
                }
                *parentMatch3 = match;
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ParameterDeclaration"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ParameterDeclaration"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match FunctionParser::Assign(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("Assign"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
        soulng::parser::Match match(false);
        if (*lexer == ASSIGN)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Assign"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new AssignNode(sourcePos));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Assign"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("Assign"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match FunctionParser::OperatorFunctionId(CppLexer& lexer, sngcpp::par::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("OperatorFunctionId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    SourcePos s = SourcePos();
    std::unique_ptr<Node> operatorKw;
    std::unique_ptr<Node> op;
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
                    soulng::parser::Match match = FunctionParser::OperatorKw(lexer);
                    operatorKw.reset(static_cast<Node*>(match.value));
                    if (match.hit)
                    {
                        s = sourcePos;
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
                    soulng::parser::Match match = FunctionParser::Operator(lexer, ctx);
                    op.reset(static_cast<Node*>(match.value));
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
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("OperatorFunctionId"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new OperatorFunctionIdNode(s, operatorKw.release(), op.release()));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("OperatorFunctionId"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("OperatorFunctionId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match FunctionParser::ConversionFunctionId(CppLexer& lexer, sngcpp::par::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ConversionFunctionId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    SourcePos s = SourcePos();
    std::unique_ptr<Node> operatorKw;
    std::unique_ptr<Node> conversionTypeId;
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
                    soulng::parser::Match match = FunctionParser::OperatorKw(lexer);
                    operatorKw.reset(static_cast<Node*>(match.value));
                    if (match.hit)
                    {
                        s = sourcePos;
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
                    soulng::parser::Match match = FunctionParser::ConversionTypeId(lexer, ctx);
                    conversionTypeId.reset(static_cast<Node*>(match.value));
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
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ConversionFunctionId"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new ConversionFunctionIdNode(s, operatorKw.release(), conversionTypeId.release()));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ConversionFunctionId"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ConversionFunctionId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match FunctionParser::DestructorId(CppLexer& lexer, sngcpp::par::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("DestructorId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<Node> node = std::unique_ptr<Node>();
    SourcePos s = SourcePos();
    std::unique_ptr<Node> typeName;
    std::unique_ptr<Node> declTypeSpecifier;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int64_t pos = lexer.GetPos();
            soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
            soulng::parser::Match match(false);
            if (*lexer == TILDE)
            {
                ++lexer;
                match.hit = true;
            }
            if (match.hit)
            {
                s = sourcePos;
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
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                int64_t pos = lexer.GetPos();
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
                            int64_t pos = lexer.GetPos();
                            soulng::parser::Match match = TypeParser::TypeName(lexer, ctx);
                            typeName.reset(static_cast<Node*>(match.value));
                            if (match.hit)
                            {
                                node.reset(typeName.release());
                            }
                            *parentMatch6 = match;
                        }
                        *parentMatch5 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch8 = &match;
                                {
                                    int64_t pos = lexer.GetPos();
                                    soulng::parser::Match match = TypeParser::DeclTypeSpecifier(lexer, ctx);
                                    declTypeSpecifier.reset(static_cast<Node*>(match.value));
                                    if (match.hit)
                                    {
                                        node.reset(declTypeSpecifier.release());
                                    }
                                    *parentMatch8 = match;
                                }
                                *parentMatch7 = match;
                            }
                            *parentMatch5 = match;
                        }
                    }
                    *parentMatch4 = match;
                }
                if (match.hit)
                {
                    {
                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("DestructorId"));
                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                        return soulng::parser::Match(true, new DestructorIdNode(s, node.release()));
                    }
                }
                *parentMatch3 = match;
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("DestructorId"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("DestructorId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match FunctionParser::ConversionTypeId(CppLexer& lexer, sngcpp::par::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ConversionTypeId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    SourcePos s = SourcePos();
    std::unique_ptr<Node> typeSpecifierSeq;
    std::unique_ptr<Node> declarator;
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
                    soulng::parser::Match match = TypeParser::TypeSpecifierSeq(lexer, ctx);
                    typeSpecifierSeq.reset(static_cast<Node*>(match.value));
                    if (match.hit)
                    {
                        s = sourcePos;
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
                    int64_t save = lexer.GetPos();
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        soulng::parser::Match match = FunctionParser::ConversionDeclarator(lexer, ctx);
                        declarator.reset(static_cast<Node*>(match.value));
                        if (match.hit)
                        {
                            *parentMatch5 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
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
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ConversionTypeId"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new ConversionTypeIdNode(s, typeSpecifierSeq.release(), declarator.release()));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ConversionTypeId"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ConversionTypeId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match FunctionParser::ConversionDeclarator(CppLexer& lexer, sngcpp::par::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ConversionDeclarator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    SourcePos s = SourcePos();
    std::unique_ptr<Node> op;
    std::unique_ptr<Node> declarator;
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
                    soulng::parser::Match match = DeclarationParser::PtrOperator(lexer, ctx);
                    op.reset(static_cast<Node*>(match.value));
                    if (match.hit)
                    {
                        s = sourcePos;
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
                    int64_t save = lexer.GetPos();
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        soulng::parser::Match match = FunctionParser::ConversionDeclarator(lexer, ctx);
                        declarator.reset(static_cast<Node*>(match.value));
                        if (match.hit)
                        {
                            *parentMatch5 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
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
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ConversionDeclarator"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new ConversionDeclaratorNode(s, op.release(), declarator.release()));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ConversionDeclarator"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ConversionDeclarator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match FunctionParser::OperatorKw(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("OperatorKw"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
        soulng::parser::Match match(false);
        if (*lexer == OPERATOR)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("OperatorKw"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new OperatorNode(sourcePos));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("OperatorKw"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("OperatorKw"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match FunctionParser::Operator(CppLexer& lexer, sngcpp::par::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("Operator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    SourcePos s = SourcePos();
    SourcePos lbPos = SourcePos();
    SourcePos rbPos = SourcePos();
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
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
                            int64_t save = lexer.GetPos();
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                int64_t save = lexer.GetPos();
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    int64_t save = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int64_t save = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            int64_t save = lexer.GetPos();
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch10 = &match;
                                            {
                                                int64_t save = lexer.GetPos();
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch11 = &match;
                                                {
                                                    int64_t save = lexer.GetPos();
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch12 = &match;
                                                    {
                                                        int64_t save = lexer.GetPos();
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch13 = &match;
                                                        {
                                                            int64_t save = lexer.GetPos();
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch14 = &match;
                                                            {
                                                                int64_t save = lexer.GetPos();
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch15 = &match;
                                                                {
                                                                    int64_t save = lexer.GetPos();
                                                                    soulng::parser::Match match(false);
                                                                    soulng::parser::Match* parentMatch16 = &match;
                                                                    {
                                                                        int64_t save = lexer.GetPos();
                                                                        soulng::parser::Match match(false);
                                                                        soulng::parser::Match* parentMatch17 = &match;
                                                                        {
                                                                            int64_t save = lexer.GetPos();
                                                                            soulng::parser::Match match(false);
                                                                            soulng::parser::Match* parentMatch18 = &match;
                                                                            {
                                                                                int64_t save = lexer.GetPos();
                                                                                soulng::parser::Match match(false);
                                                                                soulng::parser::Match* parentMatch19 = &match;
                                                                                {
                                                                                    int64_t save = lexer.GetPos();
                                                                                    soulng::parser::Match match(false);
                                                                                    soulng::parser::Match* parentMatch20 = &match;
                                                                                    {
                                                                                        int64_t save = lexer.GetPos();
                                                                                        soulng::parser::Match match(false);
                                                                                        soulng::parser::Match* parentMatch21 = &match;
                                                                                        {
                                                                                            int64_t save = lexer.GetPos();
                                                                                            soulng::parser::Match match(false);
                                                                                            soulng::parser::Match* parentMatch22 = &match;
                                                                                            {
                                                                                                int64_t save = lexer.GetPos();
                                                                                                soulng::parser::Match match(false);
                                                                                                soulng::parser::Match* parentMatch23 = &match;
                                                                                                {
                                                                                                    int64_t save = lexer.GetPos();
                                                                                                    soulng::parser::Match match(false);
                                                                                                    soulng::parser::Match* parentMatch24 = &match;
                                                                                                    {
                                                                                                        int64_t save = lexer.GetPos();
                                                                                                        soulng::parser::Match match(false);
                                                                                                        soulng::parser::Match* parentMatch25 = &match;
                                                                                                        {
                                                                                                            int64_t save = lexer.GetPos();
                                                                                                            soulng::parser::Match match(false);
                                                                                                            soulng::parser::Match* parentMatch26 = &match;
                                                                                                            {
                                                                                                                int64_t save = lexer.GetPos();
                                                                                                                soulng::parser::Match match(false);
                                                                                                                soulng::parser::Match* parentMatch27 = &match;
                                                                                                                {
                                                                                                                    int64_t save = lexer.GetPos();
                                                                                                                    soulng::parser::Match match(false);
                                                                                                                    soulng::parser::Match* parentMatch28 = &match;
                                                                                                                    {
                                                                                                                        int64_t save = lexer.GetPos();
                                                                                                                        soulng::parser::Match match(false);
                                                                                                                        soulng::parser::Match* parentMatch29 = &match;
                                                                                                                        {
                                                                                                                            int64_t save = lexer.GetPos();
                                                                                                                            soulng::parser::Match match(false);
                                                                                                                            soulng::parser::Match* parentMatch30 = &match;
                                                                                                                            {
                                                                                                                                int64_t save = lexer.GetPos();
                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                soulng::parser::Match* parentMatch31 = &match;
                                                                                                                                {
                                                                                                                                    int64_t save = lexer.GetPos();
                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                    soulng::parser::Match* parentMatch32 = &match;
                                                                                                                                    {
                                                                                                                                        int64_t save = lexer.GetPos();
                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                        soulng::parser::Match* parentMatch33 = &match;
                                                                                                                                        {
                                                                                                                                            int64_t save = lexer.GetPos();
                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                            soulng::parser::Match* parentMatch34 = &match;
                                                                                                                                            {
                                                                                                                                                int64_t save = lexer.GetPos();
                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                soulng::parser::Match* parentMatch35 = &match;
                                                                                                                                                {
                                                                                                                                                    int64_t save = lexer.GetPos();
                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                    soulng::parser::Match* parentMatch36 = &match;
                                                                                                                                                    {
                                                                                                                                                        int64_t save = lexer.GetPos();
                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                        soulng::parser::Match* parentMatch37 = &match;
                                                                                                                                                        {
                                                                                                                                                            int64_t save = lexer.GetPos();
                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                            soulng::parser::Match* parentMatch38 = &match;
                                                                                                                                                            {
                                                                                                                                                                int64_t save = lexer.GetPos();
                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                soulng::parser::Match* parentMatch39 = &match;
                                                                                                                                                                {
                                                                                                                                                                    int64_t save = lexer.GetPos();
                                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                                    soulng::parser::Match* parentMatch40 = &match;
                                                                                                                                                                    {
                                                                                                                                                                        int64_t save = lexer.GetPos();
                                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                                        soulng::parser::Match* parentMatch41 = &match;
                                                                                                                                                                        {
                                                                                                                                                                            int64_t save = lexer.GetPos();
                                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                                            soulng::parser::Match* parentMatch42 = &match;
                                                                                                                                                                            {
                                                                                                                                                                                int64_t save = lexer.GetPos();
                                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                                soulng::parser::Match* parentMatch43 = &match;
                                                                                                                                                                                {
                                                                                                                                                                                    int64_t save = lexer.GetPos();
                                                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                                                    soulng::parser::Match* parentMatch44 = &match;
                                                                                                                                                                                    {
                                                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                                                        soulng::parser::Match* parentMatch45 = &match;
                                                                                                                                                                                        {
                                                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                                                            soulng::parser::Match* parentMatch46 = &match;
                                                                                                                                                                                            {
                                                                                                                                                                                                int64_t pos = lexer.GetPos();
                                                                                                                                                                                                soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                                                if (*lexer == NEW)
                                                                                                                                                                                                {
                                                                                                                                                                                                    ++lexer;
                                                                                                                                                                                                    match.hit = true;
                                                                                                                                                                                                }
                                                                                                                                                                                                if (match.hit)
                                                                                                                                                                                                {
                                                                                                                                                                                                    s = sourcePos;
                                                                                                                                                                                                }
                                                                                                                                                                                                *parentMatch46 = match;
                                                                                                                                                                                            }
                                                                                                                                                                                            *parentMatch45 = match;
                                                                                                                                                                                        }
                                                                                                                                                                                        if (match.hit)
                                                                                                                                                                                        {
                                                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                                                            soulng::parser::Match* parentMatch47 = &match;
                                                                                                                                                                                            {
                                                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                                                soulng::parser::Match* parentMatch48 = &match;
                                                                                                                                                                                                {
                                                                                                                                                                                                    int64_t pos = lexer.GetPos();
                                                                                                                                                                                                    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                                                                    if (*lexer == LBRACKET)
                                                                                                                                                                                                    {
                                                                                                                                                                                                        ++lexer;
                                                                                                                                                                                                        match.hit = true;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    if (match.hit)
                                                                                                                                                                                                    {
                                                                                                                                                                                                        lbPos = sourcePos;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    *parentMatch48 = match;
                                                                                                                                                                                                }
                                                                                                                                                                                                *parentMatch47 = match;
                                                                                                                                                                                            }
                                                                                                                                                                                            *parentMatch45 = match;
                                                                                                                                                                                        }
                                                                                                                                                                                        *parentMatch44 = match;
                                                                                                                                                                                    }
                                                                                                                                                                                    if (match.hit)
                                                                                                                                                                                    {
                                                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                                                        soulng::parser::Match* parentMatch49 = &match;
                                                                                                                                                                                        {
                                                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                                                            soulng::parser::Match* parentMatch50 = &match;
                                                                                                                                                                                            {
                                                                                                                                                                                                int64_t pos = lexer.GetPos();
                                                                                                                                                                                                soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                                                if (*lexer == RBRACKET)
                                                                                                                                                                                                {
                                                                                                                                                                                                    ++lexer;
                                                                                                                                                                                                    match.hit = true;
                                                                                                                                                                                                }
                                                                                                                                                                                                if (match.hit)
                                                                                                                                                                                                {
                                                                                                                                                                                                    rbPos = sourcePos;
                                                                                                                                                                                                    {
                                                                                                                                                                                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                                                                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                                                        return soulng::parser::Match(true, new NewArrayOpNode(s, lbPos, rbPos));
                                                                                                                                                                                                    }
                                                                                                                                                                                                }
                                                                                                                                                                                                *parentMatch50 = match;
                                                                                                                                                                                            }
                                                                                                                                                                                            *parentMatch49 = match;
                                                                                                                                                                                        }
                                                                                                                                                                                        *parentMatch44 = match;
                                                                                                                                                                                    }
                                                                                                                                                                                    *parentMatch43 = match;
                                                                                                                                                                                    if (!match.hit)
                                                                                                                                                                                    {
                                                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                                                        soulng::parser::Match* parentMatch51 = &match;
                                                                                                                                                                                        lexer.SetPos(save);
                                                                                                                                                                                        {
                                                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                                                            soulng::parser::Match* parentMatch52 = &match;
                                                                                                                                                                                            {
                                                                                                                                                                                                int64_t pos = lexer.GetPos();
                                                                                                                                                                                                soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                                                if (*lexer == NEW)
                                                                                                                                                                                                {
                                                                                                                                                                                                    ++lexer;
                                                                                                                                                                                                    match.hit = true;
                                                                                                                                                                                                }
                                                                                                                                                                                                if (match.hit)
                                                                                                                                                                                                {
                                                                                                                                                                                                    {
                                                                                                                                                                                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                                                                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                                                        return soulng::parser::Match(true, new NewOpNode(sourcePos));
                                                                                                                                                                                                    }
                                                                                                                                                                                                }
                                                                                                                                                                                                *parentMatch52 = match;
                                                                                                                                                                                            }
                                                                                                                                                                                            *parentMatch51 = match;
                                                                                                                                                                                        }
                                                                                                                                                                                        *parentMatch43 = match;
                                                                                                                                                                                    }
                                                                                                                                                                                }
                                                                                                                                                                                *parentMatch42 = match;
                                                                                                                                                                                if (!match.hit)
                                                                                                                                                                                {
                                                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                                                    soulng::parser::Match* parentMatch53 = &match;
                                                                                                                                                                                    lexer.SetPos(save);
                                                                                                                                                                                    {
                                                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                                                        soulng::parser::Match* parentMatch54 = &match;
                                                                                                                                                                                        {
                                                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                                                            soulng::parser::Match* parentMatch55 = &match;
                                                                                                                                                                                            {
                                                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                                                soulng::parser::Match* parentMatch56 = &match;
                                                                                                                                                                                                {
                                                                                                                                                                                                    int64_t pos = lexer.GetPos();
                                                                                                                                                                                                    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                                                                    if (*lexer == DELETE)
                                                                                                                                                                                                    {
                                                                                                                                                                                                        ++lexer;
                                                                                                                                                                                                        match.hit = true;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    if (match.hit)
                                                                                                                                                                                                    {
                                                                                                                                                                                                        s = sourcePos;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    *parentMatch56 = match;
                                                                                                                                                                                                }
                                                                                                                                                                                                *parentMatch55 = match;
                                                                                                                                                                                            }
                                                                                                                                                                                            if (match.hit)
                                                                                                                                                                                            {
                                                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                                                soulng::parser::Match* parentMatch57 = &match;
                                                                                                                                                                                                {
                                                                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                                                                    soulng::parser::Match* parentMatch58 = &match;
                                                                                                                                                                                                    {
                                                                                                                                                                                                        int64_t pos = lexer.GetPos();
                                                                                                                                                                                                        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                                                                        if (*lexer == LBRACKET)
                                                                                                                                                                                                        {
                                                                                                                                                                                                            ++lexer;
                                                                                                                                                                                                            match.hit = true;
                                                                                                                                                                                                        }
                                                                                                                                                                                                        if (match.hit)
                                                                                                                                                                                                        {
                                                                                                                                                                                                            lbPos = sourcePos;
                                                                                                                                                                                                        }
                                                                                                                                                                                                        *parentMatch58 = match;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    *parentMatch57 = match;
                                                                                                                                                                                                }
                                                                                                                                                                                                *parentMatch55 = match;
                                                                                                                                                                                            }
                                                                                                                                                                                            *parentMatch54 = match;
                                                                                                                                                                                        }
                                                                                                                                                                                        if (match.hit)
                                                                                                                                                                                        {
                                                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                                                            soulng::parser::Match* parentMatch59 = &match;
                                                                                                                                                                                            {
                                                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                                                soulng::parser::Match* parentMatch60 = &match;
                                                                                                                                                                                                {
                                                                                                                                                                                                    int64_t pos = lexer.GetPos();
                                                                                                                                                                                                    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                                                                    if (*lexer == RBRACKET)
                                                                                                                                                                                                    {
                                                                                                                                                                                                        ++lexer;
                                                                                                                                                                                                        match.hit = true;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    if (match.hit)
                                                                                                                                                                                                    {
                                                                                                                                                                                                        rbPos = sourcePos;
                                                                                                                                                                                                        {
                                                                                                                                                                                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                                                                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                                                            return soulng::parser::Match(true, new DeleteArrayOpNode(s, lbPos, rbPos));
                                                                                                                                                                                                        }
                                                                                                                                                                                                    }
                                                                                                                                                                                                    *parentMatch60 = match;
                                                                                                                                                                                                }
                                                                                                                                                                                                *parentMatch59 = match;
                                                                                                                                                                                            }
                                                                                                                                                                                            *parentMatch54 = match;
                                                                                                                                                                                        }
                                                                                                                                                                                        *parentMatch53 = match;
                                                                                                                                                                                    }
                                                                                                                                                                                    *parentMatch42 = match;
                                                                                                                                                                                }
                                                                                                                                                                            }
                                                                                                                                                                            *parentMatch41 = match;
                                                                                                                                                                            if (!match.hit)
                                                                                                                                                                            {
                                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                                soulng::parser::Match* parentMatch61 = &match;
                                                                                                                                                                                lexer.SetPos(save);
                                                                                                                                                                                {
                                                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                                                    soulng::parser::Match* parentMatch62 = &match;
                                                                                                                                                                                    {
                                                                                                                                                                                        int64_t pos = lexer.GetPos();
                                                                                                                                                                                        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                                                        if (*lexer == DELETE)
                                                                                                                                                                                        {
                                                                                                                                                                                            ++lexer;
                                                                                                                                                                                            match.hit = true;
                                                                                                                                                                                        }
                                                                                                                                                                                        if (match.hit)
                                                                                                                                                                                        {
                                                                                                                                                                                            {
                                                                                                                                                                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                                                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                                                return soulng::parser::Match(true, new DeleteOpNode(sourcePos));
                                                                                                                                                                                            }
                                                                                                                                                                                        }
                                                                                                                                                                                        *parentMatch62 = match;
                                                                                                                                                                                    }
                                                                                                                                                                                    *parentMatch61 = match;
                                                                                                                                                                                }
                                                                                                                                                                                *parentMatch41 = match;
                                                                                                                                                                            }
                                                                                                                                                                        }
                                                                                                                                                                        *parentMatch40 = match;
                                                                                                                                                                        if (!match.hit)
                                                                                                                                                                        {
                                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                                            soulng::parser::Match* parentMatch63 = &match;
                                                                                                                                                                            lexer.SetPos(save);
                                                                                                                                                                            {
                                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                                soulng::parser::Match* parentMatch64 = &match;
                                                                                                                                                                                {
                                                                                                                                                                                    int64_t pos = lexer.GetPos();
                                                                                                                                                                                    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                                                    if (*lexer == CO_AWAIT)
                                                                                                                                                                                    {
                                                                                                                                                                                        ++lexer;
                                                                                                                                                                                        match.hit = true;
                                                                                                                                                                                    }
                                                                                                                                                                                    if (match.hit)
                                                                                                                                                                                    {
                                                                                                                                                                                        {
                                                                                                                                                                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                                                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                                            return soulng::parser::Match(true, new CoAwaitOpNode(sourcePos));
                                                                                                                                                                                        }
                                                                                                                                                                                    }
                                                                                                                                                                                    *parentMatch64 = match;
                                                                                                                                                                                }
                                                                                                                                                                                *parentMatch63 = match;
                                                                                                                                                                            }
                                                                                                                                                                            *parentMatch40 = match;
                                                                                                                                                                        }
                                                                                                                                                                    }
                                                                                                                                                                    *parentMatch39 = match;
                                                                                                                                                                    if (!match.hit)
                                                                                                                                                                    {
                                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                                        soulng::parser::Match* parentMatch65 = &match;
                                                                                                                                                                        lexer.SetPos(save);
                                                                                                                                                                        {
                                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                                            soulng::parser::Match* parentMatch66 = &match;
                                                                                                                                                                            {
                                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                                soulng::parser::Match* parentMatch67 = &match;
                                                                                                                                                                                {
                                                                                                                                                                                    int64_t pos = lexer.GetPos();
                                                                                                                                                                                    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                                                    if (*lexer == LPAREN)
                                                                                                                                                                                    {
                                                                                                                                                                                        ++lexer;
                                                                                                                                                                                        match.hit = true;
                                                                                                                                                                                    }
                                                                                                                                                                                    if (match.hit)
                                                                                                                                                                                    {
                                                                                                                                                                                        s = sourcePos;
                                                                                                                                                                                    }
                                                                                                                                                                                    *parentMatch67 = match;
                                                                                                                                                                                }
                                                                                                                                                                                *parentMatch66 = match;
                                                                                                                                                                            }
                                                                                                                                                                            if (match.hit)
                                                                                                                                                                            {
                                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                                soulng::parser::Match* parentMatch68 = &match;
                                                                                                                                                                                {
                                                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                                                    soulng::parser::Match* parentMatch69 = &match;
                                                                                                                                                                                    {
                                                                                                                                                                                        int64_t pos = lexer.GetPos();
                                                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                                                        if (*lexer == RPAREN)
                                                                                                                                                                                        {
                                                                                                                                                                                            ++lexer;
                                                                                                                                                                                            match.hit = true;
                                                                                                                                                                                        }
                                                                                                                                                                                        if (match.hit)
                                                                                                                                                                                        {
                                                                                                                                                                                            {
                                                                                                                                                                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                                                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                                                return soulng::parser::Match(true, new InvokeOpNode(s));
                                                                                                                                                                                            }
                                                                                                                                                                                        }
                                                                                                                                                                                        *parentMatch69 = match;
                                                                                                                                                                                    }
                                                                                                                                                                                    *parentMatch68 = match;
                                                                                                                                                                                }
                                                                                                                                                                                *parentMatch66 = match;
                                                                                                                                                                            }
                                                                                                                                                                            *parentMatch65 = match;
                                                                                                                                                                        }
                                                                                                                                                                        *parentMatch39 = match;
                                                                                                                                                                    }
                                                                                                                                                                }
                                                                                                                                                                *parentMatch38 = match;
                                                                                                                                                                if (!match.hit)
                                                                                                                                                                {
                                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                                    soulng::parser::Match* parentMatch70 = &match;
                                                                                                                                                                    lexer.SetPos(save);
                                                                                                                                                                    {
                                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                                        soulng::parser::Match* parentMatch71 = &match;
                                                                                                                                                                        {
                                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                                            soulng::parser::Match* parentMatch72 = &match;
                                                                                                                                                                            {
                                                                                                                                                                                int64_t pos = lexer.GetPos();
                                                                                                                                                                                soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                                if (*lexer == LBRACKET)
                                                                                                                                                                                {
                                                                                                                                                                                    ++lexer;
                                                                                                                                                                                    match.hit = true;
                                                                                                                                                                                }
                                                                                                                                                                                if (match.hit)
                                                                                                                                                                                {
                                                                                                                                                                                    s = sourcePos;
                                                                                                                                                                                }
                                                                                                                                                                                *parentMatch72 = match;
                                                                                                                                                                            }
                                                                                                                                                                            *parentMatch71 = match;
                                                                                                                                                                        }
                                                                                                                                                                        if (match.hit)
                                                                                                                                                                        {
                                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                                            soulng::parser::Match* parentMatch73 = &match;
                                                                                                                                                                            {
                                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                                soulng::parser::Match* parentMatch74 = &match;
                                                                                                                                                                                {
                                                                                                                                                                                    int64_t pos = lexer.GetPos();
                                                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                                                    if (*lexer == RBRACKET)
                                                                                                                                                                                    {
                                                                                                                                                                                        ++lexer;
                                                                                                                                                                                        match.hit = true;
                                                                                                                                                                                    }
                                                                                                                                                                                    if (match.hit)
                                                                                                                                                                                    {
                                                                                                                                                                                        {
                                                                                                                                                                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                                                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                                            return soulng::parser::Match(true, new SubscriptOpNode(s));
                                                                                                                                                                                        }
                                                                                                                                                                                    }
                                                                                                                                                                                    *parentMatch74 = match;
                                                                                                                                                                                }
                                                                                                                                                                                *parentMatch73 = match;
                                                                                                                                                                            }
                                                                                                                                                                            *parentMatch71 = match;
                                                                                                                                                                        }
                                                                                                                                                                        *parentMatch70 = match;
                                                                                                                                                                    }
                                                                                                                                                                    *parentMatch38 = match;
                                                                                                                                                                }
                                                                                                                                                            }
                                                                                                                                                            *parentMatch37 = match;
                                                                                                                                                            if (!match.hit)
                                                                                                                                                            {
                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                soulng::parser::Match* parentMatch75 = &match;
                                                                                                                                                                lexer.SetPos(save);
                                                                                                                                                                {
                                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                                    soulng::parser::Match* parentMatch76 = &match;
                                                                                                                                                                    {
                                                                                                                                                                        int64_t pos = lexer.GetPos();
                                                                                                                                                                        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                                        if (*lexer == ARROW)
                                                                                                                                                                        {
                                                                                                                                                                            ++lexer;
                                                                                                                                                                            match.hit = true;
                                                                                                                                                                        }
                                                                                                                                                                        if (match.hit)
                                                                                                                                                                        {
                                                                                                                                                                            {
                                                                                                                                                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                                return soulng::parser::Match(true, new ArrowNode(sourcePos));
                                                                                                                                                                            }
                                                                                                                                                                        }
                                                                                                                                                                        *parentMatch76 = match;
                                                                                                                                                                    }
                                                                                                                                                                    *parentMatch75 = match;
                                                                                                                                                                }
                                                                                                                                                                *parentMatch37 = match;
                                                                                                                                                            }
                                                                                                                                                        }
                                                                                                                                                        *parentMatch36 = match;
                                                                                                                                                        if (!match.hit)
                                                                                                                                                        {
                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                            soulng::parser::Match* parentMatch77 = &match;
                                                                                                                                                            lexer.SetPos(save);
                                                                                                                                                            {
                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                soulng::parser::Match* parentMatch78 = &match;
                                                                                                                                                                {
                                                                                                                                                                    int64_t pos = lexer.GetPos();
                                                                                                                                                                    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                                    if (*lexer == ARROWSTAR)
                                                                                                                                                                    {
                                                                                                                                                                        ++lexer;
                                                                                                                                                                        match.hit = true;
                                                                                                                                                                    }
                                                                                                                                                                    if (match.hit)
                                                                                                                                                                    {
                                                                                                                                                                        {
                                                                                                                                                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                            return soulng::parser::Match(true, new ArrowStarNode(sourcePos));
                                                                                                                                                                        }
                                                                                                                                                                    }
                                                                                                                                                                    *parentMatch78 = match;
                                                                                                                                                                }
                                                                                                                                                                *parentMatch77 = match;
                                                                                                                                                            }
                                                                                                                                                            *parentMatch36 = match;
                                                                                                                                                        }
                                                                                                                                                    }
                                                                                                                                                    *parentMatch35 = match;
                                                                                                                                                    if (!match.hit)
                                                                                                                                                    {
                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                        soulng::parser::Match* parentMatch79 = &match;
                                                                                                                                                        lexer.SetPos(save);
                                                                                                                                                        {
                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                            soulng::parser::Match* parentMatch80 = &match;
                                                                                                                                                            {
                                                                                                                                                                int64_t pos = lexer.GetPos();
                                                                                                                                                                soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                                if (*lexer == TILDE)
                                                                                                                                                                {
                                                                                                                                                                    ++lexer;
                                                                                                                                                                    match.hit = true;
                                                                                                                                                                }
                                                                                                                                                                if (match.hit)
                                                                                                                                                                {
                                                                                                                                                                    {
                                                                                                                                                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                        return soulng::parser::Match(true, new ComplementNode(sourcePos));
                                                                                                                                                                    }
                                                                                                                                                                }
                                                                                                                                                                *parentMatch80 = match;
                                                                                                                                                            }
                                                                                                                                                            *parentMatch79 = match;
                                                                                                                                                        }
                                                                                                                                                        *parentMatch35 = match;
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                                *parentMatch34 = match;
                                                                                                                                                if (!match.hit)
                                                                                                                                                {
                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                    soulng::parser::Match* parentMatch81 = &match;
                                                                                                                                                    lexer.SetPos(save);
                                                                                                                                                    {
                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                        soulng::parser::Match* parentMatch82 = &match;
                                                                                                                                                        {
                                                                                                                                                            int64_t pos = lexer.GetPos();
                                                                                                                                                            soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                                            if (*lexer == EXCLAMATION)
                                                                                                                                                            {
                                                                                                                                                                ++lexer;
                                                                                                                                                                match.hit = true;
                                                                                                                                                            }
                                                                                                                                                            if (match.hit)
                                                                                                                                                            {
                                                                                                                                                                {
                                                                                                                                                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                    return soulng::parser::Match(true, new NotNode(sourcePos));
                                                                                                                                                                }
                                                                                                                                                            }
                                                                                                                                                            *parentMatch82 = match;
                                                                                                                                                        }
                                                                                                                                                        *parentMatch81 = match;
                                                                                                                                                    }
                                                                                                                                                    *parentMatch34 = match;
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                            *parentMatch33 = match;
                                                                                                                                            if (!match.hit)
                                                                                                                                            {
                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                soulng::parser::Match* parentMatch83 = &match;
                                                                                                                                                lexer.SetPos(save);
                                                                                                                                                {
                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                    soulng::parser::Match* parentMatch84 = &match;
                                                                                                                                                    {
                                                                                                                                                        int64_t pos = lexer.GetPos();
                                                                                                                                                        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                                        if (*lexer == PLUS)
                                                                                                                                                        {
                                                                                                                                                            ++lexer;
                                                                                                                                                            match.hit = true;
                                                                                                                                                        }
                                                                                                                                                        if (match.hit)
                                                                                                                                                        {
                                                                                                                                                            {
                                                                                                                                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                                return soulng::parser::Match(true, new PlusNode(sourcePos));
                                                                                                                                                            }
                                                                                                                                                        }
                                                                                                                                                        *parentMatch84 = match;
                                                                                                                                                    }
                                                                                                                                                    *parentMatch83 = match;
                                                                                                                                                }
                                                                                                                                                *parentMatch33 = match;
                                                                                                                                            }
                                                                                                                                        }
                                                                                                                                        *parentMatch32 = match;
                                                                                                                                        if (!match.hit)
                                                                                                                                        {
                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                            soulng::parser::Match* parentMatch85 = &match;
                                                                                                                                            lexer.SetPos(save);
                                                                                                                                            {
                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                soulng::parser::Match* parentMatch86 = &match;
                                                                                                                                                {
                                                                                                                                                    int64_t pos = lexer.GetPos();
                                                                                                                                                    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                                    if (*lexer == MINUS)
                                                                                                                                                    {
                                                                                                                                                        ++lexer;
                                                                                                                                                        match.hit = true;
                                                                                                                                                    }
                                                                                                                                                    if (match.hit)
                                                                                                                                                    {
                                                                                                                                                        {
                                                                                                                                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                            return soulng::parser::Match(true, new MinusNode(sourcePos));
                                                                                                                                                        }
                                                                                                                                                    }
                                                                                                                                                    *parentMatch86 = match;
                                                                                                                                                }
                                                                                                                                                *parentMatch85 = match;
                                                                                                                                            }
                                                                                                                                            *parentMatch32 = match;
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                    *parentMatch31 = match;
                                                                                                                                    if (!match.hit)
                                                                                                                                    {
                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                        soulng::parser::Match* parentMatch87 = &match;
                                                                                                                                        lexer.SetPos(save);
                                                                                                                                        {
                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                            soulng::parser::Match* parentMatch88 = &match;
                                                                                                                                            {
                                                                                                                                                int64_t pos = lexer.GetPos();
                                                                                                                                                soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                                if (*lexer == STAR)
                                                                                                                                                {
                                                                                                                                                    ++lexer;
                                                                                                                                                    match.hit = true;
                                                                                                                                                }
                                                                                                                                                if (match.hit)
                                                                                                                                                {
                                                                                                                                                    {
                                                                                                                                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                        return soulng::parser::Match(true, new MulNode(sourcePos));
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                                *parentMatch88 = match;
                                                                                                                                            }
                                                                                                                                            *parentMatch87 = match;
                                                                                                                                        }
                                                                                                                                        *parentMatch31 = match;
                                                                                                                                    }
                                                                                                                                }
                                                                                                                                *parentMatch30 = match;
                                                                                                                                if (!match.hit)
                                                                                                                                {
                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                    soulng::parser::Match* parentMatch89 = &match;
                                                                                                                                    lexer.SetPos(save);
                                                                                                                                    {
                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                        soulng::parser::Match* parentMatch90 = &match;
                                                                                                                                        {
                                                                                                                                            int64_t pos = lexer.GetPos();
                                                                                                                                            soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                            soulng::parser::Match match(false);
                                                                                                                                            if (*lexer == DIV)
                                                                                                                                            {
                                                                                                                                                ++lexer;
                                                                                                                                                match.hit = true;
                                                                                                                                            }
                                                                                                                                            if (match.hit)
                                                                                                                                            {
                                                                                                                                                {
                                                                                                                                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                    return soulng::parser::Match(true, new DivNode(sourcePos));
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                            *parentMatch90 = match;
                                                                                                                                        }
                                                                                                                                        *parentMatch89 = match;
                                                                                                                                    }
                                                                                                                                    *parentMatch30 = match;
                                                                                                                                }
                                                                                                                            }
                                                                                                                            *parentMatch29 = match;
                                                                                                                            if (!match.hit)
                                                                                                                            {
                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                soulng::parser::Match* parentMatch91 = &match;
                                                                                                                                lexer.SetPos(save);
                                                                                                                                {
                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                    soulng::parser::Match* parentMatch92 = &match;
                                                                                                                                    {
                                                                                                                                        int64_t pos = lexer.GetPos();
                                                                                                                                        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                        soulng::parser::Match match(false);
                                                                                                                                        if (*lexer == MOD)
                                                                                                                                        {
                                                                                                                                            ++lexer;
                                                                                                                                            match.hit = true;
                                                                                                                                        }
                                                                                                                                        if (match.hit)
                                                                                                                                        {
                                                                                                                                            {
                                                                                                                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                                return soulng::parser::Match(true, new ModNode(sourcePos));
                                                                                                                                            }
                                                                                                                                        }
                                                                                                                                        *parentMatch92 = match;
                                                                                                                                    }
                                                                                                                                    *parentMatch91 = match;
                                                                                                                                }
                                                                                                                                *parentMatch29 = match;
                                                                                                                            }
                                                                                                                        }
                                                                                                                        *parentMatch28 = match;
                                                                                                                        if (!match.hit)
                                                                                                                        {
                                                                                                                            soulng::parser::Match match(false);
                                                                                                                            soulng::parser::Match* parentMatch93 = &match;
                                                                                                                            lexer.SetPos(save);
                                                                                                                            {
                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                soulng::parser::Match* parentMatch94 = &match;
                                                                                                                                {
                                                                                                                                    int64_t pos = lexer.GetPos();
                                                                                                                                    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                    soulng::parser::Match match(false);
                                                                                                                                    if (*lexer == XOR)
                                                                                                                                    {
                                                                                                                                        ++lexer;
                                                                                                                                        match.hit = true;
                                                                                                                                    }
                                                                                                                                    if (match.hit)
                                                                                                                                    {
                                                                                                                                        {
                                                                                                                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                            return soulng::parser::Match(true, new ExclusiveOrNode(sourcePos));
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                    *parentMatch94 = match;
                                                                                                                                }
                                                                                                                                *parentMatch93 = match;
                                                                                                                            }
                                                                                                                            *parentMatch28 = match;
                                                                                                                        }
                                                                                                                    }
                                                                                                                    *parentMatch27 = match;
                                                                                                                    if (!match.hit)
                                                                                                                    {
                                                                                                                        soulng::parser::Match match(false);
                                                                                                                        soulng::parser::Match* parentMatch95 = &match;
                                                                                                                        lexer.SetPos(save);
                                                                                                                        {
                                                                                                                            soulng::parser::Match match(false);
                                                                                                                            soulng::parser::Match* parentMatch96 = &match;
                                                                                                                            {
                                                                                                                                int64_t pos = lexer.GetPos();
                                                                                                                                soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                                soulng::parser::Match match(false);
                                                                                                                                if (*lexer == AMP)
                                                                                                                                {
                                                                                                                                    ++lexer;
                                                                                                                                    match.hit = true;
                                                                                                                                }
                                                                                                                                if (match.hit)
                                                                                                                                {
                                                                                                                                    {
                                                                                                                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                        return soulng::parser::Match(true, new AndNode(sourcePos));
                                                                                                                                    }
                                                                                                                                }
                                                                                                                                *parentMatch96 = match;
                                                                                                                            }
                                                                                                                            *parentMatch95 = match;
                                                                                                                        }
                                                                                                                        *parentMatch27 = match;
                                                                                                                    }
                                                                                                                }
                                                                                                                *parentMatch26 = match;
                                                                                                                if (!match.hit)
                                                                                                                {
                                                                                                                    soulng::parser::Match match(false);
                                                                                                                    soulng::parser::Match* parentMatch97 = &match;
                                                                                                                    lexer.SetPos(save);
                                                                                                                    {
                                                                                                                        soulng::parser::Match match(false);
                                                                                                                        soulng::parser::Match* parentMatch98 = &match;
                                                                                                                        {
                                                                                                                            int64_t pos = lexer.GetPos();
                                                                                                                            soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                            soulng::parser::Match match(false);
                                                                                                                            if (*lexer == OR)
                                                                                                                            {
                                                                                                                                ++lexer;
                                                                                                                                match.hit = true;
                                                                                                                            }
                                                                                                                            if (match.hit)
                                                                                                                            {
                                                                                                                                {
                                                                                                                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                    return soulng::parser::Match(true, new InclusiveOrNode(sourcePos));
                                                                                                                                }
                                                                                                                            }
                                                                                                                            *parentMatch98 = match;
                                                                                                                        }
                                                                                                                        *parentMatch97 = match;
                                                                                                                    }
                                                                                                                    *parentMatch26 = match;
                                                                                                                }
                                                                                                            }
                                                                                                            *parentMatch25 = match;
                                                                                                            if (!match.hit)
                                                                                                            {
                                                                                                                soulng::parser::Match match(false);
                                                                                                                soulng::parser::Match* parentMatch99 = &match;
                                                                                                                lexer.SetPos(save);
                                                                                                                {
                                                                                                                    soulng::parser::Match match(false);
                                                                                                                    soulng::parser::Match* parentMatch100 = &match;
                                                                                                                    {
                                                                                                                        int64_t pos = lexer.GetPos();
                                                                                                                        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                        soulng::parser::Match match(false);
                                                                                                                        if (*lexer == ASSIGN)
                                                                                                                        {
                                                                                                                            ++lexer;
                                                                                                                            match.hit = true;
                                                                                                                        }
                                                                                                                        if (match.hit)
                                                                                                                        {
                                                                                                                            {
                                                                                                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                                return soulng::parser::Match(true, new AssignNode(sourcePos));
                                                                                                                            }
                                                                                                                        }
                                                                                                                        *parentMatch100 = match;
                                                                                                                    }
                                                                                                                    *parentMatch99 = match;
                                                                                                                }
                                                                                                                *parentMatch25 = match;
                                                                                                            }
                                                                                                        }
                                                                                                        *parentMatch24 = match;
                                                                                                        if (!match.hit)
                                                                                                        {
                                                                                                            soulng::parser::Match match(false);
                                                                                                            soulng::parser::Match* parentMatch101 = &match;
                                                                                                            lexer.SetPos(save);
                                                                                                            {
                                                                                                                soulng::parser::Match match(false);
                                                                                                                soulng::parser::Match* parentMatch102 = &match;
                                                                                                                {
                                                                                                                    int64_t pos = lexer.GetPos();
                                                                                                                    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                    soulng::parser::Match match(false);
                                                                                                                    if (*lexer == ADDASSIGN)
                                                                                                                    {
                                                                                                                        ++lexer;
                                                                                                                        match.hit = true;
                                                                                                                    }
                                                                                                                    if (match.hit)
                                                                                                                    {
                                                                                                                        {
                                                                                                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                            return soulng::parser::Match(true, new PlusAssignNode(sourcePos));
                                                                                                                        }
                                                                                                                    }
                                                                                                                    *parentMatch102 = match;
                                                                                                                }
                                                                                                                *parentMatch101 = match;
                                                                                                            }
                                                                                                            *parentMatch24 = match;
                                                                                                        }
                                                                                                    }
                                                                                                    *parentMatch23 = match;
                                                                                                    if (!match.hit)
                                                                                                    {
                                                                                                        soulng::parser::Match match(false);
                                                                                                        soulng::parser::Match* parentMatch103 = &match;
                                                                                                        lexer.SetPos(save);
                                                                                                        {
                                                                                                            soulng::parser::Match match(false);
                                                                                                            soulng::parser::Match* parentMatch104 = &match;
                                                                                                            {
                                                                                                                int64_t pos = lexer.GetPos();
                                                                                                                soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                                soulng::parser::Match match(false);
                                                                                                                if (*lexer == SUBASSIGN)
                                                                                                                {
                                                                                                                    ++lexer;
                                                                                                                    match.hit = true;
                                                                                                                }
                                                                                                                if (match.hit)
                                                                                                                {
                                                                                                                    {
                                                                                                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                        return soulng::parser::Match(true, new MinusAssignNode(sourcePos));
                                                                                                                    }
                                                                                                                }
                                                                                                                *parentMatch104 = match;
                                                                                                            }
                                                                                                            *parentMatch103 = match;
                                                                                                        }
                                                                                                        *parentMatch23 = match;
                                                                                                    }
                                                                                                }
                                                                                                *parentMatch22 = match;
                                                                                                if (!match.hit)
                                                                                                {
                                                                                                    soulng::parser::Match match(false);
                                                                                                    soulng::parser::Match* parentMatch105 = &match;
                                                                                                    lexer.SetPos(save);
                                                                                                    {
                                                                                                        soulng::parser::Match match(false);
                                                                                                        soulng::parser::Match* parentMatch106 = &match;
                                                                                                        {
                                                                                                            int64_t pos = lexer.GetPos();
                                                                                                            soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                            soulng::parser::Match match(false);
                                                                                                            if (*lexer == MULASSIGN)
                                                                                                            {
                                                                                                                ++lexer;
                                                                                                                match.hit = true;
                                                                                                            }
                                                                                                            if (match.hit)
                                                                                                            {
                                                                                                                {
                                                                                                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                    return soulng::parser::Match(true, new MulAssignNode(sourcePos));
                                                                                                                }
                                                                                                            }
                                                                                                            *parentMatch106 = match;
                                                                                                        }
                                                                                                        *parentMatch105 = match;
                                                                                                    }
                                                                                                    *parentMatch22 = match;
                                                                                                }
                                                                                            }
                                                                                            *parentMatch21 = match;
                                                                                            if (!match.hit)
                                                                                            {
                                                                                                soulng::parser::Match match(false);
                                                                                                soulng::parser::Match* parentMatch107 = &match;
                                                                                                lexer.SetPos(save);
                                                                                                {
                                                                                                    soulng::parser::Match match(false);
                                                                                                    soulng::parser::Match* parentMatch108 = &match;
                                                                                                    {
                                                                                                        int64_t pos = lexer.GetPos();
                                                                                                        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                        soulng::parser::Match match(false);
                                                                                                        if (*lexer == DIVASSIGN)
                                                                                                        {
                                                                                                            ++lexer;
                                                                                                            match.hit = true;
                                                                                                        }
                                                                                                        if (match.hit)
                                                                                                        {
                                                                                                            {
                                                                                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                                return soulng::parser::Match(true, new DivAssignNode(sourcePos));
                                                                                                            }
                                                                                                        }
                                                                                                        *parentMatch108 = match;
                                                                                                    }
                                                                                                    *parentMatch107 = match;
                                                                                                }
                                                                                                *parentMatch21 = match;
                                                                                            }
                                                                                        }
                                                                                        *parentMatch20 = match;
                                                                                        if (!match.hit)
                                                                                        {
                                                                                            soulng::parser::Match match(false);
                                                                                            soulng::parser::Match* parentMatch109 = &match;
                                                                                            lexer.SetPos(save);
                                                                                            {
                                                                                                soulng::parser::Match match(false);
                                                                                                soulng::parser::Match* parentMatch110 = &match;
                                                                                                {
                                                                                                    int64_t pos = lexer.GetPos();
                                                                                                    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                    soulng::parser::Match match(false);
                                                                                                    if (*lexer == REMASSIGN)
                                                                                                    {
                                                                                                        ++lexer;
                                                                                                        match.hit = true;
                                                                                                    }
                                                                                                    if (match.hit)
                                                                                                    {
                                                                                                        {
                                                                                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                            return soulng::parser::Match(true, new ModAssignNode(sourcePos));
                                                                                                        }
                                                                                                    }
                                                                                                    *parentMatch110 = match;
                                                                                                }
                                                                                                *parentMatch109 = match;
                                                                                            }
                                                                                            *parentMatch20 = match;
                                                                                        }
                                                                                    }
                                                                                    *parentMatch19 = match;
                                                                                    if (!match.hit)
                                                                                    {
                                                                                        soulng::parser::Match match(false);
                                                                                        soulng::parser::Match* parentMatch111 = &match;
                                                                                        lexer.SetPos(save);
                                                                                        {
                                                                                            soulng::parser::Match match(false);
                                                                                            soulng::parser::Match* parentMatch112 = &match;
                                                                                            {
                                                                                                int64_t pos = lexer.GetPos();
                                                                                                soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                                soulng::parser::Match match(false);
                                                                                                if (*lexer == XORASSIGN)
                                                                                                {
                                                                                                    ++lexer;
                                                                                                    match.hit = true;
                                                                                                }
                                                                                                if (match.hit)
                                                                                                {
                                                                                                    {
                                                                                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                        return soulng::parser::Match(true, new XorAssignNode(sourcePos));
                                                                                                    }
                                                                                                }
                                                                                                *parentMatch112 = match;
                                                                                            }
                                                                                            *parentMatch111 = match;
                                                                                        }
                                                                                        *parentMatch19 = match;
                                                                                    }
                                                                                }
                                                                                *parentMatch18 = match;
                                                                                if (!match.hit)
                                                                                {
                                                                                    soulng::parser::Match match(false);
                                                                                    soulng::parser::Match* parentMatch113 = &match;
                                                                                    lexer.SetPos(save);
                                                                                    {
                                                                                        soulng::parser::Match match(false);
                                                                                        soulng::parser::Match* parentMatch114 = &match;
                                                                                        {
                                                                                            int64_t pos = lexer.GetPos();
                                                                                            soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                            soulng::parser::Match match(false);
                                                                                            if (*lexer == ANDASSIGN)
                                                                                            {
                                                                                                ++lexer;
                                                                                                match.hit = true;
                                                                                            }
                                                                                            if (match.hit)
                                                                                            {
                                                                                                {
                                                                                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                    return soulng::parser::Match(true, new AndAssignNode(sourcePos));
                                                                                                }
                                                                                            }
                                                                                            *parentMatch114 = match;
                                                                                        }
                                                                                        *parentMatch113 = match;
                                                                                    }
                                                                                    *parentMatch18 = match;
                                                                                }
                                                                            }
                                                                            *parentMatch17 = match;
                                                                            if (!match.hit)
                                                                            {
                                                                                soulng::parser::Match match(false);
                                                                                soulng::parser::Match* parentMatch115 = &match;
                                                                                lexer.SetPos(save);
                                                                                {
                                                                                    soulng::parser::Match match(false);
                                                                                    soulng::parser::Match* parentMatch116 = &match;
                                                                                    {
                                                                                        int64_t pos = lexer.GetPos();
                                                                                        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                        soulng::parser::Match match(false);
                                                                                        if (*lexer == ORASSIGN)
                                                                                        {
                                                                                            ++lexer;
                                                                                            match.hit = true;
                                                                                        }
                                                                                        if (match.hit)
                                                                                        {
                                                                                            {
                                                                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                                return soulng::parser::Match(true, new OrAssignNode(sourcePos));
                                                                                            }
                                                                                        }
                                                                                        *parentMatch116 = match;
                                                                                    }
                                                                                    *parentMatch115 = match;
                                                                                }
                                                                                *parentMatch17 = match;
                                                                            }
                                                                        }
                                                                        *parentMatch16 = match;
                                                                        if (!match.hit)
                                                                        {
                                                                            soulng::parser::Match match(false);
                                                                            soulng::parser::Match* parentMatch117 = &match;
                                                                            lexer.SetPos(save);
                                                                            {
                                                                                soulng::parser::Match match(false);
                                                                                soulng::parser::Match* parentMatch118 = &match;
                                                                                {
                                                                                    int64_t pos = lexer.GetPos();
                                                                                    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                    soulng::parser::Match match(false);
                                                                                    if (*lexer == SHIFTLEFTASSIGN)
                                                                                    {
                                                                                        ++lexer;
                                                                                        match.hit = true;
                                                                                    }
                                                                                    if (match.hit)
                                                                                    {
                                                                                        {
                                                                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                            return soulng::parser::Match(true, new ShiftLeftAssignNode(sourcePos));
                                                                                        }
                                                                                    }
                                                                                    *parentMatch118 = match;
                                                                                }
                                                                                *parentMatch117 = match;
                                                                            }
                                                                            *parentMatch16 = match;
                                                                        }
                                                                    }
                                                                    *parentMatch15 = match;
                                                                    if (!match.hit)
                                                                    {
                                                                        soulng::parser::Match match(false);
                                                                        soulng::parser::Match* parentMatch119 = &match;
                                                                        lexer.SetPos(save);
                                                                        {
                                                                            soulng::parser::Match match(false);
                                                                            soulng::parser::Match* parentMatch120 = &match;
                                                                            {
                                                                                int64_t pos = lexer.GetPos();
                                                                                soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                                soulng::parser::Match match(false);
                                                                                if (*lexer == SHIFTRIGHTASSIGN)
                                                                                {
                                                                                    ++lexer;
                                                                                    match.hit = true;
                                                                                }
                                                                                if (match.hit)
                                                                                {
                                                                                    {
                                                                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                        return soulng::parser::Match(true, new ShiftRightAssignNode(sourcePos));
                                                                                    }
                                                                                }
                                                                                *parentMatch120 = match;
                                                                            }
                                                                            *parentMatch119 = match;
                                                                        }
                                                                        *parentMatch15 = match;
                                                                    }
                                                                }
                                                                *parentMatch14 = match;
                                                                if (!match.hit)
                                                                {
                                                                    soulng::parser::Match match(false);
                                                                    soulng::parser::Match* parentMatch121 = &match;
                                                                    lexer.SetPos(save);
                                                                    {
                                                                        soulng::parser::Match match(false);
                                                                        soulng::parser::Match* parentMatch122 = &match;
                                                                        {
                                                                            int64_t pos = lexer.GetPos();
                                                                            soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                            soulng::parser::Match match(false);
                                                                            if (*lexer == EQ)
                                                                            {
                                                                                ++lexer;
                                                                                match.hit = true;
                                                                            }
                                                                            if (match.hit)
                                                                            {
                                                                                {
                                                                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                    return soulng::parser::Match(true, new EqualNode(sourcePos));
                                                                                }
                                                                            }
                                                                            *parentMatch122 = match;
                                                                        }
                                                                        *parentMatch121 = match;
                                                                    }
                                                                    *parentMatch14 = match;
                                                                }
                                                            }
                                                            *parentMatch13 = match;
                                                            if (!match.hit)
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch123 = &match;
                                                                lexer.SetPos(save);
                                                                {
                                                                    soulng::parser::Match match(false);
                                                                    soulng::parser::Match* parentMatch124 = &match;
                                                                    {
                                                                        int64_t pos = lexer.GetPos();
                                                                        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                        soulng::parser::Match match(false);
                                                                        if (*lexer == NEQ)
                                                                        {
                                                                            ++lexer;
                                                                            match.hit = true;
                                                                        }
                                                                        if (match.hit)
                                                                        {
                                                                            {
                                                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                                return soulng::parser::Match(true, new NotEqualNode(sourcePos));
                                                                            }
                                                                        }
                                                                        *parentMatch124 = match;
                                                                    }
                                                                    *parentMatch123 = match;
                                                                }
                                                                *parentMatch13 = match;
                                                            }
                                                        }
                                                        *parentMatch12 = match;
                                                        if (!match.hit)
                                                        {
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch125 = &match;
                                                            lexer.SetPos(save);
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch126 = &match;
                                                                {
                                                                    int64_t pos = lexer.GetPos();
                                                                    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                    soulng::parser::Match match(false);
                                                                    if (*lexer == LEQ)
                                                                    {
                                                                        ++lexer;
                                                                        match.hit = true;
                                                                    }
                                                                    if (match.hit)
                                                                    {
                                                                        {
                                                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                            return soulng::parser::Match(true, new LessOrEqualNode(sourcePos));
                                                                        }
                                                                    }
                                                                    *parentMatch126 = match;
                                                                }
                                                                *parentMatch125 = match;
                                                            }
                                                            *parentMatch12 = match;
                                                        }
                                                    }
                                                    *parentMatch11 = match;
                                                    if (!match.hit)
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch127 = &match;
                                                        lexer.SetPos(save);
                                                        {
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch128 = &match;
                                                            {
                                                                int64_t pos = lexer.GetPos();
                                                                soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                                soulng::parser::Match match(false);
                                                                if (*lexer == GEQ)
                                                                {
                                                                    ++lexer;
                                                                    match.hit = true;
                                                                }
                                                                if (match.hit)
                                                                {
                                                                    {
                                                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                        return soulng::parser::Match(true, new GreaterOrEqualNode(sourcePos));
                                                                    }
                                                                }
                                                                *parentMatch128 = match;
                                                            }
                                                            *parentMatch127 = match;
                                                        }
                                                        *parentMatch11 = match;
                                                    }
                                                }
                                                *parentMatch10 = match;
                                                if (!match.hit)
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch129 = &match;
                                                    lexer.SetPos(save);
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch130 = &match;
                                                        {
                                                            int64_t pos = lexer.GetPos();
                                                            soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                            soulng::parser::Match match(false);
                                                            if (*lexer == SPACESHIP)
                                                            {
                                                                ++lexer;
                                                                match.hit = true;
                                                            }
                                                            if (match.hit)
                                                            {
                                                                {
                                                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                    return soulng::parser::Match(true, new CompareNode(sourcePos));
                                                                }
                                                            }
                                                            *parentMatch130 = match;
                                                        }
                                                        *parentMatch129 = match;
                                                    }
                                                    *parentMatch10 = match;
                                                }
                                            }
                                            *parentMatch9 = match;
                                            if (!match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch131 = &match;
                                                lexer.SetPos(save);
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch132 = &match;
                                                    {
                                                        int64_t pos = lexer.GetPos();
                                                        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                        soulng::parser::Match match(false);
                                                        if (*lexer == LANGLE)
                                                        {
                                                            ++lexer;
                                                            match.hit = true;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            {
                                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                return soulng::parser::Match(true, new LessNode(sourcePos));
                                                            }
                                                        }
                                                        *parentMatch132 = match;
                                                    }
                                                    *parentMatch131 = match;
                                                }
                                                *parentMatch9 = match;
                                            }
                                        }
                                        *parentMatch8 = match;
                                        if (!match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch133 = &match;
                                            lexer.SetPos(save);
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch134 = &match;
                                                {
                                                    int64_t pos = lexer.GetPos();
                                                    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                    soulng::parser::Match match(false);
                                                    if (*lexer == RANGLE)
                                                    {
                                                        ++lexer;
                                                        match.hit = true;
                                                    }
                                                    if (match.hit)
                                                    {
                                                        {
                                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                            return soulng::parser::Match(true, new GreaterNode(sourcePos));
                                                        }
                                                    }
                                                    *parentMatch134 = match;
                                                }
                                                *parentMatch133 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                    }
                                    *parentMatch7 = match;
                                    if (!match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch135 = &match;
                                        lexer.SetPos(save);
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch136 = &match;
                                            {
                                                int64_t pos = lexer.GetPos();
                                                soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                                soulng::parser::Match match(false);
                                                if (*lexer == AMPAMP)
                                                {
                                                    ++lexer;
                                                    match.hit = true;
                                                }
                                                if (match.hit)
                                                {
                                                    {
                                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                        return soulng::parser::Match(true, new ConjunctionNode(sourcePos));
                                                    }
                                                }
                                                *parentMatch136 = match;
                                            }
                                            *parentMatch135 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                }
                                *parentMatch6 = match;
                                if (!match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch137 = &match;
                                    lexer.SetPos(save);
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch138 = &match;
                                        {
                                            int64_t pos = lexer.GetPos();
                                            soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                            soulng::parser::Match match(false);
                                            if (*lexer == OROR)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            if (match.hit)
                                            {
                                                {
                                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                    return soulng::parser::Match(true, new DisjunctionNode(sourcePos));
                                                }
                                            }
                                            *parentMatch138 = match;
                                        }
                                        *parentMatch137 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                            }
                            *parentMatch5 = match;
                            if (!match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch139 = &match;
                                lexer.SetPos(save);
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch140 = &match;
                                    {
                                        int64_t pos = lexer.GetPos();
                                        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                        soulng::parser::Match match(false);
                                        if (*lexer == SHIFTLEFT)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            {
                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                return soulng::parser::Match(true, new ShiftLeftNode(sourcePos));
                                            }
                                        }
                                        *parentMatch140 = match;
                                    }
                                    *parentMatch139 = match;
                                }
                                *parentMatch5 = match;
                            }
                        }
                        *parentMatch4 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch141 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch142 = &match;
                                {
                                    int64_t pos = lexer.GetPos();
                                    soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                    soulng::parser::Match match(false);
                                    if (*lexer == SHIFTRIGHT)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        {
                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                            return soulng::parser::Match(true, new ShiftRightNode(sourcePos));
                                        }
                                    }
                                    *parentMatch142 = match;
                                }
                                *parentMatch141 = match;
                            }
                            *parentMatch4 = match;
                        }
                    }
                    *parentMatch3 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch143 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch144 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                                soulng::parser::Match match(false);
                                if (*lexer == PLUSPLUS)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    {
                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                        return soulng::parser::Match(true, new PrefixIncNode(sourcePos));
                                    }
                                }
                                *parentMatch144 = match;
                            }
                            *parentMatch143 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch145 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch146 = &match;
                        {
                            int64_t pos = lexer.GetPos();
                            soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                            soulng::parser::Match match(false);
                            if (*lexer == MINUSMINUS)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                {
                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                    return soulng::parser::Match(true, new PrefixDecNode(sourcePos));
                                }
                            }
                            *parentMatch146 = match;
                        }
                        *parentMatch145 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch147 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch148 = &match;
                    {
                        int64_t pos = lexer.GetPos();
                        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                        soulng::parser::Match match(false);
                        if (*lexer == COMMA)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (match.hit)
                        {
                            {
                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                return soulng::parser::Match(true, new CommaNode(sourcePos));
                            }
                        }
                        *parentMatch148 = match;
                    }
                    *parentMatch147 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Operator"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("Operator"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match FunctionParser::Noexcept(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("Noexcept"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
        soulng::parser::Match match(false);
        if (*lexer == NOEXCEPT)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Noexcept"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new NoexceptNode(sourcePos));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("Noexcept"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("Noexcept"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}

soulng::parser::Match FunctionParser::FunctionTryBlock(CppLexer& lexer, sngcpp::par::Context* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("FunctionTryBlock"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    SourcePos s = SourcePos();
    std::unique_ptr<Node> ctorInitializer;
    std::unique_ptr<Node> tryBlock;
    std::unique_ptr<Node> handlers;
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
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int64_t pos = lexer.GetPos();
                            soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos();
                            soulng::parser::Match match(false);
                            if (*lexer == TRY)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                s = sourcePos;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match(true);
                            int64_t save = lexer.GetPos();
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                soulng::parser::Match match = ClassParser::CtorInitializer(lexer, ctx);
                                ctorInitializer.reset(static_cast<Node*>(match.value));
                                if (match.hit)
                                {
                                    *parentMatch7 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                }
                            }
                            *parentMatch6 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch8 = &match;
                    {
                        soulng::parser::Match match = StatementParser::CompoundStatement(lexer, ctx);
                        tryBlock.reset(static_cast<Node*>(match.value));
                        *parentMatch8 = match;
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
                    soulng::parser::Match match = StatementParser::HandlerSeq(lexer, ctx);
                    handlers.reset(static_cast<Node*>(match.value));
                    *parentMatch9 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("FunctionTryBlock"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new FunctionTryBlockNode(s, ctorInitializer.release(), tryBlock.release(), handlers.release()));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("FunctionTryBlock"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("FunctionTryBlock"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    if (!match.hit)
    {
        match.value = nullptr;
    }
    return match;
}
