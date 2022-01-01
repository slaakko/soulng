// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sng2html/sng2html/CharSet.hpp>

namespace sng2html { namespace sng2html {

CharSet::CharSet() : inverse(false)
{
}

void CharSet::AddRange(const soulng::parser::Range& range)
{
    ranges.push_back(range);
}

} } // namespace sng2html::sng2html
