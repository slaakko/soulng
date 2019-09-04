
// this file has been automatically generated from 'D:/work/soulng/slg/RegExLexer.lexer' using soulng lexer generator slg version 1.0.0

#include <map>
std::map<std::u32string, int> tokenIdMapRegExTokens;
#include <soulng/slg/RegExTokens.hpp>

namespace RegExTokens
{
    void InitTokenIdMap()
    {
        tokenIdMapRegExTokens[U"ALT"] = 7;
        tokenIdMapRegExTokens[U"CHAR"] = 15;
        tokenIdMapRegExTokens[U"DOT"] = 11;
        tokenIdMapRegExTokens[U"ESCAPE"] = 12;
        tokenIdMapRegExTokens[U"INVERSE"] = 13;
        tokenIdMapRegExTokens[U"LBRACE"] = 5;
        tokenIdMapRegExTokens[U"LBRACKET"] = 3;
        tokenIdMapRegExTokens[U"LPAREN"] = 1;
        tokenIdMapRegExTokens[U"MINUS"] = 14;
        tokenIdMapRegExTokens[U"PLUS"] = 9;
        tokenIdMapRegExTokens[U"QUEST"] = 10;
        tokenIdMapRegExTokens[U"RBRACE"] = 6;
        tokenIdMapRegExTokens[U"RBRACKET"] = 4;
        tokenIdMapRegExTokens[U"RPAREN"] = 2;
        tokenIdMapRegExTokens[U"STAR"] = 8;
    }

    int GetTokenId(const std::u32string& tokenName)
    {
        auto it = tokenIdMapRegExTokens.find(tokenName);
        if (it != tokenIdMapRegExTokens.cend())
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
        "LPAREN",
        "RPAREN",
        "LBRACKET",
        "RBRACKET",
        "LBRACE",
        "RBRACE",
        "ALT",
        "STAR",
        "PLUS",
        "QUEST",
        "DOT",
        "ESCAPE",
        "INVERSE",
        "MINUS",
        "CHAR"
    };

    const char* GetTokenName(int tokenId)
    {
        return tokenName[tokenId];
    }

    const char* tokenInfo[] =
    {
        "end of file",
        "'('",
        "')'",
        "'['",
        "']'",
        "'{'",
        "'}",
        "'|'",
        "'*'",
        "'+'",
        "'?'",
        "'.'",
        "escape",
        "'^'",
        "'-'",
        "character"
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
