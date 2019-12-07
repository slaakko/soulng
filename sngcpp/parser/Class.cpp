#include "Class.hpp"
#include <soulng/util/Unicode.hpp>
#include <sngcpp/parser/Declaration.hpp>
#include <sngcpp/parser/Declarator.hpp>
#include <sngcpp/parser/Enumeration.hpp>
#include <sngcpp/parser/Expression.hpp>
#include <sngcpp/parser/Function.hpp>
#include <sngcpp/parser/Identifier.hpp>
#include <sngcpp/parser/Literal.hpp>
#include <sngcpp/parser/Template.hpp>
#include <sngcpp/parser/TypeExpr.hpp>
#include <sngcpp/lexer/CppLexer.hpp>
#include <sngcpp/lexer/CppTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/parser/Class.parser' using soulng parser generator spg version 3.0.0

using namespace soulng::unicode;
using namespace CppTokens;
using namespace soulng::lexer;

soulng::parser::Match ClassParser::ClassDeclaration(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ClassDeclaration"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> classSpecifier;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match = ClassParser::ClassSpecifier(lexer, ctx);
        classSpecifier.reset(static_cast<sngcpp::ast::Node*>(match.value));
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
                int64_t pos = lexer.GetPos();
                soulng::parser::Match match(false);
                if (*lexer == SEMICOLON)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    {
                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ClassDeclaration"));
                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                        return soulng::parser::Match(true, classSpecifier.release());
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
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ClassDeclaration"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ClassDeclaration"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::ClassSpecifier(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ClassSpecifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::ClassNode> classNode = std::unique_ptr<sngcpp::ast::ClassNode>();
    std::unique_ptr<sngcpp::ast::ClassNode> classHead;
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
                            soulng::parser::Match match = ClassParser::ClassHead(lexer, ctx);
                            classHead.reset(static_cast<sngcpp::ast::ClassNode*>(match.value));
                            if (match.hit)
                            {
                                classNode.reset(classHead.release());
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
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match(false);
                                if (*lexer == LBRACE)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    classNode->SetOpenBraceSpan(span);
                                }
                                *parentMatch7 = match;
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
                        soulng::parser::Match match = ClassParser::MemberSpecifications(lexer, ctx, classNode.get());
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
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch10 = &match;
                    {
                        int64_t pos = lexer.GetPos();
                        soulng::lexer::Span span = lexer.GetSpan();
                        soulng::parser::Match match(false);
                        if (*lexer == RBRACE)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (match.hit)
                        {
                            classNode->SetCloseBraceSpan(span);
                        }
                        *parentMatch10 = match;
                    }
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
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ClassSpecifier"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, classNode.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ClassSpecifier"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ClassSpecifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::MemberSpecifications(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx, sngcpp::ast::ClassNode* classNode)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("MemberSpecifications"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(true);
    soulng::parser::Match* parentMatch0 = &match;
    {
        while (true)
        {
            int64_t save = lexer.GetPos();
            {
                soulng::parser::Match match = ClassParser::MemberSpecification(lexer, ctx, classNode);
                if (match.hit)
                {
                    *parentMatch0 = match;
                }
                else
                {
                    lexer.SetPos(save);
                    break;
                }
            }
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberSpecifications"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("MemberSpecifications"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::MemberSpecification(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx, sngcpp::ast::ClassNode* classNode)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("MemberSpecification"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    Span s = Span();
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Specifier>> accessSpecifier;
    std::unique_ptr<sngcpp::ast::Node> m1;
    std::unique_ptr<sngcpp::ast::Node> m2;
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
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int64_t pos = lexer.GetPos();
                        soulng::lexer::Span span = lexer.GetSpan();
                        soulng::parser::Match match = ClassParser::AccessSpecifier(lexer);
                        accessSpecifier.reset(static_cast<soulng::parser::Value<sngcpp::ast::Specifier>*>(match.value));
                        if (match.hit)
                        {
                            s = span;
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
                        if (*lexer == COLON)
                        {
                            ++lexer;
                            match.hit = true;
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
                soulng::parser::Match* parentMatch6 = &match;
                {
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch7 = &match;
                    {
                        while (true)
                        {
                            int64_t save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch8 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch9 = &match;
                                    {
                                        int64_t pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match = ClassParser::MemberDeclaration(lexer, ctx);
                                        m1.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                        if (match.hit)
                                        {
                                            s.end = span.end;
                                            classNode->AddDeclaration(s, new sngcpp::ast::MemberAccessDeclarationNode(s, accessSpecifier->value, m1.release(), true));
                                        }
                                        *parentMatch9 = match;
                                    }
                                    *parentMatch8 = match;
                                }
                                if (match.hit)
                                {
                                    *parentMatch7 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                    break;
                                }
                            }
                        }
                    }
                    *parentMatch6 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch10 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch11 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch12 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch13 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match = ClassParser::MemberDeclaration(lexer, ctx);
                                m2.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                if (match.hit)
                                {
                                    s = span;
                                    classNode->AddDeclaration(s, new sngcpp::ast::MemberAccessDeclarationNode(s, classNode->DefaultAccess(), m2.release(), false));
                                }
                                *parentMatch13 = match;
                            }
                            *parentMatch12 = match;
                        }
                        *parentMatch11 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(true);
                        soulng::parser::Match* parentMatch14 = &match;
                        while (true)
                        {
                            int64_t save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch15 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch16 = &match;
                                    {
                                        int64_t pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match = ClassParser::MemberDeclaration(lexer, ctx);
                                        m2.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                        if (match.hit)
                                        {
                                            s = span;
                                            classNode->AddDeclaration(s, new sngcpp::ast::MemberAccessDeclarationNode(s, classNode->DefaultAccess(), m2.release(), false));
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
                                    break;
                                }
                            }
                        }
                    }
                    *parentMatch10 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberSpecification"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("MemberSpecification"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::MemberDeclaration(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("MemberDeclaration"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> declarator = std::unique_ptr<sngcpp::ast::Node>();
    Span s = Span();
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Specifier>> declSpecifiers;
    std::unique_ptr<sngcpp::ast::Node> typeExpr;
    std::unique_ptr<sngcpp::ast::Node> d;
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Specifier>> virtPureSpecifiers;
    std::unique_ptr<sngcpp::ast::Node> initializer;
    std::unique_ptr<sngcpp::ast::Node> specialMemberFunctionDeclaration;
    std::unique_ptr<sngcpp::ast::Node> functionDefinition;
    std::unique_ptr<sngcpp::ast::Node> specialMemberFunctionDefition;
    std::unique_ptr<sngcpp::ast::Node> usingDeclaration;
    std::unique_ptr<sngcpp::ast::Node> typedefDeclaration;
    std::unique_ptr<sngcpp::ast::Node> templateDeclaration;
    std::unique_ptr<sngcpp::ast::Node> classDeclaration;
    std::unique_ptr<sngcpp::ast::Node> enumDeclaration;
    std::unique_ptr<sngcpp::ast::Node> aliasDeclaration;
    std::unique_ptr<sngcpp::ast::Node> forwardClassDeclaration;
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
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch11 = &match;
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch12 = &match;
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
                                                                    int64_t pos = lexer.GetPos();
                                                                    soulng::lexer::Span span = lexer.GetSpan();
                                                                    soulng::parser::Match match = DeclarationParser::DeclSpecifiers(lexer);
                                                                    declSpecifiers.reset(static_cast<soulng::parser::Value<sngcpp::ast::Specifier>*>(match.value));
                                                                    if (match.hit)
                                                                    {
                                                                        s = span;
                                                                    }
                                                                    *parentMatch15 = match;
                                                                }
                                                                *parentMatch14 = match;
                                                            }
                                                            if (match.hit)
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch16 = &match;
                                                                {
                                                                    soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                                                                    typeExpr.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                                    *parentMatch16 = match;
                                                                }
                                                                *parentMatch14 = match;
                                                            }
                                                            *parentMatch13 = match;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch17 = &match;
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch18 = &match;
                                                                {
                                                                    int64_t pos = lexer.GetPos();
                                                                    soulng::parser::Match match = DeclaratorParser::Declarator(lexer, ctx);
                                                                    d.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                                    if (match.hit)
                                                                    {
                                                                        declarator.reset(d.release());
                                                                    }
                                                                    *parentMatch18 = match;
                                                                }
                                                                *parentMatch17 = match;
                                                            }
                                                            *parentMatch13 = match;
                                                        }
                                                        *parentMatch12 = match;
                                                    }
                                                    if (match.hit)
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch19 = &match;
                                                        {
                                                            soulng::parser::Match match = ClassParser::VirtPureSpecifiers(lexer, sngcpp::ast::IsFunctionDeclarator(declarator.get()));
                                                            virtPureSpecifiers.reset(static_cast<soulng::parser::Value<sngcpp::ast::Specifier>*>(match.value));
                                                            *parentMatch19 = match;
                                                        }
                                                        *parentMatch12 = match;
                                                    }
                                                    *parentMatch11 = match;
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
                                                            soulng::parser::Match match = DeclaratorParser::BraceOrEqualInitializer(lexer, ctx);
                                                            initializer.reset(static_cast<sngcpp::ast::Node*>(match.value));
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
                                                    *parentMatch11 = match;
                                                }
                                                *parentMatch10 = match;
                                            }
                                            if (match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch22 = &match;
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch23 = &match;
                                                    {
                                                        int64_t pos = lexer.GetPos();
                                                        soulng::lexer::Span span = lexer.GetSpan();
                                                        soulng::parser::Match match(false);
                                                        if (*lexer == SEMICOLON)
                                                        {
                                                            ++lexer;
                                                            match.hit = true;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            s.end = span.end;
                                                            {
                                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberDeclaration"));
                                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                return soulng::parser::Match(true, new sngcpp::ast::MemberDeclarationNode(s, declSpecifiers->value | virtPureSpecifiers->value, typeExpr.release(), declarator.release(), initializer.release()));
                                                            }
                                                        }
                                                        *parentMatch23 = match;
                                                    }
                                                    *parentMatch22 = match;
                                                }
                                                *parentMatch10 = match;
                                            }
                                            *parentMatch9 = match;
                                            if (!match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch24 = &match;
                                                lexer.SetPos(save);
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch25 = &match;
                                                    {
                                                        int64_t pos = lexer.GetPos();
                                                        soulng::parser::Match match = ClassParser::SpecialMemberFunctionDeclaration(lexer, ctx);
                                                        specialMemberFunctionDeclaration.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                        if (match.hit)
                                                        {
                                                            {
                                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberDeclaration"));
                                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                                return soulng::parser::Match(true, specialMemberFunctionDeclaration.release());
                                                            }
                                                        }
                                                        *parentMatch25 = match;
                                                    }
                                                    *parentMatch24 = match;
                                                }
                                                *parentMatch9 = match;
                                            }
                                        }
                                        *parentMatch8 = match;
                                        if (!match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch26 = &match;
                                            lexer.SetPos(save);
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch27 = &match;
                                                {
                                                    int64_t pos = lexer.GetPos();
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch28 = &match;
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch29 = &match;
                                                        {
                                                            soulng::parser::Match match = FunctionParser::FunctionDefinition(lexer, ctx);
                                                            functionDefinition.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                            *parentMatch29 = match;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch30 = &match;
                                                            {
                                                                soulng::parser::Match match(true);
                                                                int64_t save = lexer.GetPos();
                                                                soulng::parser::Match* parentMatch31 = &match;
                                                                {
                                                                    soulng::parser::Match match(false);
                                                                    if (*lexer == SEMICOLON)
                                                                    {
                                                                        ++lexer;
                                                                        match.hit = true;
                                                                    }
                                                                    if (match.hit)
                                                                    {
                                                                        *parentMatch31 = match;
                                                                    }
                                                                    else
                                                                    {
                                                                        lexer.SetPos(save);
                                                                    }
                                                                }
                                                                *parentMatch30 = match;
                                                            }
                                                            *parentMatch29 = match;
                                                        }
                                                        *parentMatch28 = match;
                                                    }
                                                    if (match.hit)
                                                    {
                                                        {
                                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberDeclaration"));
                                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                            return soulng::parser::Match(true, functionDefinition.release());
                                                        }
                                                    }
                                                    *parentMatch27 = match;
                                                }
                                                *parentMatch26 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                    }
                                    *parentMatch7 = match;
                                    if (!match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch32 = &match;
                                        lexer.SetPos(save);
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch33 = &match;
                                            {
                                                int64_t pos = lexer.GetPos();
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch34 = &match;
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch35 = &match;
                                                    {
                                                        soulng::parser::Match match = ClassParser::SpecialMemberFunctionDefinition(lexer, ctx);
                                                        specialMemberFunctionDefition.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                        *parentMatch35 = match;
                                                    }
                                                    if (match.hit)
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch36 = &match;
                                                        {
                                                            soulng::parser::Match match(true);
                                                            int64_t save = lexer.GetPos();
                                                            soulng::parser::Match* parentMatch37 = &match;
                                                            {
                                                                soulng::parser::Match match(false);
                                                                if (*lexer == SEMICOLON)
                                                                {
                                                                    ++lexer;
                                                                    match.hit = true;
                                                                }
                                                                if (match.hit)
                                                                {
                                                                    *parentMatch37 = match;
                                                                }
                                                                else
                                                                {
                                                                    lexer.SetPos(save);
                                                                }
                                                            }
                                                            *parentMatch36 = match;
                                                        }
                                                        *parentMatch35 = match;
                                                    }
                                                    *parentMatch34 = match;
                                                }
                                                if (match.hit)
                                                {
                                                    {
                                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberDeclaration"));
                                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                        return soulng::parser::Match(true, specialMemberFunctionDefition.release());
                                                    }
                                                }
                                                *parentMatch33 = match;
                                            }
                                            *parentMatch32 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                }
                                *parentMatch6 = match;
                                if (!match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch38 = &match;
                                    lexer.SetPos(save);
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch39 = &match;
                                        {
                                            int64_t pos = lexer.GetPos();
                                            soulng::parser::Match match = DeclarationParser::UsingDeclaration(lexer, ctx);
                                            usingDeclaration.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                            if (match.hit)
                                            {
                                                {
                                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberDeclaration"));
                                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                    return soulng::parser::Match(true, usingDeclaration.release());
                                                }
                                            }
                                            *parentMatch39 = match;
                                        }
                                        *parentMatch38 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                            }
                            *parentMatch5 = match;
                            if (!match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch40 = &match;
                                lexer.SetPos(save);
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch41 = &match;
                                    {
                                        int64_t pos = lexer.GetPos();
                                        soulng::parser::Match match = DeclarationParser::TypedefDeclaration(lexer, ctx);
                                        typedefDeclaration.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                        if (match.hit)
                                        {
                                            {
                                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberDeclaration"));
                                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                                return soulng::parser::Match(true, typedefDeclaration.release());
                                            }
                                        }
                                        *parentMatch41 = match;
                                    }
                                    *parentMatch40 = match;
                                }
                                *parentMatch5 = match;
                            }
                        }
                        *parentMatch4 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch42 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch43 = &match;
                                {
                                    int64_t pos = lexer.GetPos();
                                    soulng::parser::Match match = TemplateParser::TemplateDeclaration(lexer, ctx);
                                    templateDeclaration.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                    if (match.hit)
                                    {
                                        {
                                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberDeclaration"));
                                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                            return soulng::parser::Match(true, templateDeclaration.release());
                                        }
                                    }
                                    *parentMatch43 = match;
                                }
                                *parentMatch42 = match;
                            }
                            *parentMatch4 = match;
                        }
                    }
                    *parentMatch3 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch44 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch45 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::parser::Match match = ClassParser::ClassDeclaration(lexer, ctx);
                                classDeclaration.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                if (match.hit)
                                {
                                    {
                                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberDeclaration"));
                                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                        return soulng::parser::Match(true, classDeclaration.release());
                                    }
                                }
                                *parentMatch45 = match;
                            }
                            *parentMatch44 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch46 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch47 = &match;
                        {
                            int64_t pos = lexer.GetPos();
                            soulng::parser::Match match = EnumerationParser::EnumDeclaration(lexer, ctx);
                            enumDeclaration.reset(static_cast<sngcpp::ast::Node*>(match.value));
                            if (match.hit)
                            {
                                {
                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberDeclaration"));
                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                    return soulng::parser::Match(true, enumDeclaration.release());
                                }
                            }
                            *parentMatch47 = match;
                        }
                        *parentMatch46 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch48 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch49 = &match;
                    {
                        int64_t pos = lexer.GetPos();
                        soulng::parser::Match match = DeclarationParser::AliasDeclaration(lexer, ctx);
                        aliasDeclaration.reset(static_cast<sngcpp::ast::Node*>(match.value));
                        if (match.hit)
                        {
                            {
                                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberDeclaration"));
                                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                return soulng::parser::Match(true, aliasDeclaration.release());
                            }
                        }
                        *parentMatch49 = match;
                    }
                    *parentMatch48 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch50 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch51 = &match;
                {
                    int64_t pos = lexer.GetPos();
                    soulng::parser::Match match = ClassParser::ForwardClassDeclaration(lexer, ctx);
                    forwardClassDeclaration.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        {
                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberDeclaration"));
                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                            return soulng::parser::Match(true, forwardClassDeclaration.release());
                        }
                    }
                    *parentMatch51 = match;
                }
                *parentMatch50 = match;
            }
            *parentMatch0 = match;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberDeclaration"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("MemberDeclaration"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::SpecialMemberFunctionDeclaration(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("SpecialMemberFunctionDeclaration"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> declarator = std::unique_ptr<sngcpp::ast::Node>();
    Span s = Span();
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Specifier>> declSpecifiers;
    std::unique_ptr<sngcpp::ast::Node> d;
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Specifier>> virtPureSpecifiers;
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
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = DeclarationParser::DeclSpecifiers(lexer);
                    declSpecifiers.reset(static_cast<soulng::parser::Value<sngcpp::ast::Specifier>*>(match.value));
                    if (match.hit)
                    {
                        s = span;
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
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        int64_t pos = lexer.GetPos();
                        bool pass = true;
                        soulng::parser::Match match = DeclaratorParser::Declarator(lexer, ctx);
                        d.reset(static_cast<sngcpp::ast::Node*>(match.value));
                        if (match.hit)
                        {
                            declarator.reset(d.release());
                            pass = sngcpp::ast::IsFunctionDeclarator(declarator.get());
                        }
                        if (match.hit && !pass)
                        {
                            match = soulng::parser::Match(false);
                        }
                        *parentMatch5 = match;
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch6 = &match;
            {
                soulng::parser::Match match = ClassParser::VirtPureSpecifiers(lexer, true);
                virtPureSpecifiers.reset(static_cast<soulng::parser::Value<sngcpp::ast::Specifier>*>(match.value));
                *parentMatch6 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
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
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                if (*lexer == SEMICOLON)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    s.end = span.end;
                    {
                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SpecialMemberFunctionDeclaration"));
                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                        return soulng::parser::Match(true, new sngcpp::ast::MemberDeclarationNode(s, declSpecifiers->value | virtPureSpecifiers->value, nullptr, declarator.release(), nullptr));
                    }
                }
                *parentMatch8 = match;
            }
            *parentMatch7 = match;
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SpecialMemberFunctionDeclaration"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("SpecialMemberFunctionDeclaration"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::ClassHead(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ClassHead"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    Span s = Span();
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::ClassKey>> classKey;
    std::unique_ptr<sngcpp::ast::Node> className;
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Specifier>> classVirtSpecifiers;
    std::unique_ptr<sngcpp::ast::Node> baseClause;
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
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match = ClassParser::ClassKey(lexer);
                            classKey.reset(static_cast<soulng::parser::Value<sngcpp::ast::ClassKey>*>(match.value));
                            if (match.hit)
                            {
                                s = span;
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
                            soulng::parser::Match match = ClassParser::ClassName(lexer, ctx);
                            className.reset(static_cast<sngcpp::ast::Node*>(match.value));
                            *parentMatch6 = match;
                        }
                        *parentMatch4 = match;
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
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match = ClassParser::ClassVirtSpecifiers(lexer);
                            classVirtSpecifiers.reset(static_cast<soulng::parser::Value<sngcpp::ast::Specifier>*>(match.value));
                            if (match.hit)
                            {
                                s.end = span.end;
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
                    soulng::parser::Match match(true);
                    int64_t save = lexer.GetPos();
                    soulng::parser::Match* parentMatch10 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch11 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch12 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match = ClassParser::BaseClause(lexer, ctx);
                                baseClause.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                if (match.hit)
                                {
                                    s.end = span.end;
                                }
                                *parentMatch12 = match;
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
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ClassHead"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new sngcpp::ast::ClassNode(s, classKey->value, className.release(), classVirtSpecifiers->value, baseClause.release()));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ClassHead"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ClassHead"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::ForwardClassDeclaration(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ForwardClassDeclaration"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    Span s = Span();
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::ClassKey>> classKey;
    std::unique_ptr<sngcpp::ast::Node> className;
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
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ClassParser::ClassKey(lexer);
                classKey.reset(static_cast<soulng::parser::Value<sngcpp::ast::ClassKey>*>(match.value));
                if (match.hit)
                {
                    s = span;
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
                soulng::parser::Match match = ClassParser::ClassName(lexer, ctx);
                className.reset(static_cast<sngcpp::ast::Node*>(match.value));
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch4 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            {
                int64_t pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                if (*lexer == SEMICOLON)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    s.end = span.end;
                    {
                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ForwardClassDeclaration"));
                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                        return soulng::parser::Match(true, new sngcpp::ast::ForwardClassDeclarationNode(s, classKey->value, className.release()));
                    }
                }
                *parentMatch5 = match;
            }
            *parentMatch4 = match;
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ForwardClassDeclaration"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ForwardClassDeclaration"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::ClassKey(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ClassKey"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    int64_t pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case CLASS:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ClassKey"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::ClassKey>(sngcpp::ast::ClassKey::class_));
                }
            }
            break;
        }
        case STRUCT:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ClassKey"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::ClassKey>(sngcpp::ast::ClassKey::struct_));
                }
            }
            break;
        }
        case UNION:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ClassKey"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::ClassKey>(sngcpp::ast::ClassKey::union_));
                }
            }
            break;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ClassKey"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ClassKey"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::ClassName(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ClassName"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> className;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match = IdentifierParser::QualifiedIdNode(lexer, ctx);
        className.reset(static_cast<sngcpp::ast::Node*>(match.value));
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ClassName"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, className.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ClassName"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ClassName"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::ClassVirtSpecifiers(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ClassVirtSpecifiers"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    sngcpp::ast::Specifier specifiers = sngcpp::ast::Specifier();
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Specifier>> specifier;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(true);
            soulng::parser::Match* parentMatch2 = &match;
            {
                while (true)
                {
                    int64_t save = lexer.GetPos();
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch3 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch4 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::parser::Match match = ClassParser::ClassVirtSpecifier(lexer);
                                specifier.reset(static_cast<soulng::parser::Value<sngcpp::ast::Specifier>*>(match.value));
                                if (match.hit)
                                {
                                    specifiers = specifiers | specifier->value;
                                }
                                *parentMatch4 = match;
                            }
                            *parentMatch3 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch2 = match;
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
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ClassVirtSpecifiers"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Specifier>(specifiers));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ClassVirtSpecifiers"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ClassVirtSpecifiers"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::ClassVirtSpecifier(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("ClassVirtSpecifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    int64_t pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case FINAL:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ClassVirtSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Specifier>(sngcpp::ast::Specifier::final_));
                }
            }
            break;
        }
        case EXPLICIT:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ClassVirtSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Specifier>(sngcpp::ast::Specifier::explicit_));
                }
            }
            break;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("ClassVirtSpecifier"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("ClassVirtSpecifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::BaseClause(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("BaseClause"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> bc;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        if (*lexer == COLON)
        {
            ++lexer;
            match.hit = true;
        }
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
                int64_t pos = lexer.GetPos();
                soulng::parser::Match match = ClassParser::BaseClassSpecifierList(lexer, ctx);
                bc.reset(static_cast<sngcpp::ast::Node*>(match.value));
                if (match.hit)
                {
                    {
                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("BaseClause"));
                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                        return soulng::parser::Match(true, bc.release());
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
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("BaseClause"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("BaseClause"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::BaseClassSpecifierList(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("BaseClassSpecifierList"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> node = std::unique_ptr<sngcpp::ast::Node>();
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> b1;
    std::unique_ptr<sngcpp::ast::Node> b2;
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
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = ClassParser::BaseClassSpecifier(lexer, ctx);
                    b1.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        s = span;
                        node.reset(b1.release());
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
                                        if (*lexer == COMMA)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        *parentMatch7 = match;
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
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                soulng::parser::Match match = ClassParser::BaseClassSpecifier(lexer, ctx);
                                                b2.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    s.end = span.end;
                                                    node.reset(new sngcpp::ast::BaseClassSpecifierSequenceNode(s, node.release(), b2.release()));
                                                }
                                                *parentMatch9 = match;
                                            }
                                            *parentMatch8 = match;
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
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("BaseClassSpecifierList"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, node.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("BaseClassSpecifierList"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("BaseClassSpecifierList"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::BaseClassSpecifier(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("BaseClassSpecifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    Span s = Span();
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Specifier>> baseSpecifiers;
    std::unique_ptr<sngcpp::ast::Node> className;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int64_t pos = lexer.GetPos();
            soulng::lexer::Span span = lexer.GetSpan();
            soulng::parser::Match match = ClassParser::BaseSpecifiers(lexer);
            baseSpecifiers.reset(static_cast<soulng::parser::Value<sngcpp::ast::Specifier>*>(match.value));
            if (match.hit)
            {
                s = span;
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
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ClassParser::ClassName(lexer, ctx);
                className.reset(static_cast<sngcpp::ast::Node*>(match.value));
                if (match.hit)
                {
                    s.end = span.end;
                    {
                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("BaseClassSpecifier"));
                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                        return soulng::parser::Match(true, new sngcpp::ast::BaseClassSpecifierNode(s, baseSpecifiers->value, className.release()));
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
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("BaseClassSpecifier"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("BaseClassSpecifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::BaseSpecifiers(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("BaseSpecifiers"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    sngcpp::ast::Specifier specifiers = sngcpp::ast::Specifier();
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Specifier>> specifier;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(true);
            soulng::parser::Match* parentMatch2 = &match;
            {
                while (true)
                {
                    int64_t save = lexer.GetPos();
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch3 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch4 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::parser::Match match = ClassParser::BaseSpecifier(lexer);
                                specifier.reset(static_cast<soulng::parser::Value<sngcpp::ast::Specifier>*>(match.value));
                                if (match.hit)
                                {
                                    specifiers = specifiers | specifier->value;
                                }
                                *parentMatch4 = match;
                            }
                            *parentMatch3 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch2 = match;
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
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("BaseSpecifiers"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Specifier>(specifiers));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("BaseSpecifiers"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("BaseSpecifiers"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::BaseSpecifier(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("BaseSpecifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Specifier>> accessSpecifier;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int64_t pos = lexer.GetPos();
            soulng::parser::Match match(false);
            if (*lexer == VIRTUAL)
            {
                ++lexer;
                match.hit = true;
            }
            if (match.hit)
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("BaseSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Specifier>(sngcpp::ast::Specifier::virtual_));
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
                    int64_t pos = lexer.GetPos();
                    soulng::parser::Match match = ClassParser::AccessSpecifier(lexer);
                    accessSpecifier.reset(static_cast<soulng::parser::Value<sngcpp::ast::Specifier>*>(match.value));
                    if (match.hit)
                    {
                        {
                            #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                            if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("BaseSpecifier"));
                            #endif // SOULNG_PARSER_DEBUG_SUPPORT
                            return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Specifier>(accessSpecifier->value));
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
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("BaseSpecifier"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("BaseSpecifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::AccessSpecifier(CppLexer& lexer)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("AccessSpecifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    soulng::parser::Match match(false);
    int64_t pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case PUBLIC:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AccessSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Specifier>(sngcpp::ast::Specifier::public_));
                }
            }
            break;
        }
        case PROTECTED:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AccessSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Specifier>(sngcpp::ast::Specifier::protected_));
                }
            }
            break;
        }
        case PRIVATE:
        {
            ++lexer;
            {
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AccessSpecifier"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Specifier>(sngcpp::ast::Specifier::private_));
                }
            }
            break;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("AccessSpecifier"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("AccessSpecifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::VirtPureSpecifiers(CppLexer& lexer, bool functionMember)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("VirtPureSpecifiers"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    sngcpp::ast::Specifier specifiers = sngcpp::ast::Specifier();
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Specifier>> virtSpecifier;
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Specifier>> pureSpecifier;
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
                                    int64_t pos = lexer.GetPos();
                                    soulng::parser::Match match = ClassParser::VirtSpecifier(lexer, functionMember);
                                    virtSpecifier.reset(static_cast<soulng::parser::Value<sngcpp::ast::Specifier>*>(match.value));
                                    if (match.hit)
                                    {
                                        specifiers = specifiers | virtSpecifier->value;
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
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                {
                    soulng::parser::Match match(true);
                    int64_t save = lexer.GetPos();
                    soulng::parser::Match* parentMatch7 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch8 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch9 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                soulng::parser::Match match = ClassParser::PureSpecifier(lexer, functionMember);
                                pureSpecifier.reset(static_cast<soulng::parser::Value<sngcpp::ast::Specifier>*>(match.value));
                                if (match.hit)
                                {
                                    specifiers = specifiers | pureSpecifier->value;
                                }
                                *parentMatch9 = match;
                            }
                            *parentMatch8 = match;
                        }
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
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("VirtPureSpecifiers"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Specifier>(specifiers));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("VirtPureSpecifiers"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("VirtPureSpecifiers"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::VirtSpecifier(CppLexer& lexer, bool functionMember)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("VirtSpecifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    sngcpp::ast::Specifier specifier = sngcpp::ast::Specifier();
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
                int64_t save = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int64_t save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int64_t pos = lexer.GetPos();
                        bool pass = true;
                        soulng::parser::Match match(false);
                        if (*lexer == OVERRIDE)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (match.hit)
                        {
                            pass = functionMember;
                            specifier = sngcpp::ast::Specifier::override_;
                        }
                        if (match.hit && !pass)
                        {
                            match = soulng::parser::Match(false);
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                int64_t pos = lexer.GetPos();
                                bool pass = true;
                                soulng::parser::Match match(false);
                                if (*lexer == FINAL)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    pass = functionMember;
                                    specifier = sngcpp::ast::Specifier::final_;
                                }
                                if (match.hit && !pass)
                                {
                                    match = soulng::parser::Match(false);
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
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
                            bool pass = true;
                            soulng::parser::Match match(false);
                            if (*lexer == NEW)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                pass = functionMember;
                                specifier = sngcpp::ast::Specifier::new_;
                            }
                            if (match.hit && !pass)
                            {
                                match = soulng::parser::Match(false);
                            }
                            *parentMatch8 = match;
                        }
                        *parentMatch7 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("VirtSpecifier"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Specifier>(specifier));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("VirtSpecifier"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("VirtSpecifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::PureSpecifier(CppLexer& lexer, bool functionMember)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("PureSpecifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::IntegerLiteralNode> integerLiteral;
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
                if (*lexer == ASSIGN)
                {
                    ++lexer;
                    match.hit = true;
                }
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
                        bool pass = true;
                        soulng::parser::Match match = LiteralParser::IntegerLiteral(lexer);
                        integerLiteral.reset(static_cast<sngcpp::ast::IntegerLiteralNode*>(match.value));
                        if (match.hit)
                        {
                            pass = functionMember && integerLiteral.release()->Value() == 0;
                        }
                        if (match.hit && !pass)
                        {
                            match = soulng::parser::Match(false);
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
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("PureSpecifier"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, new soulng::parser::Value<sngcpp::ast::Specifier>(sngcpp::ast::Specifier::pure_));
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("PureSpecifier"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("PureSpecifier"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::SpecialMemberFunctionDefinition(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("SpecialMemberFunctionDefinition"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> declarator = std::unique_ptr<sngcpp::ast::Node>();
    sngcpp::ast::Specifier defaultOrDeleteSpecifier = sngcpp::ast::Specifier();
    Span s = Span();
    std::unique_ptr<soulng::parser::Value<sngcpp::ast::Specifier>> declSpecifiers;
    std::unique_ptr<sngcpp::ast::Node> d;
    std::unique_ptr<sngcpp::ast::Node> ctorInitializer;
    std::unique_ptr<sngcpp::ast::CompoundStatementNode> body;
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
                    int64_t pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = DeclarationParser::DeclSpecifiers(lexer);
                    declSpecifiers.reset(static_cast<soulng::parser::Value<sngcpp::ast::Specifier>*>(match.value));
                    if (match.hit)
                    {
                        s = span;
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
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        int64_t pos = lexer.GetPos();
                        bool pass = true;
                        soulng::parser::Match match = DeclaratorParser::Declarator(lexer, ctx);
                        d.reset(static_cast<sngcpp::ast::Node*>(match.value));
                        if (match.hit)
                        {
                            declarator.reset(d.release());
                            pass = sngcpp::ast::IsFunctionDeclarator(declarator.get());
                        }
                        if (match.hit && !pass)
                        {
                            match = soulng::parser::Match(false);
                        }
                        *parentMatch5 = match;
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
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
                    ctorInitializer.reset(static_cast<sngcpp::ast::Node*>(match.value));
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
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
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
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch10 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch11 = &match;
                    {
                        int64_t save = lexer.GetPos();
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch12 = &match;
                        {
                            int64_t pos = lexer.GetPos();
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match = FunctionParser::FunctionBody(lexer, ctx);
                            body.reset(static_cast<sngcpp::ast::CompoundStatementNode*>(match.value));
                            if (match.hit)
                            {
                                s.end = span.end;
                            }
                            *parentMatch12 = match;
                        }
                        *parentMatch11 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch13 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch14 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch15 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == ASSIGN)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        *parentMatch15 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch16 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch17 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch18 = &match;
                                                {
                                                    int64_t save = lexer.GetPos();
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch19 = &match;
                                                    {
                                                        int64_t pos = lexer.GetPos();
                                                        soulng::parser::Match match(false);
                                                        if (*lexer == DEFAULT)
                                                        {
                                                            ++lexer;
                                                            match.hit = true;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            defaultOrDeleteSpecifier = sngcpp::ast::Specifier::default_;
                                                        }
                                                        *parentMatch19 = match;
                                                    }
                                                    *parentMatch18 = match;
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
                                                                soulng::parser::Match match(false);
                                                                if (*lexer == DELETE)
                                                                {
                                                                    ++lexer;
                                                                    match.hit = true;
                                                                }
                                                                if (match.hit)
                                                                {
                                                                    defaultOrDeleteSpecifier = sngcpp::ast::Specifier::delete_;
                                                                }
                                                                *parentMatch21 = match;
                                                            }
                                                            *parentMatch20 = match;
                                                        }
                                                        *parentMatch18 = match;
                                                    }
                                                }
                                                *parentMatch17 = match;
                                            }
                                            *parentMatch16 = match;
                                        }
                                        *parentMatch15 = match;
                                    }
                                    *parentMatch14 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch22 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch23 = &match;
                                        {
                                            int64_t pos = lexer.GetPos();
                                            soulng::lexer::Span span = lexer.GetSpan();
                                            soulng::parser::Match match(false);
                                            if (*lexer == SEMICOLON)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            if (match.hit)
                                            {
                                                s.end = span.end;
                                            }
                                            *parentMatch23 = match;
                                        }
                                        *parentMatch22 = match;
                                    }
                                    *parentMatch14 = match;
                                }
                                *parentMatch13 = match;
                            }
                            *parentMatch11 = match;
                        }
                    }
                    *parentMatch10 = match;
                }
                if (match.hit)
                {
                    {
                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SpecialMemberFunctionDefinition"));
                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                        return soulng::parser::Match(true, new sngcpp::ast::SpecialMemberFunctionNode(s, declSpecifiers->value | defaultOrDeleteSpecifier, declarator.release(), ctorInitializer.release(), body.release()));
                    }
                }
                *parentMatch9 = match;
            }
            *parentMatch8 = match;
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("SpecialMemberFunctionDefinition"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("SpecialMemberFunctionDefinition"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::CtorInitializer(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("CtorInitializer"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    Span s = Span();
    std::unique_ptr<sngcpp::ast::Node> mil;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int64_t pos = lexer.GetPos();
            soulng::lexer::Span span = lexer.GetSpan();
            soulng::parser::Match match(false);
            if (*lexer == COLON)
            {
                ++lexer;
                match.hit = true;
            }
            if (match.hit)
            {
                s = span;
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
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ClassParser::MemberInitializerList(lexer, ctx);
                mil.reset(static_cast<sngcpp::ast::Node*>(match.value));
                if (match.hit)
                {
                    s.end = span.end;
                    {
                        #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                        if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("CtorInitializer"));
                        #endif // SOULNG_PARSER_DEBUG_SUPPORT
                        return soulng::parser::Match(true, new sngcpp::ast::CtorInitializerNode(s, mil.release()));
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
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("CtorInitializer"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("CtorInitializer"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::MemberInitializerList(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("MemberInitializerList"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> list = std::unique_ptr<sngcpp::ast::Node>();
    std::unique_ptr<sngcpp::ast::Node> left;
    std::unique_ptr<sngcpp::ast::Node> right;
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
                    soulng::parser::Match match = ClassParser::MemberInitializer(lexer, ctx);
                    left.reset(static_cast<sngcpp::ast::Node*>(match.value));
                    if (match.hit)
                    {
                        list.reset(left.release());
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
                                        if (*lexer == COMMA)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        *parentMatch7 = match;
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
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                soulng::parser::Match match = ClassParser::MemberInitializer(lexer, ctx);
                                                right.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    list.reset(new sngcpp::ast::MemberInitializerSequenceNode(span, list.release(), right.release()));
                                                }
                                                *parentMatch9 = match;
                                            }
                                            *parentMatch8 = match;
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
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberInitializerList"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, list.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberInitializerList"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("MemberInitializerList"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::MemberInitializer(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("MemberInitializer"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    Span s = Span();
    Span argsSpan = Span();
    std::unique_ptr<sngcpp::ast::Node> id1;
    std::unique_ptr<sngcpp::ast::Node> args;
    std::unique_ptr<sngcpp::ast::Node> id2;
    std::unique_ptr<sngcpp::ast::Node> bi;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int64_t pos = lexer.GetPos();
            soulng::lexer::Span span = lexer.GetSpan();
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
                                int64_t pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match = ClassParser::MemberInitializerId(lexer, ctx);
                                id1.reset(static_cast<sngcpp::ast::Node*>(match.value));
                                if (match.hit)
                                {
                                    s = span;
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
                                    soulng::lexer::Span span = lexer.GetSpan();
                                    soulng::parser::Match match(false);
                                    if (*lexer == LPAREN)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        argsSpan = span;
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
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch9 = &match;
                        {
                            soulng::parser::Match match = ExpressionParser::ArgumentList(lexer, ctx);
                            args.reset(static_cast<sngcpp::ast::Node*>(match.value));
                            *parentMatch9 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch10 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch11 = &match;
                        {
                            int64_t pos = lexer.GetPos();
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match(false);
                            if (*lexer == RPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                argsSpan.end = span.end;
                            }
                            *parentMatch11 = match;
                        }
                        *parentMatch10 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                s.end = span.end;
                {
                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberInitializer"));
                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                    return soulng::parser::Match(true, new sngcpp::ast::MemberInitializerNode(s, id1.release(), new sngcpp::ast::ExpressionListInitializerNode(argsSpan, args.release())));
                }
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch12 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch13 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch14 = &match;
                    {
                        int64_t pos = lexer.GetPos();
                        soulng::lexer::Span span = lexer.GetSpan();
                        soulng::parser::Match match = ClassParser::MemberInitializerId(lexer, ctx);
                        id2.reset(static_cast<sngcpp::ast::Node*>(match.value));
                        if (match.hit)
                        {
                            s = span;
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
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match = DeclaratorParser::BracedInitializerList(lexer, ctx);
                            bi.reset(static_cast<sngcpp::ast::Node*>(match.value));
                            if (match.hit)
                            {
                                s.end = span.end;
                                {
                                    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                                    if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberInitializer"));
                                    #endif // SOULNG_PARSER_DEBUG_SUPPORT
                                    return soulng::parser::Match(true, new sngcpp::ast::MemberInitializerNode(s, id2.release(), bi.release()));
                                }
                            }
                            *parentMatch16 = match;
                        }
                        *parentMatch15 = match;
                    }
                    *parentMatch13 = match;
                }
                *parentMatch12 = match;
            }
            *parentMatch0 = match;
        }
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberInitializer"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("MemberInitializer"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}

soulng::parser::Match ClassParser::MemberInitializerId(CppLexer& lexer, sngcpp::cppparser::ParsingContext* ctx)
{
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    soulng::lexer::Span parser_debug_match_span;
    bool parser_debug_write_to_log = lexer.Log() != nullptr;
    if (parser_debug_write_to_log)
    {
        parser_debug_match_span = lexer.GetSpan();
        soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32("MemberInitializerId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    std::unique_ptr<sngcpp::ast::Node> qid;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int64_t pos = lexer.GetPos();
        soulng::parser::Match match = IdentifierParser::QualifiedIdNode(lexer, ctx);
        qid.reset(static_cast<sngcpp::ast::Node*>(match.value));
        if (match.hit)
        {
            {
                #ifdef SOULNG_PARSER_DEBUG_SUPPORT
                if (parser_debug_write_to_log) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberInitializerId"));
                #endif // SOULNG_PARSER_DEBUG_SUPPORT
                return soulng::parser::Match(true, qid.release());
            }
        }
        *parentMatch0 = match;
    }
    #ifdef SOULNG_PARSER_DEBUG_SUPPORT
    if (parser_debug_write_to_log)
    {
        if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32("MemberInitializerId"));
        else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32("MemberInitializerId"));
    }
    #endif // SOULNG_PARSER_DEBUG_SUPPORT
    return match;
}
