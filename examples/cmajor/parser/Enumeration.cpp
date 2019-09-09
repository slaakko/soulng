#include "Enumeration.hpp"
#include <soulng/util/Unicode.hpp>
#include <cmajor/parser/Specifier.hpp>
#include <cmajor/parser/Identifier.hpp>
#include <cmajor/parser/TypeExpr.hpp>
#include <cmajor/parser/Expression.hpp>
#include <cmajor/lexer/CmajorLexer.hpp>
#include <cmajor/lexer/CmajorTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/Enumeration.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace cmajor::ast;
using namespace CmajorTokens;

soulng::parser::Match EnumerationParser::EnumType(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<EnumTypeNode> enumTypeNode = std::unique_ptr<EnumTypeNode>();
    Span s = Span();
    Span beginBraceSpan = Span();
    Span endBraceSpan = Span();
    std::unique_ptr<soulng::parser::Value<cmajor::ast::Specifiers>> specifiers;
    std::unique_ptr<IdentifierNode> enumTypeId;
    std::unique_ptr<Node> underlyingType;
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
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                int pos = lexer.GetPos();
                                Span span = lexer.GetSpan();
                                soulng::parser::Match match = SpecifierParser::Specifiers(lexer);
                                specifiers.reset(static_cast<soulng::parser::Value<cmajor::ast::Specifiers>*>(match.value));
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
                                if (*lexer == ENUM)
                                {
                                    ++lexer;
                                    match.hit = true;
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
                        soulng::parser::Match* parentMatch8 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch9 = &match;
                            {
                                int pos = lexer.GetPos();
                                Span span = lexer.GetSpan();
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                    enumTypeId.reset(static_cast<IdentifierNode*>(match.value));
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, U"identifier");
                                    }
                                }
                                if (match.hit)
                                {
                                    s.end = span.end;
                                    enumTypeNode.reset(new EnumTypeNode(s, specifiers->value, enumTypeId.release()));
                                }
                                *parentMatch9 = match;
                            }
                            *parentMatch8 = match;
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
                        soulng::parser::Match match(true);
                        int save = lexer.GetPos();
                        soulng::parser::Match* parentMatch11 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch12 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = EnumerationParser::UnderlyingType(lexer, ctx);
                                underlyingType.reset(static_cast<Node*>(match.value));
                                if (match.hit)
                                {
                                    enumTypeNode->SetUnderlyingType(underlyingType.release());
                                }
                                *parentMatch12 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch11 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                            }
                        }
                        *parentMatch10 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch13 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch14 = &match;
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
                        *parentMatch14 = match;
                    }
                    *parentMatch13 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch15 = &match;
            {
                soulng::parser::Match match = EnumerationParser::EnumConstants(lexer, ctx, enumTypeNode.get());
                *parentMatch15 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
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
                    enumTypeNode->SetBeginBraceSpan(beginBraceSpan);
                    enumTypeNode->SetEndBraceSpan(endBraceSpan);
                    return soulng::parser::Match(true, enumTypeNode.release());
                }
                *parentMatch17 = match;
            }
            *parentMatch16 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match EnumerationParser::UnderlyingType(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> type;
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
                int pos = lexer.GetPos();
                soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                type.reset(static_cast<Node*>(match.value));
                if (match.hit)
                {
                    return soulng::parser::Match(true, type.release());
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match EnumerationParser::EnumConstants(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::EnumTypeNode* enumType)
{
    std::unique_ptr<EnumConstantNode> enumConstant;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match(true);
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match = EnumerationParser::EnumConstant(lexer, ctx, enumType);
                enumConstant.reset(static_cast<EnumConstantNode*>(match.value));
                if (!match.hit)
                {
                    lexer.ThrowExpectationFailure(pos, U"enumeration constant");
                }
            }
            if (match.hit)
            {
                enumType->AddConstant(enumConstant.release());
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
                            if (*lexer == COMMA)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch4 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch5 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(true);
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match = EnumerationParser::EnumConstant(lexer, ctx, enumType);
                                        enumConstant.reset(static_cast<EnumConstantNode*>(match.value));
                                        if (!match.hit)
                                        {
                                            lexer.ThrowExpectationFailure(pos, U"enumeration constant");
                                        }
                                    }
                                    if (match.hit)
                                    {
                                        enumType->AddConstant(enumConstant.release());
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
    return match;
}

soulng::parser::Match EnumerationParser::EnumConstant(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::EnumTypeNode* enumType)
{
    Span s = Span();
    std::unique_ptr<IdentifierNode> constantId;
    std::unique_ptr<Node> constantValue;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            Span span = lexer.GetSpan();
            soulng::parser::Match match(true);
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                constantId.reset(static_cast<IdentifierNode*>(match.value));
                if (!match.hit)
                {
                    lexer.ThrowExpectationFailure(pos, U"identifier");
                }
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
                int save = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match(false);
                    if (*lexer == ASSIGN)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch4 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            int pos = lexer.GetPos();
                            Span span = lexer.GetSpan();
                            soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                            constantValue.reset(static_cast<Node*>(match.value));
                            if (match.hit)
                            {
                                s.end = span.end;
                                EnumConstantNode * value = new EnumConstantNode(s, constantId.release(), constantValue.release());
                                value->SetHasValue();
                                value->SetStrValue(lexer.GetMatch(s));
                                return soulng::parser::Match(true, value);
                            }
                            *parentMatch6 = match;
                        }
                        *parentMatch5 = match;
                    }
                    *parentMatch4 = match;
                }
                *parentMatch3 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch7 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch8 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(true);
                            if (match.hit)
                            {
                                return soulng::parser::Match(true, new EnumConstantNode(s, constantId.release(), MakeNextEnumConstantValue(s, enumType)));
                            }
                            *parentMatch8 = match;
                        }
                        *parentMatch7 = match;
                    }
                    *parentMatch3 = match;
                }
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}
