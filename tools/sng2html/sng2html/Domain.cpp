// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sng2html/sng2html/Domain.hpp>
#include <sng2html/sng2html/Visitor.hpp>
#include <soulng/util/Unicode.hpp>

namespace sng2html { namespace sng2html {

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

} } // namespace sng2html::sng2html
