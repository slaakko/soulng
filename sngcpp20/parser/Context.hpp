// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef PARSER_CONTEXT_INCLUDED
#define PARSER_CONTEXT_INCLUDED
#include <stack>

namespace sngcpp::par {

enum class ContextFlags : int
{
    none = 0,
    parsingTemplate = 1 << 0
};

inline ContextFlags operator|(ContextFlags left, ContextFlags right)
{
    return ContextFlags(int(left) | int(right));
}

inline ContextFlags operator&(ContextFlags left, ContextFlags right)
{
    return ContextFlags(int(left) & int(right));
}

class Context
{
public:
    Context();
    void PushFlag(ContextFlags flag);
    void PopFlags();
    bool GetFlag(ContextFlags flag) const { return (flags & flag) != ContextFlags::none; }
private:
    ContextFlags flags;
    std::stack<ContextFlags> flagStack;
};

} // namespace sngcpp::par

#endif // PARSER_CONTEXT_INCLUDED
