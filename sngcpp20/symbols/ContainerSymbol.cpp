// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/ContainerSymbol.hpp>
#include <sngcpp20/symbols/ClassGroupSymbol.hpp>
#include <sngcpp20/symbols/FunctionGroupSymbol.hpp>
#include <sngcpp20/symbols/ConceptGroupSymbol.hpp>
#include <sngcpp20/symbols/Exception.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp::symbols {

using namespace soulng::unicode;

ContainerSymbol::ContainerSymbol(const std::u32string& name_, SymbolKind kind_) : Symbol(name_, kind_)
{
    scope.SetContainerSymbol(this);
}

void ContainerSymbol::AddSymbol(Symbol* symbol, SymbolGroupKind symbolGroupKind, const SourcePos& sourcePos, Scope* groupScope, Context* context)
{
    if (groupScope)
    {
        symbol->AddToGroup(groupScope, sourcePos, context);
    }
    symbol->SetParent(this);
    Scope* childScope = symbol->GetScope();
    if (childScope)
    {
        childScope->SetParentScope(&scope);
    }
    if (symbol->CanInstall())
    {
        scope.Install(symbol, symbolGroupKind);
    }
    symbols.push_back(std::unique_ptr<Symbol>(symbol));
}

void ContainerSymbol::RemoveSymbol(Symbol* symbol, SymbolGroupKind symbolGroupKind)
{
    if (symbol->CanInstall())
    {
        scope.Uninstall(symbol, symbolGroupKind);
    }
    for (std::vector<std::unique_ptr<Symbol>>::iterator i = symbols.begin(); i != symbols.end(); ++i)
    {
        if (i->get() == symbol)
        {
            symbols.erase(i);
            break;
        }
    }
}

} // sngcpp::symbols
