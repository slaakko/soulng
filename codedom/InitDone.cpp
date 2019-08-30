// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/codedom/InitDone.hpp>
#include <soulng/codedom/Operator.hpp>

namespace soulng { namespace codedom {

void Init()
{
    OperatorInit();
}

void Done()
{
    OperatorDone();
}

} } // namespace soulng::codedom
