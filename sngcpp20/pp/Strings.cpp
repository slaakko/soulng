// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/pp/Strings.hpp>

namespace sngcpp::pp {

Strings::Strings()
{
}

Lexeme Strings::Install(std::u32string&& str)
{
    std::unique_ptr<std::u32string> s(new std::u32string(std::move(str)));
    Lexeme lexeme(s->c_str(), s->c_str() + s->length());
    strings.push_back(std::move(s));
    return lexeme;
}

} // namespace sngcpp::pp
