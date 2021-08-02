// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/FunctionGroupSymbol.hpp>
#include <sngcpp20/symbols/FunctionSymbol.hpp>
#include <sngcpp20/symbols/FunctionTypeSymbol.hpp>
#include <sngcpp20/symbols/TypeSymbol.hpp>
#include <sngcpp20/symbols/VariableSymbol.hpp>
#include <sngcpp20/symbols/Scope.hpp>

namespace sngcpp::symbols {

FunctionGroupSymbol::FunctionGroupSymbol(const std::u32string& name_) : Symbol(name_, SymbolKind::functionGroupSymbol)
{
}

bool FunctionGroupSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::namespaceScope: return true;
        case ScopeKind::templateDeclarationScope: return true;
        case ScopeKind::classScope: return true;
    }
    return false;
}

void FunctionGroupSymbol::AddFunction(FunctionSymbol* functionSymbol)
{
    functions.push_back(functionSymbol);
}

void FunctionGroupSymbol::RemoveFunction(FunctionSymbol* function)
{
    functions.erase(std::remove(functions.begin(), functions.end(), function), functions.end());
    if (functions.empty())
    {
        Parent()->RemoveSymbol(this, SymbolGroupKind::functionSymbolGroup);
    }
}

FunctionSymbol* FunctionGroupSymbol::GetFunction(const std::vector<TypeSymbol*>& parameterTypes) const
{
    int n = parameterTypes.size();
    for (FunctionSymbol* functionSymbol : functions)
    {
        if (functionSymbol->Type()->Key().parameterTypes.size() == n)
        {
            bool matched = true;
            for (int i = 0; i < n; ++i)
            {
                if (!SymbolsEqual(functionSymbol->Type()->Key().parameterTypes[i], parameterTypes[i]))
                {
                    matched = false;
                    break;
                }
            }
            if (matched)
            {
                return functionSymbol;
            }
        }
    }
    return nullptr;
}

} // sngcpp::symbols
