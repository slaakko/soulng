// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/InitDone.hpp>
#include <sngcpp20/symbols/FundamentalTypeSymbol.hpp>

namespace sngcpp::symbols {

void Init()
{
    InitFundamentalTypeSymbol();
}

void Done()
{
    DoneFundamentalTypeSymbol();
}

} // sngcpp::symbols
