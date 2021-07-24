#ifndef CppTokenLexerTokens_HPP
#define CppTokenLexerTokens_HPP

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/lexer/CppTokenLexer.lexer' using soulng lexer generator slg version 4.0.0

#include <sngcpp20/lexer/CppLexerApi.hpp>
#include <sngcpp20/ast/SourceCodeWriter.hpp>
#include <string>

namespace CppTokenLexerTokens
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
    const int COLONCOLON = 87;
    const int COMMA = 88;
    const int ASSIGN = 89;
    const int MULASSIGN = 90;
    const int DIVASSIGN = 91;
    const int REMASSIGN = 92;
    const int ADDASSIGN = 93;
    const int SUBASSIGN = 94;
    const int SHIFTRIGHTASSIGN = 95;
    const int SHIFTLEFTASSIGN = 96;
    const int ANDASSIGN = 97;
    const int XORASSIGN = 98;
    const int ORASSIGN = 99;
    const int QUEST = 100;
    const int COLON = 101;
    const int OROR = 102;
    const int AMPAMP = 103;
    const int OR = 104;
    const int XOR = 105;
    const int AMP = 106;
    const int EQ = 107;
    const int NEQ = 108;
    const int LEQ = 109;
    const int GEQ = 110;
    const int SPACESHIP = 111;
    const int LANGLE = 112;
    const int RANGLE = 113;
    const int SHIFTLEFT = 114;
    const int SHIFTRIGHT = 115;
    const int PLUS = 116;
    const int MINUS = 117;
    const int STAR = 118;
    const int DIV = 119;
    const int MOD = 120;
    const int DOTSTAR = 121;
    const int ARROWSTAR = 122;
    const int LPAREN = 123;
    const int RPAREN = 124;
    const int PLUSPLUS = 125;
    const int MINUSMINUS = 126;
    const int EXCLAMATION = 127;
    const int TILDE = 128;
    const int LBRACKET = 129;
    const int RBRACKET = 130;
    const int LBRACE = 131;
    const int RBRACE = 132;
    const int DOT = 133;
    const int ARROW = 134;
    const int SEMICOLON = 135;
    const int ELLIPSIS = 136;
    const int WS = 137;
    const int LINECOMMENT = 138;
    const int BLOCKCOMMENT = 139;
    const int BLOCKCOMMENTLINE = 140;
    const int KEYWORD = 141;
    const int ID = 142;
    const int NUMBER = 143;
    const int PP = 144;
    const int OTHER = 145;
    const int __THREAD = 146;
    const int __DECLSPEC = 147;
    const int __CDECL = 148;
    const int __FASTCALL = 149;
    const int __STDCALL = 150;
    const int __THISCALL = 151;
    const int __VECTORCALL = 152;
    const int __INT64 = 153;
    const int __INT32 = 154;
    const int __INT16 = 155;
    const int __INT8 = 156;
    const int __UNALIGNED = 157;
    const int __INLINE = 158;
    const int __NULLPTR = 159;
    const int MAX = 160;

    LEXER_API void InitTokenIdMap();
    LEXER_API int GetTokenId(const std::u32string& tokenName);
    LEXER_API const char* GetTokenName(int tokenId);
    LEXER_API const char* GetTokenInfo(int tokenId);
}
#endif
