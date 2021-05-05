// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/ContainerSymbol.hpp>

namespace sngcpp::symbols {

ContainerSymbol::ContainerSymbol(const std::u32string& name_) : Symbol(name_)
{
    scope.SetContainerSymbol(this);
}

void ContainerSymbol::AddSymbol(Symbol* symbol)
{
    symbol->SetParent(this);
    if (symbol->IsContainerSymbol())
    {
        ContainerSymbol* child = static_cast<ContainerSymbol*>(symbol);
        child->GetScope().SetParentScope(&scope);
    }
    scope.Install(symbol);
    symbols.push_back(std::unique_ptr<Symbol>(symbol));
}

} // sngcpp::symbols
