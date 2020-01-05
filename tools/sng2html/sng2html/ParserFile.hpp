// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNG2HTML_SNG2HTML_PARSER_FILE_INCLUDED
#define SNG2HTML_SNG2HTML_PARSER_FILE_INCLUDED
#include <sng2html/sng2html/Parser.hpp>

namespace sng2html { namespace sng2html {

class Include
{
public:
    Include(bool hppPrefix_, const std::u32string& str_);
    bool HppPrefix() const { return hppPrefix; }
    const std::u32string& Str() const { return str; }
private:
    bool hppPrefix;
    std::u32string str;
};

class ParserFile
{
public:
    ParserFile(const std::string& fileName_);
    void AddInclude(Include* include);
    void AddUsingNamespace(const std::u32string& usingNs);
    void AddParser(GrammarParser* parser);
    void Accept(Visitor& visitor);
    const std::string& FileName() const { return fileName; }
    const std::vector<std::unique_ptr<Include>>& Includes() const { return includes; }
    const std::vector<std::u32string>& UsingNamespaceDeclarations() const { return usingNamespaceDeclarations; }
    const std::vector<std::unique_ptr<GrammarParser>>& Parsers() const { return parsers; }
private:
    std::string fileName;
    std::vector<std::unique_ptr<Include>> includes;
    std::vector<std::u32string> usingNamespaceDeclarations;
    std::vector<std::unique_ptr<GrammarParser>> parsers;
};

} } // namespace sng2html::sng2html

#endif // SNG2HTML_SNG2HTML_PARSER_FILE_INCLUDED
