
// this file has been automatically generated from 'C:/work/soulng/sngcpp20/pp/TextLexer.lexer' using soulng lexer generator slg version 4.0.0

#include <sngcpp20/pp/TextTokens.hpp>
#include <map>

namespace TextTokens
{
    std::map<std::u32string, int> tokenIdMap;

    void InitTokenIdMap()
    {
        tokenIdMap[U"ADDASSIGN"] = 17;
        tokenIdMap[U"AMP"] = 30;
        tokenIdMap[U"AMPAMP"] = 27;
        tokenIdMap[U"ANDASSIGN"] = 21;
        tokenIdMap[U"ANGLEHEADERNAME"] = 2;
        tokenIdMap[U"ARROW"] = 58;
        tokenIdMap[U"ARROWSTAR"] = 46;
        tokenIdMap[U"ASSIGN"] = 13;
        tokenIdMap[U"BEGINBLOCKCOMMENT"] = 62;
        tokenIdMap[U"BEGINRAWSTRINGLITERAL"] = 7;
        tokenIdMap[U"BLOCKCOMMENT"] = 63;
        tokenIdMap[U"CHAR"] = 8;
        tokenIdMap[U"CHARLITERAL"] = 5;
        tokenIdMap[U"COLON"] = 25;
        tokenIdMap[U"COLONCOLON"] = 11;
        tokenIdMap[U"COMMA"] = 12;
        tokenIdMap[U"DEFINED"] = 1;
        tokenIdMap[U"DIV"] = 43;
        tokenIdMap[U"DIVASSIGN"] = 15;
        tokenIdMap[U"DOT"] = 57;
        tokenIdMap[U"DOTSTAR"] = 45;
        tokenIdMap[U"ELLIPSES"] = 60;
        tokenIdMap[U"EQ"] = 31;
        tokenIdMap[U"EXCLAMATION"] = 51;
        tokenIdMap[U"GEQ"] = 34;
        tokenIdMap[U"HASH"] = 68;
        tokenIdMap[U"HASHHASH"] = 67;
        tokenIdMap[U"ID"] = 9;
        tokenIdMap[U"KEYWORD"] = 10;
        tokenIdMap[U"LANGLE"] = 36;
        tokenIdMap[U"LBRACE"] = 55;
        tokenIdMap[U"LBRACKET"] = 53;
        tokenIdMap[U"LEQ"] = 33;
        tokenIdMap[U"LINECOMMENT"] = 64;
        tokenIdMap[U"LPAREN"] = 47;
        tokenIdMap[U"MAX"] = 70;
        tokenIdMap[U"MINUS"] = 41;
        tokenIdMap[U"MINUSMINUS"] = 50;
        tokenIdMap[U"MOD"] = 44;
        tokenIdMap[U"MULASSIGN"] = 14;
        tokenIdMap[U"NEQ"] = 32;
        tokenIdMap[U"NEWLINE"] = 65;
        tokenIdMap[U"OR"] = 28;
        tokenIdMap[U"ORASSIGN"] = 23;
        tokenIdMap[U"OROR"] = 26;
        tokenIdMap[U"OTHER"] = 66;
        tokenIdMap[U"PLACEMARKER"] = 69;
        tokenIdMap[U"PLUS"] = 40;
        tokenIdMap[U"PLUSPLUS"] = 49;
        tokenIdMap[U"PPNUMBER"] = 4;
        tokenIdMap[U"QUEST"] = 24;
        tokenIdMap[U"QUOTEHEADERNAME"] = 3;
        tokenIdMap[U"RANGLE"] = 37;
        tokenIdMap[U"RBRACE"] = 56;
        tokenIdMap[U"RBRACKET"] = 54;
        tokenIdMap[U"REMASSIGN"] = 16;
        tokenIdMap[U"RPAREN"] = 48;
        tokenIdMap[U"SEMICOLON"] = 59;
        tokenIdMap[U"SHIFTLEFT"] = 38;
        tokenIdMap[U"SHIFTLEFTASSIGN"] = 20;
        tokenIdMap[U"SHIFTRIGHT"] = 39;
        tokenIdMap[U"SHIFTRIGHTASSIGN"] = 19;
        tokenIdMap[U"SPACESHIP"] = 35;
        tokenIdMap[U"STAR"] = 42;
        tokenIdMap[U"STRINGLITERAL"] = 6;
        tokenIdMap[U"SUBASSIGN"] = 18;
        tokenIdMap[U"TILDE"] = 52;
        tokenIdMap[U"WS"] = 61;
        tokenIdMap[U"XOR"] = 29;
        tokenIdMap[U"XORASSIGN"] = 22;
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
        "BEGINRAWSTRINGLITERAL",
        "CHAR",
        "ID",
        "KEYWORD",
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
        "WS",
        "BEGINBLOCKCOMMENT",
        "BLOCKCOMMENT",
        "LINECOMMENT",
        "NEWLINE",
        "OTHER",
        "HASHHASH",
        "HASH",
        "PLACEMARKER",
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
        "begin raw string literal",
        "character",
        "identifier",
        "keyword",
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
        "white space",
        "begin block comment",
        "block comment",
        "line comment",
        "'newline'",
        "'other'",
        "'##'",
        "'#'",
        "place marker",
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
