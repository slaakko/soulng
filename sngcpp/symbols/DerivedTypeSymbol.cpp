// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/DerivedTypeSymbol.hpp>
#include <limits>

namespace sngcpp { namespace symbols {

bool HasConstDerivation(const std::vector<Derivation>& derivations)
{
    for (Derivation derivation : derivations)
    {
        if (derivation == Derivation::const_) return true;
    }
    return false;
}

bool HasVolatileDerivation(const std::vector<Derivation>& derivations)
{
    for (Derivation derivation : derivations)
    {
        if (derivation == Derivation::volatile_) return true;
    }
    return false;
}

bool HasLValueRefDerivation(const std::vector<Derivation>& derivations)
{
    for (Derivation derivation : derivations)
    {
        if (derivation == Derivation::lvalueRef) return true;
    }
    return false;
}

bool HasRValueRefDerivation(const std::vector<Derivation>& derivations)
{
    for (Derivation derivation : derivations)
    {
        if (derivation == Derivation::rvalueRef) return true;
    }
    return false;
}

int CountPointerDerivations(const std::vector<Derivation>& derivations)
{
    int n = 0;
    for (Derivation derivation : derivations)
    {
        if (derivation == Derivation::ptr) ++n;
    }
    return n;
}

std::vector<Derivation> UnifyDerivations(const std::vector<Derivation>& left, const std::vector<Derivation>& right)
{
    std::vector<Derivation> unifiedDerivations;
    if (HasConstDerivation(left) || HasConstDerivation(right))
    {
        unifiedDerivations.push_back(Derivation::const_);
    }
    if (HasVolatileDerivation(left) || HasVolatileDerivation(right))
    {
        unifiedDerivations.push_back(Derivation::volatile_);
    }
    unifiedDerivations.push_back(Derivation::base);
    int numPointers = CountPointerDerivations(left) + CountPointerDerivations(right);
    for (int i = 0; i < numPointers; ++i)
    {
        unifiedDerivations.push_back(Derivation::ptr);
    }
    if (HasLValueRefDerivation(left))
    {
        unifiedDerivations.push_back(Derivation::lvalueRef);
    }
    else if (HasRValueRefDerivation(left))
    {
        unifiedDerivations.push_back(Derivation::rvalueRef);
    }
    else if (HasLValueRefDerivation(right))
    {
        unifiedDerivations.push_back(Derivation::lvalueRef);
    }
    else if (HasRValueRefDerivation(right))
    {
        unifiedDerivations.push_back(Derivation::rvalueRef);
    }
    return unifiedDerivations;
}

std::u32string MakeDerivedTypeId(const std::vector<Derivation>& derivations, TypeSymbol* baseType)
{
    std::u32string id;
    bool first = true;
    for (Derivation derivation : derivations)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            id.append(U".");
        }
        switch (derivation)
        {
        case Derivation::base: id.append(baseType->Id()); break;
        case Derivation::const_: id.append(U"const"); break;
        case Derivation::volatile_: id.append(U"volatile"); break;
        case Derivation::lvalueRef: id.append(U"lvalueref"); break;
        case Derivation::rvalueRef: id.append(U"rvalueref"); break;
        case Derivation::ptr: id.append(U"ptr"); break;
        }
    }
    id.append(U".").append(baseType->Id());
    return id;
}

std::u32string MakeDerivedTypeName(const std::vector<Derivation>& derivations, TypeSymbol* baseType)
{
    std::u32string name;
    for (Derivation derivation : derivations)
    {
        switch (derivation)
        {
        case Derivation::base: name.append(baseType->Name()); break;
        case Derivation::const_: name.append(U"const "); break;
        case Derivation::volatile_: name.append(U"volatile "); break;
        case Derivation::lvalueRef: name.append(U"&"); break;
        case Derivation::rvalueRef: name.append(U"&&"); break;
        case Derivation::ptr: name.append(U"*"); break;
        }
    }
    return name;
}

DerivedTypeSymbol::DerivedTypeSymbol(const Span& span_, const std::u32string& name_, TypeSymbol* baseType_, const std::vector<Derivation>& derivations_,
    const std::u32string& id_) : TypeSymbol(span_, name_), baseType(baseType_), derivations(derivations_), id(id_)
{
}

int DerivedTypeSymbol::MatchValue(TypeSymbol* argumentType)
{
    int parentMatchValue = TypeSymbol::MatchValue(argumentType);
    if (parentMatchValue == std::numeric_limits<int>::max())
    {
        return parentMatchValue; // exact match
    }
    if (argumentType != nullptr)
    {
        int baseMatchValue = baseType->MatchValue(argumentType->BaseType());
        if (baseMatchValue == std::numeric_limits<int>::max())
        {
            return baseMatchValue; // exact match with derived type
        }
        return baseMatchValue + 1;
    }
    if (parentMatchValue > 0)
    {
        return parentMatchValue;
    }
    return 0;
}

bool DerivedTypeSymbol::IsReferenceTypeSymbol() const
{
    return std::find(derivations.cbegin(), derivations.cend(), Derivation::lvalueRef) != derivations.cend() ||
        std::find(derivations.cbegin(), derivations.cend(), Derivation::rvalueRef) != derivations.cend();
}

std::unique_ptr<sngxml::dom::Element> DerivedTypeSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> typeElement(new sngxml::dom::Element(U"derivedType"));
    std::unique_ptr<sngxml::dom::Element> derivationsElement(new sngxml::dom::Element(U"derivations"));
    for (Derivation derivation : derivations)
    {
        std::unique_ptr<sngxml::dom::Element> derivationElement(new sngxml::dom::Element(U"derivation"));
        switch (derivation)
        {
        case Derivation::base:
        {
            derivationElement->SetAttribute(U"kind", U"base");
            derivationElement->SetAttribute(U"typeId", baseType->Id());
            break;
        }
        case Derivation::const_:
        {
            derivationElement->SetAttribute(U"kind", U"specifier");
            derivationElement->SetAttribute(U"str", U"const ");
            break;
        }
        case Derivation::volatile_:
        {
            derivationElement->SetAttribute(U"kind", U"specifier");
            derivationElement->SetAttribute(U"str", U"volatile ");
            break;
        }
        case Derivation::lvalueRef:
        {
            derivationElement->SetAttribute(U"kind", U"operator");
            derivationElement->SetAttribute(U"str", U"&");
            break;
        }
        case Derivation::rvalueRef:
        {
            derivationElement->SetAttribute(U"kind", U"operator");
            derivationElement->SetAttribute(U"str", U"&&");
            break;
        }
        case Derivation::ptr:
        {
            derivationElement->SetAttribute(U"kind", U"operator");
            derivationElement->SetAttribute(U"str", U"*");
            break;
        }
        }
        derivationsElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(derivationElement.release()));
    }
    typeElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(derivationsElement.release()));
    return typeElement;
}

} } // namespace sngcpp::symbols
