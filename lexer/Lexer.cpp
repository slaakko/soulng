// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/lexer/Lexer.hpp>

namespace soulng { namespace lexer {

Lexer::Lexer(const std::u32string& content_) :
    content(content_), keywordMap(nullptr), start(content.c_str()), end(content.c_str() + content.length()), pos(start), state(0), c('\0'), line(1), current(tokens.end())
{
}

Lexer::~Lexer()
{
}

void Lexer::operator++()
{
    if (current != tokens.end())
    {
        ++current;
    }
    if (current == tokens.end())
    {
        NextToken();
    }
}

void Lexer::NextToken()
{
    state = 0;
    while (pos != end)
    {
        c = *pos;
        if (state == 0)
        {
            lexeme.begin = pos;
            token.id = INVALID_TOKEN;
            token.line = line;
        }
        lexeme.end = pos + 1;
        GetNextToken();
        if (c == '\n')
        {
            ++line;
        }
        ++pos;
    }
    tokens.push_back(Token(END));
    current = tokens.end() - 1;
}

void Lexer::GetNextToken()
{
}

int Lexer::GetKeywordToken(const Lexeme& lexeme) const
{
    if (keywordMap)
    {
        return keywordMap->GetKeywordToken(lexeme);
    }
    else
    {
        return INVALID_TOKEN;
    }
}

} } // namespace soulng::lexer
