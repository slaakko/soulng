#include "Concept.hpp"
#include <soulng/util/Unicode.hpp>
#include <cmajor/parser/Parameter.hpp>
#include <cmajor/parser/Specifier.hpp>
#include <cmajor/parser/TypeExpr.hpp>
#include <cmajor/parser/Identifier.hpp>
#include <cmajor/parser/Expression.hpp>
#include <cmajor/parser/Function.hpp>
#include <cmajor/lexer/CmajorLexer.hpp>
#include <cmajor/lexer/CmajorTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/Concept.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace cmajor::ast;
using namespace CmajorTokens;

soulng::parser::Match ConceptParser::Concept(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<ConceptNode> concept = std::unique_ptr<ConceptNode>();
    std::unique_ptr<WhereConstraintNode> constraint = std::unique_ptr<WhereConstraintNode>();
    Span s = Span();
    Span beginBraceSpan = Span();
    Span endBraceSpan = Span();
    std::unique_ptr<soulng::parser::Value<cmajor::ast::Specifiers>> specifiers;
    std::unique_ptr<IdentifierNode> conceptName;
    std::unique_ptr<IdentifierNode> typeParam;
    std::unique_ptr<ConceptIdNode> refinement;
    std::unique_ptr<WhereConstraintNode> c;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match(true);
            if (match.hit)
            {
                ctx->BeginParsingConcept();
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
                int pos = lexer.GetPos();
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
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch11 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::lexer::Span span = lexer.GetSpan();
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
                                                            soulng::parser::Match match = SpecifierParser::Specifiers(lexer);
                                                            specifiers.reset(static_cast<soulng::parser::Value<cmajor::ast::Specifiers>*>(match.value));
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
                                                            if (*lexer == CONCEPT)
                                                            {
                                                                ++lexer;
                                                                match.hit = true;
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
                                                            soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                                            conceptName.reset(static_cast<IdentifierNode*>(match.value));
                                                            if (!match.hit)
                                                            {
                                                                lexer.ThrowExpectationFailure(pos, U"identifier");
                                                            }
                                                        }
                                                        *parentMatch16 = match;
                                                    }
                                                    *parentMatch12 = match;
                                                }
                                                if (match.hit)
                                                {
                                                    concept.reset(new ConceptNode(span, specifiers->value, conceptName.release()));
                                                }
                                                *parentMatch11 = match;
                                            }
                                            *parentMatch10 = match;
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
                                                    if (*lexer == LANGLE)
                                                    {
                                                        ++lexer;
                                                        match.hit = true;
                                                    }
                                                    if (!match.hit)
                                                    {
                                                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LANGLE)));
                                                    }
                                                }
                                                *parentMatch17 = match;
                                            }
                                            *parentMatch10 = match;
                                        }
                                        *parentMatch9 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch18 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch19 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch20 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                                    typeParam.reset(static_cast<IdentifierNode*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        concept->AddTypeParameter(typeParam.release());
                                                    }
                                                    *parentMatch20 = match;
                                                }
                                                *parentMatch19 = match;
                                            }
                                            if (match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch21 = &match;
                                                {
                                                    soulng::parser::Match match(true);
                                                    soulng::parser::Match* parentMatch22 = &match;
                                                    {
                                                        while (true)
                                                        {
                                                            int save = lexer.GetPos();
                                                            {
                                                                soulng::parser::Match match(false);
                                                                soulng::parser::Match* parentMatch23 = &match;
                                                                {
                                                                    soulng::parser::Match match(false);
                                                                    if (*lexer == COMMA)
                                                                    {
                                                                        ++lexer;
                                                                        match.hit = true;
                                                                    }
                                                                    *parentMatch23 = match;
                                                                }
                                                                if (match.hit)
                                                                {
                                                                    soulng::parser::Match match(false);
                                                                    soulng::parser::Match* parentMatch24 = &match;
                                                                    {
                                                                        soulng::parser::Match match(false);
                                                                        soulng::parser::Match* parentMatch25 = &match;
                                                                        {
                                                                            int pos = lexer.GetPos();
                                                                            soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                                                            typeParam.reset(static_cast<IdentifierNode*>(match.value));
                                                                            if (match.hit)
                                                                            {
                                                                                concept->AddTypeParameter(typeParam.release());
                                                                            }
                                                                            *parentMatch25 = match;
                                                                        }
                                                                        *parentMatch24 = match;
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
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                    *parentMatch21 = match;
                                                }
                                                *parentMatch19 = match;
                                            }
                                            *parentMatch18 = match;
                                        }
                                        *parentMatch9 = match;
                                    }
                                    *parentMatch8 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch26 = &match;
                                    {
                                        soulng::parser::Match match(true);
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match(false);
                                            if (*lexer == RANGLE)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            if (!match.hit)
                                            {
                                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RANGLE)));
                                            }
                                        }
                                        *parentMatch26 = match;
                                    }
                                    *parentMatch8 = match;
                                }
                                *parentMatch7 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch27 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch28 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch29 = &match;
                                        {
                                            soulng::parser::Match match(true);
                                            int save = lexer.GetPos();
                                            soulng::parser::Match* parentMatch30 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch31 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = ConceptParser::Refinement(lexer);
                                                    refinement.reset(static_cast<ConceptIdNode*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        concept->SetRefinement(refinement.release());
                                                    }
                                                    *parentMatch31 = match;
                                                }
                                                if (match.hit)
                                                {
                                                    *parentMatch30 = match;
                                                }
                                                else
                                                {
                                                    lexer.SetPos(save);
                                                }
                                            }
                                            *parentMatch29 = match;
                                        }
                                        if (match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch32 = &match;
                                            {
                                                soulng::parser::Match match(true);
                                                int save = lexer.GetPos();
                                                soulng::parser::Match* parentMatch33 = &match;
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch34 = &match;
                                                    {
                                                        int pos = lexer.GetPos();
                                                        soulng::lexer::Span span = lexer.GetSpan();
                                                        soulng::parser::Match match = ConceptParser::WhereConstraint(lexer, ctx);
                                                        c.reset(static_cast<WhereConstraintNode*>(match.value));
                                                        if (match.hit)
                                                        {
                                                            s.end = span.end;
                                                            constraint.reset(c.release());
                                                            constraint->SetHeaderConstraint();
                                                            concept->AddConstraint(constraint.release());
                                                        }
                                                        *parentMatch34 = match;
                                                    }
                                                    if (match.hit)
                                                    {
                                                        *parentMatch33 = match;
                                                    }
                                                    else
                                                    {
                                                        lexer.SetPos(save);
                                                    }
                                                }
                                                *parentMatch32 = match;
                                            }
                                            *parentMatch29 = match;
                                        }
                                        if (match.hit)
                                        {
                                            concept->SetSpan(s);
                                        }
                                        *parentMatch28 = match;
                                    }
                                    *parentMatch27 = match;
                                }
                                *parentMatch7 = match;
                            }
                            *parentMatch6 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch35 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch36 = &match;
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
                                    *parentMatch36 = match;
                                }
                                *parentMatch35 = match;
                            }
                            *parentMatch6 = match;
                        }
                        *parentMatch5 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch37 = &match;
                        {
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = ConceptParser::ConceptBody(lexer, ctx, concept.get());
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, U"concept body");
                                }
                            }
                            *parentMatch37 = match;
                        }
                        *parentMatch5 = match;
                    }
                    *parentMatch4 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch38 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch39 = &match;
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
                            }
                            *parentMatch39 = match;
                        }
                        *parentMatch38 = match;
                    }
                    *parentMatch4 = match;
                }
                if (match.hit)
                {
                    ctx->EndParsingConcept();
                    concept->SetBeginBraceSpan(beginBraceSpan);
                    concept->SetEndBraceSpan(endBraceSpan);
                    return soulng::parser::Match(true, concept.release());
                }
                else
                {
                    ctx->EndParsingConcept();
                }
                *parentMatch3 = match;
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ConceptParser::Refinement(CmajorLexer& lexer)
{
    std::unique_ptr<ConceptIdNode> conceptId = std::unique_ptr<ConceptIdNode>();
    std::unique_ptr<IdentifierNode> refinedConcept;
    std::unique_ptr<IdentifierNode> typeParam;
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
                        if (*lexer == COLON)
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
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match = IdentifierParser::QualifiedId(lexer);
                                refinedConcept.reset(static_cast<IdentifierNode*>(match.value));
                                if (match.hit)
                                {
                                    conceptId.reset(new ConceptIdNode(span, refinedConcept.release()));
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
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
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == LANGLE)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LANGLE)));
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
                soulng::parser::Match* parentMatch8 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch9 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch10 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                            typeParam.reset(static_cast<IdentifierNode*>(match.value));
                            if (match.hit)
                            {
                                conceptId->AddTypeParameter(typeParam.release());
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
                            soulng::parser::Match* parentMatch12 = &match;
                            {
                                while (true)
                                {
                                    int save = lexer.GetPos();
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch13 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            if (*lexer == COMMA)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            *parentMatch13 = match;
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
                                                    soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                                    typeParam.reset(static_cast<IdentifierNode*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        conceptId->AddTypeParameter(typeParam.release());
                                                    }
                                                    *parentMatch15 = match;
                                                }
                                                *parentMatch14 = match;
                                            }
                                            *parentMatch13 = match;
                                        }
                                        if (match.hit)
                                        {
                                            *parentMatch12 = match;
                                        }
                                        else
                                        {
                                            lexer.SetPos(save);
                                            break;
                                        }
                                    }
                                }
                            }
                            *parentMatch11 = match;
                        }
                        *parentMatch9 = match;
                    }
                    *parentMatch8 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch16 = &match;
            {
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RANGLE)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RANGLE)));
                    }
                }
                *parentMatch16 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, conceptId.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ConceptParser::ConceptBody(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::ConceptNode* concept)
{
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
                    int save = lexer.GetPos();
                    soulng::parser::Match match = ConceptParser::ConceptBodyConstraint(lexer, ctx, concept);
                    *parentMatch1 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch2 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match = ConceptParser::Axiom(lexer, ctx, concept);
                            *parentMatch2 = match;
                        }
                        *parentMatch1 = match;
                    }
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

