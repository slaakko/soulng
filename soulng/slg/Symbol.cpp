// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/slg/Symbol.hpp>
#include <soulng/slg/LexerContext.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/TextUtils.hpp>
#include <algorithm>

namespace soulng { namespace slg {

using namespace soulng::unicode;

Symbol::Symbol() : contained(false), dontSetContained(false)
{
}

Symbol::~Symbol()
{
}

void Symbol::SetName(const std::string& name_)
{
    name = name_;
}

Char::Char(char32_t chr_) : chr(chr_)
{
    SetName("(" + ToUtf8(std::u32string(1, chr)) + ")");
}

bool Char::Match(char32_t c)
{
    return chr == c;
}

void Char::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

Any::Any()
{
    SetName("(*)");
}

bool Any::Match(char32_t c)
{
    return true;
}

void Any::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

Range::Range(char32_t start_, char32_t end_) : start(start_), end(end_)
{
    SetName("(" + ToUtf8(std::u32string(1, start)) + "-" + ToUtf8(std::u32string(1, end)) + ")");
}

bool Range::Match(char32_t c)
{
    return c >= start && c <= end;
}

void Range::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void Range::Print(CodeFormatter& formatter)
{
    formatter.Write(soulng::unicode::ToUtf8(soulng::util::CharStr(start)));
    formatter.Write("-");
    formatter.Write(soulng::unicode::ToUtf8(soulng::util::CharStr(end)));
}

bool Intersect(const Range& left, const Range& right)
{
    if (left.IsEmpty() || right.IsEmpty()) return false;
    if (left.Start() <= right.Start())
    {
        return right.Start() >= left.Start() && right.Start() <= left.End();
    }
    else
    {
        return left.Start() >= right.Start() && left.Start() <= right.End();
    }
}

Range operator&(const Range& left, const Range& right)
{
    if (Intersect(left, right))
    {
        Range intersection(std::max(left.Start(), right.Start()), std::min(left.End(), right.End()));
        return intersection;
    }
    return Range(static_cast<char32_t>(1), static_cast<char32_t>(0));
}

std::vector<Range> operator-(const Range& left, const Range& right)
{
    std::vector<Range> ranges;
    if (right.Start() <= left.Start() && right.End() >= left.End())
    {
        return ranges;
    }
    else if (right.Start() > left.End() || right.End() < left.Start())
    {
        ranges.push_back(left);
    }
    else
    {
        if (right.Start() >= left.Start() && right.Start() <= left.End())
        {
            ranges.push_back(Range(left.Start(), right.Start() - 1));
        }
        if (right.End() >= left.Start() && right.End() <= left.End())
        {
            ranges.push_back(Range(right.End() + 1, left.End()));
        }
    }
    return ranges;
}

std::vector<Range> operator~(const Range& that)
{
    std::vector<Range> result;
    if (that.Start() > char32_t(1))
    {
        result.push_back(Range(static_cast<char32_t>(1), static_cast<char32_t>(that.Start() - 1)));
    }
    if (static_cast<uint32_t>(that.End()) < 0x110000)
    {
        result.push_back(Range(static_cast<char32_t>(that.End() + 1), static_cast<char32_t>(0x10FFFF)));
    }
    return result;
}

Class::Class(int index_) : index(index_), inverse(false)
{
    SetName("[" + std::to_string(index) + "]");
}

void Class::SetIndex(int index_)
{
    index = index_;
    SetName("[" + std::to_string(index) + "]");
}

Class* Class::MakeCanonical(LexerContext& lexerContext)
{
    std::vector<Range> rangeVec;
    Class* canonicalClass = new Class(-1);
    for (Symbol* symbol : symbols)
    {
        if (symbol->IsChar())
        {
            Char* chr = static_cast<Char*>(symbol);
            rangeVec.push_back(Range(chr->Chr(), chr->Chr()));
        }
        else if (symbol->IsRange())
        {
            Range* range = static_cast<Range*>(symbol);
            rangeVec.push_back(*range);
        }
        else if (symbol->IsAny())
        {
            throw std::runtime_error("class contains any");
        }
        else if (symbol->IsClass())
        {
            throw std::runtime_error("class contains class");
        }
    }
    for (const Range& range : rangeVec)
    {
        canonicalClass->ranges.push_back(range);
    }
    if (inverse)
    {
        canonicalClass->MakeInverse(lexerContext);
    }
    return canonicalClass;
}

void Class::MakeMinimal(LexerContext& lexerContext)
{
    std::vector<Range> rangeVec;
    for (const Range& range : ranges)
    {
        rangeVec.push_back(range);
    }
    ranges.clear();
    std::sort(rangeVec.begin(), rangeVec.end());
    std::vector<Range>::iterator e = std::unique(rangeVec.begin(), rangeVec.end());
    rangeVec.erase(e, rangeVec.end());
    bool changed = true;
    while (changed)
    {
        changed = false;
        std::vector<Range> combinedRanges;
        for (int i = 0; i < rangeVec.size(); ++i)
        {
            bool combined = false;
            Range current = rangeVec[i];
            if (i > 0)
            {
                Range left = rangeVec[i - 1];
                if (left.End() + 1 == current.Start())
                {
                    combinedRanges.push_back(Range(left.Start(), current.End()));
                    combined = true;
                }
            }
            if (i < rangeVec.size() - 1)
            {
                Range right = rangeVec[i + 1];
                if (current.End() + 1 == right.Start())
                {
                    combinedRanges.push_back(Range(current.Start(), right.End()));
                    combined = true;
                }
            }
            if (combined)
            {
                changed = true;
            }
            else
            {
                combinedRanges.push_back(current);
            }
        }
        std::sort(combinedRanges.begin(), combinedRanges.end());
        std::vector<Range>::iterator e = std::unique(combinedRanges.begin(), combinedRanges.end());
        combinedRanges.erase(e, combinedRanges.end());
        std::swap(rangeVec, combinedRanges);
    }
    symbols.clear();
    chars.clear();
    for (const Range& range : rangeVec)
    {
        if (range.IsEmpty()) continue;
        ranges.push_back(range);
        if (chars.empty())
        {
            AddChar(range.Start());
        }
    }
}

void Class::MakeInverse(LexerContext& lexerContext)
{
    std::vector<Range> rangeVec;
    for (const Range& range : ranges)
    {
        rangeVec.push_back(range);
    }
    ranges.clear();
    std::vector<Range> inverseRanges;
    inverseRanges.push_back(Range(1, 0x10FFFF));
    for (const Range& range : rangeVec)
    {
        std::vector<Range> newInverse;
        for (const Range& i : inverseRanges)
        {
            if (Intersect(range, i))
            {
                Range intersection = range & i;
                Range left = Range(i.Start(), intersection.Start() - 1);
                if (!left.IsEmpty())
                {
                    newInverse.push_back(left);
                }
                Range right = Range(intersection.End() + 1, i.End());
                if (!right.IsEmpty())
                {
                    newInverse.push_back(right);
                }
            }
            else
            {
                newInverse.push_back(i);
            }
        }
        std::swap(inverseRanges, newInverse);
    }
    symbols.clear();
    chars.clear();
    for (const Range& range : inverseRanges)
    {
        ranges.push_back(range);
        if (chars.empty())
        {
            AddChar(range.Start());
        }
    }
    MakeMinimal(lexerContext);
    inverse = false;
}

Class* Class::Clone()
{
    Class* cls = new Class(-1);
    for (Symbol* symbol : symbols)
    {
        cls->AddSymbol(symbol);
    }
    for (char32_t c : chars)
    {
        cls->AddChar(c);
    }
    return cls;
}

bool Class::Match(char32_t c)
{
    bool match = false;
    for (Symbol* symbol : symbols)
    {
        if (symbol->Match(c))
        {
            match = true;
            break;
        }
    }
    return match != inverse;
}

void Class::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void Class::AddSymbol(Symbol* symbol)
{
    symbol->SetContained();
    symbols.push_back(symbol);
}

void Class::AddChar(char32_t c)
{
    chars.push_back(c);
}

void Class::Print(CodeFormatter& formatter)
{
    formatter.Write("{");
    for (auto& range : ranges)
    {
        range.Print(formatter);
    }
    formatter.Write("}");
}

bool operator==(const Class& left, const Class& right)
{
    if (left.Symbols().size() != right.Symbols().size()) return false;
    int n = left.Symbols().size();
    for (int i = 0; i < n; ++i)
    {
        Symbol* leftSymbol = left.Symbols()[i];
        Symbol* rightSymbol = right.Symbols()[i];
        if (leftSymbol->IsRange() && rightSymbol->IsRange())
        {
            const Range* leftRange = static_cast<const Range*>(leftSymbol);
            const Range* rightRange = static_cast<const Range*>(rightSymbol);
            if (!(*leftRange == *rightRange))
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

struct RangeEndLess
{
    bool operator()(const Range& left, const Range& right) const
    {
        if (left.End() < right.End()) return true;
        if (left.End() > right.End()) return false;
        return left.Start() < right.Start();
    }
};

bool Intersect(const Class& left, const Class& right)
{
    for (Symbol* leftSymbol : left.Symbols())
    {
        if (leftSymbol->IsRange())
        {
            Range* leftRange = static_cast<Range*>(leftSymbol);
            for (Symbol* rightSymbol : right.Symbols())
            {
                if (rightSymbol->IsRange())
                {
                    Range* rightRange = static_cast<Range*>(rightSymbol);
                    if (Intersect(*leftRange, *rightRange))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

Class* MakeIntertersection(const Class& left, const Class& right, LexerContext& lexerContext)
{
    std::vector<Range> leftRanges;
    for (Symbol* leftSymbol : left.Symbols())
    {
        if (leftSymbol->IsRange())
        {
            Range* leftRange = static_cast<Range*>(leftSymbol);
            leftRanges.push_back(*leftRange);
        }
    }
    std::vector<Range> rightRanges;
    for (Symbol* rightSymbol : right.Symbols())
    {
        if (rightSymbol->IsRange())
        {
            Range* rightRange = static_cast<Range*>(rightSymbol);
            rightRanges.push_back(*rightRange);
        }
    }
    std::vector<Range> intersection;
    for (const Range& left : leftRanges)
    {
        std::vector<Range>::iterator start = std::lower_bound(rightRanges.begin(), rightRanges.end(), left);
        std::vector<Range>::iterator end = std::upper_bound(rightRanges.begin(), rightRanges.end(), left, RangeEndLess());
        if (start != rightRanges.begin()) --start;
        if (end < rightRanges.end()) ++end;
        for (std::vector<Range>::iterator i = start; i != end; ++i)
        {
            const Range& right = *i;
            if (left == right)
            {
                intersection.push_back(left);
                break;
            }
            else if (Intersect(left, right))
            {
                intersection.push_back(left & right);
            }
        }
    }
    std::sort(intersection.begin(), intersection.end());
    std::vector<Range>::iterator e = std::unique(intersection.begin(), intersection.end());
    intersection.erase(e, intersection.end());
    Class* cls = lexerContext.MakeClass();
    for (const Range& i : intersection)
    {
        cls->AddSymbol(lexerContext.MakeRange(i.Start(), i.End()));
        if (cls->Chars().empty())
        {
            cls->AddChar(i.Start());
        }
    }
    return cls;
}

Class* MakeDifference(const Class& left, const Class& right, LexerContext& lexerContext)
{
    std::vector<Range> leftRanges;
    for (Symbol* leftSymbol : left.Symbols())
    {
        if (leftSymbol->IsRange())
        {
            Range* leftRange = static_cast<Range*>(leftSymbol);
            leftRanges.push_back(*leftRange);
        }
    }
    std::vector<Range> rightRanges;
    for (Symbol* rightSymbol : right.Symbols())
    {
        if (rightSymbol->IsRange())
        {
            Range* rightRange = static_cast<Range*>(rightSymbol);
            rightRanges.push_back(*rightRange);
        }
    }
    std::vector<Range> difference;
    for (const Range& left : leftRanges)
    {
        bool found = false;
        std::vector<Range> diffs;
        std::vector<Range>::iterator start = std::lower_bound(rightRanges.begin(), rightRanges.end(), left);
        std::vector<Range>::iterator end = std::upper_bound(rightRanges.begin(), rightRanges.end(), left, RangeEndLess());
        if (start != rightRanges.begin()) --start;
        if (end < rightRanges.end()) ++end;
        for (std::vector<Range>::iterator i = start; i != end; ++i)
        {
            const Range& right = *i;
            if (left == right)
            {
                found = true;
                break;
            }
            else
            {
                if (Intersect(left, right))
                {
                    Range intersection = left & right;
                    Range l = Range(left.Start(), intersection.Start() - 1);
                    if (!l.IsEmpty())
                    {
                        diffs.push_back(l);
                    }
                    Range r = Range(intersection.End() + 1, left.End());
                    if (!r.IsEmpty())
                    {
                        diffs.push_back(r);
                    }
                }
            }
        }
        if (!found)
        {
            if (diffs.empty())
            {
                difference.push_back(left);
            }
            else
            {
                for (const Range& diff : diffs)
                {
                    difference.push_back(diff);
                }
            }
        }
    }
    Class* d = lexerContext.MakeClass();
    for (const Range& r : difference)
    {
        d->AddSymbol(lexerContext.MakeRange(r.Start(), r.End()));
        if (d->Chars().empty())
        {
            d->AddChar(r.Start());
        }
    }
    d->MakeMinimal(lexerContext);
    return d;
}

} } // namespace soulng::slg
