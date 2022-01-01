// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Util.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp::ast {

using namespace soulng::unicode;

std::string UniversalCharacterName(char32_t c)
{
    std::string s;
    s.append("\\");
    if (c >= 0 && c <= 0xFFFF)
    {
        s.append("u").append(ToHexString(static_cast<uint16_t>(c)));
    }
    else
    {
        s.append("U").append(ToHexString(static_cast<uint32_t>(c)));
    }
    return s;
}

std::u32string ToUniversalId(const std::u32string& id)
{
    std::u32string s;
    for (char32_t c : id)
    {
        if (c >= 32 && c < 127)
        {
            s.append(1, c);
        }
        else
        {
            s.append(ToUtf32(UniversalCharacterName(c)));
        }
    }
    return s;
}

} // namespace sngcpp::ast
