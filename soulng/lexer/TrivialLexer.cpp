// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/lexer/TrivialLexer.hpp>

TrivialLexer::TrivialLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_) : Lexer(content_, fileName_, fileIndex_)
{
}

int TrivialLexer::NextState(int state, char32_t c)
{
    token.id = static_cast<int>(c);
    token.match = lexeme;
    if (c == '\n')
    {
        ++line;
    }
    return -1;
}

std::string GetTokenInfo(int tokenId)
{
    return std::to_string(tokenId);
}
