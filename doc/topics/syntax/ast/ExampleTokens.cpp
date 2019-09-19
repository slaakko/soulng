
// this file has been automatically generated from 'D:/work/soulng-project/doc/topics/syntax/ast/ExampleLexer.lexer' using soulng lexer generator slg version 1.0.0

#include "ExampleTokens.hpp"
#include <map>

namespace ExampleTokens
{
    std::map<std::u32string, int> tokenIdMap;

    void InitTokenIdMap()
    {
        tokenIdMap[U"ID"] = 1;
        tokenIdMap[U"LPAREN"] = 3;
        tokenIdMap[U"RPAREN"] = 4;
        tokenIdMap[U"SEMICOLON"] = 5;
        tokenIdMap[U"WHILE"] = 2;
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
        "ID",
        "WHILE",
        "LPAREN",
        "RPAREN",
        "SEMICOLON"
    };

    const char* GetTokenName(int tokenId)
    {
        return tokenName[tokenId];
    }

    const char* tokenInfo[] =
    {
        "end of file",
        "identifier",
        "'while'",
        "'('",
        "')'",
        "';'"
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
