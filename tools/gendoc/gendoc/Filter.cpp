// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <gendoc/gendoc/Filter.hpp>
#include <soulng/rex/Match.hpp>

namespace gendoc {

Filter::Filter(soulng::rex::Context& context_, Type type_, const std::u32string& pattern_) : type(type_), pattern(pattern_), nfa(soulng::rex::CompileFilePattern(context_, pattern))
{
}

void Filter::Apply(File& file)
{
    bool match = soulng::rex::PatternMatch(file.Name(), nfa);
    if (match)
    {
        switch (type)
        {
            case Type::include:
            {
                file.SetIncluded(true);
                break;
            }
            case Type::exclude:
            {
                file.SetIncluded(false);
                break;
            }
        }
    }
}

FilterList::FilterList() : filters()
{
}

void FilterList::Add(Filter& filter)
{
    filters.push_back(filter);
}

void FilterList::Apply(File& file)
{
    for (Filter& filter : filters)
    {
        filter.Apply(file);
    }
}

} // namespace gendoc
