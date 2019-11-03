#ifndef CppTokens_HPP
#define CppTokens_HPP

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/lexer/CppLexer.lexer' using soulng lexer generator slg version 2.0.0

#include <sngcpp/lexer/CppLexerApi.hpp>
#include <string>

namespace CppTokens
{
    const int END = 0;
    const int ALIGNAS = 1;
    const int ALIGNOF = 2;
    const int ASM = 3;
    const int AUTO = 4;
    const int BOOL = 5;
    const int BREAK = 6;
    const int CASE = 7;
    const int CATCH = 8;
    const int CHAR = 9;
    const int CHAR8_T = 10;
    const int CHAR16_T = 11;
    const int CHAR32_T = 12;
    const int CLASS = 13;
    const int CONCEPT = 14;
    const int CONST = 15;
    const int CONSTEVAL = 16;
    const int CONSTEXPR = 17;
    const int CONSTINIT = 18;
    const int CONST_CAST = 19;
    const int CONTINUE = 20;
    const int CO_AWAIT = 21;
    const int CO_RETURN = 22;
    const int CO_YIELD = 23;
    const int DECLTYPE = 24;
    const int DEFAULT = 25;
    const int DELETE = 26;
    const int DO = 27;
    const int DOUBLE = 28;
    const int DYNAMIC_CAST = 29;
    const int ELSE = 30;
    const int ENUM = 31;
    const int EXPLICIT = 32;
    const int EXPORT = 33;
    const int EXTERN = 34;
    const int FALSE = 35;
    const int FLOAT = 36;
    const int FOR = 37;
    const int FRIEND = 38;
    const int GOTO = 39;
    const int IF = 40;
    const int INLINE = 41;
    const int INT = 42;
    const int LONG = 43;
    const int MUTABLE = 44;
    const int NAMESPACE = 45;
    const int NEW = 46;
    const int NOEXCEPT = 47;
    const int NULLPTR = 48;
    const int OPERATOR = 49;
    const int PRIVATE = 50;
    const int PROTECTED = 51;
    const int PUBLIC = 52;
    const int REGISTER = 53;
    const int REINTERPRET_CAST = 54;
    const int REQUIRES = 55;
    const int RETURN = 56;
    const int SHORT = 57;
    const int SIGNED = 58;
    const int SIZEOF = 59;
    const int STATIC = 60;
    const int STATIC_ASSERT = 61;
    const int STATIC_CAST = 62;
    const int STRUCT = 63;
    const int SWITCH = 64;
    const int TEMPLATE = 65;
    const int THIS = 66;
    const int THREAD_LOCAL = 67;
    const int THROW = 68;
    const int TRUE = 69;
    const int TRY = 70;
    const int TYPEDEF = 71;
    const int TYPEID = 72;
    const int TYPENAME = 73;
    const int UNION = 74;
    const int UNSIGNED = 75;
    const int USING = 76;
    const int VIRTUAL = 77;
    const int VOID = 78;
    const int VOLATILE = 79;
    const int WCHAR_T = 80;
    const int WHILE = 81;
    const int OVERRIDE = 82;
    const int FINAL = 83;
    const int __DECLSPEC = 84;
    const int __THREAD = 85;
    const int FLOATLIT = 86;
    const int INTLIT = 87;
    const int CHARLIT = 88;
    const int STRINGLIT = 89;
    const int ID = 90;
    const int COLONCOLON = 91;
    const int COMMA = 92;
    const int ASSIGN = 93;
    const int MULASSIGN = 94;
    const int DIVASSIGN = 95;
    const int REMASSIGN = 96;
    const int ADDASSIGN = 97;
    const int SUBASSIGN = 98;
    const int SHIFTRIGHTASSIGN = 99;
    const int SHIFTLEFTASSIGN = 100;
    const int ANDASSIGN = 101;
    const int XORASSIGN = 102;
    const int ORASSIGN = 103;
    const int QUEST = 104;
    const int COLON = 105;
    const int OROR = 106;
    const int AMPAMP = 107;
    const int OR = 108;
    const int XOR = 109;
    const int AMP = 110;
    const int EQ = 111;
    const int NEQ = 112;
    const int LEQ = 113;
    const int GEQ = 114;
    const int SPACESHIP = 115;
    const int LANGLE = 116;
    const int RANGLE = 117;
    const int SHIFTLEFT = 118;
    const int SHIFTRIGHT = 119;
    const int PLUS = 120;
    const int MINUS = 121;
    const int STAR = 122;
    const int DIV = 123;
    const int MOD = 124;
    const int DOTSTAR = 125;
    const int ARROWSTAR = 126;
    const int LPAREN = 127;
    const int RPAREN = 128;
    const int PLUSPLUS = 129;
    const int MINUSMINUS = 130;
    const int EXCLAMATION = 131;
    const int TILDE = 132;
    const int LBRACKET = 133;
    const int RBRACKET = 134;
    const int LBRACE = 135;
    const int RBRACE = 136;
    const int DOT = 137;
    const int ARROW = 138;
    const int SEMICOLON = 139;
    const int ELLIPSES = 140;
    const int MAX = 141;

    SNGCPP_LEXER_API void InitTokenIdMap();
    SNGCPP_LEXER_API int GetTokenId(const std::u32string& tokenName);
    SNGCPP_LEXER_API const char* GetTokenName(int tokenId);
    SNGCPP_LEXER_API const char* GetTokenInfo(int tokenId);
}
#endif