// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/cppcode/InitDone.hpp>
#include <soulng/cppcode/Operator.hpp>

namespace soulng { namespace cppcode  {

void Init()
{
    OperatorInit();
}

void Done()
{
    OperatorDone();
}

} } // namespace soulng::cppcode
