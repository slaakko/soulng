// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SLG_TOKEN_VALUE_PARSERS_INCLUDED
#define SOULNG_SLG_TOKEN_VALUE_PARSERS_INCLUDED
#include <soulng/lexer/Token.hpp>

namespace soulng { namespace slg {

std::u32string MakeStrValue(const std::string& fileName, const soulng::lexer::Token& token);
std::u32string MakeExprStringValue(const std::string& fileName, const soulng::lexer::Token& token);
std::u32string MakePathValue(const std::string& fileName, const soulng::lexer::Token& token);
int MakeActionIntValue(const std::string& fileName, const soulng::lexer::Token& token);
std::u32string MakeExprRefId(const std::string& fileName, const std::u32string& match, int line);
char32_t MakeEscapeValue(const std::string& fileName, const soulng::lexer::Token& token);

} } // namespace soulng::slg

#endif // SOULNG_SLG_TOKEN_VALUE_PARSERS_INCLUDED
