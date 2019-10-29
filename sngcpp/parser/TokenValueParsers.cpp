// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/parser/TokenValueParsers.hpp>
#include <soulng/util/Unicode.hpp>
#include <sstream>

namespace sngcpp { namespace cppparser {

using namespace soulng::unicode;

void ParseFloatingLiteral(const std::string& fileName, const soulng::lexer::Token& token, double& value, sngcpp::ast::Suffix& suffix)
{
    value = 0.0;
    suffix = sngcpp::ast::Suffix::none;
    const char32_t* p = token.match.begin;
    const char32_t* e = token.match.end;
    while (p != e && *p >= '0' && *p <= '9')
    {
        ++p;
    }
    if (p != e && *p == '.')
    {
        ++p;
    }
    while (p != e && *p >= '0' && *p <= '9')
    {
        ++p;
    }
    if (p != e && (*p == 'e' || *p == 'E'))
    {
        ++p;
    }
    if (p != e && (*p == '+' || *p == '-'))
    {
        ++p;
    }
    while (p != e && *p >= '0' && *p <= '9')
    {
        ++p;
    }
    if (p != e)
    {
        std::string s = ToUtf8(std::u32string(p, e));
        std::stringstream sstream;
        sstream.str(s);
        sstream >> value;
        if (!sstream)
        {
            throw std::runtime_error("invalid floating point literal in '" + fileName + "' at line " + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
        }
        if (p != e && (*p == 'f' || *p == 'F'))
        {
            suffix = sngcpp::ast::Suffix::f;
            ++p;
        }
        else if (p != e && (*p == 'l' || *p == 'L'))
        {
            suffix = sngcpp::ast::Suffix::l;
            ++p;
        }
    }
    if (p != e)
    {
        throw std::runtime_error("invalid floating point literal in '" + fileName + "' at line " + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
    }
}

void ParseIntegerLiteral(const std::string& fileName, const soulng::lexer::Token& token, uint64_t& value, sngcpp::ast::Base& base, sngcpp::ast::Suffix& suffix)
{
    value = 0;
    base = sngcpp::ast::Base::decimal;
    suffix = sngcpp::ast::Suffix::none;
    const char32_t* p = token.match.begin;
    const char32_t* e = token.match.end;
    if (p != e && *p == '0')
    {
        base = sngcpp::ast::Base::octal;
        ++p;
        if (p != e && (*p == 'x' || *p == 'X'))
        {
            base = sngcpp::ast::Base::hex;
            ++p;
            while (p != e && ((*p >= '0' && *p <= '9') || (*p >= 'a' && *p <= 'f') || (*p >= 'A' && *p <= 'F')))
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
        }
        else
        {
            while (p != e && *p >= '0' && *p <= '7')
            {
                value = 8 * value + *p - '0';
                ++p;
            }
        }
    }
    else 
    {
        base = sngcpp::ast::Base::decimal;
        while (p != e && *p >= '0' && *p <= '9')
        {
            value = 10 * value + *p - '0';
            ++p;
        }
    }
    if (p != e && (*p == 'u' || *p == 'U'))
    {
        suffix = sngcpp::ast::Suffix::u;
        ++p;
    }
    if (p != e && (*p == 'l' || *p == 'L'))
    {
        ++p;
        if (p != e && (*p == 'l' || *p == 'L'))
        {
            suffix = suffix | sngcpp::ast::Suffix::ll;
            ++p;
        }
        else
        {
            suffix = suffix | sngcpp::ast::Suffix::l;
        }
        if (p != e && (*p == 'u' || *p == 'U'))
        {
            suffix = suffix | sngcpp::ast::Suffix::u;
            ++p;
        }
    }
    if (p != e)
    {
        throw std::runtime_error("invalid integer literal in '" + fileName + "' at line " + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
    }
}

void ParseHexChar(const std::string& fileName, const soulng::lexer::Token& token, const char32_t*& p, const char32_t* e, char32_t& value)
{
    if (p != e && ((*p >= '0' && *p <= '9') || (*p >= 'a' && *p <= 'f') || (*p >= 'A' && *p <= 'F')))
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
        throw std::runtime_error("hexadecimal character expected in '" + fileName + "' at line " + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
    }
}

void ParseEscape(const std::string& fileName, const soulng::lexer::Token& token, const char32_t*& p, const char32_t* e, char32_t& value)
{
    if (p != e && *p == '\\')
    {
        ++p;
        if (p != e && *p == 'x')
        {
            ++p;
            ParseHexChar(fileName, token, p, e, value);
            ParseHexChar(fileName, token, p, e, value);
        }
        else if (p != e && *p == 'u')
        {
            ++p;
            ParseHexChar(fileName, token, p, e, value);
            ParseHexChar(fileName, token, p, e, value);
            ParseHexChar(fileName, token, p, e, value);
            ParseHexChar(fileName, token, p, e, value);
        }
        else if (p != e && *p == 'U')
        {
            ++p;
            ParseHexChar(fileName, token, p, e, value);
            ParseHexChar(fileName, token, p, e, value);
            ParseHexChar(fileName, token, p, e, value);
            ParseHexChar(fileName, token, p, e, value);
            ParseHexChar(fileName, token, p, e, value);
            ParseHexChar(fileName, token, p, e, value);
            ParseHexChar(fileName, token, p, e, value);
            ParseHexChar(fileName, token, p, e, value);
        }
        else if (p != e && *p >= '0' && *p <= '7')
        {
            value = *p - '0';
            ++p;
            if (p != e && *p >= '0' && *p <= '7')
            {
                value = 8 * value + *p - '0';
                ++p;
                if (p != e && *p >= '0' && *p <= '7')
                {
                    value = 8 * value + *p - '0';
                    ++p;
                }
            }
        }
        else if (p != e)
        {
            switch (*p)
            {
                case 'a': value = '\a'; ++p; break;
                case 'b': value = '\b'; ++p; break;
                case 'f': value = '\f'; ++p; break;
                case 'n': value = '\n'; ++p; break;
                case 'r': value = '\r'; ++p; break;
                case 't': value = '\t'; ++p; break;
                case 'v': value = '\v'; ++p; break;
                case '\\': value = '\\'; ++p; break;
                case '?': value = '?'; ++p; break;
                default: value = *p; ++p; break;
            }
        }
    }
    else
    {
        throw std::runtime_error("invalid escape in '" + fileName + "' at line " + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
    }
}

void ParseCharacterLiteral(const std::string& fileName, const soulng::lexer::Token& token, char32_t& value, char32_t& prefix)
{
    value = '\0';
    prefix = '\0';
    const char32_t* p = token.match.begin;
    const char32_t* e = token.match.end;
    if (p != e && *p == 'u')
    {
        prefix = *p;
        ++p;
    }
    else if (p != e && *p == 'U')
    {
        prefix = *p;
        ++p;
    }
    else if (p != e && *p == 'L')
    {
        prefix = *p;
        ++p;
    }
    if (p != e && *p == '\'')
    {
        ++p;
        if (p != e && *p == '\\')
        {
            ParseEscape(fileName, token, p, e, value);
        }
        else if (p != e)
        {
            value = *p;
            ++p;
        }
        if (p != e && *p == '\'')
        {
            ++p;
        }
        if (p != e)
        {
            throw std::runtime_error("invalid character literal in '" + fileName + "' at line " + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
        }
    }
    else
    {
        throw std::runtime_error("invalid character literal in '" + fileName + "' at line " + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
    }
}

void ParseStringLiteral(const std::string& fileName, const soulng::lexer::Token& token, std::u32string& encodingPrefix, std::u32string& value)
{
    encodingPrefix.clear();
    value.clear();
    const char32_t* p = token.match.begin;
    const char32_t* e = token.match.end;
    if (p != e && *p == 'u')
    {
        ++p;
        if (p != e && *p == '8')
        {
            ++p;
            encodingPrefix = U"u8";
        }
        else
        {
            encodingPrefix = U"u";
        }
    }
    else if (p != e && *p == 'U')
    {
        ++p;
        encodingPrefix = U"U";
    }
    else if (p != e && *p == 'L')
    {
        ++p;
        encodingPrefix = U"L";
    }
    if (p != e && *p == 'R')
    {
        ++p;
        if (p != e && *p == '"')
        {
            ++p;
            while (p != e && *p != '"')
            {
                value.append(1, *p);
                ++p;
            }
            if (p != e && *p == '"')
            {
                ++p;
            }
            if (p != e)
            {
                throw std::runtime_error("invalid string literal in '" + fileName + "' at line " + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
            }
        }
        else
        {
            throw std::runtime_error("invalid string literal in '" + fileName + "' at line " + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
        }
    }
    else if (p != e && *p == '"')
    {
        ++p;
        while (p != e && *p != '"')
        {
            if (*p == '\\')
            {
                char32_t c = '\0';
                ParseEscape(fileName, token, p, e, c);
                value.append(1, c);
            }
            else
            {
                value.append(1, *p);
                ++p;
            }
        }
        if (p != e && *p == '"')
        {
            ++p;
        }
        if (p != e)
        {
            throw std::runtime_error("invalid string literal in '" + fileName + "' at line " + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
        }
    }
    else
    {
        throw std::runtime_error("invalid string literal in '" + fileName + "' at line " + std::to_string(token.line) + ": " + ToUtf8(token.match.ToString()));
    }
}

} } // namespace sngcpp::cppparser
