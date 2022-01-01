// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_VAR_ARG_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_VAR_ARG_TYPE_SYMBOL_INCLUDED
#include <sngcpp20/symbols/TypeSymbol.hpp>

namespace sngcpp::symbols {

class SYMBOLS_API VarArgTypeSymbol : public TypeSymbol
{
public:
    VarArgTypeSymbol();
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_VAR_ARG_TYPE_SYMBOL_INCLUDED
