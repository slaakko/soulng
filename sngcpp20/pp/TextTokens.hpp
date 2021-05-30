#ifndef TextTokens_HPP
#define TextTokens_HPP

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/pp/TextLexer.lexer' using soulng lexer generator slg version 4.0.0

#include <sngcpp20/pp/PP.hpp>
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
    const int BEGINRAWSTRINGLITERAL = 7;
    const int CHAR = 8;
    const int ID = 9;
    const int KEYWORD = 10;
    const int COLONCOLON = 11;
    const int COMMA = 12;
    const int ASSIGN = 13;
    const int MULASSIGN = 14;
    const int DIVASSIGN = 15;
    const int REMASSIGN = 16;
    const int ADDASSIGN = 17;
    const int SUBASSIGN = 18;
    const int SHIFTRIGHTASSIGN = 19;
    const int SHIFTLEFTASSIGN = 20;
    const int ANDASSIGN = 21;
    const int XORASSIGN = 22;
    const int ORASSIGN = 23;
    const int QUEST = 24;
    const int COLON = 25;
    const int OROR = 26;
    const int AMPAMP = 27;
    const int OR = 28;
    const int XOR = 29;
    const int AMP = 30;
    const int EQ = 31;
    const int NEQ = 32;
    const int LEQ = 33;
    const int GEQ = 34;
    const int SPACESHIP = 35;
    const int LANGLE = 36;
    const int RANGLE = 37;
    const int SHIFTLEFT = 38;
    const int SHIFTRIGHT = 39;
    const int PLUS = 40;
    const int MINUS = 41;
    const int STAR = 42;
    const int DIV = 43;
    const int MOD = 44;
    const int DOTSTAR = 45;
    const int ARROWSTAR = 46;
    const int LPAREN = 47;
    const int RPAREN = 48;
    const int PLUSPLUS = 49;
    const int MINUSMINUS = 50;
    const int EXCLAMATION = 51;
    const int TILDE = 52;
    const int LBRACKET = 53;
    const int RBRACKET = 54;
    const int LBRACE = 55;
    const int RBRACE = 56;
    const int DOT = 57;
    const int ARROW = 58;
    const int SEMICOLON = 59;
    const int ELLIPSIS = 60;
    const int WS = 61;
    const int BEGINBLOCKCOMMENT = 62;
    const int BLOCKCOMMENT = 63;
    const int LINECOMMENT = 64;
    const int NEWLINE = 65;
    const int OTHER = 66;
    const int HASHHASH = 67;
    const int HASH = 68;
    const int PLACEMARKER = 69;
    const int MAX = 70;

    PP_API void InitTokenIdMap();
    PP_API int GetTokenId(const std::u32string& tokenName);
    PP_API const char* GetTokenName(int tokenId);
    PP_API const char* GetTokenInfo(int tokenId);
}
#endif
