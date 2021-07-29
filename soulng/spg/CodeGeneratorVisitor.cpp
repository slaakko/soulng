// =================================
// Copyright (E) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/spg/CodeGeneratorVisitor.hpp>
#include <soulng/spg/CodeEvaluationVisitor.hpp>
#include <soulng/spg/CodeModifyVisitor.hpp>
#include <soulng/spg/ArrayGeneratorVisitor.hpp>
#include <soulng/spg/Domain.hpp>
#include <soulng/util/CodeFormatter.hpp>
#include <soulng/util/Error.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/util/Unicode.hpp>
#include <fstream>
#include <iostream>

namespace soulng { namespace spg {

using namespace soulng::unicode;
using namespace soulng::util;

std::string ParserGeneratorVersionStr()
{
    return "4.0.0";
}

CodeGeneratorVisitor::CodeGeneratorVisitor(bool verbose_, bool noParserDebugSupport_) :
    verbose(verbose_), noParserDebugSupport(noParserDebugSupport_), domain(nullptr), currentParser(nullptr), currentRule(nullptr), stage(Stage::generateHeader), formatter(nullptr),
    lexerTypeName("soulng::lexer::Lexer"), parentMatchNumber(0), setParentMatchNumber(-1), sn(0)
{
}

void CodeGeneratorVisitor::Visit(EmptyParser& parser)
{
    formatter->WriteLine("soulng::parser::Match match(true);");
}

void CodeGeneratorVisitor::Visit(AnyParser& parser)
{
    formatter->WriteLine("soulng::parser::Match match(false);");
    formatter->WriteLine("if (*lexer != soulng::lexer::END_TOKEN)");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("++lexer;");
    formatter->WriteLine("match.hit = true;");
    formatter->DecIndent();
    formatter->WriteLine("}");
}

void CodeGeneratorVisitor::Visit(TokenParser& parser)
{
    if (stage == Stage::beginGenerateTokenSwitch)
    {
        formatter->WriteLine("case " + ToUtf8(parser.TokenName()) + ":");
        formatter->WriteLine("{");
        formatter->IncIndent();
        formatter->WriteLine("++lexer;");
    }
    else if (stage == Stage::endGenerateTokenSwitch)
    {
        formatter->WriteLine("break;");
        formatter->DecIndent();
        formatter->WriteLine("}");
    }
    else
    {
        formatter->WriteLine("soulng::parser::Match match(false);");
        formatter->WriteLine("if (*lexer == " + ToUtf8(parser.TokenName()) + ")");
        formatter->WriteLine("{");
        formatter->IncIndent();
        formatter->WriteLine("++lexer;");
        formatter->WriteLine("match.hit = true;");
        formatter->DecIndent();
        formatter->WriteLine("}");
    }
}

void CodeGeneratorVisitor::Visit(CharParser& parser)
{
    formatter->WriteLine("soulng::parser::Match match(false);");
    formatter->WriteLine("if (*lexer == " + std::to_string(static_cast<int>(parser.Chr())) + ")");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("++lexer;");
    formatter->WriteLine("match.hit = true;");
    formatter->DecIndent();
    formatter->WriteLine("}");
}

void CodeGeneratorVisitor::Visit(StringParser& parser)
{
    formatter->WriteLine("soulng::parser::Match match(true);");
    formatter->WriteLine("for (int i : " + parser.ArrayName() + ")");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("if (*lexer == i)");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("++lexer;");
    formatter->DecIndent();
    formatter->WriteLine("}");
    formatter->WriteLine("else");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("match.hit = false;");
    formatter->WriteLine("break;");
    formatter->DecIndent();
    formatter->WriteLine("}");
    formatter->DecIndent();
    formatter->WriteLine("}");
}

void CodeGeneratorVisitor::Visit(CharSetParser& parser)
{
    if (parser.Set().Inverse())
    {
        formatter->WriteLine("soulng::parser::Match match(lexer.Pos() != lexer.End());");
        formatter->WriteLine("for (const soulng::parser::Range& range : " + parser.ArrayName() + ")");
        formatter->WriteLine("{");
        formatter->IncIndent();
        formatter->WriteLine("if (*lexer >= range.first && *lexer <= range.last)");
        formatter->WriteLine("{");
        formatter->IncIndent();
        formatter->WriteLine("match.hit = false;");
        formatter->WriteLine("break;");
        formatter->DecIndent();
        formatter->WriteLine("}");
        formatter->DecIndent();
        formatter->WriteLine("}");
        formatter->WriteLine("if (match.hit)");
        formatter->WriteLine("{");
        formatter->IncIndent();
        formatter->WriteLine("++lexer;");
        formatter->DecIndent();
        formatter->WriteLine("}");
    }
    else
    {
        formatter->WriteLine("soulng::parser::Match match(false);");
        formatter->WriteLine("for (const soulng::parser::Range& range : " + parser.ArrayName() + ")");
        formatter->WriteLine("{");
        formatter->IncIndent();
        formatter->WriteLine("if (*lexer >= range.first && *lexer <= range.last)");
        formatter->WriteLine("{");
        formatter->IncIndent();
        formatter->WriteLine("match.hit = true;");
        formatter->WriteLine("++lexer;");
        formatter->WriteLine("break;");
        formatter->DecIndent();
        formatter->WriteLine("}");
        formatter->DecIndent();
        formatter->WriteLine("}");
    }
}

void CodeGeneratorVisitor::Visit(OptionalParser& parser)
{
    formatter->WriteLine("soulng::parser::Match match(true);");
    formatter->WriteLine("int64_t save = lexer.GetPos();");
    int prevSetParentMatchNumber = setParentMatchNumber;
    setParentMatchNumber = parentMatchNumber;
    formatter->WriteLine("soulng::parser::Match* parentMatch" + std::to_string(parentMatchNumber++) + " = &match;");
    formatter->WriteLine("{");
    formatter->IncIndent();
    parser.Child()->Accept(*this);
    formatter->WriteLine("if (match.hit)");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = match;");
    formatter->DecIndent();
    formatter->WriteLine("}");
    formatter->WriteLine("else");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("lexer.SetPos(save);");
    formatter->DecIndent();
    formatter->WriteLine("}");
    formatter->DecIndent();
    formatter->WriteLine("}");
    setParentMatchNumber = prevSetParentMatchNumber;
}

void CodeGeneratorVisitor::Visit(KleeneParser& parser)
{
    formatter->WriteLine("soulng::parser::Match match(true);");
    int prevSetParentMatchNumber = setParentMatchNumber;
    setParentMatchNumber = parentMatchNumber;
    formatter->WriteLine("soulng::parser::Match* parentMatch" + std::to_string(parentMatchNumber++) + " = &match;");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("while (true)");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("int64_t save = lexer.GetPos();");
    formatter->WriteLine("{");
    formatter->IncIndent();
    parser.Child()->Accept(*this);
    formatter->WriteLine("if (match.hit)");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = match;");
    formatter->DecIndent();
    formatter->WriteLine("}");
    formatter->WriteLine("else");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("lexer.SetPos(save);");
    formatter->WriteLine("break;");
    formatter->DecIndent();
    formatter->WriteLine("}");
    formatter->DecIndent();
    formatter->WriteLine("}");
    formatter->DecIndent();
    formatter->WriteLine("}");
    formatter->DecIndent();
    formatter->WriteLine("}");
    setParentMatchNumber = prevSetParentMatchNumber;
}

void CodeGeneratorVisitor::Visit(PositiveParser& parser)
{
    formatter->WriteLine("soulng::parser::Match match(false);");
    int prevSetParentMatchNumber0 = setParentMatchNumber;
    setParentMatchNumber = parentMatchNumber;
    formatter->WriteLine("soulng::parser::Match* parentMatch" + std::to_string(parentMatchNumber++) + " = &match;");
    formatter->WriteLine("{");
    formatter->IncIndent();
    parser.Child()->Accept(*this);
    formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = match;");
    formatter->DecIndent();
    formatter->WriteLine("}");
    formatter->WriteLine("if (match.hit)");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("soulng::parser::Match match(true);");
    int prevSetParentMatchNumber1 = setParentMatchNumber;
    setParentMatchNumber = parentMatchNumber;
    formatter->WriteLine("soulng::parser::Match* parentMatch" + std::to_string(parentMatchNumber++) + " = &match;");
    formatter->WriteLine("while (true)");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("int64_t save = lexer.GetPos();");
    formatter->WriteLine("{");
    formatter->IncIndent();
    parser.Child()->Accept(*this);
    formatter->WriteLine("if (match.hit)");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = match;");
    formatter->DecIndent();
    formatter->WriteLine("}");
    formatter->WriteLine("else");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("lexer.SetPos(save);");
    formatter->WriteLine("break;");
    formatter->DecIndent();
    formatter->WriteLine("}");
    formatter->DecIndent();
    formatter->WriteLine("}");
    formatter->DecIndent();
    formatter->WriteLine("}");
    formatter->DecIndent();
    formatter->WriteLine("}");
    setParentMatchNumber = prevSetParentMatchNumber1;
    setParentMatchNumber = prevSetParentMatchNumber0;
}

void CodeGeneratorVisitor::Visit(ExpectationParser& parser)
{
    formatter->WriteLine("soulng::parser::Match match(true);");
    int prevSetParentMatchNumber0 = setParentMatchNumber;
    setParentMatchNumber = parentMatchNumber;
    formatter->WriteLine("soulng::parser::Match* parentMatch" + std::to_string(parentMatchNumber++) + " = &match;");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("soulng::lexer::Span span = lexer.GetSpan();");
    parser.Child()->Accept(*this);
    formatter->WriteLine("if (match.hit)");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("lexer.ResetRecovered();");
    formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = match;");
    formatter->DecIndent();
    formatter->WriteLine("}");
    formatter->WriteLine("else");
    formatter->WriteLine("{");
    formatter->IncIndent();
    if (parser.Child()->IsNonterminal())
    {
        NonterminalParser* nonterminalParser = static_cast<NonterminalParser*>(parser.Child());
        RuleParser* rule = nonterminalParser->Rule();
        std::u32string ruleInfo = rule->Info();
        if (ruleInfo.empty())
        {
            ruleInfo = rule->Name();
        }
        if (parser.IsNothrow())
        {
            formatter->WriteLine("match.hit = true;");
            formatter->WriteLine("lexer.SetRecovered();");
            formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = match;");
            formatter->WriteLine("lexer.AddError(span, U\"" + ToUtf8(ruleInfo) + "\");");
        }
        else
        {
            formatter->WriteLine("lexer.ThrowExpectationFailure(span, U\"" + ToUtf8(ruleInfo) + "\");");
        }
    }
    else if (parser.Child()->IsToken())
    {
        std::u32string tokenName = static_cast<TokenParser*>(parser.Child())->TokenName();
        if (parser.IsNothrow())
        {
            formatter->WriteLine("match.hit = true;");
            formatter->WriteLine("lexer.SetRecovered();");
            formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = match;");
            formatter->WriteLine("lexer.AddError(span, ToUtf32(GetTokenInfo(" + ToUtf8(tokenName) + ")));");
        }
        else
        {
            formatter->WriteLine("lexer.ThrowExpectationFailure(span, ToUtf32(GetTokenInfo(" + ToUtf8(tokenName) + ")));");
        }
    }
    else
    {
        std::u32string parserName = parser.Child()->Name();
        if (parser.IsNothrow())
        {
            formatter->WriteLine("match.hit = true;");
            formatter->WriteLine("lexer.SetRecovered();");
            formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = match;");
            formatter->WriteLine("lexer.AddError(span, U\"" + ToUtf8(parserName) + "\");");
        }
        else
        {
            formatter->WriteLine("lexer.ThrowExpectationFailure(span, U\"" + ToUtf8(parserName) + "\");");
        }
    }
    formatter->DecIndent();
    formatter->WriteLine("}");
    formatter->DecIndent();
    formatter->WriteLine("}");
    setParentMatchNumber = prevSetParentMatchNumber0;
}

void CodeGeneratorVisitor::Visit(GroupingParser& parser)
{
    formatter->WriteLine("soulng::parser::Match match(false);");
    int prevSetParentMatchNumber = setParentMatchNumber;
    setParentMatchNumber = parentMatchNumber;
    formatter->WriteLine("soulng::parser::Match* parentMatch" + std::to_string(parentMatchNumber++) + " = &match;");
    formatter->WriteLine("{");
    formatter->IncIndent();
    parser.Child()->Accept(*this);
    formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = match;");
    formatter->DecIndent();
    formatter->WriteLine("}");
    setParentMatchNumber = prevSetParentMatchNumber;
}

void CodeGeneratorVisitor::Visit(SequenceParser& parser)
{
    formatter->WriteLine("soulng::parser::Match match(false);");
    int prevSetParentMatchNumber0 = setParentMatchNumber;
    setParentMatchNumber = parentMatchNumber;
    formatter->WriteLine("soulng::parser::Match* parentMatch" + std::to_string(parentMatchNumber++) + " = &match;");
    formatter->WriteLine("{");
    formatter->IncIndent();
    parser.Left()->Accept(*this);
    formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = match;");
    formatter->DecIndent();
    formatter->WriteLine("}");
    formatter->WriteLine("if (match.hit)");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("soulng::parser::Match match(false);");
    int prevSetParentMatchNumber1 = setParentMatchNumber;
    setParentMatchNumber = parentMatchNumber;
    formatter->WriteLine("soulng::parser::Match* parentMatch" + std::to_string(parentMatchNumber++) + " = &match;");
    formatter->WriteLine("{");
    formatter->IncIndent();
    parser.Right()->Accept(*this);
    formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = match;");
    formatter->DecIndent();
    formatter->WriteLine("}");
    setParentMatchNumber = prevSetParentMatchNumber1;
    formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = match;");
    formatter->DecIndent();
    formatter->WriteLine("}");
    setParentMatchNumber = prevSetParentMatchNumber0;
}

void CodeGeneratorVisitor::Visit(AlternativeParser& parser)
{
    if (stage == Stage::generateTokenSwitch)
    {
        parser.Left()->Accept(*this);
        parser.Right()->Accept(*this);
    }
    else
    {
        if (parser.IsTokenSwitch())
        {
            Stage prevStage = stage;
            stage = Stage::generateTokenSwitch;
            formatter->WriteLine("int64_t pos = lexer.GetPos();");
            formatter->WriteLine("soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos(pos);");
            formatter->WriteLine("soulng::lexer::Span span = lexer.GetSpan();");
            formatter->WriteLine("switch (*lexer)");
            formatter->WriteLine("{");
            formatter->IncIndent();
            parser.Left()->Accept(*this);
            parser.Right()->Accept(*this);
            formatter->DecIndent();
            formatter->WriteLine("}");
            stage = prevStage;
        }
        else
        {
            int prevSetParentMatchNumber0 = setParentMatchNumber;
            formatter->WriteLine("soulng::parser::Match match(false);");
            setParentMatchNumber = parentMatchNumber;
            formatter->WriteLine("soulng::parser::Match* parentMatch" + std::to_string(parentMatchNumber++) + " = &match;");
            formatter->WriteLine("{");
            formatter->IncIndent();
            formatter->WriteLine("int64_t save = lexer.GetPos();");
            parser.Left()->Accept(*this);
            formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = match;");
            formatter->WriteLine("if (!match.hit)");
            formatter->WriteLine("{");
            formatter->IncIndent();
            int prevSetParentMatchNumber1 = setParentMatchNumber;
            formatter->WriteLine("soulng::parser::Match match(false);");
            setParentMatchNumber = parentMatchNumber;
            formatter->WriteLine("soulng::parser::Match* parentMatch" + std::to_string(parentMatchNumber++) + " = &match;");
            formatter->WriteLine("lexer.SetPos(save);");
            formatter->WriteLine("{");
            formatter->IncIndent();
            parser.Right()->Accept(*this);
            formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = match;");
            formatter->DecIndent();
            formatter->WriteLine("}");
            setParentMatchNumber = prevSetParentMatchNumber1;
            formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = match;");
            formatter->DecIndent();
            formatter->WriteLine("}");
            formatter->DecIndent();
            formatter->WriteLine("}");
            setParentMatchNumber = prevSetParentMatchNumber0;
        }
    }
}

void CodeGeneratorVisitor::Visit(DifferenceParser& parser)
{
    formatter->WriteLine("soulng::parser::Match match(false);");
    int prevSetParentMatchNumber0 = setParentMatchNumber;
    setParentMatchNumber = parentMatchNumber;
    formatter->WriteLine("soulng::parser::Match* parentMatch" + std::to_string(parentMatchNumber++) + " = &match;");
    formatter->WriteLine("int64_t save = lexer.GetPos();");
    formatter->WriteLine("{");
    formatter->IncIndent();
    parser.Left()->Accept(*this);
    formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = match;");
    formatter->DecIndent();
    formatter->WriteLine("}");
    formatter->WriteLine("if (match.hit)");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("soulng::parser::Match match(false);");
    int prevSetParentMatchNumber1 = setParentMatchNumber;
    setParentMatchNumber = parentMatchNumber;
    formatter->WriteLine("soulng::parser::Match* parentMatch" + std::to_string(parentMatchNumber++) + " = &match;");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("int64_t tmp = lexer.GetPos();");
    formatter->WriteLine("lexer.SetPos(save);");
    formatter->WriteLine("save = tmp;");
    parser.Right()->Accept(*this);
    formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = match;");
    formatter->DecIndent();
    formatter->WriteLine("}");
    setParentMatchNumber = prevSetParentMatchNumber1;
    formatter->WriteLine("if (!match.hit)");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("lexer.SetPos(save);");
    formatter->DecIndent();
    formatter->WriteLine("}");
    formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = soulng::parser::Match(!match.hit, match.value);");
    formatter->DecIndent();
    formatter->WriteLine("}");
    setParentMatchNumber = prevSetParentMatchNumber0;
}

void CodeGeneratorVisitor::Visit(ListParser& parser)
{
    parser.Child()->Accept(*this);
}

void CodeGeneratorVisitor::Visit(LookaheadParser& parser)
{
    formatter->WriteLine("soulng::parser::Match match(true);");
    formatter->WriteLine("int64_t save = lexer.GetPos();");
    int prevSetParentMatchNumber = setParentMatchNumber;
    setParentMatchNumber = parentMatchNumber;
    formatter->WriteLine("soulng::parser::Match* parentMatch" + std::to_string(parentMatchNumber++) + " = &match;");
    formatter->WriteLine("{");
    formatter->IncIndent();
    parser.Child()->Accept(*this);
    formatter->WriteLine("if (match.hit)");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = match;");
    formatter->WriteLine("lexer.SetPos(save);");
    formatter->DecIndent();
    formatter->WriteLine("}");
    formatter->WriteLine("else");
    formatter->WriteLine("{");
    formatter->IncIndent();
    formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = soulng::parser::Match(false);");
    formatter->WriteLine("lexer.SetPos(save);");
    formatter->DecIndent();
    formatter->WriteLine("}");
    formatter->DecIndent();
    formatter->WriteLine("}");
    setParentMatchNumber = prevSetParentMatchNumber;
}

void CodeGeneratorVisitor::Visit(ActionParser& parser)
{
    if (stage == Stage::generateTokenSwitch)
    {
        CodeEvaluationVisitor codeEvaluationVisitor;
        parser.SuccessCode()->Accept(codeEvaluationVisitor);
        bool hasPass = codeEvaluationVisitor.HasPass();
        if (hasPass)
        {
            throw std::runtime_error("token switch does not support pass");
        }
        if (codeEvaluationVisitor.HasReturn())
        {
            currentRule->SetHasReturn();
        }
        stage = Stage::beginGenerateTokenSwitch;
        parser.Child()->Accept(*this);
        bool nonterminalValue = parser.Child()->IsNonterminal();
        bool ptrType = false;
        if (currentRule->ReturnType() != nullptr)
        {
            ptrType = currentRule->ReturnType()->IsPtrType();
        }
        std::u32string nonterminalName;
        soulng::cppcode::TypeId* returnType = nullptr;
        if (!ptrType)
        {
            returnType = currentRule->ReturnType();
        }
        if (nonterminalValue)
        {
            NonterminalParser* nt = static_cast<NonterminalParser*>(parser.Child());
            nonterminalName = nt->Name();
        }
        NonterminalCountingVisitor countingVisitor(nonterminalInfos);
        parser.SuccessCode()->Accept(countingVisitor);
        CodeModifyVisitor modifyVisitor(ptrType, nonterminalName, nonterminalInfos, returnType, noParserDebugSupport, currentRule->Name());
        parser.SuccessCode()->Accept(modifyVisitor);
        parser.SuccessCode()->Print(*formatter);
        stage = Stage::endGenerateTokenSwitch;
        parser.Child()->Accept(*this);
        stage = Stage::generateTokenSwitch;
    }
    else
    {
        int prevSetParentMatchNumber = setParentMatchNumber;
        formatter->WriteLine("soulng::parser::Match match(false);");
        setParentMatchNumber = parentMatchNumber;
        formatter->WriteLine("soulng::parser::Match* parentMatch" + std::to_string(parentMatchNumber++) + " = &match;");
        formatter->WriteLine("{");
        formatter->IncIndent();
        formatter->WriteLine("int64_t pos = lexer.GetPos();");
        CodeEvaluationVisitor codeEvaluationVisitor;
        parser.SuccessCode()->Accept(codeEvaluationVisitor);
        if (codeEvaluationVisitor.HasReturn())
        {
            currentRule->SetHasReturn();
        }
        bool hasPass = codeEvaluationVisitor.HasPass();
        bool hasSpan = codeEvaluationVisitor.HasSpan();
        bool hasSourcePos = codeEvaluationVisitor.HasSourcePos();
        if (hasSpan)
        {
            formatter->WriteLine("soulng::lexer::Span span = lexer.GetSpan();");
        }
        if (hasSourcePos)
        {
            formatter->WriteLine("soulng::lexer::SourcePos sourcePos = lexer.GetSourcePos(pos);");
        }
        if (hasPass)
        {
            formatter->WriteLine("bool pass = true;");
        }
        parser.Child()->Accept(*this);
        formatter->WriteLine("if (match.hit)");
        bool nonterminalValue = parser.Child()->IsNonterminal();
        bool ptrType = false;
        if (currentRule->ReturnType() != nullptr)
        {
            ptrType = currentRule->ReturnType()->IsPtrType();
        }
        std::u32string nonterminalName;
        soulng::cppcode::TypeId* returnType = nullptr;
        if (!ptrType)
        {
            returnType = currentRule->ReturnType();
        }
        if (nonterminalValue)
        {
            NonterminalParser* nt = static_cast<NonterminalParser*>(parser.Child());
            nonterminalName = nt->Name();
        }
        NonterminalCountingVisitor countingVisitor(nonterminalInfos);
        parser.SuccessCode()->Accept(countingVisitor);
        CodeModifyVisitor modifyVisitor(ptrType, nonterminalName, nonterminalInfos, returnType, noParserDebugSupport, currentRule->Name());
        parser.SuccessCode()->Accept(modifyVisitor);
        parser.SuccessCode()->Print(*formatter);
        if (parser.FailCode())
        {
            formatter->WriteLine("else");
            parser.FailCode()->Print(*formatter);
        }
        if (hasPass)
        {
            formatter->WriteLine("if (match.hit && !pass)");
            formatter->WriteLine("{");
            formatter->IncIndent();
            formatter->WriteLine("match = soulng::parser::Match(false);");
            formatter->DecIndent();
            formatter->WriteLine("}");
        }
        formatter->WriteLine("*parentMatch" + std::to_string(setParentMatchNumber) + " = match;");
        setParentMatchNumber = prevSetParentMatchNumber;
        formatter->DecIndent();
        formatter->WriteLine("}");
    }
}

void CodeGeneratorVisitor::Visit(NonterminalParser& parser)
{
    RuleParser* rule = parser.Rule();
    std::string ruleName = ToUtf8(rule->Parent()->Name()) + "::" + ToUtf8(rule->Name());
    formatter->Write("soulng::parser::Match match = " + ruleName + "(lexer");
    for (const auto& arg : parser.Arguments())
    {
        formatter->Write(", ");
        arg->Print(*formatter);
    }
    formatter->WriteLine(");");
    RuleParser* calledRule = parser.Rule();
    Assert(calledRule, "rule not set");
    if (calledRule->ReturnType() != nullptr)
    {
        formatter->Write(ToUtf8(parser.Name()) + ".reset(");
        if (calledRule->ReturnType()->IsPtrType())
        {
            formatter->Write("static_cast<");
            calledRule->ReturnType()->Print(*formatter);
            formatter->WriteLine(">(match.value));");
        }
        else
        {
            formatter->Write("static_cast<soulng::parser::Value<");
            calledRule->ReturnType()->Print(*formatter);
            formatter->WriteLine(">*>(match.value));");
        }
    }
}

void CodeGeneratorVisitor::Visit(RuleParser& parser)
{
    parentMatchNumber = 0;
    setParentMatchNumber = -1;
    currentRule = &parser;
    if (stage == Stage::generateHeader)
    {
        formatter->Write("static soulng::parser::Match " + ToUtf8(parser.Name()) + "(" + lexerTypeName + "& lexer");
        for (const auto& param : parser.Parameters())
        {
            formatter->Write(", ");
            param->type->Print(*formatter);
            formatter->Write(" ");
            formatter->Write(ToUtf8(param->name));
        }
        formatter->WriteLine(");");
    }
    else if (stage == Stage::generateSource)
    {
        bool first = false;
        if (!currentParser->Rules().empty())
        {
            if (currentParser->Rules().front().get() == &parser)
            {
                first = true;
            }
        }
        if (!first)
        {
            formatter->WriteLine();
        }
        formatter->Write("soulng::parser::Match " + ToUtf8(parser.Parent()->Name()) + "::" + ToUtf8(parser.Name()) + "(" + lexerTypeName + "& lexer");
        for (const auto& param : parser.Parameters())
        {
            formatter->Write(", ");
            param->type->Print(*formatter);
            formatter->Write(" ");
            formatter->Write(ToUtf8(param->name));
        }
        formatter->WriteLine(")");
        formatter->WriteLine("{");
        formatter->IncIndent();
        if (!noParserDebugSupport)
        {
            formatter->WriteLine("#ifdef SOULNG_PARSER_DEBUG_SUPPORT");
            formatter->WriteLine("soulng::lexer::Span parser_debug_match_span;");
            formatter->WriteLine("bool parser_debug_write_to_log = lexer.Log() != nullptr;");
            formatter->WriteLine("if (parser_debug_write_to_log)");
            formatter->WriteLine("{");
            formatter->IncIndent();
            formatter->WriteLine("parser_debug_match_span = lexer.GetSpan();");
            formatter->WriteLine("soulng::lexer::WriteBeginRuleToLog(lexer, soulng::unicode::ToUtf32(\"" + ToUtf8(parser.Name()) + "\"));");
            formatter->DecIndent();
            formatter->WriteLine("}");
            formatter->WriteLine("#endif // SOULNG_PARSER_DEBUG_SUPPORT");
        }
        if (parser.IsState() && parser.Id() != -1)
        {
            formatter->WriteLine("soulng::lexer::RuleGuard ruleGuard(lexer, " + std::to_string(parser.Id()) + ");");
        }
        for (const auto& variable : parser.Variables())
        {
            variable->type->Print(*formatter);
            formatter->Write(" ");
            formatter->Write(ToUtf8(variable->name));
            formatter->Write(" = ");
            if (variable->type->IsPtrType())
            {
                formatter->WriteLine("nullptr;");
            }
            else
            {
                variable->type->Print(*formatter);
                formatter->WriteLine("();");
            }
        }
        nonterminalInfos.clear();
        for (const auto& nonterminal : parser.Nonterminals())
        {
            bool found = false;
            for (const auto& info : nonterminalInfos)
            {
                if (info.name == nonterminal->Name())
                {
                    found = true;
                    break;
                }
            }
            if (found) continue;
            RuleParser* calledRule = nonterminal->Rule();
            Assert(calledRule, "rule not set");
            if (calledRule->ReturnType() != nullptr)
            {
                if (calledRule->ReturnType()->IsPtrType())
                {
                    formatter->Write("std::unique_ptr<");
                    calledRule->ReturnType()->PrintNonPtrType(*formatter);
                    formatter->Write(">");
                    nonterminalInfos.push_back(NonterminalInfo(nonterminal->Name(), true));
                }
                else
                {
                    formatter->Write("std::unique_ptr<soulng::parser::Value<");
                    calledRule->ReturnType()->Print(*formatter);
                    formatter->Write(">>");
                    nonterminalInfos.push_back(NonterminalInfo(nonterminal->Name(), false));
                }
                formatter->WriteLine(" " + ToUtf8(nonterminal->Name()) + ";");
            }
        }
        if (parser.Definition()->IsTokenSwitch())
        {
            formatter->WriteLine("soulng::parser::Match match(false);");
        }
        parser.Definition()->Accept(*this);
        if (!noParserDebugSupport)
        {
            formatter->WriteLine("#ifdef SOULNG_PARSER_DEBUG_SUPPORT");
            formatter->WriteLine("if (parser_debug_write_to_log)");
            formatter->WriteLine("{");
            formatter->IncIndent();
            formatter->WriteLine("if (match.hit) soulng::lexer::WriteSuccessToLog(lexer, parser_debug_match_span, soulng::unicode::ToUtf32(\"" + ToUtf8(parser.Name()) + "\"));");
            formatter->WriteLine("else soulng::lexer::WriteFailureToLog(lexer, soulng::unicode::ToUtf32(\"" + ToUtf8(parser.Name()) + "\"));");
            formatter->DecIndent();
            formatter->WriteLine("}");
            formatter->WriteLine("#endif // SOULNG_PARSER_DEBUG_SUPPORT");
        }
        formatter->WriteLine("if (!match.hit)");
        formatter->WriteLine("{");
        formatter->IncIndent();
        formatter->WriteLine("match.value = nullptr;");
        formatter->DecIndent();
        formatter->WriteLine("}");
        formatter->WriteLine("return match;");
        formatter->DecIndent();
        formatter->WriteLine("}");
        for (const auto& info : nonterminalInfos)
        {
            if (info.ptrType && info.count > 1)
            {
                std::cout << "warning: unique pointer value of nonterminal '" + ToUtf8(info.name) + "' used " + std::to_string(info.count) + " times in semantic actions of rule '" + ToUtf8(parser.Name()) +
                    "' of parser '" + ToUtf8(parser.Parent()->Name()) << "'" << std::endl;
            }
        }
        if (parser.ReturnType() != nullptr && !parser.HasReturn())
        {
            std::cout << "warning: rule '" + ToUtf8(parser.Name()) +
                "' of parser '" + ToUtf8(parser.Parent()->Name()) << "' returns value, but no semantic action has a return statement." << std::endl;
        }
    }
}

void CodeGeneratorVisitor::Visit(GrammarParser& parser)
{
    currentParser = &parser;
    if (stage == Stage::generateHeader)
    {
        if (!parser.Lexer().empty())
        {
            lexerTypeName = ToUtf8(parser.Lexer());
            formatter->WriteLine("class " + lexerTypeName + ";");
            formatter->WriteLine();
        }
        else
        {
            lexerTypeName = "soulng::lexer::Lexer";
            std::cout << "warning: 'uselexer' statement missing from '" + ToUtf8(parser.Name()) + "' parser." << std::endl;
        }
        if (parser.Api().empty())
        {
            formatter->WriteLine("struct " + ToUtf8(parser.Name()));
        }
        else
        {
            formatter->WriteLine("struct " + ToUtf8(parser.Api()) + " " + ToUtf8(parser.Name()));
        }
        formatter->WriteLine("{");
        formatter->IncIndent();
        if (parser.Main())
        {
            if (!parser.Rules().empty())
            {
                const std::unique_ptr<RuleParser>& startRule = parser.Rules().front();
                if (startRule->ReturnType() != nullptr)
                {
                    formatter->Write("static ");
                    if (startRule->ReturnType()->IsPtrType())
                    {
                        formatter->Write("std::unique_ptr<");
                        startRule->ReturnType()->PrintNonPtrType(*formatter);
                        formatter->Write(">");
                    }
                    else
                    {
                        startRule->ReturnType()->Print(*formatter);
                    }
                    formatter->Write(" Parse(" + lexerTypeName + "& lexer");
                }
                else
                {
                    formatter->Write("static void Parse(" + lexerTypeName + "& lexer");
                }
                for (const auto& param : startRule->Parameters())
                {
                    formatter->Write(", ");
                    param->type->Print(*formatter);
                    formatter->Write(" ");
                    formatter->Write(ToUtf8(param->name));
                }
                formatter->WriteLine(");");
            }
        }
        for (const auto& rule : parser.Rules())
        {
            rule->Accept(*this);
        }
        formatter->DecIndent();
        formatter->WriteLine("};");
    }
    else if (stage == Stage::generateSource)
    {
        if (parser.Main())
        {
            if (!parser.Rules().empty())
            {
                const std::unique_ptr<RuleParser>& startRule = parser.Rules().front();
                if (startRule->ReturnType() != nullptr)
                {
                    if (startRule->ReturnType()->IsPtrType())
                    {
                        formatter->Write("std::unique_ptr<");
                        startRule->ReturnType()->PrintNonPtrType(*formatter);
                        formatter->Write(">");
                    }
                    else
                    {
                        startRule->ReturnType()->Print(*formatter);
                    }
                    formatter->Write(" " + ToUtf8(parser.Name()) + "::Parse(" + lexerTypeName + "& lexer");
                }
                else
                {
                    formatter->Write("void " + ToUtf8(parser.Name()) + "::Parse(" + lexerTypeName + "& lexer");
                }
                for (const auto& param : startRule->Parameters())
                {
                    formatter->Write(", ");
                    param->type->Print(*formatter);
                    formatter->Write(" ");
                    formatter->Write(ToUtf8(param->name));
                }
                formatter->WriteLine(")");
                formatter->WriteLine("{");
                formatter->IncIndent();
                RuleParser* rule = startRule.get();
                if (rule->ReturnType() != nullptr)
                {
                    formatter->Write("std::unique_ptr<");
                    if (rule->ReturnType()->IsPtrType())
                    {
                        rule->ReturnType()->PrintNonPtrType(*formatter);
                        formatter->Write(">");
                    }
                    else
                    {
                        formatter->Write("soulng::parser::Value<");
                        rule->ReturnType()->Print(*formatter);
                        formatter->Write(">>");
                    }
					formatter->WriteLine(" value;");
				}
                if (!noParserDebugSupport)
                {
                    formatter->WriteLine("#ifdef SOULNG_PARSER_DEBUG_SUPPORT");
                    formatter->WriteLine("if (lexer.Log())");
                    formatter->WriteLine("{");
                    formatter->IncIndent();
                    formatter->WriteLine("lexer.Log()->WriteBeginRule(soulng::unicode::ToUtf32(\"parse\"));");
                    formatter->WriteLine("lexer.Log()->IncIndent();");
                    formatter->DecIndent();
                    formatter->WriteLine("}");
                    formatter->WriteLine("#endif // SOULNG_PARSER_DEBUG_SUPPORT");
                }
                formatter->WriteLine("++lexer;");
                formatter->WriteLine("soulng::lexer::Span span = lexer.GetSpan();");
                std::string ruleName = ToUtf8(rule->Parent()->Name()) + "::" + ToUtf8(rule->Name());
                formatter->Write("soulng::parser::Match match = " + ruleName + "(lexer");
                for (const auto& param : startRule->Parameters())
                {
                    formatter->Write(", ");
                    formatter->Write(ToUtf8(param->name));
                }
                formatter->WriteLine(");");
                RuleParser* calledRule = rule;
                Assert(calledRule, "rule not set");
                if (calledRule->ReturnType() != nullptr)
                {
                    formatter->Write("value.reset(");
                    if (calledRule->ReturnType()->IsPtrType())
                    {
                        formatter->Write("static_cast<");
                        calledRule->ReturnType()->Print(*formatter);
                        formatter->WriteLine(">(match.value));");
                    }
                    else
                    {
                        formatter->Write("static_cast<soulng::parser::Value<");
                        calledRule->ReturnType()->Print(*formatter);
                        formatter->WriteLine(">*>(match.value));");
                    }
                }
                if (!noParserDebugSupport)
                {
                    formatter->WriteLine("#ifdef SOULNG_PARSER_DEBUG_SUPPORT");
                    formatter->WriteLine("if (lexer.Log())");
                    formatter->WriteLine("{");
                    formatter->IncIndent();
                    formatter->WriteLine("lexer.Log()->DecIndent();");
                    formatter->WriteLine("lexer.Log()->WriteEndRule(soulng::unicode::ToUtf32(\"parse\"));");
                    formatter->DecIndent();
                    formatter->WriteLine("}");
                    formatter->WriteLine("#endif // SOULNG_PARSER_DEBUG_SUPPORT");
                }
                formatter->WriteLine("if (match.hit)");
                formatter->WriteLine("{");
                formatter->IncIndent();
                formatter->WriteLine("if (*lexer == soulng::lexer::END_TOKEN)");
                formatter->WriteLine("{");
                formatter->IncIndent();
				if (startRule->ReturnType())
				{
					if (startRule->ReturnType()->IsPtrType())
					{
						formatter->WriteLine("return value;");
					}
					else
					{
						formatter->WriteLine("return value->value;");
					}
				}
				else
				{
					formatter->WriteLine("return;");
				}
                formatter->DecIndent();
                formatter->WriteLine("}");
                formatter->WriteLine("else");
                formatter->WriteLine("{");
                formatter->IncIndent();
                if (parser.IsNothrow())
                {
                    formatter->WriteLine("lexer.AddError(lexer.GetSpan(), ToUtf32(soulng::lexer::GetEndTokenInfo()));");
                    if (startRule->ReturnType())
                    {
                        if (startRule->ReturnType()->IsPtrType())
                        {
                            formatter->WriteLine("return value;");
                        }
                        else
                        {
                            formatter->WriteLine("return value->value;");
                        }
                    }
                    else
                    {
                        formatter->WriteLine("return;");
                    }
                }
                else
                {
                    if (parser.IsFarthestError())
                    {
                        formatter->WriteLine("lexer.ThrowFarthestError();");
                    }
                    else
                    {
                        formatter->WriteLine("lexer.ThrowExpectationFailure(lexer.GetSpan(), ToUtf32(soulng::lexer::GetEndTokenInfo()));");
                    }
                }
                formatter->DecIndent();
                formatter->WriteLine("}");
                formatter->DecIndent();
                formatter->WriteLine("}");
                formatter->WriteLine("else");
                formatter->WriteLine("{");
                formatter->IncIndent();
                std::u32string ruleInfo = rule->Info();
                if (ruleInfo.empty())
                {
                    ruleInfo = rule->Name();
                }
                if (parser.IsNothrow())
                {
                    formatter->WriteLine("lexer.AddError(span, U\"" + ToUtf8(ruleInfo) + "\");");
                    if (startRule->ReturnType())
                    {
                        if (startRule->ReturnType()->IsPtrType())
                        {
                            formatter->WriteLine("return value;");
                        }
                        else
                        {
                            formatter->WriteLine("return value->value;");
                        }
                    }
                    else
                    {
                        formatter->WriteLine("return;");
                    }
                }
                else
                {
                    if (parser.IsFarthestError())
                    {
                        formatter->WriteLine("lexer.ThrowFarthestError();");
                    }
                    else
                    {
                        formatter->WriteLine("lexer.ThrowExpectationFailure(span, U\"" + ToUtf8(ruleInfo) + "\");");
                    }
                }
                formatter->DecIndent();
                formatter->WriteLine("}");
				if (startRule->ReturnType())
				{
					if (startRule->ReturnType()->IsPtrType())
					{
						formatter->WriteLine("return value;");
					}
					else
					{
						formatter->WriteLine("return value->value;");
					}
				}
				else
				{
					formatter->WriteLine("return;");
				}
                formatter->DecIndent();
                formatter->WriteLine("}");
                formatter->WriteLine();
            }
        }
        for (const auto& rule : parser.Rules())
        {
            rule->Accept(*this);
        }
    }
}

void CodeGeneratorVisitor::Visit(ParserFile& parserFile)
{
    if (verbose)
    {
        std::cout << "> " << parserFile.FileName() << std::endl;
    }
    sn = 0;
    stage = Stage::generateHeader;
    std::string headerFileName = Path::ChangeExtension(parserFile.FileName(), ".hpp");
    std::ofstream headerFile(headerFileName);
    CodeFormatter headerFormatter(headerFile);
    formatter = &headerFormatter;
    std::string includeGuard = ToUtf8(ToUpper(ToUtf32(Path::GetFileName(headerFileName))));
    includeGuard = Replace(includeGuard, '.', '_');
    formatter->WriteLine("#ifndef " + includeGuard);
    formatter->WriteLine("#define " + includeGuard);
    for (const auto& include : parserFile.Includes())
    {
        if (include->HppPrefix())
        {
            formatter->WriteLine(ToUtf8(include->Str()));
        }
    }
    formatter->WriteLine("#include <soulng/lexer/Token.hpp>");
    formatter->WriteLine("#include <soulng/parser/Match.hpp>");
    formatter->WriteLine("#include <soulng/parser/Value.hpp>");
    formatter->WriteLine();
    formatter->WriteLine("// this file has been automatically generated from '" + parserFile.FileName() + "' using soulng parser generator spg version " + ParserGeneratorVersionStr());
    formatter->WriteLine();
    bool first = true;
    for (const auto& parser : parserFile.Parsers())
    {
        if (first)
        {
            first = false;
        }
        else
        {
            formatter->WriteLine();
        }
        parser->Accept(*this);
    }
    formatter->WriteLine();
    formatter->WriteLine("#endif // " + includeGuard);
    if (verbose)
    {
        std::cout << "==> " << headerFileName << std::endl;
    }
    stage = Stage::generateSource;
    std::string sourceFileName = Path::ChangeExtension(parserFile.FileName(), ".cpp");
    std::ofstream sourceFile(sourceFileName);
    CodeFormatter sourceFormatter(sourceFile);
    formatter = &sourceFormatter;
    formatter->WriteLine("#include \"" + Path::ChangeExtension(Path::GetFileName(parserFile.FileName()), ".hpp") + "\"");
    formatter->WriteLine("#include <soulng/util/Unicode.hpp>");
    for (const auto& include : parserFile.Includes())
    {
        if (!include->HppPrefix())
        {
            formatter->WriteLine(ToUtf8(include->Str()));
        }
    }
    formatter->WriteLine();
    formatter->WriteLine("// this file has been automatically generated from '" + parserFile.FileName() + "' using soulng parser generator spg version " + ParserGeneratorVersionStr());
    formatter->WriteLine();
    ArrayGeneratorVisitor arrayGeneratorVisitor(formatter, sn);
    parserFile.Accept(arrayGeneratorVisitor);
    formatter->WriteLine("using namespace soulng::unicode;");
    bool hasUsings = true;
    for (const auto& usingNs : parserFile.UsingNamespaceDeclarations())
    {
        formatter->WriteLine(ToUtf8(usingNs));
        hasUsings = true;
    }
    if (hasUsings)
    {
        formatter->WriteLine();
    }
    for (const auto& parser : parserFile.Parsers())
    {
        parser->Accept(*this);
    }
    if (verbose)
    {
        std::cout << "==> " << sourceFileName << std::endl;
    }
}

void GenerateRuleFiles(Domain& domain)
{
    std::ofstream ruleHeaderFile(domain.RuleHeaderFilePath());
    CodeFormatter headerFormatter(ruleHeaderFile);
    headerFormatter.WriteLine("#ifndef RULES_H");
    headerFormatter.WriteLine("#define RULES_H");
    GrammarParser* firstGrammar = nullptr;
    if (!domain.ParserFiles().empty())
    {
        ParserFile* firstParserFile = domain.ParserFiles().front();
        for (const auto& include : firstParserFile->Includes())
        {
            if (include->HppPrefix())
            {
                headerFormatter.WriteLine(ToUtf8(include->Str()));
            }
        }
        if (!firstParserFile->Parsers().empty())
        {
            firstGrammar = firstParserFile->Parsers().front().get();
        }
    }
    headerFormatter.WriteLine("#include <vector>");
    headerFormatter.WriteLine();
    std::string api;
    if (firstGrammar)
    {
        if (!firstGrammar->Api().empty())
        {
            api = ToUtf8(firstGrammar->Api()) + " ";
        }
    }
    headerFormatter.WriteLine(api + "std::vector<const char*>* GetRuleNameVecPtr();");
    headerFormatter.WriteLine();
    for (RuleParser* rule : domain.Rules())
    {
        headerFormatter.WriteLine("const int " + ToUtf8(rule->Parent()->Name()) + "_" + ToUtf8(rule->Name()) + " = " + std::to_string(rule->Id()) + ";");
    }
    headerFormatter.WriteLine();
    headerFormatter.WriteLine("#endif // RULES_H");

    std::ofstream ruleSourceFile(domain.RuleSourceFilePath());
    CodeFormatter sourceFormatter(ruleSourceFile);
    sourceFormatter.WriteLine("#include \"" + Path::GetFileName(domain.RuleHeaderFilePath()) + "\"");
    sourceFormatter.WriteLine();
    sourceFormatter.WriteLine("std::vector<const char*> rules = {");
    bool first = true;
    for (RuleParser* rule : domain.Rules())
    {
        if (first)
        {
            first = false;
        }
        else
        {
            sourceFormatter.Write(", ");
        }
        sourceFormatter.WriteLine("\"" + ToUtf8(rule->Parent()->Name()) + "." + ToUtf8(rule->Name()) + "\"");
    }
    sourceFormatter.WriteLine("};");
    sourceFormatter.WriteLine();
    sourceFormatter.WriteLine("std::vector<const char*>* GetRuleNameVecPtr()");
    sourceFormatter.WriteLine("{");
    sourceFormatter.IncIndent();
    sourceFormatter.WriteLine("return &rules;");
    sourceFormatter.DecIndent();
    sourceFormatter.WriteLine("}");
}

void CodeGeneratorVisitor::Visit(Domain& domain)
{
    this->domain = &domain;
    for (const auto& parserFile : domain.ParserFiles())
    {
        parserFile->Accept(*this);
    }
    if (!domain.RuleHeaderFilePath().empty() && !domain.RuleSourceFilePath().empty())
    {
        GenerateRuleFiles(domain);
    }
}

} } // namespae soulng::spg
