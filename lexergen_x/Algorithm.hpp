// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_LEXERGEN_ALGORITHM_INCLUDED
#define SOULNG_LEXERGEN_ALGORITHM_INCLUDED
#include <soulng/lexergen/LexerContext.hpp>

namespace soulng { namespace lexergen {

std::vector<NfaState*> EpsilonClosure(const std::vector<NfaState*>& states);
std::vector<NfaState*> EpsilonClosure(NfaState* state);
std::vector<NfaState*> Move(const std::vector<NfaState*>& states, char32_t c);
Dfa Compile(LexerContext& lexerContext, Nfa& nfa);

} } // namespace soulng::lexergen

#endif // SOULNG_LEXERGEN_ALGORITHM_INCLUDED
