// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/pp/Scan.hpp>
#include <sngcpp20/pp/TextTokens.hpp>

namespace sngcpp::pp {

bool ScanRawStringLiteral(soulng::lexer::Lexer& lexer, soulng::lexer::Token& token)
{
    int64_t save = lexer.GetPos();
    const char32_t* p = token.match.begin;
    const char32_t* e = lexer.End();
    bool valid = false;
    bool stop = false;
    int state = 0;
    int index = 0;
    std::u32string dm;
    while (p != e && !stop && !valid)
    {
        switch (state)
        {
            case 0:
            {
                if (*p == 'R')
                {
                    state = 1;
                }
                else
                {
                    stop = true;
                }
                break;
            }
            case 1:
            {
                if (*p == '"')
                {
                    state = 2;
                }
                else
                {
                    stop = true;
                }
                break;
            }
            case 2:
            {
                switch (*p)
                {
                    case ' ': case ')': case '\\': case '\t': case '\v': case '\f': case '\n':
                    {
                        stop = true;
                        break;
                    }
                    case '(':
                    {
                        dm.append(1, '"');
                        state = 3;
                        break;
                    }
                    default:
                    {
                        dm.append(1, *p);
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                switch (*p)
                {
                    case ')':
                    {
                        index = 0;
                        state = 4;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            case 4:
            {
                if (index == dm.length())
                {
                    valid = true;
                }
                else if (*p == dm[index])
                {
                    ++index;
                }
                else
                {
                    switch (*p)
                    {
                        case ')':
                        {
                            index = 0;
                            break;
                        }
                        default:
                        {
                            state = 3;
                            break;
                        }
                    }
                }
                break;
            }
        }
        if (!valid)
        {
            ++p;
        }
    }
    if (state == 4 && index == dm.length())
    {
        valid = true;
    }    
    if (valid)
    {
        token.match.end = p;
        lexer.Tokens().erase(lexer.Current() + 1, lexer.Tokens().end());
        lexer.SetPos(p);
        return true;
    }
    lexer.SetPos(save);
    return false;
}

bool ScanBlockComment(soulng::lexer::Lexer& lexer, soulng::lexer::Token& token)
{
    int64_t save = lexer.GetPos();
    const char32_t* p = token.match.begin;
    const char32_t* e = lexer.End();
    int state = 0;
    while (p != e)
    {
        switch (state)
        {
            case 0:
            {
                switch (*p)
                {
                    case '/':
                    {
                        state = 1;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            case 1:
            {
                switch (*p)
                {
                    case '/':
                    {
                        break;
                    }
                    case '*':
                    {
                        state = 2;
                        break;
                    }
                    default:
                    {
                        state = 0;
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                switch (*p)
                {
                    case '*':
                    {
                        state = 3;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                switch (*p)
                {
                    case '*':
                    {
                        break;
                    }
                    case '/':
                    {
                        state = 4;
                        ++p;
                        token.id = TextTokens::BLOCKCOMMENT;
                        lexer.Tokens().erase(lexer.Current() + 1, lexer.Tokens().end());
                        token.match.end = p;
                        lexer.SetPos(p);
                        return true;
                    }
                    default:
                    {
                        state = 2;
                        break;
                    }
                }
                break;
            }
        }
        ++p;
    }
    lexer.SetPos(save);
    return false;
}

bool ScanLineCommentWithoutNewLine(soulng::lexer::Lexer& lexer, soulng::lexer::Token& token)
{
    int64_t save = lexer.GetPos();
    const char32_t* p = token.match.begin;
    const char32_t* e = lexer.End();
    int state = 0;
    while (p != e)
    {
        switch (state)
        {
            case 0:
            {
                switch (*p)
                {
                    case '/':
                    {
                        state = 1;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            case 1:
            {
                switch (*p)
                {
                    case '/':
                    {
                        state = 2;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                switch (*p)
                {
                    case '\n':
                    {
                        token.id = TextTokens::LINECOMMENT;
                        token.match.end = p;
                        lexer.Tokens().erase(lexer.Current() + 1, lexer.Tokens().end());
                        lexer.SetPos(p);
                        return true;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
        }
        ++p;
    }
    lexer.SetPos(save);
    return false;
}

} // namespace sngcpp::pp
