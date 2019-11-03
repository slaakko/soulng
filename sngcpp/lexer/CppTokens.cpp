
// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/lexer/CppLexer.lexer' using soulng lexer generator slg version 2.0.0

#include <sngcpp/lexer/CppTokens.hpp>
#include <map>

namespace CppTokens
{
    std::map<std::u32string, int> tokenIdMap;

    void InitTokenIdMap()
    {
        tokenIdMap[U"ADDASSIGN"] = 97;
        tokenIdMap[U"ALIGNAS"] = 1;
        tokenIdMap[U"ALIGNOF"] = 2;
        tokenIdMap[U"AMP"] = 110;
        tokenIdMap[U"AMPAMP"] = 107;
        tokenIdMap[U"ANDASSIGN"] = 101;
        tokenIdMap[U"ARROW"] = 138;
        tokenIdMap[U"ARROWSTAR"] = 126;
        tokenIdMap[U"ASM"] = 3;
        tokenIdMap[U"ASSIGN"] = 93;
        tokenIdMap[U"AUTO"] = 4;
        tokenIdMap[U"BOOL"] = 5;
        tokenIdMap[U"BREAK"] = 6;
        tokenIdMap[U"CASE"] = 7;
        tokenIdMap[U"CATCH"] = 8;
        tokenIdMap[U"CHAR"] = 9;
        tokenIdMap[U"CHAR16_T"] = 11;
        tokenIdMap[U"CHAR32_T"] = 12;
        tokenIdMap[U"CHAR8_T"] = 10;
        tokenIdMap[U"CHARLIT"] = 88;
        tokenIdMap[U"CLASS"] = 13;
        tokenIdMap[U"COLON"] = 105;
        tokenIdMap[U"COLONCOLON"] = 91;
        tokenIdMap[U"COMMA"] = 92;
        tokenIdMap[U"CONCEPT"] = 14;
        tokenIdMap[U"CONST"] = 15;
        tokenIdMap[U"CONSTEVAL"] = 16;
        tokenIdMap[U"CONSTEXPR"] = 17;
        tokenIdMap[U"CONSTINIT"] = 18;
        tokenIdMap[U"CONST_CAST"] = 19;
        tokenIdMap[U"CONTINUE"] = 20;
        tokenIdMap[U"CO_AWAIT"] = 21;
        tokenIdMap[U"CO_RETURN"] = 22;
        tokenIdMap[U"CO_YIELD"] = 23;
        tokenIdMap[U"DECLTYPE"] = 24;
        tokenIdMap[U"DEFAULT"] = 25;
        tokenIdMap[U"DELETE"] = 26;
        tokenIdMap[U"DIV"] = 123;
        tokenIdMap[U"DIVASSIGN"] = 95;
        tokenIdMap[U"DO"] = 27;
        tokenIdMap[U"DOT"] = 137;
        tokenIdMap[U"DOTSTAR"] = 125;
        tokenIdMap[U"DOUBLE"] = 28;
        tokenIdMap[U"DYNAMIC_CAST"] = 29;
        tokenIdMap[U"ELLIPSES"] = 140;
        tokenIdMap[U"ELSE"] = 30;
        tokenIdMap[U"ENUM"] = 31;
        tokenIdMap[U"EQ"] = 111;
        tokenIdMap[U"EXCLAMATION"] = 131;
        tokenIdMap[U"EXPLICIT"] = 32;
        tokenIdMap[U"EXPORT"] = 33;
        tokenIdMap[U"EXTERN"] = 34;
        tokenIdMap[U"FALSE"] = 35;
        tokenIdMap[U"FINAL"] = 83;
        tokenIdMap[U"FLOAT"] = 36;
        tokenIdMap[U"FLOATLIT"] = 86;
        tokenIdMap[U"FOR"] = 37;
        tokenIdMap[U"FRIEND"] = 38;
        tokenIdMap[U"GEQ"] = 114;
        tokenIdMap[U"GOTO"] = 39;
        tokenIdMap[U"ID"] = 90;
        tokenIdMap[U"IF"] = 40;
        tokenIdMap[U"INLINE"] = 41;
        tokenIdMap[U"INT"] = 42;
        tokenIdMap[U"INTLIT"] = 87;
        tokenIdMap[U"LANGLE"] = 116;
        tokenIdMap[U"LBRACE"] = 135;
        tokenIdMap[U"LBRACKET"] = 133;
        tokenIdMap[U"LEQ"] = 113;
        tokenIdMap[U"LONG"] = 43;
        tokenIdMap[U"LPAREN"] = 127;
        tokenIdMap[U"MAX"] = 141;
        tokenIdMap[U"MINUS"] = 121;
        tokenIdMap[U"MINUSMINUS"] = 130;
        tokenIdMap[U"MOD"] = 124;
        tokenIdMap[U"MULASSIGN"] = 94;
        tokenIdMap[U"MUTABLE"] = 44;
        tokenIdMap[U"NAMESPACE"] = 45;
        tokenIdMap[U"NEQ"] = 112;
        tokenIdMap[U"NEW"] = 46;
        tokenIdMap[U"NOEXCEPT"] = 47;
        tokenIdMap[U"NULLPTR"] = 48;
        tokenIdMap[U"OPERATOR"] = 49;
        tokenIdMap[U"OR"] = 108;
        tokenIdMap[U"ORASSIGN"] = 103;
        tokenIdMap[U"OROR"] = 106;
        tokenIdMap[U"OVERRIDE"] = 82;
        tokenIdMap[U"PLUS"] = 120;
        tokenIdMap[U"PLUSPLUS"] = 129;
        tokenIdMap[U"PRIVATE"] = 50;
        tokenIdMap[U"PROTECTED"] = 51;
        tokenIdMap[U"PUBLIC"] = 52;
        tokenIdMap[U"QUEST"] = 104;
        tokenIdMap[U"RANGLE"] = 117;
        tokenIdMap[U"RBRACE"] = 136;
        tokenIdMap[U"RBRACKET"] = 134;
        tokenIdMap[U"REGISTER"] = 53;
        tokenIdMap[U"REINTERPRET_CAST"] = 54;
        tokenIdMap[U"REMASSIGN"] = 96;
        tokenIdMap[U"REQUIRES"] = 55;
        tokenIdMap[U"RETURN"] = 56;
        tokenIdMap[U"RPAREN"] = 128;
        tokenIdMap[U"SEMICOLON"] = 139;
        tokenIdMap[U"SHIFTLEFT"] = 118;
        tokenIdMap[U"SHIFTLEFTASSIGN"] = 100;
        tokenIdMap[U"SHIFTRIGHT"] = 119;
        tokenIdMap[U"SHIFTRIGHTASSIGN"] = 99;
        tokenIdMap[U"SHORT"] = 57;
        tokenIdMap[U"SIGNED"] = 58;
        tokenIdMap[U"SIZEOF"] = 59;
        tokenIdMap[U"SPACESHIP"] = 115;
        tokenIdMap[U"STAR"] = 122;
        tokenIdMap[U"STATIC"] = 60;
        tokenIdMap[U"STATIC_ASSERT"] = 61;
        tokenIdMap[U"STATIC_CAST"] = 62;
        tokenIdMap[U"STRINGLIT"] = 89;
        tokenIdMap[U"STRUCT"] = 63;
        tokenIdMap[U"SUBASSIGN"] = 98;
        tokenIdMap[U"SWITCH"] = 64;
        tokenIdMap[U"TEMPLATE"] = 65;
        tokenIdMap[U"THIS"] = 66;
        tokenIdMap[U"THREAD_LOCAL"] = 67;
        tokenIdMap[U"THROW"] = 68;
        tokenIdMap[U"TILDE"] = 132;
        tokenIdMap[U"TRUE"] = 69;
        tokenIdMap[U"TRY"] = 70;
        tokenIdMap[U"TYPEDEF"] = 71;
        tokenIdMap[U"TYPEID"] = 72;
        tokenIdMap[U"TYPENAME"] = 73;
        tokenIdMap[U"UNION"] = 74;
        tokenIdMap[U"UNSIGNED"] = 75;
        tokenIdMap[U"USING"] = 76;
        tokenIdMap[U"VIRTUAL"] = 77;
        tokenIdMap[U"VOID"] = 78;
        tokenIdMap[U"VOLATILE"] = 79;
        tokenIdMap[U"WCHAR_T"] = 80;
        tokenIdMap[U"WHILE"] = 81;
        tokenIdMap[U"XOR"] = 109;
        tokenIdMap[U"XORASSIGN"] = 102;
        tokenIdMap[U"__DECLSPEC"] = 84;
        tokenIdMap[U"__THREAD"] = 85;
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
        "ALIGNAS",
        "ALIGNOF",
        "ASM",
        "AUTO",
        "BOOL",
        "BREAK",
        "CASE",
        "CATCH",
        "CHAR",
        "CHAR8_T",
        "CHAR16_T",
        "CHAR32_T",
        "CLASS",
        "CONCEPT",
        "CONST",
        "CONSTEVAL",
        "CONSTEXPR",
        "CONSTINIT",
        "CONST_CAST",
        "CONTINUE",
        "CO_AWAIT",
        "CO_RETURN",
        "CO_YIELD",
        "DECLTYPE",
        "DEFAULT",
        "DELETE",
        "DO",
        "DOUBLE",
        "DYNAMIC_CAST",
        "ELSE",
        "ENUM",
        "EXPLICIT",
        "EXPORT",
        "EXTERN",
        "FALSE",
        "FLOAT",
        "FOR",
        "FRIEND",
        "GOTO",
        "IF",
        "INLINE",
        "INT",
        "LONG",
        "MUTABLE",
        "NAMESPACE",
        "NEW",
        "NOEXCEPT",
        "NULLPTR",
        "OPERATOR",
        "PRIVATE",
        "PROTECTED",
        "PUBLIC",
        "REGISTER",
        "REINTERPRET_CAST",
        "REQUIRES",
        "RETURN",
        "SHORT",
        "SIGNED",
        "SIZEOF",
        "STATIC",
        "STATIC_ASSERT",
        "STATIC_CAST",
        "STRUCT",
        "SWITCH",
        "TEMPLATE",
        "THIS",
        "THREAD_LOCAL",
        "THROW",
        "TRUE",
        "TRY",
        "TYPEDEF",
        "TYPEID",
        "TYPENAME",
        "UNION",
        "UNSIGNED",
        "USING",
        "VIRTUAL",
        "VOID",
        "VOLATILE",
        "WCHAR_T",
        "WHILE",
        "OVERRIDE",
        "FINAL",
        "__DECLSPEC",
        "__THREAD",
        "FLOATLIT",
        "INTLIT",
        "CHARLIT",
        "STRINGLIT",
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
        "'alignas'",
        "'alignof'",
        "'asm'",
        "'auto'",
        "'bool'",
        "'break'",
        "'case'",
        "'catch'",
        "'char'",
        "'char8_t'",
        "'char16_t'",
        "'char32_t'",
        "'class'",
        "'concept'",
        "'const'",
        "'consteval'",
        "'constexpr'",
        "'constinit'",
        "'const_cast'",
        "'continue'",
        "'co_await'",
        "'co_return'",
        "'co_yield'",
        "'decltype'",
        "'default'",
        "'delete'",
        "'do'",
        "'double'",
        "'dynamic_cast'",
        "'else'",
        "'enum'",
        "'explicit'",
        "'export'",
        "'extern'",
        "'false'",
        "'float'",
        "'for'",
        "'friend'",
        "'goto'",
        "'if'",
        "'inline'",
        "'int'",
        "'long'",
        "'mutable'",
        "'namespace'",
        "'new'",
        "'noexcept'",
        "'nullptr'",
        "'operator'",
        "'private'",
        "'protected'",
        "'public'",
        "'register'",
        "'reinterpret_cast'",
        "'requires'",
        "'return'",
        "'short'",
        "'signed'",
        "'sizeof'",
        "'static'",
        "'static_assert'",
        "'static_cast'",
        "'struct'",
        "'switch'",
        "'template'",
        "'this'",
        "'thread_local'",
        "'throw'",
        "'true'",
        "'try'",
        "'typedef'",
        "'typeid'",
        "'typename'",
        "'union'",
        "'unsigned'",
        "'using'",
        "'virtual'",
        "'void'",
        "'volatile'",
        "'wchar_t'",
        "'while'",
        "'override'",
        "'final'",
        "'__declspec'",
        "'__thread'",
        "floating literal",
        "integer literal",
        "character literal",
        "string literal",
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
