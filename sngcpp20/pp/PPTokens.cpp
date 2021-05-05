
// this file has been automatically generated from 'C:/work/soulng/sngcpp20/pp/PPLexer.lexer' using soulng lexer generator slg version 4.0.0

#include <sngcpp20/pp/PPTokens.hpp>
#include <map>

namespace PPTokens
{
    std::map<std::u32string, int> tokenIdMap;

    void InitTokenIdMap()
    {
        tokenIdMap[U"ADDASSIGN"] = 25;
        tokenIdMap[U"AMP"] = 38;
        tokenIdMap[U"AMPAMP"] = 35;
        tokenIdMap[U"ANDASSIGN"] = 29;
        tokenIdMap[U"ANGLEHEADERNAME"] = 11;
        tokenIdMap[U"ARROW"] = 66;
        tokenIdMap[U"ARROWSTAR"] = 54;
        tokenIdMap[U"ASSIGN"] = 21;
        tokenIdMap[U"CHAR"] = 17;
        tokenIdMap[U"CHARLITERAL"] = 14;
        tokenIdMap[U"COLON"] = 33;
        tokenIdMap[U"COLONCOLON"] = 19;
        tokenIdMap[U"COMMA"] = 20;
        tokenIdMap[U"DEFINE"] = 1;
        tokenIdMap[U"DEFINED"] = 10;
        tokenIdMap[U"DIV"] = 51;
        tokenIdMap[U"DIVASSIGN"] = 23;
        tokenIdMap[U"DOT"] = 65;
        tokenIdMap[U"DOTSTAR"] = 53;
        tokenIdMap[U"ELIF"] = 4;
        tokenIdMap[U"ELLIPSES"] = 68;
        tokenIdMap[U"ELSE"] = 5;
        tokenIdMap[U"ENDIF"] = 6;
        tokenIdMap[U"EQ"] = 39;
        tokenIdMap[U"EXCLAMATION"] = 59;
        tokenIdMap[U"GEQ"] = 42;
        tokenIdMap[U"HASH"] = 16;
        tokenIdMap[U"ID"] = 18;
        tokenIdMap[U"IF"] = 3;
        tokenIdMap[U"IFDEF"] = 7;
        tokenIdMap[U"IFNDEF"] = 8;
        tokenIdMap[U"INCLUDE"] = 2;
        tokenIdMap[U"LANGLE"] = 44;
        tokenIdMap[U"LBRACE"] = 63;
        tokenIdMap[U"LBRACKET"] = 61;
        tokenIdMap[U"LEQ"] = 41;
        tokenIdMap[U"LPAREN"] = 55;
        tokenIdMap[U"MAX"] = 69;
        tokenIdMap[U"MINUS"] = 49;
        tokenIdMap[U"MINUSMINUS"] = 58;
        tokenIdMap[U"MOD"] = 52;
        tokenIdMap[U"MULASSIGN"] = 22;
        tokenIdMap[U"NEQ"] = 40;
        tokenIdMap[U"OR"] = 36;
        tokenIdMap[U"ORASSIGN"] = 31;
        tokenIdMap[U"OROR"] = 34;
        tokenIdMap[U"PLUS"] = 48;
        tokenIdMap[U"PLUSPLUS"] = 57;
        tokenIdMap[U"PPNUMBER"] = 13;
        tokenIdMap[U"QUEST"] = 32;
        tokenIdMap[U"QUOTEHEADERNAME"] = 12;
        tokenIdMap[U"RANGLE"] = 45;
        tokenIdMap[U"RBRACE"] = 64;
        tokenIdMap[U"RBRACKET"] = 62;
        tokenIdMap[U"REMASSIGN"] = 24;
        tokenIdMap[U"RPAREN"] = 56;
        tokenIdMap[U"SEMICOLON"] = 67;
        tokenIdMap[U"SHIFTLEFT"] = 46;
        tokenIdMap[U"SHIFTLEFTASSIGN"] = 28;
        tokenIdMap[U"SHIFTRIGHT"] = 47;
        tokenIdMap[U"SHIFTRIGHTASSIGN"] = 27;
        tokenIdMap[U"SPACESHIP"] = 43;
        tokenIdMap[U"STAR"] = 50;
        tokenIdMap[U"STRINGLITERAL"] = 15;
        tokenIdMap[U"SUBASSIGN"] = 26;
        tokenIdMap[U"TILDE"] = 60;
        tokenIdMap[U"UNDEF"] = 9;
        tokenIdMap[U"XOR"] = 37;
        tokenIdMap[U"XORASSIGN"] = 30;
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
        "DEFINE",
        "INCLUDE",
        "IF",
        "ELIF",
        "ELSE",
        "ENDIF",
        "IFDEF",
        "IFNDEF",
        "UNDEF",
        "DEFINED",
        "ANGLEHEADERNAME",
        "QUOTEHEADERNAME",
        "PPNUMBER",
        "CHARLITERAL",
        "STRINGLITERAL",
        "HASH",
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
        "MAX"
    };

    const char* GetTokenName(int tokenId)
    {
        return tokenName[tokenId];
    }

    const char* tokenInfo[] =
    {
        "end of file",
        "'define'",
        "'include'",
        "'if'",
        "'elif'",
        "'else'",
        "'endif'",
        "'ifdef",
        "'ifndef'",
        "'undef'",
        "'defined'",
        "angleheadername",
        "quoteheadername",
        "preprocessing number",
        "character literal",
        "string literal",
        "'#'",
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
