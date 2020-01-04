// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNG2HTML_SNG2HTML_DOMAIN_INCLUDED
#define SNG2HTML_SNG2HTML_DOMAIN_INCLUDED
#include <sng2html/sng2html/ParserFile.hpp>
#include <map>

namespace sng2html { namespace sng2html {

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

} } // namespace sng2html::sng2html

#endif // SNG2HTML_SNG2HTML_DOMAIN_INCLUDED
