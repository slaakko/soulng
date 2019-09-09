// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/slg/Nfa.hpp>
#include <soulng/slg/LexerContext.hpp>

namespace soulng { namespace slg {

NfaEdge::NfaEdge(Symbol* symbol_, NfaState* next_) : symbol(symbol_), next(next_)
{
}

NfaState::NfaState(int id_, int statementIndex_) : id(id_), statementIndex(statementIndex_),  accept(false)
{
}

void NfaState::SetEdges(const std::vector<NfaEdge>& edges_)
{
    edges = edges_;
}

void NfaState::AddEdge(const NfaEdge& edge)
{
    edges.push_back(edge);
}

std::vector<NfaState*> NfaState::Next(char32_t c) const
{
    std::vector<NfaState*> next;
    for (const auto& edge : edges)
    {
        Symbol* symbol = edge.GetSymbol();
        if (symbol->Match(c))
        {
            next.push_back(edge.Next());
        }
    }
    return next;
}

Nfa::Nfa() : start(nullptr), end(nullptr)
{
}

Nfa::Nfa(NfaState* start_, NfaState* end_) : start(start_), end(end_)
{
}

Nfa MakeNfa(LexerContext& lexerContext, Symbol* symbol)
{
    NfaState* start = lexerContext.MakeNfaState();
    NfaState* end = lexerContext.MakeNfaState();
    end->SetAccept(true);
    start->AddEdge(NfaEdge(symbol, end));
    return Nfa(start, end);
}

Nfa Cat(const Nfa& left, const Nfa& right)
{
    Nfa cat(left);
    NfaState* leftEnd = cat.End();
    leftEnd->SetAccept(false);
    NfaState* rightStart = right.Start();
    rightStart->SetStatementIndex(-1);
    leftEnd->SetEdges(rightStart->Edges());
    cat.SetEnd(right.End());
    return cat;
}

Nfa Alt(LexerContext& lexerContext, const Nfa& left, const Nfa& right)
{
    NfaState* leftStart = left.Start();
    NfaState* leftEnd = left.End();
    NfaState* rightStart = right.Start();
    NfaState* rightEnd = right.End();
    NfaState* start = lexerContext.MakeNfaState();
    NfaState* end = lexerContext.MakeNfaState();
    end->SetAccept(true);
    start->AddEdge(NfaEdge(lexerContext.MakeEpsilon(), leftStart));
    start->AddEdge(NfaEdge(lexerContext.MakeEpsilon(), rightStart));
    Nfa alt;
    alt.SetStart(start);
    leftEnd->SetAccept(false);
    leftEnd->AddEdge(NfaEdge(lexerContext.MakeEpsilon(), end));
    rightEnd->SetAccept(false);
    rightEnd->AddEdge(NfaEdge(lexerContext.MakeEpsilon(), end));
    alt.SetEnd(end);
    return alt;
}

Nfa Kleene(LexerContext& lexerContext, const Nfa& nfa)
{
    Nfa kleene;
    NfaState* start = lexerContext.MakeNfaState();
    NfaState* end = lexerContext.MakeNfaState();
    end->SetAccept(true);
    start->AddEdge(NfaEdge(lexerContext.MakeEpsilon(), end));
    kleene.SetStart(start);
    NfaState* nfaStart = nfa.Start();
    start->AddEdge(NfaEdge(lexerContext.MakeEpsilon(), nfaStart));
    NfaState* nfaEnd = nfa.End();
    nfaEnd->SetAccept(false);
    nfaEnd->AddEdge(NfaEdge(lexerContext.MakeEpsilon(), end));
    nfaEnd->AddEdge(NfaEdge(lexerContext.MakeEpsilon(), nfaStart));
    kleene.SetEnd(end);
    return kleene;
}

Nfa Pos(LexerContext& lexerContext, const Nfa& nfa)
{
    Nfa pos;
    NfaState* start = lexerContext.MakeNfaState();
    NfaState* end = lexerContext.MakeNfaState();
    end->SetAccept(true);
    pos.SetStart(start);
    NfaState* nfaStart = nfa.Start();
    start->AddEdge(NfaEdge(lexerContext.MakeEpsilon(), nfaStart));
    NfaState* nfaEnd = nfa.End();
    nfaEnd->SetAccept(false);
    nfaEnd->AddEdge(NfaEdge(lexerContext.MakeEpsilon(), end));
    nfaEnd->AddEdge(NfaEdge(lexerContext.MakeEpsilon(), nfaStart));
    pos.SetEnd(end);
    return pos;
}

Nfa Opt(LexerContext& lexerContext, const Nfa& nfa)
{
    Nfa opt(nfa);
    opt.Start()->AddEdge(NfaEdge(lexerContext.MakeEpsilon(), opt.End()));
    return opt;
}

} } // namespace soulng::slg
