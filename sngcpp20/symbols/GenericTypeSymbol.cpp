// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/GenericTypeSymbol.hpp>

namespace sngcpp::symbols {

GenericTypeSymbol::GenericTypeSymbol() : TypeSymbol(std::u32string(), SymbolKind::genericTypeSymbol)
{
}

} // sngcpp::symbols
