#ifndef RegExTokens_HPP
#define RegExTokens_HPP

// this file has been automatically generated from 'D:/work/soulng-project/soulng/slg/RegExLexer.lexer' using soulng lexer generator slg version 2.0.0

#include <string>

namespace RegExTokens
{
    const int END = 0;
    const int LPAREN = 1;
    const int RPAREN = 2;
    const int LBRACKET = 3;
    const int RBRACKET = 4;
    const int LBRACE = 5;
    const int RBRACE = 6;
    const int ALT = 7;
    const int STAR = 8;
    const int PLUS = 9;
    const int QUEST = 10;
    const int DOT = 11;
    const int ESCAPE = 12;
    const int INVERSE = 13;
    const int MINUS = 14;
    const int CHAR = 15;

    void InitTokenIdMap();
    int GetTokenId(const std::u32string& tokenName);
    const char* GetTokenName(int tokenId);
    const char* GetTokenInfo(int tokenId);
}
#endif
