// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_VARIABLE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_VARIABLE_SYMBOL_INCLUDED
#include <sngcpp20/symbols/Symbol.hpp>

namespace sngcpp::symbols {

class VariableGroupSymbol;
class TemplateDeclarationSymbol;
class TemplateParameterSymbol;
class TypeSymbol;
class Value;

class SYMBOLS_API VariableSymbol : public Symbol
{
public:
    VariableSymbol(const std::u32string& name_);
    VariableSymbol(const std::u32string& name_, SymbolKind kind_);
    std::string SymbolKindStr() const override { return "variable symbol"; }
    bool IsVariableTemplate() const;
    SymbolGroupKind GetSymbolGroupKind() const override { return SymbolGroupKind::variableSymbolGroup; }
    Scope* GetGroupScope() override { return groupScope; }
    void AddToGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context) override;
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
    bool CanInstall() const override { return false; }
    void SetType(TypeSymbol* type_) { type = type_; }
    TypeSymbol* Type() const { return type; }
    Value* GetValue() const { return value; }
    void SetValue(Value* value_) { value = value_; }
    TemplateDeclarationSymbol* GetTemplateDeclarationSymbol() const { return templateDeclarationSymbol; }
    void SetTemplateDeclarationSymbol(TemplateDeclarationSymbol* templateDeclarationSymbol_) { templateDeclarationSymbol = templateDeclarationSymbol_; }
    const std::vector<Symbol*>& TemplateArguments() const { return templateArguments; }
    void SetTemplateArguments(const std::vector<Symbol*>& templateArguments_);
    VariableSymbol* VariableTemplate() const { return variableTemplate; }
    void SetVariableTemplate(VariableSymbol* variableTemplate_);
    void AddTemplateParameters(const std::vector<TemplateParameterSymbol*>& templateParameters);
private:
    TypeSymbol* type;
    Value* value;
    VariableSymbol* variableTemplate;
    TemplateDeclarationSymbol* templateDeclarationSymbol;
    std::vector<Symbol*> templateArguments;
    Scope* groupScope;
    VariableGroupSymbol* group;
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
