// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/NullPtrTypeSymbol.hpp>

namespace sngcpp::symbols {

NullPtrTypeSymbol::NullPtrTypeSymbol() : TypeSymbol(std::u32string(), SymbolKind::nullPtrTypeSymbol)
{
}

} // sngcpp::symbols
