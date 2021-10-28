
// this file has been automatically generated from 'C:/work/soulng/sngxml/example/library/Query/QueryLexer.lexer' using soulng lexer generator slg version 3.1.0

#include <Query/QueryTokens.hpp>
#include <map>

namespace QueryTokens
{
    std::map<std::u32string, int> tokenIdMap;

    void InitTokenIdMap()
    {
        tokenIdMap[U"AND"] = 10;
        tokenIdMap[U"DOT"] = 19;
        tokenIdMap[U"DQ_STRING"] = 2;
        tokenIdMap[U"EQ"] = 13;
        tokenIdMap[U"EXCLAMATION"] = 20;
        tokenIdMap[U"FALSE"] = 6;
        tokenIdMap[U"GE"] = 18;
        tokenIdMap[U"GET"] = 7;
        tokenIdMap[U"GT"] = 16;
        tokenIdMap[U"ID"] = 1;
        tokenIdMap[U"INTEGER"] = 4;
        tokenIdMap[U"LE"] = 17;
        tokenIdMap[U"LPAREN"] = 21;
        tokenIdMap[U"LT"] = 15;
        tokenIdMap[U"MATCH"] = 9;
        tokenIdMap[U"NE"] = 14;
        tokenIdMap[U"NOT"] = 12;
        tokenIdMap[U"OR"] = 11;
        tokenIdMap[U"RPAREN"] = 22;
        tokenIdMap[U"SEMICOLON"] = 23;
        tokenIdMap[U"SQ_STRING"] = 3;
        tokenIdMap[U"TRUE"] = 5;
        tokenIdMap[U"WHERE"] = 8;
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
        "DQ_STRING",
        "SQ_STRING",
        "INTEGER",
        "TRUE",
        "FALSE",
        "GET",
        "WHERE",
        "MATCH",
        "AND",
        "OR",
        "NOT",
        "EQ",
        "NE",
        "LT",
        "GT",
        "LE",
        "GE",
        "DOT",
        "EXCLAMATION",
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
        "'id'",
        "'dq_string'",
        "'sq_string'",
        "'integer'",
        "'true'",
        "'false'",
        "'get'",
        "'where'",
        "'match'",
        "'and'",
        "'or'",
        "'not'",
        "==",
        "!=",
        "'<",
        "'>",
        "'<='",
        "'>='",
        "'.'",
        "'!'",
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
