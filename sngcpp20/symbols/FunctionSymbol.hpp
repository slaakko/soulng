// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_FUNCTION_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_FUNCTION_SYMBOL_INCLUDED
#include <sngcpp20/symbols/ContainerSymbol.hpp>
#include <sngcpp20/symbols/VariableSymbol.hpp>

namespace sngcpp::symbols {

class TypeSymbol;
class FunctionTypeSymbol;

class SYMBOLS_API FunctionSymbol : public ContainerSymbol
{
public:
    FunctionSymbol(const std::u32string& name_, std::vector<std::unique_ptr<ParameterSymbol>>&& parameters_, bool definition_);
    std::string SymbolKindStr() const override { return "function symbol"; }
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
    bool CanInstall() const override { return false; }
    bool IsFunctionSymbol() const override { return true; }
    void AddToGroup(ContainerSymbol* containerSymbol, const SourcePos& sourcePos, Context* context) override;
    void RemoveFromGroup(ContainerSymbol* containerSymbol, const SourcePos& sourcePos, Context* context) override;
    void SetType(FunctionTypeSymbol* type_) { type = type_;  }
    FunctionTypeSymbol* Type() const { return type; }
    const std::vector<std::unique_ptr<ParameterSymbol>>& Parameters() const { return parameters; }
    bool Definition() const { return definition; }
    void SetDefinition() { definition = true; }
private:
    FunctionTypeSymbol* type;
    std::vector<std::unique_ptr<ParameterSymbol>> parameters;
    bool definition;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_FUNCTION_SYMBOL_INCLUDED
