// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_CONCEPT_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_CONCEPT_SYMBOL_INCLUDED
#include <sngcpp20/symbols/Symbol.hpp>

namespace sngcpp::symbols {

class ConceptGroupSymbol;
class TemplateParameterSymbol;
class TemplateDeclarationSymbol;

class SYMBOLS_API ConceptSymbol : public Symbol
{
public:
    ConceptSymbol(const std::u32string& name_);
    TemplateDeclarationSymbol* GetTemplateDeclarationSymbol() const { return templateDeclarationSymbol; }
    void SetTemplateDeclarationSymbol(TemplateDeclarationSymbol* templateDeclarationSymbol_);
    std::string SymbolKindStr() const override { return "concept symbol"; }
    SymbolGroupKind GetSymbolGroupKind() const override { return SymbolGroupKind::conceptSymbolGroup; }
    void AddToGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context) override;
    bool CanInstall() const override { return false; }
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
    const std::vector<Symbol*>& TemplateArguments() const { return templateArguments; }
    void SetTemplateArguments(const std::vector<Symbol*>& templateArguments_);
    void AddTemplateParameters(const std::vector<TemplateParameterSymbol*>& templateParameters);
private:
    Scope* groupScope;
    ConceptGroupSymbol* group;
    TemplateDeclarationSymbol* templateDeclarationSymbol;
    std::vector<Symbol*> templateArguments;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_CONCEPT_SYMBOL_INCLUDED
