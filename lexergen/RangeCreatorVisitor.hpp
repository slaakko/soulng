// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_LEXERGEN_RANGE_CREATOR_VISITOR_INCLUDED
#define SOULNG_LEXERGEN_RANGE_CREATOR_VISITOR_INCLUDED
#include <soulng/lexergen/Visitor.hpp>
#include <vector>

namespace soulng { namespace lexergen {

class RangeCreatorVisitor : public Visitor
{
public:
    void Visit(Char& c) override;
    void Visit(Range& r) override;
    void Visit(Class& c) override;
    const std::vector<Range>& Ranges() const { return ranges; }
private:
    std::vector<Range> ranges;
    void AddRange(const Range& range);
};

} } // namespace soulng::lexergen

#endif // SOULNG_LEXERGEN_RANGE_CREATOR_VISITOR_INCLUDED
