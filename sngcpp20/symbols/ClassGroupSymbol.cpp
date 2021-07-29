// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/ClassGroupSymbol.hpp>
#include <sngcpp20/symbols/ClassTypeSymbol.hpp>
#include <sngcpp20/symbols/Scope.hpp>
#include <algorithm>

namespace sngcpp::symbols {

bool ScoreLess::operator()(const std::pair<Symbol*, int>& left, const std::pair<Symbol*, int>& right) const
{
    return left.second < right.second;
}

ClassGroupSymbol::ClassGroupSymbol(const std::u32string& name_) : Symbol(name_, SymbolKind::classGroupSymbol)
{
}

bool ClassGroupSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
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

void ClassGroupSymbol::AddClass(ClassTypeSymbol* classTypeSymbol)
{
    classes.push_back(classTypeSymbol);
}

ClassTypeSymbol* ClassGroupSymbol::GetClass(const std::vector<Symbol*>& templateArguments, MatchKind matchKind, bool& exact) const
{
    exact = false;
    if (templateArguments.empty() && classes.size() == 1)
    {
        exact = true;
        return classes.front();
    }
    for (ClassTypeSymbol* classTypeSymbol : classes)
    {
        if (SymbolsEqual(templateArguments, classTypeSymbol->TemplateArguments()))
        {
            exact = true;
            return classTypeSymbol;
        }
    }
    if (matchKind == MatchKind::exact) return nullptr;
    std::vector<std::pair<Symbol*, int>> symbolScores;
    for (ClassTypeSymbol* classTypeSymbol : classes)
    {
        int score = Match(templateArguments, classTypeSymbol->TemplateArguments());
        if (score >= 0)
        {
            symbolScores.push_back(std::make_pair(classTypeSymbol, score));
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
        return static_cast<ClassTypeSymbol*>(first.first);
    }
    else
    {
        if (first.second == 0) exact = true;
        return static_cast<ClassTypeSymbol*>(first.first);
    }
}

ClassTypeSymbol* ClassGroupSymbol::GetClassTemplate() const
{
    for (ClassTypeSymbol* classTypeSymbol : classes)
    {
        if (classTypeSymbol->IsClassTemplate())
        {
            return classTypeSymbol;
        }
    }
    return nullptr;
}

} // sngcpp::symbols
