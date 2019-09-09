// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_PARSERGEN_DOMAIN_INCLUDED
#define SOULNG_PARSERGEN_DOMAIN_INCLUDED
#include <soulng/parsergen/ParserFile.hpp>
#include <map>

namespace soulng { namespace parsergen {

class Domain
{
public:
    void Accept(Visitor& visitor);
    void AddParserFile(ParserFile* parserFile);
    const std::vector<ParserFile*>& ParserFiles() const { return parserFiles; }
    void AddGrammar(GrammarParser* grammar);
    GrammarParser* GetGrammar(const std::u32string& grammarName) const;
private:
    std::vector<ParserFile*> parserFiles;
    std::map<std::u32string, GrammarParser*> grammarMap;
};

} } // namespae soulng::parsergen

#endif // SOULNG_PARSERGEN_DOMAIN_INCLUDED
