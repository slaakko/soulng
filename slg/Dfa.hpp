// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SLG_DFA_INCLUDED
#define SOULNG_SLG_DFA_INCLUDED
#include <soulng/slg/Nfa.hpp>

namespace soulng { namespace slg {

class DfaState
{
public:
    DfaState(int id_, const std::vector<NfaState*>& nfaStates_);
    int Id() const { return id; }
    bool IsMarked() const { return marked; }
    void Mark() { marked = true; }
    bool Accept() const { return accept; }
    void SetAccept(bool accept_) { accept = accept_; }
    int StatementIndex() const { return statementIndex; }
    void SetStatementIndex(int index) { statementIndex = index; }
    const std::vector<NfaState*>& NfaStates() const { return nfaStates; }
    void AddNext(DfaState* next);
    DfaState* Next(int i) const;
private:
    int id;
    std::vector<NfaState*> nfaStates;
    std::vector<DfaState*> next;
    bool marked;
    bool accept;
    int statementIndex;
};

class Dfa
{
public:
    void AddState(DfaState* state);
    const std::vector<DfaState*>& States() const { return states; }
    void Finalize();
private:
    std::vector<DfaState*> states;
};

} } // namespace soulng::slg

#endif // SOULNG_SLG_DFA_INCLUDED
