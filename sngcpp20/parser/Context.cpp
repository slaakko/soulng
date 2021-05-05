// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/parser/Context.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>

namespace sngcpp::par {

Context::Context() : flags(ContextFlags::none), node(nullptr), symbolTable(nullptr)
{
}

void Context::PushFlags()
{
    flagStack.push(flags);
}

void Context::PopFlags()
{
    flags = flagStack.top();
    flagStack.pop();
}

void Context::PushSetFlag(ContextFlags flag)
{
    PushFlags();
    flags = flags | flag;
}

void Context::PushResetFlag(ContextFlags flag)
{
    PushFlags();
    flags = flags & ~flag;
}

void Context::PushNode(sngcpp::ast::Node* node_)
{
    nodeStack.push(node);
    node = node_;
}

void Context::PopNode()
{
    node = nodeStack.top();
    nodeStack.pop();
}

} // namespace sngcpp::par
