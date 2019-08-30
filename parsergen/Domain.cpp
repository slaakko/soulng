// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/parsergen/Domain.hpp>
#include <soulng/parsergen/Visitor.hpp>
#include <soulng/util/Unicode.hpp>

namespace soulng { namespace parsergen {

using namespace soulng::unicode;

void Domain::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void Domain::AddParserFile(ParserFile* parserFile)
{
    parserFiles.push_back(parserFile);
}

void Domain::AddGrammar(GrammarParser* grammar)
{
    auto it = grammarMap.find(grammar->Name());
    if (it != grammarMap.cend())
    {
        throw std::runtime_error("parser '" + ToUtf8(grammar->Name()) + "' already exists");
    }
    grammarMap[grammar->Name()] = grammar;
}

GrammarParser* Domain::GetGrammar(const std::u32string& grammarName) const
{
    auto it = grammarMap.find(grammarName);
    if (it != grammarMap.cend())
    {
        return it->second;
    }
    else
    {
        throw std::runtime_error("parser '" + ToUtf8(grammarName) + "' not found");
    }
}

} } // namespae soulng::parsergen
