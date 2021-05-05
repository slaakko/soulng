// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Scope.hpp>
#include <sngcpp20/symbols/ContainerSymbol.hpp>
#include <soulng/util/Unicode.hpp>
#include <stdexcept>

namespace sngcpp::symbols {

using namespace soulng::unicode;

Scope::Scope() : parentScope(nullptr), containerSymbol(nullptr)
{
}

void Scope::Install(Symbol* symbol)
{
    auto it = symbolMap.find(symbol->Name());
    if (it != symbolMap.cend())
    {
        throw std::runtime_error("symbol '" + ToUtf8(symbol->Name()) + "' already installed to scope '" + ToUtf8(GetContainerSymbol()->FullName()) + "'");
    }
    symbolMap[symbol->Name()] = symbol;
}

Symbol* Scope::Lookup(const std::u32string& id, ScopeLookup scopeLookup) const
{
    if ((scopeLookup & ScopeLookup::thisScope) != ScopeLookup::none)
    {
        auto it = symbolMap.find(id);
        if (it != symbolMap.cend())
        {
            return it->second;
        }
    }
    if ((scopeLookup & ScopeLookup::parentScope) != ScopeLookup::none)
    {
        if (parentScope)
        {
            return parentScope->Lookup(id, scopeLookup);
        }
    }
    return nullptr;
}

} // sngcpp::symbols
