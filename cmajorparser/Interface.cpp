#include "Interface.hpp"
#include <soulng/util/Unicode.hpp>
#include <cmajorparser/Attribute.hpp>
#include <cmajorparser/Specifier.hpp>
#include <cmajorparser/Identifier.hpp>
#include <cmajorparser/TypeExpr.hpp>
#include <cmajorparser/Parameter.hpp>
#include <soulng/cmajorlexer/CmajorLexer.hpp>
#include <soulng/cmajorlexer/CmajorTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng/cmajorparser/Interface.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace cmajor::ast;
using namespace CmajorTokens;

soulng::parser::Match InterfaceParser::Interface(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<InterfaceNode> intf = std::unique_ptr<InterfaceNode>();
    Span s = Span();
    Span specifierSpan = Span();
    Span beginBraceSpan = Span();
    Span endBraceSpan = Span();
    std::unique_ptr<cmajor::ast::Attributes> attrs;
    std::unique_ptr<soulng::parser::Value<cmajor::ast::Specifiers>> specifiers;
    std::unique_ptr<IdentifierNode> id;
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
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        Span span = lexer.GetSpan();
                                        soulng::parser::Match match(true);
                                        if (match.hit)
                                        {
                                            s = span;
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
                                        soulng::parser::Match match(true);
                                        int save = lexer.GetPos();
                                        soulng::parser::Match* parentMatch10 = &match;
                                        {
                                            soulng::parser::Match match = AttributeParser::Attributes(lexer);
                                            attrs.reset(static_cast<cmajor::ast::Attributes*>(match.value));
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
                                    *parentMatch7 = match;
                                }
                                *parentMatch6 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch11 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch12 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        Span span = lexer.GetSpan();
                                        soulng::parser::Match match = SpecifierParser::Specifiers(lexer);
                                        specifiers.reset(static_cast<soulng::parser::Value<cmajor::ast::Specifiers>*>(match.value));
                                        if (match.hit)
                                        {
                                            specifierSpan = span;
                                        }
                                        *parentMatch12 = match;
                                    }
                                    *parentMatch11 = match;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch13 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == INTERFACE)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch13 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch14 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch15 = &match;
                            {
                                int pos = lexer.GetPos();
                                Span span = lexer.GetSpan();
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                    id.reset(static_cast<IdentifierNode*>(match.value));
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, U"identifier");
                                    }
                                }
                                if (match.hit)
                                {
                                    s.end = span.end;
                                    intf.reset(new InterfaceNode(s, specifiers->value, id.release(), attrs.release()));
                                    intf->SetSpecifierSpan(specifierSpan);
                                }
                                *parentMatch15 = match;
                            }
                            *parentMatch14 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
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
                            Span span = lexer.GetSpan();
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == LBRACE)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LBRACE)));
                                }
                            }
                            if (match.hit)
                            {
                                beginBraceSpan = span;
                            }
                            *parentMatch17 = match;
                        }
                        *parentMatch16 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch18 = &match;
                {
                    soulng::parser::Match match = InterfaceParser::InterfaceContent(lexer, ctx, intf.get());
                    *parentMatch18 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch19 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch20 = &match;
                {
                    int pos = lexer.GetPos();
                    Span span = lexer.GetSpan();
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == RBRACE)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RBRACE)));
                        }
                    }
                    if (match.hit)
                    {
                        endBraceSpan = span;
                        intf->SetBeginBraceSpan(beginBraceSpan);
                        intf->SetEndBraceSpan(endBraceSpan);
                    }
                    *parentMatch20 = match;
                }
                *parentMatch19 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, intf.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match InterfaceParser::InterfaceContent(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::InterfaceNode* intf)
{
    std::unique_ptr<Node> intfMemFun;
    soulng::parser::Match match(true);
    soulng::parser::Match* parentMatch0 = &match;
    {
        while (true)
        {
            int save = lexer.GetPos();
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch1 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = InterfaceParser::InterfaceMemFun(lexer, ctx);
                    intfMemFun.reset(static_cast<Node*>(match.value));
                    if (match.hit)
                    {
                        intf->AddMember(intfMemFun.release());
                    }
                    *parentMatch1 = match;
                }
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
    return match;
}

soulng::parser::Match InterfaceParser::InterfaceMemFun(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<MemberFunctionNode> memFun = std::unique_ptr<MemberFunctionNode>();
    Span s = Span();
    std::unique_ptr<cmajor::ast::Attributes> attrs;
    std::unique_ptr<Node> returnType;
    std::unique_ptr<soulng::parser::Value<std::u32string>> groupId;
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
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int pos = lexer.GetPos();
                            Span span = lexer.GetSpan();
                            soulng::parser::Match match(true);
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
                            soulng::parser::Match match(true);
                            int save = lexer.GetPos();
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                soulng::parser::Match match = AttributeParser::Attributes(lexer);
                                attrs.reset(static_cast<cmajor::ast::Attributes*>(match.value));
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
                        soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                        returnType.reset(static_cast<Node*>(match.value));
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
                        int pos = lexer.GetPos();
                        Span span = lexer.GetSpan();
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = InterfaceParser::InterfaceFunctionGroupId(lexer);
                            groupId.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, U"interface function group identifier");
                            }
                        }
                        if (match.hit)
                        {
                            s.end = span.end;
                            memFun.reset(new MemberFunctionNode(s, Specifiers(), returnType.release(), groupId->value, attrs.release()));
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
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch11 = &match;
            {
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ParameterParser::ParameterList(lexer, ctx, memFun.get());
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, U"parameter list");
                    }
                }
                *parentMatch11 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch12 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch13 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, memFun.release());
                }
                *parentMatch13 = match;
            }
            *parentMatch12 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match InterfaceParser::InterfaceFunctionGroupId(CmajorLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        Span span = lexer.GetSpan();
        soulng::parser::Match match(false);
        if (*lexer == ID)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::parser::Value<std::u32string>(lexer.GetMatch(span)));
        }
        *parentMatch0 = match;
    }
    return match;
}
