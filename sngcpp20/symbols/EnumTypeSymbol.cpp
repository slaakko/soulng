// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/EnumTypeSymbol.hpp>

namespace sngcpp::symbols {

EnumeratorSymbol::EnumeratorSymbol(const std::u32string& name_, uint64_t value_, const std::u32string& rep_) : Symbol(name_, SymbolKind::enumeratorSymbol), value(value_), rep(rep_)
{
}

EnumTypeSymbol::EnumTypeSymbol(const std::u32string& name_, TypeSymbol* enumBaseType_) : TypeSymbol(name_, SymbolKind::enumTypeSymbol), idNode(nullptr), enumBaseType(enumBaseType_)
{
    GetScope()->SetKind(ScopeKind::enumerationScope);
}

bool EnumTypeSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::namespaceScope: return true;
        case ScopeKind::classScope: return true;
    }
    return false;
}

void EnumTypeSymbol::AddEnumerator(EnumeratorSymbol* enumerator)
{
    enumerators.push_back(std::unique_ptr<EnumeratorSymbol>(enumerator));
}



} // sngcpp::symbols
