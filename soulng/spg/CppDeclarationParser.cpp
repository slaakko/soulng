#include "CppDeclarationParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <soulng/spg/CppDeclaratorParser.hpp>
#include <soulng/spg/CppIdentifierParser.hpp>
#include <soulng/spg/CppExpressionParser.hpp>
#include <soulng/spg/ParserFileLexer.hpp>
#include <soulng/spg/ParserFileTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/soulng/spg/CppDeclarationParser.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace soulng::lexer;
using namespace ParserFileTokens;

soulng::parser::Match CppDeclarationParser::BlockDeclaration(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::UsingObject> nsAlias;
    std::unique_ptr<soulng::cppcode::UsingObject> usingDirective;
    std::unique_ptr<soulng::cppcode::UsingObject> usingDeclaration;
    std::unique_ptr<soulng::cppcode::SimpleDeclaration> simpleDeclaration;
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
                    soulng::parser::Match match = CppDeclarationParser::NamespaceAliasDefinition(lexer);
                    nsAlias.reset(static_cast<soulng::cppcode::UsingObject*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, nsAlias.release());
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
                            soulng::parser::Match match = CppDeclarationParser::UsingDirective(lexer);
                            usingDirective.reset(static_cast<soulng::cppcode::UsingObject*>(match.value));
                            if (match.hit)
                            {
                                return soulng::parser::Match(true, usingDirective.release());
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
                        soulng::parser::Match match = CppDeclarationParser::UsingDeclaration(lexer);
                        usingDeclaration.reset(static_cast<soulng::cppcode::UsingObject*>(match.value));
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, usingDeclaration.release());
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
                    soulng::parser::Match match = CppDeclarationParser::SimpleDeclaration(lexer);
                    simpleDeclaration.reset(static_cast<soulng::cppcode::SimpleDeclaration*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, simpleDeclaration.release());
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

soulng::parser::Match CppDeclarationParser::SimpleDeclaration(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::SimpleDeclaration> simpleDeclaration = std::unique_ptr<soulng::cppcode::SimpleDeclaration>();
    std::unique_ptr<soulng::cppcode::InitDeclaratorList> initDeclaratorList;
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
                    soulng::parser::Match match(true);
                    if (match.hit)
                    {
                        simpleDeclaration.reset(new soulng::cppcode::SimpleDeclaration);
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
                        soulng::parser::Match match = CppDeclarationParser::DeclSpecifierSeq(lexer, simpleDeclaration.get());
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
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch6 = &match;
            {
                soulng::parser::Match match(true);
                int save = lexer.GetPos();
                soulng::parser::Match* parentMatch7 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch8 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = CppDeclaratorParser::InitDeclaratorList(lexer);
                        initDeclaratorList.reset(static_cast<soulng::cppcode::InitDeclaratorList*>(match.value));
                        if (match.hit)
                        {
                            simpleDeclaration->SetInitDeclaratorList(initDeclaratorList.release());
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
                soulng::parser::Match match(false);
                if (*lexer == SEMICOLON)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, simpleDeclaration.release());
                }
                *parentMatch10 = match;
            }
            *parentMatch9 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppDeclarationParser::DeclSpecifierSeq(ParserFileLexer& lexer, soulng::cppcode::SimpleDeclaration* declaration)
{
    std::unique_ptr<soulng::cppcode::DeclSpecifier> declSpecifier;
    std::unique_ptr<soulng::cppcode::TypeName> typeName;
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
                int pos = lexer.GetPos();
                soulng::parser::Match match = CppDeclarationParser::DeclSpecifier(lexer);
                declSpecifier.reset(static_cast<soulng::cppcode::DeclSpecifier*>(match.value));
                if (match.hit)
                {
                    declaration->Add(declSpecifier.release());
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(true);
            soulng::parser::Match* parentMatch3 = &match;
            while (true)
            {
                int save = lexer.GetPos();
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = CppDeclarationParser::DeclSpecifier(lexer);
                        declSpecifier.reset(static_cast<soulng::cppcode::DeclSpecifier*>(match.value));
                        if (match.hit)
                        {
                            declaration->Add(declSpecifier.release());
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
                    soulng::parser::Match match = CppDeclarationParser::TypeName(lexer);
                    typeName.reset(static_cast<soulng::cppcode::TypeName*>(match.value));
                    if (match.hit)
                    {
                        declaration->Add(typeName.release());
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

soulng::parser::Match CppDeclarationParser::DeclSpecifier(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::StorageClassSpecifier> storateClassSpecifier;
    std::unique_ptr<soulng::cppcode::TypeSpecifier> typeSpecifier;
    std::unique_ptr<soulng::cppcode::DeclSpecifier> tdef;
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
                soulng::parser::Match match = CppDeclarationParser::StorageClassSpecifier(lexer);
                storateClassSpecifier.reset(static_cast<soulng::cppcode::StorageClassSpecifier*>(match.value));
                if (match.hit)
                {
                    return soulng::parser::Match(true, storateClassSpecifier.release());
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
                        soulng::parser::Match match = CppDeclarationParser::TypeSpecifier(lexer);
                        typeSpecifier.reset(static_cast<soulng::cppcode::TypeSpecifier*>(match.value));
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, typeSpecifier.release());
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
                    soulng::parser::Match match = CppDeclarationParser::Typedef(lexer);
                    tdef.reset(static_cast<soulng::cppcode::DeclSpecifier*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, tdef.release());
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

soulng::parser::Match CppDeclarationParser::StorageClassSpecifier(ParserFileLexer& lexer)
{
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case AUTO:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::StorageClassSpecifier(U"auto"));
            }
            break;
        }
        case REGISTER:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::StorageClassSpecifier(U"register"));
            }
            break;
        }
        case STATIC:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::StorageClassSpecifier(U"static"));
            }
            break;
        }
        case EXTERN:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::StorageClassSpecifier(U"extern"));
            }
            break;
        }
        case MUTABLE:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::StorageClassSpecifier(U"mutable"));
            }
            break;
        }
    }
    return match;
}

