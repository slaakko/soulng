// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license

#include <soulng/spg/CharSet.hpp>

namespace soulng { namespace spg {

CharSet::CharSet() : inverse(false)
{
}

void CharSet::AddRange(const soulng::parser::Range& range)
{
    ranges.push_back(range);
}

} } // namespae soulng::spg
