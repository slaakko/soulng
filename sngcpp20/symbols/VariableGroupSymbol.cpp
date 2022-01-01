// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/VariableGroupSymbol.hpp>
#include <sngcpp20/symbols/VariableSymbol.hpp>
#include <sngcpp20/symbols/ClassGroupSymbol.hpp>
#include <sngcpp20/symbols/Scope.hpp>
#include <algorithm>

namespace sngcpp::symbols {

VariableGroupSymbol::VariableGroupSymbol(const std::u32string& name_) : Symbol(name_, SymbolKind::variableGroupSymbol)
{
}

bool VariableGroupSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::namespaceScope: return true;
        case ScopeKind::templateDeclarationScope: return true;
        case ScopeKind::classScope: return true;
        case ScopeKind::blockScope: return true;
    }
    return false;
}

void VariableGroupSymbol::AddVariable(VariableSymbol* variableSymbol)
{
    variables.push_back(variableSymbol);
}

VariableSymbol* VariableGroupSymbol::GetVariable(const std::vector<Symbol*>& templateArguments, MatchKind matchKind, bool& exact) const
{
    exact = false;
    for (VariableSymbol* variableSymbol : variables)
    {
        if (SymbolsEqual(templateArguments, variableSymbol->TemplateArguments()))
        {
            exact = true;
            return variableSymbol;
        }
    }
    if (matchKind == MatchKind::exact) return nullptr;
    std::vector<std::pair<Symbol*, int>> symbolScores;
    for (VariableSymbol* variable : variables)
    {
        int score = Match(variable->TemplateArguments(), templateArguments);
        if (score >= 0)
        {
            symbolScores.push_back(std::make_pair(variable, score));
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
        return static_cast<VariableSymbol*>(first.first);
    }
    else
    {
        return static_cast<VariableSymbol*>(first.first);
    }
}

VariableSymbol* VariableGroupSymbol::GetVariableTemplate() const
{
    for (VariableSymbol* variable : variables)
    {
        if (variable->IsVariableTemplate())
        {
            return variable;
        }
    }
    return nullptr;
}

} // sngcpp::symbols