soulng::parser::Match CppDeclarationParser::TypeSpecifier(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::TypeSpecifier> simpleTypeSpecifier;
    std::unique_ptr<soulng::cppcode::TypeSpecifier> cvQualified;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match = CppDeclarationParser::SimpleTypeSpecifier(lexer);
            simpleTypeSpecifier.reset(static_cast<soulng::cppcode::TypeSpecifier*>(match.value));
            if (match.hit)
            {
                return soulng::parser::Match(true, simpleTypeSpecifier.release());
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
                    soulng::parser::Match match = CppDeclarationParser::CVQualifier(lexer);
                    cvQualified.reset(static_cast<soulng::cppcode::TypeSpecifier*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, cvQualified.release());
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

soulng::parser::Match CppDeclarationParser::SimpleTypeSpecifier(ParserFileLexer& lexer)
{
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case CHAR:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::TypeSpecifier(U"char"));
            }
            break;
        }
        case WCHART:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::TypeSpecifier(U"wchar_t"));
            }
            break;
        }
        case BOOL:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::TypeSpecifier(U"bool"));
            }
            break;
        }
        case SHORT:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::TypeSpecifier(U"short"));
            }
            break;
        }
        case INT:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::TypeSpecifier(U"int"));
            }
            break;
        }
        case LONG:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::TypeSpecifier(U"long"));
            }
            break;
        }
        case SIGNED:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::TypeSpecifier(U"signed"));
            }
            break;
        }
        case UNSIGNED:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::TypeSpecifier(U"unsigned"));
            }
            break;
        }
        case FLOAT:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::TypeSpecifier(U"float"));
            }
            break;
        }
        case DOUBLE:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::TypeSpecifier(U"double"));
            }
            break;
        }
        case VOID:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::TypeSpecifier(U"void"));
            }
            break;
        }
    }
    return match;
}

