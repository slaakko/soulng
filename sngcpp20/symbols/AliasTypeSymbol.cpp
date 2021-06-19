// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/AliasTypeSymbol.hpp>
#include <sngcpp20/symbols/AliasGroupSymbol.hpp>

namespace sngcpp::symbols {

AliasTypeSymbol::AliasTypeSymbol(const std::u32string& name_, TypeSymbol* referredType_) : TypeSymbol(name_, SymbolKind::aliasTypeSymbol), referredType(referredType_), templateDeclarationSymbol(nullptr)
{
}

bool AliasTypeSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::namespaceScope: return true;
        case ScopeKind::classScope: return true;
        case ScopeKind::blockScope: return true;
    }
    return false;
}

void AliasTypeSymbol::AddToGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context)
{
    AliasGroupSymbol* aliasGroup = groupScope->GetOrInsertAliasGroup(Name(), sourcePos, context);
    aliasGroup->AddAliasTypeSymbol(this);
}

} // sngcpp::symbols
