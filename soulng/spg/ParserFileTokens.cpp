
// this file has been automatically generated from 'C:/work/soulng/soulng/spg/ParserFileLexer.lexer' using soulng lexer generator slg version 3.1.0

#include <soulng/spg/ParserFileTokens.hpp>
#include <map>

namespace ParserFileTokens
{
    std::map<std::u32string, int> tokenIdMap;

    void InitTokenIdMap()
    {
        tokenIdMap[U"AMP"] = 79;
        tokenIdMap[U"AMPAMP"] = 74;
        tokenIdMap[U"ANDASSIGN"] = 119;
        tokenIdMap[U"ANY"] = 12;
        tokenIdMap[U"API"] = 2;
        tokenIdMap[U"ARROW"] = 95;
        tokenIdMap[U"ARROWSTAR"] = 76;
        tokenIdMap[U"ASSIGN"] = 111;
        tokenIdMap[U"AUTO"] = 19;
        tokenIdMap[U"BITOR"] = 77;
        tokenIdMap[U"BITXOR"] = 78;
        tokenIdMap[U"BOOL"] = 26;
        tokenIdMap[U"BREAK"] = 62;
        tokenIdMap[U"CASE"] = 54;
        tokenIdMap[U"CATCH"] = 67;
        tokenIdMap[U"CHAR"] = 24;
        tokenIdMap[U"CHARLIT"] = 71;
        tokenIdMap[U"COLON"] = 107;
        tokenIdMap[U"COLONCOLON"] = 106;
        tokenIdMap[U"COMMA"] = 110;
        tokenIdMap[U"CONST"] = 36;
        tokenIdMap[U"CONSTCAST"] = 46;
        tokenIdMap[U"CONTINUE"] = 63;
        tokenIdMap[U"CPL"] = 93;
        tokenIdMap[U"CPPPREFIX"] = 14;
        tokenIdMap[U"DEFAULT"] = 55;
        tokenIdMap[U"DELETE"] = 50;
        tokenIdMap[U"DISJUNCTION"] = 73;
        tokenIdMap[U"DIV"] = 89;
        tokenIdMap[U"DIVASSIGN"] = 113;
        tokenIdMap[U"DO"] = 60;
        tokenIdMap[U"DOT"] = 94;
        tokenIdMap[U"DOTSTAR"] = 75;
        tokenIdMap[U"DOUBLE"] = 33;
        tokenIdMap[U"DYNAMICCAST"] = 43;
        tokenIdMap[U"ELLIPSIS"] = 105;
        tokenIdMap[U"ELSE"] = 57;
        tokenIdMap[U"EMPTY"] = 11;
        tokenIdMap[U"EQ"] = 80;
        tokenIdMap[U"EXCLAMATION"] = 18;
        tokenIdMap[U"EXTERN"] = 22;
        tokenIdMap[U"FALSE"] = 52;
        tokenIdMap[U"FARTHEST_ERROR"] = 8;
        tokenIdMap[U"FILEPATH"] = 16;
        tokenIdMap[U"FLOAT"] = 32;
        tokenIdMap[U"FLOATINGLIT"] = 70;
        tokenIdMap[U"FOR"] = 61;
        tokenIdMap[U"GEQ"] = 83;
        tokenIdMap[U"GOTO"] = 65;
        tokenIdMap[U"HASH"] = 109;
        tokenIdMap[U"HPPPREFIX"] = 15;
        tokenIdMap[U"ID"] = 68;
        tokenIdMap[U"IF"] = 56;
        tokenIdMap[U"INCLUDE"] = 3;
        tokenIdMap[U"INT"] = 28;
        tokenIdMap[U"INTLIT"] = 69;
        tokenIdMap[U"LANGLE"] = 103;
        tokenIdMap[U"LBRACE"] = 99;
        tokenIdMap[U"LBRACKET"] = 101;
        tokenIdMap[U"LEQ"] = 82;
        tokenIdMap[U"LONG"] = 29;
        tokenIdMap[U"LPAREN"] = 97;
        tokenIdMap[U"MAIN"] = 4;
        tokenIdMap[U"MINUS"] = 87;
        tokenIdMap[U"MINUSASSIGN"] = 116;
        tokenIdMap[U"MINUSMINUS"] = 92;
        tokenIdMap[U"MULASSIGN"] = 112;
        tokenIdMap[U"MUTABLE"] = 23;
        tokenIdMap[U"NAMESPACE"] = 39;
        tokenIdMap[U"NEQ"] = 81;
        tokenIdMap[U"NEW"] = 49;
        tokenIdMap[U"NOTHROW"] = 6;
        tokenIdMap[U"NULLPTR"] = 53;
        tokenIdMap[U"OPERATOR"] = 42;
        tokenIdMap[U"ORASSIGN"] = 121;
        tokenIdMap[U"PARSER"] = 1;
        tokenIdMap[U"PLUS"] = 86;
        tokenIdMap[U"PLUSASSIGN"] = 115;
        tokenIdMap[U"PLUSPLUS"] = 91;
        tokenIdMap[U"PRODUCES"] = 17;
        tokenIdMap[U"QUEST"] = 96;
        tokenIdMap[U"RANGLE"] = 104;
        tokenIdMap[U"RBRACE"] = 100;
        tokenIdMap[U"RBRACKET"] = 102;
        tokenIdMap[U"REGISTER"] = 20;
        tokenIdMap[U"REINTERPRETCAST"] = 45;
        tokenIdMap[U"REM"] = 90;
        tokenIdMap[U"REMASSIGN"] = 114;
        tokenIdMap[U"RETURN"] = 64;
        tokenIdMap[U"RPAREN"] = 98;
        tokenIdMap[U"RULEINFO"] = 10;
        tokenIdMap[U"SEMICOLON"] = 108;
        tokenIdMap[U"SHIFTLEFT"] = 84;
        tokenIdMap[U"SHIFTLEFTASSIGN"] = 117;
        tokenIdMap[U"SHIFTRIGHT"] = 85;
        tokenIdMap[U"SHIFTRIGHTASSIGN"] = 118;
        tokenIdMap[U"SHORT"] = 27;
        tokenIdMap[U"SIGNED"] = 30;
        tokenIdMap[U"SIZEOF"] = 41;
        tokenIdMap[U"STAR"] = 88;
        tokenIdMap[U"START"] = 5;
        tokenIdMap[U"STATE"] = 7;
        tokenIdMap[U"STATIC"] = 21;
        tokenIdMap[U"STATICCAST"] = 44;
        tokenIdMap[U"STRINGLIT"] = 72;
        tokenIdMap[U"SWITCH"] = 58;
        tokenIdMap[U"THIS"] = 48;
        tokenIdMap[U"THROW"] = 40;
        tokenIdMap[U"TRUE"] = 51;
        tokenIdMap[U"TRY"] = 66;
        tokenIdMap[U"TYPEDEF"] = 35;
        tokenIdMap[U"TYPEID"] = 47;
        tokenIdMap[U"UNSIGNED"] = 31;
        tokenIdMap[U"USELEXER"] = 9;
        tokenIdMap[U"USING"] = 38;
        tokenIdMap[U"VAR"] = 13;
        tokenIdMap[U"VOID"] = 34;
        tokenIdMap[U"VOLATILE"] = 37;
        tokenIdMap[U"WCHART"] = 25;
        tokenIdMap[U"WHILE"] = 59;
        tokenIdMap[U"XORASSIGN"] = 120;
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
        "START",
        "NOTHROW",
        "STATE",
        "FARTHEST_ERROR",
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
        "'start'",
        "'nothrow'",
        "'state'",
        "'farthest_error'",
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
