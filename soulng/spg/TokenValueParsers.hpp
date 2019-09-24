// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef TOKEN_VALUE_PARSERS_HPP
#define TOKEN_VALUE_PARSERS_HPP
#include <soulng/lexer/Token.hpp>
#include <soulng/spg/CharSet.hpp>

namespace soulng { namespace spg {

std::string MakeFilePath(const std::string& fileName, const soulng::lexer::Token& token);
std::u32string ParseStringLiteral(const std::string& fileName, const soulng::lexer::Token& token);
char32_t ParseCharLiteral(const std::string& fileName, const soulng::lexer::Token& token);
CharSet ParseCharSet(const std::string& fileName, const soulng::lexer::Token& token, const std::u32string& str);

} } // namespapce soulng::spg

#endif // TOKEN_VALUE_PARSERS_HPP
