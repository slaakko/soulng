// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_PARSING_MATCH_INCLUDED
#define SOULNG_PARSING_MATCH_INCLUDED

namespace soulng { namespace parsing {

class Match
{
public:
    Match(bool hit_, int length_): hit(hit_), length(length_) {}
    bool Hit() const { return hit; }
    int Length() const { return length; }
    void Concatenate(const Match& that)
    {
        length += that.length;
    }
    static Match Empty() 
    {
        return Match(true, 0);
    }
    static Match One()
    {
        return Match(true, 1);
    }
    static Match Nothing()
    {
        return Match(false, -1);
    }
private:
    bool hit;
    int length;
};

} } // namespace soulng::parsing

#endif // SOULNG_PARSING_MATCH_INCLUDED

