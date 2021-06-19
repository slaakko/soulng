// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_NAMESPACE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_NAMESPACE_SYMBOL_INCLUDED
#include <sngcpp20/symbols/ContainerSymbol.hpp>

namespace sngcpp::symbols {

class SYMBOLS_API NamespaceSymbol : public ContainerSymbol
{
public:
    NamespaceSymbol(const std::u32string& name_);
    std::string SymbolKindStr() const override { return "namespace symbol"; }
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_NAMESPACE_SYMBOL_INCLUDED
