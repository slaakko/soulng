// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <cpp2cm/cpp2cm/Args.hpp>
#include <cpp2cm/cpp2cm/ArgsParser.hpp>
#include <soulng/lexer/TrivialLexer.hpp>

std::vector<int> ParseArgs(const std::u32string& args)
{
    std::vector<int> argsVec;
    TrivialLexer lexer(args, "", 0);
    ArgsParser::Parse(lexer, &argsVec);
    return argsVec;
}

int ParseInt(const std::u32string& s)
{
    int x = 0;
    for (char32_t c : s)
    {
        if (c >= '0' && c <= '9')
        {
            x = 10 * x + c - '0';
        }
    }
    return x;
}
