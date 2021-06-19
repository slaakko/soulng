// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/ConceptGroupSymbol.hpp>
#include <sngcpp20/symbols/ConceptSymbol.hpp>

namespace sngcpp::symbols {

ConceptGroupSymbol::ConceptGroupSymbol(const std::u32string& name_) : Symbol(name_, SymbolKind::conceptGroupSymbol)
{
}

void ConceptGroupSymbol::AddConcept(ConceptSymbol* conceptSymbol)
{
    concepts.push_back(conceptSymbol);
}

ConceptSymbol* ConceptGroupSymbol::GetConcept() const
{
    if (!concepts.empty())
    {
        return concepts.front();
    }
    return nullptr;
}

} // sngcpp::symbols
