// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/BlockSymbol.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp::symbols {

using namespace soulng::unicode;

BlockSymbol::BlockSymbol(int number_) : ContainerSymbol(std::u32string(), SymbolKind::blockSymbol), number(number_)
{
    GetScope()->SetKind(ScopeKind::blockScope);
    installationName = ToUtf32("block" + std::to_string(number));
}

bool BlockSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::functionScope: return true;
        case ScopeKind::blockScope: return true;
    }
    return false;
}

} // sngcpp::symbols
