
// this file has been automatically generated from 'C:/work/soulng/sngcpp20/pp/PPLexer.lexer' using soulng lexer generator slg version 3.1.0

#include <sngcpp20/pp/PPTokens.hpp>
#include <map>

namespace PPTokens
{
    std::map<std::u32string, int> tokenIdMap;

    void InitTokenIdMap()
    {
        tokenIdMap[U"ADDASSIGN"] = 35;
        tokenIdMap[U"AMP"] = 48;
        tokenIdMap[U"AMPAMP"] = 45;
        tokenIdMap[U"ANDASSIGN"] = 39;
        tokenIdMap[U"ANGLEHEADERNAME"] = 14;
        tokenIdMap[U"ARROW"] = 76;
        tokenIdMap[U"ARROWSTAR"] = 64;
        tokenIdMap[U"ASSIGN"] = 31;
        tokenIdMap[U"BEGINBLOCKCOMMENT"] = 20;
        tokenIdMap[U"BEGINRAWSTRINGLITERAL"] = 19;
        tokenIdMap[U"BLOCKCOMMENT"] = 21;
        tokenIdMap[U"CHAR"] = 27;
        tokenIdMap[U"CHARLITERAL"] = 17;
        tokenIdMap[U"COLON"] = 43;
        tokenIdMap[U"COLONCOLON"] = 29;
        tokenIdMap[U"COMMA"] = 30;
        tokenIdMap[U"DEFINE"] = 1;
        tokenIdMap[U"DEFINED"] = 13;
        tokenIdMap[U"DIV"] = 61;
        tokenIdMap[U"DIVASSIGN"] = 33;
        tokenIdMap[U"DOT"] = 75;
        tokenIdMap[U"DOTSTAR"] = 63;
        tokenIdMap[U"ELIF"] = 4;
        tokenIdMap[U"ELLIPSIS"] = 78;
        tokenIdMap[U"ELSE"] = 5;
        tokenIdMap[U"ENDIF"] = 6;
        tokenIdMap[U"EQ"] = 49;
        tokenIdMap[U"ERROR"] = 11;
        tokenIdMap[U"EXCLAMATION"] = 69;
        tokenIdMap[U"GEQ"] = 52;
        tokenIdMap[U"HASH"] = 26;
        tokenIdMap[U"HASHHASH"] = 25;
        tokenIdMap[U"ID"] = 28;
        tokenIdMap[U"IF"] = 3;
        tokenIdMap[U"IFDEF"] = 7;
        tokenIdMap[U"IFNDEF"] = 8;
        tokenIdMap[U"INCLUDE"] = 2;
        tokenIdMap[U"LANGLE"] = 54;
        tokenIdMap[U"LBRACE"] = 73;
        tokenIdMap[U"LBRACKET"] = 71;
        tokenIdMap[U"LEQ"] = 51;
        tokenIdMap[U"LINE"] = 10;
        tokenIdMap[U"LINECOMMENT"] = 22;
        tokenIdMap[U"LPAREN"] = 65;
        tokenIdMap[U"MAX"] = 80;
        tokenIdMap[U"MINUS"] = 59;
        tokenIdMap[U"MINUSMINUS"] = 68;
        tokenIdMap[U"MOD"] = 62;
        tokenIdMap[U"MULASSIGN"] = 32;
        tokenIdMap[U"NEQ"] = 50;
        tokenIdMap[U"NEWLINE"] = 24;
        tokenIdMap[U"OR"] = 46;
        tokenIdMap[U"ORASSIGN"] = 41;
        tokenIdMap[U"OROR"] = 44;
        tokenIdMap[U"OTHER"] = 79;
        tokenIdMap[U"PLUS"] = 58;
        tokenIdMap[U"PLUSPLUS"] = 67;
        tokenIdMap[U"PPNUMBER"] = 16;
        tokenIdMap[U"PRAGMA"] = 12;
        tokenIdMap[U"QUEST"] = 42;
        tokenIdMap[U"QUOTEHEADERNAME"] = 15;
        tokenIdMap[U"RANGLE"] = 55;
        tokenIdMap[U"RBRACE"] = 74;
        tokenIdMap[U"RBRACKET"] = 72;
        tokenIdMap[U"REMASSIGN"] = 34;
        tokenIdMap[U"RPAREN"] = 66;
        tokenIdMap[U"SEMICOLON"] = 77;
        tokenIdMap[U"SHIFTLEFT"] = 56;
        tokenIdMap[U"SHIFTLEFTASSIGN"] = 38;
        tokenIdMap[U"SHIFTRIGHT"] = 57;
        tokenIdMap[U"SHIFTRIGHTASSIGN"] = 37;
        tokenIdMap[U"SPACESHIP"] = 53;
        tokenIdMap[U"STAR"] = 60;
        tokenIdMap[U"STRINGLITERAL"] = 18;
        tokenIdMap[U"SUBASSIGN"] = 36;
        tokenIdMap[U"TILDE"] = 70;
        tokenIdMap[U"UNDEF"] = 9;
        tokenIdMap[U"WS"] = 23;
        tokenIdMap[U"XOR"] = 47;
        tokenIdMap[U"XORASSIGN"] = 40;
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
        "LINE",
        "ERROR",
        "PRAGMA",
        "DEFINED",
        "ANGLEHEADERNAME",
        "QUOTEHEADERNAME",
        "PPNUMBER",
        "CHARLITERAL",
        "STRINGLITERAL",
        "BEGINRAWSTRINGLITERAL",
        "BEGINBLOCKCOMMENT",
        "BLOCKCOMMENT",
        "LINECOMMENT",
        "WS",
        "NEWLINE",
        "HASHHASH",
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
        "ELLIPSIS",
        "OTHER",
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
        "'line'",
        "'error'",
        "'pragma'",
        "'defined'",
        "angleheadername",
        "quoteheadername",
        "preprocessing number",
        "character literal",
        "string literal",
        "begin raw string literal",
        "begin block comment",
        "'block comment'",
        "'line comment'",
        "'ws'",
        "'newline'",
        "'##'",
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
        "'other'",
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
