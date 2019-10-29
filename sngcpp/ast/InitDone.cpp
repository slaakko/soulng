// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/InitDone.hpp>
#include <sngcpp/ast/Node.hpp>

namespace sngcpp { namespace ast {

void Init()
{
    NodeInit();
}

void Done()
{
    NodeDone();
}

} } // namespace sngcpp::ast
