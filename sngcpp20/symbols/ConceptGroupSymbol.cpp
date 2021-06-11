// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/ConceptGroupSymbol.hpp>
#include <sngcpp20/symbols/ConceptSymbol.hpp>

namespace sngcpp::symbols {

ConceptGroupSymbol::ConceptGroupSymbol(const std::u32string& name_) : Symbol(name_)
{
}

void ConceptGroupSymbol::AddConcept(ConceptSymbol* conceptSymbol)
{
    concepts.push_back(conceptSymbol);
}

Scope* ConceptGroupSymbol::GetScope()
{
    if (concepts.size() == 1)
    {
        ConceptSymbol* conceptSymbol = concepts.front();
        return conceptSymbol->GetScope();
    }
    return nullptr;
}

} // sngcpp::symbols
