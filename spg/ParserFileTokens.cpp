
// this file has been automatically generated from 'D:/work/soulng/spg/ParserFileLexer.lexer' using soulng lexer generator slg version 1.0.0

#include <map>
static std::map<std::u32string, int> tokenIdMap;
#include <soulng/spg/ParserFileTokens.hpp>

static void Init()
{
    tokenIdMap[U"AMP"] = 74;
    tokenIdMap[U"AMPAMP"] = 69;
    tokenIdMap[U"ANDASSIGN"] = 115;
    tokenIdMap[U"API"] = 2;
    tokenIdMap[U"ARROW"] = 90;
    tokenIdMap[U"ARROWSTAR"] = 71;
    tokenIdMap[U"ASSIGN"] = 107;
    tokenIdMap[U"AUTO"] = 14;
    tokenIdMap[U"BITOR"] = 72;
    tokenIdMap[U"BITXOR"] = 73;
    tokenIdMap[U"BOOL"] = 21;
    tokenIdMap[U"BREAK"] = 57;
    tokenIdMap[U"CASE"] = 49;
    tokenIdMap[U"CATCH"] = 62;
    tokenIdMap[U"CHAR"] = 19;
    tokenIdMap[U"CHARLIT"] = 66;
    tokenIdMap[U"COLON"] = 103;
    tokenIdMap[U"COLONCOLON"] = 102;
    tokenIdMap[U"COMMA"] = 106;
    tokenIdMap[U"CONST"] = 31;
    tokenIdMap[U"CONSTCAST"] = 41;
    tokenIdMap[U"CONTINUE"] = 58;
    tokenIdMap[U"CPL"] = 88;
    tokenIdMap[U"CPPPREFIX"] = 9;
    tokenIdMap[U"DEFAULT"] = 50;
    tokenIdMap[U"DELETE"] = 45;
    tokenIdMap[U"DISJUNCTION"] = 68;
    tokenIdMap[U"DIV"] = 84;
    tokenIdMap[U"DIVASSIGN"] = 109;
    tokenIdMap[U"DO"] = 55;
    tokenIdMap[U"DOT"] = 89;
    tokenIdMap[U"DOTSTAR"] = 70;
    tokenIdMap[U"DOUBLE"] = 28;
    tokenIdMap[U"DYNAMICCAST"] = 38;
    tokenIdMap[U"ELLIPSIS"] = 101;
    tokenIdMap[U"ELSE"] = 52;
    tokenIdMap[U"EMPTY"] = 7;
    tokenIdMap[U"EQ"] = 75;
    tokenIdMap[U"EXCLAMATION"] = 13;
    tokenIdMap[U"EXTERN"] = 17;
    tokenIdMap[U"FALSE"] = 47;
    tokenIdMap[U"FILEPATH"] = 11;
    tokenIdMap[U"FLOAT"] = 27;
    tokenIdMap[U"FLOATINGLIT"] = 65;
    tokenIdMap[U"FOR"] = 56;
    tokenIdMap[U"GEQ"] = 78;
    tokenIdMap[U"GOTO"] = 60;
    tokenIdMap[U"HASH"] = 105;
    tokenIdMap[U"HPPPREFIX"] = 10;
    tokenIdMap[U"ID"] = 63;
    tokenIdMap[U"IF"] = 51;
    tokenIdMap[U"INCLUDE"] = 3;
    tokenIdMap[U"INT"] = 23;
    tokenIdMap[U"INTLIT"] = 64;
    tokenIdMap[U"LANGLE"] = 99;
    tokenIdMap[U"LBRACE"] = 95;
    tokenIdMap[U"LBRACKET"] = 97;
    tokenIdMap[U"LEQ"] = 77;
    tokenIdMap[U"LONG"] = 24;
    tokenIdMap[U"LPAREN"] = 93;
    tokenIdMap[U"MAIN"] = 4;
    tokenIdMap[U"MINUS"] = 82;
    tokenIdMap[U"MINUSASSIGN"] = 112;
    tokenIdMap[U"MINUSMINUS"] = 87;
    tokenIdMap[U"MULASSIGN"] = 108;
    tokenIdMap[U"MUTABLE"] = 18;
    tokenIdMap[U"NAMESPACE"] = 34;
    tokenIdMap[U"NEQ"] = 76;
    tokenIdMap[U"NEW"] = 44;
    tokenIdMap[U"NOT"] = 91;
    tokenIdMap[U"NULLPTR"] = 48;
    tokenIdMap[U"OPERATOR"] = 37;
    tokenIdMap[U"ORASSIGN"] = 117;
    tokenIdMap[U"PARSER"] = 1;
    tokenIdMap[U"PLUS"] = 81;
    tokenIdMap[U"PLUSASSIGN"] = 111;
    tokenIdMap[U"PLUSPLUS"] = 86;
    tokenIdMap[U"PRODUCES"] = 12;
    tokenIdMap[U"QUEST"] = 92;
    tokenIdMap[U"RANGLE"] = 100;
    tokenIdMap[U"RBRACE"] = 96;
    tokenIdMap[U"RBRACKET"] = 98;
    tokenIdMap[U"REGISTER"] = 15;
    tokenIdMap[U"REINTERPRETCAST"] = 40;
    tokenIdMap[U"REM"] = 85;
    tokenIdMap[U"REMASSIGN"] = 110;
    tokenIdMap[U"RETURN"] = 59;
    tokenIdMap[U"RPAREN"] = 94;
    tokenIdMap[U"RULEINFO"] = 6;
    tokenIdMap[U"SEMICOLON"] = 104;
    tokenIdMap[U"SHIFTLEFT"] = 79;
    tokenIdMap[U"SHIFTLEFTASSIGN"] = 113;
    tokenIdMap[U"SHIFTRIGHT"] = 80;
    tokenIdMap[U"SHIFTRIGHTASSIGN"] = 114;
    tokenIdMap[U"SHORT"] = 22;
    tokenIdMap[U"SIGNED"] = 25;
    tokenIdMap[U"SIZEOF"] = 36;
    tokenIdMap[U"STAR"] = 83;
    tokenIdMap[U"STATIC"] = 16;
    tokenIdMap[U"STATICCAST"] = 39;
    tokenIdMap[U"STRINGLIT"] = 67;
    tokenIdMap[U"SWITCH"] = 53;
    tokenIdMap[U"THIS"] = 43;
    tokenIdMap[U"THROW"] = 35;
    tokenIdMap[U"TRUE"] = 46;
    tokenIdMap[U"TRY"] = 61;
    tokenIdMap[U"TYPEDEF"] = 30;
    tokenIdMap[U"TYPEID"] = 42;
    tokenIdMap[U"UNSIGNED"] = 26;
    tokenIdMap[U"USELEXER"] = 5;
    tokenIdMap[U"USING"] = 33;
    tokenIdMap[U"VAR"] = 8;
    tokenIdMap[U"VOID"] = 29;
    tokenIdMap[U"VOLATILE"] = 32;
    tokenIdMap[U"WCHART"] = 20;
    tokenIdMap[U"WHILE"] = 54;
    tokenIdMap[U"XORASSIGN"] = 116;
}

namespace ParserFileTokens
{
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

    static const char* tokenName[] =
    {
        "END",
        "PARSER",
        "API",
        "INCLUDE",
        "MAIN",
        "USELEXER",
        "RULEINFO",
        "EMPTY",
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
        "NOT",
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

    static const char* tokenInfo[] =
    {
        "end of file",
        "'parser'",
        "'api'",
        "'include'",
        "'main'",
        "'uselexer'",
        "'ruleinfo'",
        "'empty'",
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
        "'!'",
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
        Initializer() { Init(); }
    };

    Initializer initializer;
}
