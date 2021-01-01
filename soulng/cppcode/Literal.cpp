// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/cppcode/Literal.hpp>
#include <soulng/cppcode/Visitor.hpp>

namespace soulng { namespace cppcode  {

Literal::Literal(const std::u32string& name_): CppObject(name_)
{
}

void Literal::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} } // namespace soulng::cppcode
