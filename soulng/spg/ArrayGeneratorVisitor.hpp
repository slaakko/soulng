// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SPG_ARRAY_WRITER_VISITOR_INCLUDED
#define SOULNG_SPG_ARRAY_WRITER_VISITOR_INCLUDED
#include <soulng/spg/Visitor.hpp>
#include <soulng/util/CodeFormatter.hpp>

namespace soulng { namespace spg {

using soulng::util::CodeFormatter;

class ArrayGeneratorVisitor : public Visitor
{
public:
    ArrayGeneratorVisitor(CodeFormatter* formatter_, int& sn_);
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
    void Visit(ActionParser& parser) override;
    void Visit(RuleParser& parser) override;
    void Visit(GrammarParser& parser) override;
    void Visit(ParserFile& parserFile) override;
private:
    CodeFormatter* formatter;
    int& sn;
};

} } // soulng::spg

#endif // SOULNG_SPG_ARRAY_WRITER_VISITOR_INCLUDED
