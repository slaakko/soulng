// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/VarArgTypeSymbol.hpp>

namespace sngcpp::symbols {

VarArgTypeSymbol::VarArgTypeSymbol() : TypeSymbol(std::u32string(), SymbolKind::varArgTypeSymbol)
{
}

} // sngcpp::symbols
