#ifndef MINILANG_TOKEN_VALUE_PARSER_HPP
#define MINILANG_TOKEN_VALUE_PARSER_HPP
#include <soulng/lexer/Token.hpp>
#include <stdint.h>

namespace minilang {

int64_t ParseIntegerLiteral(const std::string& fileName, const soulng::lexer::Token& token);

} // namespace minilang

#endif // MINILANG_TOKEN_VALUE_PARSER_HPP
