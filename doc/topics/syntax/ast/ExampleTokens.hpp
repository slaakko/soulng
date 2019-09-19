#ifndef ExampleTokens_HPP
#define ExampleTokens_HPP

// this file has been automatically generated from 'D:/work/soulng-project/doc/topics/syntax/ast/ExampleLexer.lexer' using soulng lexer generator slg version 1.0.0

#include <string>

namespace ExampleTokens
{
    const int END = 0;
    const int ID = 1;
    const int WHILE = 2;
    const int LPAREN = 3;
    const int RPAREN = 4;
    const int SEMICOLON = 5;

    void InitTokenIdMap();
    int GetTokenId(const std::u32string& tokenName);
    const char* GetTokenName(int tokenId);
    const char* GetTokenInfo(int tokenId);
}
#endif