soulng::parser::Match CppDeclarationParser::TypeName(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::TypeName> typeName = std::unique_ptr<soulng::cppcode::TypeName>();
    std::unique_ptr<soulng::parser::Value<std::u32string>> qid;
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
                soulng::parser::Match match = CppIdentifierParser::QualifiedCppId(lexer);
                qid.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                if (match.hit)
                {
                    typeName.reset(new soulng::cppcode::TypeName(qid->value));
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
                int save = lexer.GetPos();
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
                                soulng::parser::Match match(false);
                                if (*lexer == LANGLE)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    ++lexer.leftAngleCount;
                                    typeName->IsTemplate() = true;
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
                                soulng::parser::Match match = CppDeclarationParser::TemplateArgumentList(lexer, typeName.get());
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
                            soulng::parser::Match* parentMatch10 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == RANGLE)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    --lexer.leftAngleCount;
                                }
                                *parentMatch10 = match;
                            }
                            *parentMatch9 = match;
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
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, typeName.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppDeclarationParser::TemplateArgumentList(ParserFileLexer& lexer, soulng::cppcode::TypeName* typeName)
{
    std::unique_ptr<soulng::cppcode::CppObject> arg;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match = CppDeclarationParser::TemplateArgument(lexer);
            arg.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
            if (match.hit)
            {
                typeName->AddTemplateArgument(arg.release());
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
                                    soulng::parser::Match match = CppDeclarationParser::TemplateArgument(lexer);
                                    arg.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                                    if (match.hit)
                                    {
                                        typeName->AddTemplateArgument(arg.release());
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

soulng::parser::Match CppDeclarationParser::TemplateArgument(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::TypeId> typeId;
    std::unique_ptr<soulng::cppcode::CppObject> assignmentExpr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match = CppDeclaratorParser::TypeId(lexer);
            typeId.reset(static_cast<soulng::cppcode::TypeId*>(match.value));
            if (match.hit)
            {
                return soulng::parser::Match(true, typeId.release());
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
                    soulng::parser::Match match = CppExpressionParser::AssignmentExpression(lexer);
                    assignmentExpr.reset(static_cast<soulng::cppcode::CppObject*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, assignmentExpr.release());
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

soulng::parser::Match CppDeclarationParser::Typedef(ParserFileLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        if (*lexer == TYPEDEF)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::cppcode::Typedef);
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppDeclarationParser::CVQualifier(ParserFileLexer& lexer)
{
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case CONST:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::Const);
            }
            break;
        }
        case VOLATILE:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::Volatile);
            }
            break;
        }
    }
    return match;
}

soulng::parser::Match CppDeclarationParser::NamespaceAliasDefinition(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::parser::Value<std::u32string>> id;
    std::unique_ptr<soulng::parser::Value<std::u32string>> qid;
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
                        if (*lexer == NAMESPACE)
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
                            soulng::parser::Match match = CppIdentifierParser::CppIdentifier(lexer);
                            id.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
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
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch7 = &match;
                {
                    soulng::parser::Match match = CppIdentifierParser::QualifiedCppId(lexer);
                    qid.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
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
                if (*lexer == SEMICOLON)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch8 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::cppcode::NamespaceAlias(id->value, qid->value));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppDeclarationParser::UsingDeclaration(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::parser::Value<std::u32string>> qid;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            if (*lexer == USING)
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
                soulng::parser::Match match = CppIdentifierParser::QualifiedCppId(lexer);
                qid.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
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
                soulng::parser::Match match(false);
                if (*lexer == SEMICOLON)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, new soulng::cppcode::UsingDeclaration(qid->value));
                }
                *parentMatch4 = match;
            }
            *parentMatch3 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppDeclarationParser::UsingDirective(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::parser::Value<std::u32string>> ns;
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
                if (*lexer == USING)
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
                    if (*lexer == NAMESPACE)
                    {
                        ++lexer;
                        match.hit = true;
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
            soulng::parser::Match* parentMatch4 = &match;
            {
                soulng::parser::Match match = CppIdentifierParser::QualifiedCppId(lexer);
                ns.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                *parentMatch4 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
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
                soulng::parser::Match match(false);
                if (*lexer == SEMICOLON)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, new soulng::cppcode::UsingDirective(ns->value));
                }
                *parentMatch6 = match;
            }
            *parentMatch5 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}
