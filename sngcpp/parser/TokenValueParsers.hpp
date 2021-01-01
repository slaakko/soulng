// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_PARSER_TOKEN_VALUE_PARSERS_INCLUDED
#define SNGCPP_PARSER_TOKEN_VALUE_PARSERS_INCLUDED
#include <sngcpp/parser/ParserApi.hpp>
#include <sngcpp/ast/Literal.hpp>
#include <soulng/lexer/Token.hpp>

namespace sngcpp { namespace cppparser {

void ParseFloatingLiteral(const std::string& fileName, const soulng::lexer::Token& token, double& value, sngcpp::ast::Suffix& suffix);
void ParseIntegerLiteral(const std::string& fileName, const soulng::lexer::Token& token, uint64_t& value, sngcpp::ast::Base& base, sngcpp::ast::Suffix& suffix);
void ParseCharacterLiteral(const std::string& fileName, const soulng::lexer::Token& token, char32_t& value, char32_t& prefix);
void ParseStringLiteral(const std::string& fileName, const soulng::lexer::Token& token, std::u32string& encodingPrefix, std::u32string& value);

} } // namespace sngcpp::cppparser

#endif // SNGCPP_PARSER_TOKEN_VALUE_PARSERS_INCLUDED
