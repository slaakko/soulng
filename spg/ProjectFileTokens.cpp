
// this file has been automatically generated from 'D:/work/soulng/spg/ProjectFileLexer.lexer' using soulng lexer generator slg version 1.0.0

#include <map>
static std::map<std::u32string, int> tokenIdMap;
#include <soulng/spg/ProjectFileTokens.hpp>

static void Init()
{
    tokenIdMap[U"DOT"] = 5;
    tokenIdMap[U"FILEPATH"] = 4;
    tokenIdMap[U"ID"] = 3;
    tokenIdMap[U"PROJECT"] = 1;
    tokenIdMap[U"SEMICOLON"] = 6;
    tokenIdMap[U"SOURCE"] = 2;
}

namespace ProjectFileTokens
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
        "PROJECT",
        "SOURCE",
        "ID",
        "FILEPATH",
        "DOT",
        "SEMICOLON"
    };

    const char* GetTokenName(int tokenId)
    {
        return tokenName[tokenId];
    }

    static const char* tokenInfo[] =
    {
        "end of file",
        "'project'",
        "'source'",
        "identifier",
        "file path",
        "'.'",
        "';'"
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
