
// this file has been automatically generated from 'D:/work/soulng-project/soulng/slg/LexerFileLexer.lexer' using soulng lexer generator slg version 1.0.0

#include <soulng/slg/LexerFileTokens.hpp>
#include <map>

namespace LexerFileTokens
{
    std::map<std::u32string, int> tokenIdMap;

    void InitTokenIdMap()
    {
        tokenIdMap[U"ACTIONS"] = 8;
        tokenIdMap[U"AMP"] = 74;
        tokenIdMap[U"AMPAMP"] = 69;
        tokenIdMap[U"ANDASSIGN"] = 114;
        tokenIdMap[U"API"] = 9;
        tokenIdMap[U"ARROW"] = 90;
        tokenIdMap[U"ARROWSTAR"] = 71;
        tokenIdMap[U"ASSIGN"] = 106;
        tokenIdMap[U"AUTO"] = 14;
        tokenIdMap[U"BITOR"] = 72;
        tokenIdMap[U"BITXOR"] = 73;
        tokenIdMap[U"BOOL"] = 21;
        tokenIdMap[U"BREAK"] = 57;
        tokenIdMap[U"CASE"] = 49;
        tokenIdMap[U"CATCH"] = 62;
        tokenIdMap[U"CHAR"] = 19;
        tokenIdMap[U"CHARLIT"] = 66;
        tokenIdMap[U"CLASSMAP"] = 1;
        tokenIdMap[U"COLON"] = 102;
        tokenIdMap[U"COLONCOLON"] = 101;
        tokenIdMap[U"COMMA"] = 105;
        tokenIdMap[U"CONST"] = 31;
        tokenIdMap[U"CONSTCAST"] = 41;
        tokenIdMap[U"CONTINUE"] = 58;
        tokenIdMap[U"CPL"] = 88;
        tokenIdMap[U"DEFAULT"] = 50;
        tokenIdMap[U"DELETE"] = 45;
        tokenIdMap[U"DISJUNCTION"] = 68;
        tokenIdMap[U"DIV"] = 84;
        tokenIdMap[U"DIVASSIGN"] = 108;
        tokenIdMap[U"DO"] = 55;
        tokenIdMap[U"DOLLAR"] = 12;
        tokenIdMap[U"DOT"] = 89;
        tokenIdMap[U"DOTSTAR"] = 70;
        tokenIdMap[U"DOUBLE"] = 28;
        tokenIdMap[U"DYNAMICCAST"] = 38;
        tokenIdMap[U"ELLIPSIS"] = 100;
        tokenIdMap[U"ELSE"] = 52;
        tokenIdMap[U"EQ"] = 75;
        tokenIdMap[U"EXCLAMATION"] = 13;
        tokenIdMap[U"EXPRESSIONS"] = 5;
        tokenIdMap[U"EXTERN"] = 17;
        tokenIdMap[U"FALSE"] = 47;
        tokenIdMap[U"FILEPATH"] = 11;
        tokenIdMap[U"FLOAT"] = 27;
        tokenIdMap[U"FLOATINGLIT"] = 65;
        tokenIdMap[U"FOR"] = 56;
        tokenIdMap[U"GEQ"] = 78;
        tokenIdMap[U"GOTO"] = 60;
        tokenIdMap[U"HASH"] = 104;
        tokenIdMap[U"ID"] = 63;
        tokenIdMap[U"IF"] = 51;
        tokenIdMap[U"INCLUDE"] = 10;
        tokenIdMap[U"INT"] = 23;
        tokenIdMap[U"INTLIT"] = 64;
        tokenIdMap[U"KEYWORDS"] = 4;
        tokenIdMap[U"LANGLE"] = 98;
        tokenIdMap[U"LBRACE"] = 94;
        tokenIdMap[U"LBRACKET"] = 96;
        tokenIdMap[U"LEQ"] = 77;
        tokenIdMap[U"LEXER"] = 6;
        tokenIdMap[U"LONG"] = 24;
        tokenIdMap[U"LPAREN"] = 92;
        tokenIdMap[U"MINUS"] = 82;
        tokenIdMap[U"MINUSASSIGN"] = 111;
        tokenIdMap[U"MINUSMINUS"] = 87;
        tokenIdMap[U"MULASSIGN"] = 107;
        tokenIdMap[U"MUTABLE"] = 18;
        tokenIdMap[U"NAMESPACE"] = 34;
        tokenIdMap[U"NEQ"] = 76;
        tokenIdMap[U"NEW"] = 44;
        tokenIdMap[U"NULLPTR"] = 48;
        tokenIdMap[U"OPERATOR"] = 37;
        tokenIdMap[U"ORASSIGN"] = 116;
        tokenIdMap[U"PLUS"] = 81;
        tokenIdMap[U"PLUSASSIGN"] = 110;
        tokenIdMap[U"PLUSPLUS"] = 86;
        tokenIdMap[U"PREFIX"] = 2;
        tokenIdMap[U"QUEST"] = 91;
        tokenIdMap[U"RANGLE"] = 99;
        tokenIdMap[U"RBRACE"] = 95;
        tokenIdMap[U"RBRACKET"] = 97;
        tokenIdMap[U"REGISTER"] = 15;
        tokenIdMap[U"REINTERPRETCAST"] = 40;
        tokenIdMap[U"REM"] = 85;
        tokenIdMap[U"REMASSIGN"] = 109;
        tokenIdMap[U"RETURN"] = 59;
        tokenIdMap[U"RPAREN"] = 93;
        tokenIdMap[U"SEMICOLON"] = 103;
        tokenIdMap[U"SHIFTLEFT"] = 79;
        tokenIdMap[U"SHIFTLEFTASSIGN"] = 112;
        tokenIdMap[U"SHIFTRIGHT"] = 80;
        tokenIdMap[U"SHIFTRIGHTASSIGN"] = 113;
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
        tokenIdMap[U"TOKENS"] = 3;
        tokenIdMap[U"TRUE"] = 46;
        tokenIdMap[U"TRY"] = 61;
        tokenIdMap[U"TYPEDEF"] = 30;
        tokenIdMap[U"TYPEID"] = 42;
        tokenIdMap[U"UNSIGNED"] = 26;
        tokenIdMap[U"USING"] = 33;
        tokenIdMap[U"VARIABLES"] = 7;
        tokenIdMap[U"VOID"] = 29;
        tokenIdMap[U"VOLATILE"] = 32;
        tokenIdMap[U"WCHART"] = 20;
        tokenIdMap[U"WHILE"] = 54;
        tokenIdMap[U"XORASSIGN"] = 115;
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
