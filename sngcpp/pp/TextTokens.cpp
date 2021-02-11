
// this file has been automatically generated from 'C:/work/soulng/sngcpp/pp/TextLexer.lexer' using soulng lexer generator slg version 3.10.0

#include <sngcpp/pp/TextTokens.hpp>
#include <map>

namespace TextTokens
{
    std::map<std::u32string, int> tokenIdMap;

    void InitTokenIdMap()
    {
        tokenIdMap[U"ADDASSIGN"] = 15;
        tokenIdMap[U"AMP"] = 28;
        tokenIdMap[U"AMPAMP"] = 25;
        tokenIdMap[U"ANDASSIGN"] = 19;
        tokenIdMap[U"ANGLEHEADERNAME"] = 2;
        tokenIdMap[U"ARROW"] = 56;
        tokenIdMap[U"ARROWSTAR"] = 44;
        tokenIdMap[U"ASSIGN"] = 11;
        tokenIdMap[U"BLOCKCOMMENT"] = 61;
        tokenIdMap[U"CHAR"] = 7;
        tokenIdMap[U"CHARLITERAL"] = 5;
        tokenIdMap[U"COLON"] = 23;
        tokenIdMap[U"COLONCOLON"] = 9;
        tokenIdMap[U"COMMA"] = 10;
        tokenIdMap[U"DEFINED"] = 1;
        tokenIdMap[U"DIV"] = 41;
        tokenIdMap[U"DIVASSIGN"] = 13;
        tokenIdMap[U"DOT"] = 55;
        tokenIdMap[U"DOTSTAR"] = 43;
        tokenIdMap[U"ELLIPSES"] = 58;
        tokenIdMap[U"EQ"] = 29;
        tokenIdMap[U"EXCLAMATION"] = 49;
        tokenIdMap[U"GEQ"] = 32;
        tokenIdMap[U"ID"] = 8;
        tokenIdMap[U"KEYWORD"] = 59;
        tokenIdMap[U"LANGLE"] = 34;
        tokenIdMap[U"LBRACE"] = 53;
        tokenIdMap[U"LBRACKET"] = 51;
        tokenIdMap[U"LEQ"] = 31;
        tokenIdMap[U"LINECOMMENT"] = 62;
        tokenIdMap[U"LPAREN"] = 45;
        tokenIdMap[U"MAX"] = 63;
        tokenIdMap[U"MINUS"] = 39;
        tokenIdMap[U"MINUSMINUS"] = 48;
        tokenIdMap[U"MOD"] = 42;
        tokenIdMap[U"MULASSIGN"] = 12;
        tokenIdMap[U"NEQ"] = 30;
        tokenIdMap[U"OR"] = 26;
        tokenIdMap[U"ORASSIGN"] = 21;
        tokenIdMap[U"OROR"] = 24;
        tokenIdMap[U"PLUS"] = 38;
        tokenIdMap[U"PLUSPLUS"] = 47;
        tokenIdMap[U"PPNUMBER"] = 4;
        tokenIdMap[U"QUEST"] = 22;
        tokenIdMap[U"QUOTEHEADERNAME"] = 3;
        tokenIdMap[U"RANGLE"] = 35;
        tokenIdMap[U"RBRACE"] = 54;
        tokenIdMap[U"RBRACKET"] = 52;
        tokenIdMap[U"REMASSIGN"] = 14;
        tokenIdMap[U"RPAREN"] = 46;
        tokenIdMap[U"SEMICOLON"] = 57;
        tokenIdMap[U"SHIFTLEFT"] = 36;
        tokenIdMap[U"SHIFTLEFTASSIGN"] = 18;
        tokenIdMap[U"SHIFTRIGHT"] = 37;
        tokenIdMap[U"SHIFTRIGHTASSIGN"] = 17;
        tokenIdMap[U"SPACESHIP"] = 33;
        tokenIdMap[U"STAR"] = 40;
        tokenIdMap[U"STRINGLITERAL"] = 6;
        tokenIdMap[U"SUBASSIGN"] = 16;
        tokenIdMap[U"TILDE"] = 50;
        tokenIdMap[U"WS"] = 60;
        tokenIdMap[U"XOR"] = 27;
        tokenIdMap[U"XORASSIGN"] = 20;
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
        "DEFINED",
        "ANGLEHEADERNAME",
        "QUOTEHEADERNAME",
        "PPNUMBER",
        "CHARLITERAL",
        "STRINGLITERAL",
        "CHAR",
        "ID",
        "COLONCOLON",
        "COMMA",
        "ASSIGN",
        "MULASSIGN",
        "DIVASSIGN",
        "REMASSIGN",
        "ADDASSIGN",
        "SUBASSIGN",
        "SHIFTRIGHTASSIGN",
        "SHIFTLEFTASSIGN",
        "ANDASSIGN",
        "XORASSIGN",
        "ORASSIGN",
        "QUEST",
        "COLON",
        "OROR",
        "AMPAMP",
        "OR",
        "XOR",
        "AMP",
        "EQ",
        "NEQ",
        "LEQ",
        "GEQ",
        "SPACESHIP",
        "LANGLE",
        "RANGLE",
        "SHIFTLEFT",
        "SHIFTRIGHT",
        "PLUS",
        "MINUS",
        "STAR",
        "DIV",
        "MOD",
        "DOTSTAR",
        "ARROWSTAR",
        "LPAREN",
        "RPAREN",
        "PLUSPLUS",
        "MINUSMINUS",
        "EXCLAMATION",
        "TILDE",
        "LBRACKET",
        "RBRACKET",
        "LBRACE",
        "RBRACE",
        "DOT",
        "ARROW",
        "SEMICOLON",
        "ELLIPSES",
        "KEYWORD",
        "WS",
        "BLOCKCOMMENT",
        "LINECOMMENT",
        "MAX"
    };

    const char* GetTokenName(int tokenId)
    {
        return tokenName[tokenId];
    }

    const char* tokenInfo[] =
    {
        "end of file",
        "'defined'",
        "angleheadername",
        "quoteheadername",
        "preprocessing number",
        "character literal",
        "string literal",
        "character",
        "identifier",
        "'::'",
        "','",
        "'='",
        "'*='",
        "'/='",
        "'%='",
        "'+='",
        "'-='",
        "'>>='",
        "'<<='",
        "'&='",
        "'^='",
        "'|='",
        "'?'",
        "':'",
        "'||'",
        "'&&'",
        "'|'",
        "'^'",
        "'&'",
        "'=='",
        "'!='",
        "'<='",
        "'>='",
        "<=>",
        "'<'",
        "'>'",
        "'<<'",
        "'>>'",
        "'+'",
        "'-'",
        "'*'",
        "'/'",
        "'%'",
        "'.*'",
        "'->*'",
        "'('",
        "')'",
        "'++'",
        "'--'",
        "'!'",
        "'~'",
        "'['",
        "']'",
        "'{'",
        "'}'",
        "'.'",
        "'->'",
        "';'",
        "'...'",
        "keyword",
        "white space",
        "block comment",
        "line comment",
        "max"
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
