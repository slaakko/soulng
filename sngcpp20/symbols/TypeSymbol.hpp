// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_TYPE_SYMBOL_INCLUDED
#include <sngcpp20/symbols/ContainerSymbol.hpp>

namespace sngcpp::symbols {

class SYMBOLS_API TypeSymbol : public ContainerSymbol
{
public:
    TypeSymbol(const std::u32string& name_);
    virtual bool IsTypeSymbol() const override { return true; }
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_TYPE_SYMBOL_INCLUDED
