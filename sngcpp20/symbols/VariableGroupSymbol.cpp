// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/VariableGroupSymbol.hpp>
#include <sngcpp20/symbols/Scope.hpp>

namespace sngcpp::symbols {

VariableGroupSymbol::VariableGroupSymbol(const std::u32string& name_) : Symbol(name_, SymbolKind::variableGroupSymbol)
{
}

bool VariableGroupSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::namespaceScope: return true;
        case ScopeKind::classScope: return true;
        case ScopeKind::blockScope: return true;
    }
    return false;
}

void VariableGroupSymbol::AddVariable(VariableSymbol* variableSymbol)
{
    variables.push_back(variableSymbol);
}

VariableSymbol* VariableGroupSymbol::GetVariable() const
{
    if (!variables.empty())
    {
        return variables.front();
    }
    return nullptr;
}

} // sngcpp::symbols
