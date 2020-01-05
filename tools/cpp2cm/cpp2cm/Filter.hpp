// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef CPP2CM_CPP2CM_FILTER_INCLUDED
#define CPP2CM_CPP2CM_FILTER_INCLUDED
#include <cpp2cm/cpp2cm/File.hpp>
#include <soulng/rex/Nfa.hpp>

namespace cpp2cm {

class Filter
{
public:
    enum class Type { include, exclude };
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

} // namespace cpp2cm

#endif // CPP2CM_CPP2CM_FILTER_INCLUDED
