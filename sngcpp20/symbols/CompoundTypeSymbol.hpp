// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_COMPOUND_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_COMPOUND_TYPE_SYMBOL_INCLUDED
#include <sngcpp20/symbols/TypeSymbol.hpp>

namespace sngcpp::symbols {

class SYMBOLS_API CompoundTypeSymbol : public TypeSymbol
{
public:
    CompoundTypeSymbol(const std::u32string& name_, SymbolKind kind_, TypeSymbol* baseType_);
    std::string SymbolKindStr() const override { return "compound type symbol"; }
    bool IsCompoundTypeSymbol() const override { return true; }
    TypeSymbol* BaseType() const { return baseType; }
private:
    TypeSymbol* baseType;
};

class SYMBOLS_API ConstTypeSymbol : public CompoundTypeSymbol
{
public:
    ConstTypeSymbol(TypeSymbol* baseType_);
};

class SYMBOLS_API VolatileTypeSymbol : public CompoundTypeSymbol
{
public:
    VolatileTypeSymbol(TypeSymbol* baseType_);
};

class SYMBOLS_API PointerTypeSymbol : public CompoundTypeSymbol
{
public:
    PointerTypeSymbol(TypeSymbol* baseType_);
};

class SYMBOLS_API LvalueRefTypeSymbol : public CompoundTypeSymbol
{
public:
    LvalueRefTypeSymbol(TypeSymbol* baseType_);
};

class SYMBOLS_API RvalueRefTypeSymbol : public CompoundTypeSymbol
{
public:
    RvalueRefTypeSymbol(TypeSymbol* baseType_);
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_COMPOUND_TYPE_SYMBOL_INCLUDED
