// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_LEXER_COMMENT_INCLUDED
#define SOULNG_LEXER_COMMENT_INCLUDED
#include <soulng/lexer/LexerApi.hpp>
#include <string>

namespace soulng { namespace lexer {

SOULNG_LEXER_API void RemoveComments(std::u32string& content);

} } // namespace soulng::lexer

#endif // SOULNG_LEXER_COMMENT_INCLUDED
