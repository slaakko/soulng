// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/spg/Domain.hpp>
#include <soulng/spg/Visitor.hpp>
#include <soulng/util/Unicode.hpp>

namespace soulng { namespace spg {

using namespace soulng::unicode;

void Domain::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void Domain::AddParserFile(ParserFile* parserFile)
{
    parserFiles.push_back(parserFile);
}

void Domain::AddParser(GrammarParser* parser)
{
    auto it = parserMap.find(parser->Name());
    if (it != parserMap.cend())
    {
        throw std::runtime_error("parser '" + ToUtf8(parser->Name()) + "' already exists");
    }
    parserMap[parser->Name()] = parser;
}

GrammarParser* Domain::GetParser(const std::u32string& parserName) const
{
    auto it = parserMap.find(parserName);
    if (it != parserMap.cend())
    {
        return it->second;
    }
    else
    {
        throw std::runtime_error("parser '" + ToUtf8(parserName) + "' not found");
    }
}

} } // namespae soulng::spg
