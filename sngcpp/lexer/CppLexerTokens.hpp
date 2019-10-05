#ifndef CppLexerTokens_HPP
#define CppLexerTokens_HPP

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/lexer/CppLexer.lexer' using soulng lexer generator slg version 1.2.0

#include <sngcpp/lexer/CppLexerApi.hpp>
#include <string>

namespace CppLexerTokens
{
    const int END = 0;
    const int CHAR = 1;
    const int CHAR16_T = 2;
    const int CHAR32_T = 3;
    const int WCHAR_T = 4;
    const int BOOL = 5;
    const int SHORT = 6;
    const int INT = 7;
    const int LONG = 8;
    const int SIGNED = 9;
    const int UNSIGNED = 10;
    const int FLOAT = 11;
    const int DOUBLE = 12;
    const int VOID = 13;
    const int AUTO = 14;
    const int FLOATLIT = 15;
    const int INTLIT = 16;
    const int CHARLIT = 17;
    const int STRINGLIT = 18;
    const int NULLPTR = 19;
    const int TRUE = 20;
    const int FALSE = 21;
    const int ID = 22;
    const int COLONCOLON = 23;
    const int COMMA = 24;
    const int ASSIGN = 25;
    const int MULASSIGN = 26;
    const int DIVASSIGN = 27;
    const int REMASSIGN = 28;
    const int ADDASSIGN = 29;
    const int SUBASSIGN = 30;
    const int SHIFTRIGHTASSIGN = 31;
    const int SHIFTLEFTASSIGN = 32;
    const int ANDASSIGN = 33;
    const int XORASSIGN = 34;
    const int ORASSIGN = 35;
    const int QUEST = 36;
    const int COLON = 37;
    const int THROW = 38;
    const int OROR = 39;
    const int ANDAND = 40;
    const int OR = 41;
    const int XOR = 42;
    const int AMP = 43;
    const int EQ = 44;
    const int NEQ = 45;
    const int LEQ = 46;
    const int GEQ = 47;
    const int LANGLE = 48;
    const int RANGLE = 49;
    const int SHIFTLEFT = 50;
    const int SHIFTRIGHT = 51;
    const int PLUS = 52;
    const int MINUS = 53;
    const int STAR = 54;
    const int DIV = 55;
    const int MOD = 56;
    const int DOTSTAR = 57;
    const int ARROWSTAR = 58;
    const int LPAREN = 59;
    const int RPAREN = 60;
    const int PLUSPLUS = 61;
    const int MINUSMINUS = 62;
    const int EXCLAMATION = 63;
    const int TILDE = 64;
    const int SIZEOF = 65;
    const int ALIGNOF = 66;
    const int NEW = 67;
    const int DELETE = 68;
    const int LBRACKET = 69;
    const int RBRACKET = 70;
    const int DOT = 71;
    const int ARROW = 72;
    const int THIS = 73;
    const int STATIC_CAST = 74;
    const int DYNAMIC_CAST = 75;
    const int REINTERPRET_CAST = 76;
    const int CONST_CAST = 77;
    const int TYPEID = 78;
    const int OPERATOR = 79;

    SNGCPP_LEXER_API void InitTokenIdMap();
    SNGCPP_LEXER_API int GetTokenId(const std::u32string& tokenName);
    SNGCPP_LEXER_API const char* GetTokenName(int tokenId);
    SNGCPP_LEXER_API const char* GetTokenInfo(int tokenId);
}
#endif
