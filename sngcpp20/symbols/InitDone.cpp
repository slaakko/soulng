// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/InitDone.hpp>
#include <sngcpp20/symbols/FundamentalTypeSymbol.hpp>
#include <sngcpp20/symbols/Value.hpp>

namespace sngcpp::symbols {

void Init()
{
    InitFundamentalTypeSymbol();
    InitValue();
}

void Done()
{
    DoneValue();
    DoneFundamentalTypeSymbol();
}

} // sngcpp::symbols
