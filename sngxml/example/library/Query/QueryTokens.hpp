#ifndef QueryTokens_HPP
#define QueryTokens_HPP

// this file has been automatically generated from 'C:/work/soulng/sngxml/example/library/Query/QueryLexer.lexer' using soulng lexer generator slg version 3.1.0

#include <Query/Api.hpp>
#include <string>

namespace QueryTokens
{
    const int END = 0;
    const int ID = 1;
    const int DQ_STRING = 2;
    const int SQ_STRING = 3;
    const int INTEGER = 4;
    const int TRUE = 5;
    const int FALSE = 6;
    const int GET = 7;
    const int WHERE = 8;
    const int MATCH = 9;
    const int AND = 10;
    const int OR = 11;
    const int NOT = 12;
    const int EQ = 13;
    const int NE = 14;
    const int LT = 15;
    const int GT = 16;
    const int LE = 17;
    const int GE = 18;
    const int DOT = 19;
    const int EXCLAMATION = 20;
    const int LPAREN = 21;
    const int RPAREN = 22;
    const int SEMICOLON = 23;

    QUERY_API void InitTokenIdMap();
    QUERY_API int GetTokenId(const std::u32string& tokenName);
    QUERY_API const char* GetTokenName(int tokenId);
    QUERY_API const char* GetTokenInfo(int tokenId);
}
#endif
