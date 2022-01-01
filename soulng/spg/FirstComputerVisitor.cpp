// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/spg/FirstComputerVisitor.hpp>
#include <soulng/spg/Parser.hpp>
#include <soulng/spg/ParserFile.hpp>
#include <soulng/spg/Domain.hpp>
#include <soulng/util/Unicode.hpp>

namespace soulng {namespace spg {

using namespace soulng::unicode;

FirstComputerVisitor::FirstComputerVisitor() : tokens(nullptr), changed(false)
{
}

void FirstComputerVisitor::Visit(EmptyParser& parser)
{
    if (Computed(&parser)) return;
    SetComputed(&parser);
    TokenSet first;
    first.AddToken(tokens->GetToken(nullTokenId));
    if (first != parser.First())
    {
        changed = true;
        parser.SetFirst(first);
    }
}

void FirstComputerVisitor::Visit(AnyParser& parser)
{
    if (Computed(&parser)) return;
    SetComputed(&parser);
    TokenSet first = tokens->GetAll();
    if (first != parser.First())
    {
        changed = true;
        parser.SetFirst(first);
    }
}

void FirstComputerVisitor::Visit(TokenParser& parser)
{
    if (Computed(&parser)) return;
    SetComputed(&parser);
    TokenSet first;
    first.AddToken(tokens->GetToken(ToUtf8(parser.TokenName())));
    if (first != parser.First())
    {
        changed = true;
        parser.SetFirst(first);
    }
}

void FirstComputerVisitor::Visit(CharParser& parser) 
{
    if (Computed(&parser)) return;
    SetComputed(&parser);
    TokenSet first;
    int tokenId = static_cast<int>(parser.Chr());
    Token* token = tokens->GetToken(tokenId);
    first.AddToken(token);
    if (first != parser.First())
    {
        changed = true;
        parser.SetFirst(first);
    }
}

void FirstComputerVisitor::Visit(StringParser& parser) 
{
    if (Computed(&parser)) return;
    SetComputed(&parser);
    TokenSet first;
    if (parser.Str().empty())
    {
        first.AddToken(tokens->GetToken(nullTokenId));
    }
    else
    {
        int tokenId = static_cast<int>(parser.Str()[0]);
        Token* token = tokens->GetToken(tokenId);
        first.AddToken(token);
    }
    if (first != parser.First())
    {
        changed = true;
        parser.SetFirst(first);
    }
}

void FirstComputerVisitor::Visit(CharSetParser& parser)
{
    if (Computed(&parser)) return;
    SetComputed(&parser);
    TokenSet first;
    const CharSet& charSet = parser.Set();
    if (charSet.Inverse())
    {
        first = tokens->GetAll();
        for (const soulng::parser::Range& range : charSet.Ranges())
        {
            for (int tokenId = range.first; tokenId != range.last; ++tokenId)
            {
                first.RemoveToken(tokens->GetToken(tokenId));
            }
        }
    }
    else
    {
        for (const soulng::parser::Range& range : charSet.Ranges())
        {
            for (int tokenId = range.first; tokenId != range.last; ++tokenId)
            {
                first.AddToken(tokens->GetToken(tokenId));
            }
        }
    }
    if (first != parser.First())
    {
        changed = true;
        parser.SetFirst(first);
    }
}

void FirstComputerVisitor::Visit(OptionalParser& parser) 
{
    if (Computed(&parser)) return;
    SetComputed(&parser);
    TokenSet first;
    parser.Child()->Accept(*this);
    first.AddToken(tokens->GetToken(nullTokenId));
    first = first + parser.Child()->First();
    if (first != parser.First())
    {
        changed = true;
        parser.SetFirst(first);
    }
}

void FirstComputerVisitor::Visit(KleeneParser& parser)
{
    if (Computed(&parser)) return;
    SetComputed(&parser);
    TokenSet first;
    parser.Child()->Accept(*this);
    first.AddToken(tokens->GetToken(nullTokenId));
    first = first + parser.Child()->First();
    if (first != parser.First())
    {
        changed = true;
        parser.SetFirst(first);
    }
}

void FirstComputerVisitor::Visit(PositiveParser& parser)
{
    if (Computed(&parser)) return;
    SetComputed(&parser);
    TokenSet first;
    parser.Child()->Accept(*this);
    first = first + parser.Child()->First();
    if (first != parser.First())
    {
        changed = true;
        parser.SetFirst(first);
    }
}

void FirstComputerVisitor::Visit(ExpectationParser& parser)
{
    if (Computed(&parser)) return;
    SetComputed(&parser);
    TokenSet first;
    parser.Child()->Accept(*this);
    first = first + parser.Child()->First();
    if (first != parser.First())
    {
        changed = true;
        parser.SetFirst(first);
    }
}

void FirstComputerVisitor::Visit(GroupingParser& parser)
{
    if (Computed(&parser)) return;
    SetComputed(&parser);
    TokenSet first;
    parser.Child()->Accept(*this);
    first = first + parser.Child()->First();
    if (first != parser.First())
    {
        changed = true;
        parser.SetFirst(first);
    }
}

void FirstComputerVisitor::Visit(SequenceParser& parser)
{
    if (Computed(&parser)) return;
    SetComputed(&parser);
    TokenSet first;
    parser.Left()->Accept(*this);
    parser.Right()->Accept(*this);
    if (!parser.Left()->First().Member(tokens->GetToken(nullTokenId)))
    {
        first = first + parser.Left()->First();
    }
    else
    {
        if (parser.Right()->First().Member(tokens->GetToken(nullTokenId)))
        {
            first = parser.Left()->First() + parser.Right()->First();
        }
        else
        {
            first = parser.Left()->First();
            first.RemoveToken(tokens->GetToken(nullTokenId));
            first = first + parser.Right()->First();
        }
    }
    if (first != parser.First())
    {
        changed = true;
        parser.SetFirst(first);
    }
}

void FirstComputerVisitor::Visit(AlternativeParser& parser)
{
    if (Computed(&parser)) return;
    SetComputed(&parser);
    parser.Left()->Accept(*this);
    parser.Right()->Accept(*this);
    TokenSet first = parser.Left()->First() + parser.Right()->First();
    if (first != parser.First())
    {
        changed = true;
        parser.SetFirst(first);
    }
}

void FirstComputerVisitor::Visit(DifferenceParser& parser)
{
    if (Computed(&parser)) return;
    SetComputed(&parser);
    parser.Left()->Accept(*this);
    parser.Right()->Accept(*this);
    TokenSet first = parser.Left()->First() - parser.Right()->First();
    if (first != parser.First())
    {
        changed = true;
        parser.SetFirst(first);
    }
}

void FirstComputerVisitor::Visit(ListParser& parser)
{
    if (Computed(&parser)) return;
    SetComputed(&parser);
    parser.Child()->Accept(*this);
    TokenSet first = parser.Child()->First();
    if (first != parser.First())
    {
        changed = true;
        parser.SetFirst(first);
    }
}

void FirstComputerVisitor::Visit(LookaheadParser& parser)
{
    if (Computed(&parser)) return;
    SetComputed(&parser);
    parser.Child()->Accept(*this);
    TokenSet first = parser.Child()->First();
    if (first != parser.First())
    {
        changed = true;
        parser.SetFirst(first);
    }
}

void FirstComputerVisitor::Visit(ActionParser& parser)
{
    if (Computed(&parser)) return;
    SetComputed(&parser);
    parser.Child()->Accept(*this);
    TokenSet first = parser.Child()->First();
    if (first != parser.First())
    {
        changed = true;
        parser.SetFirst(first);
    }
}

void FirstComputerVisitor::Visit(NonterminalParser& parser)
{
    if (Computed(&parser)) return;
    SetComputed(&parser);
    parser.Rule()->Accept(*this);
    TokenSet first = parser.Rule()->First();
    if (first != parser.First())
    {
        changed = true;
        parser.SetFirst(first);
    }
}

void FirstComputerVisitor::Visit(RuleParser& parser)
{
    if (Computed(&parser)) return;
    SetComputed(&parser);
    parser.Definition()->Accept(*this);
    TokenSet first = parser.Definition()->First();
    if (first != parser.First())
    {
        changed = true;
        parser.SetFirst(first);
    }
}

void FirstComputerVisitor::Visit(GrammarParser& parser)
{
    if (Computed(&parser)) return;
    SetComputed(&parser);
    for (const std::unique_ptr<RuleParser>& rule : parser.Rules())
    {
        rule->Accept(*this);
    }
}

void FirstComputerVisitor::Visit(ParserFile& parserFile)
{
    for (const std::unique_ptr<GrammarParser>& grammar : parserFile.Parsers())
    {
        grammar->Accept(*this);
    }
}

void FirstComputerVisitor::Visit(Domain& domain)
{
    tokens = domain.GetTokens();
    for (ParserFile* parserFile : domain.ParserFiles())
    {
        parserFile->Accept(*this);
    }
}

} } // namespae soulng::spg
