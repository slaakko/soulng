// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNG2HTML_SNG2HTML_TOKEN_VALUE_PARSERS_INCLUDED
#define SNG2HTML_SNG2HTML_TOKEN_VALUE_PARSERS_INCLUDED
#include <sng2html/sng2html/CharSet.hpp>
#include <soulng/lexer/Token.hpp>

namespace sng2html { namespace sng2html {

std::u32string MakeStrValue(const std::string& fileName, const soulng::lexer::Token& token);
std::u32string MakeExprStringValue(const std::string& fileName, const soulng::lexer::Token& token);
std::u32string MakePathValue(const std::string& fileName, const soulng::lexer::Token& token);
int MakeActionIntValue(const std::string& fileName, const soulng::lexer::Token& token);
std::u32string MakeExprRefId(const std::string& fileName, const std::u32string& match, int line);
char32_t MakeEscapeValue(const std::string& fileName, const soulng::lexer::Token& token);
std::string MakeFilePath(const std::string& fileName, const soulng::lexer::Token& token);
std::u32string ParseStringLiteral(const std::string& fileName, const soulng::lexer::Token& token);
char32_t ParseCharLiteral(const std::string& fileName, const soulng::lexer::Token& token);
CharSet ParseCharSet(const std::string& fileName, const soulng::lexer::Token& token, const std::u32string& str);

} } // namespace sng2html::sng2html

#endif // SNG2HTML_SNG2HTML_TOKEN_VALUE_PARSERS_INCLUDED
