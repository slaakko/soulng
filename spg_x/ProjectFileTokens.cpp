
// this file has been automatically generated from 'D:/work/soulng/spg/ProjectFileLexer.lexer' using soulng lexer generator slg version 1.0.0

#include <map>
std::map<std::u32string, int> tokenIdMapProjectFileTokens;
#include <soulng/spg/ProjectFileTokens.hpp>

namespace ProjectFileTokens
{
    void InitTokenIdMap()
    {
        tokenIdMapProjectFileTokens[U"DOT"] = 5;
        tokenIdMapProjectFileTokens[U"FILEPATH"] = 4;
        tokenIdMapProjectFileTokens[U"ID"] = 3;
        tokenIdMapProjectFileTokens[U"PROJECT"] = 1;
        tokenIdMapProjectFileTokens[U"SEMICOLON"] = 6;
        tokenIdMapProjectFileTokens[U"SOURCE"] = 2;
    }

    int GetTokenId(const std::u32string& tokenName)
    {
        auto it = tokenIdMapProjectFileTokens.find(tokenName);
        if (it != tokenIdMapProjectFileTokens.cend())
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
