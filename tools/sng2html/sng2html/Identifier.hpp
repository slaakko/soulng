// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNG2HTML_SNG2HTML_IDENTIFIER_INCLUDED
#define SNG2HTML_SNG2HTML_IDENTIFIER_INCLUDED
#include <sng2html/sng2html/LexerContext.hpp>

namespace sng2html { namespace sng2html {

void MakeAsciiIdentifierClasses(LexerContext& lexerContext);
void MakeUnicodeIdentifierClasses(LexerContext& lexerContext);

} } // namespace sng2html::sng2html

#endif // SNG2HTML_SNG2HTML_IDENTIFIER_INCLUDED
