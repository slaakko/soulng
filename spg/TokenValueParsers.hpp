// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef TOKEN_VALUE_PARSERS_HPP
#define TOKEN_VALUE_PARSERS_HPP
#include <soulng/lexer/Token.hpp>

namespace soulng { namespace spg {

std::string MakeFilePath(const std::string& fileName, const soulng::lexer::Token& token);
std::u32string ParseStringLiteral(const std::string& fileName, const soulng::lexer::Token& token);

} } // namespapce soulng::spg

#endif // TOKEN_VALUE_PARSERS_HPP
