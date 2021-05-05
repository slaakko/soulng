// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_CONTAINER_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_CONTAINER_SYMBOL_INCLUDED
#include <sngcpp20/symbols/Symbol.hpp>
#include <sngcpp20/symbols/Scope.hpp>
#include <memory>
#include <vector>

namespace sngcpp::symbols {

class SYMBOLS_API ContainerSymbol : public Symbol
{
public:
    ContainerSymbol(const std::u32string& name_);
    ContainerSymbol(const ContainerSymbol&) = delete;
    ContainerSymbol& operator=(const ContainerSymbol&) = delete;
    bool IsContainerSymbol() const override { return true; }
    void AddSymbol(Symbol* symbol);
    const Scope& GetScope() const { return scope; }
    Scope& GetScope() { return scope; }
private:
    std::vector<std::unique_ptr<Symbol>> symbols;
    Scope scope;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_CONTAINER_SYMBOL_INCLUDED
