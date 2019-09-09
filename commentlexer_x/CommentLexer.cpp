#include "CommentLexer.hpp"
#include "CommentKeywords.hpp"
#include <soulng/lexer/Token.hpp>
#include "CommentTokens.hpp"
#include "ClassMap.hpp"

using namespace soulng::lexer;
using namespace CommentTokens;

CommentLexer::CommentLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_) : soulng::lexer::Lexer(content_, fileName_, fileIndex_)
{
    SetKeywordMap(CommentKeywords::GetKeywordMap());
}

int CommentLexer::NextState(int state, char32_t c)
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
                default:
                {
                    return -1;
                }
            }
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
                    return 4;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 4:
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
                    return 4;
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
                    return 5;
                }
                case 1:
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
                {
                    return 7;
                }
                case 1:
                {
                    return 8;
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
                case 1:
                {
                    return 8;
                }
                case 0:
                {
                    return 9;
                }
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                {
                    return 10;
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
                {
                    return 7;
                }
                case 1:
                {
                    return 8;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 9:
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
                {
                    return 7;
                }
                case 1:
                {
                    return 8;
                }
                case 0:
                {
                    return 11;
                }
                case 2:
                case 3:
                case 6:
                case 7:
                {
                    return 12;
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
                {
                    return 7;
                }
                case 1:
                {
                    return 8;
                }
                case 0:
                {
                    return 11;
                }
                case 2:
                case 3:
                case 6:
                case 7:
                {
                    return 12;
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
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                {
                    return 7;
                }
                case 0:
                {
                    return 13;
                }
                case 1:
                {
                    return 14;
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
                case 1:
                {
                    return 8;
                }
                case 0:
                {
                    return 9;
                }
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                {
                    return 10;
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
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                {
                    return 15;
                }
                case 1:
                {
                    return 16;
                }
                case 2:
                {
                    return 17;
                }
                case 3:
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
                {
                    return 7;
                }
                case 1:
                {
                    return 8;
                }
                case 0:
                {
                    return 11;
                }
                case 3:
                case 6:
                case 7:
                {
                    return 12;
                }
                case 2:
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
                {
                    return 7;
                }
                case 1:
                {
                    return 8;
                }
                case 0:
                {
                    return 11;
                }
                case 2:
                case 3:
                case 6:
                case 7:
                {
                    return 12;
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
                case 4:
                case 5:
                case 8:
                {
                    return 7;
                }
                case 1:
                {
                    return 8;
                }
                case 0:
                {
                    return 11;
                }
                case 2:
                case 3:
                case 6:
                case 7:
                {
                    return 12;
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
                case 1:
                {
                    return 16;
                }
                case 0:
                {
                    return 20;
                }
                case 2:
                {
                    return 21;
                }
                case 3:
                {
                    return 22;
                }
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
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
            switch (i)
            {
                case 0:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                {
                    return 15;
                }
                case 1:
                {
                    return 16;
                }
                case 2:
                {
                    return 17;
                }
                case 3:
                {
                    return 18;
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
                {
                    return 7;
                }
                case 1:
                {
                    return 8;
                }
                case 0:
                {
                    return 11;
                }
                case 3:
                case 6:
                case 7:
                {
                    return 12;
                }
                case 2:
                {
                    return 19;
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
                {
                    return 7;
                }
                case 1:
                {
                    return 8;
                }
                case 0:
                {
                    return 11;
                }
                case 2:
                case 3:
                case 6:
                case 7:
                {
                    return 12;
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
                {
                    return 15;
                }
                case 1:
                {
                    return 16;
                }
                case 0:
                {
                    return 24;
                }
                case 2:
                {
                    return 25;
                }
                case 3:
                {
                    return 26;
                }
                case 6:
                case 7:
                {
                    return 27;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 27:
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
                {
                    return 15;
                }
                case 1:
                {
                    return 16;
                }
                case 0:
                {
                    return 24;
                }
                case 2:
                {
                    return 25;
                }
                case 3:
                {
                    return 26;
                }
                case 6:
                case 7:
                {
                    return 27;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 26:
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
                {
                    return 7;
                }
                case 1:
                {
                    return 8;
                }
                case 0:
                {
                    return 11;
                }
                case 3:
                case 6:
                case 7:
                {
                    return 12;
                }
                case 2:
                {
                    return 19;
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
                {
                    return 7;
                }
                case 1:
                {
                    return 8;
                }
                case 0:
                {
                    return 11;
                }
                case 2:
                case 3:
                case 6:
                case 7:
                {
                    return 12;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 24:
        {
            switch (i)
            {
                case 0:
                {
                    return 13;
                }
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                {
                    return 15;
                }
                case 2:
                {
                    return 17;
                }
                case 3:
                {
                    return 18;
                }
                case 1:
                {
                    return 28;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 28:
        {
            switch (i)
            {
                case 1:
                {
                    return 16;
                }
                case 0:
                {
                    return 20;
                }
                case 2:
                {
                    return 21;
                }
                case 3:
                {
                    return 22;
                }
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                {
                    return 23;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 15:
        {
            switch (i)
            {
                case 0:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                {
                    return 15;
                }
                case 1:
                {
                    return 16;
                }
                case 2:
                {
                    return 17;
                }
                case 3:
                {
                    return 18;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 7:
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
                {
                    return 7;
                }
                case 1:
                {
                    return 8;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 5:
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
                {
                    return 29;
                }
                case 2:
                {
                    return 30;
                }
                case 3:
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
                    return 32;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 32:
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
        case 29:
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
                {
                    return 29;
                }
                case 2:
                {
                    return 30;
                }
                case 3:
                {
                    return 31;
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

int CommentLexer::GetTokenId(int statementIndex)
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
    }
    return CONTINUE_TOKEN;
}
