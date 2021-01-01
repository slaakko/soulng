// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SLG_IDENTIFIER_INCLUDED
#define SOULNG_SLG_IDENTIFIER_INCLUDED
#include <soulng/slg/LexerContext.hpp>

namespace soulng { namespace slg {

void MakeAsciiIdentifierClasses(LexerContext& lexerContext);
void MakeUnicodeIdentifierClasses(LexerContext& lexerContext);

} } // namespace soulng::slg

#endif // SOULNG_SLG_IDENTIFIER_INCLUDED
