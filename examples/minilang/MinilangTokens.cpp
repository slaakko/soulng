
// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/Minilang.lexer' using soulng lexer generator slg version 1.1.0

#include "MinilangTokens.hpp"
#include <map>

namespace MinilangTokens
{
    std::map<std::u32string, int> tokenIdMap;

    void InitTokenIdMap()
    {
        tokenIdMap[U"ASSIGN"] = 29;
        tokenIdMap[U"BOOL"] = 6;
        tokenIdMap[U"COMMA"] = 30;
        tokenIdMap[U"DIV"] = 20;
        tokenIdMap[U"ELSE"] = 2;
        tokenIdMap[U"EQ"] = 23;
        tokenIdMap[U"FALSE"] = 11;
        tokenIdMap[U"GEQ"] = 26;
        tokenIdMap[U"GREATER"] = 28;
        tokenIdMap[U"ID"] = 8;
        tokenIdMap[U"IF"] = 1;
        tokenIdMap[U"INT"] = 5;
        tokenIdMap[U"INTLIT"] = 9;
        tokenIdMap[U"LBRACE"] = 15;
        tokenIdMap[U"LEQ"] = 25;
        tokenIdMap[U"LESS"] = 27;
        tokenIdMap[U"LPAREN"] = 13;
        tokenIdMap[U"MINUS"] = 18;
        tokenIdMap[U"MOD"] = 21;
        tokenIdMap[U"MUL"] = 19;
        tokenIdMap[U"NEQ"] = 24;
        tokenIdMap[U"NOT"] = 22;
        tokenIdMap[U"PLUS"] = 17;
        tokenIdMap[U"RBRACE"] = 16;
        tokenIdMap[U"RETURN"] = 4;
        tokenIdMap[U"RPAREN"] = 14;
        tokenIdMap[U"SEMICOLON"] = 12;
        tokenIdMap[U"TRUE"] = 10;
        tokenIdMap[U"VOID"] = 7;
        tokenIdMap[U"WHILE"] = 3;
    }

    int GetTokenId(const std::u32string& tokenName)
    {
        auto it = tokenIdMap.find(tokenName);
        if (it != tokenIdMap.cend())
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
