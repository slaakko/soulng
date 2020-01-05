// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_CPPCODE_LITERAL_INCLUDED
#define SOULNG_CPPCODE_LITERAL_INCLUDED
#include <soulng/cppcode/Object.hpp>

namespace soulng { namespace cppcode  {

class CPPCODE_API Literal: public CppObject
{
public:
    Literal(const std::u32string& name_);
    void Accept(Visitor& visitor) override;
};

} } // namespace soulng::cppcode

#endif // SOULNG_CPPCODE_LITERAL_INCLUDED

