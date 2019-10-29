
// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/lexer/CppTokenLexer.lexer' using soulng lexer generator slg version 1.2.0

#include <sngcpp/lexer/CppTokenLexer.hpp>
#include <sngcpp/lexer/CppTokenLexerKeywords.hpp>
#include <soulng/lexer/Token.hpp>
#include <sngcpp/lexer/CppTokenLexerTokens.hpp>
#include <sngcpp/lexer/CppTokenLexerClassMap.hpp>

using namespace soulng::lexer;
using namespace CppTokenLexerTokens;

CppTokenLexer::CppTokenLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_) : soulng::lexer::Lexer(content_, fileName_, fileIndex_),
    writer()
{
    SetKeywordMap(CppTokenLexerKeywords::GetKeywordMap());
}

CppTokenLexer::CppTokenLexer(const char32_t* start_, const char32_t* end_, const std::string& fileName_, int fileIndex_) : soulng::lexer::Lexer(start_, end_, fileName_, fileIndex_),
    writer()
{
    SetKeywordMap(CppTokenLexerKeywords::GetKeywordMap());
}

int CppTokenLexer::NextState(int state, char32_t c)
{
    int i = CppTokenLexerClassMap::GetClass(c);
    switch (state)
    {
        case 0:
        {
            switch (i)
            {
                case 0:
                {
                    return 1;
                }
                case 1:
                {
                    return 2;
                }
                case 2:
                {
                    return 3;
                }
                case 3:
                {
                    return 4;
                }
                case 4:
                {
                    return 5;
                }
                case 5:
                case 14:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 6;
                }
                case 9:
                {
                    return 7;
                }
                case 10:
                {
                    return 8;
                }
                case 11:
                {
                    return 9;
                }
                case 12:
                {
                    return 10;
                }
                case 13:
                {
                    return 11;
                }
                case 15:
                {
                    return 12;
                }
                case 16:
                {
                    return 13;
                }
                case 17:
                {
                    return 14;
                }
                case 23:
                {
                    return 15;
                }
                case 25:
                case 26:
                case 27:
                {
                    return 16;
                }
                case 34:
                case 35:
                {
                    return 17;
                }
                case 36:
                {
                    return 18;
                }
                case 37:
                {
                    return 19;
                }
                case 38:
                {
                    return 20;
                }
                case 39:
                {
                    return 21;
                }
                case 40:
                {
                    return 22;
                }
                case 41:
                {
                    return 23;
                }
                case 42:
                {
                    return 24;
                }
                case 43:
                {
                    return 25;
                }
                case 44:
                {
                    return 26;
                }
                case 45:
                {
                    return 27;
                }
                case 46:
                {
                    return 28;
                }
                case 47:
                {
                    return 29;
                }
                case 48:
                {
                    return 30;
                }
                case 49:
                {
                    return 31;
                }
                case 50:
                {
                    return 32;
                }
                case 51:
                {
                    return 33;
                }
                case 52:
                {
                    return 34;
                }
                case 53:
                {
                    return 35;
                }
                case 54:
                {
                    return 36;
                }
                case 55:
                {
                    return 37;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 37:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(58);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 36:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(57);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 35:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(55);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 34:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(52);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 33:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(51);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 32:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(50);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 31:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(46);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 30:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(45);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 29:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(49);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 40:
                {
                    return 38;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 38:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(30);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 28:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(26);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 40:
                {
                    return 39;
                }
                case 46:
                {
                    return 40;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 40:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(24);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 39:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(21);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 27:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(27);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 40:
                {
                    return 41;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 41:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(20);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 26:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(28);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 40:
                {
                    return 42;
                }
                case 44:
                {
                    return 43;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 43:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(25);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 42:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(19);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 25:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(34);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 40:
                {
                    return 44;
                }
                case 43:
                {
                    return 45;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 45:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(36);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 40:
                {
                    return 46;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 46:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(18);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 44:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(31);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 42:
                {
                    return 47;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 47:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(33);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 24:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(35);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 40:
                {
                    return 48;
                }
                case 42:
                {
                    return 49;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 49:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(37);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 40:
                {
                    return 50;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 50:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(17);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 48:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(32);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 23:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(42);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 40:
                {
                    return 51;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 51:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(14);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 22:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(11);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 40:
                {
                    return 52;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 52:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(29);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 21:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(10);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 20:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(23);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 38:
                {
                    return 53;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 53:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(9);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 19:
        {
            switch (i)
            {
                case 0:
                {
                    return 1;
                }
                case 1:
                {
                    return 2;
                }
                case 2:
                {
                    return 3;
                }
                case 3:
                {
                    return 4;
                }
                case 4:
                {
                    return 5;
                }
                case 5:
                case 14:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 6;
                }
                case 9:
                {
                    return 7;
                }
                case 10:
                {
                    return 8;
                }
                case 11:
                {
                    return 9;
                }
                case 12:
                {
                    return 10;
                }
                case 13:
                {
                    return 11;
                }
                case 15:
                {
                    return 12;
                }
                case 16:
                {
                    return 13;
                }
                case 17:
                {
                    return 14;
                }
                case 23:
                {
                    return 15;
                }
                case 25:
                case 26:
                case 27:
                {
                    return 16;
                }
                case 34:
                case 35:
                {
                    return 17;
                }
                case 36:
                {
                    return 18;
                }
                case 38:
                {
                    return 20;
                }
                case 39:
                {
                    return 21;
                }
                case 40:
                {
                    return 22;
                }
                case 41:
                {
                    return 23;
                }
                case 42:
                {
                    return 24;
                }
                case 43:
                {
                    return 25;
                }
                case 44:
                {
                    return 26;
                }
                case 45:
                {
                    return 27;
                }
                case 46:
                {
                    return 28;
                }
                case 47:
                {
                    return 29;
                }
                case 48:
                {
                    return 30;
                }
                case 49:
                {
                    return 31;
                }
                case 50:
                {
                    return 32;
                }
                case 51:
                {
                    return 33;
                }
                case 52:
                {
                    return 34;
                }
                case 53:
                {
                    return 35;
                }
                case 54:
                {
                    return 36;
                }
                case 55:
                {
                    return 37;
                }
                case 37:
                {
                    return 54;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 54:
        {
            switch (i)
            {
                case 0:
                {
                    return 1;
                }
                case 1:
                {
                    return 2;
                }
                case 2:
                {
                    return 3;
                }
                case 9:
                {
                    return 7;
                }
                case 25:
                case 26:
                case 27:
                {
                    return 16;
                }
                case 34:
                case 35:
                {
                    return 17;
                }
                case 36:
                {
                    return 18;
                }
                case 11:
                {
                    return 55;
                }
                case 15:
                {
                    return 56;
                }
                case 16:
                {
                    return 57;
                }
                case 17:
                {
                    return 58;
                }
                case 23:
                {
                    return 59;
                }
                case 37:
                {
                    return 60;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 60:
        {
            switch (i)
            {
                case 1:
                {
                    return 2;
                }
                case 2:
                {
                    return 3;
                }
                case 25:
                case 26:
                case 27:
                {
                    return 16;
                }
                case 15:
                {
                    return 56;
                }
                case 16:
                {
                    return 57;
                }
                case 17:
                {
                    return 58;
                }
                case 23:
                {
                    return 59;
                }
                case 0:
                {
                    return 61;
                }
                case 34:
                case 35:
                {
                    return 62;
                }
                case 37:
                {
                    return 63;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 63:
        {
            switch (i)
            {
                case 15:
                {
                    return 56;
                }
                case 16:
                {
                    return 57;
                }
                case 37:
                {
                    return 64;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 64:
        {
            switch (i)
            {
                case 15:
                {
                    return 56;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 62:
        {
            switch (i)
            {
                case 36:
                {
                    return 18;
                }
                case 34:
                case 35:
                {
                    return 62;
                }
                case 37:
                {
                    return 65;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 65:
        {
            switch (i)
            {
                case 36:
                {
                    return 18;
                }
                case 34:
                case 35:
                {
                    return 62;
                }
                case 37:
                {
                    return 66;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 66:
        {
            switch (i)
            {
                case 36:
                {
                    return 18;
                }
                case 34:
                case 35:
                {
                    return 62;
                }
                case 37:
                {
                    return 67;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 67:
        {
            switch (i)
            {
                case 34:
                case 35:
                {
                    return 62;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 61:
        {
            switch (i)
            {
                case 1:
                {
                    return 68;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 68:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(1);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 37:
                {
                    return 69;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 69:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(1);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 37:
                {
                    return 70;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 70:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(1);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 59:
        {
            switch (i)
            {
                case 2:
                {
                    return 71;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 71:
        {
            switch (i)
            {
                case 2:
                {
                    return 72;
                }
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 73;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 73:
        {
            switch (i)
            {
                case 2:
                {
                    return 72;
                }
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 73;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 72:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(6);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 37:
                {
                    return 74;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 74:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(6);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 58:
        {
            switch (i)
            {
                case 2:
                {
                    return 3;
                }
                case 23:
                {
                    return 59;
                }
                case 37:
                {
                    return 75;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 75:
        {
            switch (i)
            {
                case 2:
                {
                    return 3;
                }
                case 23:
                {
                    return 59;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 57:
        {
            switch (i)
            {
                case 2:
                {
                    return 3;
                }
                case 23:
                {
                    return 59;
                }
                case 37:
                {
                    return 76;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 76:
        {
            switch (i)
            {
                case 2:
                {
                    return 3;
                }
                case 23:
                {
                    return 59;
                }
                case 37:
                {
                    return 75;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 56:
        {
            switch (i)
            {
                case 2:
                {
                    return 3;
                }
                case 23:
                {
                    return 59;
                }
                case 26:
                {
                    return 77;
                }
                case 37:
                {
                    return 78;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 78:
        {
            switch (i)
            {
                case 2:
                {
                    return 3;
                }
                case 23:
                {
                    return 59;
                }
                case 37:
                {
                    return 76;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 77:
        {
            switch (i)
            {
                case 2:
                {
                    return 3;
                }
                case 23:
                {
                    return 59;
                }
                case 37:
                {
                    return 78;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 55:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                {
                    return 79;
                }
                case 37:
                {
                    return 80;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 80:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                {
                    return 79;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 79:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(7);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                {
                    return 79;
                }
                case 8:
                {
                    return 81;
                }
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                {
                    return 82;
                }
                case 32:
                case 33:
                {
                    return 83;
                }
                case 37:
                {
                    return 84;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 84:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(7);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                {
                    return 79;
                }
                case 8:
                {
                    return 81;
                }
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                {
                    return 82;
                }
                case 32:
                case 33:
                {
                    return 83;
                }
                case 37:
                {
                    return 85;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 85:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(7);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 8:
                {
                    return 81;
                }
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                {
                    return 82;
                }
                case 32:
                case 33:
                {
                    return 83;
                }
                case 37:
                {
                    return 86;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 86:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(7);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 8:
                {
                    return 81;
                }
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                {
                    return 82;
                }
                case 32:
                case 33:
                {
                    return 83;
                }
                case 37:
                {
                    return 87;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 87:
        {
            switch (i)
            {
                case 8:
                {
                    return 81;
                }
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                {
                    return 82;
                }
                case 32:
                case 33:
                {
                    return 83;
                }
                case 37:
                {
                    return 88;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 88:
        {
            switch (i)
            {
                case 8:
                {
                    return 81;
                }
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 82;
                }
                case 37:
                {
                    return 89;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 89:
        {
            switch (i)
            {
                case 8:
                {
                    return 81;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 83:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(7);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 8:
                {
                    return 81;
                }
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                {
                    return 82;
                }
                case 32:
                case 33:
                {
                    return 83;
                }
                case 12:
                {
                    return 90;
                }
                case 13:
                {
                    return 91;
                }
                case 37:
                {
                    return 92;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 92:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(7);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 8:
                {
                    return 81;
                }
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                {
                    return 82;
                }
                case 32:
                case 33:
                {
                    return 83;
                }
                case 12:
                {
                    return 90;
                }
                case 13:
                {
                    return 91;
                }
                case 37:
                {
                    return 93;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 93:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(7);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 8:
                {
                    return 81;
                }
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                {
                    return 82;
                }
                case 32:
                case 33:
                {
                    return 83;
                }
                case 37:
                {
                    return 86;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 91:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(7);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 8:
                {
                    return 81;
                }
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                {
                    return 82;
                }
                case 32:
                case 33:
                {
                    return 83;
                }
                case 37:
                {
                    return 94;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 94:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(7);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 8:
                {
                    return 81;
                }
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                {
                    return 82;
                }
                case 32:
                case 33:
                {
                    return 83;
                }
                case 37:
                {
                    return 93;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 90:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(7);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 8:
                {
                    return 81;
                }
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                {
                    return 82;
                }
                case 32:
                case 33:
                {
                    return 83;
                }
                case 37:
                {
                    return 94;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 82:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(7);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 8:
                {
                    return 81;
                }
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                {
                    return 82;
                }
                case 32:
                case 33:
                {
                    return 83;
                }
                case 37:
                {
                    return 95;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 95:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(7);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 8:
                {
                    return 81;
                }
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                {
                    return 82;
                }
                case 32:
                case 33:
                {
                    return 83;
                }
                case 37:
                {
                    return 93;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 81:
        {
            switch (i)
            {
                case 15:
                {
                    return 96;
                }
                case 16:
                {
                    return 97;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 97:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 98;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 98:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 99;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 99:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 100;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 100:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 101;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 101:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 102;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 102:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 103;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 103:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 104;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 104:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 105;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 105:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(7);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 8:
                {
                    return 81;
                }
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                {
                    return 82;
                }
                case 32:
                case 33:
                {
                    return 83;
                }
                case 37:
                {
                    return 106;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 106:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(7);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 8:
                {
                    return 81;
                }
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                {
                    return 82;
                }
                case 32:
                case 33:
                {
                    return 83;
                }
                case 37:
                {
                    return 95;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 96:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 107;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 107:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 108;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 108:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 109;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 109:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 110;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 110:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(7);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 8:
                {
                    return 81;
                }
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                {
                    return 82;
                }
                case 32:
                case 33:
                {
                    return 83;
                }
                case 37:
                {
                    return 106;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 18:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(8);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 111;
                }
                case 37:
                {
                    return 112;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 112:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(8);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 111;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 111:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(8);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 111;
                }
                case 37:
                {
                    return 112;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 17:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(0);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 34:
                case 35:
                {
                    return 17;
                }
                case 36:
                {
                    return 18;
                }
                case 37:
                {
                    return 113;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 113:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(0);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 34:
                case 35:
                {
                    return 17;
                }
                case 36:
                {
                    return 18;
                }
                case 37:
                {
                    return 66;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 16:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(7);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                {
                    return 16;
                }
                case 8:
                {
                    return 81;
                }
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                {
                    return 82;
                }
                case 32:
                case 33:
                {
                    return 83;
                }
                case 11:
                {
                    return 114;
                }
                case 37:
                {
                    return 115;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 115:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(7);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                {
                    return 16;
                }
                case 8:
                {
                    return 81;
                }
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                {
                    return 82;
                }
                case 32:
                case 33:
                {
                    return 83;
                }
                case 11:
                case 37:
                {
                    return 114;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 114:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(7);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 8:
                {
                    return 81;
                }
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 28:
                case 29:
                case 30:
                case 31:
                {
                    return 82;
                }
                case 32:
                case 33:
                {
                    return 83;
                }
                case 37:
                {
                    return 85;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 15:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(4);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 2:
                {
                    return 71;
                }
                case 5:
                case 6:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 116;
                }
                case 37:
                {
                    return 117;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 117:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(4);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 5:
                case 6:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 116;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 116:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(4);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 5:
                case 6:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 116;
                }
                case 37:
                {
                    return 117;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 14:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(4);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 2:
                {
                    return 3;
                }
                case 9:
                {
                    return 7;
                }
                case 5:
                case 6:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 116;
                }
                case 23:
                {
                    return 118;
                }
                case 37:
                {
                    return 119;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 119:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(4);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 2:
                {
                    return 3;
                }
                case 5:
                case 6:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 116;
                }
                case 23:
                {
                    return 118;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 118:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(4);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 2:
                {
                    return 71;
                }
                case 5:
                case 6:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 116;
                }
                case 37:
                {
                    return 117;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 13:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(4);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 2:
                {
                    return 3;
                }
                case 9:
                {
                    return 7;
                }
                case 5:
                case 6:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 116;
                }
                case 23:
                {
                    return 118;
                }
                case 37:
                {
                    return 120;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 120:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(4);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 2:
                {
                    return 3;
                }
                case 37:
                {
                    return 75;
                }
                case 5:
                case 6:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 116;
                }
                case 23:
                {
                    return 118;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 12:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(4);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 2:
                {
                    return 3;
                }
                case 9:
                {
                    return 7;
                }
                case 5:
                case 6:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 24:
                case 25:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 116;
                }
                case 23:
                {
                    return 118;
                }
                case 26:
                {
                    return 121;
                }
                case 37:
                {
                    return 122;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 122:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(4);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 2:
                {
                    return 3;
                }
                case 37:
                {
                    return 76;
                }
                case 5:
                case 6:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 116;
                }
                case 23:
                {
                    return 118;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 121:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(4);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 2:
                {
                    return 3;
                }
                case 5:
                case 6:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 116;
                }
                case 23:
                {
                    return 118;
                }
                case 37:
                {
                    return 122;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 11:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(39);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 13:
                {
                    return 123;
                }
                case 40:
                {
                    return 124;
                }
                case 42:
                {
                    return 125;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 125:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(54);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 4:
                {
                    return 126;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 126:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(44);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 124:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(16);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 123:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(48);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 10:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(38);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 12:
                {
                    return 127;
                }
                case 40:
                {
                    return 128;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 128:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(15);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 127:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(47);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 9:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(53);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                {
                    return 79;
                }
                case 37:
                {
                    return 80;
                }
                case 4:
                {
                    return 129;
                }
                case 11:
                {
                    return 130;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 130:
        {
            switch (i)
            {
                case 11:
                {
                    return 131;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 131:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(56);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 129:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(43);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 8:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(22);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 7:
        {
            switch (i)
            {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 132;
                }
                case 8:
                {
                    return 133;
                }
                case 9:
                {
                    return 134;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 134:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(5);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 133:
        {
            switch (i)
            {
                case 2:
                case 8:
                case 9:
                case 10:
                case 19:
                case 20:
                case 21:
                case 22:
                case 29:
                case 30:
                case 31:
                {
                    return 135;
                }
                case 15:
                {
                    return 136;
                }
                case 16:
                {
                    return 137;
                }
                case 18:
                {
                    return 138;
                }
                case 27:
                {
                    return 139;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 139:
        {
            switch (i)
            {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 132;
                }
                case 8:
                {
                    return 133;
                }
                case 9:
                {
                    return 134;
                }
                case 27:
                {
                    return 140;
                }
                case 37:
                {
                    return 141;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 141:
        {
            switch (i)
            {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 132;
                }
                case 8:
                {
                    return 133;
                }
                case 9:
                {
                    return 134;
                }
                case 37:
                {
                    return 142;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 142:
        {
            switch (i)
            {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 132;
                }
                case 8:
                {
                    return 133;
                }
                case 9:
                {
                    return 134;
                }
                case 37:
                {
                    return 143;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 143:
        {
            switch (i)
            {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 132;
                }
                case 8:
                {
                    return 133;
                }
                case 9:
                {
                    return 134;
                }
                case 37:
                {
                    return 144;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 144:
        {
            switch (i)
            {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 132;
                }
                case 8:
                {
                    return 133;
                }
                case 9:
                {
                    return 134;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 140:
        {
            switch (i)
            {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 132;
                }
                case 8:
                {
                    return 133;
                }
                case 9:
                {
                    return 134;
                }
                case 37:
                {
                    return 141;
                }
                case 27:
                {
                    return 145;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 145:
        {
            switch (i)
            {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 132;
                }
                case 8:
                {
                    return 133;
                }
                case 9:
                {
                    return 134;
                }
                case 37:
                {
                    return 142;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 138:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 146;
                }
                case 37:
                {
                    return 147;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 147:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 146;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 146:
        {
            switch (i)
            {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 132;
                }
                case 8:
                {
                    return 133;
                }
                case 9:
                {
                    return 134;
                }
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 146;
                }
                case 37:
                {
                    return 148;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 148:
        {
            switch (i)
            {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 132;
                }
                case 8:
                {
                    return 133;
                }
                case 9:
                {
                    return 134;
                }
                case 37:
                {
                    return 144;
                }
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 146;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 137:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 149;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 149:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 150;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 150:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 151;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 151:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 152;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 152:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 153;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 153:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 154;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 154:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 155;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 155:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 156;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 156:
        {
            switch (i)
            {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 132;
                }
                case 8:
                {
                    return 133;
                }
                case 9:
                {
                    return 134;
                }
                case 37:
                {
                    return 157;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 157:
        {
            switch (i)
            {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 132;
                }
                case 8:
                {
                    return 133;
                }
                case 9:
                {
                    return 134;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 136:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 158;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 158:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 159;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 159:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 160;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 160:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 161;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 161:
        {
            switch (i)
            {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 132;
                }
                case 8:
                {
                    return 133;
                }
                case 9:
                {
                    return 134;
                }
                case 37:
                {
                    return 157;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 135:
        {
            switch (i)
            {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 132;
                }
                case 8:
                {
                    return 133;
                }
                case 9:
                {
                    return 134;
                }
                case 37:
                {
                    return 143;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 132:
        {
            switch (i)
            {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 132;
                }
                case 8:
                {
                    return 133;
                }
                case 9:
                {
                    return 134;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 6:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(4);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 5:
                case 6:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 116;
                }
                case 37:
                {
                    return 117;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 5:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(40);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 40:
                {
                    return 162;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 162:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(12);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 4:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(41);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 3:
                {
                    return 163;
                }
                case 4:
                {
                    return 164;
                }
                case 40:
                {
                    return 165;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 165:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(13);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 164:
        {
            switch (i)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 166;
                }
                case 4:
                {
                    return 167;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 167:
        {
            switch (i)
            {
                case 4:
                {
                    return 167;
                }
                case 0:
                case 1:
                case 2:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 168;
                }
                case 3:
                {
                    return 169;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 169:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(3);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 166;
                }
                case 4:
                {
                    return 167;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 168:
        {
            switch (i)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 166;
                }
                case 4:
                {
                    return 167;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 166:
        {
            switch (i)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 166;
                }
                case 4:
                {
                    return 167;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 163:
        {
            switch (i)
            {
                case 0:
                {
                    return 170;
                }
                case 1:
                {
                    return 171;
                }
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 172;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 172:
        {
            switch (i)
            {
                case 0:
                {
                    return 170;
                }
                case 1:
                {
                    return 171;
                }
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 172;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 171:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(2);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 37:
                {
                    return 173;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 173:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(2);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 37:
                {
                    return 174;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 174:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(2);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            return -1;
        }
        case 170:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(2);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 37:
                {
                    return 174;
                }
                case 1:
                {
                    return 175;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 175:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(2);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 37:
                {
                    return 173;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 3:
        {
            switch (i)
            {
                case 2:
                {
                    return 176;
                }
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 177;
                }
                case 8:
                {
                    return 178;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 178:
        {
            switch (i)
            {
                case 2:
                case 8:
                case 9:
                case 10:
                case 19:
                case 20:
                case 21:
                case 22:
                case 29:
                case 30:
                case 31:
                {
                    return 179;
                }
                case 15:
                {
                    return 180;
                }
                case 16:
                {
                    return 181;
                }
                case 18:
                {
                    return 182;
                }
                case 27:
                {
                    return 183;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 183:
        {
            switch (i)
            {
                case 2:
                {
                    return 176;
                }
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 177;
                }
                case 8:
                {
                    return 178;
                }
                case 27:
                {
                    return 184;
                }
                case 37:
                {
                    return 185;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 185:
        {
            switch (i)
            {
                case 2:
                {
                    return 176;
                }
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 177;
                }
                case 8:
                {
                    return 178;
                }
                case 37:
                {
                    return 186;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 186:
        {
            switch (i)
            {
                case 2:
                {
                    return 176;
                }
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 177;
                }
                case 8:
                {
                    return 178;
                }
                case 37:
                {
                    return 187;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 187:
        {
            switch (i)
            {
                case 2:
                {
                    return 176;
                }
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 177;
                }
                case 8:
                {
                    return 178;
                }
                case 37:
                {
                    return 188;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 188:
        {
            switch (i)
            {
                case 2:
                {
                    return 176;
                }
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 177;
                }
                case 8:
                {
                    return 178;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 184:
        {
            switch (i)
            {
                case 2:
                {
                    return 176;
                }
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 177;
                }
                case 8:
                {
                    return 178;
                }
                case 37:
                {
                    return 185;
                }
                case 27:
                {
                    return 189;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 189:
        {
            switch (i)
            {
                case 2:
                {
                    return 176;
                }
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 177;
                }
                case 8:
                {
                    return 178;
                }
                case 37:
                {
                    return 186;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 182:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 190;
                }
                case 37:
                {
                    return 191;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 191:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 190;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 190:
        {
            switch (i)
            {
                case 2:
                {
                    return 176;
                }
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 177;
                }
                case 8:
                {
                    return 178;
                }
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 190;
                }
                case 37:
                {
                    return 192;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 192:
        {
            switch (i)
            {
                case 2:
                {
                    return 176;
                }
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 177;
                }
                case 8:
                {
                    return 178;
                }
                case 37:
                {
                    return 188;
                }
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 190;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 181:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 193;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 193:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 194;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 194:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 195;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 195:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 196;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 196:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 197;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 197:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 198;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 198:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 199;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 199:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 200;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 200:
        {
            switch (i)
            {
                case 2:
                {
                    return 176;
                }
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 177;
                }
                case 8:
                {
                    return 178;
                }
                case 37:
                {
                    return 201;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 201:
        {
            switch (i)
            {
                case 2:
                {
                    return 176;
                }
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 177;
                }
                case 8:
                {
                    return 178;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 180:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 202;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 202:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 203;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 203:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 204;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 204:
        {
            switch (i)
            {
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                {
                    return 205;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 205:
        {
            switch (i)
            {
                case 2:
                {
                    return 176;
                }
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 177;
                }
                case 8:
                {
                    return 178;
                }
                case 37:
                {
                    return 201;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 179:
        {
            switch (i)
            {
                case 2:
                {
                    return 176;
                }
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 177;
                }
                case 8:
                {
                    return 178;
                }
                case 37:
                {
                    return 187;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 177:
        {
            switch (i)
            {
                case 2:
                {
                    return 176;
                }
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                {
                    return 177;
                }
                case 8:
                {
                    return 178;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 176:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(6);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 37:
                {
                    return 74;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 2:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(1);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 37:
                {
                    return 69;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 1:
        {
            Lexeme prevMatch = token.match;
            token.match = lexeme;
            int tokenId = GetTokenId(1);
            if (tokenId == CONTINUE_TOKEN)
            {
                token.id = tokenId;
                return -1;
            }
            else if (tokenId != INVALID_TOKEN)
            {
                token.id = tokenId;
            }
            else
            {
                token.match = prevMatch;
            }
            switch (i)
            {
                case 1:
                {
                    return 68;
                }
                case 37:
                {
                    return 70;
                }
                default:
                {
                    return -1;
                }
            }
        }
    }
    return -1;
}

int CppTokenLexer::GetTokenId(int statementIndex)
{
    switch (statementIndex)
    {
        case 0:
        {
            Retract();
            return WS;
            break;
        }
        case 1:
        {
            Retract();
            break;
        }
        case 2:
        {
            Retract();
            return LINECOMMENT;
            break;
        }
        case 3:
        {
            Retract();
            return BLOCKCOMMENT;
            break;
        }
        case 4:
        {
            Retract();
            if (GetKeywordToken(token.match) != INVALID_TOKEN) return KEYWORD;
            else return ID;
            break;
        }
        case 5:
        {
            Retract();
            return CHARLIT;
            break;
        }
        case 6:
        {
            Retract();
            return STRINGLIT;
            break;
        }
        case 7:
        {
            Retract();
            return NUMBER;
            break;
        }
        case 8:
        {
            Retract();
            return PP;
            break;
        }
        case 9:
        {
            Retract();
            return OTHER;
            break;
        }
        case 10:
        {
            Retract();
            return OTHER;
            break;
        }
        case 11:
        {
            Retract();
            return OTHER;
            break;
        }
        case 12:
        {
            Retract();
            return OTHER;
            break;
        }
        case 13:
        {
            Retract();
            return OTHER;
            break;
        }
        case 14:
        {
            Retract();
            return OTHER;
            break;
        }
        case 15:
        {
            Retract();
            return OTHER;
            break;
        }
        case 16:
        {
            Retract();
            return OTHER;
            break;
        }
        case 17:
        {
            Retract();
            return OTHER;
            break;
        }
        case 18:
        {
            Retract();
            return OTHER;
            break;
        }
        case 19:
        {
            Retract();
            return OTHER;
            break;
        }
        case 20:
        {
            Retract();
            return OTHER;
            break;
        }
        case 21:
        {
            Retract();
            return OTHER;
            break;
        }
        case 22:
        {
            Retract();
            return OTHER;
            break;
        }
        case 23:
        {
            Retract();
            return OTHER;
            break;
        }
        case 24:
        {
            Retract();
            return OTHER;
            break;
        }
        case 25:
        {
            Retract();
            return OTHER;
            break;
        }
        case 26:
        {
            Retract();
            return OTHER;
            break;
        }
        case 27:
        {
            Retract();
            return OTHER;
            break;
        }
        case 28:
        {
            Retract();
            return OTHER;
            break;
        }
        case 29:
        {
            Retract();
            return OTHER;
            break;
        }
        case 30:
        {
            Retract();
            return OTHER;
            break;
        }
        case 31:
        {
            Retract();
            return OTHER;
            break;
        }
        case 32:
        {
            Retract();
            return OTHER;
            break;
        }
        case 33:
        {
            Retract();
            return OTHER;
            break;
        }
        case 34:
        {
            Retract();
            return OTHER;
            break;
        }
        case 35:
        {
            Retract();
            return OTHER;
            break;
        }
        case 36:
        {
            Retract();
            return OTHER;
            break;
        }
        case 37:
        {
            Retract();
            return OTHER;
            break;
        }
        case 38:
        {
            Retract();
            return OTHER;
            break;
        }
        case 39:
        {
            Retract();
            return OTHER;
            break;
        }
        case 40:
        {
            Retract();
            return OTHER;
            break;
        }
        case 41:
        {
            Retract();
            return OTHER;
            break;
        }
        case 42:
        {
            Retract();
            return OTHER;
            break;
        }
        case 43:
        {
            Retract();
            return OTHER;
            break;
        }
        case 44:
        {
            Retract();
            return OTHER;
            break;
        }
        case 45:
        {
            Retract();
            return OTHER;
            break;
        }
        case 46:
        {
            Retract();
            return OTHER;
            break;
        }
        case 47:
        {
            Retract();
            return OTHER;
            break;
        }
        case 48:
        {
            Retract();
            return OTHER;
            break;
        }
        case 49:
        {
            Retract();
            return OTHER;
            break;
        }
        case 50:
        {
            Retract();
            return OTHER;
            break;
        }
        case 51:
        {
            Retract();
            return OTHER;
            break;
        }
        case 52:
        {
            Retract();
            return OTHER;
            break;
        }
        case 53:
        {
            Retract();
            return OTHER;
            break;
        }
        case 54:
        {
            Retract();
            return OTHER;
            break;
        }
        case 55:
        {
            Retract();
            return OTHER;
            break;
        }
        case 56:
        {
            Retract();
            return OTHER;
            break;
        }
        case 57:
        {
            Retract();
            return OTHER;
            break;
        }
        case 58:
        {
            Retract();
            return OTHER;
            break;
        }
    }
    return CONTINUE_TOKEN;
}
