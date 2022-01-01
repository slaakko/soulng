// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNG2HTML_SNG2HTML_CHAR_SET_INCLUDED
#define SNG2HTML_SNG2HTML_CHAR_SET_INCLUDED
#include <soulng/parser/Range.hpp>
#include <vector>

namespace sng2html { namespace sng2html {

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

} } // namespace sng2html::sng2html

#endif // SNG2HTML_SNG2HTML_CHAR_SET_INCLUDED
