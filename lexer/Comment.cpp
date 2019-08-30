// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/lexer/Comment.hpp>

namespace soulng { namespace lexer {

void RemoveComments(std::u32string& content)
{
    const char32_t* s = content.c_str();
    const char32_t* p = content.c_str();
    const char32_t* e = content.c_str() + content.length();
    int commentStart = 0;
    int commentEnd = 0;
    int state = 0;
    while (p != e)
    {
        switch (state)
        {
        case 0:
        {
            if (*p == '/')
            {
                commentStart = p - s;
                state = 1;
            }
            break;
        }
        case 1:
        {
            switch (*p)
            {
            case '*': state = 2; break;
            case '/': state = 4; break;
            default: state = 0; break;
            }
            break;
        }
        case 2:
        {
            if (*p == '*')
            {
                state = 3;
            }
            break;
        }
        case 3:
        {
            switch (*p)
            {
            case '/':
            {
                commentEnd = p - s;
                for (int i = commentStart; i <= commentEnd; ++i)
                {
                    if (content[i] != '\r' &&content[i] != '\n')
                    {
                        content[i] = ' ';
                    }
                }
                state = 0;
                break;
            }
            case '*': break;
            default: state = 2; break;
            }
            break;
        }
        case 4:
        {
            switch (*p)
            {
            case '\r': case '\n':
            {
                commentEnd = p - s;
                for (int i = commentStart; i <= commentEnd; ++i)
                {
                    if (content[i] != '\r' &&content[i] != '\n')
                    {
                        content[i] = ' ';
                    }
                }
                state = 0;
            }
            }
            break;
        }
        }
        ++p;
    }
}

} } // namespace soulng::lexer
