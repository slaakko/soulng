// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_PP_STRINGS_INCLUDED
#define SNGCPP_PP_STRINGS_INCLUDED
#include <sngcpp20/pp/PPApi.hpp>
#include <soulng/lexer/Lexeme.hpp>
#include <memory>
#include <vector>

namespace sngcpp::pp {

using namespace soulng::lexer;

class PP_API Strings
{
public:
    Strings();
    Strings(const Strings&) = delete;
    Strings(Strings&& that) = default;
    Strings& operator=(const Strings&) = delete;
    Strings& operator=(Strings&&) = default;
    Lexeme Install(std::u32string&& str);
private:
    std::vector<std::unique_ptr<std::u32string>> strings;
};

} // namespace sngcpp::pp

#endif // SNGCPP_PP_STRINGS_INCLUDED
