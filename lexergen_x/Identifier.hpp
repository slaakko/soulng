// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_LEXERGEN_IDENTIFIER_INCLUDED
#define SOULNG_LEXERGEN_IDENTIFIER_INCLUDED
#include <soulng/lexergen/LexerContext.hpp>

namespace soulng { namespace lexergen {

void MakeAsciiIdentifierClasses(LexerContext& lexerContext);
void MakeUnicodeIdentifierClasses(LexerContext& lexerContext);

} } // namespace soulng::lexergen

#endif // SOULNG_LEXERGEN_IDENTIFIER_INCLUDED
