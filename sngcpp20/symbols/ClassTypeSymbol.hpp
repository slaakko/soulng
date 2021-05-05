// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_CLASS_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_CLASS_TYPE_SYMBOL_INCLUDED
#include <sngcpp20/symbols/TypeSymbol.hpp>

namespace sngcpp::symbols {

class SYMBOLS_API ClassTypeSymbol : public TypeSymbol
{
public:
    ClassTypeSymbol(const std::u32string& name_);
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_CLASS_TYPE_SYMBOL_INCLUDED
