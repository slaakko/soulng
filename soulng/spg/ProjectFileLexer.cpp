
// this file has been automatically generated from 'D:/work/soulng-project/soulng/spg/ProjectFileLexer.lexer' using soulng lexer generator slg version 1.2.0

#include <soulng/spg/ProjectFileLexer.hpp>
#include <soulng/spg/ProjectFileKeywords.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/spg/ProjectFileTokens.hpp>
#include <soulng/spg/ProjectFileClassMap.hpp>

using namespace soulng::lexer;
using namespace ProjectFileTokens;

ProjectFileLexer::ProjectFileLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_) : soulng::lexer::Lexer(content_, fileName_, fileIndex_),
    filePath()
{
    SetKeywordMap(ProjectFileKeywords::GetKeywordMap());
}

ProjectFileLexer::ProjectFileLexer(const char32_t* start_, const char32_t* end_, const std::string& fileName_, int fileIndex_) : soulng::lexer::Lexer(start_, end_, fileName_, fileIndex_),
    filePath()
{
    SetKeywordMap(ProjectFileKeywords::GetKeywordMap());
}

int ProjectFileLexer::NextState(int state, char32_t c)
{
    int i = ProjectFileClassMap::GetClass(c);
    switch (state)
    {
        case 0:
        {
            switch (i)
            {
                case 0:
                case 3:
                case 6:
                case 7:
                {
                    return 1;
                }
                case 1:
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
                case 11:
                {
                    return 5;
                }
                case 12:
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
            switch (i)
            {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 11:
                case 12:
                {
                    return 7;
                }
                case 10:
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
        case 7:
        {
            switch (i)
            {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 11:
                case 12:
                {
                    return 7;
                }
                case 10:
                {
                    return 8;
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
                    return 9;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 2:
        {
            switch (i)
            {
                case 1:
                {
                    return 10;
                }
                case 2:
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
                case 0:
                case 1:
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
                {
                    return 12;
                }
                case 2:
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
                case 2:
                {
                    return 13;
                }
                case 0:
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
                {
                    return 14;
                }
                case 1:
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
                case 12:
                {
                    return 12;
                }
                case 2:
                {
                    return 13;
                }
                case 0:
                case 3:
                case 6:
                case 7:
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
                case 0:
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
                {
                    return 12;
                }
                case 1:
                {
                    return 18;
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
            switch (i)
            {
                case 2:
                {
                    return 13;
                }
                case 0:
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
                {
                    return 14;
                }
                case 1:
                {
                    return 15;
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
                {
                    return 20;
                }
                case 1:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                {
                    return 21;
                }
                case 2:
                {
                    return 22;
                }
                case 3:
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
                case 12:
                {
                    return 12;
                }
                case 2:
                {
                    return 13;
                }
                case 3:
                case 6:
                case 7:
                {
                    return 16;
                }
                case 1:
                {
                    return 17;
                }
                case 0:
                {
                    return 24;
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
                case 12:
                {
                    return 12;
                }
                case 2:
                {
                    return 13;
                }
                case 0:
                case 3:
                case 6:
                case 7:
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
        case 22:
        {
            switch (i)
            {
                case 2:
                {
                    return 22;
                }
                case 0:
                {
                    return 25;
                }
                case 1:
                {
                    return 26;
                }
                case 3:
                {
                    return 27;
                }
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
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
                case 0:
                {
                    return 20;
                }
                case 1:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                {
                    return 21;
                }
                case 2:
                {
                    return 22;
                }
                case 3:
                {
                    return 23;
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
                case 9:
                case 10:
                case 11:
                case 12:
                {
                    return 12;
                }
                case 2:
                {
                    return 13;
                }
                case 3:
                case 6:
                case 7:
                {
                    return 16;
                }
                case 1:
                {
                    return 17;
                }
                case 0:
                {
                    return 24;
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
                case 9:
                case 10:
                case 11:
                case 12:
                {
                    return 21;
                }
                case 2:
                {
                    return 22;
                }
                case 0:
                {
                    return 29;
                }
                case 1:
                {
                    return 30;
                }
                case 3:
                {
                    return 31;
                }
                case 6:
                case 7:
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
                case 4:
                case 5:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                {
                    return 21;
                }
                case 2:
                {
                    return 22;
                }
                case 0:
                {
                    return 29;
                }
                case 1:
                {
                    return 30;
                }
                case 3:
                {
                    return 31;
                }
                case 6:
                case 7:
                {
                    return 32;
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
                case 4:
                case 5:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                {
                    return 12;
                }
                case 2:
                {
                    return 13;
                }
                case 3:
                case 6:
                case 7:
                {
                    return 16;
                }
                case 1:
                {
                    return 17;
                }
                case 0:
                {
                    return 24;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 30:
        {
            switch (i)
            {
                case 1:
                {
                    return 18;
                }
                case 0:
                {
                    return 20;
                }
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                {
                    return 21;
                }
                case 3:
                {
                    return 23;
                }
                case 2:
                {
                    return 33;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 33:
        {
            switch (i)
            {
                case 2:
                {
                    return 22;
                }
                case 0:
                {
                    return 25;
                }
                case 1:
                {
                    return 26;
                }
                case 3:
                {
                    return 27;
                }
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                {
                    return 28;
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
                case 12:
                {
                    return 12;
                }
                case 2:
                {
                    return 13;
                }
                case 0:
                case 3:
                case 6:
                case 7:
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
                case 12:
                {
                    return 12;
                }
                case 2:
                {
                    return 13;
                }
                case 0:
                case 3:
                case 6:
                case 7:
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
        case 21:
        {
            switch (i)
            {
                case 0:
                {
                    return 20;
                }
                case 1:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                {
                    return 21;
                }
                case 2:
                {
                    return 22;
                }
                case 3:
                {
                    return 23;
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
                case 12:
                {
                    return 12;
                }
                case 2:
                {
                    return 13;
                }
                case 0:
                case 3:
                case 6:
                case 7:
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
        case 16:
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
                case 12:
                {
                    return 12;
                }
                case 2:
                {
                    return 13;
                }
                case 0:
                case 3:
                case 6:
                case 7:
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
        case 14:
        {
            switch (i)
            {
                case 0:
                case 1:
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
                {
                    return 12;
                }
                case 2:
                {
                    return 13;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 12:
        {
            switch (i)
            {
                case 0:
                case 1:
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
                {
                    return 12;
                }
                case 2:
                {
                    return 13;
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
                {
                    return 34;
                }
                case 1:
                case 2:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                {
                    return 35;
                }
                case 3:
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
                case 3:
                case 6:
                case 7:
                {
                    return 1;
                }
                case 1:
                {
                    return 2;
                }
                case 0:
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
                case 3:
                case 6:
                case 7:
                {
                    return 1;
                }
                case 1:
                {
                    return 2;
                }
                default:
                {
                    return -1;
                }
            }
        }
        case 35:
        {
            switch (i)
            {
                case 0:
                {
                    return 34;
                }
                case 1:
                case 2:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                {
                    return 35;
                }
                case 3:
                {
                    return 36;
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
                case 3:
                case 6:
                case 7:
                {
                    return 1;
                }
                case 1:
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
                case 3:
                case 6:
                case 7:
                {
                    return 1;
                }
                case 1:
                {
                    return 2;
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

int ProjectFileLexer::GetTokenId(int statementIndex)
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
            filePath = soulng::spg::MakeFilePath(FileName(), token);
            return FILEPATH;
            break;
        }
        case 3:
        {
            Retract();
            return DOT;
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
