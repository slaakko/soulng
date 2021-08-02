// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_FUNCTION_GROUP_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_FUNCTION_GROUP_SYMBOL_INCLUDED
#include <sngcpp20/symbols/Symbol.hpp>
#include <memory>
#include <vector>

namespace sngcpp::symbols {

class FunctionSymbol;
class ParameterSymbol;
class TypeSymbol;

class SYMBOLS_API FunctionGroupSymbol : public Symbol
{
public:
    FunctionGroupSymbol(const std::u32string& name_);
    std::string SymbolKindStr() const override { return "function group symbol"; }
    SymbolGroupKind GetSymbolGroupKind() const override { return SymbolGroupKind::functionSymbolGroup; }
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
    void AddFunction(FunctionSymbol* function);
    void RemoveFunction(FunctionSymbol* function);
    FunctionSymbol* GetFunction(const std::vector<TypeSymbol*>& parameterTypes) const;
private:
    std::vector<FunctionSymbol*> functions;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_FUNCTION_GROUP_SYMBOL_INCLUDED
