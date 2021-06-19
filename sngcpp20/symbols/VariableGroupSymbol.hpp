// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_VARIABLE_GROUP_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_VARIABLE_GROUP_SYMBOL_INCLUDED
#include <sngcpp20/symbols/Symbol.hpp>
#include <vector>

namespace sngcpp::symbols {

class VariableSymbol;

class SYMBOLS_API VariableGroupSymbol : public Symbol
{
public:
    VariableGroupSymbol(const std::u32string& name_);
    std::string SymbolKindStr() const override { return "variable group symbol"; }
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
    void AddVariable(VariableSymbol* variableSymbol);
    VariableSymbol* GetVariable() const;
private:
    std::vector<VariableSymbol*> variables;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_VARIABLE_GROUP_SYMBOL_INCLUDED
