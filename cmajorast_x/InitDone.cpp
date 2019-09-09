// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <cmajorast/InitDone.hpp>
#include <cmajorast/Node.hpp>
#include <cmajorast/SystemFileIndex.hpp>

namespace cmajor { namespace ast {

void Init()
{
    NodeInit();
    SystemFileIndexInit();
}

void Done()
{
    NodeDone();
}

} } // namespace cmajor::ast
