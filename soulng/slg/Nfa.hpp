// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SLG_NFA_INCLUDED
#define SOULNG_SLG_NFA_INCLUDED
#include <soulng/slg/Symbol.hpp>
#include <set>

namespace soulng { namespace slg {

class NfaState;
class LexerContext;

class NfaEdge
{
public:
    NfaEdge(Symbol* symbol_, NfaState* next_);
    Symbol* GetSymbol() const { return symbol; }
    NfaState* Next() const { return next; }
private:
    Symbol* symbol;
    NfaState* next;
};

class NfaState
{
public:
    NfaState(int id_, int statementIndex_);
    int Id() const { return id; }
    int StatementIndex() const { return statementIndex; }
    void SetStatementIndex(int statementIndex_) { statementIndex = statementIndex_; }
    bool Accept() const { return accept; }
    void SetAccept(bool accept_) { accept = accept_; }
    const std::vector<NfaEdge>& Edges() const { return edges; }
    void SetEdges(const std::vector<NfaEdge>& edges_);
    void AddEdge(const NfaEdge& edge);
    std::vector<NfaState*> Next(char32_t c) const;
private:
    int id;
    int statementIndex;
    bool accept;
    std::vector<NfaEdge> edges;
};

class Nfa
{
public:
    Nfa();
    Nfa(NfaState* start_, NfaState* end_);
    NfaState* Start() const { return start; }
    void SetStart(NfaState* start_) { start = start_; }
    NfaState* End() const { return end; }
    void SetEnd(NfaState* end_) { end = end_; }
private:
    NfaState* start;
    NfaState* end;
};

Nfa MakeNfa(LexerContext& lexerContext, Symbol* symbol);
Nfa Cat(const Nfa& left, const Nfa& right);
Nfa Alt(LexerContext& lexerContext, const Nfa& left, const Nfa& right);
Nfa Kleene(LexerContext& lexerContext, const Nfa& nfa);
Nfa Pos(LexerContext& lexerContext, const Nfa& nfa);
Nfa Opt(LexerContext& lexerContext, const Nfa& nfa);

} } // namespace soulng::slg

#endif // SOULNG_SLG_NFA_INCLUDED
