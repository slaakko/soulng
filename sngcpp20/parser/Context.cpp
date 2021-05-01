// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/parser/Context.hpp>

namespace sngcpp::par {

Context::Context() : flags(ContextFlags::none)
{
}

void Context::PushFlag(ContextFlags flag)
{
    flagStack.push(flags);
    flags = flags | flag;
}

void Context::PopFlags()
{
    flags = flagStack.top();
    flagStack.pop();
}

} // namespace sngcpp::par
