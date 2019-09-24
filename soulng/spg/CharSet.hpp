// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SPG_CHAR_SET_INCLUDED
#define SOULNG_SPG_CHAR_SET_INCLUDED
#include <soulng/parser/Range.hpp>
#include <vector>

namespace soulng { namespace spg {

class CharSet
{
public:
    CharSet();
    void SetInverse() { inverse = true; }
    bool Inverse() const { return inverse; }
    const std::vector<soulng::parser::Range>& Ranges() const { return ranges; }
    void AddRange(const soulng::parser::Range& range);
private:
    bool inverse;
    std::vector<soulng::parser::Range> ranges;
};

} } // namespae soulng::spg

#endif // SOULNG_SPG_CHAR_SET_INCLUDED
