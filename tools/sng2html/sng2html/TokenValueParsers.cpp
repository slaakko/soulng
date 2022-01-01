// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sng2html/sng2html/TokenValueParsers.hpp>
#include <soulng/util/Unicode.hpp>

namespace sng2html { namespace sng2html {

using namespace soulng::unicode;

void ParseHexChar(const std::string& fileName, char32_t& value, const char32_t*& p, const char32_t* e, const soulng::lexer::Token& token)
{
    if (p != e)
    {
        switch (*p)
        {
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        {
            value = 16 * value + *p - '0';
            break;
        }
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
        {
            value = 16 * value + 10 + *p - 'A';
            break;
        }
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
        {
            value = 16 * value + 10 + *p - 'a';
            break;
        }
        }
        ++p;
    }
    else
    {
        throw std::runtime_error("hex character expected at " + fileName + ":" + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
    }
}

char32_t ParseEscape(const std::string& fileName, const char32_t*& p, const char32_t* e, const soulng::lexer::Token& token)
{
    char32_t value = '\0';
    if (p != e && (*p == 'x' || *p == 'X'))
    {
        ++p;
        while (p != e && ((*p >= '0' && *p <= '9') || (*p >= 'a' && *p <= 'f') || (*p >= 'A' && *p <= 'F')))
        {
            ParseHexChar(fileName, value, p, e, token);
        }
    }
    else if (p != e && (*p == 'd' || *p == 'D'))
    {
        ++p;
        while (p != e && *p >= '0' && *p <= '9')
        {
            value = 10 * value + (*p - '0');
            ++p;
        }
    }
    else if (p != e && (*p >= '0' && *p <= '7'))
    {
        while (p != e && *p >= '0' && *p <= '7')
        {
            value = 8 * value + (*p - '0');
            ++p;
        }
    }
    else if (p != e && *p == 'u')
    {
        ++p;
        ParseHexChar(fileName, value, p, e, token);
        ParseHexChar(fileName, value, p, e, token);
        ParseHexChar(fileName, value, p, e, token);
        ParseHexChar(fileName, value, p, e, token);
    }
    else if (p != e && *p == 'U')
    {
        ++p;
        ParseHexChar(fileName, value, p, e, token);
        ParseHexChar(fileName, value, p, e, token);
        ParseHexChar(fileName, value, p, e, token);
        ParseHexChar(fileName, value, p, e, token);
        ParseHexChar(fileName, value, p, e, token);
        ParseHexChar(fileName, value, p, e, token);
        ParseHexChar(fileName, value, p, e, token);
        ParseHexChar(fileName, value, p, e, token);
    }
    else if (p != e)
    {
        switch (*p)
        {
            case 'a': value = '\a'; break;
            case 'b': value = '\b'; break;
            case 'f': value = '\f'; break;
            case 'n': value = '\n'; break;
            case 'r': value = '\r'; break;
            case 't': value = '\t'; break;
            case 'v': value = '\v'; break;
            default: value = *p; break;
        }
        ++p;
    }
    return value;
}

std::u32string MakeStrValue(const std::string& fileName, const soulng::lexer::Token& token)
{
    std::u32string strValue;
    const char32_t* p = token.match.begin;
    const char32_t* e = token.match.end;
    if (p != e && *p == '"')
    {
        ++p;
    }
    while (p != e && *p != '\r' && *p != '\n' && *p != '"')
    {
        if (*p == '\\')
        {
            ++p;
            strValue.append(1, ParseEscape(fileName, p, e, token));
        }
        else
        {
            strValue.append(1, *p);
            ++p;
        }
    }
    if (p != e && *p == '"')
    {
        ++p;
    }
    if (p != e)
    {
        throw std::runtime_error("invalid string literal at " + fileName + ":" + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
    }
    return strValue;
}

std::u32string MakeExprStringValue(const std::string& fileName, const soulng::lexer::Token& token)
{
    std::u32string strValue;
    const char32_t* p = token.match.begin;
    const char32_t* e = token.match.end;
    if (p != e && *p == '"')
    {
        ++p;
    }
    while (p != e && *p != '\r' && *p != '\n' && *p != '"')
    {
        if (*p == '\\')
        {
            ++p;
            if (p != e && *p == '"')
            {
                strValue.append(1, '"');
                ++p;
            }
            else
            {
                strValue.append(1, '\\');
                strValue.append(1, *p);
                ++p;
            }
        }
        else
        {
            strValue.append(1, *p);
            ++p;
        }
    }
    if (p != e && *p == '"')
    {
        ++p;
    }
    if (p != e)
    {
        throw std::runtime_error("invalid expression string literal at " + fileName + ":" + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
    }
    return strValue;
}

std::u32string MakePathValue(const std::string& fileName, const soulng::lexer::Token& token)
{
    std::u32string pathValue;
    const char32_t* p = token.match.begin;
    const char32_t* e = token.match.end;
    if (p != e && *p == '<')
    {
        ++p;
    }
    while (p != e && *p != '\r' && *p != '\n' && *p != '>')
    {
        pathValue.append(1, *p);
        ++p;
    }
    if (p != e && *p == '>')
    {
        ++p;
    }
    if (p != e)
    {
        throw std::runtime_error("invalid path literal at " + fileName + ":" + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
    }
    return pathValue;
}

int MakeActionIntValue(const std::string& fileName, const soulng::lexer::Token& token)
{
    int actionIntValue = 0;
    const char32_t* p = token.match.begin;
    const char32_t* e = token.match.end;
    if (p == e)
    {
        throw std::runtime_error("invalid action integer value at " + fileName + ":" + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
    }
    while (p != e && *p >= '0' && *p <= '9')
    {
        actionIntValue = 10 * actionIntValue + (*p - '0');
        ++p;
    }
    if (p != e)
    {
        throw std::runtime_error("invalid action integer value at " + fileName + ":" + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
    }
    return actionIntValue;
}

std::u32string MakeExprRefId(const std::string& fileName, const std::u32string& match, int line)
{
    std::u32string exprRefId;
    const char32_t* p = match.c_str();
    const char32_t* e = match.c_str() + match.length();
    if (p != e && *p == '{')
    {
        ++p;
    }
    while (p != e && *p != '\r' && *p != '\n' && *p != '}')
    {
        exprRefId.append(1, *p);
        ++p;
    }
    if (p != e && *p == '}')
    {
        ++p;
    }
    if (p != e)
    {
        throw std::runtime_error("invalid expression reference at " + fileName + ":" + std::to_string(line) + ": " + ToUtf8(match));
    }
    return exprRefId;
}

char32_t MakeEscapeValue(const std::string& fileName, const soulng::lexer::Token& token)
{
    char32_t escapeValue = '\0';
    const char32_t* p = token.match.begin;
    const char32_t* e = token.match.end;
    if (p != e && *p == '\\')
    {
        ++p;
    }
    escapeValue = ParseEscape(fileName, p, e, token);
    if (p != e)
    {
        throw std::runtime_error("invalid escape at " + fileName + ":" + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
    }
    return escapeValue;
}

std::string MakeFilePath(const std::string& fileName, const soulng::lexer::Token& token)
{
    std::u32string s;
    const char32_t* p = token.match.begin;
    const char32_t* e = token.match.end;
    if (p != e && *p == '<')
    {
        ++p;
    }
    while (p != e && *p != '>')
    {
        s.append(1, *p);
        ++p;
    }
    if (p != e && *p == '>')
    {
        ++p;
    }
    if (p != e)
    {
        throw std::runtime_error("invalid file path at " + fileName + ":" + std::to_string(token.line) + " : '" + ToUtf8(token.match.ToString()) + "'");
    }
    return ToUtf8(s);
}

std::u32string ParseStringLiteral(const std::string& fileName, const soulng::lexer::Token& token)
{
    std::u32string stringLiteral;
    const char32_t* p = token.match.begin;
    const char32_t* e = token.match.end;
    if (p != e && *p == '"')
    {
        ++p;
        while (p != e && *p != '\r' && *p != '\n' && *p != '"')
        {
            if (*p == '\\')
            {
                ++p;
                stringLiteral.append(1, ParseEscape(fileName, p, e, token));
            }
            else
            {
                stringLiteral.append(1, *p);
                ++p;
            }
        }
        if (p != e && *p == '"')
        {
            ++p;
        }
        if (p != e)
        {
            throw std::runtime_error("invalid string literal at " + fileName + ":" + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
        }
    }
    else
    {
        throw std::runtime_error("invalid string literal at " + fileName + ":" + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
    }
    return stringLiteral;
}

char32_t ParseCharLiteral(const std::string& fileName, const soulng::lexer::Token& token)
{
    char32_t charLit = '\0';
    const char32_t* p = token.match.begin;
    const char32_t* e = token.match.end;
    bool first = true;
    if (p != e && *p == '\'')
    {
        ++p;
        while (p != e && *p != '\r' && *p != '\n' && *p != '\'')
        {
            if (*p == '\\')
            {
                ++p;
                if (first)
                {
                    charLit = ParseEscape(fileName, p, e, token);
                    first = false;
                }
                else
                {
                    throw std::runtime_error("invalid character literal at " + fileName + ":" + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
                }
            }
            else
            {
                if (first)
                {
                    charLit = *p;
                    first = false;
                }
                else
                {
                    throw std::runtime_error("invalid character literal at " + fileName + ":" + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
                }
                ++p;
            }
        }
        if (p != e && *p == '\'')
        {
            ++p;
        }
        if (p != e)
        {
            throw std::runtime_error("invalid character literal at " + fileName + ":" + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
        }
    }
    else
    {
        throw std::runtime_error("invalid character literal at " + fileName + ":" + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
    }
    return charLit;
}

CharSet ParseCharSet(const std::string& fileName, const soulng::lexer::Token& token, const std::u32string& str)
{
    CharSet set;
    const char32_t* p = str.c_str();
    const char32_t* e = str.c_str() + str.length();
    bool inverse = false;
    if (p != e && *p == '[')
    {
        ++p;
        if (p != e && *p == '^')
        {
            set.SetInverse();
            ++p;
        }
        while (p != e && *p != ']')
        {
            char32_t first = *p;
            char32_t last = first;
            ++p;
            if (p != e && *p != ']')
            {
                if (*p == '-')
                {
                    ++p;
                    if (p != e && *p != ']')
                    {
                        last = *p;
                        ++p;
                    }
                    else
                    {
                        soulng::parser::Range range;
                        range.first = first;
                        range.last = first;
                        set.AddRange(range);
                        first = '-';
                        last = '-';
                    }
                }
            }
            soulng::parser::Range range;
            range.first = first;
            range.last = last;
            set.AddRange(range);
        }
        if (p != e && *p == ']')
        {
            ++p;
        }
        if (p != e)
        {
            throw std::runtime_error("invalid character set literal at " + fileName + ":" + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
        }
    }
    else
    {
        throw std::runtime_error("invalid character set literal at " + fileName + ":" + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
    }
    return set;
}


} } // namespace soulng::slg
