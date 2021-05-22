// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/VariableSymbol.hpp>
#include <sngcpp20/symbols/Scope.hpp>

namespace sngcpp::symbols {

VariableSymbol::VariableSymbol(const std::u32string& name_) : Symbol(name_), type(nullptr)
{
}

bool VariableSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::namespaceScope: return true;
        case ScopeKind::classScope: return true;
        case ScopeKind::blockScope: return true;
    }
    return false;
}

ParameterSymbol::ParameterSymbol(const std::u32string& name_) : VariableSymbol(name_)
{
}

bool ParameterSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::functionScope: return true;
    }
    return false;
}

} // sngcpp::symbols
