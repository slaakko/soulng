// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/pp/InitDone.hpp>
#include <sngcpp20/pp/PP.hpp>

namespace sngcpp::pp {

void Init()
{
    InitPP();
}

void Done()
{
    DonePP();
}

} // namespace sngcpp::pp
