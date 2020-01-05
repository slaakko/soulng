// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef CPP2CM_CPP2CM_NOTHROW_LIST_INCLUDED
#define CPP2CM_CPP2CM_NOTHROW_LIST_INCLUDED
#include <soulng/rex/Nfa.hpp>
#include <string>

namespace cpp2cm {

struct Item
{
    enum class Type { none, file, class_, function };
    Item(Type type_, const std::u32string& text_, bool default_);
    Type type;
    std::u32string text;
    bool include;
};

struct NothrowPattern
{
    enum class Kind { include, exclude };
    NothrowPattern(soulng::rex::Context& context_, Kind kind_, Item::Type type_, const std::u32string& pattern_);
    void ApplyTo(Item& item);
    Kind kind;
    Item::Type type;
    std::u32string pattern;
    soulng::rex::Nfa nfa;
};

class NothrowList
{
public:
    NothrowList(bool verbose_);
    void AddPattern(const NothrowPattern& pattern);
    void ApplyTo(Item& item);
    bool Verbose() const { return verbose; }
private:
    bool verbose;
    std::vector<NothrowPattern> patterns;
};

} // namespace cpp2cm

#endif // CPP2CM_CPP2CM_NOTHROW_LIST_INCLUDED
