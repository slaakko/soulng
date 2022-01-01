// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_VARIABLE_GROUP_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_VARIABLE_GROUP_SYMBOL_INCLUDED
#include <sngcpp20/symbols/ClassGroupSymbol.hpp>
#include <vector>

namespace sngcpp::symbols {

class VariableSymbol;

class SYMBOLS_API VariableGroupSymbol : public Symbol
{
public:
    VariableGroupSymbol(const std::u32string& name_);
    std::string SymbolKindStr() const override { return "variable group symbol"; }
    SymbolGroupKind GetSymbolGroupKind() const override { return SymbolGroupKind::variableSymbolGroup; }
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
    void AddVariable(VariableSymbol* variableSymbol);
    VariableSymbol* GetVariable(const std::vector<Symbol*>& templateArguments, MatchKind matchKind, bool& exact) const;
    VariableSymbol* GetVariableTemplate() const;
private:
    std::vector<VariableSymbol*> variables;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_VARIABLE_GROUP_SYMBOL_INCLUDED
