// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_ALIAS_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_ALIAS_TYPE_SYMBOL_INCLUDED
#include <sngcpp20/symbols/TypeSymbol.hpp>

namespace sngcpp::symbols {

class SYMBOLS_API AliasTypeSymbol : public TypeSymbol
{
public:
    AliasTypeSymbol(const std::u32string& name_, TypeSymbol* referredType_);
    std::string SymbolKindStr() const override { return "alias type symbol"; }
    Scope* GetGroupScope() override { return groupScope; }
    const TypeSymbol* ReferredType() const override { return referredType; }
    void AddToGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context);
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
    bool CanInstall() const override { return false; }
    TemplateDeclarationSymbol* GetTemplateDeclarationSymbol() const { return templateDeclarationSymbol; }
    const std::vector<Symbol*>& TemplateArguments() const { return templateArguments; }
    void SetTemplateArguments(const std::vector<Symbol*>& templateArguments_);
    void SetTemplateDeclarationSymbol(TemplateDeclarationSymbol* templateDeclarationSymbol_) { templateDeclarationSymbol = templateDeclarationSymbol_; }
private:
    TypeSymbol* referredType;
    std::vector<Symbol*> templateArguments;
    TemplateDeclarationSymbol* templateDeclarationSymbol;
    Scope* groupScope;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_ALIAS_TYPE_SYMBOL_INCLUDED
