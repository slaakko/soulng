// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/parsergen/ParserFile.hpp>
#include <soulng/parsergen/Visitor.hpp>

namespace soulng { namespace parsergen {

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

void ParserFile::AddGrammar(GrammarParser* grammar)
{
    grammars.push_back(std::unique_ptr<GrammarParser>(grammar));
}

void ParserFile::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} } // namespae soulng::parsergen
