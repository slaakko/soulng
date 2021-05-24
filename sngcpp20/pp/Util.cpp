// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/pp/Util.hpp>
#include <sngcpp20/pp/TextTokens.hpp>
#include <algorithm>

namespace sngcpp::pp {

bool IsPPLine(const Lexeme& line)
{
    const char32_t* p = line.begin;
    const char32_t* e = line.end;
    while (p != e && (*p == ' ' || *p == '\t'))
    {
        ++p;
    }
    if (p != e && *p == '#') return true;
    return false;
}

int GetNumberOfNewLines(const Lexeme& lexeme)
{
    int numNewLines = 0;
    const char32_t* p = lexeme.begin;
    const char32_t* e = lexeme.end;
    while (p != e)
    {
        if (*p == '\n') ++numNewLines;
        ++p;
    }
    return numNewLines;
}

std::vector<Token> TrimTextTokens(const std::vector<Token>& tokens)
{
    if (tokens.empty()) return std::vector<Token>();
    std::vector<Token>::const_iterator i = tokens.cbegin();
    while (i != tokens.cend() && i->id == TextTokens::WS)
    {
        ++i;
    }
    if (i == tokens.cend())
    {
        return std::vector<Token>();
    }
    std::vector<Token>::const_iterator e = tokens.cend() - 1;
    while (e != tokens.cbegin() && e->id == TextTokens::WS)
    {
        --e;
    }
    ++e;
    return std::vector<Token>(i, e);
}

std::vector<Token> RemoveWhiteSpace(const std::vector<Token>& tokens)
{
    std::vector<Token> wsRemovedTokens;
    for (const Token& token : tokens)
    {
        if (token.id != TextTokens::WS && token.id != TextTokens::NEWLINE)
        {
            wsRemovedTokens.push_back(token);
        }
    }
    return wsRemovedTokens;
}

Token Stringize(const std::vector<Token>& tokens, PP* pp)
{
    std::u32string value;
    value.append(1, '"');
    for (const Token& token : tokens)
    {
        if (token.id == TextTokens::WS || token.id == TextTokens::NEWLINE)
        {
            value.append(pp->Space().ToString());
        }
        value.append(token.match.ToString());
    }
    value.append(1, '"');
    Lexeme stringized = pp->StringsRef().Install(std::move(value));
    return Token(TextTokens::STRINGLITERAL, stringized, pp->LineNumber());
}

Token Concatenate(const Token& left, const Token& right, PP* pp)
{
    if (left.id == TextTokens::PLACEMARKER && right.id == TextTokens::PLACEMARKER)
    {
        return left;
    }
    else if (left.id == TextTokens::PLACEMARKER)
    {
        return right;
    }
    else if (right.id == TextTokens::PLACEMARKER)
    {
        return left;
    }
    else
    {
        std::u32string value = left.match.ToString();
        value.append(right.match.ToString());
        Lexeme lexeme = pp->StringsRef().Install(std::move(value));
        return Token(left.id, lexeme, left.line);
    }
}

struct IsPlacemarkerToken
{
    bool operator()(const Token& token) const
    {
        return token.id == TextTokens::PLACEMARKER;
    }
};

void RemovePlacemarkers(std::vector<Token>& tokens)
{
    std::vector<Token>::iterator p = std::remove_if(tokens.begin(), tokens.end(), IsPlacemarkerToken());
    tokens.erase(p, tokens.end());
}

std::vector<Token> ConcatenateTokens(const std::vector<Token>& tokens, PP* pp)
{
    std::vector<Token> result;
    int state = 0;
    for (const Token& token : tokens)
    {
        switch (state)
        {
            case 0:
            {
                if (token.id == TextTokens::HASHHASH)
                {
                    state = 1;
                }
                else
                {
                    result.push_back(token);
                }
                break;
            }
            case 1:
            {
                if (token.id != TextTokens::WS)
                {
                    if (!result.empty())
                    {
                        std::vector<Token>::iterator p = result.end() - 1;
                        while (p != result.begin() && p->id == TextTokens::WS)
                        {
                            --p;
                        }
                        *p = Concatenate(*p, token, pp);
                        result.erase(p + 1, result.end());
                    }
                    else
                    {
                        std::string error = "## operator must be preceded by a parameter: ': " + pp->FileName() + ":" + std::to_string(pp->GetLineIndex() + 1);
                        pp->AddError(error);
                        return tokens;
                    }
                    state = 0;
                }
                break;
            }
        }
    }
    if (state == 1)
    {
        std::string error = "## operator must be followed by a parameter: '" + pp->FileName() + ":" + std::to_string(pp->GetLineIndex() + 1);
        pp->AddError(error);
        return tokens;
    }
    RemovePlacemarkers(result);
    return result;
}

bool ContainsHash(const std::vector<Token>& tokens)
{
    for (const Token& token : tokens)
    {
        if (token.id == TextTokens::HASH)
        {
            return true;
        }
    }
    return false;
}

bool ContainsHashHash(const std::vector<Token>& tokens)
{
    for (const Token& token : tokens)
    {
        if (token.id == TextTokens::HASHHASH)
        {
            return true;
        }
    }
    return false;
}

bool IsMSPragma(const std::vector<Token>& tokens, const Lexeme& mspragmaLexeme, std::vector<Token>& pragmaTokens, int& newLines)
{
    int state = 0;
    int parenCount = 0;
    bool result = false;
    for (const Token& token : tokens)
    {
        switch (state)
        {
            case 0:
            {
                if (token.id == TextTokens::WS || token.id == TextTokens::RBRACE)
                {
                    pragmaTokens.push_back(token);
                }
                else if (token.match == mspragmaLexeme)
                {
                    state = 1;
                    result = true;
                }
                else
                {
                    return false;
                }
                break;
            }
            case 1:
            {
                if (token.id == TextTokens::LPAREN)
                {
                    ++parenCount;
                }
                else if (token.id == TextTokens::RPAREN)
                {
                    --parenCount;
                    if (parenCount == 0)
                    {
                        state = 2;
                    }
                }
                break;
            }
            case 2:
            {
                pragmaTokens.push_back(token);
                if (token.id == TextTokens::NEWLINE)
                {
                    ++newLines;
                }
                break;
            }
        }
    }
    return result;
}

} // namespace sngcpp::pp
