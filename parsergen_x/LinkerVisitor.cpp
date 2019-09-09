// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/parsergen/LinkerVisitor.hpp>
#include <soulng/parsergen/Domain.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/Util.hpp>

namespace soulng { namespace parsergen {

using namespace soulng::unicode;
using namespace soulng::util;

LinkerVisitor::LinkerVisitor() : domain(nullptr), currentGrammar(nullptr), currentRule(nullptr), stage(Stage::addGrammars)
{
}

void LinkerVisitor::Visit(OptionalParser& parser)
{
    parser.Child()->Accept(*this);
}

void LinkerVisitor::Visit(KleeneParser& parser)
{
    parser.Child()->Accept(*this);
}

void LinkerVisitor::Visit(PositiveParser& parser)
{
    parser.Child()->Accept(*this);
}

void LinkerVisitor::Visit(ExpectationParser& parser)
{
    parser.Child()->Accept(*this);
}

void LinkerVisitor::Visit(GroupingParser& parser)
{
    parser.Child()->Accept(*this);
}

void LinkerVisitor::Visit(SequenceParser& parser)
{
    parser.Left()->Accept(*this);
    parser.Right()->Accept(*this);
}

void LinkerVisitor::Visit(AlternativeParser& parser)
{
    parser.Left()->Accept(*this);
    parser.Right()->Accept(*this);
}

void LinkerVisitor::Visit(DifferenceParser& parser)
{
    parser.Left()->Accept(*this);
    parser.Right()->Accept(*this);
}

void LinkerVisitor::Visit(ListParser& parser)
{
    parser.Child()->Accept(*this);
}

void LinkerVisitor::Visit(ActionParser& parser)
{
    parser.Child()->Accept(*this);
}

void LinkerVisitor::Visit(NonterminalParser& parser)
{
    currentRule->AddNonterminal(&parser);
    RuleParser* rule = currentGrammar->GetRule(parser.RuleName());
    parser.SetRule(rule);
    if (rule->Parameters().size() != parser.Arguments().size())
    {
        throw std::runtime_error("Rule '" + ToUtf8(rule->Name()) + "' takes " + std::to_string(rule->Parameters().size()) + " parameters (" +
            std::to_string(parser.Arguments().size()) + " arguments supplied). Detected in parser '" + ToUtf8(currentGrammar->Name()) + "' rule '" + ToUtf8(currentRule->Name()) + "'.");
    }
}

void LinkerVisitor::Visit(RuleParser& parser)
{
    currentRule = &parser;
    parser.Child()->Accept(*this);
}

void LinkerVisitor::Visit(GrammarParser& parser)
{
    if (stage == Stage::addGrammars)
    {
        domain->AddGrammar(&parser);
    }
    else if (stage == Stage::resolveRules)
    {
        currentGrammar = &parser;
        for (const auto& u : parser.Usings())
        {
            std::vector<std::u32string> components = Split(u, '.');
            if (components.size() != 2)
            {
                throw std::runtime_error("invalid using '" + ToUtf8(u) + "' in parser '" + ToUtf8(parser.Name()) + "'");
            }
            const std::u32string& grammarName = components[0];
            const std::u32string& ruleName = components[1];
            GrammarParser* targetGrammar = domain->GetGrammar(grammarName);
            RuleParser* rule = targetGrammar->GetRule(ruleName);
            parser.MapRule(rule);
        }
        for (const auto& rule : parser.Rules())
        {
            rule->Accept(*this);
        }
        for (const auto& ruleInfo : parser.RuleInfos())
        {
            RuleParser* rule = parser.GetRule(ruleInfo.first);
            rule->SetInfo(ruleInfo.second);
        }
    }
}

void LinkerVisitor::Visit(ParserFile& parserFile)
{
    for (const auto& grammar : parserFile.Grammars())
    {
        grammar->Accept(*this);
    }
}

void LinkerVisitor::Visit(Domain& domain)
{
    this->domain = &domain;
    stage = Stage::addGrammars;
    for (const auto& parserFile : domain.ParserFiles())
    {
        parserFile->Accept(*this);
    }
    stage = Stage::resolveRules;
    for (const auto& parserFile : domain.ParserFiles())
    {
        parserFile->Accept(*this);
    }
}

} } // namespae soulng::parsergen
