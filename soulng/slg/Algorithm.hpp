// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SLG_ALGORITHM_INCLUDED
#define SOULNG_SLG_ALGORITHM_INCLUDED
#include <soulng/slg/LexerContext.hpp>

namespace soulng { namespace slg {

std::vector<NfaState*> EpsilonClosure(const std::vector<NfaState*>& states);
std::vector<NfaState*> EpsilonClosure(NfaState* state);
std::vector<NfaState*> Move(const std::vector<NfaState*>& states, char32_t c);
Dfa Compile(LexerContext& lexerContext, Nfa& nfa);

} } // namespace soulng::slg

#endif // SOULNG_SLG_ALGORITHM_INCLUDED
