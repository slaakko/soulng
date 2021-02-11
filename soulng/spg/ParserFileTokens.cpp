
// this file has been automatically generated from 'C:/work/soulng/soulng/spg/ParserFileLexer.lexer' using soulng lexer generator slg version 3.10.0

#include <soulng/spg/ParserFileTokens.hpp>
#include <map>

namespace ParserFileTokens
{
    std::map<std::u32string, int> tokenIdMap;

    void InitTokenIdMap()
    {
        tokenIdMap[U"AMP"] = 77;
        tokenIdMap[U"AMPAMP"] = 72;
        tokenIdMap[U"ANDASSIGN"] = 117;
        tokenIdMap[U"ANY"] = 10;
        tokenIdMap[U"API"] = 2;
        tokenIdMap[U"ARROW"] = 93;
        tokenIdMap[U"ARROWSTAR"] = 74;
        tokenIdMap[U"ASSIGN"] = 109;
        tokenIdMap[U"AUTO"] = 17;
        tokenIdMap[U"BITOR"] = 75;
        tokenIdMap[U"BITXOR"] = 76;
        tokenIdMap[U"BOOL"] = 24;
        tokenIdMap[U"BREAK"] = 60;
        tokenIdMap[U"CASE"] = 52;
        tokenIdMap[U"CATCH"] = 65;
        tokenIdMap[U"CHAR"] = 22;
        tokenIdMap[U"CHARLIT"] = 69;
        tokenIdMap[U"COLON"] = 105;
        tokenIdMap[U"COLONCOLON"] = 104;
        tokenIdMap[U"COMMA"] = 108;
        tokenIdMap[U"CONST"] = 34;
        tokenIdMap[U"CONSTCAST"] = 44;
        tokenIdMap[U"CONTINUE"] = 61;
        tokenIdMap[U"CPL"] = 91;
        tokenIdMap[U"CPPPREFIX"] = 12;
        tokenIdMap[U"DEFAULT"] = 53;
        tokenIdMap[U"DELETE"] = 48;
        tokenIdMap[U"DISJUNCTION"] = 71;
        tokenIdMap[U"DIV"] = 87;
        tokenIdMap[U"DIVASSIGN"] = 111;
        tokenIdMap[U"DO"] = 58;
        tokenIdMap[U"DOT"] = 92;
        tokenIdMap[U"DOTSTAR"] = 73;
        tokenIdMap[U"DOUBLE"] = 31;
        tokenIdMap[U"DYNAMICCAST"] = 41;
        tokenIdMap[U"ELLIPSIS"] = 103;
        tokenIdMap[U"ELSE"] = 55;
        tokenIdMap[U"EMPTY"] = 9;
        tokenIdMap[U"EQ"] = 78;
        tokenIdMap[U"EXCLAMATION"] = 16;
        tokenIdMap[U"EXTERN"] = 20;
        tokenIdMap[U"FALSE"] = 50;
        tokenIdMap[U"FILEPATH"] = 14;
        tokenIdMap[U"FLOAT"] = 30;
        tokenIdMap[U"FLOATINGLIT"] = 68;
        tokenIdMap[U"FOR"] = 59;
        tokenIdMap[U"GEQ"] = 81;
        tokenIdMap[U"GOTO"] = 63;
        tokenIdMap[U"HASH"] = 107;
        tokenIdMap[U"HPPPREFIX"] = 13;
        tokenIdMap[U"ID"] = 66;
        tokenIdMap[U"IF"] = 54;
        tokenIdMap[U"INCLUDE"] = 3;
        tokenIdMap[U"INT"] = 26;
        tokenIdMap[U"INTLIT"] = 67;
        tokenIdMap[U"LANGLE"] = 101;
        tokenIdMap[U"LBRACE"] = 97;
        tokenIdMap[U"LBRACKET"] = 99;
        tokenIdMap[U"LEQ"] = 80;
        tokenIdMap[U"LONG"] = 27;
        tokenIdMap[U"LPAREN"] = 95;
        tokenIdMap[U"MAIN"] = 4;
        tokenIdMap[U"MINUS"] = 85;
        tokenIdMap[U"MINUSASSIGN"] = 114;
        tokenIdMap[U"MINUSMINUS"] = 90;
        tokenIdMap[U"MULASSIGN"] = 110;
        tokenIdMap[U"MUTABLE"] = 21;
        tokenIdMap[U"NAMESPACE"] = 37;
        tokenIdMap[U"NEQ"] = 79;
        tokenIdMap[U"NEW"] = 47;
        tokenIdMap[U"NOTHROW"] = 5;
        tokenIdMap[U"NULLPTR"] = 51;
        tokenIdMap[U"OPERATOR"] = 40;
        tokenIdMap[U"ORASSIGN"] = 119;
        tokenIdMap[U"PARSER"] = 1;
        tokenIdMap[U"PLUS"] = 84;
        tokenIdMap[U"PLUSASSIGN"] = 113;
        tokenIdMap[U"PLUSPLUS"] = 89;
        tokenIdMap[U"PRODUCES"] = 15;
        tokenIdMap[U"QUEST"] = 94;
        tokenIdMap[U"RANGLE"] = 102;
        tokenIdMap[U"RBRACE"] = 98;
        tokenIdMap[U"RBRACKET"] = 100;
        tokenIdMap[U"REGISTER"] = 18;
        tokenIdMap[U"REINTERPRETCAST"] = 43;
        tokenIdMap[U"REM"] = 88;
        tokenIdMap[U"REMASSIGN"] = 112;
        tokenIdMap[U"RETURN"] = 62;
        tokenIdMap[U"RPAREN"] = 96;
        tokenIdMap[U"RULEINFO"] = 8;
        tokenIdMap[U"SEMICOLON"] = 106;
        tokenIdMap[U"SHIFTLEFT"] = 82;
        tokenIdMap[U"SHIFTLEFTASSIGN"] = 115;
        tokenIdMap[U"SHIFTRIGHT"] = 83;
        tokenIdMap[U"SHIFTRIGHTASSIGN"] = 116;
        tokenIdMap[U"SHORT"] = 25;
        tokenIdMap[U"SIGNED"] = 28;
        tokenIdMap[U"SIZEOF"] = 39;
        tokenIdMap[U"STAR"] = 86;
        tokenIdMap[U"STATE"] = 6;
        tokenIdMap[U"STATIC"] = 19;
        tokenIdMap[U"STATICCAST"] = 42;
        tokenIdMap[U"STRINGLIT"] = 70;
        tokenIdMap[U"SWITCH"] = 56;
        tokenIdMap[U"THIS"] = 46;
        tokenIdMap[U"THROW"] = 38;
        tokenIdMap[U"TRUE"] = 49;
        tokenIdMap[U"TRY"] = 64;
        tokenIdMap[U"TYPEDEF"] = 33;
        tokenIdMap[U"TYPEID"] = 45;
        tokenIdMap[U"UNSIGNED"] = 29;
        tokenIdMap[U"USELEXER"] = 7;
        tokenIdMap[U"USING"] = 36;
        tokenIdMap[U"VAR"] = 11;
        tokenIdMap[U"VOID"] = 32;
        tokenIdMap[U"VOLATILE"] = 35;
        tokenIdMap[U"WCHART"] = 23;
        tokenIdMap[U"WHILE"] = 57;
        tokenIdMap[U"XORASSIGN"] = 118;
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
        "PARSER",
        "API",
        "INCLUDE",
        "MAIN",
        "NOTHROW",
        "STATE",
        "USELEXER",
        "RULEINFO",
        "EMPTY",
        "ANY",
        "VAR",
        "CPPPREFIX",
        "HPPPREFIX",
        "FILEPATH",
        "PRODUCES",
        "EXCLAMATION",
        "AUTO",
        "REGISTER",
        "STATIC",
        "EXTERN",
        "MUTABLE",
        "CHAR",
        "WCHART",
        "BOOL",
        "SHORT",
        "INT",
        "LONG",
        "SIGNED",
        "UNSIGNED",
        "FLOAT",
        "DOUBLE",
        "VOID",
        "TYPEDEF",
        "CONST",
        "VOLATILE",
        "USING",
        "NAMESPACE",
        "THROW",
        "SIZEOF",
        "OPERATOR",
        "DYNAMICCAST",
        "STATICCAST",
        "REINTERPRETCAST",
        "CONSTCAST",
        "TYPEID",
        "THIS",
        "NEW",
        "DELETE",
        "TRUE",
        "FALSE",
        "NULLPTR",
        "CASE",
        "DEFAULT",
        "IF",
        "ELSE",
        "SWITCH",
        "WHILE",
        "DO",
        "FOR",
        "BREAK",
        "CONTINUE",
        "RETURN",
        "GOTO",
        "TRY",
        "CATCH",
        "ID",
        "INTLIT",
        "FLOATINGLIT",
        "CHARLIT",
        "STRINGLIT",
        "DISJUNCTION",
        "AMPAMP",
        "DOTSTAR",
        "ARROWSTAR",
        "BITOR",
        "BITXOR",
        "AMP",
        "EQ",
        "NEQ",
        "LEQ",
        "GEQ",
        "SHIFTLEFT",
        "SHIFTRIGHT",
        "PLUS",
        "MINUS",
        "STAR",
        "DIV",
        "REM",
        "PLUSPLUS",
        "MINUSMINUS",
        "CPL",
        "DOT",
        "ARROW",
        "QUEST",
        "LPAREN",
        "RPAREN",
        "LBRACE",
        "RBRACE",
        "LBRACKET",
        "RBRACKET",
        "LANGLE",
        "RANGLE",
        "ELLIPSIS",
        "COLONCOLON",
        "COLON",
        "SEMICOLON",
        "HASH",
        "COMMA",
        "ASSIGN",
        "MULASSIGN",
        "DIVASSIGN",
        "REMASSIGN",
        "PLUSASSIGN",
        "MINUSASSIGN",
        "SHIFTLEFTASSIGN",
        "SHIFTRIGHTASSIGN",
        "ANDASSIGN",
        "XORASSIGN",
        "ORASSIGN"
    };

