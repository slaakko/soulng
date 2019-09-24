// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SPG_CODE_GENERATOR_VISITOR_INCLUDED
#define SOULNG_SPG_CODE_GENERATOR_VISITOR_INCLUDED
#include <soulng/spg/NonterminalInfo.hpp>
#include <soulng/spg/Visitor.hpp>
#include <soulng/util/CodeFormatter.hpp>
#include <vector>

namespace soulng { namespace spg {

using soulng::util::CodeFormatter;

std::string ParserGeneratorVersionStr();

class CodeGeneratorVisitor : public Visitor
{
public:
    enum class Stage { generateHeader, generateSource, generateTokenSwitch, beginGenerateTokenSwitch, endGenerateTokenSwitch };
    CodeGeneratorVisitor(bool verbose_);
    void Visit(EmptyParser& parser) override;
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
    void Visit(ActionParser& parser) override;
    void Visit(NonterminalParser& parser) override;
    void Visit(RuleParser& parser) override;
    void Visit(GrammarParser& parser) override;
    void Visit(ParserFile& parserFile) override;
    void Visit(Domain& domain) override;
private:
    bool verbose;
    Domain* domain;
    GrammarParser* currentParser;
    RuleParser* currentRule;
    Stage stage;
    CodeFormatter* formatter;
    std::string lexerTypeName;
    std::vector<NonterminalInfo> nonterminalInfos;
    int parentMatchNumber;
    int setParentMatchNumber;
    int sn;
};

} } // namespae soulng::spg

#endif // SOULNG_SPG_CODE_GENERATOR_VISITOR_INCLUDED
