// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/spg/ArrayGeneratorVisitor.hpp>
#include <soulng/spg/Parser.hpp>
#include <soulng/spg/ParserFile.hpp>

namespace soulng { namespace spg {

ArrayGeneratorVisitor::ArrayGeneratorVisitor(CodeFormatter* formatter_, int& sn_) : formatter(formatter_), sn(sn_)
{
}

void ArrayGeneratorVisitor::Visit(StringParser& parser)
{
    std::string s = "s" + std::to_string(sn++);
    parser.SetArrayName(s);
    formatter->Write("static const int " + s + "[] = {");
    bool first = true;
    for (char32_t c : parser.Str())
    {
        if (first)
        {
            first = false;
        }
        else
        {
            formatter->Write(", ");
        }
        formatter->Write(std::to_string(static_cast<int>(c)));
    }
    formatter->WriteLine("};");
    formatter->WriteLine();
}

void ArrayGeneratorVisitor::Visit(CharSetParser& parser)
{
    std::string s = "s" + std::to_string(sn++);
    parser.SetArrayName(s);
    formatter->Write("static const soulng::parser::Range " + s + "[] = {");
    bool first = true;
    for (const soulng::parser::Range& range : parser.Set().Ranges())
    {
        if (first)
        {
            first = false;
        }
        else
        {
            formatter->Write(", ");
        }
        formatter->Write("{" + std::to_string(range.first) + ", " + std::to_string(range.last) + "}");
    }
    formatter->WriteLine("};");
    formatter->WriteLine();
}

void ArrayGeneratorVisitor::Visit(OptionalParser& parser)
{
    parser.Child()->Accept(*this);
}

void ArrayGeneratorVisitor::Visit(KleeneParser& parser)
{
    parser.Child()->Accept(*this);
}

void ArrayGeneratorVisitor::Visit(PositiveParser& parser)
{
    parser.Child()->Accept(*this);
}

void ArrayGeneratorVisitor::Visit(ExpectationParser& parser)
{
    parser.Child()->Accept(*this);
}

void ArrayGeneratorVisitor::Visit(GroupingParser& parser)
{
    parser.Child()->Accept(*this);
}

void ArrayGeneratorVisitor::Visit(SequenceParser& parser)
{
    parser.Left()->Accept(*this);
    parser.Right()->Accept(*this);
}

void ArrayGeneratorVisitor::Visit(AlternativeParser& parser)
{
    parser.Left()->Accept(*this);
    parser.Right()->Accept(*this);
}

void ArrayGeneratorVisitor::Visit(DifferenceParser& parser)
{
    parser.Left()->Accept(*this);
    parser.Right()->Accept(*this);
}

void ArrayGeneratorVisitor::Visit(ListParser& parser)
{
    parser.Child()->Accept(*this);
}

void ArrayGeneratorVisitor::Visit(LookaheadParser& parser)
{
    parser.Child()->Accept(*this);
}

void ArrayGeneratorVisitor::Visit(ActionParser& parser)
{
    parser.Child()->Accept(*this);
}

void ArrayGeneratorVisitor::Visit(RuleParser& parser)
{
    parser.Definition()->Accept(*this);
}

void ArrayGeneratorVisitor::Visit(GrammarParser& parser)
{
    for (const auto& rule : parser.Rules())
    {
        rule->Accept(*this);
    }
}

void ArrayGeneratorVisitor::Visit(ParserFile& parserFile)
{
    for (const auto& parser : parserFile.Parsers())
    {
        parser->Accept(*this);
    }
}

} } // soulng::spg
