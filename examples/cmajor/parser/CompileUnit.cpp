#include "CompileUnit.hpp"
#include <soulng/util/Unicode.hpp>
#include <cmajor/parser/Typedef.hpp>
#include <cmajor/parser/Identifier.hpp>
#include <cmajor/parser/Concept.hpp>
#include <cmajor/parser/Function.hpp>
#include <cmajor/parser/Class.hpp>
#include <cmajor/parser/Interface.hpp>
#include <cmajor/parser/Enumeration.hpp>
#include <cmajor/parser/Constant.hpp>
#include <cmajor/parser/Delegate.hpp>
#include <cmajor/parser/GlobalVariable.hpp>
#include <cmajor/lexer/CmajorLexer.hpp>
#include <cmajor/lexer/CmajorTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/CompileUnit.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace cmajor::ast;
using namespace CmajorTokens;

std::unique_ptr<cmajor::ast::CompileUnitNode> CompileUnitParser::Parse(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<cmajor::ast::CompileUnitNode> value;
    ++lexer;
    int pos = lexer.GetPos();
    soulng::parser::Match match = CompileUnitParser::CompileUnit(lexer, ctx);
    value.reset(static_cast<cmajor::ast::CompileUnitNode*>(match.value));
    if (match.hit)
    {
        if (*lexer == soulng::lexer::END)
        {
            return value;
        }
        else
        {
            lexer.ThrowExpectationFailure(lexer.GetPos(), ToUtf32(GetTokenInfo(soulng::lexer::END)));
        }
    }
    else
    {
        lexer.ThrowExpectationFailure(pos, U"compile unit");
    }
    return value;
}

