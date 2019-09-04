// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SPG_VISITOR_INCLUDED
#define SOULNG_SPG_VISITOR_INCLUDED

namespace soulng { namespace spg {

class EmptyParser;
class TokenParser;
class OptionalParser;
class KleeneParser;
class PositiveParser;
class ExpectationParser;
class GroupingParser;
class SequenceParser;
class AlternativeParser;
class DifferenceParser;
class ListParser;
class ActionParser;
class NonterminalParser;
class RuleParser;
class GrammarParser;
class ParserFile;
class Domain;

class Visitor
{
public:
    virtual ~Visitor();
    virtual void Visit(EmptyParser& parser) {}
    virtual void Visit(TokenParser& parser) {}
    virtual void Visit(OptionalParser& parser) {}
    virtual void Visit(KleeneParser& parser) {}
    virtual void Visit(PositiveParser& parser) {}
    virtual void Visit(ExpectationParser& parser) {}
    virtual void Visit(GroupingParser& parser) {}
    virtual void Visit(SequenceParser& parser) {}
    virtual void Visit(AlternativeParser& parser) {}
    virtual void Visit(DifferenceParser& parser) {}
    virtual void Visit(ListParser& parser) {}
    virtual void Visit(ActionParser& parser) {}
    virtual void Visit(NonterminalParser& parser) {}
    virtual void Visit(RuleParser& parser) {}
    virtual void Visit(GrammarParser& parser) {}
    virtual void Visit(ParserFile& parserFile) {}
    virtual void Visit(Domain& domain) {}
};

} } // namespae soulng::spg

#endif // SOULNG_SPG_VISITOR_INCLUDED
