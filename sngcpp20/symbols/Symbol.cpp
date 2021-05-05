// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Symbol.hpp>
#include <sngcpp20/symbols/ContainerSymbol.hpp>

namespace sngcpp::symbols {

Symbol::Symbol(const std::u32string& name_) : name(name_), parent(nullptr)
{
}

Symbol::~Symbol()
{
}

std::u32string Symbol::FullName() const
{
    std::u32string fullName;
    if (parent)
    {
        fullName = parent->FullName();
    }
    if (!fullName.empty())
    {
        fullName.append(U"::");
    }
    fullName.append(name);
    return fullName;
}

} // sngcpp::symbols
