
// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/pp/TextLexer.lexer' using soulng lexer generator slg version 3.0.0

#include <sngcpp/pp/TextLexer.hpp>
#include <soulng/lexer/Token.hpp>
#include <sngcpp/pp/TextTokens.hpp>
#include <sngcpp/pp/TextClassMap.hpp>

using namespace soulng::lexer;
using namespace TextTokens;

TextLexer::TextLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_) : soulng::lexer::Lexer(content_, fileName_, fileIndex_),
    pp()
{
}

TextLexer::TextLexer(const char32_t* start_, const char32_t* end_, const std::string& fileName_, int fileIndex_) : soulng::lexer::Lexer(start_, end_, fileName_, fileIndex_),
    pp()
{
}

int TextLexer::NextState(int state, char32_t c)
{
    int i = TextClassMap::GetClass(c);
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
                case 13:
                case 14:
                case 18:
                case 22:
                case 23:
                case 24:
                case 25:
                case 27:
                case 28:
                case 29:
                case 31:
                case 32:
                case 33:
                {
                    return 6;
                }
                case 7:
                case 8:
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
                case 15:
                {
                    return 11;
                }
                case 16:
                {
                    return 12;
                }
                case 17:
                {
                    return 13;
                }
                case 19:
                {
                    return 14;
                }
                case 20:
                {
                    return 15;
                }
                case 21:
                {
                    return 16;
                }
                case 26:
                case 30:
                case 34:
                {
                    return 17;
                }
                case 35:
                {
                    return 18;
                }
                case 36:
                {
                    return 19;
                }
                case 37:
                {
                    return 20;
                }
                case 38:
                {
                    return 21;
                }
                case 39:
                {
                    return 22;
                }
                case 40:
                {
                    return 23;
                }
                case 41:
                {
                    return 24;
                }
                case 42:
                {
                    return 25;
                }
                case 43:
                {
                    return 26;
                }
                case 44:
                {
                    return 27;
                }
                case 45:
                {
                    return 28;
                }
                case 46:
                {
                    return 29;
                }
                case 47:
                {
                    return 30;
                }
                case 48:
                {
                    return 31;
                }
                case 49:
                {
                    return 32;
                }
                case 50:
                {
                    return 33;
                }
                case 51:
                {
                    return 34;
                }
                case 52:
                {
                    return 35;
                }
                case 53:
                {
                    return 36;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 36:
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
        case 35:
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
        case 34:
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
        case 33:
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
        case 32:
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
        case 31:
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
        case 30:
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
        case 29:
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
        case 28:
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
                case 38:
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
        case 27:
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
                case 38:
                {
                    return 38;
                }
                case 44:
                {
                    return 39;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 39:
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
        case 38:
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
        case 26:
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
                case 38:
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
        case 25:
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
                case 38:
                {
                    return 41;
                }
                case 42:
                {
                    return 42;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 42:
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
        case 41:
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
        case 24:
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
                case 38:
                {
                    return 43;
                }
                case 41:
                {
                    return 44;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 44:
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
                case 38:
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
        case 43:
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
        case 23:
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
                case 38:
                {
                    return 47;
                }
                case 40:
                {
                    return 48;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 48:
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
                case 38:
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
        case 47:
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
        case 22:
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
                case 38:
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
        case 21:
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
                case 38:
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
        case 20:
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
        case 19:
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
                case 36:
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
        case 18:
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
            switch (i)
            {
                case 2:
                {
                    return 53;
                }
                case 5:
                case 6:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
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
            switch (i)
            {
                case 5:
                case 6:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
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
                {
                    return 54;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 53:
        {
            switch (i)
            {
                case 2:
                {
                    return 55;
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
                {
                    return 56;
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
                    return 55;
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
                {
                    return 56;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 55:
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
            return -1;
        }
        case 17:
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
                case 26:
                case 30:
                case 34:
                {
                    return 17;
                }
                case 10:
                {
                    return 57;
                }
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 22:
                case 23:
                case 24:
                case 25:
                case 27:
                case 31:
                case 32:
                case 33:
                case 35:
                {
                    return 58;
                }
                case 19:
                {
                    return 59;
                }
                case 28:
                case 29:
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
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 22:
                case 23:
                case 24:
                case 25:
                case 27:
                case 31:
                case 32:
                case 33:
                case 35:
                {
                    return 58;
                }
                case 19:
                {
                    return 59;
                }
                case 28:
                case 29:
                {
                    return 60;
                }
                case 11:
                {
                    return 61;
                }
                case 12:
                {
                    return 62;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 62:
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
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 22:
                case 23:
                case 24:
                case 25:
                case 27:
                case 31:
                case 32:
                case 33:
                case 35:
                {
                    return 58;
                }
                case 19:
                {
                    return 59;
                }
                case 28:
                case 29:
                {
                    return 60;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 61:
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
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 22:
                case 23:
                case 24:
                case 25:
                case 27:
                case 31:
                case 32:
                case 33:
                case 35:
                {
                    return 58;
                }
                case 19:
                {
                    return 59;
                }
                case 28:
                case 29:
                {
                    return 60;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 59:
        {
            switch (i)
            {
                case 15:
                {
                    return 63;
                }
                case 16:
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
            switch (i)
            {
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
            switch (i)
            {
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
            switch (i)
            {
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                {
                    return 72;
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
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 22:
                case 23:
                case 24:
                case 25:
                case 27:
                case 31:
                case 32:
                case 33:
                case 35:
                {
                    return 58;
                }
                case 19:
                {
                    return 59;
                }
                case 28:
                case 29:
                {
                    return 60;
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
            switch (i)
            {
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 22:
                case 23:
                case 24:
                case 25:
                case 27:
                case 31:
                case 32:
                case 33:
                case 35:
                {
                    return 58;
                }
                case 19:
                {
                    return 59;
                }
                case 28:
                case 29:
                {
                    return 60;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 58:
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
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 22:
                case 23:
                case 24:
                case 25:
                case 27:
                case 31:
                case 32:
                case 33:
                case 35:
                {
                    return 58;
                }
                case 19:
                {
                    return 59;
                }
                case 28:
                case 29:
                {
                    return 60;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 57:
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
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 22:
                case 23:
                case 24:
                case 25:
                case 27:
                case 31:
                case 32:
                case 33:
                case 35:
                {
                    return 58;
                }
                case 19:
                {
                    return 59;
                }
                case 28:
                case 29:
                {
                    return 60;
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
        case 15:
        {
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
                {
                    return 77;
                }
                case 19:
                {
                    return 78;
                }
                case 20:
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
            return -1;
        }
        case 78:
        {
            switch (i)
            {
                case 2:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 31:
                case 32:
                case 33:
                {
                    return 80;
                }
                case 15:
                {
                    return 81;
                }
                case 16:
                {
                    return 82;
                }
                case 18:
                {
                    return 83;
                }
                case 34:
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
                {
                    return 77;
                }
                case 19:
                {
                    return 78;
                }
                case 20:
                {
                    return 79;
                }
                case 34:
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
                {
                    return 77;
                }
                case 19:
                {
                    return 78;
                }
                case 20:
                {
                    return 79;
                }
                case 34:
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
                {
                    return 77;
                }
                case 19:
                {
                    return 78;
                }
                case 20:
                {
                    return 79;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 83:
        {
            switch (i)
            {
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
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
                {
                    return 77;
                }
                case 19:
                {
                    return 78;
                }
                case 20:
                {
                    return 79;
                }
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                {
                    return 87;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 82:
        {
            switch (i)
            {
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                {
                    return 90;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 90:
        {
            switch (i)
            {
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                {
                    return 91;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 91:
        {
            switch (i)
            {
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
            switch (i)
            {
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
            switch (i)
            {
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
            switch (i)
            {
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                {
                    return 77;
                }
                case 19:
                {
                    return 78;
                }
                case 20:
                {
                    return 79;
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                {
                    return 96;
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                {
                    return 77;
                }
                case 19:
                {
                    return 78;
                }
                case 20:
                {
                    return 79;
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
                {
                    return 77;
                }
                case 19:
                {
                    return 78;
                }
                case 20:
                {
                    return 79;
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
                {
                    return 77;
                }
                case 19:
                {
                    return 78;
                }
                case 20:
                {
                    return 79;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 14:
        {
            switch (i)
            {
                case 0:
                {
                    return 100;
                }
                case 1:
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
        case 100:
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
        case 13:
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
            switch (i)
            {
                case 2:
                {
                    return 3;
                }
                case 20:
                {
                    return 15;
                }
                case 5:
                case 6:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
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
                {
                    return 54;
                }
                case 35:
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
            switch (i)
            {
                case 2:
                {
                    return 53;
                }
                case 5:
                case 6:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
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
                {
                    return 54;
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
            switch (i)
            {
                case 2:
                {
                    return 3;
                }
                case 20:
                {
                    return 15;
                }
                case 5:
                case 6:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
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
                {
                    return 54;
                }
                case 35:
                {
                    return 103;
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
            switch (i)
            {
                case 2:
                {
                    return 3;
                }
                case 20:
                {
                    return 15;
                }
                case 5:
                case 6:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 31:
                case 32:
                case 33:
                case 34:
                {
                    return 54;
                }
                case 35:
                {
                    return 103;
                }
                case 30:
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
            switch (i)
            {
                case 2:
                {
                    return 3;
                }
                case 5:
                case 6:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
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
                {
                    return 54;
                }
                case 35:
                {
                    return 103;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 10:
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
                case 12:
                {
                    return 105;
                }
                case 38:
                {
                    return 106;
                }
                case 40:
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
        case 106:
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
        case 105:
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
        case 9:
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
                case 11:
                {
                    return 109;
                }
                case 38:
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
        case 109:
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
        case 8:
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
                case 4:
                {
                    return 111;
                }
                case 10:
                {
                    return 112;
                }
                case 26:
                case 30:
                case 34:
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
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 22:
                case 23:
                case 24:
                case 25:
                case 27:
                case 31:
                case 32:
                case 33:
                case 35:
                {
                    return 58;
                }
                case 19:
                {
                    return 59;
                }
                case 28:
                case 29:
                {
                    return 60;
                }
                case 26:
                case 30:
                case 34:
                {
                    return 113;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 112:
        {
            switch (i)
            {
                case 10:
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
        case 111:
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
        case 7:
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
                case 7:
                case 8:
                {
                    return 7;
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
            switch (i)
            {
                case 5:
                case 6:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
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
                {
                    return 54;
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
                case 38:
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
                    return 116;
                }
                case 4:
                {
                    return 117;
                }
                case 38:
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
        case 117:
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
                {
                    return 119;
                }
                case 4:
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
            switch (i)
            {
                case 4:
                {
                    return 120;
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
                {
                    return 121;
                }
                case 3:
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
                {
                    return 119;
                }
                case 4:
                {
                    return 120;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 121:
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
                {
                    return 119;
                }
                case 4:
                {
                    return 120;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 119:
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
                {
                    return 119;
                }
                case 4:
                {
                    return 120;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 116:
        {
            switch (i)
            {
                case 0:
                {
                    return 123;
                }
                case 1:
                {
                    return 124;
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
            switch (i)
            {
                case 0:
                {
                    return 123;
                }
                case 1:
                {
                    return 124;
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
                {
                    return 125;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 124:
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
            return -1;
        }
        case 123:
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
                case 1:
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
            return -1;
        }
        case 3:
        {
            switch (i)
            {
                case 2:
                {
                    return 127;
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
                {
                    return 128;
                }
                case 19:
                {
                    return 129;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 129:
        {
            switch (i)
            {
                case 2:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 31:
                case 32:
                case 33:
                {
                    return 130;
                }
                case 15:
                {
                    return 131;
                }
                case 16:
                {
                    return 132;
                }
                case 18:
                {
                    return 133;
                }
                case 34:
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
            switch (i)
            {
                case 2:
                {
                    return 127;
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
                {
                    return 128;
                }
                case 19:
                {
                    return 129;
                }
                case 34:
                {
                    return 135;
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
                {
                    return 127;
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
                {
                    return 128;
                }
                case 19:
                {
                    return 129;
                }
                case 34:
                {
                    return 136;
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
                case 2:
                {
                    return 127;
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
                {
                    return 128;
                }
                case 19:
                {
                    return 129;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 133:
        {
            switch (i)
            {
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                {
                    return 137;
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
                case 2:
                {
                    return 127;
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
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
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
                {
                    return 128;
                }
                case 19:
                {
                    return 129;
                }
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                {
                    return 137;
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                {
                    return 138;
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                {
                    return 140;
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                {
                    return 127;
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
                {
                    return 128;
                }
                case 19:
                {
                    return 129;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 131:
        {
            switch (i)
            {
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
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
                case 2:
                {
                    return 127;
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
                {
                    return 128;
                }
                case 19:
                {
                    return 129;
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
                case 2:
                {
                    return 127;
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
                {
                    return 128;
                }
                case 19:
                {
                    return 129;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 128:
        {
            switch (i)
            {
                case 2:
                {
                    return 127;
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
                {
                    return 128;
                }
                case 19:
                {
                    return 129;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 127:
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
            return -1;
        }
        case 2:
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
            return -1;
        }
        case 1:
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
                case 1:
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
            return -1;
        }
    }
    return -1;
}

int TextLexer::GetTokenId(int statementIndex)
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
            pp->Emit(U" ", token.match, BLOCKCOMMENT);
            break;
        }
        case 3:
        {
            Retract();
            pp->Emit(U" ", token.match, LINECOMMENT);
            break;
        }
        case 4:
        {
            Retract();
            break;
        }
        case 5:
        {
            Retract();
            if (pp->IsKeywordToken(token)) return KEYWORD;
            else return ID;
            break;
        }
        case 6:
        {
            Retract();
            return PPNUMBER;
            break;
        }
        case 7:
        {
            Retract();
            return CHARLITERAL;
            break;
        }
        case 8:
        {
            Retract();
            return STRINGLITERAL;
            break;
        }
        case 9:
        {
            Retract();
            return COLONCOLON;
            break;
        }
        case 10:
        {
            Retract();
            return COMMA;
            break;
        }
        case 11:
        {
            Retract();
            return ASSIGN;
            break;
        }
        case 12:
        {
            Retract();
            return MULASSIGN;
            break;
        }
        case 13:
        {
            Retract();
            return DIVASSIGN;
            break;
        }
        case 14:
        {
            Retract();
            return REMASSIGN;
            break;
        }
        case 15:
        {
            Retract();
            return ADDASSIGN;
            break;
        }
        case 16:
        {
            Retract();
            return SUBASSIGN;
            break;
        }
        case 17:
        {
            Retract();
            return SHIFTRIGHTASSIGN;
            break;
        }
        case 18:
        {
            Retract();
            return SHIFTLEFTASSIGN;
            break;
        }
        case 19:
        {
            Retract();
            return ANDASSIGN;
            break;
        }
        case 20:
        {
            Retract();
            return XORASSIGN;
            break;
        }
        case 21:
        {
            Retract();
            return ORASSIGN;
            break;
        }
        case 22:
        {
            Retract();
            return QUEST;
            break;
        }
        case 23:
        {
            Retract();
            return COLON;
            break;
        }
        case 24:
        {
            Retract();
            return OROR;
            break;
        }
        case 25:
        {
            Retract();
            return AMPAMP;
            break;
        }
        case 26:
        {
            Retract();
            return OR;
            break;
        }
        case 27:
        {
            Retract();
            return XOR;
            break;
        }
        case 28:
        {
            Retract();
            return AMP;
            break;
        }
        case 29:
        {
            Retract();
            return EQ;
            break;
        }
        case 30:
        {
            Retract();
            return NEQ;
            break;
        }
        case 31:
        {
            Retract();
            return LEQ;
            break;
        }
        case 32:
        {
            Retract();
            return GEQ;
            break;
        }
        case 33:
        {
            Retract();
            return SPACESHIP;
            break;
        }
        case 34:
        {
            Retract();
            return LANGLE;
            break;
        }
        case 35:
        {
            Retract();
            return RANGLE;
            break;
        }
        case 36:
        {
            Retract();
            return SHIFTLEFT;
            break;
        }
        case 37:
        {
            Retract();
            return SHIFTRIGHT;
            break;
        }
        case 38:
        {
            Retract();
            return PLUS;
            break;
        }
        case 39:
        {
            Retract();
            return MINUS;
            break;
        }
        case 40:
        {
            Retract();
            return STAR;
            break;
        }
        case 41:
        {
            Retract();
            return DIV;
            break;
        }
        case 42:
        {
            Retract();
            return MOD;
            break;
        }
        case 43:
        {
            Retract();
            return DOTSTAR;
            break;
        }
        case 44:
        {
            Retract();
            return ARROWSTAR;
            break;
        }
        case 45:
        {
            Retract();
            return LPAREN;
            break;
        }
        case 46:
        {
            Retract();
            return RPAREN;
            break;
        }
        case 47:
        {
            Retract();
            return PLUSPLUS;
            break;
        }
        case 48:
        {
            Retract();
            return MINUSMINUS;
            break;
        }
        case 49:
        {
            Retract();
            return EXCLAMATION;
            break;
        }
        case 50:
        {
            Retract();
            return TILDE;
            break;
        }
        case 51:
        {
            Retract();
            return LBRACKET;
            break;
        }
        case 52:
        {
            Retract();
            return RBRACKET;
            break;
        }
        case 53:
        {
            Retract();
            return DOT;
            break;
        }
        case 54:
        {
            Retract();
            return ARROW;
            break;
        }
        case 55:
        {
            Retract();
            return SEMICOLON;
            break;
        }
        case 56:
        {
            Retract();
            return ELLIPSES;
            break;
        }
        case 57:
        {
            Retract();
            return LBRACE;
            break;
        }
        case 58:
        {
            Retract();
            return RBRACE;
            break;
        }
    }
    return CONTINUE_TOKEN;
}
