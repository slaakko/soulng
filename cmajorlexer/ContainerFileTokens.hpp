#ifndef ContainerFileTokens_HPP
#define ContainerFileTokens_HPP
#include <soulng/cmajorlexer/CmajorLexerApi.hpp>
#include <soulng/cmajorlexer/TokenValueParsers.hpp>

#undef NULL

namespace ContainerFileTokens
{
    const int END = 0;
    const int PROJECT = 1;
    const int SOLUTION = 2;
    const int REFERENCE = 3;
    const int SOURCE = 4;
    const int TEXT = 5;
    const int TARGET = 6;
    const int PROGRAM = 7;
    const int LIBRARY = 8;
    const int UNITTEST = 9;
    const int ACTIVEPROJECT = 10;
    const int ID = 11;
    const int FILEPATH = 12;
    const int ASSIGN = 13;
    const int SEMICOLON = 14;
    const int DOT = 15;

    CMAJOR_LEXER_API int GetTokenId(const std::u32string& tokenName);
    CMAJOR_LEXER_API const char* GetTokenName(int tokenId);
    CMAJOR_LEXER_API const char* GetTokenInfo(int tokenId);
}
#endif
