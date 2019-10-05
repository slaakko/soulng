// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/parser/TokenValueParsers.hpp>

namespace sngcpp { namespace cppparser {

void ParseFloatingLiteral(const std::string& fileName, const soulng::lexer::Token& token, double& value, sngcpp::ast::Suffix& suffix)
{

}

void ParseIntegerLiteral(const std::string& fileName, const soulng::lexer::Token& token, uint64_t& value, sngcpp::ast::Base& base, sngcpp::ast::Suffix& suffix)
{

}

void ParseCharacterLiteral(const std::string& fileName, const soulng::lexer::Token& token, std::u32string& value, char32_t& prefix)
{

}

void ParseStringLiteral(const std::string& fileName, const soulng::lexer::Token& token, std::u32string& encodingPrefix, std::u32string& value)
{

}

} } // namespace sngcpp::cppparser
