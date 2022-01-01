// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/Symbol.hpp>
#include <sngcpp/symbols/ContainerSymbol.hpp>
#include <sngcpp/symbols/ClassTypeSymbol.hpp>
#include <soulng/util/Sha1.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp { namespace symbols {

using namespace soulng::unicode;
using namespace soulng::util;

std::u32string ToString(SymbolAccess access)
{
    switch (access)
    {
        case SymbolAccess::public_: return U"public";
        case SymbolAccess::protected_: return U"protected";
        case SymbolAccess::private_: return U"private";
    }
    return std::u32string();
}

Symbol::Symbol(const Span& span_, const std::u32string& name_) : span(span_), name(name_), parent(nullptr), access(SymbolAccess::private_)
{
}

Symbol::~Symbol()
{
}

std::u32string Symbol::FullName()
{
    std::u32string fullName;
    if (Parent())
    {
        fullName = Parent()->FullName();
    }
    if (fullName.empty())
    {
        return Name();
    }
    else
    {
        fullName.append(U"::").append(Name());
        return fullName;
    }
}

void Symbol::SetAccess(Specifier accessSpecifier)
{
    if ((accessSpecifier & Specifier::public_) != Specifier::none)
    {
        access = SymbolAccess::public_;
    }
    else if ((accessSpecifier & Specifier::protected_) != Specifier::none)
    {
        access = SymbolAccess::protected_;
    }
    else if ((accessSpecifier & Specifier::private_) != Specifier::none)
    {
        access = SymbolAccess::private_;
    }
}

std::u32string Symbol::IdStr()
{
    return FullName();
}

std::u32string Symbol::Id()
{
    std::u32string id = KindStr();
    id.append(1, '_').append(SimpleName()).append(1, '_').append(ToUtf32(GetSha1MessageDigest(ToUtf8(IdStr()))));
    return id;
}

void Symbol::SetProjectName(const std::u32string& projectName_)
{
    projectName = projectName_;
}

std::unique_ptr<sngxml::dom::Element> Symbol::ToDomElement()
{
    std::unique_ptr<sngxml::dom::Element> element = CreateElement();
    element->SetAttribute(U"name", Name());
    element->SetAttribute(U"id", Id());
    element->SetAttribute(U"access", ToString(access));
    if (!IsNamespaceSymbol() && parent && parent->IsNamespaceSymbol())
    {
        element->SetAttribute(U"project", projectName);
    }
    std::unique_ptr<sngxml::dom::Element> namespaces = Namespaces();
    if (namespaces)
    {
        element->AppendChild(std::unique_ptr<sngxml::dom::Node>(namespaces.release()));
    }
    std::unique_ptr<sngxml::dom::Element> classes = Classes();
    if (classes)
    {
        element->AppendChild(std::unique_ptr<sngxml::dom::Node>(classes.release()));
    }
    std::unique_ptr<sngxml::dom::Element> constructors = Constructors();
    if (constructors)
    {
        element->AppendChild(std::unique_ptr<sngxml::dom::Node>(constructors.release()));
    }
    std::unique_ptr<sngxml::dom::Element> functions = Functions();
    if (functions)
    {
        element->AppendChild(std::unique_ptr<sngxml::dom::Node>(functions.release()));
    }
    std::unique_ptr<sngxml::dom::Element> enumTypes = EnumTypes();
    if (enumTypes)
    {
        element->AppendChild(std::unique_ptr<sngxml::dom::Node>(enumTypes.release()));
    }
    std::unique_ptr<sngxml::dom::Element> enumerators = Enumerators();
    if (enumerators)
    {
        element->AppendChild(std::unique_ptr<sngxml::dom::Node>(enumerators.release()));
    }
    std::unique_ptr<sngxml::dom::Element> typedefs = Typedefs();
    if (typedefs)
    {
        element->AppendChild(std::unique_ptr<sngxml::dom::Node>(typedefs.release()));
    }
    std::unique_ptr<sngxml::dom::Element> variables = Variables();
    if (variables)
    {
        element->AppendChild(std::unique_ptr<sngxml::dom::Node>(variables.release()));
    }
    std::unique_ptr<sngxml::dom::Element> grammars = Grammars();
    if (grammars)
    {
        element->AppendChild(std::unique_ptr<sngxml::dom::Node>(grammars.release()));
    }
    return element;
}

std::unique_ptr<sngxml::dom::Element> Symbol::Namespaces()
{
    return std::unique_ptr<sngxml::dom::Element>();
}

std::unique_ptr<sngxml::dom::Element> Symbol::Classes()
{
    return std::unique_ptr<sngxml::dom::Element>();
}

std::unique_ptr<sngxml::dom::Element> Symbol::Constructors()
{
    return std::unique_ptr<sngxml::dom::Element>();
}

std::unique_ptr<sngxml::dom::Element> Symbol::Functions()
{
    return std::unique_ptr<sngxml::dom::Element>();
}

std::unique_ptr<sngxml::dom::Element> Symbol::EnumTypes()
{
    return std::unique_ptr<sngxml::dom::Element>();
}

std::unique_ptr<sngxml::dom::Element> Symbol::Enumerators()
{
    return std::unique_ptr<sngxml::dom::Element>();
}

std::unique_ptr<sngxml::dom::Element> Symbol::Typedefs()
{
    return std::unique_ptr<sngxml::dom::Element>();
}

std::unique_ptr<sngxml::dom::Element> Symbol::Variables()
{
    return std::unique_ptr<sngxml::dom::Element>();
}

std::unique_ptr<sngxml::dom::Element> Symbol::Grammars()
{
    return std::unique_ptr<sngxml::dom::Element>();
}

ClassTypeSymbol* Symbol::Class()
{
    if (IsClassTypeSymbol())
    {
        return static_cast<ClassTypeSymbol*>(this);
    }
    else if (parent)
    {
        return parent->Class();
    }
    else
    {
        return nullptr;
    }
}

} } // namespace sngcpp::symbols
