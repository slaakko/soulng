#include "CppDeclaratorParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <soulng/spg/CppExpressionParser.hpp>
#include <soulng/spg/CppDeclarationParser.hpp>
#include <soulng/spg/ParserFileLexer.hpp>
#include <soulng/spg/ParserFileTokens.hpp>
#include <soulng/util/TextUtils.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/soulng/spg/CppDeclaratorParser.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace soulng::lexer;
using namespace ParserFileTokens;

soulng::parser::Match CppDeclaratorParser::InitDeclaratorList(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::InitDeclaratorList> initDeclaratorList = std::unique_ptr<soulng::cppcode::InitDeclaratorList>();
    std::unique_ptr<soulng::cppcode::InitDeclarator> initDeclarator;
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
                soulng::parser::Match match(true);
                if (match.hit)
                {
                    initDeclaratorList.reset(new soulng::cppcode::InitDeclaratorList);
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
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = CppDeclaratorParser::InitDeclarator(lexer);
                        initDeclarator.reset(static_cast<soulng::cppcode::InitDeclarator*>(match.value));
                        if (match.hit)
                        {
                            initDeclaratorList->Add(initDeclarator.release());
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
                        soulng::parser::Match* parentMatch7 = &match;
                        {
                            while (true)
                            {
                                int save = lexer.GetPos();
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == COMMA)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
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
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match = CppDeclaratorParser::InitDeclarator(lexer);
                                                initDeclarator.reset(static_cast<soulng::cppcode::InitDeclarator*>(match.value));
                                                if (match.hit)
                                                {
                                                    initDeclaratorList->Add(initDeclarator.release());
                                                }
                                                *parentMatch10 = match;
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
                    *parentMatch4 = match;
                }
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, initDeclaratorList.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppDeclaratorParser::InitDeclarator(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::parser::Value<std::u32string>> declarator;
    std::unique_ptr<soulng::cppcode::Initializer> initializer;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match = CppDeclaratorParser::Declarator(lexer);
            declarator.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(true);
                int save = lexer.GetPos();
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match = CppDeclaratorParser::Initializer(lexer);
                    initializer.reset(static_cast<soulng::cppcode::Initializer*>(match.value));
                    if (match.hit)
                    {
                        *parentMatch3 = match;
                    }
                    else
                    {
                        lexer.SetPos(save);
                    }
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::cppcode::InitDeclarator(declarator->value, initializer.release()));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppDeclaratorParser::Declarator(ParserFileLexer& lexer)
{
    Span s = Span();
    std::unique_ptr<soulng::parser::Value<std::u32string>> declarator;
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match = CppDeclaratorParser::DirectDeclarator(lexer);
                if (match.hit)
                {
                    s = span;
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
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match = CppDeclaratorParser::PtrOperator(lexer);
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
                                soulng::parser::Match match = CppDeclaratorParser::Declarator(lexer);
                                declarator.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                                if (match.hit)
                                {
                                    s.end = span.end;
                                }
                                *parentMatch7 = match;
                            }
                            *parentMatch6 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch1 = match;
            }
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::parser::Value<std::u32string>(lexer.GetMatch(s)));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppDeclaratorParser::DirectDeclarator(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr;
    std::unique_ptr<soulng::parser::Value<std::u32string>> declarator;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match = CppDeclaratorParser::DeclaratorId(lexer);
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(true);
            soulng::parser::Match* parentMatch2 = &match;
            {
                while (true)
                {
                    int save = lexer.GetPos();
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch3 = &match;
                        {
                            int save = lexer.GetPos();
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch4 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch5 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    if (*lexer == LBRACKET)
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
                                        soulng::parser::Match match(true);
                                        int save = lexer.GetPos();
                                        soulng::parser::Match* parentMatch7 = &match;
                                        {
                                            soulng::parser::Match match = CppExpressionParser::ConstantExpression(lexer);
                                            expr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
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
                                    if (*lexer == RBRACKET)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    *parentMatch8 = match;
                                }
                                *parentMatch4 = match;
                            }
                            *parentMatch3 = match;
                            if (!match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch9 = &match;
                                lexer.SetPos(save);
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch10 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch11 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            if (*lexer == LPAREN)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            *parentMatch11 = match;
                                        }
                                        if (match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch12 = &match;
                                            {
                                                soulng::parser::Match match = CppDeclaratorParser::Declarator(lexer);
                                                declarator.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                                                *parentMatch12 = match;
                                            }
                                            *parentMatch11 = match;
                                        }
                                        *parentMatch10 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch13 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            if (*lexer == RPAREN)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            *parentMatch13 = match;
                                        }
                                        *parentMatch10 = match;
                                    }
                                    *parentMatch9 = match;
                                }
                                *parentMatch3 = match;
                            }
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
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppDeclaratorParser::DeclaratorId(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::IdExpr> idExpr;
    std::unique_ptr<soulng::cppcode::TypeName> typeName;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match = CppExpressionParser::IdExpression(lexer);
        idExpr.reset(static_cast<soulng::cppcode::IdExpr*>(match.value));
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch1 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match = CppDeclarationParser::TypeName(lexer);
                typeName.reset(static_cast<soulng::cppcode::TypeName*>(match.value));
                *parentMatch1 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match CppDeclaratorParser::TypeId(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::TypeId> typeId = std::unique_ptr<soulng::cppcode::TypeId>();
    std::unique_ptr<soulng::cppcode::TypeName> typeName;
    std::unique_ptr<soulng::parser::Value<std::u32string>> abstractDeclarator;
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
                typeId.reset(new soulng::cppcode::TypeId);
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
                        int save = lexer.GetPos();
                        soulng::parser::Match match = CppDeclaratorParser::TypeSpecifierSeq(lexer, typeId.get());
                        *parentMatch5 = match;
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
                                    soulng::parser::Match match = CppDeclarationParser::TypeName(lexer);
                                    typeName.reset(static_cast<soulng::cppcode::TypeName*>(match.value));
                                    if (match.hit)
                                    {
                                        typeId->Add(typeName.release());
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                    }
                    *parentMatch4 = match;
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
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch10 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = CppDeclaratorParser::AbstractDeclarator(lexer);
                                abstractDeclarator.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                                if (match.hit)
                                {
                                    typeId->Declarator() = abstractDeclarator->value;
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
                            }
                        }
                        *parentMatch8 = match;
                    }
                    *parentMatch4 = match;
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, typeId.release());
                }
                *parentMatch3 = match;
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppDeclaratorParser::Type(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::Type> type = std::unique_ptr<soulng::cppcode::Type>();
    std::unique_ptr<soulng::cppcode::TypeSpecifier> typeSpecifier;
    std::unique_ptr<soulng::cppcode::TypeName> typeName;
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
                type.reset(new soulng::cppcode::Type);
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
                    int save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = CppDeclarationParser::TypeSpecifier(lexer);
                            typeSpecifier.reset(static_cast<soulng::cppcode::TypeSpecifier*>(match.value));
                            if (match.hit)
                            {
                                type->Add(typeSpecifier.release());
                            }
                            *parentMatch6 = match;
                        }
                        *parentMatch5 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(true);
                        soulng::parser::Match* parentMatch7 = &match;
                        while (true)
                        {
                            int save = lexer.GetPos();
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch8 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = CppDeclarationParser::TypeSpecifier(lexer);
                                    typeSpecifier.reset(static_cast<soulng::cppcode::TypeSpecifier*>(match.value));
                                    if (match.hit)
                                    {
                                        type->Add(typeSpecifier.release());
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
                    *parentMatch4 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch9 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch10 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = CppDeclarationParser::TypeName(lexer);
                                typeName.reset(static_cast<soulng::cppcode::TypeName*>(match.value));
                                if (match.hit)
                                {
                                    type->Add(typeName.release());
                                }
                                *parentMatch10 = match;
                            }
                            *parentMatch9 = match;
                        }
                        *parentMatch4 = match;
                    }
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, type.release());
                }
                *parentMatch3 = match;
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppDeclaratorParser::TypeSpecifierSeq(ParserFileLexer& lexer, soulng::cppcode::TypeId* typeId)
{
    std::unique_ptr<soulng::cppcode::TypeSpecifier> typeSpecifier;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match = CppDeclarationParser::TypeSpecifier(lexer);
            typeSpecifier.reset(static_cast<soulng::cppcode::TypeSpecifier*>(match.value));
            if (match.hit)
            {
                typeId->Add(typeSpecifier.release());
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(true);
        soulng::parser::Match* parentMatch2 = &match;
        while (true)
        {
            int save = lexer.GetPos();
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppDeclarationParser::TypeSpecifier(lexer);
                    typeSpecifier.reset(static_cast<soulng::cppcode::TypeSpecifier*>(match.value));
                    if (match.hit)
                    {
                        typeId->Add(typeSpecifier.release());
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
    return match;
}

soulng::parser::Match CppDeclaratorParser::AbstractDeclarator(ParserFileLexer& lexer)
{
    Span s = Span();
    std::unique_ptr<soulng::parser::Value<std::u32string>> abstractDeclarator;
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
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match = CppDeclaratorParser::PtrOperator(lexer);
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
                    soulng::parser::Match match(true);
                    int save = lexer.GetPos();
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match = CppDeclaratorParser::AbstractDeclarator(lexer);
                            abstractDeclarator.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                            if (match.hit)
                            {
                                s.end = span.end;
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
                        }
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
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
                        soulng::lexer::Span span = lexer.GetSpan();
                        soulng::parser::Match match = CppDeclaratorParser::DirectAbstractDeclarator(lexer);
                        if (match.hit)
                        {
                            s = span;
                        }
                        *parentMatch8 = match;
                    }
                    *parentMatch7 = match;
                }
                *parentMatch1 = match;
            }
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::parser::Value<std::u32string>(soulng::util::Trim(lexer.GetMatch(s))));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppDeclaratorParser::DirectAbstractDeclarator(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::CppObject> expr;
    std::unique_ptr<soulng::parser::Value<std::u32string>> abstractDeclarator;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int save = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    if (*lexer == LBRACKET)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(true);
                        int save = lexer.GetPos();
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match = CppExpressionParser::ConstantExpression(lexer);
                            expr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
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
                    if (*lexer == RBRACKET)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch6 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
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
                            if (*lexer == LPAREN)
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
                                soulng::parser::Match match = CppDeclaratorParser::AbstractDeclarator(lexer);
                                abstractDeclarator.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                                *parentMatch10 = match;
                            }
                            *parentMatch9 = match;
                        }
                        *parentMatch8 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch11 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == RPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch11 = match;
                        }
                        *parentMatch8 = match;
                    }
                    *parentMatch7 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(true);
        soulng::parser::Match* parentMatch12 = &match;
        while (true)
        {
            int save = lexer.GetPos();
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch13 = &match;
                {
                    int save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch14 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch15 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == LBRACKET)
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
                                soulng::parser::Match match(true);
                                int save = lexer.GetPos();
                                soulng::parser::Match* parentMatch17 = &match;
                                {
                                    soulng::parser::Match match = CppExpressionParser::ConstantExpression(lexer);
                                    expr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
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
                            *parentMatch15 = match;
                        }
                        *parentMatch14 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch18 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == RBRACKET)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch18 = match;
                        }
                        *parentMatch14 = match;
                    }
                    *parentMatch13 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch19 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch20 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch21 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    if (*lexer == LPAREN)
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
                                        soulng::parser::Match match = CppDeclaratorParser::AbstractDeclarator(lexer);
                                        abstractDeclarator.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                                        *parentMatch22 = match;
                                    }
                                    *parentMatch21 = match;
                                }
                                *parentMatch20 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch23 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    if (*lexer == RPAREN)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    *parentMatch23 = match;
                                }
                                *parentMatch20 = match;
                            }
                            *parentMatch19 = match;
                        }
                        *parentMatch13 = match;
                    }
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
    return match;
}

