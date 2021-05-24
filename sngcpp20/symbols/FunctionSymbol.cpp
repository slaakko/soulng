// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/FunctionSymbol.hpp>
#include <sngcpp20/symbols/VariableSymbol.hpp>

namespace sngcpp::symbols {

FunctionSymbol::FunctionSymbol(const std::u32string& name_) : ContainerSymbol(name_), returnType(nullptr)
{
    GetScope().SetKind(ScopeKind::functionScope);
}

bool FunctionSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::namespaceScope: return true;
        case ScopeKind::classScope: return true;
    }
    return false;
}

void FunctionSymbol::AddSymbol(Symbol* symbol)
{
    ContainerSymbol::AddSymbol(symbol);
    if (symbol->IsParameterSymbol())
    {
        parameters.push_back(static_cast<ParameterSymbol*>(symbol));
    }
}

} // sngcpp::symbols