#include <map>
static std::map<std::u32string, int> tokenIdMap;
#include "CommentTokens.hpp"

static void Init()
{
    tokenIdMap[U"ID"] = 1;
}

namespace CommentTokens
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
        "ID"
    };

    const char* GetTokenName(int tokenId)
    {
        return tokenName[tokenId];
    }

    static const char* tokenInfo[] =
    {
        "end of file",
        "identifier"
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
