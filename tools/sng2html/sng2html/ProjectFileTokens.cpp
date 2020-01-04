
// this file has been automatically generated from 'D:/work/soulng-project/tools/sng2html/sng2html/ProjectFileLexer.lexer' using soulng lexer generator slg version 3.0.0

#include <sng2html/sng2html/ProjectFileTokens.hpp>
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
        tokenIdMap[U"SEMICOLON"] = 6;
        tokenIdMap[U"SOURCE"] = 2;
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
        "SEMICOLON"
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
