#ifndef TextTokens_HPP
#define TextTokens_HPP

// this file has been automatically generated from 'C:/work/soulng/sngcpp/pp/TextLexer.lexer' using soulng lexer generator slg version 3.1.0

#include <sngcpp/pp/PP.hpp>
#include <string>

namespace TextTokens
{
    const int END = 0;
    const int DEFINED = 1;
    const int ANGLEHEADERNAME = 2;
    const int QUOTEHEADERNAME = 3;
    const int PPNUMBER = 4;
    const int CHARLITERAL = 5;
    const int STRINGLITERAL = 6;
    const int CHAR = 7;
    const int ID = 8;
    const int COLONCOLON = 9;
    const int COMMA = 10;
    const int ASSIGN = 11;
    const int MULASSIGN = 12;
    const int DIVASSIGN = 13;
    const int REMASSIGN = 14;
    const int ADDASSIGN = 15;
    const int SUBASSIGN = 16;
    const int SHIFTRIGHTASSIGN = 17;
    const int SHIFTLEFTASSIGN = 18;
    const int ANDASSIGN = 19;
    const int XORASSIGN = 20;
    const int ORASSIGN = 21;
    const int QUEST = 22;
    const int COLON = 23;
    const int OROR = 24;
    const int AMPAMP = 25;
    const int OR = 26;
    const int XOR = 27;
    const int AMP = 28;
    const int EQ = 29;
    const int NEQ = 30;
    const int LEQ = 31;
    const int GEQ = 32;
    const int SPACESHIP = 33;
    const int LANGLE = 34;
    const int RANGLE = 35;
    const int SHIFTLEFT = 36;
    const int SHIFTRIGHT = 37;
    const int PLUS = 38;
    const int MINUS = 39;
    const int STAR = 40;
    const int DIV = 41;
    const int MOD = 42;
    const int DOTSTAR = 43;
    const int ARROWSTAR = 44;
    const int LPAREN = 45;
    const int RPAREN = 46;
    const int PLUSPLUS = 47;
    const int MINUSMINUS = 48;
    const int EXCLAMATION = 49;
    const int TILDE = 50;
    const int LBRACKET = 51;
    const int RBRACKET = 52;
    const int LBRACE = 53;
    const int RBRACE = 54;
    const int DOT = 55;
    const int ARROW = 56;
    const int SEMICOLON = 57;
    const int ELLIPSIS = 58;
    const int KEYWORD = 59;
    const int WS = 60;
    const int BLOCKCOMMENT = 61;
    const int LINECOMMENT = 62;
    const int MAX = 63;

    SNGCPP_PP_API void InitTokenIdMap();
    SNGCPP_PP_API int GetTokenId(const std::u32string& tokenName);
    SNGCPP_PP_API const char* GetTokenName(int tokenId);
    SNGCPP_PP_API const char* GetTokenInfo(int tokenId);
}
#endif
