// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_VARIABLE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_VARIABLE_SYMBOL_INCLUDED
#include <sngcpp20/symbols/Symbol.hpp>

namespace sngcpp::symbols {

class TypeSymbol;

class SYMBOLS_API VariableSymbol : public Symbol
{
public:
    VariableSymbol(const std::u32string& name_);
    VariableSymbol(const std::u32string& name_, SymbolKind kind_);
    std::string SymbolKindStr() const override { return "variable symbol"; }
    void AddToGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context);
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
    bool CanInstall() const override { return false; }
    void SetType(TypeSymbol* type_) { type = type_; }
    TypeSymbol* Type() const { return type; }
private:
    TypeSymbol* type;
};

class SYMBOLS_API ParameterSymbol : public VariableSymbol
{
public:
    ParameterSymbol(const std::u32string& name_);
    std::string SymbolKindStr() const override { return "parameter symbol"; }
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_VARIABLE_SYMBOL_INCLUDED
