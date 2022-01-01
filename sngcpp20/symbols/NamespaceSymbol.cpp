// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/NamespaceSymbol.hpp>

namespace sngcpp::symbols {

NamespaceSymbol::NamespaceSymbol(const std::u32string& name_) : ContainerSymbol(name_, SymbolKind::namespaceSymbol)
{
    GetScope()->SetKind(ScopeKind::namespaceScope);
}

bool NamespaceSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::namespaceScope: return true;
    }
    return false;
}

} // sngcpp::symbols
