
// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/Minilang.lexer' using soulng lexer generator slg version 1.2.0

#include "MinilangLexer.hpp"
#include "MinilangKeywords.hpp"
#include <soulng/lexer/Token.hpp>
#include "MinilangTokens.hpp"
#include "ClassMap.hpp"

using namespace soulng::lexer;
using namespace MinilangTokens;

MinilangLexer::MinilangLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_) : soulng::lexer::Lexer(content_, fileName_, fileIndex_)
{
    SetKeywordMap(MinilangKeywords::GetKeywordMap());
}

int MinilangLexer::NextState(int state, char32_t c)
{
    int i = ClassMap::GetClass(c);
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
                case 2:
                case 3:
                case 4:
                case 5:
                {
                    return 2;
                }
                case 6:
                {
                    return 3;
                }
                case 7:
                {
                    return 4;
                }
                case 8:
                {
                    return 5;
                }
                case 9:
                {
                    return 6;
                }
                case 10:
                {
                    return 7;
                }
                case 11:
                {
                    return 8;
                }
                case 12:
                {
                    return 9;
                }
                case 13:
                {
                    return 10;
                }
                case 14:
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
                case 18:
                {
                    return 15;
                }
                case 19:
                {
                    return 16;
                }
                case 20:
                {
                    return 17;
                }
                case 21:
                {
                    return 18;
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
        case 17:
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
            switch (i)
            {
                case 18:
                {
                    return 19;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 19:
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
        case 16:
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
            switch (i)
            {
                case 18:
                {
                    return 20;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 20:
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
        case 15:
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
            switch (i)
            {
                case 18:
                {
                    return 21;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 21:
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
        case 14:
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
            switch (i)
            {
                case 18:
                {
                    return 22;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 22:
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
        case 13:
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
        case 12:
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
            return -1;
        }
        case 11:
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
        case 10:
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
        case 9:
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
        case 8:
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
        case 7:
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
            return -1;
        }
        case 5:
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
        case 4:
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
                case 6:
                {
                    return 3;
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
                case 2:
                case 3:
                case 4:
                case 5:
                {
                    return 2;
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
                case 0:
                case 1:
                case 6:
                {
                    return 23;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 23:
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
                case 0:
                case 1:
                case 6:
                {
                    return 23;
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

int MinilangLexer::GetTokenId(int statementIndex)
{
    switch (statementIndex)
    {
        case 0:
        {
            Retract();
            break;
        }
        case 1:
        {
            Retract();
            int kw = GetKeywordToken(token.match);
            if (kw == INVALID_TOKEN) return ID;
            else return kw;
            break;
        }
        case 2:
        {
            Retract();
            return INTLIT;
            break;
        }
        case 3:
        {
            Retract();
            return SEMICOLON;
            break;
        }
        case 4:
        {
            Retract();
            return LPAREN;
            break;
        }
        case 5:
        {
            Retract();
            return RPAREN;
            break;
        }
        case 6:
        {
            Retract();
            return LBRACE;
            break;
        }
        case 7:
        {
            Retract();
            return RBRACE;
            break;
        }
        case 8:
        {
            Retract();
            return PLUS;
            break;
        }
        case 9:
        {
            Retract();
            return MINUS;
            break;
        }
        case 10:
        {
            Retract();
            return MUL;
            break;
        }
        case 11:
        {
            Retract();
            return DIV;
            break;
        }
        case 12:
        {
            Retract();
            return MOD;
            break;
        }
        case 13:
        {
            Retract();
            return NOT;
            break;
        }
        case 14:
        {
            Retract();
            return EQ;
            break;
        }
        case 15:
        {
            Retract();
            return NEQ;
            break;
        }
        case 16:
        {
            Retract();
            return LEQ;
            break;
        }
        case 17:
        {
            Retract();
            return GEQ;
            break;
        }
        case 18:
        {
            Retract();
            return LESS;
            break;
        }
        case 19:
        {
            Retract();
            return GREATER;
            break;
        }
        case 20:
        {
            Retract();
            return ASSIGN;
            break;
        }
        case 21:
        {
            Retract();
            return COMMA;
            break;
        }
    }
    return CONTINUE_TOKEN;
}
