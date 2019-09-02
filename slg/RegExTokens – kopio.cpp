#include <map>
static std::map<std::u32string, int> tokenIdMap;
#include <soulng/slg/RegExTokens.hpp>

static void Init()
{
    tokenIdMap[U"ALT"] = 7;
    tokenIdMap[U"CHAR"] = 15;
    tokenIdMap[U"DOT"] = 11;
    tokenIdMap[U"ESCAPE"] = 12;
    tokenIdMap[U"INVERSE"] = 13;
    tokenIdMap[U"LBRACE"] = 5;
    tokenIdMap[U"LBRACKET"] = 3;
    tokenIdMap[U"LPAREN"] = 1;
    tokenIdMap[U"MINUS"] = 14;
    tokenIdMap[U"PLUS"] = 9;
    tokenIdMap[U"QUEST"] = 10;
    tokenIdMap[U"RBRACE"] = 6;
    tokenIdMap[U"RBRACKET"] = 4;
    tokenIdMap[U"RPAREN"] = 2;
    tokenIdMap[U"STAR"] = 8;
}

namespace RegExTokens
{
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

    static const char* tokenName[] =
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

    static const char* tokenInfo[] =
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
        Initializer() { Init(); }
    };

    Initializer initializer;
}
