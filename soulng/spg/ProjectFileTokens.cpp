
// this file has been automatically generated from 'C:/work/soulng/soulng/spg/ProjectFileLexer.lexer' using soulng lexer generator slg version 4.0.0

#include <soulng/spg/ProjectFileTokens.hpp>
#include <map>

namespace ProjectFileTokens
{
    std::map<std::u32string, int> tokenIdMap;

    void InitTokenIdMap()
    {
        tokenIdMap[U"DOT"] = 5;
        tokenIdMap[U"FILEPATH"] = 4;
        tokenIdMap[U"ID"] = 3;
        tokenIdMap[U"PROJECT"] = 1;
        tokenIdMap[U"RECOVERY"] = 7;
        tokenIdMap[U"RULES"] = 9;
        tokenIdMap[U"SEMICOLON"] = 6;
        tokenIdMap[U"SOURCE"] = 2;
        tokenIdMap[U"TOKENS"] = 8;
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
        "PROJECT",
        "SOURCE",
        "ID",
        "FILEPATH",
        "DOT",
        "SEMICOLON",
        "RECOVERY",
        "TOKENS",
        "RULES"
    };

    const char* GetTokenName(int tokenId)
    {
        return tokenName[tokenId];
    }

    const char* tokenInfo[] =
    {
        "end of file",
        "'project'",
        "'source'",
        "identifier",
        "file path",
        "'.'",
        "';'",
        "'recovery'",
        "'tokens'",
        "'rules'"
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
