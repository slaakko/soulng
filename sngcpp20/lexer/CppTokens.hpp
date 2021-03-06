#ifndef CppTokens_HPP
#define CppTokens_HPP

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/lexer/CppLexer.lexer' using soulng lexer generator slg version 4.0.0

#include <sngcpp20/lexer/CppLexerApi.hpp>
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
    const int FLOATLIT = 82;
    const int INTLIT = 83;
    const int CHARLIT = 84;
    const int STRINGLIT = 85;
    const int BEGINRAWSTRINGLIT = 86;
    const int ID = 87;
    const int COLONCOLON = 88;
    const int COMMA = 89;
    const int ASSIGN = 90;
    const int MULASSIGN = 91;
    const int DIVASSIGN = 92;
    const int REMASSIGN = 93;
    const int ADDASSIGN = 94;
    const int SUBASSIGN = 95;
    const int SHIFTRIGHTASSIGN = 96;
    const int SHIFTLEFTASSIGN = 97;
    const int ANDASSIGN = 98;
    const int XORASSIGN = 99;
    const int ORASSIGN = 100;
    const int QUEST = 101;
    const int COLON = 102;
    const int OROR = 103;
    const int AMPAMP = 104;
    const int OR = 105;
    const int XOR = 106;
    const int AMP = 107;
    const int EQ = 108;
    const int NEQ = 109;
    const int LEQ = 110;
    const int GEQ = 111;
    const int SPACESHIP = 112;
    const int LANGLE = 113;
    const int RANGLE = 114;
    const int SHIFTLEFT = 115;
    const int SHIFTRIGHT = 116;
    const int PLUS = 117;
    const int MINUS = 118;
    const int STAR = 119;
    const int DIV = 120;
    const int MOD = 121;
    const int DOTSTAR = 122;
    const int ARROWSTAR = 123;
    const int LPAREN = 124;
    const int RPAREN = 125;
    const int PLUSPLUS = 126;
    const int MINUSMINUS = 127;
    const int EXCLAMATION = 128;
    const int TILDE = 129;
    const int LBRACKET = 130;
    const int RBRACKET = 131;
    const int LBRACE = 132;
    const int RBRACE = 133;
    const int DOT = 134;
    const int ARROW = 135;
    const int SEMICOLON = 136;
    const int ELLIPSIS = 137;
    const int ANGLEHEADERNAME = 138;
    const int QUOTEHEADERNAME = 139;
    const int __THREAD = 140;
    const int __DECLSPEC = 141;
    const int __CDECL = 142;
    const int __FASTCALL = 143;
    const int __STDCALL = 144;
    const int __INT64 = 145;
    const int __UNALIGNED = 146;
    const int __INLINE = 147;
    const int __NULLPTR = 148;
    const int MAX = 149;

    LEXER_API void InitTokenIdMap();
    LEXER_API int GetTokenId(const std::u32string& tokenName);
    LEXER_API const char* GetTokenName(int tokenId);
    LEXER_API const char* GetTokenInfo(int tokenId);
}
#endif
