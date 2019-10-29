// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef GENDOC_GENDOC_FILTER_INCLUDED
#define GENDOC_GENDOC_FILTER_INCLUDED
#include <gendoc/gendoc/File.hpp>
#include <soulng/rex/Nfa.hpp>

namespace gendoc {

class Filter
{
public:
    enum Type { include, exclude };
    Filter(soulng::rex::Context& context_, Type type_, const std::u32string& pattern_);
    void Apply(File& file);
private:
    Type type;
    std::u32string pattern;
    soulng::rex::Nfa nfa;
};

class FilterList
{
public:
    FilterList();
    void Add(Filter& filter);
    void Apply(File& file);
private:
    std::vector<Filter> filters;
};


} // namespace gendoc

#endif // GENDOC_GENDOC_FILTER_INCLUDED
