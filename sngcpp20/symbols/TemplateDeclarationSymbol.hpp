// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_TEMPLATE_PARAMETER_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_TEMPLATE_PARAMETER_SYMBOL_INCLUDED
#include <sngcpp20/symbols/TypeSymbol.hpp>

namespace sngcpp::symbols {

class SYMBOLS_API TemplateDeclarationSymbol : public ContainerSymbol
{
public:
    TemplateDeclarationSymbol();
    bool CanInstall() const override { return false; }
    std::string SymbolKindStr() const override { return "template declaration symbol"; }
};

class SYMBOLS_API TemplateParameterSymbol : public TypeSymbol
{
public:
    TemplateParameterSymbol(const std::u32string& name_);
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_TEMPLATE_PARAMETER_SYMBOL_INCLUDED
