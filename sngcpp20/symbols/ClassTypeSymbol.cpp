// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/ClassTypeSymbol.hpp>

namespace sngcpp::symbols {

ClassTypeSymbol::ClassTypeSymbol(const std::u32string& name_) : TypeSymbol(name_)
{
    GetScope().SetKind(ScopeKind::classScope);
}

bool ClassTypeSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::namespaceScope: return true;
        case ScopeKind::classScope: return true;
    }
    return false;
}

} // sngcpp::symbols
