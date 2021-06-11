// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/FunctionGroupSymbol.hpp>
#include <sngcpp20/symbols/FunctionSymbol.hpp>
#include <sngcpp20/symbols/VariableSymbol.hpp>
#include <sngcpp20/symbols/Scope.hpp>

namespace sngcpp::symbols {

FunctionGroupSymbol::FunctionGroupSymbol(const std::u32string& name_) : Symbol(name_)
{
}

bool FunctionGroupSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::namespaceScope: return true;
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
        Parent()->RemoveSymbol(this);
    }
}

FunctionSymbol* FunctionGroupSymbol::GetFunction(const std::vector<std::unique_ptr<ParameterSymbol>>& parameters) const
{
    int n = parameters.size();
    for (FunctionSymbol* functionSymbol : functions)
    {
        if (functionSymbol->Parameters().size() == n)
        {
            bool matched = true;
            for (int i = 0; i < n; ++i)
            {
                if (functionSymbol->Parameters()[i]->Type() != parameters[i]->Type())
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

Scope* FunctionGroupSymbol::GetScope()
{
    if (functions.size() == 1)
    {
        FunctionSymbol* functionSymbol = functions.front();
        return functionSymbol->GetScope();
    }
    return nullptr;
}

} // sngcpp::symbols
