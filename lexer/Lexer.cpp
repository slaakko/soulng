// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/lexer/Lexer.hpp>
#include <soulng/util/Unicode.hpp>
#include <string>
#include <algorithm>

namespace soulng { namespace lexer {

using namespace soulng::unicode;

Lexer::Lexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_) :
    content(content_), fileName(fileName_), fileIndex(fileIndex_), line(1), keywordMap(nullptr), start(content.c_str()), end(content.c_str() + content.length()), pos(start), current(tokens.end())
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
    int state = 0;
    while (pos != end)
    {
        char32_t c = *pos;
        if (state == 0)
        {
            lexeme.begin = pos;
            token.id = INVALID_TOKEN;
            token.line = line;
        }
        lexeme.end = pos + 1;
        state = NextState(state, c);
        if (state == -1)
        {
            if (token.id == CONTINUE_TOKEN)
            {
                pos = token.match.end;
                state = 0;
                continue;
            }
            else if (token.id == INVALID_TOKEN)
            {
                throw std::runtime_error("invalid character '" + ToUtf8(std::u32string(1, c)) + "' at line " + std::to_string(line));
            }
            else
            {
                tokens.push_back(token);
                current = tokens.end() - 1;
                pos = token.match.end;
                return;
            }
        }
        if (c == '\n')
        {
            ++line;
        }
        ++pos;
    }
    token.id = INVALID_TOKEN;
    state = NextState(state, '\0');
    int p = -1;
    if (token.id != INVALID_TOKEN && token.id != CONTINUE_TOKEN)
    {
        tokens.push_back(token);
        current = tokens.end() - 1;
        p = GetPos();
    }
    Token endToken(END);
    endToken.match.begin = end;
    endToken.match.end = end;
    tokens.push_back(endToken);
    if (p == -1)
    {
        current = tokens.end() - 1;
        p = GetPos();
    }
    SetPos(p);
}

int Lexer::NextState(int state, char32_t c)
{
    return -1;
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

Token Lexer::GetToken(int tokenIndex) const
{
    if (tokenIndex >= 0 && tokenIndex < tokens.size())
    {
        return tokens[tokenIndex];
    }
    else
    {
        throw std::runtime_error("invalid token index");
    }
}

std::u32string Lexer::GetMatch(const Span& span) const
{
    std::u32string match;
    Token startToken = GetToken(span.start);
    match.append(std::u32string(startToken.match.begin, startToken.match.end));
    const char32_t* e = startToken.match.end;
    for (int i = span.start + 1; i <= span.end; ++i)
    {
        Token token = GetToken(i);
        match.append(std::u32string(token.match.begin - e, ' '));
        match.append(std::u32string(token.match.begin, token.match.end));
        e = token.match.end;
    }
    return match;
}

const char32_t* LineStart(const char32_t* start, const char32_t* p)
{
    while (p != start && *p != '\n' && *p != '\r')
    {
        --p;
    }
    if (p != start)
    {
        ++p;
    }
    return p;
}

const char32_t* LineEnd(const char32_t* end, const char32_t* p)
{
    while (p != end && *p != '\n' && *p != '\r')
    {
        ++p;
    }
    return p;
}

std::u32string Lexer::ErrorLines(const Token& token) const
{
    std::u32string lines;
    const char32_t* lineStart = LineStart(start, token.match.begin);
    const char32_t* lineEnd = LineEnd(end, token.match.end);
    lines.append(std::u32string(lineStart, token.match.begin));
    lines.append(std::u32string(token.match.begin, token.match.end));
    lines.append(std::u32string(token.match.end, lineEnd));
    lines.append(1, '\n');
    lines.append(token.match.begin - lineStart, ' ');
    lines.append(std::max(static_cast<int64_t>(1), token.match.end - token.match.begin), '^');
    lines.append(lineEnd - token.match.end, ' ');
    lines.append(1, '\n');
    return lines;
}

std::u32string Lexer::ErrorLines(const Span& span) const
{
    std::u32string lines;
    Token startToken = GetToken(span.start);
    Token endToken = startToken;
    const char32_t* lineStart = LineStart(start, startToken.match.begin);
    if (span.end != span.start)
    {
        endToken = GetToken(span.end);
    }
    const char32_t* lineEnd = LineEnd(end, endToken.match.end);
    lines.append(std::u32string(lineStart, startToken.match.begin));
    lines.append(std::u32string(startToken.match.begin, startToken.match.end));
    const char32_t* s = startToken.match.begin;
    const char32_t* e = startToken.match.end;
    for (int i = span.start + 1; i <= span.end; ++i)
    {
        Token token = GetToken(i);
        lines.append(std::u32string(token.match.begin - e, ' '));
        lines.append(std::u32string(token.match.begin, token.match.end));
        e = token.match.end;
    }
    lines.append(std::u32string(e, lineEnd));
    lines.append(1, '\n');
    lines.append(s - lineStart, ' ');
    lines.append(std::max(static_cast<int64_t>(1), e - s), '^');
    lines.append(lineEnd - e, ' ');
    lines.append(1, '\n');
    return lines;
}

void Lexer::ThrowExpectationFailure(int pos, const std::u32string& name)
{
    Token token = GetToken(pos);
    throw std::runtime_error("parsing error in " + fileName + ":" + std::to_string(token.line) + ": " + ToUtf8(name) + " expected:\n" + ToUtf8(ErrorLines(token)));
}

} } // namespace soulng::lexer
