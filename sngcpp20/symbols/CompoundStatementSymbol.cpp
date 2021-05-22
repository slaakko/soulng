// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/CompoundStatementSymbol.hpp>

namespace sngcpp::symbols {

CompoundStatementSymbol::CompoundStatementSymbol() : ContainerSymbol(std::u32string())
{
    GetScope().SetKind(ScopeKind::blockScope);
}

bool CompoundStatementSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::functionScope: return true;
        case ScopeKind::blockScope: return true;
    }
    return false;
}

} // sngcpp::symbols
