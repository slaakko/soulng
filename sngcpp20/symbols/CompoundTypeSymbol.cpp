// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/CompoundTypeSymbol.hpp>

namespace sngcpp::symbols {

CompoundTypeSymbol::CompoundTypeSymbol(const std::u32string& name_, SymbolKind kind_, TypeSymbol* baseType_) : TypeSymbol(name_, kind_), baseType(baseType_)
{
}

ConstTypeSymbol::ConstTypeSymbol(TypeSymbol* baseType_) : CompoundTypeSymbol(U"const " + baseType_->Name(), SymbolKind::constTypeSymbol, baseType_)
{
}

VolatileTypeSymbol::VolatileTypeSymbol(TypeSymbol* baseType_) : CompoundTypeSymbol(U"volatile " + baseType_->Name(), SymbolKind::volatileTypeSymbol, baseType_)
{
}

PointerTypeSymbol::PointerTypeSymbol(TypeSymbol* baseType_) : CompoundTypeSymbol(baseType_->Name() + U"*", SymbolKind::pointerTypeSymbol, baseType_)
{
}

LvalueRefTypeSymbol::LvalueRefTypeSymbol(TypeSymbol* baseType_) : CompoundTypeSymbol(baseType_->Name() + U"&", SymbolKind::lvalueRefTypeSymbol, baseType_)
{
}

RvalueRefTypeSymbol::RvalueRefTypeSymbol(TypeSymbol* baseType_) : CompoundTypeSymbol(baseType_->Name() + U"&&", SymbolKind::rvalueRefTypeSymbol, baseType_)
{
}

} // sngcpp::symbols
