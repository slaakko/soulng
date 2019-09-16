
// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/minilang.lexer' using soulng lexer generator slg version 1.0.0

#include <map>
std::map<std::u32string, int> tokenIdMapMinilangTokens;
#include "MinilangTokens.hpp"

namespace MinilangTokens
{
    void InitTokenIdMap()
    {
        tokenIdMapMinilangTokens[U"ASSIGN"] = 29;
        tokenIdMapMinilangTokens[U"BOOL"] = 6;
        tokenIdMapMinilangTokens[U"COMMA"] = 30;
        tokenIdMapMinilangTokens[U"DIV"] = 20;
        tokenIdMapMinilangTokens[U"ELSE"] = 2;
        tokenIdMapMinilangTokens[U"EQ"] = 23;
        tokenIdMapMinilangTokens[U"FALSE"] = 11;
        tokenIdMapMinilangTokens[U"GEQ"] = 26;
        tokenIdMapMinilangTokens[U"GREATER"] = 28;
        tokenIdMapMinilangTokens[U"ID"] = 8;
        tokenIdMapMinilangTokens[U"IF"] = 1;
        tokenIdMapMinilangTokens[U"INT"] = 5;
        tokenIdMapMinilangTokens[U"INTLIT"] = 9;
        tokenIdMapMinilangTokens[U"LBRACE"] = 15;
        tokenIdMapMinilangTokens[U"LEQ"] = 25;
        tokenIdMapMinilangTokens[U"LESS"] = 27;
        tokenIdMapMinilangTokens[U"LPAREN"] = 13;
        tokenIdMapMinilangTokens[U"MINUS"] = 18;
        tokenIdMapMinilangTokens[U"MOD"] = 21;
        tokenIdMapMinilangTokens[U"MUL"] = 19;
        tokenIdMapMinilangTokens[U"NEQ"] = 24;
        tokenIdMapMinilangTokens[U"NOT"] = 22;
        tokenIdMapMinilangTokens[U"PLUS"] = 17;
        tokenIdMapMinilangTokens[U"RBRACE"] = 16;
        tokenIdMapMinilangTokens[U"RETURN"] = 4;
        tokenIdMapMinilangTokens[U"RPAREN"] = 14;
        tokenIdMapMinilangTokens[U"SEMICOLON"] = 12;
        tokenIdMapMinilangTokens[U"TRUE"] = 10;
        tokenIdMapMinilangTokens[U"VOID"] = 7;
        tokenIdMapMinilangTokens[U"WHILE"] = 3;
    }

    int GetTokenId(const std::u32string& tokenName)
    {
        auto it = tokenIdMapMinilangTokens.find(tokenName);
        if (it != tokenIdMapMinilangTokens.cend())
        {
            return it->second;
        }
        else
        {
            return -1;
        }
    }

    const char* tokenName[] =
    {
        "END",
        "IF",
        "ELSE",
        "WHILE",
        "RETURN",
        "INT",
        "BOOL",
        "VOID",
        "ID",
        "INTLIT",
        "TRUE",
        "FALSE",
        "SEMICOLON",
        "LPAREN",
        "RPAREN",
        "LBRACE",
        "RBRACE",
        "PLUS",
        "MINUS",
        "MUL",
        "DIV",
        "MOD",
        "NOT",
        "EQ",
        "NEQ",
        "LEQ",
        "GEQ",
        "LESS",
        "GREATER",
        "ASSIGN",
        "COMMA"
    };

    const char* GetTokenName(int tokenId)
    {
        return tokenName[tokenId];
    }

    const char* tokenInfo[] =
    {
        "end of file",
        "'if'",
        "'else'",
        "'while'",
        "'return'",
        "'int'",
        "'bool'",
        "'void'",
        "identifier",
        "integer literal",
        "'true'",
        "'false'",
        "';'",
        "'('",
        "')'",
        "'{'",
        "'}'",
        "'+'",
        "'-'",
        "'*'",
        "'/'",
        "'%''",
        "'!'",
        "'=='",
        "'!='",
        "'<='",
        "'>='",
        "'<'",
        "'>'",
        "'='",
        "','"
    };

    const char* GetTokenInfo(int tokenId)
    {
        return tokenInfo[tokenId];
    }

    struct Initializer
    {
        Initializer() { InitTokenIdMap(); }
    };

    Initializer initializer;
}