    const char* GetTokenName(int tokenId)
    {
        return tokenName[tokenId];
    }

    const char* tokenInfo[] =
    {
        "end of file",
        "'parser'",
        "'api'",
        "'include'",
        "'main'",
        "'nothrow'",
        "'state'",
        "'uselexer'",
        "'ruleinfo'",
        "'empty'",
        "'any'",
        "'var'",
        "cpp-prefix",
        "hpp-prefix",
        "file path",
        "'::='",
        "'!'",
        "'auto'",
        "'register'",
        "'static'",
        "'extern'",
        "'mutable'",
        "'char'",
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
        "'typedef'",
        "'const'",
        "'volatile'",
        "'using'",
        "'namespace'",
        "'throw'",
        "'sizeof'",
        "'operator'",
        "'dynamic_cast'",
        "'static_cast'",
        "'reinterpret_cast'",
        "'const_cast'",
        "'typeid'",
        "'this'",
        "'new'",
        "'delete'",
        "'true'",
        "'false'",
        "'nullptr'",
        "'case'",
        "'default'",
        "'if'",
        "'else'",
        "'switch'",
        "'while'",
        "'do'",
        "'for'",
        "'break'",
        "'continue'",
        "'return'",
        "'goto'",
        "'try'",
        "'catch'",
        "identifier",
        "integer literal",
        "floating literal",
        "character literal",
        "string literal",
        "'||'",
        "'&&'",
        "'.*'",
        "'->*'",
        "'|'",
        "'^'",
        "'&'",
        "'=='",
        "'!='",
        "'<='",
        "'>='",
        "'<<'",
        "'>>'",
        "'+'",
        "'-'",
        "'*'",
        "'/'",
        "'%'",
        "'++'",
        "'--'",
        "'~'",
        "'.'",
        "'->'",
        "'?'",
        "'('",
        "')'",
        "'{'",
        "'}'",
        "'['",
        "']'",
        "'<'",
        "'>'",
        "'...'",
        "'::'",
        "':'",
        "';'",
        "'#'",
        "','",
        "'='",
        "'*='",
        "'/='",
        "'%='",
        "'+='",
        "'-='",
        "'<<='",
        "'>>='",
        "'&='",
        "'^='",
        "'|='"
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
