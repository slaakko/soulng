// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/pp/InitDone.hpp>
#include <sngcpp/pp/PP.hpp>

namespace sngcpp { namespace pp {

void Init()
{
    InitTextTokenCppTokenMap();
    InitPPTokenTextTokenMap();
}

void Done()
{
}

} } // namespace sngcpp::pp
