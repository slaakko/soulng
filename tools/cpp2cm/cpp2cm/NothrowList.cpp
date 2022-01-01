// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <cpp2cm/cpp2cm/NothrowList.hpp>
#include <soulng/rex/Match.hpp>

namespace cpp2cm {

Item::Item(Type type_, const std::u32string& text_, bool default_) : type(type_), text(text_), include(default_)
{
}

NothrowPattern::NothrowPattern(soulng::rex::Context& context_, Kind kind_, Item::Type type_, const std::u32string& pattern_) :
    kind(kind_), type(type_), pattern(pattern_), nfa(soulng::rex::CompileFilePattern(context_, pattern_))
{
}

void NothrowPattern::ApplyTo(Item& item)
{
    if (item.type == type)
    {
        bool match = soulng::rex::PatternMatch(item.text, nfa);
        if (match)
        {
            if (kind == Kind::include)
            {
                item.include = true;
            }
            else if (kind == Kind::exclude)
            {
                item.include = false;
            }
        }
    }
}

NothrowList::NothrowList(bool verbose_) : verbose(verbose_)
{
}

void NothrowList::AddPattern(const NothrowPattern& pattern)
{
    patterns.push_back(pattern);
}

void NothrowList::ApplyTo(Item& item)
{
    for (auto& pattern : patterns)
    {
        pattern.ApplyTo(item);
    }
}

} // namespace cpp2cm
