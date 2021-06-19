// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_TEMPLATE_PARAMETER_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_TEMPLATE_PARAMETER_SYMBOL_INCLUDED
#include <sngcpp20/symbols/TypeSymbol.hpp>

namespace sngcpp::symbols {

class SYMBOLS_API TypenameConstraintSymbol : public TypeSymbol
{
public:
    TypenameConstraintSymbol();
};

class SYMBOLS_API TemplateParameterSymbol : public TypeSymbol
{
public:
    TemplateParameterSymbol(Symbol* constraint_, const std::u32string& name_, int index_);
    Symbol* Constraint() const { return constraint; }
    int Index() const { return index; }
private:
    Symbol* constraint;
    int index;
};

class SYMBOLS_API TemplateDeclarationSymbol : public ContainerSymbol
{
public:
    TemplateDeclarationSymbol();
    bool CanInstall() const override { return false; }
    void AddSymbol(Symbol* symbol, const SourcePos& sourcePos, Scope* groupScope, Context* context) override;
    std::string SymbolKindStr() const override { return "template declaration symbol"; }
    const std::vector<TemplateParameterSymbol*>& TemplateParameters() const { return temlateParameters; }
private:
    std::vector<TemplateParameterSymbol*> temlateParameters;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_TEMPLATE_PARAMETER_SYMBOL_INCLUDED
