// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/TypeSymbol.hpp>
#include <sngcpp20/symbols/CompoundTypeSymbol.hpp>

namespace sngcpp::symbols {

TypeSymbol::TypeSymbol(const std::u32string& name_, SymbolKind kind_) : ContainerSymbol(name_, kind_)
{
}

} // sngcpp::symbols
