// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_LEXER_TRIVIAL_LEXER_INCLUDED
#define SOULNG_LEXER_TRIVIAL_LEXER_INCLUDED
#include <soulng/lexer/Lexer.hpp>

class SOULNG_LEXER_API TrivialLexer : public soulng::lexer::Lexer
{
public:
    TrivialLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    int NextState(int state, char32_t c) override;
};

SOULNG_LEXER_API std::string GetTokenInfo(int tokenId);

#endif // SOULNG_LEXER_TRIVIAL_LEXER_INCLUDED