soulng::parser::Match ConceptParser::ConceptBodyConstraint(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::ConceptNode* concept)
{
    std::unique_ptr<ConstraintNode> typeNameConstraint;
    std::unique_ptr<ConstraintNode> signatureConstraint;
    std::unique_ptr<WhereConstraintNode> embeddedConstraint;
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
                int pos = lexer.GetPos();
                soulng::parser::Match match = ConceptParser::TypeNameConstraint(lexer, ctx);
                typeNameConstraint.reset(static_cast<ConstraintNode*>(match.value));
                if (match.hit)
                {
                    concept->AddConstraint(typeNameConstraint.release());
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = ConceptParser::SignatureConstraint(lexer, ctx, concept->TypeParameters()[0]);
                        signatureConstraint.reset(static_cast<ConstraintNode*>(match.value));
                        if (match.hit)
                        {
                            concept->AddConstraint(signatureConstraint.release());
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ConceptParser::EmbeddedConstraint(lexer, ctx);
                    embeddedConstraint.reset(static_cast<WhereConstraintNode*>(match.value));
                    if (match.hit)
                    {
                        concept->AddConstraint(embeddedConstraint.release());
                    }
                    *parentMatch6 = match;
                }
                *parentMatch5 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match ConceptParser::TypeNameConstraint(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<Node> type;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                if (*lexer == TYPENAME)
                {
                    ++lexer;
                    match.hit = true;
                }
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
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                    type.reset(static_cast<Node*>(match.value));
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, U"type expression");
                    }
                }
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
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
                    s.end = span.end;
                    return soulng::parser::Match(true, new TypeNameConstraintNode(s, type.release()));
                }
                *parentMatch5 = match;
            }
            *parentMatch4 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ConceptParser::SignatureConstraint(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::IdentifierNode* firstTypeParameter)
{
    std::unique_ptr<ConstraintNode> constructorConstraint;
    std::unique_ptr<ConstraintNode> destructorConstraint;
    std::unique_ptr<ConstraintNode> memberFunctionConstraint;
    std::unique_ptr<ConstraintNode> functionConstraint;
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
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ConceptParser::ConstructorConstraint(lexer, ctx, firstTypeParameter);
                    constructorConstraint.reset(static_cast<ConstraintNode*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, constructorConstraint.release());
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = ConceptParser::DestructorConstraint(lexer, ctx, firstTypeParameter);
                            destructorConstraint.reset(static_cast<ConstraintNode*>(match.value));
                            if (match.hit)
                            {
                                return soulng::parser::Match(true, destructorConstraint.release());
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch7 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = ConceptParser::MemberFunctionConstraint(lexer, ctx);
                        memberFunctionConstraint.reset(static_cast<ConstraintNode*>(match.value));
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, memberFunctionConstraint.release());
                        }
                        *parentMatch7 = match;
                    }
                    *parentMatch6 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch8 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch9 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ConceptParser::FunctionConstraint(lexer, ctx);
                    functionConstraint.reset(static_cast<ConstraintNode*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, functionConstraint.release());
                    }
                    *parentMatch9 = match;
                }
                *parentMatch8 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match ConceptParser::ConstructorConstraint(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::IdentifierNode* firstTypeParameter)
{
    std::unique_ptr<ConstraintNode> ctorConstraint = std::unique_ptr<ConstraintNode>();
    Span e = Span();
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
                    soulng::parser::Match match(true);
                    int save = lexer.GetPos();
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        if (*lexer == EXPLICIT)
                        {
                            ++lexer;
                            match.hit = true;
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
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::lexer::Span span = lexer.GetSpan();
                            bool pass = true;
                            soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                            id.reset(static_cast<IdentifierNode*>(match.value));
                            if (match.hit)
                            {
                                std::u32string className = lexer.GetMatch(span);
                                pass = className == firstTypeParameter->Str();
                                if (pass) ctorConstraint.reset(new ConstructorConstraintNode(span, id.release()));
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
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch7 = &match;
                {
                    soulng::parser::Match match = ParameterParser::ParameterList(lexer, ctx, ctorConstraint.get());
                    *parentMatch7 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
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
                        e = span;
                    }
                    *parentMatch9 = match;
                }
                *parentMatch8 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            ctorConstraint->SetSpanEnd(e.end);
            return soulng::parser::Match(true, ctorConstraint.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ConceptParser::DestructorConstraint(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::IdentifierNode* firstTypeParameter)
{
    Span s = Span();
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
                            int pos = lexer.GetPos();
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match(false);
                            if (*lexer == CPL)
                            {
                                ++lexer;
                                match.hit = true;
                            }
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
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::lexer::Span span = lexer.GetSpan();
                                bool pass = true;
                                soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                id.reset(static_cast<IdentifierNode*>(match.value));
                                if (match.hit)
                                {
                                    std::u32string className = lexer.GetMatch(span);
                                    pass = className == firstTypeParameter->Str();
                                }
                                if (match.hit && !pass)
                                {
                                    match = soulng::parser::Match(false);
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
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch10 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch11 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
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
                        s.end = span.end;
                    }
                    *parentMatch11 = match;
                }
                *parentMatch10 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new DestructorConstraintNode(s, id.release()));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ConceptParser::MemberFunctionConstraint(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<ConstraintNode> memberFunctionConstraint = std::unique_ptr<ConstraintNode>();
    std::unique_ptr<Node> returnType;
    std::unique_ptr<IdentifierNode> typeParam;
    std::unique_ptr<soulng::parser::Value<std::u32string>> functionGroupId;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                            returnType.reset(static_cast<Node*>(match.value));
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                typeParam.reset(static_cast<IdentifierNode*>(match.value));
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch7 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == DOT)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch7 = match;
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
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = FunctionParser::FunctionGroupId(lexer, ctx);
                            functionGroupId.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, U"function group identifier");
                            }
                        }
                        *parentMatch8 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    memberFunctionConstraint.reset(new MemberFunctionConstraintNode(span, returnType.release(), typeParam.release(), functionGroupId->value));
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch9 = &match;
            {
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ParameterParser::ParameterList(lexer, ctx, memberFunctionConstraint.get());
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, U"parameter list");
                    }
                }
                *parentMatch9 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch10 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch11 = &match;
            {
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
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
                    memberFunctionConstraint->SetSpanEnd(span.end);
                    return soulng::parser::Match(true, memberFunctionConstraint.release());
                }
                *parentMatch11 = match;
            }
            *parentMatch10 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ConceptParser::FunctionConstraint(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<ConstraintNode> functionConstraint = std::unique_ptr<ConstraintNode>();
    std::unique_ptr<Node> returnType;
    std::unique_ptr<soulng::parser::Value<std::u32string>> functionGroupId;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                    returnType.reset(static_cast<Node*>(match.value));
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = FunctionParser::FunctionGroupId(lexer, ctx);
                            functionGroupId.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, U"function group identifier");
                            }
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    functionConstraint.reset(new FunctionConstraintNode(span, returnType.release(), functionGroupId->value));
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
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ParameterParser::ParameterList(lexer, ctx, functionConstraint.get());
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, U"parameter list");
                    }
                }
                *parentMatch5 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
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
                soulng::lexer::Span span = lexer.GetSpan();
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
                    functionConstraint->SetSpanEnd(span.end);
                    return soulng::parser::Match(true, functionConstraint.release());
                }
                *parentMatch7 = match;
            }
            *parentMatch6 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ConceptParser::EmbeddedConstraint(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<WhereConstraintNode> constraint = std::unique_ptr<WhereConstraintNode>();
    std::unique_ptr<WhereConstraintNode> c;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match = ConceptParser::WhereConstraint(lexer, ctx);
            c.reset(static_cast<WhereConstraintNode*>(match.value));
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
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
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            constraint.reset(c.release());
            constraint->SetSemicolon();
            return soulng::parser::Match(true, constraint.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ConceptParser::WhereConstraint(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<ConstraintNode> constraint;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::lexer::Span span = lexer.GetSpan();
            soulng::parser::Match match(false);
            if (*lexer == WHERE)
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ConceptParser::ConstraintExpr(lexer, ctx);
                    constraint.reset(static_cast<ConstraintNode*>(match.value));
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, U"constraint expression");
                    }
                }
                if (match.hit)
                {
                    s.end = span.end;
                    return soulng::parser::Match(true, new WhereConstraintNode(span, constraint.release()));
                }
                *parentMatch3 = match;
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ConceptParser::ConstraintExpr(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<ConstraintNode> disjunctiveConstraint;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match = ConceptParser::DisjunctiveConstraintExpr(lexer, ctx);
        disjunctiveConstraint.reset(static_cast<ConstraintNode*>(match.value));
        if (match.hit)
        {
            return soulng::parser::Match(true, disjunctiveConstraint.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ConceptParser::DisjunctiveConstraintExpr(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<ConstraintNode> constraint = std::unique_ptr<ConstraintNode>();
    std::unique_ptr<ConstraintNode> left;
    std::unique_ptr<ConstraintNode> right;
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ConceptParser::ConjunctiveConstraintExpr(lexer, ctx);
                left.reset(static_cast<ConstraintNode*>(match.value));
                if (match.hit)
                {
                    constraint.reset(left.release());
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
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    while (true)
                    {
                        int save = lexer.GetPos();
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch5 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == OR)
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
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match = ConceptParser::ConjunctiveConstraintExpr(lexer, ctx);
                                        right.reset(static_cast<ConstraintNode*>(match.value));
                                        if (match.hit)
                                        {
                                            s.end = span.end;
                                            constraint.reset(new DisjunctiveConstraintNode(s, constraint.release(), right.release()));
                                        }
                                        *parentMatch7 = match;
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
                                break;
                            }
                        }
                    }
                }
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, constraint.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ConceptParser::ConjunctiveConstraintExpr(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<ConstraintNode> constraint = std::unique_ptr<ConstraintNode>();
    std::unique_ptr<ConstraintNode> left;
    std::unique_ptr<ConstraintNode> right;
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ConceptParser::PrimaryConstraintExpr(lexer, ctx);
                left.reset(static_cast<ConstraintNode*>(match.value));
                if (match.hit)
                {
                    constraint.reset(left.release());
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
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    while (true)
                    {
                        int save = lexer.GetPos();
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch5 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == AND)
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
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match = ConceptParser::PrimaryConstraintExpr(lexer, ctx);
                                        right.reset(static_cast<ConstraintNode*>(match.value));
                                        if (match.hit)
                                        {
                                            s.end = span.end;
                                            constraint.reset(new ConjunctiveConstraintNode(s, constraint.release(), right.release()));
                                        }
                                        *parentMatch7 = match;
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
                                break;
                            }
                        }
                    }
                }
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, constraint.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ConceptParser::PrimaryConstraintExpr(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<ConstraintNode> constraint;
    std::unique_ptr<ConstraintNode> atomicConstraint;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match(false);
                    if (*lexer == LPAREN)
                    {
                        ++lexer;
                        match.hit = true;
                    }
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
                    soulng::parser::Match match = ConceptParser::ConstraintExpr(lexer, ctx);
                    constraint.reset(static_cast<ConstraintNode*>(match.value));
                    *parentMatch4 = match;
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
                        return soulng::parser::Match(true, new ParenthesizedConstraintNode(s, constraint.release()));
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
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ConceptParser::AtomicConstraintExpr(lexer, ctx);
                    atomicConstraint.reset(static_cast<ConstraintNode*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, atomicConstraint.release());
                    }
                    *parentMatch8 = match;
                }
                *parentMatch7 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match ConceptParser::AtomicConstraintExpr(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<ConstraintNode> predicateConstraint;
    std::unique_ptr<ConstraintNode> isConstraint;
    std::unique_ptr<ConstraintNode> multiParamConstraint;
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
                int pos = lexer.GetPos();
                soulng::parser::Match match = ConceptParser::PredicateConstraint(lexer, ctx);
                predicateConstraint.reset(static_cast<ConstraintNode*>(match.value));
                if (match.hit)
                {
                    return soulng::parser::Match(true, predicateConstraint.release());
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = ConceptParser::IsConstraint(lexer, ctx);
                        isConstraint.reset(static_cast<ConstraintNode*>(match.value));
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, isConstraint.release());
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ConceptParser::MultiParamConstraint(lexer, ctx);
                    multiParamConstraint.reset(static_cast<ConstraintNode*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, multiParamConstraint.release());
                    }
                    *parentMatch6 = match;
                }
                *parentMatch5 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match ConceptParser::PredicateConstraint(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> invokeExpr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::lexer::Span span = lexer.GetSpan();
        soulng::parser::Match match = ExpressionParser::InvokeExpr(lexer, ctx);
        invokeExpr.reset(static_cast<Node*>(match.value));
        if (match.hit)
        {
            return soulng::parser::Match(true, new PredicateConstraintNode(span, invokeExpr.release()));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ConceptParser::IsConstraint(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<Node> type;
    std::unique_ptr<Node> conceptOrTypeName;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                type.reset(static_cast<Node*>(match.value));
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
                soulng::parser::Match match(false);
                if (*lexer == IS)
                {
                    ++lexer;
                    match.hit = true;
                }
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ConceptParser::ConceptOrTypeName(lexer, ctx);
                    conceptOrTypeName.reset(static_cast<Node*>(match.value));
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, U"concept or type name");
                    }
                }
                if (match.hit)
                {
                    s.end = span.end;
                    return soulng::parser::Match(true, new IsConstraintNode(s, type.release(), conceptOrTypeName.release()));
                }
                *parentMatch5 = match;
            }
            *parentMatch4 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ConceptParser::ConceptOrTypeName(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<Node> conceptOrTypeName;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
        conceptOrTypeName.reset(static_cast<Node*>(match.value));
        if (match.hit)
        {
            return soulng::parser::Match(true, conceptOrTypeName.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ConceptParser::MultiParamConstraint(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<MultiParamConstraintNode> constraint = std::unique_ptr<MultiParamConstraintNode>();
    std::unique_ptr<IdentifierNode> id;
    std::unique_ptr<Node> typeExpr;
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
                    int pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = IdentifierParser::QualifiedId(lexer);
                    id.reset(static_cast<IdentifierNode*>(match.value));
                    if (match.hit)
                    {
                        constraint.reset(new MultiParamConstraintNode(span, id.release()));
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
                    if (*lexer == LANGLE)
                    {
                        ++lexer;
                        match.hit = true;
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
            soulng::parser::Match* parentMatch5 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch7 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                        typeExpr.reset(static_cast<Node*>(match.value));
                        if (match.hit)
                        {
                            constraint->AddTypeExpr(typeExpr.release());
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
                        soulng::parser::Match match(true);
                        soulng::parser::Match* parentMatch9 = &match;
                        {
                            while (true)
                            {
                                int save = lexer.GetPos();
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch10 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == COMMA)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        *parentMatch10 = match;
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
                                                soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                                                typeExpr.reset(static_cast<Node*>(match.value));
                                                if (match.hit)
                                                {
                                                    constraint->AddTypeExpr(typeExpr.release());
                                                }
                                                *parentMatch12 = match;
                                            }
                                            *parentMatch11 = match;
                                        }
                                        *parentMatch10 = match;
                                    }
                                    if (match.hit)
                                    {
                                        *parentMatch9 = match;
                                    }
                                    else
                                    {
                                        lexer.SetPos(save);
                                        break;
                                    }
                                }
                            }
                        }
                        *parentMatch8 = match;
                    }
                    *parentMatch6 = match;
                }
                *parentMatch5 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
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
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RANGLE)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RANGLE)));
                    }
                }
                if (match.hit)
                {
                    constraint->SetSpanEnd(span.end);
                    return soulng::parser::Match(true, constraint.release());
                }
                *parentMatch14 = match;
            }
            *parentMatch13 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ConceptParser::Axiom(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::ConceptNode* concept)
{
    std::unique_ptr<AxiomNode> axiom = std::unique_ptr<AxiomNode>();
    Span axiomSpan = Span();
    Span beginBraceSpan = Span();
    Span endBraceSpan = Span();
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
                                    int pos = lexer.GetPos();
                                    soulng::lexer::Span span = lexer.GetSpan();
                                    soulng::parser::Match match(false);
                                    if (*lexer == AXIOM)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        axiomSpan = span;
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
                                    soulng::parser::Match match(true);
                                    int save = lexer.GetPos();
                                    soulng::parser::Match* parentMatch9 = &match;
                                    {
                                        soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                        id.reset(static_cast<IdentifierNode*>(match.value));
                                        if (match.hit)
                                        {
                                            *parentMatch9 = match;
                                        }
                                        else
                                        {
                                            lexer.SetPos(save);
                                        }
                                    }
                                    *parentMatch8 = match;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch10 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch11 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(true);
                                    if (match.hit)
                                    {
                                        axiom.reset(new AxiomNode(axiomSpan, id.release()));
                                    }
                                    *parentMatch11 = match;
                                }
                                *parentMatch10 = match;
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
                                soulng::parser::Match match = ParameterParser::ParameterList(lexer, ctx, axiom.get());
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
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch15 = &match;
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
                            *parentMatch15 = match;
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
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = ConceptParser::AxiomBody(lexer, ctx, axiom.get());
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, U"axiom body");
                        }
                    }
                    *parentMatch16 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
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
                    }
                    *parentMatch18 = match;
                }
                *parentMatch17 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            axiom->SetBeginBraceSpan(beginBraceSpan);
            axiom->SetEndBraceSpan(endBraceSpan);
            concept->AddAxiom(axiom.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ConceptParser::AxiomBody(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::AxiomNode* axiom)
{
    std::unique_ptr<AxiomStatementNode> stmt;
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
                    soulng::parser::Match match = ConceptParser::AxiomStatement(lexer, ctx);
                    stmt.reset(static_cast<AxiomStatementNode*>(match.value));
                    if (match.hit)
                    {
                        axiom->AddStatement(stmt.release());
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

soulng::parser::Match ConceptParser::AxiomStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<Node> expr;
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                expr.reset(static_cast<Node*>(match.value));
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
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
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
                        s.end = span.end;
                    }
                    *parentMatch4 = match;
                }
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new AxiomStatementNode(s, expr.release(), lexer.GetMatch(s)));
        }
        *parentMatch0 = match;
    }
    return match;
}
