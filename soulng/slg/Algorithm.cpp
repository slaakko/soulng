// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/slg/Algorithm.hpp>
#include <algorithm>
#include <iostream>

namespace soulng { namespace slg {

std::vector<NfaState*> EpsilonClosure(const std::vector<NfaState*>& states)
{
    std::vector<NfaState*> stack;
    for (NfaState* state : states)
    {
        stack.push_back(state);
    }
    std::vector<NfaState*> epsilonClosure = states;
    while (!stack.empty())
    {
        NfaState* s = stack.back();
        stack.pop_back();
        std::vector<NfaState*> u = s->Next(eps);
        for (NfaState* v : u)
        {
            if (std::find(epsilonClosure.cbegin(), epsilonClosure.cend(), v) == epsilonClosure.cend())
            {
                epsilonClosure.push_back(v);
                stack.push_back(v);
            }
        }
    }
    return epsilonClosure;
}

std::vector<NfaState*> EpsilonClosure(NfaState* state)
{
    std::vector<NfaState*> states(1, state);
    return EpsilonClosure(states);
}

std::vector<NfaState*> Move(const std::vector<NfaState*>& states, char32_t c)
{
    std::vector<NfaState*> next;
    for (NfaState* state : states)
    {
        std::vector<NfaState*> n = state->Next(c);
        for (NfaState* s : n)
        {
            if (std::find(next.cbegin(), next.cend(), s) == next.cend())
            {
                next.push_back(s);
            }
        }
    }
    return next;
}

Dfa Compile(LexerContext& lexerContext, Nfa& nfa)
{
    Dfa dfa;
    std::vector<NfaState*> start = EpsilonClosure(nfa.Start());
    DfaState* s = lexerContext.MakeDfaState(start);
    s->Mark();
    std::vector<DfaState*> stack;
    stack.push_back(s);
    while (!stack.empty())
    {
        DfaState* state = stack.back();
        stack.pop_back();
        dfa.AddState(state);
        for (Class* cls : lexerContext.Partition())
        {
            if (!cls->Chars().empty())
            {
                char32_t c = cls->Chars().front();
                std::vector<NfaState*> next = EpsilonClosure(Move(state->NfaStates(), c));
                if (next.empty())
                {
                    state->AddNext(nullptr);
                }
                else
                {
                    DfaState* n = lexerContext.MakeDfaState(next);
                    state->AddNext(n);
                    if (!n->IsMarked())
                    {
                        n->Mark();
                        stack.push_back(n);
                    }
                }
            }
        }
    }
    dfa.Finalize();
    return dfa;
}

} } // namespace soulng::slg

