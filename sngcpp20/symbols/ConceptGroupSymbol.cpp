// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/ConceptGroupSymbol.hpp>
#include <sngcpp20/symbols/ConceptSymbol.hpp>
#include <algorithm>

namespace sngcpp::symbols {

ConceptGroupSymbol::ConceptGroupSymbol(const std::u32string& name_) : Symbol(name_, SymbolKind::conceptGroupSymbol)
{
}

void ConceptGroupSymbol::AddConcept(ConceptSymbol* conceptSymbol)
{
    concepts.push_back(conceptSymbol);
}

ConceptSymbol* ConceptGroupSymbol::GetConcept(const std::vector<Symbol*>& templateArguments, MatchKind matchKind, bool& exact) const
{
    exact = false;
    if (templateArguments.empty() && concepts.size() == 1)
    {
        exact = true;
        return concepts.front();
    }
    for (ConceptSymbol* conceptSymbol : concepts)
    {
        if (SymbolsEqual(templateArguments, conceptSymbol->TemplateArguments()))
        {
            exact = true;
            return conceptSymbol;
        }
    }
    if (matchKind == MatchKind::exact) return nullptr;
    std::vector<std::pair<Symbol*, int>> symbolScores;
    for (ConceptSymbol* conceptSymbol : concepts)
    {
        int score = Match(templateArguments, conceptSymbol->TemplateArguments());
        if (score >= 0)
        {
            symbolScores.push_back(std::make_pair(conceptSymbol, score));
        }
    }
    if (symbolScores.empty())
    {
        return nullptr;
    }
    std::sort(symbolScores.begin(), symbolScores.end(), ScoreLess());
    std::pair<Symbol*, int> first = symbolScores.front();
    if (symbolScores.size() > 1)
    {
        std::pair<Symbol*, int> second = symbolScores[1];
        if (first == second) return nullptr;
        if (first.second == 0) exact = true;
        return static_cast<ConceptSymbol*>(first.first);
    }
    else
    {
        if (first.second == 0) exact = true;
        return static_cast<ConceptSymbol*>(first.first);
    }
}

} // sngcpp::symbols
