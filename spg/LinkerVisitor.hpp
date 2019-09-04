// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SPG_LINKER_VISITOR_INCLUDED
#define SOULNG_SPG_LINKER_VISITOR_INCLUDED
#include <soulng/spg/Visitor.hpp>

namespace soulng { namespace spg {

class Domain;

class LinkerVisitor : public Visitor
{
public:
    enum class Stage { addParsers, resolveRules };
    LinkerVisitor();
    void Visit(OptionalParser& parser) override;
    void Visit(KleeneParser& parser) override;
    void Visit(PositiveParser& parser) override;
    void Visit(ExpectationParser& parser) override;
    void Visit(GroupingParser& parser) override;
    void Visit(SequenceParser& parser) override;
    void Visit(AlternativeParser& parser) override;
    void Visit(DifferenceParser& parser) override;
    void Visit(ListParser& parser) override;
    void Visit(ActionParser& parser) override;
    void Visit(NonterminalParser& parser) override;
    void Visit(RuleParser& parser) override;
    void Visit(GrammarParser& parser) override;
    void Visit(ParserFile& parserFile) override;
    void Visit(Domain& domain) override;
private:
    Domain* domain;
    Stage stage;
    GrammarParser* currentParser;
    RuleParser* currentRule;
};

} } // namespae soulng::spg

#endif // SOULNG_SPG_LINKER_VISITOR_INCLUDED
