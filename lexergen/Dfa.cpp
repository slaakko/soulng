// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/lexergen/Dfa.hpp>

namespace soulng { namespace lexergen {

DfaState::DfaState(int id_, const std::vector<NfaState*>& nfaStates_) : id(id_), nfaStates(nfaStates_), next(), marked(false), accept(false), statementIndex(-1)
{
}

void DfaState::AddNext(DfaState* n)
{
    next.push_back(n);
}

DfaState* DfaState::Next(int i) const
{
    if (i >= 0 && i < next.size())
    {
        return next[i];
    }
    else
    {
        return nullptr;
    }
}

void Dfa::AddState(DfaState* state)
{
    states.push_back(state);
}

void Dfa::Finalize()
{
    for (const auto& state : states)
    {
        for (const auto& nfaState : state->NfaStates())
        {
            if (nfaState->Accept())
            {
                state->SetAccept(true);
                if (state->StatementIndex() == -1 || (nfaState->StatementIndex() != -1 && nfaState->StatementIndex() < state->StatementIndex()))
                {
                    state->SetStatementIndex(nfaState->StatementIndex());
                }
            }
        }
    }
}

} } // namespace soulng::lexergen
