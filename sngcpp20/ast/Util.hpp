// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_UTIL_INCLUDED
#define SNGCPP_AST_UTIL_INCLUDED
#include <sngcpp20/ast/AstApi.hpp>
#include <string>

namespace sngcpp::ast {

AST_API std::string UniversalCharacterName(char32_t c);
AST_API std::u32string ToUniversalId(const std::u32string& id);

} // namespace sngcpp::ast

#endif // SNGCPP_AST_UTIL_INCLUDED
