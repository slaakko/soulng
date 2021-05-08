// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/parser/IdentifierTokenParser.hpp>
#include <sngcpp20/parser/LiteralTokenParser.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp::par {

using namespace soulng::unicode;

IdentifierNode* ParseIdentifier(const SourcePos& sourcePos, const std::string& fileName, const std::u32string& rep)
{
    std::u32string s;
    const char32_t* p = rep.c_str();
    const char32_t* e = rep.c_str() + rep.size();
    bool valid = true;
    while (p != e && valid)
    {
        char32_t value = '\0';
        if (*p == '\\')
        {
            ++p;
            if (p != e)
            {
                if (*p == 'u')
                {
                    ++p;
                    for (int i = 0; i < 4; ++i)
                    {
                        if (p != e && IsHexChar(*p))
                        {
                            value = 16 * value + ParseHexChar(*p);
                        }
                        else
                        {
                            valid = false;
                            break;
                        }
                        ++p;
                    }
                }
                else if (*p == 'U')
                {
                    ++p;
                    for (int i = 0; i < 8; ++i)
                    {
                        if (p != e && IsHexChar(*p))
                        {
                            value = 16 * value + ParseHexChar(*p);
                        }
                        else
                        {
                            valid = false;
                            break;
                        }
                        ++p;
                    }
                }
            }
        }
        else
        {
            value = *p;
            ++p;
        }
        s.append(1, value);
    }
    if (p != e || !valid)
    {
        throw std::runtime_error("invalid identifier in '" + fileName + "' at line " + std::to_string(sourcePos.line) + ": " + ToUtf8(rep));
    }
    return new IdentifierNode(sourcePos, s);
}

} // namespace sngcpp::par