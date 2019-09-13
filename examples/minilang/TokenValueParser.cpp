#include <minilang/TokenValueParser.hpp>
#include <soulng/util/Unicode.hpp>

namespace minilang {

int64_t ParseIntegerLiteral(const std::string& fileName, const soulng::lexer::Token& token)
{
	int64_t integerLiteral = 0;
	const char32_t* p = token.match.begin;
	const char32_t* e = token.match.end;
	if (p == e)
	{
		throw std::runtime_error("empty integer literal at '" + fileName + "':" + std::to_string(token.line));
	}
	while (p != e && *p >= '0' && *p <= '9')
	{
		integerLiteral = 10 * integerLiteral + *p - '0';
		++p;
	}
	if (p != e)
	{
		throw std::runtime_error("invalid integer literal '" + soulng::unicode::ToUtf8(token.match.ToString()) + "' at '" + fileName + "':" + std::to_string(token.line));
	}
	return integerLiteral;
}

} // namespace minilang
