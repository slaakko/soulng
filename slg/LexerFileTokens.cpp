
// this file has been automatically generated from 'D:/work/soulng/slg/LexerFileLexer.lexer' using soulng lexer generator slg version 1.0.0

#include <map>
static std::map<std::u32string, int> tokenIdMap;
#include <soulng/slg/LexerFileTokens.hpp>

static void Init()
{
    tokenIdMap[U"ACTIONS"] = 8;
    tokenIdMap[U"AMP"] = 73;
    tokenIdMap[U"AMPAMP"] = 68;
    tokenIdMap[U"ANDASSIGN"] = 114;
    tokenIdMap[U"API"] = 9;
    tokenIdMap[U"ARROW"] = 89;
    tokenIdMap[U"ARROWSTAR"] = 70;
    tokenIdMap[U"ASSIGN"] = 106;
    tokenIdMap[U"AUTO"] = 13;
    tokenIdMap[U"BITOR"] = 71;
    tokenIdMap[U"BITXOR"] = 72;
    tokenIdMap[U"BOOL"] = 20;
    tokenIdMap[U"BREAK"] = 56;
    tokenIdMap[U"CASE"] = 48;
    tokenIdMap[U"CATCH"] = 61;
    tokenIdMap[U"CHAR"] = 18;
    tokenIdMap[U"CHARLIT"] = 65;
    tokenIdMap[U"CLASSMAP"] = 1;
    tokenIdMap[U"COLON"] = 102;
    tokenIdMap[U"COLONCOLON"] = 101;
    tokenIdMap[U"COMMA"] = 105;
    tokenIdMap[U"CONST"] = 30;
    tokenIdMap[U"CONSTCAST"] = 40;
    tokenIdMap[U"CONTINUE"] = 57;
    tokenIdMap[U"CPL"] = 87;
    tokenIdMap[U"DEFAULT"] = 49;
    tokenIdMap[U"DELETE"] = 44;
    tokenIdMap[U"DISJUNCTION"] = 67;
    tokenIdMap[U"DIV"] = 83;
    tokenIdMap[U"DIVASSIGN"] = 108;
    tokenIdMap[U"DO"] = 54;
    tokenIdMap[U"DOLLAR"] = 12;
    tokenIdMap[U"DOT"] = 88;
    tokenIdMap[U"DOTSTAR"] = 69;
    tokenIdMap[U"DOUBLE"] = 27;
    tokenIdMap[U"DYNAMICCAST"] = 37;
    tokenIdMap[U"ELLIPSIS"] = 100;
    tokenIdMap[U"ELSE"] = 51;
    tokenIdMap[U"EQ"] = 74;
    tokenIdMap[U"EXPRESSIONS"] = 5;
    tokenIdMap[U"EXTERN"] = 16;
    tokenIdMap[U"FALSE"] = 46;
    tokenIdMap[U"FILEPATH"] = 11;
    tokenIdMap[U"FLOAT"] = 26;
    tokenIdMap[U"FLOATINGLIT"] = 64;
    tokenIdMap[U"FOR"] = 55;
    tokenIdMap[U"GEQ"] = 77;
    tokenIdMap[U"GOTO"] = 59;
    tokenIdMap[U"HASH"] = 104;
    tokenIdMap[U"ID"] = 62;
    tokenIdMap[U"IF"] = 50;
    tokenIdMap[U"INCLUDE"] = 10;
    tokenIdMap[U"INT"] = 22;
    tokenIdMap[U"INTLIT"] = 63;
    tokenIdMap[U"KEYWORDS"] = 4;
    tokenIdMap[U"LANGLE"] = 98;
    tokenIdMap[U"LBRACE"] = 94;
    tokenIdMap[U"LBRACKET"] = 96;
    tokenIdMap[U"LEQ"] = 76;
    tokenIdMap[U"LEXER"] = 6;
    tokenIdMap[U"LONG"] = 23;
    tokenIdMap[U"LPAREN"] = 92;
    tokenIdMap[U"MINUS"] = 81;
    tokenIdMap[U"MINUSASSIGN"] = 111;
    tokenIdMap[U"MINUSMINUS"] = 86;
    tokenIdMap[U"MULASSIGN"] = 107;
    tokenIdMap[U"MUTABLE"] = 17;
    tokenIdMap[U"NAMESPACE"] = 33;
    tokenIdMap[U"NEQ"] = 75;
    tokenIdMap[U"NEW"] = 43;
    tokenIdMap[U"NOT"] = 90;
    tokenIdMap[U"NULLPTR"] = 47;
    tokenIdMap[U"OPERATOR"] = 36;
    tokenIdMap[U"ORASSIGN"] = 116;
    tokenIdMap[U"PLUS"] = 80;
    tokenIdMap[U"PLUSASSIGN"] = 110;
    tokenIdMap[U"PLUSPLUS"] = 85;
    tokenIdMap[U"PREFIX"] = 2;
    tokenIdMap[U"QUEST"] = 91;
    tokenIdMap[U"RANGLE"] = 99;
    tokenIdMap[U"RBRACE"] = 95;
    tokenIdMap[U"RBRACKET"] = 97;
    tokenIdMap[U"REGISTER"] = 14;
    tokenIdMap[U"REINTERPRETCAST"] = 39;
    tokenIdMap[U"REM"] = 84;
    tokenIdMap[U"REMASSIGN"] = 109;
    tokenIdMap[U"RETURN"] = 58;
    tokenIdMap[U"RPAREN"] = 93;
    tokenIdMap[U"SEMICOLON"] = 103;
    tokenIdMap[U"SHIFTLEFT"] = 78;
    tokenIdMap[U"SHIFTLEFTASSIGN"] = 112;
    tokenIdMap[U"SHIFTRIGHT"] = 79;
    tokenIdMap[U"SHIFTRIGHTASSIGN"] = 113;
    tokenIdMap[U"SHORT"] = 21;
    tokenIdMap[U"SIGNED"] = 24;
    tokenIdMap[U"SIZEOF"] = 35;
    tokenIdMap[U"STAR"] = 82;
    tokenIdMap[U"STATIC"] = 15;
    tokenIdMap[U"STATICCAST"] = 38;
    tokenIdMap[U"STRINGLIT"] = 66;
    tokenIdMap[U"SWITCH"] = 52;
    tokenIdMap[U"THIS"] = 42;
    tokenIdMap[U"THROW"] = 34;
    tokenIdMap[U"TOKENS"] = 3;
    tokenIdMap[U"TRUE"] = 45;
    tokenIdMap[U"TRY"] = 60;
    tokenIdMap[U"TYPEDEF"] = 29;
    tokenIdMap[U"TYPEID"] = 41;
    tokenIdMap[U"UNSIGNED"] = 25;
    tokenIdMap[U"USING"] = 32;
    tokenIdMap[U"VARIABLES"] = 7;
    tokenIdMap[U"VOID"] = 28;
    tokenIdMap[U"VOLATILE"] = 31;
    tokenIdMap[U"WCHART"] = 19;
    tokenIdMap[U"WHILE"] = 53;
    tokenIdMap[U"XORASSIGN"] = 115;
}

namespace LexerFileTokens
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
        "CLASSMAP",
        "PREFIX",
        "TOKENS",
        "KEYWORDS",
        "EXPRESSIONS",
        "LEXER",
        "VARIABLES",
        "ACTIONS",
        "API",
        "INCLUDE",
        "FILEPATH",
        "DOLLAR",
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
        "'classmap'",
        "'prefix'",
        "'tokens'",
        "'keywords'",
        "'expressions'",
        "'lexer'",
        "''variables'",
        "'actions'",
        "'api'",
        "'include'",
        "file path",
        "'$'",
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
