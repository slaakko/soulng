// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_PARSING_UTILITY_INCLUDED
#define SOULNG_PARSING_UTILITY_INCLUDED
#include <soulng/parsing/ParsingApi.hpp>
#include <stdint.h>
#include <string>
#include <vector>

namespace soulng { namespace parsing {

PARSING_API std::string HexEscape(char c);
PARSING_API std::string XmlCharStr(char c);
PARSING_API std::string XmlEscape(const std::string& s);

} } // namespace soulng::parsing

#endif // SOULNG_PARSING_UTILITY_INCLUDED
