// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_ALIAS_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_ALIAS_TYPE_SYMBOL_INCLUDED
#include <sngcpp20/symbols/TypeSymbol.hpp>

namespace sngcpp::symbols {

class TemplateParameterSymbol;

class SYMBOLS_API AliasTypeSymbol : public TypeSymbol
{
public:
    AliasTypeSymbol(const std::u32string& name_, TypeSymbol* referredType_);
    bool IsAliasTemplate() const;
    std::string SymbolKindStr() const override { return "alias type symbol"; }
    Scope* GetGroupScope() override { return groupScope; }
    const TypeSymbol* ReferredType() const override { return referredType; }
    TypeSymbol* ReferredType() { return referredType; }
    void AddToGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context) override;
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
    bool CanInstall() const override { return false; }
    TemplateDeclarationSymbol* GetTemplateDeclarationSymbol() const { return templateDeclarationSymbol; }
    const std::vector<Symbol*>& TemplateArguments() const { return templateArguments; }
    void SetTemplateArguments(const std::vector<Symbol*>& templateArguments_);
    void SetTemplateDeclarationSymbol(TemplateDeclarationSymbol* templateDeclarationSymbol_) { templateDeclarationSymbol = templateDeclarationSymbol_; }
    AliasTypeSymbol* AliasTemplate() const { return aliasTemplate; }
    void SetAliasTemplate(AliasTypeSymbol* aliasTemplate_);
    void AddTemplateParameters(const std::vector<TemplateParameterSymbol*>& templateParameters);
    AliasGroupSymbol* Group() const { return group; }
    void SetGroup(AliasGroupSymbol* group_) { group = group_; }
private:
    AliasTypeSymbol* aliasTemplate;
    TypeSymbol* referredType;
    std::vector<Symbol*> templateArguments;
    TemplateDeclarationSymbol* templateDeclarationSymbol;
    Scope* groupScope;
    AliasGroupSymbol* group;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_ALIAS_TYPE_SYMBOL_INCLUDED
