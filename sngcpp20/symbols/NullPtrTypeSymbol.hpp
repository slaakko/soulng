// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_NULLPTR_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_NULLPTR_TYPE_SYMBOL_INCLUDED
#include <sngcpp20/symbols/TypeSymbol.hpp>

namespace sngcpp::symbols {

class SYMBOLS_API NullPtrTypeSymbol : public TypeSymbol
{
public:
    NullPtrTypeSymbol();
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_NULLPTR_TYPE_SYMBOL_INCLUDED