soulng::parser::Match CppDeclaratorParser::PtrOperator(ParserFileLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            if (*lexer == STAR)
            {
                ++lexer;
                match.hit = true;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(true);
                int save = lexer.GetPos();
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match = CppDeclaratorParser::CVQualifierSeq(lexer);
                    if (match.hit)
                    {
                        *parentMatch3 = match;
                    }
                    else
                    {
                        lexer.SetPos(save);
                    }
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch4 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                if (*lexer == AMP)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch4 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match CppDeclaratorParser::CVQualifierSeq(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::TypeSpecifier> cvQualifier;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match = CppDeclarationParser::CVQualifier(lexer);
        cvQualifier.reset(static_cast<soulng::cppcode::TypeSpecifier*>(match.value));
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(true);
        soulng::parser::Match* parentMatch1 = &match;
        while (true)
        {
            int save = lexer.GetPos();
            {
                soulng::parser::Match match = CppDeclarationParser::CVQualifier(lexer);
                cvQualifier.reset(static_cast<soulng::cppcode::TypeSpecifier*>(match.value));
                if (match.hit)
                {
                    *parentMatch1 = match;
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

soulng::parser::Match CppDeclaratorParser::Initializer(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::Initializer> initializer = std::unique_ptr<soulng::cppcode::Initializer>();
    std::unique_ptr<soulng::cppcode::AssignInit> initializerClause;
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
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = CppDeclaratorParser::InitializerClause(lexer);
                        initializerClause.reset(static_cast<soulng::cppcode::AssignInit*>(match.value));
                        if (match.hit)
                        {
                            initializer.reset(new soulng::cppcode::Initializer(initializerClause.release()));
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch5 = &match;
                lexer.SetPos(save);
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
                                soulng::parser::Match match(false);
                                if (*lexer == LPAREN)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    initializer.reset(new soulng::cppcode::Initializer(nullptr));
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
                                soulng::parser::Match match = CppExpressionParser::ExpressionList(lexer, initializer.get());
                                *parentMatch9 = match;
                            }
                            *parentMatch7 = match;
                        }
                        *parentMatch6 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch10 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == RPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch10 = match;
                        }
                        *parentMatch6 = match;
                    }
                    *parentMatch5 = match;
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

soulng::parser::Match CppDeclaratorParser::InitializerClause(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::AssignInit> assignInit = std::unique_ptr<soulng::cppcode::AssignInit>();
    std::unique_ptr<soulng::cppcode::CppObject> expr;
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
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppExpressionParser::AssignmentExpression(lexer);
                    expr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    if (match.hit)
                    {
                        assignInit.reset(new soulng::cppcode::AssignInit(expr.release()));
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
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    if (*lexer == LBRACE)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        assignInit.reset(new soulng::cppcode::AssignInit(nullptr));
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
                                    soulng::parser::Match match = CppDeclaratorParser::InitializerList(lexer, assignInit.get());
                                    *parentMatch8 = match;
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
                                if (*lexer == RBRACE)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch9 = match;
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
                soulng::parser::Match* parentMatch10 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch11 = &match;
                    {
                        soulng::parser::Match match(false);
                        if (*lexer == LBRACE)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        *parentMatch11 = match;
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
                                soulng::parser::Match match(false);
                                if (*lexer == RBRACE)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    assignInit.reset(new soulng::cppcode::AssignInit(nullptr));
                                }
                                *parentMatch13 = match;
                            }
                            *parentMatch12 = match;
                        }
                        *parentMatch11 = match;
                    }
                    *parentMatch10 = match;
                }
                *parentMatch1 = match;
            }
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, assignInit.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppDeclaratorParser::InitializerList(ParserFileLexer& lexer, soulng::cppcode::AssignInit* init)
{
    std::unique_ptr<soulng::cppcode::AssignInit> initializerClause;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match = CppDeclaratorParser::InitializerClause(lexer);
            initializerClause.reset(static_cast<soulng::cppcode::AssignInit*>(match.value));
            if (match.hit)
            {
                init->Add(initializerClause.release());
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
                                    soulng::parser::Match match = CppDeclaratorParser::InitializerClause(lexer);
                                    initializerClause.reset(static_cast<soulng::cppcode::AssignInit*>(match.value));
                                    if (match.hit)
                                    {
                                        init->Add(initializerClause.release());
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