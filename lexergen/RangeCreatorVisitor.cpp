// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/lexergen/RangeCreatorVisitor.hpp>
#include <soulng/lexergen/Symbol.hpp>

namespace soulng { namespace lexergen {

class ComplementMakerVisitor : public Visitor
{
public:
    void Visit(Char& c) override;
    void Visit(Range& r) override;
    const std::vector<Range>& Ranges() const { return ranges; }
private:
    std::vector<Range> ranges;
};

void ComplementMakerVisitor::Visit(Char& c)
{
    Range range(c.Chr(), c.Chr());
    ranges = ~range;
}

void ComplementMakerVisitor::Visit(Range& r)
{
    ranges = ~r;
}

void RangeCreatorVisitor::Visit(Char& c)
{
    Range range(c.Chr(), c.Chr());
    AddRange(range);
}

void RangeCreatorVisitor::Visit(Range& r)
{
    AddRange(r);
}

void RangeCreatorVisitor::Visit(Class& c)
{
    if (c.Inverse())
    {
        for (Symbol* s : c.Symbols())
        {
            ComplementMakerVisitor v;
            s->Accept(v);
            for (const Range& range : v.Ranges())
            {
                AddRange(range);
            }
        }
    }
    else
    {
        for (Symbol* s : c.Symbols())
        {
            s->Accept(*this);
        }
    }
}

void RangeCreatorVisitor::AddRange(const Range& range)
{
    Range newRange = range;
    std::vector<Range> newRanges;
    for (const Range& r : ranges)
    {
        if (Intersect(newRange, r))
        {
            Range intersection = newRange & r;
            if (r < newRange)
            {
                Range left(r.Start(), static_cast<char32_t>(intersection.Start() - 1));
                if (!left.IsEmpty())
                {
                    newRanges.push_back(left);
                }
            }
            else
            {
                Range left(newRange.Start(), static_cast<char32_t>(intersection.Start() - 1));
                if (!left.IsEmpty())
                {
                    newRanges.push_back(left);
                }
            }
            newRanges.push_back(intersection);
            if (r.End() > newRange.End())
            {
                Range right(static_cast<char32_t>(intersection.End() + 1), r.End());
                newRange = right;
            }
            else
            {
                Range right(static_cast<char32_t>(intersection.End() + 1), newRange.End());
                newRange = right;
            }
        }
        else
        {
            newRanges.push_back(r);
        }
    }
    if (!newRange.IsEmpty())
    {
        newRanges.push_back(newRange);
    }
    std::swap(ranges, newRanges);
}

} } // namespace soulng::lexergen
