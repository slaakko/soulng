// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SPG_DOMAIN_INCLUDED
#define SOULNG_SPG_DOMAIN_INCLUDED
#include <soulng/spg/ParserFile.hpp>
#include <map>

namespace soulng { namespace spg {

class Domain
{
public:
    void Accept(Visitor& visitor);
    void AddParserFile(ParserFile* parserFile);
    const std::vector<ParserFile*>& ParserFiles() const { return parserFiles; }
    void AddParser(GrammarParser* parser);
    GrammarParser* GetParser(const std::u32string& parserName) const;
private:
    std::vector<ParserFile*> parserFiles;
    std::map<std::u32string, GrammarParser*> parserMap;
};

} } // namespae soulng::spg

#endif // SOULNG_SPG_DOMAIN_INCLUDED
