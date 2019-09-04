#include <map>
static std::map<std::u32string, int> tokenIdMap;
#include <soulng/cmajorlexer/ContainerFileTokens.hpp>

static void Init()
{
    tokenIdMap[U"ACTIVEPROJECT"] = 10;
    tokenIdMap[U"ASSIGN"] = 13;
    tokenIdMap[U"DOT"] = 15;
    tokenIdMap[U"FILEPATH"] = 12;
    tokenIdMap[U"ID"] = 11;
    tokenIdMap[U"LIBRARY"] = 8;
    tokenIdMap[U"PROGRAM"] = 7;
    tokenIdMap[U"PROJECT"] = 1;
    tokenIdMap[U"REFERENCE"] = 3;
    tokenIdMap[U"SEMICOLON"] = 14;
    tokenIdMap[U"SOLUTION"] = 2;
    tokenIdMap[U"SOURCE"] = 4;
    tokenIdMap[U"TARGET"] = 6;
    tokenIdMap[U"TEXT"] = 5;
    tokenIdMap[U"UNITTEST"] = 9;
}

namespace ContainerFileTokens
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
        "SOLUTION",
        "REFERENCE",
        "SOURCE",
        "TEXT",
        "TARGET",
        "PROGRAM",
        "LIBRARY",
        "UNITTEST",
        "ACTIVEPROJECT",
        "ID",
        "FILEPATH",
        "ASSIGN",
        "SEMICOLON",
        "DOT"
    };

    const char* GetTokenName(int tokenId)
    {
        return tokenName[tokenId];
    }

    static const char* tokenInfo[] =
    {
        "end of file",
        "'project'",
        "'solution'",
        "'reference'",
        "'source'",
        "'text'",
        "'target'",
        "'program'",
        "'library'",
        "'unittest'",
        "'activeProject'",
        "identifier",
        "file path",
        "'='",
        "';'",
        "'.'"
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
