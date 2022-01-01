// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/InitDone.hpp>
#include <sngcpp20/ast/Node.hpp>

namespace sngcpp::ast {

void Init()
{
    NodeInit();
}

void Done()
{
    NodeDone();
}

} // namespace sngcpp::ast
