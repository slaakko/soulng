// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_BLOCK_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_BLOCK_SYMBOL_INCLUDED
#include <sngcpp20/symbols/ContainerSymbol.hpp>

namespace sngcpp::symbols {

class SYMBOLS_API BlockSymbol : public ContainerSymbol
{
public:
    BlockSymbol();
    std::string SymbolKindStr() const override { return "block"; }
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
    bool IsBlockSymbol() const override { return true; }
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_BLOCK_SYMBOL_INCLUDED
