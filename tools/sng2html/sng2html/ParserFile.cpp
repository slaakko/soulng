// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sng2html/sng2html/ParserFile.hpp>
#include <sng2html/sng2html/Visitor.hpp>

namespace sng2html { namespace sng2html {

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

} } // namespace sng2html::sng2html
