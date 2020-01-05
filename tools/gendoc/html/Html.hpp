// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef GENDOC_HTML_HTML_INCLUDED
#define GENDOC_HTML_HTML_INCLUDED
#include <gendoc/html/HtmlApi.hpp>
#include <gendoc/html/HtmlContentFilePathResolver.hpp>
#include <gendoc/html/Grammar.hpp>
#include <sngxml/dom/Document.hpp>
#include <sngcpp/ast/SourceFile.hpp>
#include <sngcpp/symbols/SymbolTable.hpp>

namespace gendoc { namespace html {

GENDOC_HTML_API void InitHeaderElementNames();
GENDOC_HTML_API void MakeDirectories(const std::string& targetDir, std::string& htmlDir, std::string& contentDir, std::string& fileDir, std::string& styleDir);
GENDOC_HTML_API void GenerateStyleSheet(const std::string& styleDir, std::string& styleDirName, std::string& styleFileName);
GENDOC_HTML_API void GenerateModuleHtml(const std::u32string& projectName, const std::u32string& parentProjectName, const std::u32string& prevProject, const std::u32string& nextProject,
    const std::vector<std::u32string>& childProjects, const std::vector<std::u32string>& childProjectNames,
    sngxml::dom::Document* contentXml, const std::string& contentDir, const std::string& styleDirName, const std::string& styleFileName,
    const std::vector<sngcpp::ast::SourceFileNode*>& sourceFiles, const std::string& contentXmlFilePath, bool verbose, bool rebuild, bool& upToDate,
    HtmlContentFilePathResolver* contentFilePathResolver, const std::u32string& topLink, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml,
    const std::vector<Grammar>& grammars);
GENDOC_HTML_API void GenerateContent(const std::u32string& projectName, sngxml::dom::Document* contentXml, const std::string& contentDir, const std::string& styleDirName, const std::string& styleFileName,
    std::unordered_map<std::u32string, std::unique_ptr<sngxml::dom::Element>>& inlineCodeMap, const std::string& contentXmlFilePath, bool verbose, bool rebuild, bool& upToDate,
    HtmlContentFilePathResolver* contentFilePathResolver, const std::u32string& topLink, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml);
GENDOC_HTML_API void GenerateHtmlCodeFiles(const std::u32string& projectName, const std::vector<sngcpp::ast::SourceFileNode*>& sourceFiles, const std::string& styleDirName, const std::string& styleFileName,
    sngcpp::symbols::SymbolTable& symbolTable, int inlineCodeLimit, std::unordered_map<std::u32string, std::unique_ptr<sngxml::dom::Element>>& inlineCodeMap, bool verbose, bool rebuild,
    bool& upToDate, HtmlContentFilePathResolver* contentFilePathResolver);

} } // namespace gendoc::html

#endif // GENDOC_HTML_HTML_INCLUDED
