// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/spg/ParserFile.hpp>
#include <soulng/spg/Visitor.hpp>

namespace soulng { namespace spg {

Include::Include(bool hppPrefix_, const std::u32string& str_) : hppPrefix(hppPrefix_), str(str_)
{
}

ParserFile::ParserFile(const std::string& fileName_) : fileName(fileName_)
{
}

void ParserFile::AddInclude(Include* include)
{
    includes.push_back(std::unique_ptr<Include>(include));
}

void ParserFile::AddUsingNamespace(const std::u32string& usingNs)
{
    usingNamespaceDeclarations.push_back(usingNs);
}

void ParserFile::AddParser(GrammarParser* parser)
{
    parsers.push_back(std::unique_ptr<GrammarParser>(parser));
}

void ParserFile::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ParserFile::Write(CodeFormatter& formatter)
{
    for (std::unique_ptr<GrammarParser>& parser : parsers)
    {
        parser->Write(formatter);
    }
}

} } // namespae soulng::spg
