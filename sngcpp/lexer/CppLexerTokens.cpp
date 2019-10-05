
// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/lexer/CppLexer.lexer' using soulng lexer generator slg version 1.2.0

#include <sngcpp/lexer/CppLexerTokens.hpp>
#include <map>

namespace CppLexerTokens
{
    std::map<std::u32string, int> tokenIdMap;

    void InitTokenIdMap()
    {
        tokenIdMap[U"ADDASSIGN"] = 29;
        tokenIdMap[U"ALIGNOF"] = 66;
        tokenIdMap[U"AMP"] = 43;
        tokenIdMap[U"ANDAND"] = 40;
        tokenIdMap[U"ANDASSIGN"] = 33;
        tokenIdMap[U"ARROW"] = 72;
        tokenIdMap[U"ARROWSTAR"] = 58;
        tokenIdMap[U"ASSIGN"] = 25;
        tokenIdMap[U"AUTO"] = 14;
        tokenIdMap[U"BOOL"] = 5;
        tokenIdMap[U"CHAR"] = 1;
        tokenIdMap[U"CHAR16_T"] = 2;
        tokenIdMap[U"CHAR32_T"] = 3;
        tokenIdMap[U"CHARLIT"] = 17;
        tokenIdMap[U"COLON"] = 37;
        tokenIdMap[U"COLONCOLON"] = 23;
        tokenIdMap[U"COMMA"] = 24;
        tokenIdMap[U"CONST_CAST"] = 77;
        tokenIdMap[U"DELETE"] = 68;
        tokenIdMap[U"DIV"] = 55;
        tokenIdMap[U"DIVASSIGN"] = 27;
        tokenIdMap[U"DOT"] = 71;
        tokenIdMap[U"DOTSTAR"] = 57;
        tokenIdMap[U"DOUBLE"] = 12;
        tokenIdMap[U"DYNAMIC_CAST"] = 75;
        tokenIdMap[U"EQ"] = 44;
        tokenIdMap[U"EXCLAMATION"] = 63;
        tokenIdMap[U"FALSE"] = 21;
        tokenIdMap[U"FLOAT"] = 11;
        tokenIdMap[U"FLOATLIT"] = 15;
        tokenIdMap[U"GEQ"] = 47;
        tokenIdMap[U"ID"] = 22;
        tokenIdMap[U"INT"] = 7;
        tokenIdMap[U"INTLIT"] = 16;
        tokenIdMap[U"LANGLE"] = 48;
        tokenIdMap[U"LBRACKET"] = 69;
        tokenIdMap[U"LEQ"] = 46;
        tokenIdMap[U"LONG"] = 8;
        tokenIdMap[U"LPAREN"] = 59;
        tokenIdMap[U"MINUS"] = 53;
        tokenIdMap[U"MINUSMINUS"] = 62;
        tokenIdMap[U"MOD"] = 56;
        tokenIdMap[U"MULASSIGN"] = 26;
        tokenIdMap[U"NEQ"] = 45;
        tokenIdMap[U"NEW"] = 67;
        tokenIdMap[U"NULLPTR"] = 19;
        tokenIdMap[U"OPERATOR"] = 79;
        tokenIdMap[U"OR"] = 41;
        tokenIdMap[U"ORASSIGN"] = 35;
        tokenIdMap[U"OROR"] = 39;
        tokenIdMap[U"PLUS"] = 52;
        tokenIdMap[U"PLUSPLUS"] = 61;
        tokenIdMap[U"QUEST"] = 36;
        tokenIdMap[U"RANGLE"] = 49;
        tokenIdMap[U"RBRACKET"] = 70;
        tokenIdMap[U"REINTERPRET_CAST"] = 76;
        tokenIdMap[U"REMASSIGN"] = 28;
        tokenIdMap[U"RPAREN"] = 60;
        tokenIdMap[U"SHIFTLEFT"] = 50;
        tokenIdMap[U"SHIFTLEFTASSIGN"] = 32;
        tokenIdMap[U"SHIFTRIGHT"] = 51;
        tokenIdMap[U"SHIFTRIGHTASSIGN"] = 31;
        tokenIdMap[U"SHORT"] = 6;
        tokenIdMap[U"SIGNED"] = 9;
        tokenIdMap[U"SIZEOF"] = 65;
        tokenIdMap[U"STAR"] = 54;
        tokenIdMap[U"STATIC_CAST"] = 74;
        tokenIdMap[U"STRINGLIT"] = 18;
        tokenIdMap[U"SUBASSIGN"] = 30;
        tokenIdMap[U"THIS"] = 73;
        tokenIdMap[U"THROW"] = 38;
        tokenIdMap[U"TILDE"] = 64;
        tokenIdMap[U"TRUE"] = 20;
        tokenIdMap[U"TYPEID"] = 78;
        tokenIdMap[U"UNSIGNED"] = 10;
        tokenIdMap[U"VOID"] = 13;
        tokenIdMap[U"WCHAR_T"] = 4;
        tokenIdMap[U"XOR"] = 42;
        tokenIdMap[U"XORASSIGN"] = 34;
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
        "CHAR",
        "CHAR16_T",
        "CHAR32_T",
        "WCHAR_T",
        "BOOL",
        "SHORT",
        "INT",
        "LONG",
        "SIGNED",
        "UNSIGNED",
        "FLOAT",
        "DOUBLE",
        "VOID",
        "AUTO",
        "FLOATLIT",
        "INTLIT",
        "CHARLIT",
        "STRINGLIT",
        "NULLPTR",
        "TRUE",
        "FALSE",
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
        "THROW",
        "OROR",
        "ANDAND",
        "OR",
        "XOR",
        "AMP",
        "EQ",
        "NEQ",
        "LEQ",
        "GEQ",
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
        "SIZEOF",
        "ALIGNOF",
        "NEW",
        "DELETE",
        "LBRACKET",
        "RBRACKET",
        "DOT",
        "ARROW",
        "THIS",
        "STATIC_CAST",
        "DYNAMIC_CAST",
        "REINTERPRET_CAST",
        "CONST_CAST",
        "TYPEID",
        "OPERATOR"
    };

    const char* GetTokenName(int tokenId)
    {
        return tokenName[tokenId];
    }

    const char* tokenInfo[] =
    {
        "end of file",
        "'char'",
        "'char16_t'",
        "'char32_t'",
        "'wchar_t'",
        "'bool'",
        "'short'",
        "'int'",
        "'long'",
        "'signed'",
        "'unsigned'",
        "'float'",
        "'double'",
        "'void'",
        "'auto'",
        "floating literal",
        "integer literal",
        "character literal",
        "string literal",
        "'nullptr'",
        "'true'",
        "'false'",
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
        "'throw'",
        "'||'",
        "'&&'",
        "'|'",
        "'^'",
        "'&'",
        "'=='",
        "'!='",
        "'<='",
        "'>='",
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
        "'sizeof'",
        "'alignof'",
        "'new'",
        "'delete'",
        "'['",
        "']'",
        "'.'",
        "'->'",
        "'this'",
        "'static_cast'",
        "'dynamic_cast'",
        "'reinterpret_cast'",
        "'const_cast'",
        "'typeid'",
        "'operator'"
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
