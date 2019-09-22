#ifndef ParserFileTokens_HPP
#define ParserFileTokens_HPP

// this file has been automatically generated from 'D:/work/soulng-project/soulng/spg/ParserFileLexer.lexer' using soulng lexer generator slg version 1.1.0

#include <string>

namespace ParserFileTokens
{
    const int END = 0;
    const int PARSER = 1;
    const int API = 2;
    const int INCLUDE = 3;
    const int MAIN = 4;
    const int USELEXER = 5;
    const int RULEINFO = 6;
    const int EMPTY = 7;
    const int VAR = 8;
    const int CPPPREFIX = 9;
    const int HPPPREFIX = 10;
    const int FILEPATH = 11;
    const int PRODUCES = 12;
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
    const int ID = 63;
    const int INTLIT = 64;
    const int FLOATINGLIT = 65;
    const int CHARLIT = 66;
    const int STRINGLIT = 67;
    const int DISJUNCTION = 68;
    const int AMPAMP = 69;
    const int DOTSTAR = 70;
    const int ARROWSTAR = 71;
    const int BITOR = 72;
    const int BITXOR = 73;
    const int AMP = 74;
    const int EQ = 75;
    const int NEQ = 76;
    const int LEQ = 77;
    const int GEQ = 78;
    const int SHIFTLEFT = 79;
    const int SHIFTRIGHT = 80;
    const int PLUS = 81;
    const int MINUS = 82;
    const int STAR = 83;
    const int DIV = 84;
    const int REM = 85;
    const int PLUSPLUS = 86;
    const int MINUSMINUS = 87;
    const int CPL = 88;
    const int DOT = 89;
    const int ARROW = 90;
    const int QUEST = 91;
    const int LPAREN = 92;
    const int RPAREN = 93;
    const int LBRACE = 94;
    const int RBRACE = 95;
    const int LBRACKET = 96;
    const int RBRACKET = 97;
    const int LANGLE = 98;
    const int RANGLE = 99;
    const int ELLIPSIS = 100;
    const int COLONCOLON = 101;
    const int COLON = 102;
    const int SEMICOLON = 103;
    const int HASH = 104;
    const int COMMA = 105;
    const int ASSIGN = 106;
    const int MULASSIGN = 107;
    const int DIVASSIGN = 108;
    const int REMASSIGN = 109;
    const int PLUSASSIGN = 110;
    const int MINUSASSIGN = 111;
    const int SHIFTLEFTASSIGN = 112;
    const int SHIFTRIGHTASSIGN = 113;
    const int ANDASSIGN = 114;
    const int XORASSIGN = 115;
    const int ORASSIGN = 116;

    void InitTokenIdMap();
    int GetTokenId(const std::u32string& tokenName);
    const char* GetTokenName(int tokenId);
    const char* GetTokenInfo(int tokenId);
}
#endif
