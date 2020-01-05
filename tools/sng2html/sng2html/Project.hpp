// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNG2HTML_SNG2HTML_PROJECT_INCLUDED
#define SNG2HTML_SNG2HTML_PROJECT_INCLUDED
#include <sng2html/sng2html/Domain.hpp>
#include <sng2html/sng2html/LexerFile.hpp>
#include <sng2html/sng2html/ParserFile.hpp>
#include <sng2html/sng2html/Grammar.hpp>
#include <sng2html/sng2html/LexerContext.hpp>
#include <sngxml/dom/Document.hpp>
#include <sngxml/dom/Parser.hpp>

namespace sng2html { namespace sng2html {

class Project
{
public:
    Project(bool verbose_, const std::string& xmlFilePath_);
    void Process();
    void ReadLexerFiles();
    void ReadParserFiles();
    void ReadOutDir();
    void ReadStyleFilePath();
    void ReadGrammarFiles();
    void Link();
    void ParseLexerFiles();
    void GenerateHtml();
private:
    bool verbose;
    std::string xmlFilePath;
    std::string rootDir;
    std::unique_ptr<sngxml::dom::Document> xmlDoc;
    std::vector<std::unique_ptr<LexerFile>> lexerFiles;
    std::vector<std::unique_ptr<ParserFile>> parserFiles;
    Domain domain;
    std::unordered_map<std::u32string, LexerFile*> lexerMap;
    std::string outDir;
    std::u32string styleFilePath;
    std::vector<std::unique_ptr<Grammar>> grammars;
    std::unordered_map<GrammarParser*, Grammar*> parserGrammarMap;
    std::unordered_map<RuleParser*, Rule*> parserRuleMap;
    std::unordered_map<LexerFile*, Grammar*> lexerGrammarMap;
    std::unordered_map<Expression*, Rule*> lexerRuleMap;
    LexerContext lexerContext;
};

} } // namespace sng2html::sng2html

#endif // SNG2HTML_SNG2HTML_PROJECT_INCLUDED
