// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/slg/Dfa.hpp>
#include <soulng/slg/LexerContext.hpp>

namespace soulng { namespace slg {

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

void DfaState::Print(LexerContext& context, CodeFormatter& formatter)
{
    std::string str = std::to_string(id);
    str.append("[");
    bool first = true;
    for (NfaState* nfaState : nfaStates)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            str.append(", ");
        }
        str.append(std::to_string(nfaState->Id()));
    }
    str.append("]");
    if (accept)
    {
        str.append(" : ACCEPT");
    }
    if (statementIndex != -1)
    {
        str.append(" : STATEMENT=" + std::to_string(statementIndex));
    }
    formatter.WriteLine(str);
    formatter.IncIndent();
    int n = next.size();
    for (int i = 0; i < n; ++i)
    {
        if (next[i])
        {
            formatter.Write(std::to_string(i));
            if (context.Partition()[i]->Ranges().size() == 1)
            {
                context.Partition()[i]->Print(formatter);
            }
            formatter.WriteLine( + " -> " + std::to_string(next[i]->Id()));
        }
    }
    formatter.DecIndent();
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

void Dfa::Print(LexerContext& lexerContext, CodeFormatter& formatter)
{
    formatter.WriteLine("DFA:");
    for (DfaState* state : states)
    {
        state->Print(lexerContext, formatter);
    }
    formatter.WriteLine();
}

} } // namespace soulng::slg

