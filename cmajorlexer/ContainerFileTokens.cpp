
// this file has been automatically generated from 'D:/work/soulng/cmajorlexer/ContainerFileLexer.lexer' using soulng lexer generator slg version 1.0.0

#include <map>
std::map<std::u32string, int> tokenIdMapContainerFileTokens;
#include <soulng/cmajorlexer/ContainerFileTokens.hpp>

namespace ContainerFileTokens
{
    void InitTokenIdMap()
    {
        tokenIdMapContainerFileTokens[U"ACTIVEPROJECT"] = 10;
        tokenIdMapContainerFileTokens[U"ASSIGN"] = 13;
        tokenIdMapContainerFileTokens[U"DOT"] = 15;
        tokenIdMapContainerFileTokens[U"FILEPATH"] = 12;
        tokenIdMapContainerFileTokens[U"ID"] = 11;
        tokenIdMapContainerFileTokens[U"LIBRARY"] = 8;
        tokenIdMapContainerFileTokens[U"PROGRAM"] = 7;
        tokenIdMapContainerFileTokens[U"PROJECT"] = 1;
        tokenIdMapContainerFileTokens[U"REFERENCE"] = 3;
        tokenIdMapContainerFileTokens[U"SEMICOLON"] = 14;
        tokenIdMapContainerFileTokens[U"SOLUTION"] = 2;
        tokenIdMapContainerFileTokens[U"SOURCE"] = 4;
        tokenIdMapContainerFileTokens[U"TARGET"] = 6;
        tokenIdMapContainerFileTokens[U"TEXT"] = 5;
        tokenIdMapContainerFileTokens[U"UNITTEST"] = 9;
    }

    int GetTokenId(const std::u32string& tokenName)
    {
        auto it = tokenIdMapContainerFileTokens.find(tokenName);
        if (it != tokenIdMapContainerFileTokens.cend())
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

    const char* tokenInfo[] =
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
        Initializer() { InitTokenIdMap(); }
    };

    Initializer initializer;
}