soulng::parser::Match CompileUnitParser::CompileUnit(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<CompileUnitNode> compileUnit = std::unique_ptr<CompileUnitNode>();
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::lexer::Span span = lexer.GetSpan();
            soulng::parser::Match match(true);
            if (match.hit)
            {
                compileUnit.reset(new CompileUnitNode(span, lexer.FileName()));
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
                soulng::parser::Match match = CompileUnitParser::NamespaceContent(lexer, ctx, compileUnit.get(), compileUnit->GlobalNs());
                if (match.hit)
                {
                    return soulng::parser::Match(true, compileUnit.release());
                }
                *parentMatch3 = match;
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CompileUnitParser::NamespaceContent(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::CompileUnitNode* cu, cmajor::ast::NamespaceNode* ns)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match = CompileUnitParser::UsingDirectives(lexer, ctx, ns);
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match = CompileUnitParser::Definitions(lexer, ctx, cu, ns);
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CompileUnitParser::UsingDirectives(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::NamespaceNode* ns)
{
    soulng::parser::Match match(true);
    soulng::parser::Match* parentMatch0 = &match;
    {
        while (true)
        {
            int save = lexer.GetPos();
            {
                soulng::parser::Match match = CompileUnitParser::UsingDirective(lexer, ctx, ns);
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

soulng::parser::Match CompileUnitParser::UsingDirective(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::NamespaceNode* ns)
{
    std::unique_ptr<Node> usingAlias;
    std::unique_ptr<Node> usingNs;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match = CompileUnitParser::UsingAliasDirective(lexer);
            usingAlias.reset(static_cast<Node*>(match.value));
            if (match.hit)
            {
                ns->AddMember(usingAlias.release());
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
                    soulng::parser::Match match = CompileUnitParser::UsingNamespaceDirective(lexer, ctx);
                    usingNs.reset(static_cast<Node*>(match.value));
                    if (match.hit)
                    {
                        ns->AddMember(usingNs.release());
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

soulng::parser::Match CompileUnitParser::UsingAliasDirective(CmajorLexer& lexer)
{
    Span s = Span();
    std::unique_ptr<IdentifierNode> id;
    std::unique_ptr<IdentifierNode> qid;
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
                        int pos = lexer.GetPos();
                        soulng::lexer::Span span = lexer.GetSpan();
                        soulng::parser::Match match(false);
                        if (*lexer == USING)
                        {
                            ++lexer;
                            match.hit = true;
                        }
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
                        soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                        id.reset(static_cast<IdentifierNode*>(match.value));
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
                    soulng::parser::Match match(false);
                    if (*lexer == ASSIGN)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch6 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch7 = &match;
            {
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = IdentifierParser::QualifiedId(lexer);
                    qid.reset(static_cast<IdentifierNode*>(match.value));
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, U"identifier");
                    }
                }
                *parentMatch7 = match;
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
                    return soulng::parser::Match(true, new AliasNode(s, id.release(), qid.release()));
                }
                *parentMatch9 = match;
            }
            *parentMatch8 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CompileUnitParser::UsingNamespaceDirective(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<IdentifierNode> ns;
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
                if (*lexer == USING)
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
                    soulng::parser::Match match = IdentifierParser::QualifiedId(lexer);
                    ns.reset(static_cast<IdentifierNode*>(match.value));
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, U"identifier");
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
                    return soulng::parser::Match(true, new NamespaceImportNode(s, ns.release()));
                }
                *parentMatch5 = match;
            }
            *parentMatch4 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CompileUnitParser::Definitions(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::CompileUnitNode* cu, cmajor::ast::NamespaceNode* ns)
{
    std::unique_ptr<Node> definition;
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
                    soulng::parser::Match match = CompileUnitParser::Definition(lexer, ctx, cu, ns);
                    definition.reset(static_cast<Node*>(match.value));
                    if (match.hit)
                    {
                        ns->AddMember(definition.release());
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

soulng::parser::Match CompileUnitParser::Definition(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::CompileUnitNode* cu, cmajor::ast::NamespaceNode* ns)
{
    std::unique_ptr<NamespaceNode> nsDefinition;
    std::unique_ptr<TypedefNode> typedefDeclaration;
    std::unique_ptr<ConceptNode> conceptDefinition;
    std::unique_ptr<FunctionNode> functionDefinition;
    std::unique_ptr<ClassNode> classDefinition;
    std::unique_ptr<InterfaceNode> interfaceDefinition;
    std::unique_ptr<EnumTypeNode> enumTypeDefinition;
    std::unique_ptr<ConstantNode> constantDefinition;
    std::unique_ptr<DelegateNode> delegateDefinition;
    std::unique_ptr<ClassDelegateNode> classDelegateDefinition;
    std::unique_ptr<GlobalVariableNode> globalVariableDefinition;
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
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match = CompileUnitParser::NamespaceDefinition(lexer, ctx, cu, ns);
                                                nsDefinition.reset(static_cast<NamespaceNode*>(match.value));
                                                if (match.hit)
                                                {
                                                    return soulng::parser::Match(true, nsDefinition.release());
                                                }
                                                *parentMatch10 = match;
                                            }
                                            *parentMatch9 = match;
                                            if (!match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch11 = &match;
                                                lexer.SetPos(save);
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch12 = &match;
                                                    {
                                                        int pos = lexer.GetPos();
                                                        soulng::parser::Match match = CompileUnitParser::TypedefDeclaration(lexer, ctx);
                                                        typedefDeclaration.reset(static_cast<TypedefNode*>(match.value));
                                                        if (match.hit)
                                                        {
                                                            return soulng::parser::Match(true, typedefDeclaration.release());
                                                        }
                                                        *parentMatch12 = match;
                                                    }
                                                    *parentMatch11 = match;
                                                }
                                                *parentMatch9 = match;
                                            }
                                        }
                                        *parentMatch8 = match;
                                        if (!match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch13 = &match;
                                            lexer.SetPos(save);
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch14 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = CompileUnitParser::ConceptDefinition(lexer, ctx);
                                                    conceptDefinition.reset(static_cast<ConceptNode*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        return soulng::parser::Match(true, conceptDefinition.release());
                                                    }
                                                    *parentMatch14 = match;
                                                }
                                                *parentMatch13 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                    }
                                    *parentMatch7 = match;
                                    if (!match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch15 = &match;
                                        lexer.SetPos(save);
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch16 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match = CompileUnitParser::FunctionDefinition(lexer, ctx);
                                                functionDefinition.reset(static_cast<FunctionNode*>(match.value));
                                                if (match.hit)
                                                {
                                                    return soulng::parser::Match(true, functionDefinition.release());
                                                }
                                                *parentMatch16 = match;
                                            }
                                            *parentMatch15 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                }
                                *parentMatch6 = match;
                                if (!match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch17 = &match;
                                    lexer.SetPos(save);
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch18 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = CompileUnitParser::ClassDefinition(lexer, ctx);
                                            classDefinition.reset(static_cast<ClassNode*>(match.value));
                                            if (match.hit)
                                            {
                                                return soulng::parser::Match(true, classDefinition.release());
                                            }
                                            *parentMatch18 = match;
                                        }
                                        *parentMatch17 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                            }
                            *parentMatch5 = match;
                            if (!match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch19 = &match;
                                lexer.SetPos(save);
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch20 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match = CompileUnitParser::InterfaceDefinition(lexer, ctx);
                                        interfaceDefinition.reset(static_cast<InterfaceNode*>(match.value));
                                        if (match.hit)
                                        {
                                            return soulng::parser::Match(true, interfaceDefinition.release());
                                        }
                                        *parentMatch20 = match;
                                    }
                                    *parentMatch19 = match;
                                }
                                *parentMatch5 = match;
                            }
                        }
                        *parentMatch4 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch21 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch22 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = CompileUnitParser::EnumTypeDefinition(lexer, ctx);
                                    enumTypeDefinition.reset(static_cast<EnumTypeNode*>(match.value));
                                    if (match.hit)
                                    {
                                        return soulng::parser::Match(true, enumTypeDefinition.release());
                                    }
                                    *parentMatch22 = match;
                                }
                                *parentMatch21 = match;
                            }
                            *parentMatch4 = match;
                        }
                    }
                    *parentMatch3 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch23 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch24 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = CompileUnitParser::ConstantDefinition(lexer, ctx);
                                constantDefinition.reset(static_cast<ConstantNode*>(match.value));
                                if (match.hit)
                                {
                                    return soulng::parser::Match(true, constantDefinition.release());
                                }
                                *parentMatch24 = match;
                            }
                            *parentMatch23 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch25 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch26 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = CompileUnitParser::DelegateDefinition(lexer, ctx);
                            delegateDefinition.reset(static_cast<DelegateNode*>(match.value));
                            if (match.hit)
                            {
                                return soulng::parser::Match(true, delegateDefinition.release());
                            }
                            *parentMatch26 = match;
                        }
                        *parentMatch25 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch27 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch28 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = CompileUnitParser::ClassDelegateDefinition(lexer, ctx);
                        classDelegateDefinition.reset(static_cast<ClassDelegateNode*>(match.value));
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, classDelegateDefinition.release());
                        }
                        *parentMatch28 = match;
                    }
                    *parentMatch27 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch29 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch30 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CompileUnitParser::GlobalVariableDefinition(lexer, ctx, cu);
                    globalVariableDefinition.reset(static_cast<GlobalVariableNode*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, globalVariableDefinition.release());
                    }
                    *parentMatch30 = match;
                }
                *parentMatch29 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match CompileUnitParser::NamespaceDefinition(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::CompileUnitNode* cu, cmajor::ast::NamespaceNode* ns)
{
    std::unique_ptr<NamespaceNode> nsNode = std::unique_ptr<NamespaceNode>();
    Span s = Span();
    std::unique_ptr<IdentifierNode> nsName;
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
                        int pos = lexer.GetPos();
                        soulng::lexer::Span span = lexer.GetSpan();
                        soulng::parser::Match match(false);
                        if (*lexer == NAMESPACE)
                        {
                            ++lexer;
                            match.hit = true;
                        }
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
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match = IdentifierParser::QualifiedId(lexer);
                            nsName.reset(static_cast<IdentifierNode*>(match.value));
                            if (match.hit)
                            {
                                s.end = span.end;
                                nsNode.reset(new NamespaceNode(s, nsName.release()));
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
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CompileUnitParser::NamespaceContent(lexer, ctx, cu, nsNode.get());
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, U"namespace content");
                    }
                }
                *parentMatch8 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
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
                    return soulng::parser::Match(true, nsNode.release());
                }
                *parentMatch10 = match;
            }
            *parentMatch9 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CompileUnitParser::TypedefDeclaration(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<TypedefNode> typedefDeclaration;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match = TypedefParser::Typedef(lexer, ctx);
        typedefDeclaration.reset(static_cast<TypedefNode*>(match.value));
        if (match.hit)
        {
            return soulng::parser::Match(true, typedefDeclaration.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CompileUnitParser::ConceptDefinition(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<ConceptNode> conceptDefinition;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match = ConceptParser::Concept(lexer, ctx);
        conceptDefinition.reset(static_cast<ConceptNode*>(match.value));
        if (match.hit)
        {
            return soulng::parser::Match(true, conceptDefinition.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CompileUnitParser::FunctionDefinition(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<FunctionNode> functionDefinition;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match = FunctionParser::Function(lexer, ctx);
        functionDefinition.reset(static_cast<FunctionNode*>(match.value));
        if (match.hit)
        {
            return soulng::parser::Match(true, functionDefinition.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CompileUnitParser::ClassDefinition(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<ClassNode> classDefinition;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match = ClassParser::Class(lexer, ctx);
        classDefinition.reset(static_cast<ClassNode*>(match.value));
        if (match.hit)
        {
            return soulng::parser::Match(true, classDefinition.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CompileUnitParser::InterfaceDefinition(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<InterfaceNode> interfaceDefinition;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match = InterfaceParser::Interface(lexer, ctx);
        interfaceDefinition.reset(static_cast<InterfaceNode*>(match.value));
        if (match.hit)
        {
            return soulng::parser::Match(true, interfaceDefinition.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CompileUnitParser::EnumTypeDefinition(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<EnumTypeNode> enumTypeDefinition;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match = EnumerationParser::EnumType(lexer, ctx);
        enumTypeDefinition.reset(static_cast<EnumTypeNode*>(match.value));
        if (match.hit)
        {
            return soulng::parser::Match(true, enumTypeDefinition.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CompileUnitParser::ConstantDefinition(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<ConstantNode> constantDefinition;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match = ConstantParser::Constant(lexer, ctx);
        constantDefinition.reset(static_cast<ConstantNode*>(match.value));
        if (match.hit)
        {
            return soulng::parser::Match(true, constantDefinition.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CompileUnitParser::DelegateDefinition(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<DelegateNode> delegateDefinition;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match = DelegateParser::Delegate(lexer, ctx);
        delegateDefinition.reset(static_cast<DelegateNode*>(match.value));
        if (match.hit)
        {
            return soulng::parser::Match(true, delegateDefinition.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CompileUnitParser::ClassDelegateDefinition(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<ClassDelegateNode> classDelegateDefinition;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match = DelegateParser::ClassDelegate(lexer, ctx);
        classDelegateDefinition.reset(static_cast<ClassDelegateNode*>(match.value));
        if (match.hit)
        {
            return soulng::parser::Match(true, classDelegateDefinition.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CompileUnitParser::GlobalVariableDefinition(CmajorLexer& lexer, ParsingContext* ctx, cmajor::ast::CompileUnitNode* cu)
{
    std::unique_ptr<GlobalVariableNode> globalVariableDefinition;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match = GlobalVariableParser::GlobalVariable(lexer, ctx, cu);
        globalVariableDefinition.reset(static_cast<GlobalVariableNode*>(match.value));
        if (match.hit)
        {
            return soulng::parser::Match(true, globalVariableDefinition.release());
        }
        *parentMatch0 = match;
    }
    return match;
}
