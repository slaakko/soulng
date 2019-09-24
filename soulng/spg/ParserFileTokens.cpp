
// this file has been automatically generated from 'D:/work/soulng-project/soulng/spg/ParserFileLexer.lexer' using soulng lexer generator slg version 1.2.0

#include <soulng/spg/ParserFileTokens.hpp>
#include <map>

namespace ParserFileTokens
{
    std::map<std::u32string, int> tokenIdMap;

    void InitTokenIdMap()
    {
        tokenIdMap[U"AMP"] = 75;
        tokenIdMap[U"AMPAMP"] = 70;
        tokenIdMap[U"ANDASSIGN"] = 115;
        tokenIdMap[U"API"] = 2;
        tokenIdMap[U"ARROW"] = 91;
        tokenIdMap[U"ARROWSTAR"] = 72;
        tokenIdMap[U"ASSIGN"] = 107;
        tokenIdMap[U"AUTO"] = 15;
        tokenIdMap[U"BITOR"] = 73;
        tokenIdMap[U"BITXOR"] = 74;
        tokenIdMap[U"BOOL"] = 22;
        tokenIdMap[U"BREAK"] = 58;
        tokenIdMap[U"CASE"] = 50;
        tokenIdMap[U"CATCH"] = 63;
        tokenIdMap[U"CHAR"] = 20;
        tokenIdMap[U"CHARLIT"] = 67;
        tokenIdMap[U"CHARSET"] = 14;
        tokenIdMap[U"COLON"] = 103;
        tokenIdMap[U"COLONCOLON"] = 102;
        tokenIdMap[U"COMMA"] = 106;
        tokenIdMap[U"CONST"] = 32;
        tokenIdMap[U"CONSTCAST"] = 42;
        tokenIdMap[U"CONTINUE"] = 59;
        tokenIdMap[U"CPL"] = 89;
        tokenIdMap[U"CPPPREFIX"] = 9;
        tokenIdMap[U"DEFAULT"] = 51;
        tokenIdMap[U"DELETE"] = 46;
        tokenIdMap[U"DISJUNCTION"] = 69;
        tokenIdMap[U"DIV"] = 85;
        tokenIdMap[U"DIVASSIGN"] = 109;
        tokenIdMap[U"DO"] = 56;
        tokenIdMap[U"DOT"] = 90;
        tokenIdMap[U"DOTSTAR"] = 71;
        tokenIdMap[U"DOUBLE"] = 29;
        tokenIdMap[U"DYNAMICCAST"] = 39;
        tokenIdMap[U"ELLIPSIS"] = 101;
        tokenIdMap[U"ELSE"] = 53;
        tokenIdMap[U"EMPTY"] = 7;
        tokenIdMap[U"EQ"] = 76;
        tokenIdMap[U"EXCLAMATION"] = 13;
        tokenIdMap[U"EXTERN"] = 18;
        tokenIdMap[U"FALSE"] = 48;
        tokenIdMap[U"FILEPATH"] = 11;
        tokenIdMap[U"FLOAT"] = 28;
        tokenIdMap[U"FLOATINGLIT"] = 66;
        tokenIdMap[U"FOR"] = 57;
        tokenIdMap[U"GEQ"] = 79;
        tokenIdMap[U"GOTO"] = 61;
        tokenIdMap[U"HASH"] = 105;
        tokenIdMap[U"HPPPREFIX"] = 10;
        tokenIdMap[U"ID"] = 64;
        tokenIdMap[U"IF"] = 52;
        tokenIdMap[U"INCLUDE"] = 3;
        tokenIdMap[U"INT"] = 24;
        tokenIdMap[U"INTLIT"] = 65;
        tokenIdMap[U"LANGLE"] = 99;
        tokenIdMap[U"LBRACE"] = 95;
        tokenIdMap[U"LBRACKET"] = 97;
        tokenIdMap[U"LEQ"] = 78;
        tokenIdMap[U"LONG"] = 25;
        tokenIdMap[U"LPAREN"] = 93;
        tokenIdMap[U"MAIN"] = 4;
        tokenIdMap[U"MINUS"] = 83;
        tokenIdMap[U"MINUSASSIGN"] = 112;
        tokenIdMap[U"MINUSMINUS"] = 88;
        tokenIdMap[U"MULASSIGN"] = 108;
        tokenIdMap[U"MUTABLE"] = 19;
        tokenIdMap[U"NAMESPACE"] = 35;
        tokenIdMap[U"NEQ"] = 77;
        tokenIdMap[U"NEW"] = 45;
        tokenIdMap[U"NULLPTR"] = 49;
        tokenIdMap[U"OPERATOR"] = 38;
        tokenIdMap[U"ORASSIGN"] = 117;
        tokenIdMap[U"PARSER"] = 1;
        tokenIdMap[U"PLUS"] = 82;
        tokenIdMap[U"PLUSASSIGN"] = 111;
        tokenIdMap[U"PLUSPLUS"] = 87;
        tokenIdMap[U"PRODUCES"] = 12;
        tokenIdMap[U"QUEST"] = 92;
        tokenIdMap[U"RANGLE"] = 100;
        tokenIdMap[U"RBRACE"] = 96;
        tokenIdMap[U"RBRACKET"] = 98;
        tokenIdMap[U"REGISTER"] = 16;
        tokenIdMap[U"REINTERPRETCAST"] = 41;
        tokenIdMap[U"REM"] = 86;
        tokenIdMap[U"REMASSIGN"] = 110;
        tokenIdMap[U"RETURN"] = 60;
        tokenIdMap[U"RPAREN"] = 94;
        tokenIdMap[U"RULEINFO"] = 6;
        tokenIdMap[U"SEMICOLON"] = 104;
        tokenIdMap[U"SHIFTLEFT"] = 80;
        tokenIdMap[U"SHIFTLEFTASSIGN"] = 113;
        tokenIdMap[U"SHIFTRIGHT"] = 81;
        tokenIdMap[U"SHIFTRIGHTASSIGN"] = 114;
        tokenIdMap[U"SHORT"] = 23;
        tokenIdMap[U"SIGNED"] = 26;
        tokenIdMap[U"SIZEOF"] = 37;
        tokenIdMap[U"STAR"] = 84;
        tokenIdMap[U"STATIC"] = 17;
        tokenIdMap[U"STATICCAST"] = 40;
        tokenIdMap[U"STRINGLIT"] = 68;
        tokenIdMap[U"SWITCH"] = 54;
        tokenIdMap[U"THIS"] = 44;
        tokenIdMap[U"THROW"] = 36;
        tokenIdMap[U"TRUE"] = 47;
        tokenIdMap[U"TRY"] = 62;
        tokenIdMap[U"TYPEDEF"] = 31;
        tokenIdMap[U"TYPEID"] = 43;
        tokenIdMap[U"UNSIGNED"] = 27;
        tokenIdMap[U"USELEXER"] = 5;
        tokenIdMap[U"USING"] = 34;
        tokenIdMap[U"VAR"] = 8;
        tokenIdMap[U"VOID"] = 30;
        tokenIdMap[U"VOLATILE"] = 33;
        tokenIdMap[U"WCHART"] = 21;
        tokenIdMap[U"WHILE"] = 55;
        tokenIdMap[U"XORASSIGN"] = 116;
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
        "USELEXER",
        "RULEINFO",
        "EMPTY",
        "VAR",
        "CPPPREFIX",
        "HPPPREFIX",
        "FILEPATH",
        "PRODUCES",
        "EXCLAMATION",
        "CHARSET",
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
        "'uselexer'",
        "'ruleinfo'",
        "'empty'",
        "'var'",
        "cpp-prefix",
        "hpp-prefix",
        "file path",
        "'::='",
        "'!'",
        "charset",
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
