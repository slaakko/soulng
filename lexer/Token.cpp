// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/lexer/Token.hpp>

namespace soulng { namespace lexer {

bool NoWhiteSpaceBetweenTokens(const Token& first, const Token& second)
{
    if (first.match.end == second.match.begin) return true;
    return false;
}

} } // namespace soulng::lexer
