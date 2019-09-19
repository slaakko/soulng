
// this file has been automatically generated from 'D:/work/soulng-project/doc/topics/syntax/ast/ExampleLexer.lexer' using soulng lexer generator slg version 1.0.0

#include "ExampleLexer.hpp"
#include "ExampleKeywords.hpp"
#include <soulng/lexer/Token.hpp>
#include "ExampleTokens.hpp"
#include "ClassMap.hpp"

using namespace soulng::lexer;
using namespace ExampleTokens;

ExampleLexer::ExampleLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_) : soulng::lexer::Lexer(content_, fileName_, fileIndex_)
{
    SetKeywordMap(ExampleKeywords::GetKeywordMap());
}

int ExampleLexer::NextState(int state, char32_t c)
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
                case 6:
                case 7:
                {
                    return 2;
                }
                case 4:
                {
                    return 3;
                }
                case 9:
                {
                    return 4;
                }
                case 10:
                {
                    return 5;
                }
                case 11:
                {
                    return 6;
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
            return -1;
        }
        case 5:
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
        case 4:
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
        case 3:
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
                case 4:
                case 5:
                {
                    return 7;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 7:
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
                case 4:
                case 5:
                {
                    return 7;
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
                case 0:
                {
                    return 1;
                }
                case 2:
                case 3:
                case 6:
                case 7:
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
            switch (i)
            {
                case 0:
                {
                    return 8;
                }
                case 1:
                {
                    return 9;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 9:
        {
            switch (i)
            {
                case 0:
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
                {
                    return 10;
                }
                case 1:
                {
                    return 11;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 11:
        {
            switch (i)
            {
                case 1:
                {
                    return 11;
                }
                case 0:
                {
                    return 12;
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
                {
                    return 13;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 13:
        {
            switch (i)
            {
                case 0:
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
                {
                    return 10;
                }
                case 1:
                {
                    return 11;
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
                case 4:
                case 5:
                case 8:
                case 9:
                case 10:
                case 11:
                {
                    return 10;
                }
                case 1:
                {
                    return 11;
                }
                case 0:
                {
                    return 14;
                }
                case 2:
                case 3:
                case 6:
                case 7:
                {
                    return 15;
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
                case 4:
                case 5:
                case 8:
                case 9:
                case 10:
                case 11:
                {
                    return 10;
                }
                case 1:
                {
                    return 11;
                }
                case 0:
                {
                    return 14;
                }
                case 2:
                case 3:
                case 6:
                case 7:
                {
                    return 15;
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
                {
                    return 10;
                }
                case 0:
                {
                    return 16;
                }
                case 1:
                {
                    return 17;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 17:
        {
            switch (i)
            {
                case 1:
                {
                    return 11;
                }
                case 0:
                {
                    return 12;
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
                {
                    return 13;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 16:
        {
            switch (i)
            {
                case 0:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                {
                    return 18;
                }
                case 1:
                {
                    return 19;
                }
                case 2:
                {
                    return 20;
                }
                case 3:
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
                case 4:
                case 5:
                case 8:
                case 9:
                case 10:
                case 11:
                {
                    return 10;
                }
                case 1:
                {
                    return 11;
                }
                case 0:
                {
                    return 14;
                }
                case 3:
                case 6:
                case 7:
                {
                    return 15;
                }
                case 2:
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
                case 4:
                case 5:
                case 8:
                case 9:
                case 10:
                case 11:
                {
                    return 10;
                }
                case 1:
                {
                    return 11;
                }
                case 0:
                {
                    return 14;
                }
                case 2:
                case 3:
                case 6:
                case 7:
                {
                    return 15;
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
                case 4:
                case 5:
                case 8:
                case 9:
                case 10:
                case 11:
                {
                    return 10;
                }
                case 1:
                {
                    return 11;
                }
                case 0:
                {
                    return 14;
                }
                case 2:
                case 3:
                case 6:
                case 7:
                {
                    return 15;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 19:
        {
            switch (i)
            {
                case 1:
                {
                    return 19;
                }
                case 0:
                {
                    return 23;
                }
                case 2:
                {
                    return 24;
                }
                case 3:
                {
                    return 25;
                }
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                {
                    return 26;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 26:
        {
            switch (i)
            {
                case 0:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                {
                    return 18;
                }
                case 1:
                {
                    return 19;
                }
                case 2:
                {
                    return 20;
                }
                case 3:
                {
                    return 21;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 25:
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
                case 4:
                case 5:
                case 8:
                case 9:
                case 10:
                case 11:
                {
                    return 10;
                }
                case 1:
                {
                    return 11;
                }
                case 0:
                {
                    return 14;
                }
                case 3:
                case 6:
                case 7:
                {
                    return 15;
                }
                case 2:
                {
                    return 22;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 24:
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
                case 4:
                case 5:
                case 8:
                case 9:
                case 10:
                case 11:
                {
                    return 10;
                }
                case 1:
                {
                    return 11;
                }
                case 0:
                {
                    return 14;
                }
                case 2:
                case 3:
                case 6:
                case 7:
                {
                    return 15;
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
                case 4:
                case 5:
                case 8:
                case 9:
                case 10:
                case 11:
                {
                    return 18;
                }
                case 1:
                {
                    return 19;
                }
                case 0:
                {
                    return 27;
                }
                case 2:
                {
                    return 28;
                }
                case 3:
                {
                    return 29;
                }
                case 6:
                case 7:
                {
                    return 30;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 30:
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
                case 4:
                case 5:
                case 8:
                case 9:
                case 10:
                case 11:
                {
                    return 18;
                }
                case 1:
                {
                    return 19;
                }
                case 0:
                {
                    return 27;
                }
                case 2:
                {
                    return 28;
                }
                case 3:
                {
                    return 29;
                }
                case 6:
                case 7:
                {
                    return 30;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 29:
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
                case 4:
                case 5:
                case 8:
                case 9:
                case 10:
                case 11:
                {
                    return 10;
                }
                case 1:
                {
                    return 11;
                }
                case 0:
                {
                    return 14;
                }
                case 3:
                case 6:
                case 7:
                {
                    return 15;
                }
                case 2:
                {
                    return 22;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 28:
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
                case 4:
                case 5:
                case 8:
                case 9:
                case 10:
                case 11:
                {
                    return 10;
                }
                case 1:
                {
                    return 11;
                }
                case 0:
                {
                    return 14;
                }
                case 2:
                case 3:
                case 6:
                case 7:
                {
                    return 15;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 27:
        {
            switch (i)
            {
                case 0:
                {
                    return 16;
                }
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                {
                    return 18;
                }
                case 2:
                {
                    return 20;
                }
                case 3:
                {
                    return 21;
                }
                case 1:
                {
                    return 31;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 31:
        {
            switch (i)
            {
                case 1:
                {
                    return 19;
                }
                case 0:
                {
                    return 23;
                }
                case 2:
                {
                    return 24;
                }
                case 3:
                {
                    return 25;
                }
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                {
                    return 26;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 18:
        {
            switch (i)
            {
                case 0:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                {
                    return 18;
                }
                case 1:
                {
                    return 19;
                }
                case 2:
                {
                    return 20;
                }
                case 3:
                {
                    return 21;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 10:
        {
            switch (i)
            {
                case 0:
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
                {
                    return 10;
                }
                case 1:
                {
                    return 11;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 8:
        {
            switch (i)
            {
                case 0:
                case 1:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                {
                    return 32;
                }
                case 2:
                {
                    return 33;
                }
                case 3:
                {
                    return 34;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 34:
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
                case 0:
                {
                    return 1;
                }
                case 3:
                case 6:
                case 7:
                {
                    return 2;
                }
                case 2:
                {
                    return 35;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 35:
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
                case 0:
                {
                    return 1;
                }
                case 2:
                case 3:
                case 6:
                case 7:
                {
                    return 2;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 33:
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
                case 0:
                {
                    return 1;
                }
                case 2:
                case 3:
                case 6:
                case 7:
                {
                    return 2;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 32:
        {
            switch (i)
            {
                case 0:
                case 1:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                {
                    return 32;
                }
                case 2:
                {
                    return 33;
                }
                case 3:
                {
                    return 34;
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

int ExampleLexer::GetTokenId(int statementIndex)
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
            return LPAREN;
            break;
        }
        case 3:
        {
            Retract();
            return RPAREN;
            break;
        }
        case 4:
        {
            Retract();
            return SEMICOLON;
            break;
        }
    }
    return CONTINUE_TOKEN;
}
