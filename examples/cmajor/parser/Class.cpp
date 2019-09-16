#include "Class.hpp"
#include <soulng/util/Unicode.hpp>
#include <cmajor/parser/Attribute.hpp>
#include <cmajor/parser/Specifier.hpp>
#include <cmajor/parser/Identifier.hpp>
#include <cmajor/parser/TypeExpr.hpp>
#include <cmajor/parser/Concept.hpp>
#include <cmajor/parser/Expression.hpp>
#include <cmajor/parser/Statement.hpp>
#include <cmajor/parser/Parameter.hpp>
#include <cmajor/parser/Function.hpp>
#include <cmajor/parser/Template.hpp>
#include <cmajor/parser/Typedef.hpp>
#include <cmajor/parser/Enumeration.hpp>
#include <cmajor/parser/Constant.hpp>
#include <cmajor/parser/Delegate.hpp>
#include <cmajor/lexer/CmajorLexer.hpp>
#include <cmajor/lexer/CmajorTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/Class.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace cmajor::ast;
using namespace CmajorTokens;

soulng::parser::Match ClassParser::Class(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<ClassNode> cls = std::unique_ptr<ClassNode>();
    Span s = Span();
    Span specifierSpan = Span();
    Span classSpan = Span();
    Span beginBraceSpan = Span();
    Span endBraceSpan = Span();
    std::unique_ptr<cmajor::ast::Attributes> attrs;
    std::unique_ptr<soulng::parser::Value<cmajor::ast::Specifiers>> specifiers;
    std::unique_ptr<IdentifierNode> id;
    std::unique_ptr<WhereConstraintNode> constraint;
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
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
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
                                                int pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                soulng::parser::Match match(true);
                                                if (match.hit)
                                                {
                                                    s = span;
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
                                                int save = lexer.GetPos();
                                                soulng::parser::Match* parentMatch12 = &match;
                                                {
                                                    soulng::parser::Match match = AttributeParser::Attributes(lexer);
                                                    attrs.reset(static_cast<cmajor::ast::Attributes*>(match.value));
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
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch14 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                soulng::parser::Match match = SpecifierParser::Specifiers(lexer);
                                                specifiers.reset(static_cast<soulng::parser::Value<cmajor::ast::Specifiers>*>(match.value));
                                                if (match.hit)
                                                {
                                                    specifierSpan = span;
                                                }
                                                *parentMatch14 = match;
                                            }
                                            *parentMatch13 = match;
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch15 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch16 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::lexer::Span span = lexer.GetSpan();
                                            soulng::parser::Match match(false);
                                            if (*lexer == CLASS)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            if (match.hit)
                                            {
                                                classSpan = span;
                                            }
                                            *parentMatch16 = match;
                                        }
                                        *parentMatch15 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch6 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch17 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch18 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                        id.reset(static_cast<IdentifierNode*>(match.value));
                                        if (match.hit)
                                        {
                                            s.end = span.end;
                                            cls.reset(new ClassNode(s, specifiers->value, id.release(), attrs.release()));
                                            cls->SetSpecifierSpan(specifierSpan);
                                            cls->SetClassSpan(classSpan);
                                        }
                                        *parentMatch18 = match;
                                    }
                                    *parentMatch17 = match;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch19 = &match;
                            {
                                soulng::parser::Match match(true);
                                int save = lexer.GetPos();
                                soulng::parser::Match* parentMatch20 = &match;
                                {
                                    soulng::parser::Match match = TemplateParser::TemplateParameterList(lexer, ctx, cls.get());
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
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch21 = &match;
                        {
                            soulng::parser::Match match(true);
                            int save = lexer.GetPos();
                            soulng::parser::Match* parentMatch22 = &match;
                            {
                                soulng::parser::Match match = ClassParser::InheritanceAndInterfaces(lexer, ctx, cls.get());
                                if (match.hit)
                                {
                                    *parentMatch22 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                }
                            }
                            *parentMatch21 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch23 = &match;
                    {
                        soulng::parser::Match match(true);
                        int save = lexer.GetPos();
                        soulng::parser::Match* parentMatch24 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch25 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = ConceptParser::WhereConstraint(lexer, ctx);
                                constraint.reset(static_cast<WhereConstraintNode*>(match.value));
                                if (match.hit)
                                {
                                    cls->SetConstraint(constraint.release());
                                }
                                *parentMatch25 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch24 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                            }
                        }
                        *parentMatch23 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch26 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch27 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::lexer::Span span = lexer.GetSpan();
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
                        *parentMatch27 = match;
                    }
                    *parentMatch26 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch28 = &match;
            {
                soulng::parser::Match match = ClassParser::ClassContent(lexer, ctx, cls.get());
                *parentMatch28 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch29 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch30 = &match;
            {
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
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
                    cls->SetBeginBraceSpan(beginBraceSpan);
                    cls->SetEndBraceSpan(endBraceSpan);
                    return soulng::parser::Match(true, cls.release());
                }
                *parentMatch30 = match;
            }
            *parentMatch29 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ClassParser::InheritanceAndInterfaces(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::ClassNode* classNode)
{
    std::unique_ptr<Node> baseOrIntf;
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
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(true);
                        if (match.hit)
                        {
                            ctx->BeginParsingTypeExpr();
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
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = ClassParser::BaseClassOrInterface(lexer, ctx);
                            baseOrIntf.reset(static_cast<Node*>(match.value));
                            if (match.hit)
                            {
                                classNode->AddBaseClassOrInterface(baseOrIntf.release());
                                ctx->EndParsingTypeExpr();
                            }
                            else
                            {
                                ctx->EndParsingTypeExpr();
                            }
                            *parentMatch6 = match;
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
                soulng::parser::Match* parentMatch7 = &match;
                {
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch8 = &match;
                    {
                        while (true)
                        {
                            int save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch9 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    if (*lexer == COMMA)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    *parentMatch9 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch10 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch11 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch12 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match(true);
                                                if (match.hit)
                                                {
                                                    ctx->BeginParsingTypeExpr();
                                                }
                                                *parentMatch12 = match;
                                            }
                                            *parentMatch11 = match;
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
                                                    soulng::parser::Match match = ClassParser::BaseClassOrInterface(lexer, ctx);
                                                    baseOrIntf.reset(static_cast<Node*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        classNode->AddBaseClassOrInterface(baseOrIntf.release());
                                                        ctx->EndParsingTypeExpr();
                                                    }
                                                    else
                                                    {
                                                        ctx->EndParsingTypeExpr();
                                                    }
                                                    *parentMatch14 = match;
                                                }
                                                *parentMatch13 = match;
                                            }
                                            *parentMatch11 = match;
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
                                    break;
                                }
                            }
                        }
                    }
                    *parentMatch7 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ClassParser::BaseClassOrInterface(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> templateId;
    std::unique_ptr<IdentifierNode> qid;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match = TemplateParser::TemplateId(lexer, ctx);
            templateId.reset(static_cast<Node*>(match.value));
            if (match.hit)
            {
                return soulng::parser::Match(true, templateId.release());
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
                    soulng::parser::Match match = IdentifierParser::QualifiedId(lexer);
                    qid.reset(static_cast<IdentifierNode*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, qid.release());
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match ClassParser::ClassContent(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::ClassNode* classNode)
{
    std::unique_ptr<Node> classMember;
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
                    soulng::parser::Match match = ClassParser::ClassMember(lexer, ctx, classNode);
                    classMember.reset(static_cast<Node*>(match.value));
                    if (match.hit)
                    {
                        classNode->AddMember(classMember.release());
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

soulng::parser::Match ClassParser::ClassMember(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::ClassNode* classNode)
{
    std::unique_ptr<StaticConstructorNode> staticConstructor;
    std::unique_ptr<Node> constructor;
    std::unique_ptr<Node> destructor;
    std::unique_ptr<Node> memberFunction;
    std::unique_ptr<Node> conversionFunction;
    std::unique_ptr<MemberVariableNode> memberVariable;
    std::unique_ptr<TypedefNode> typedefinition;
    std::unique_ptr<ClassNode> cls;
    std::unique_ptr<EnumTypeNode> enumType;
    std::unique_ptr<ConstantNode> constant;
    std::unique_ptr<DelegateNode> delegate;
    std::unique_ptr<ClassDelegateNode> classDelegate;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int save = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int save = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int save = lexer.GetPos();
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int save = lexer.GetPos();
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                int save = lexer.GetPos();
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    int save = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int save = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            int save = lexer.GetPos();
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch10 = &match;
                                            {
                                                int save = lexer.GetPos();
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch11 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = ClassParser::StaticConstructor(lexer, ctx, classNode);
                                                    staticConstructor.reset(static_cast<StaticConstructorNode*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        return soulng::parser::Match(true, staticConstructor.release());
                                                    }
                                                    *parentMatch11 = match;
                                                }
                                                *parentMatch10 = match;
                                                if (!match.hit)
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch12 = &match;
                                                    lexer.SetPos(save);
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch13 = &match;
                                                        {
                                                            int pos = lexer.GetPos();
                                                            soulng::parser::Match match = ClassParser::Constructor(lexer, ctx, classNode);
                                                            constructor.reset(static_cast<Node*>(match.value));
                                                            if (match.hit)
                                                            {
                                                                return soulng::parser::Match(true, constructor.release());
                                                            }
                                                            *parentMatch13 = match;
                                                        }
                                                        *parentMatch12 = match;
                                                    }
                                                    *parentMatch10 = match;
                                                }
                                            }
                                            *parentMatch9 = match;
                                            if (!match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch14 = &match;
                                                lexer.SetPos(save);
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch15 = &match;
                                                    {
                                                        int pos = lexer.GetPos();
                                                        soulng::parser::Match match = ClassParser::Destructor(lexer, ctx, classNode);
                                                        destructor.reset(static_cast<Node*>(match.value));
                                                        if (match.hit)
                                                        {
                                                            return soulng::parser::Match(true, destructor.release());
                                                        }
                                                        *parentMatch15 = match;
                                                    }
                                                    *parentMatch14 = match;
                                                }
                                                *parentMatch9 = match;
                                            }
                                        }
                                        *parentMatch8 = match;
                                        if (!match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch16 = &match;
                                            lexer.SetPos(save);
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch17 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = ClassParser::MemberFunction(lexer, ctx);
                                                    memberFunction.reset(static_cast<Node*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        return soulng::parser::Match(true, memberFunction.release());
                                                    }
                                                    *parentMatch17 = match;
                                                }
                                                *parentMatch16 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                    }
                                    *parentMatch7 = match;
                                    if (!match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch18 = &match;
                                        lexer.SetPos(save);
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch19 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match = ClassParser::ConversionFunction(lexer, ctx);
                                                conversionFunction.reset(static_cast<Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    return soulng::parser::Match(true, conversionFunction.release());
                                                }
                                                *parentMatch19 = match;
                                            }
                                            *parentMatch18 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                }
                                *parentMatch6 = match;
                                if (!match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch20 = &match;
                                    lexer.SetPos(save);
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch21 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = ClassParser::MemberVariable(lexer, ctx);
                                            memberVariable.reset(static_cast<MemberVariableNode*>(match.value));
                                            if (match.hit)
                                            {
                                                return soulng::parser::Match(true, memberVariable.release());
                                            }
                                            *parentMatch21 = match;
                                        }
                                        *parentMatch20 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                            }
                            *parentMatch5 = match;
                            if (!match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch22 = &match;
                                lexer.SetPos(save);
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch23 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match = TypedefParser::Typedef(lexer, ctx);
                                        typedefinition.reset(static_cast<TypedefNode*>(match.value));
                                        if (match.hit)
                                        {
                                            return soulng::parser::Match(true, typedefinition.release());
                                        }
                                        *parentMatch23 = match;
                                    }
                                    *parentMatch22 = match;
                                }
                                *parentMatch5 = match;
                            }
                        }
                        *parentMatch4 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch24 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch25 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = ClassParser::Class(lexer, ctx);
                                    cls.reset(static_cast<ClassNode*>(match.value));
                                    if (match.hit)
                                    {
                                        return soulng::parser::Match(true, cls.release());
                                    }
                                    *parentMatch25 = match;
                                }
                                *parentMatch24 = match;
                            }
                            *parentMatch4 = match;
                        }
                    }
                    *parentMatch3 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch26 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch27 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = EnumerationParser::EnumType(lexer, ctx);
                                enumType.reset(static_cast<EnumTypeNode*>(match.value));
                                if (match.hit)
                                {
                                    return soulng::parser::Match(true, enumType.release());
                                }
                                *parentMatch27 = match;
                            }
                            *parentMatch26 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch28 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch29 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = ConstantParser::Constant(lexer, ctx);
                            constant.reset(static_cast<ConstantNode*>(match.value));
                            if (match.hit)
                            {
                                return soulng::parser::Match(true, constant.release());
                            }
                            *parentMatch29 = match;
                        }
                        *parentMatch28 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch30 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch31 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = DelegateParser::Delegate(lexer, ctx);
                        delegate.reset(static_cast<DelegateNode*>(match.value));
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, delegate.release());
                        }
                        *parentMatch31 = match;
                    }
                    *parentMatch30 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch32 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch33 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = DelegateParser::ClassDelegate(lexer, ctx);
                    classDelegate.reset(static_cast<ClassDelegateNode*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, classDelegate.release());
                    }
                    *parentMatch33 = match;
                }
                *parentMatch32 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match ClassParser::StaticConstructor(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::ClassNode* classNode)
{
    std::unique_ptr<StaticConstructorNode> staticConstructor = std::unique_ptr<StaticConstructorNode>();
    Span s = Span();
    Span specifierSpan = Span();
    std::u32string className = std::u32string();
    std::unique_ptr<cmajor::ast::Attributes> attrs;
    std::unique_ptr<soulng::parser::Value<cmajor::ast::Specifiers>> specifiers;
    std::unique_ptr<IdentifierNode> id;
    std::unique_ptr<InitializerNode> initializer;
    std::unique_ptr<WhereConstraintNode> constraint;
    std::unique_ptr<CompoundStatementNode> body;
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
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::lexer::Span span = lexer.GetSpan();
                                            soulng::parser::Match match(true);
                                            if (match.hit)
                                            {
                                                s = span;
                                            }
                                            *parentMatch9 = match;
                                        }
                                        *parentMatch8 = match;
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
                                                soulng::parser::Match match = AttributeParser::Attributes(lexer);
                                                attrs.reset(static_cast<cmajor::ast::Attributes*>(match.value));
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
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
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
                                            soulng::lexer::Span span = lexer.GetSpan();
                                            soulng::parser::Match match = SpecifierParser::Specifiers(lexer);
                                            specifiers.reset(static_cast<soulng::parser::Value<cmajor::ast::Specifiers>*>(match.value));
                                            if (match.hit)
                                            {
                                                specifierSpan = span;
                                            }
                                            *parentMatch13 = match;
                                        }
                                        *parentMatch12 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch6 = match;
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
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                        id.reset(static_cast<IdentifierNode*>(match.value));
                                        if (match.hit)
                                        {
                                            className = lexer.GetMatch(span);
                                        }
                                        *parentMatch15 = match;
                                    }
                                    *parentMatch14 = match;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch16 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == LPAREN)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch16 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch17 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch18 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                bool pass = true;
                                soulng::parser::Match match(false);
                                if (*lexer == RPAREN)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    s.end = span.end;
                                    if (className != classNode->Id()->Str()) pass = false;
                                    else if (!StaticConstructorSpecifiers(specifiers->value)) pass = false;
                                    else
                                    {
                                        staticConstructor.reset(new StaticConstructorNode(s, specifiers->value, attrs.release()));
                                        staticConstructor->SetClassId(id.release());
                                        staticConstructor->SetSpecifierSpan(specifierSpan);
                                    }
                                }
                                if (match.hit && !pass)
                                {
                                    match = soulng::parser::Match(false);
                                }
                                *parentMatch18 = match;
                            }
                            *parentMatch17 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch19 = &match;
                    {
                        soulng::parser::Match match(true);
                        int save = lexer.GetPos();
                        soulng::parser::Match* parentMatch20 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch21 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == COLON)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch21 = match;
                            }
                            if (match.hit)
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
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = ClassParser::Initializer(lexer, ctx);
                                            initializer.reset(static_cast<InitializerNode*>(match.value));
                                            if (match.hit)
                                            {
                                                staticConstructor->AddInitializer(initializer.release());
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
                                            soulng::parser::Match match(true);
                                            soulng::parser::Match* parentMatch26 = &match;
                                            {
                                                while (true)
                                                {
                                                    int save = lexer.GetPos();
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch27 = &match;
                                                        {
                                                            soulng::parser::Match match(false);
                                                            if (*lexer == COMMA)
                                                            {
                                                                ++lexer;
                                                                match.hit = true;
                                                            }
                                                            *parentMatch27 = match;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch28 = &match;
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch29 = &match;
                                                                {
                                                                    int pos = lexer.GetPos();
                                                                    soulng::parser::Match match = ClassParser::Initializer(lexer, ctx);
                                                                    initializer.reset(static_cast<InitializerNode*>(match.value));
                                                                    if (match.hit)
                                                                    {
                                                                        staticConstructor->AddInitializer(initializer.release());
                                                                    }
                                                                    *parentMatch29 = match;
                                                                }
                                                                *parentMatch28 = match;
                                                            }
                                                            *parentMatch27 = match;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            *parentMatch26 = match;
                                                        }
                                                        else
                                                        {
                                                            lexer.SetPos(save);
                                                            break;
                                                        }
                                                    }
                                                }
                                            }
                                            *parentMatch25 = match;
                                        }
                                        *parentMatch23 = match;
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
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch30 = &match;
                {
                    soulng::parser::Match match(true);
                    int save = lexer.GetPos();
                    soulng::parser::Match* parentMatch31 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch32 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = ConceptParser::WhereConstraint(lexer, ctx);
                            constraint.reset(static_cast<WhereConstraintNode*>(match.value));
                            if (match.hit)
                            {
                                staticConstructor->SetConstraint(constraint.release());
                            }
                            *parentMatch32 = match;
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
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch33 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch34 = &match;
                {
                    int save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch35 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = StatementParser::CompoundStatement(lexer, ctx);
                        body.reset(static_cast<CompoundStatementNode*>(match.value));
                        if (match.hit)
                        {
                            staticConstructor->SetBody(body.release());
                        }
                        *parentMatch35 = match;
                    }
                    *parentMatch34 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch36 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == SEMICOLON)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch36 = match;
                        }
                        *parentMatch34 = match;
                    }
                }
                *parentMatch33 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, staticConstructor.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ClassParser::Constructor(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::ClassNode* classNode)
{
    std::unique_ptr<ConstructorNode> ctor = std::unique_ptr<ConstructorNode>();
    Span s = Span();
    Span specifierSpan = Span();
    std::unique_ptr<cmajor::ast::Attributes> attrs;
    std::unique_ptr<soulng::parser::Value<cmajor::ast::Specifiers>> specifiers;
    std::unique_ptr<IdentifierNode> id;
    std::unique_ptr<InitializerNode> initializer;
    std::unique_ptr<WhereConstraintNode> constraint;
    std::unique_ptr<CompoundStatementNode> body;
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
                                        soulng::lexer::Span span = lexer.GetSpan();
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
                                        soulng::lexer::Span span = lexer.GetSpan();
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
                                soulng::parser::Match* parentMatch14 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::lexer::Span span = lexer.GetSpan();
                                    bool pass = true;
                                    soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                    id.reset(static_cast<IdentifierNode*>(match.value));
                                    if (match.hit)
                                    {
                                        std::u32string className = lexer.GetMatch(span);
                                        s.end = span.end;
                                        if (className != classNode->Id()->Str()) pass = false;
                                        else
                                        {
                                            ctor.reset(new ConstructorNode(s, specifiers->value, attrs.release()));
                                            ctor->SetClassId(id.release());
                                            ctor->SetSpecifierSpan(specifierSpan);
                                        }
                                    }
                                    if (match.hit && !pass)
                                    {
                                        match = soulng::parser::Match(false);
                                    }
                                    *parentMatch14 = match;
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
                        soulng::parser::Match* parentMatch15 = &match;
                        {
                            soulng::parser::Match match = ParameterParser::ParameterList(lexer, ctx, ctor.get());
                            *parentMatch15 = match;
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
                        soulng::parser::Match match(true);
                        int save = lexer.GetPos();
                        soulng::parser::Match* parentMatch17 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch18 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == COLON)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch18 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch19 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch20 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch21 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = ClassParser::Initializer(lexer, ctx);
                                            initializer.reset(static_cast<InitializerNode*>(match.value));
                                            if (match.hit)
                                            {
                                                ctor->AddInitializer(initializer.release());
                                            }
                                            *parentMatch21 = match;
                                        }
                                        *parentMatch20 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch22 = &match;
                                        {
                                            soulng::parser::Match match(true);
                                            soulng::parser::Match* parentMatch23 = &match;
                                            {
                                                while (true)
                                                {
                                                    int save = lexer.GetPos();
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch24 = &match;
                                                        {
                                                            soulng::parser::Match match(false);
                                                            if (*lexer == COMMA)
                                                            {
                                                                ++lexer;
                                                                match.hit = true;
                                                            }
                                                            *parentMatch24 = match;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch25 = &match;
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch26 = &match;
                                                                {
                                                                    int pos = lexer.GetPos();
                                                                    soulng::parser::Match match = ClassParser::Initializer(lexer, ctx);
                                                                    initializer.reset(static_cast<InitializerNode*>(match.value));
                                                                    if (match.hit)
                                                                    {
                                                                        ctor->AddInitializer(initializer.release());
                                                                    }
                                                                    *parentMatch26 = match;
                                                                }
                                                                *parentMatch25 = match;
                                                            }
                                                            *parentMatch24 = match;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            *parentMatch23 = match;
                                                        }
                                                        else
                                                        {
                                                            lexer.SetPos(save);
                                                            break;
                                                        }
                                                    }
                                                }
                                            }
                                            *parentMatch22 = match;
                                        }
                                        *parentMatch20 = match;
                                    }
                                    *parentMatch19 = match;
                                }
                                *parentMatch18 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch17 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                            }
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
                soulng::parser::Match* parentMatch27 = &match;
                {
                    soulng::parser::Match match(true);
                    int save = lexer.GetPos();
                    soulng::parser::Match* parentMatch28 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch29 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = ConceptParser::WhereConstraint(lexer, ctx);
                            constraint.reset(static_cast<WhereConstraintNode*>(match.value));
                            if (match.hit)
                            {
                                ctor->SetConstraint(constraint.release());
                            }
                            *parentMatch29 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch28 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                        }
                    }
                    *parentMatch27 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch30 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch31 = &match;
                {
                    int save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch32 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = StatementParser::CompoundStatement(lexer, ctx);
                        body.reset(static_cast<CompoundStatementNode*>(match.value));
                        if (match.hit)
                        {
                            ctor->SetBody(body.release());
                        }
                        *parentMatch32 = match;
                    }
                    *parentMatch31 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch33 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == SEMICOLON)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch33 = match;
                        }
                        *parentMatch31 = match;
                    }
                }
                *parentMatch30 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, ctor.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ClassParser::Destructor(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::ClassNode* classNode)
{
    std::unique_ptr<DestructorNode> dtor = std::unique_ptr<DestructorNode>();
    Span s = Span();
    Span specifierSpan = Span();
    std::u32string className = std::u32string();
    std::unique_ptr<cmajor::ast::Attributes> attrs;
    std::unique_ptr<soulng::parser::Value<cmajor::ast::Specifiers>> specifiers;
    std::unique_ptr<IdentifierNode> id;
    std::unique_ptr<WhereConstraintNode> contraint;
    std::unique_ptr<CompoundStatementNode> body;
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
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::lexer::Span span = lexer.GetSpan();
                                            soulng::parser::Match match(true);
                                            if (match.hit)
                                            {
                                                s = span;
                                            }
                                            *parentMatch9 = match;
                                        }
                                        *parentMatch8 = match;
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
                                                soulng::parser::Match match = AttributeParser::Attributes(lexer);
                                                attrs.reset(static_cast<cmajor::ast::Attributes*>(match.value));
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
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
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
                                            soulng::lexer::Span span = lexer.GetSpan();
                                            soulng::parser::Match match = SpecifierParser::Specifiers(lexer);
                                            specifiers.reset(static_cast<soulng::parser::Value<cmajor::ast::Specifiers>*>(match.value));
                                            if (match.hit)
                                            {
                                                specifierSpan = span;
                                            }
                                            *parentMatch13 = match;
                                        }
                                        *parentMatch12 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch6 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch14 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    if (*lexer == CPL)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    *parentMatch14 = match;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch15 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch16 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::lexer::Span span = lexer.GetSpan();
                                    soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                    id.reset(static_cast<IdentifierNode*>(match.value));
                                    if (match.hit)
                                    {
                                        className = lexer.GetMatch(span);
                                    }
                                    *parentMatch16 = match;
                                }
                                *parentMatch15 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch17 = &match;
                        {
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == LPAREN)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                                }
                            }
                            *parentMatch17 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch18 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch19 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::lexer::Span span = lexer.GetSpan();
                            bool pass = true;
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == RPAREN)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                                }
                            }
                            if (match.hit)
                            {
                                s.end = span.end;
                                if (className != classNode->Id()->Str()) pass = false;
                                else
                                {
                                    dtor.reset(new DestructorNode(s, specifiers->value, attrs.release()));
                                    dtor->SetClassId(id.release());
                                    dtor->SetSpecifierSpan(specifierSpan);
                                }
                            }
                            if (match.hit && !pass)
                            {
                                match = soulng::parser::Match(false);
                            }
                            *parentMatch19 = match;
                        }
                        *parentMatch18 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch20 = &match;
                {
                    soulng::parser::Match match(true);
                    int save = lexer.GetPos();
                    soulng::parser::Match* parentMatch21 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch22 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = ConceptParser::WhereConstraint(lexer, ctx);
                            contraint.reset(static_cast<WhereConstraintNode*>(match.value));
                            if (match.hit)
                            {
                                dtor->SetConstraint(contraint.release());
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
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch23 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch24 = &match;
                {
                    int save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch25 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = StatementParser::CompoundStatement(lexer, ctx);
                        body.reset(static_cast<CompoundStatementNode*>(match.value));
                        if (match.hit)
                        {
                            dtor->SetBody(body.release());
                        }
                        *parentMatch25 = match;
                    }
                    *parentMatch24 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch26 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == SEMICOLON)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch26 = match;
                        }
                        *parentMatch24 = match;
                    }
                }
                *parentMatch23 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, dtor.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ClassParser::Initializer(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<InitializerNode> initializer = std::unique_ptr<InitializerNode>();
    std::unique_ptr<IdentifierNode> id;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int save = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int save = lexer.GetPos();
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
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match(false);
                                if (*lexer == THIS)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    initializer.reset(new ThisInitializerNode(span));
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
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    if (*lexer == LPAREN)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                                    }
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
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = ExpressionParser::ArgumentList(lexer, ctx, initializer.get());
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, U"argument list");
                                }
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
                    soulng::parser::Match* parentMatch9 = &match;
                    {
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == RPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                            }
                        }
                        *parentMatch9 = match;
                    }
                    *parentMatch3 = match;
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
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch12 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch13 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch14 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match(false);
                                        if (*lexer == BASE)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            initializer.reset(new BaseInitializerNode(span));
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
                                        soulng::parser::Match match(true);
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match(false);
                                            if (*lexer == LPAREN)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            if (!match.hit)
                                            {
                                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                                            }
                                        }
                                        *parentMatch15 = match;
                                    }
                                    *parentMatch13 = match;
                                }
                                *parentMatch12 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch16 = &match;
                                {
                                    soulng::parser::Match match(true);
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match = ExpressionParser::ArgumentList(lexer, ctx, initializer.get());
                                        if (!match.hit)
                                        {
                                            lexer.ThrowExpectationFailure(pos, U"argument list");
                                        }
                                    }
                                    *parentMatch16 = match;
                                }
                                *parentMatch12 = match;
                            }
                            *parentMatch11 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch17 = &match;
                            {
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    if (*lexer == RPAREN)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                                    }
                                }
                                *parentMatch17 = match;
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
                soulng::parser::Match* parentMatch18 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch19 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch20 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch21 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch22 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::lexer::Span span = lexer.GetSpan();
                                    soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                    id.reset(static_cast<IdentifierNode*>(match.value));
                                    if (match.hit)
                                    {
                                        initializer.reset(new MemberInitializerNode(span, id.release()));
                                    }
                                    *parentMatch22 = match;
                                }
                                *parentMatch21 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch23 = &match;
                                {
                                    soulng::parser::Match match(true);
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        if (*lexer == LPAREN)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (!match.hit)
                                        {
                                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                                        }
                                    }
                                    *parentMatch23 = match;
                                }
                                *parentMatch21 = match;
                            }
                            *parentMatch20 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch24 = &match;
                            {
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = ExpressionParser::ArgumentList(lexer, ctx, initializer.get());
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, U"argument list");
                                    }
                                }
                                *parentMatch24 = match;
                            }
                            *parentMatch20 = match;
                        }
                        *parentMatch19 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch25 = &match;
                        {
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == RPAREN)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                                }
                            }
                            *parentMatch25 = match;
                        }
                        *parentMatch19 = match;
                    }
                    *parentMatch18 = match;
                }
                *parentMatch1 = match;
            }
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, initializer.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ClassParser::MemberFunction(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<MemberFunctionNode> memFun = std::unique_ptr<MemberFunctionNode>();
    Span s = Span();
    Span specifierSpan = Span();
    Span groupIdSpan = Span();
    std::unique_ptr<cmajor::ast::Attributes> attrs;
    std::unique_ptr<soulng::parser::Value<cmajor::ast::Specifiers>> specifiers;
    std::unique_ptr<Node> returnType;
    std::unique_ptr<soulng::parser::Value<std::u32string>> groupId;
    std::unique_ptr<WhereConstraintNode> constraint;
    std::unique_ptr<CompoundStatementNode> body;
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
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::lexer::Span span = lexer.GetSpan();
                                            soulng::parser::Match match(true);
                                            if (match.hit)
                                            {
                                                s = span;
                                            }
                                            *parentMatch9 = match;
                                        }
                                        *parentMatch8 = match;
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
                                                soulng::parser::Match match = AttributeParser::Attributes(lexer);
                                                attrs.reset(static_cast<cmajor::ast::Attributes*>(match.value));
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
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
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
                                            soulng::lexer::Span span = lexer.GetSpan();
                                            soulng::parser::Match match = SpecifierParser::Specifiers(lexer);
                                            specifiers.reset(static_cast<soulng::parser::Value<cmajor::ast::Specifiers>*>(match.value));
                                            if (match.hit)
                                            {
                                                specifierSpan = span;
                                            }
                                            *parentMatch13 = match;
                                        }
                                        *parentMatch12 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch6 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch14 = &match;
                                {
                                    soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                                    returnType.reset(static_cast<Node*>(match.value));
                                    *parentMatch14 = match;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch15 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch16 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::lexer::Span span = lexer.GetSpan();
                                    soulng::parser::Match match = FunctionParser::FunctionGroupId(lexer, ctx);
                                    groupId.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                                    if (match.hit)
                                    {
                                        s.end = span.end;
                                        groupIdSpan = span;
                                        memFun.reset(new MemberFunctionNode(s, specifiers->value, returnType.release(), groupId->value, attrs.release()));
                                        memFun->SetSpecifierSpan(specifierSpan);
                                        memFun->SetGroupIdSpan(groupIdSpan);
                                    }
                                    *parentMatch16 = match;
                                }
                                *parentMatch15 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch17 = &match;
                        {
                            soulng::parser::Match match = ParameterParser::ParameterList(lexer, ctx, memFun.get());
                            *parentMatch17 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch18 = &match;
                    {
                        soulng::parser::Match match(true);
                        int save = lexer.GetPos();
                        soulng::parser::Match* parentMatch19 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch20 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == CONST)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    memFun->SetConst();
                                }
                                *parentMatch20 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch19 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                            }
                        }
                        *parentMatch18 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch21 = &match;
                {
                    soulng::parser::Match match(true);
                    int save = lexer.GetPos();
                    soulng::parser::Match* parentMatch22 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch23 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = ConceptParser::WhereConstraint(lexer, ctx);
                            constraint.reset(static_cast<WhereConstraintNode*>(match.value));
                            if (match.hit)
                            {
                                memFun->SetConstraint(constraint.release());
                            }
                            *parentMatch23 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch22 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                        }
                    }
                    *parentMatch21 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch24 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch25 = &match;
                {
                    int save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch26 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = StatementParser::CompoundStatement(lexer, ctx);
                        body.reset(static_cast<CompoundStatementNode*>(match.value));
                        if (match.hit)
                        {
                            memFun->SetBody(body.release());
                        }
                        *parentMatch26 = match;
                    }
                    *parentMatch25 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch27 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == SEMICOLON)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch27 = match;
                        }
                        *parentMatch25 = match;
                    }
                }
                *parentMatch24 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, memFun.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ClassParser::ConversionFunction(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<ConversionFunctionNode> conversionFun = std::unique_ptr<ConversionFunctionNode>();
    Span s = Span();
    Span specifierSpan = Span();
    std::unique_ptr<cmajor::ast::Attributes> attrs;
    std::unique_ptr<soulng::parser::Value<cmajor::ast::Specifiers>> specifiers;
    std::unique_ptr<Node> type;
    std::unique_ptr<WhereConstraintNode> constraint;
    std::unique_ptr<CompoundStatementNode> body;
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
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch10 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                soulng::parser::Match match(true);
                                                if (match.hit)
                                                {
                                                    s = span;
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
                                                int save = lexer.GetPos();
                                                soulng::parser::Match* parentMatch12 = &match;
                                                {
                                                    soulng::parser::Match match = AttributeParser::Attributes(lexer);
                                                    attrs.reset(static_cast<cmajor::ast::Attributes*>(match.value));
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
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch14 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
                                                soulng::parser::Match match = SpecifierParser::Specifiers(lexer);
                                                specifiers.reset(static_cast<soulng::parser::Value<cmajor::ast::Specifiers>*>(match.value));
                                                if (match.hit)
                                                {
                                                    specifierSpan = span;
                                                }
                                                *parentMatch14 = match;
                                            }
                                            *parentMatch13 = match;
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch15 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == OPERATOR)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        *parentMatch15 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch6 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch16 = &match;
                                {
                                    soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                                    type.reset(static_cast<Node*>(match.value));
                                    *parentMatch16 = match;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch17 = &match;
                            {
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    if (*lexer == LPAREN)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                                    }
                                }
                                *parentMatch17 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch18 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch19 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    if (*lexer == RPAREN)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                                    }
                                }
                                if (match.hit)
                                {
                                    s.end = span.end;
                                    conversionFun.reset(new ConversionFunctionNode(s, specifiers->value, type.release(), attrs.release()));
                                    conversionFun->SetSpecifierSpan(specifierSpan);
                                }
                                *parentMatch19 = match;
                            }
                            *parentMatch18 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch20 = &match;
                    {
                        soulng::parser::Match match(true);
                        int save = lexer.GetPos();
                        soulng::parser::Match* parentMatch21 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch22 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == CONST)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    conversionFun->SetConst();
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
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch23 = &match;
                {
                    soulng::parser::Match match(true);
                    int save = lexer.GetPos();
                    soulng::parser::Match* parentMatch24 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch25 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = ConceptParser::WhereConstraint(lexer, ctx);
                            constraint.reset(static_cast<WhereConstraintNode*>(match.value));
                            if (match.hit)
                            {
                                conversionFun->SetConstraint(constraint.release());
                            }
                            *parentMatch25 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch24 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                        }
                    }
                    *parentMatch23 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch26 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch27 = &match;
                {
                    int save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch28 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = StatementParser::CompoundStatement(lexer, ctx);
                        body.reset(static_cast<CompoundStatementNode*>(match.value));
                        if (match.hit)
                        {
                            conversionFun->SetBody(body.release());
                        }
                        *parentMatch28 = match;
                    }
                    *parentMatch27 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch29 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == SEMICOLON)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch29 = match;
                        }
                        *parentMatch27 = match;
                    }
                }
                *parentMatch26 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, conversionFun.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ClassParser::MemberVariable(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    Span specifierSpan = Span();
    std::unique_ptr<cmajor::ast::Attributes> attrs;
    std::unique_ptr<soulng::parser::Value<cmajor::ast::Specifiers>> specifiers;
    std::unique_ptr<Node> type;
    std::unique_ptr<IdentifierNode> id;
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
                            soulng::lexer::Span span = lexer.GetSpan();
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
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch9 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match = SpecifierParser::Specifiers(lexer);
                            specifiers.reset(static_cast<soulng::parser::Value<cmajor::ast::Specifiers>*>(match.value));
                            if (match.hit)
                            {
                                specifierSpan = span;
                            }
                            *parentMatch9 = match;
                        }
                        *parentMatch8 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch10 = &match;
                {
                    soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                    type.reset(static_cast<Node*>(match.value));
                    *parentMatch10 = match;
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
                soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                id.reset(static_cast<IdentifierNode*>(match.value));
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
                    MemberVariableNode * value = new MemberVariableNode(s, specifiers->value, type.release(), id.release(), attrs.release());
                    value->SetSpecifierSpan(specifierSpan);
                    return soulng::parser::Match(true, value);
                }
                *parentMatch13 = match;
            }
            *parentMatch12 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}
