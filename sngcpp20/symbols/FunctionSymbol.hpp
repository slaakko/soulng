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
class TemplateDeclarationSymbol;
class TemplateParameterSymbol;

class SYMBOLS_API FunctionSymbol : public ContainerSymbol
{
public:
    FunctionSymbol(const std::u32string& name_, std::vector<std::unique_ptr<ParameterSymbol>>&& parameters_, bool definition_);
    std::string SymbolKindStr() const override { return "function symbol"; }
    bool IsConstructorSymbol() const override;
    bool IsDestructorSymbol() const override;
    SymbolGroupKind GetSymbolGroupKind() const override { return SymbolGroupKind::functionSymbolGroup; }
    TemplateDeclarationSymbol* GetTemplateDeclarationSymbol() const { return templateDeclarationSymbol; }
    void SetTemplateDeclarationSymbol(TemplateDeclarationSymbol* templateDeclarationSymbol_) { templateDeclarationSymbol = templateDeclarationSymbol_; }
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
    bool CanInstall() const override { return false; }
    void AddToGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context) override;
    void RemoveFromGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context) override;
    void SetType(FunctionTypeSymbol* type_) { type = type_;  }
    FunctionTypeSymbol* Type() const { return type; }
    const std::vector<std::unique_ptr<ParameterSymbol>>& Parameters() const { return parameters; }
    bool Definition() const { return definition; }
    void SetDefinition() { definition = true; }
private:
    FunctionTypeSymbol* type;
    std::vector<std::unique_ptr<ParameterSymbol>> parameters;
    bool definition;
    TemplateDeclarationSymbol* templateDeclarationSymbol;
    Scope* groupScope;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_FUNCTION_SYMBOL_INCLUDED
