#ifndef ProjectFileTokens_HPP
#define ProjectFileTokens_HPP

// this file has been automatically generated from 'D:/work/soulng/spg/ProjectFileLexer.lexer' using soulng lexer generator slg version 1.0.0

#include <soulng/spg/TokenValueParsers.hpp>
#undef NULL

namespace ProjectFileTokens
{
    const int END = 0;
    const int PROJECT = 1;
    const int SOURCE = 2;
    const int ID = 3;
    const int FILEPATH = 4;
    const int DOT = 5;
    const int SEMICOLON = 6;

    int GetTokenId(const std::u32string& tokenName);
    const char* GetTokenName(int tokenId);
    const char* GetTokenInfo(int tokenId);
}
#endif
