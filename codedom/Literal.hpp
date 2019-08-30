// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_CODEDOM_LITERAL_INCLUDED
#define SOULNG_CODEDOM_LITERAL_INCLUDED
#include <soulng/codedom/Object.hpp>

namespace soulng { namespace codedom {

class CODEDOM_API Literal: public CppObject
{
public:
    Literal(const std::u32string& name_);
    int Rank() const override { return 24; }
    void Accept(Visitor& visitor) override;
};

} } // namespace soulng::codedom

#endif // SOULNG_CODEDOM_LITERAL_INCLUDED

