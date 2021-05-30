#ifndef PPTokens_HPP
#define PPTokens_HPP

// this file has been automatically generated from 'C:/work/soulng/sngcpp/pp/PPLexer.lexer' using soulng lexer generator slg version 3.10.0

#include <sngcpp/pp/PP.hpp>
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
    const int DEFINED = 10;
    const int ANGLEHEADERNAME = 11;
    const int QUOTEHEADERNAME = 12;
    const int PPNUMBER = 13;
    const int CHARLITERAL = 14;
    const int STRINGLITERAL = 15;
    const int HASH = 16;
    const int CHAR = 17;
    const int ID = 18;
    const int COLONCOLON = 19;
    const int COMMA = 20;
    const int ASSIGN = 21;
    const int MULASSIGN = 22;
    const int DIVASSIGN = 23;
    const int REMASSIGN = 24;
    const int ADDASSIGN = 25;
    const int SUBASSIGN = 26;
    const int SHIFTRIGHTASSIGN = 27;
    const int SHIFTLEFTASSIGN = 28;
    const int ANDASSIGN = 29;
    const int XORASSIGN = 30;
    const int ORASSIGN = 31;
    const int QUEST = 32;
    const int COLON = 33;
    const int OROR = 34;
    const int AMPAMP = 35;
    const int OR = 36;
    const int XOR = 37;
    const int AMP = 38;
    const int EQ = 39;
    const int NEQ = 40;
    const int LEQ = 41;
    const int GEQ = 42;
    const int SPACESHIP = 43;
    const int LANGLE = 44;
    const int RANGLE = 45;
    const int SHIFTLEFT = 46;
    const int SHIFTRIGHT = 47;
    const int PLUS = 48;
    const int MINUS = 49;
    const int STAR = 50;
    const int DIV = 51;
    const int MOD = 52;
    const int DOTSTAR = 53;
    const int ARROWSTAR = 54;
    const int LPAREN = 55;
    const int RPAREN = 56;
    const int PLUSPLUS = 57;
    const int MINUSMINUS = 58;
    const int EXCLAMATION = 59;
    const int TILDE = 60;
    const int LBRACKET = 61;
    const int RBRACKET = 62;
    const int LBRACE = 63;
    const int RBRACE = 64;
    const int DOT = 65;
    const int ARROW = 66;
    const int SEMICOLON = 67;
    const int ELLIPSIS = 68;
    const int MAX = 69;

    SNGCPP_PP_API void InitTokenIdMap();
    SNGCPP_PP_API int GetTokenId(const std::u32string& tokenName);
    SNGCPP_PP_API const char* GetTokenName(int tokenId);
    SNGCPP_PP_API const char* GetTokenInfo(int tokenId);
}
#endif
