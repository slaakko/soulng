#ifndef ParserFileTokenLexerTokens_HPP
#define ParserFileTokenLexerTokens_HPP

// this file has been automatically generated from 'D:/work/soulng-project/sngcm/cmlexer/ParserFileTokenLexer.lexer' using soulng lexer generator slg version 3.0.0

#include <sngcm/cmlexer/CmajorLexerApi.hpp>
#include <string>

namespace ParserFileTokenLexerTokens
{
    const int END = 0;
    const int PARSER = 1;
    const int MAIN = 2;
    const int USELEXER = 3;
    const int RULEINFO = 4;
    const int EMPTY = 5;
    const int ANY = 6;
    const int VAR = 7;
    const int PRODUCES = 8;
    const int ASSERT = 9;
    const int ELIF = 10;
    const int ENDIF = 11;
    const int BOOL = 12;
    const int TRUE = 13;
    const int FALSE = 14;
    const int SBYTE = 15;
    const int BYTE = 16;
    const int SHORT = 17;
    const int USHORT = 18;
    const int INT = 19;
    const int UINT = 20;
    const int LONG = 21;
    const int ULONG = 22;
    const int FLOAT = 23;
    const int DOUBLE = 24;
    const int CHAR = 25;
    const int WCHAR = 26;
    const int UCHAR = 27;
    const int VOID = 28;
    const int ENUM = 29;
    const int CAST = 30;
    const int INTERFACE = 31;
    const int NAMESPACE = 32;
    const int USING = 33;
    const int STATIC = 34;
    const int EXTERN = 35;
    const int AS = 36;
    const int IS = 37;
    const int EXPLICIT = 38;
    const int DELEGATE = 39;
    const int INLINE = 40;
    const int CDECL = 41;
    const int NOTHROW = 42;
    const int PUBLIC = 43;
    const int PROTECTED = 44;
    const int PRIVATE = 45;
    const int INTERNAL = 46;
    const int VIRTUAL = 47;
    const int ABSTRACT = 48;
    const int OVERRIDE = 49;
    const int SUPPRESS = 50;
    const int OPERATOR = 51;
    const int CLASS = 52;
    const int RETURN = 53;
    const int IF = 54;
    const int ELSE = 55;
    const int SWITCH = 56;
    const int CASE = 57;
    const int DEFAULT = 58;
    const int WHILE = 59;
    const int DO = 60;
    const int FOR = 61;
    const int BREAK = 62;
    const int CONTINUE = 63;
    const int GOTO = 64;
    const int TYPEDEF = 65;
    const int TYPENAME = 66;
    const int TYPEID = 67;
    const int CONST = 68;
    const int CONSTEXPR = 69;
    const int NULLLIT = 70;
    const int THIS = 71;
    const int BASE = 72;
    const int CONSTRUCT = 73;
    const int DESTROY = 74;
    const int NEW = 75;
    const int DELETE = 76;
    const int SIZEOF = 77;
    const int TRY = 78;
    const int CATCH = 79;
    const int THROW = 80;
    const int CONCEPT = 81;
    const int WHERE = 82;
    const int AXIOM = 83;
    const int AND = 84;
    const int OR = 85;
    const int EXCLAMATION = 86;
    const int UNIT_TEST = 87;
    const int FLOATINGLIT = 88;
    const int INTLIT = 89;
    const int CHARLIT = 90;
    const int STRINGLIT = 91;
    const int EQUIVALENCE = 92;
    const int IMPLICATION = 93;
    const int DISJUNCTION = 94;
    const int AMPAMP = 95;
    const int BITOR = 96;
    const int BITXOR = 97;
    const int AMP = 98;
    const int EQ = 99;
    const int NEQ = 100;
    const int LEQ = 101;
    const int GEQ = 102;
    const int SHIFTLEFT = 103;
    const int SHIFTRIGHT = 104;
    const int PLUS = 105;
    const int MINUS = 106;
    const int STAR = 107;
    const int DIV = 108;
    const int REM = 109;
    const int PLUSPLUS = 110;
    const int MINUSMINUS = 111;
    const int CPL = 112;
    const int DOT = 113;
    const int ARROW = 114;
    const int LBRACKET = 115;
    const int RBRACKET = 116;
    const int LPAREN = 117;
    const int RPAREN = 118;
    const int LANGLE = 119;
    const int RANGLE = 120;
    const int LBRACE = 121;
    const int RBRACE = 122;
    const int COMMA = 123;
    const int ASSIGN = 124;
    const int COLON = 125;
    const int SEMICOLON = 126;
    const int HASH = 127;
    const int WS = 128;
    const int LINECOMMENT = 129;
    const int BLOCKCOMMENT = 130;
    const int BLOCKCOMMENTLINE = 131;
    const int KEYWORD = 132;
    const int ID = 133;
    const int NUMBER = 134;
    const int OTHER = 135;
    const int MAX = 136;

    SNGCM_LEXER_API void InitTokenIdMap();
    SNGCM_LEXER_API int GetTokenId(const std::u32string& tokenName);
    SNGCM_LEXER_API const char* GetTokenName(int tokenId);
    SNGCM_LEXER_API const char* GetTokenInfo(int tokenId);
}
#endif
