// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/codedom/Literal.hpp>
#include <soulng/codedom/Visitor.hpp>

namespace soulng { namespace codedom {

Literal::Literal(const std::u32string& name_): CppObject(name_)
{
}

void Literal::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} } // namespace soulng::codedom
