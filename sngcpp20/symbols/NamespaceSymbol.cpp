// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/NamespaceSymbol.hpp>

namespace sngcpp::symbols {

NamespaceSymbol::NamespaceSymbol(const std::u32string& name_) : ContainerSymbol(name_)
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
