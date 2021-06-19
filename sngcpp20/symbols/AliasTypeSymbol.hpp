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
    const TypeSymbol* ReferredType() const override { return referredType; }
    void AddToGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context);
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
    bool CanInstall() const override { return false; }
    TemplateDeclarationSymbol* GetTemplateDeclarationSymbol() const { return templateDeclarationSymbol; }
    void SetTemplateDeclarationSymbol(TemplateDeclarationSymbol* templateDeclarationSymbol_) { templateDeclarationSymbol = templateDeclarationSymbol_; }
private:
    TypeSymbol* referredType;
    TemplateDeclarationSymbol* templateDeclarationSymbol;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_ALIAS_TYPE_SYMBOL_INCLUDED
