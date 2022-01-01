// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SPG_FIRST_COMPUTER_VISITOR_INCLUDED
#define SOULNG_SPG_FIRST_COMPUTER_VISITOR_INCLUDED
#include <soulng/spg/Tokens.hpp>
#include <soulng/spg/Visitor.hpp>
#include <unordered_set>

namespace soulng { namespace spg {

class Parser;

class FirstComputerVisitor : public Visitor
{
public:
    FirstComputerVisitor();
    void Visit(EmptyParser& parser) override;
    void Visit(AnyParser& parser) override;
    void Visit(TokenParser& parser) override;
    void Visit(CharParser& parser) override;
    void Visit(StringParser& parser) override;
    void Visit(CharSetParser& parser) override;
    void Visit(OptionalParser& parser) override;
    void Visit(KleeneParser& parser) override;
    void Visit(PositiveParser& parser) override;
    void Visit(ExpectationParser& parser) override;
    void Visit(GroupingParser& parser) override;
    void Visit(SequenceParser& parser) override;
    void Visit(AlternativeParser& parser) override;
    void Visit(DifferenceParser& parser) override;
    void Visit(ListParser& parser) override;
    void Visit(LookaheadParser& parser) override;
    void Visit(ActionParser& parser) override;
    void Visit(NonterminalParser& parser) override;
    void Visit(RuleParser& parser) override;
    void Visit(GrammarParser& parser) override;
    void Visit(ParserFile& parserFile) override;
    void Visit(Domain& domain) override;
    bool Computed(Parser* parser) const { return firstComputed.find(parser) != firstComputed.cend();  }
    void SetComputed(Parser* parser) { firstComputed.insert(parser); }
    bool Changed() const { return changed; }
private:
    Tokens* tokens;
    std::unordered_set<Parser*> firstComputed;
    bool changed;
};

} } // namespae soulng::spg

#endif // SOULNG_SPG_FIRST_COMPUTER_VISITOR_INCLUDED
