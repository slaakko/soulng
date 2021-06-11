// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_FUNCTION_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_FUNCTION_SYMBOL_INCLUDED
#include <sngcpp20/symbols/ContainerSymbol.hpp>

namespace sngcpp::symbols {

class ParameterSymbol;
class TypeSymbol;

class SYMBOLS_API FunctionSymbol : public ContainerSymbol
{
public:
    FunctionSymbol(const std::u32string& name_, const std::vector<ParameterSymbol*>& parameters, bool definition_);
    void AddSymbol(Symbol* symbol, const SourcePos& sourcePos, Context* context) override;
    std::string SymbolKindStr() const override { return "function symbol"; }
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
    bool CanInstall() const override { return false; }
    bool IsFunctionSymbol() const override { return true; }
    void AddToGroup(ContainerSymbol* containerSymbol, const SourcePos& sourcePos, Context* context) override;
    void RemoveFromGroup(ContainerSymbol* containerSymbol, const SourcePos& sourcePos, Context* context) override;
    void SetReturnType(TypeSymbol* returnType_) { returnType = returnType_;  }
    TypeSymbol* ReturnType() const { return returnType; }
    const std::vector<ParameterSymbol*>& Parameters() const { return parameters; }
    bool Definition() const { return definition; }
    void SetDefinition() { definition = true; }
private:
    TypeSymbol* returnType;
    std::vector<ParameterSymbol*> parameters;
    bool definition;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_FUNCTION_SYMBOL_INCLUDED
