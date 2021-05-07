// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/spg/LinkerVisitor.hpp>
#include <soulng/spg/Domain.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/Util.hpp>

namespace soulng { namespace spg {

using namespace soulng::unicode;
using namespace soulng::util;

LinkerVisitor::LinkerVisitor() : domain(nullptr), currentParser(nullptr), currentRule(nullptr), stage(Stage::addParsers)
{
}

void LinkerVisitor::Visit(EmptyParser& parser)
{
    if (stage == Stage::resolveRules && domain->Recovery())
    {
        if (currentRule)
        {
            currentRule->AddParser(&parser);
        }
        else
        {
            throw std::runtime_error("current rule not set");
        }
    }
}

void LinkerVisitor::Visit(AnyParser& parser)
{
    if (stage == Stage::resolveRules && domain->Recovery())
    {
        if (currentRule)
        {
            currentRule->AddParser(&parser);
        }
        else
        {
            throw std::runtime_error("current rule not set");
        }
    }
}

void LinkerVisitor::Visit(TokenParser& parser)
{
    if (stage == Stage::resolveRules && domain->Recovery())
    {
        if (currentRule)
        {
            currentRule->AddParser(&parser);
        }
        else
        {
            throw std::runtime_error("current rule not set");
        }
    }
}

void LinkerVisitor::Visit(CharParser& parser)
{
    if (stage == Stage::resolveRules && domain->Recovery())
    {
        if (!domain->GetTokens()->HasToken(static_cast<int>(parser.Chr())))
        {
            Token* token = new Token(ToUtf8(std::u32string(1, parser.Chr())), static_cast<int>(parser.Chr()));
            domain->GetTokens()->AddToken(token);
        }
    }
    if (currentRule)
    {
        currentRule->AddParser(&parser);
    }
    else
    {
        throw std::runtime_error("current rule not set");
    }
}

void LinkerVisitor::Visit(StringParser& parser)
{
    if (stage == Stage::resolveRules && domain->Recovery())
    {
        if (!parser.Str().empty())
        {
            if (!domain->GetTokens()->HasToken(static_cast<int>(parser.Str()[0])))
            {
                Token* token = new Token(ToUtf8(std::u32string(1, parser.Str()[0])), static_cast<int>(parser.Str()[0]));
                domain->GetTokens()->AddToken(token);
            }
        }
    }
    if (currentRule)
    {
        currentRule->AddParser(&parser);
    }
    else
    {
        throw std::runtime_error("current rule not set");
    }
}

void LinkerVisitor::Visit(CharSetParser& parser)
{
    if (stage == Stage::resolveRules && domain->Recovery())
    {
        if (parser.Set().Inverse())
        {
            if (!domain->InverseAdded())
            {
                domain->SetInverseAdded();
                for (int i = 32; i <= 65500; ++i)
                {
                    if (!domain->GetTokens()->HasToken(i))
                    {
                        Token* token = new Token(ToUtf8(std::u32string(1, char32_t(i))), i);
                        domain->GetTokens()->AddToken(token);
                    }
                }
            }
        }
        else
        {
            for (const soulng::parser::Range& range : parser.Set().Ranges())
            {
                for (int i = range.first; i <= range.last; ++i)
                {
                    if (!domain->GetTokens()->HasToken(i))
                    {
                        Token* token = new Token(ToUtf8(std::u32string(1, char32_t(i))), i);
                        domain->GetTokens()->AddToken(token);
                    }
                }
            }
        }
    }
    if (currentRule)
    {
        currentRule->AddParser(&parser);
    }
    else
    {
        throw std::runtime_error("current rule not set");
    }
}

void LinkerVisitor::Visit(OptionalParser& parser)
{
    if (stage == Stage::resolveRules && domain->Recovery())
    {
        if (currentRule)
        {
            currentRule->AddParser(&parser);
        }
        else
        {
            throw std::runtime_error("current rule not set");
        }
    }
    parser.Child()->Accept(*this);
}

void LinkerVisitor::Visit(KleeneParser& parser)
{
    if (stage == Stage::resolveRules && domain->Recovery())
    {
        if (currentRule)
        {
            currentRule->AddParser(&parser);
        }
        else
        {
            throw std::runtime_error("current rule not set");
        }
    }
    parser.Child()->Accept(*this);
}

void LinkerVisitor::Visit(PositiveParser& parser)
{
    if (stage == Stage::resolveRules && domain->Recovery())
    {
        if (currentRule)
        {
            currentRule->AddParser(&parser);
        }
        else
        {
            throw std::runtime_error("current rule not set");
        }
    }
    parser.Child()->Accept(*this);
}

void LinkerVisitor::Visit(ExpectationParser& parser)
{
    if (stage == Stage::resolveRules && domain->Recovery())
    {
        if (currentRule)
        {
            currentRule->AddParser(&parser);
        }
        else
        {
            throw std::runtime_error("current rule not set");
        }
    }
    parser.Child()->Accept(*this);
}

void LinkerVisitor::Visit(GroupingParser& parser)
{
    if (stage == Stage::resolveRules && domain->Recovery())
    {
        if (currentRule)
        {
            currentRule->AddParser(&parser);
        }
        else
        {
            throw std::runtime_error("current rule not set");
        }
    }
    parser.Child()->Accept(*this);
}

void LinkerVisitor::Visit(SequenceParser& parser)
{
    if (stage == Stage::resolveRules && domain->Recovery())
    {
        if (currentRule)
        {
            currentRule->AddParser(&parser);
        }
        else
        {
            throw std::runtime_error("current rule not set");
        }
    }
    parser.Left()->Accept(*this);
    parser.Right()->Accept(*this);
}

void LinkerVisitor::Visit(AlternativeParser& parser)
{
    if (stage == Stage::resolveRules && domain->Recovery())
    {
        if (currentRule)
        {
            currentRule->AddParser(&parser);
        }
        else
        {
            throw std::runtime_error("current rule not set");
        }
    }
    parser.Left()->Accept(*this);
    parser.Right()->Accept(*this);
}

void LinkerVisitor::Visit(DifferenceParser& parser)
{
    if (stage == Stage::resolveRules && domain->Recovery())
    {
        if (currentRule)
        {
            currentRule->AddParser(&parser);
        }
        else
        {
            throw std::runtime_error("current rule not set");
        }
    }
    parser.Left()->Accept(*this);
    parser.Right()->Accept(*this);
}

void LinkerVisitor::Visit(ListParser& parser)
{
    if (stage == Stage::resolveRules && domain->Recovery())
    {
        if (currentRule)
        {
            currentRule->AddParser(&parser);
        }
        else
        {
            throw std::runtime_error("current rule not set");
        }
    }
    parser.Child()->Accept(*this);
}

void LinkerVisitor::Visit(ActionParser& parser)
{
    if (stage == Stage::resolveRules && domain->Recovery())
    {
        if (currentRule)
        {
            currentRule->AddParser(&parser);
        }
        else
        {
            throw std::runtime_error("current rule not set");
        }
    }
    parser.Child()->Accept(*this);
}

void LinkerVisitor::Visit(NonterminalParser& parser)
{
    if (stage == Stage::resolveRules && domain->Recovery())
    {
        if (currentRule)
        {
            currentRule->AddParser(&parser);
        }
        else
        {
            throw std::runtime_error("current rule not set");
        }
    }
    currentRule->AddNonterminal(&parser);
    RuleParser* rule = currentParser->GetRule(parser.RuleName());
    parser.SetRule(rule);
    if (rule->Parameters().size() != parser.Arguments().size())
    {
        throw std::runtime_error("Rule '" + ToUtf8(rule->Name()) + "' takes " + std::to_string(rule->Parameters().size()) + " parameters (" +
            std::to_string(parser.Arguments().size()) + " arguments supplied). Detected in parser '" + ToUtf8(currentParser->Name()) + "' rule '" + ToUtf8(currentRule->Name()) + "'.");
    }
}

void LinkerVisitor::Visit(RuleParser& parser)
{
    currentRule = &parser;
    parser.Definition()->Accept(*this);
    if (stage == Stage::resolveRules)
    {
        domain->AddRule(&parser);
    }
}

void LinkerVisitor::Visit(GrammarParser& parser)
{
    if (stage == Stage::addParsers)
    {
        if (parser.Start())
        {
            if (domain->Start())
            {
                throw std::runtime_error("already has start rule");
            }
            if (parser.Rules().empty())
            {
                throw std::runtime_error("start grammar has no rules");
            }
            domain->SetStart(parser.Rules()[0].get());
        }
        domain->AddParser(&parser);
    }
    else if (stage == Stage::resolveRules)
    {
        currentParser = &parser;
        for (const auto& u : parser.Usings())
        {
            std::vector<std::u32string> components = Split(u, '.');
            if (components.size() != 2)
            {
                throw std::runtime_error("invalid using '" + ToUtf8(u) + "' in parser '" + ToUtf8(parser.Name()) + "'");
            }
            const std::u32string& parserName = components[0];
            const std::u32string& ruleName = components[1];
            GrammarParser* targetParser = domain->GetParser(parserName);
            RuleParser* rule = targetParser->GetRule(ruleName);
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
    for (const auto& parser : parserFile.Parsers())
    {
        parser->Accept(*this);
    }
}

void LinkerVisitor::Visit(Domain& domain)
{
    this->domain = &domain;
    if (domain.Recovery() && !domain.GetTokens())
    {
        domain.SetTokens(new Tokens());
        domain.GetTokens()->AddToken(new Token("END", nullTokenId));
    }
    stage = Stage::addParsers;
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

} } // namespae soulng::spg
