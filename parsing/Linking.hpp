// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_PARSING_LINKING_INCLUDED
#define SOULNG_PARSING_LINKING_INCLUDED
#include <soulng/parsing/Visitor.hpp>

namespace soulng { namespace parsing {

class Grammar;
class Rule;
class ParsingDomain;

class PARSING_API LinkerVisitor : public Visitor
{
public:
    LinkerVisitor();
    void BeginVisit(Grammar& grammar) override;
    void EndVisit(Grammar& grammar) override;
    void Visit(RuleLink& link) override;
    void BeginVisit(Rule& rule) override;
    void EndVisit(Rule& rule) override;
    void BeginVisit(ActionParser& parser) override;
    void Visit(NonterminalParser& parser) override;
    void Visit(KeywordParser& parser) override;
    void Visit(KeywordListParser& parser) override;
private:
    Grammar* currentGrammar;
    Rule* currentRule;
    int actionNumber;
};

PARSING_API void Link(ParsingDomain* parsingDomain);
PARSING_API void ExpandCode(ParsingDomain* parsingDomain);

} } // namespace soulng::parsing

#endif // SOULNG_PARSING_LINKING_INCLUDED
