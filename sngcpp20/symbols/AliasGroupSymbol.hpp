// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_ALIAS_GROUP_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_ALIAS_GROUP_SYMBOL_INCLUDED
#include <sngcpp20/symbols/Symbol.hpp>
#include <vector>

namespace sngcpp::symbols {

class AliasTypeSymbol;

class SYMBOLS_API AliasGroupSymbol : public Symbol
{
public:
    AliasGroupSymbol(const std::u32string& name_);
    bool IsTypeSymbol() const override { return true; }
    std::string SymbolKindStr() const override { return "alias group symbol"; }
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
    void AddAliasTypeSymbol(AliasTypeSymbol* aliasTypeSymbol);
    AliasTypeSymbol* GetAliasTypeSymbol() const;
private:
    std::vector<AliasTypeSymbol*> aliasTypeSymbols;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_ALIAS_GROUP_SYMBOL_INCLUDED
