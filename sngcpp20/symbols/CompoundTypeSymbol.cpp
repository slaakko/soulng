// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/CompoundTypeSymbol.hpp>

namespace sngcpp::symbols {

CompoundTypeSymbol::CompoundTypeSymbol(const std::u32string& name_, TypeSymbol* baseType_) : TypeSymbol(name_), baseType(baseType_)
{
}

ConstTypeSymbol::ConstTypeSymbol(TypeSymbol* baseType_) : CompoundTypeSymbol(std::u32string(), baseType_)
{
}

VolatileTypeSymbol::VolatileTypeSymbol(TypeSymbol* baseType_) : CompoundTypeSymbol(std::u32string(), baseType_)
{
}

PointerTypeSymbol::PointerTypeSymbol(TypeSymbol* baseType_) : CompoundTypeSymbol(std::u32string(), baseType_)
{
}

LvalueRefTypeSymbol::LvalueRefTypeSymbol(TypeSymbol* baseType_) : CompoundTypeSymbol(std::u32string(), baseType_)
{
}

RvalueRefTypeSymbol::RvalueRefTypeSymbol(TypeSymbol* baseType_) : CompoundTypeSymbol(std::u32string(), baseType_)
{
}

} // sngcpp::symbols
