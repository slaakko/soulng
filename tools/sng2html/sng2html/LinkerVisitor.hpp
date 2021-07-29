// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNG2HTML_SNG2HTML_LINKER_VISITOR_INCLUDED
#define SNG2HTML_SNG2HTML_LINKER_VISITOR_INCLUDED
#include <sng2html/sng2html/Visitor.hpp>

namespace sng2html { namespace sng2html {

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
    void Visit(LookaheadParser& parser) override;
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

} } // namespace sng2html::sng2html

#endif // SNG2HTML_SNG2HTML_LINKER_VISITOR_INCLUDED
