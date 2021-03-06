#ifndef LexerFileTokenLexerTokens_HPP
#define LexerFileTokenLexerTokens_HPP

// this file has been automatically generated from 'D:/work/soulng-project/tools/gendoc/html/LexerFileTokenLexer.lexer' using soulng lexer generator slg version 3.0.0

#include <string>

namespace LexerFileTokenLexerTokens
{
    const int END = 0;
    const int CLASSMAP = 1;
    const int PREFIX = 2;
    const int TOKENS = 3;
    const int KEYWORDS = 4;
    const int EXPRESSIONS = 5;
    const int LEXER = 6;
    const int VARIABLES = 7;
    const int ACTIONS = 8;
    const int API = 9;
    const int INCLUDE = 10;
    const int FILEPATH = 11;
    const int DOLLAR = 12;
    const int EXCLAMATION = 13;
    const int AUTO = 14;
    const int REGISTER = 15;
    const int STATIC = 16;
    const int EXTERN = 17;
    const int MUTABLE = 18;
    const int CHAR = 19;
    const int WCHART = 20;
    const int BOOL = 21;
    const int SHORT = 22;
    const int INT = 23;
    const int LONG = 24;
    const int SIGNED = 25;
    const int UNSIGNED = 26;
    const int FLOAT = 27;
    const int DOUBLE = 28;
    const int VOID = 29;
    const int TYPEDEF = 30;
    const int CONST = 31;
    const int VOLATILE = 32;
    const int USING = 33;
    const int NAMESPACE = 34;
    const int THROW = 35;
    const int SIZEOF = 36;
    const int OPERATOR = 37;
    const int DYNAMICCAST = 38;
    const int STATICCAST = 39;
    const int REINTERPRETCAST = 40;
    const int CONSTCAST = 41;
    const int TYPEID = 42;
    const int THIS = 43;
    const int NEW = 44;
    const int DELETE = 45;
    const int TRUE = 46;
    const int FALSE = 47;
    const int NULLPTR = 48;
    const int CASE = 49;
    const int DEFAULT = 50;
    const int IF = 51;
    const int ELSE = 52;
    const int SWITCH = 53;
    const int WHILE = 54;
    const int DO = 55;
    const int FOR = 56;
    const int BREAK = 57;
    const int CONTINUE = 58;
    const int RETURN = 59;
    const int GOTO = 60;
    const int TRY = 61;
    const int CATCH = 62;
    const int INTLIT = 63;
    const int FLOATINGLIT = 64;
    const int CHARLIT = 65;
    const int STRINGLIT = 66;
    const int DISJUNCTION = 67;
    const int AMPAMP = 68;
    const int DOTSTAR = 69;
    const int ARROWSTAR = 70;
    const int BITOR = 71;
    const int BITXOR = 72;
    const int AMP = 73;
    const int EQ = 74;
    const int NEQ = 75;
    const int LEQ = 76;
    const int GEQ = 77;
    const int SHIFTLEFT = 78;
    const int SHIFTRIGHT = 79;
    const int PLUS = 80;
    const int MINUS = 81;
    const int STAR = 82;
    const int DIV = 83;
    const int REM = 84;
    const int PLUSPLUS = 85;
    const int MINUSMINUS = 86;
    const int CPL = 87;
    const int DOT = 88;
    const int ARROW = 89;
    const int QUEST = 90;
    const int LPAREN = 91;
    const int RPAREN = 92;
    const int LBRACE = 93;
    const int RBRACE = 94;
    const int LBRACKET = 95;
    const int RBRACKET = 96;
    const int LANGLE = 97;
    const int RANGLE = 98;
    const int ELLIPSIS = 99;
    const int COLONCOLON = 100;
    const int COLON = 101;
    const int SEMICOLON = 102;
    const int HASH = 103;
    const int COMMA = 104;
    const int ASSIGN = 105;
    const int MULASSIGN = 106;
    const int DIVASSIGN = 107;
    const int REMASSIGN = 108;
    const int PLUSASSIGN = 109;
    const int MINUSASSIGN = 110;
    const int SHIFTLEFTASSIGN = 111;
    const int SHIFTRIGHTASSIGN = 112;
    const int ANDASSIGN = 113;
    const int XORASSIGN = 114;
    const int ORASSIGN = 115;
    const int WS = 116;
    const int LINECOMMENT = 117;
    const int BLOCKCOMMENT = 118;
    const int KEYWORD = 119;
    const int ID = 120;
    const int NUMBER = 121;
    const int PP = 122;
    const int OTHER = 123;

    void InitTokenIdMap();
    int GetTokenId(const std::u32string& tokenName);
    const char* GetTokenName(int tokenId);
    const char* GetTokenInfo(int tokenId);
}
#endif
