// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_PARSERGEN_PARSER_FILE_INCLUDED
#define SOULNG_PARSERGEN_PARSER_FILE_INCLUDED
#include <soulng/parsergen/Parser.hpp>

namespace soulng { namespace parsergen {

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
    void AddGrammar(GrammarParser* grammar);
    void Accept(Visitor& visitor);
    const std::string& FileName() const { return fileName; }
    const std::vector<std::unique_ptr<Include>>& Includes() const { return includes; }
    const std::vector<std::u32string>& UsingNamespaceDeclarations() const { return usingNamespaceDeclarations; }
    const std::vector<std::unique_ptr<GrammarParser>>& Grammars() const { return grammars; }
private:
    std::string fileName;
    std::vector<std::unique_ptr<Include>> includes;
    std::vector<std::u32string> usingNamespaceDeclarations;
    std::vector<std::unique_ptr<GrammarParser>> grammars;
};

} } // namespae soulng::parsergen

#endif // SOULNG_PARSERGEN_PARSER_FILE_INCLUDED
