// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_FUNCTION_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_FUNCTION_SYMBOL_INCLUDED
#include <sngcpp20/symbols/ContainerSymbol.hpp>
#include <sngcpp20/symbols/VariableSymbol.hpp>

namespace sngcpp::symbols {

class Symbol;
class TypeSymbol;
class FunctionTypeSymbol;
class TemplateDeclarationSymbol;
class TemplateParameterSymbol;

class SYMBOLS_API FunctionSymbol : public ContainerSymbol
{
public:
    FunctionSymbol(const std::u32string& name_, FunctionTypeSymbol* type_, bool definition_);
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
    bool Definition() const { return definition; }
    void SetDefinition() { definition = true; }
    FunctionTypeSymbol* Type() const { return type; }
    const std::vector<Symbol*>& TemplateArguments() const { return templateArguments; }
    void SetTemplateArguments(const std::vector<Symbol*>& templateArguments_);
    void AddTemplateParameters(const std::vector<TemplateParameterSymbol*>& templateParameters);
private:
    std::vector<Symbol*> templateArguments;
    FunctionTypeSymbol* type;
    bool definition;
    TemplateDeclarationSymbol* templateDeclarationSymbol;
    Scope* groupScope;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_FUNCTION_SYMBOL_INCLUDED
