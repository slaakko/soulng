// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/AliasGroupSymbol.hpp>
#include <sngcpp20/symbols/AliasTypeSymbol.hpp>
#include <sngcpp20/symbols/ClassGroupSymbol.hpp>
#include <sngcpp20/symbols/Scope.hpp>
#include <algorithm>

namespace sngcpp::symbols {

AliasGroupSymbol::AliasGroupSymbol(const std::u32string& name_) : Symbol(name_, SymbolKind::aliasGroupSymbol)
{
}

bool AliasGroupSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::namespaceScope: return true;
        case ScopeKind::classScope: return true;
        case ScopeKind::blockScope: return true;
    }
    return false;
}

void AliasGroupSymbol::AddAliasTypeSymbol(AliasTypeSymbol* aliasTypeSymbol)
{
    aliasTypeSymbols.push_back(aliasTypeSymbol);
}

AliasTypeSymbol* AliasGroupSymbol::GetAliasTypeSymbol(const std::vector<Symbol*>& templateArguments) const
{
    std::vector<std::pair<Symbol*, int>> symbolScores;
    for (AliasTypeSymbol* aliasTypeSymbol : aliasTypeSymbols)
    {
        int score = Match(aliasTypeSymbol->TemplateArguments(), templateArguments);
        if (score >= 0)
        {
            symbolScores.push_back(std::make_pair(aliasTypeSymbol, score));
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
        std::pair<Symbol*, int> second = symbolScores[2];
        if (first == second) return nullptr;
        return static_cast<AliasTypeSymbol*>(first.first);
    }
    else
    {
        return static_cast<AliasTypeSymbol*>(first.first);
    }
}

} // sngcpp::symbols
