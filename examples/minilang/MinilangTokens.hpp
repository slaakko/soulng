#ifndef MinilangTokens_HPP
#define MinilangTokens_HPP

// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/Minilang.lexer' using soulng lexer generator slg version 1.1.0

#include <string>

namespace MinilangTokens
{
    const int END = 0;
    const int IF = 1;
    const int ELSE = 2;
    const int WHILE = 3;
    const int RETURN = 4;
    const int INT = 5;
    const int BOOL = 6;
    const int VOID = 7;
    const int ID = 8;
    const int INTLIT = 9;
    const int TRUE = 10;
    const int FALSE = 11;
    const int SEMICOLON = 12;
    const int LPAREN = 13;
    const int RPAREN = 14;
    const int LBRACE = 15;
    const int RBRACE = 16;
    const int PLUS = 17;
    const int MINUS = 18;
    const int MUL = 19;
    const int DIV = 20;
    const int MOD = 21;
    const int NOT = 22;
    const int EQ = 23;
    const int NEQ = 24;
    const int LEQ = 25;
    const int GEQ = 26;
    const int LESS = 27;
    const int GREATER = 28;
    const int ASSIGN = 29;
    const int COMMA = 30;

    void InitTokenIdMap();
    int GetTokenId(const std::u32string& tokenName);
    const char* GetTokenName(int tokenId);
    const char* GetTokenInfo(int tokenId);
}
#endif
