// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/CompoundTypeSymbol.hpp>

namespace sngcpp::symbols {

CompoundTypeSymbol::CompoundTypeSymbol(const std::u32string& name_, SymbolKind kind_, TypeSymbol* baseType_) : TypeSymbol(name_, kind_), baseType(baseType_)
{
}

ConstTypeSymbol::ConstTypeSymbol(TypeSymbol* baseType_) : CompoundTypeSymbol(std::u32string(), SymbolKind::constTypeSymbol, baseType_)
{
}

VolatileTypeSymbol::VolatileTypeSymbol(TypeSymbol* baseType_) : CompoundTypeSymbol(std::u32string(), SymbolKind::volatileTypeSymbol, baseType_)
{
}

PointerTypeSymbol::PointerTypeSymbol(TypeSymbol* baseType_) : CompoundTypeSymbol(std::u32string(), SymbolKind::pointerTypeSymbol, baseType_)
{
}

LvalueRefTypeSymbol::LvalueRefTypeSymbol(TypeSymbol* baseType_) : CompoundTypeSymbol(std::u32string(), SymbolKind::lvalueRefTypeSymbol, baseType_)
{
}

RvalueRefTypeSymbol::RvalueRefTypeSymbol(TypeSymbol* baseType_) : CompoundTypeSymbol(std::u32string(), SymbolKind::rvalueRefTypeSymbol, baseType_)
{
}

} // sngcpp::symbols
