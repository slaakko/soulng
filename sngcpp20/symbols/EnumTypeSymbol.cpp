// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/EnumTypeSymbol.hpp>

namespace sngcpp::symbols {

EnumTypeSymbol::EnumTypeSymbol(const std::u32string& name_) : TypeSymbol(name_), idNode(nullptr)
{
}

} // sngcpp::symbols
