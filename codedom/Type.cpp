// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/codedom/Type.hpp>
#include <soulng/codedom/Visitor.hpp>
#include <soulng/util/Unicode.hpp>

namespace soulng { namespace codedom {

using namespace soulng::util;
using namespace soulng::unicode;

DeclSpecifier::DeclSpecifier(const std::u32string& name_): CppObject(name_) 
{
}

Typedef::Typedef(): DeclSpecifier(U"typedef") 
{
}

void Typedef::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

TypeSpecifier::TypeSpecifier(const std::u32string& name_): DeclSpecifier(name_) 
{
}

void TypeSpecifier::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

Const::Const(): TypeSpecifier(U"const") 
{
}

Volatile::Volatile(): TypeSpecifier(U"volatile") 
{
}

TypeName::TypeName(const std::u32string& name_): TypeSpecifier(name_), isTemplate(false) 
{
}

void TypeName::AddTemplateArgument(CppObject* templateArgument) 
{ 
    Own(templateArgument);
    templateArguments.push_back(templateArgument); 
}

std::u32string TypeName::ToString() const
{
    std::u32string s(Name());
    if (isTemplate)
    {
        s.append(U"<");
        int n = int(templateArguments.size());
        for (int i = 0; i < n; ++i)
        {
            if (i > 0)
            {
                s.append(U", ");
            }
            s.append(templateArguments[i]->ToString());
        }
        s.append(U">");
    }
    return s;
}

void TypeName::Print(CodeFormatter& formatter)
{
    formatter.Write(ToUtf8(ToString()));
}

void TypeName::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

Type::Type(): CppObject(U"type") 
{
}

void Type::Add(TypeSpecifier* typeSpecifier) 
{
    Own(typeSpecifier);
    typeSpecifiers.push_back(typeSpecifier);
}

std::u32string Type::ToString() const
{
    std::u32string s;
    int n = int(typeSpecifiers.size());
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            s.append(U" ");
        }
        s.append(typeSpecifiers[i]->ToString());
    }
    return s;
}

void Type::Print(CodeFormatter& formatter)
{
    formatter.Write(ToUtf8(ToString()));
}

void Type::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

TypeId::TypeId(): CppObject(U"typeId") 
{
}

void TypeId::Add(TypeSpecifier* typeSpecifier) 
{
    Own(typeSpecifier);
    typeSpecifiers.push_back(typeSpecifier);
}

std::u32string TypeId::ToString() const
{
    std::u32string v;
    int n = int(typeSpecifiers.size());
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            v.append(U" ");
        }
        v.append(typeSpecifiers[i]->ToString());
    }
    if (!declarator.empty())
    {
        v.append(declarator);
    }
    return v;
}

void TypeId::Print(CodeFormatter& formatter)
{
    int n = int(typeSpecifiers.size());
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            formatter.Write(" ");
        }
        typeSpecifiers[i]->Print(formatter);
    }
    if (!declarator.empty())
    {
        formatter.Write(ToUtf8(declarator));
    }
}

void TypeId::PrintNonPtrType(CodeFormatter& formatter)
{
    if (IsPtrType())
    {
        int n = int(typeSpecifiers.size());
        for (int i = 0; i < n; ++i)
        {
            if (i > 0)
            {
                formatter.Write(" ");
            }
            typeSpecifiers[i]->Print(formatter);
        }
        if (!declarator.empty())
        {
            formatter.Write(ToUtf8(declarator.substr(0, declarator.size() - 1)));
        }
    }
    else
    {
        Print(formatter);
    }
}

std::u32string TypeId::Str()
{
    std::u32string str;
    int n = int(typeSpecifiers.size());
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            str.append(U", ");
        }
        str.append(typeSpecifiers[i]->Name());
    }
    if (!declarator.empty())
    {
        str.append(declarator);
    }
    return str;
}

void TypeId::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

bool TypeId::IsPtrType() const
{
    if (!declarator.empty())
    {
        return declarator.back() == '*';
    }
    else
    {
        return false;
    }
}

void StorageClassSpecifier::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} } // namespace soulng::codedom
