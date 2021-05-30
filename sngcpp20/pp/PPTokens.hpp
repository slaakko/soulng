#ifndef PPTokens_HPP
#define PPTokens_HPP

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/pp/PPLexer.lexer' using soulng lexer generator slg version 4.0.0

#include <sngcpp20/pp/PP.hpp>
#include <string>

namespace PPTokens
{
    const int END = 0;
    const int DEFINE = 1;
    const int INCLUDE = 2;
    const int IF = 3;
    const int ELIF = 4;
    const int ELSE = 5;
    const int ENDIF = 6;
    const int IFDEF = 7;
    const int IFNDEF = 8;
    const int UNDEF = 9;
    const int LINE = 10;
    const int ERROR = 11;
    const int PRAGMA = 12;
    const int DEFINED = 13;
    const int ANGLEHEADERNAME = 14;
    const int QUOTEHEADERNAME = 15;
    const int PPNUMBER = 16;
    const int CHARLITERAL = 17;
    const int STRINGLITERAL = 18;
    const int BEGINRAWSTRINGLITERAL = 19;
    const int BEGINBLOCKCOMMENT = 20;
    const int BLOCKCOMMENT = 21;
    const int LINECOMMENT = 22;
    const int WS = 23;
    const int NEWLINE = 24;
    const int HASHHASH = 25;
    const int HASH = 26;
    const int CHAR = 27;
    const int ID = 28;
    const int COLONCOLON = 29;
    const int COMMA = 30;
    const int ASSIGN = 31;
    const int MULASSIGN = 32;
    const int DIVASSIGN = 33;
    const int REMASSIGN = 34;
    const int ADDASSIGN = 35;
    const int SUBASSIGN = 36;
    const int SHIFTRIGHTASSIGN = 37;
    const int SHIFTLEFTASSIGN = 38;
    const int ANDASSIGN = 39;
    const int XORASSIGN = 40;
    const int ORASSIGN = 41;
    const int QUEST = 42;
    const int COLON = 43;
    const int OROR = 44;
    const int AMPAMP = 45;
    const int OR = 46;
    const int XOR = 47;
    const int AMP = 48;
    const int EQ = 49;
    const int NEQ = 50;
    const int LEQ = 51;
    const int GEQ = 52;
    const int SPACESHIP = 53;
    const int LANGLE = 54;
    const int RANGLE = 55;
    const int SHIFTLEFT = 56;
    const int SHIFTRIGHT = 57;
    const int PLUS = 58;
    const int MINUS = 59;
    const int STAR = 60;
    const int DIV = 61;
    const int MOD = 62;
    const int DOTSTAR = 63;
    const int ARROWSTAR = 64;
    const int LPAREN = 65;
    const int RPAREN = 66;
    const int PLUSPLUS = 67;
    const int MINUSMINUS = 68;
    const int EXCLAMATION = 69;
    const int TILDE = 70;
    const int LBRACKET = 71;
    const int RBRACKET = 72;
    const int LBRACE = 73;
    const int RBRACE = 74;
    const int DOT = 75;
    const int ARROW = 76;
    const int SEMICOLON = 77;
    const int ELLIPSIS = 78;
    const int OTHER = 79;
    const int MAX = 80;

    PP_API void InitTokenIdMap();
    PP_API int GetTokenId(const std::u32string& tokenName);
    PP_API const char* GetTokenName(int tokenId);
    PP_API const char* GetTokenInfo(int tokenId);
}
#endif
