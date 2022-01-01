// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef GENDOC_GENDOC_PROJECT_INCLUDED
#define GENDOC_GENDOC_PROJECT_INCLUDED
#include <gendoc/gendoc/File.hpp>
#include <gendoc/gendoc/Filter.hpp>
#include <gendoc/html/Grammar.hpp>
#include <gendoc/html/HtmlContentFilePathResolver.hpp>
#include <sngcpp/pp/File.hpp>
#include <sngcpp/ast/SourceFile.hpp>
#include <sngcpp/binder/TypeBinder.hpp>
#include <sngcpp/symbols/SymbolTable.hpp>
#include <sngxml/dom/Document.hpp>
#include <soulng/lexer/Lexer.hpp>
#include <soulng/rex/Context.hpp>

namespace gendoc {

class Import
{
public:
    Import(const std::u32string& name_, const std::string& relativePath_);
    const std::u32string& Name() const { return name; }
    const std::string& RelativePath() const { return relativePath; }
private:
    std::u32string name;
    std::string relativePath;
};

class Project : public gendoc::html::HtmlContentFilePathResolver, public sngcpp::binder::SourceFileResolver
{
public:
    Project(const std::string& docFilePath_);
    void Process(bool verbose, bool rebuild, bool single);
    void Clean(bool verbose, bool single);
    void ReadChildren();
    void RunChildren(bool verbose, bool rebuild, bool clean, bool single);
    void RunChildrenWithFlags(bool verbose, bool rebuild, const std::string& flags);
    void RunChildrenSingle(bool verbose, bool rebuild, bool clean, bool ast, bool content);
    void GenerateAst(bool verbose, bool rebuild, bool readAst);
    void GenerateContent(bool verbose, bool rebuild, bool endMessage, bool single);
    void ReadName();
    void ReadTop();
    void ReadParentNameAndSiblings();
    void ReadFilter();
    void ReadIncludePath();
    void ReadFilePaths(bool verbose);
    void ReadImports();
    void SetAstFilePath();
    void SetContentXmlFilePath();
    void SetHtmlFilePath();
    bool BuildAst(bool verbose, bool rebuild);
    void WriteAst(bool verbose);
    void ReadAst(bool verbose);
    void ImportAsts(bool verbose);
    void BuildSymbolTable();
    void GenerateContentXml(bool verbose, bool rebuild);
    void WriteContentXml(bool verbose);
    void ReadContentXml(bool verbose);
    void MakeDirectories();
    void GenerateStyleSheet();
    void GenerateHtmlCodeFiles(bool verbose, bool rebuild);
    void ReadGrammarXmlFiles(bool verbose);
    void GenerateHtmlContent(bool verbose, bool rebuild);
    void ReadDocumentationXml(bool verbose, bool& rebuild);
    std::string ResolveContentFilePath(const std::u32string& currentProjectName, const std::u32string& projectName, const std::string& relativeContentDirPath,
        const std::u32string& symbolId) override;
    sngcpp::ast::SourceFileNode* GetSourceFile(const std::string& sourceFilePath) const override;
private:
    bool childrenRead;
    std::vector<std::string> children;
    std::vector<std::u32string> childProjects;
    std::vector<std::u32string> childNames;
    std::vector<std::u32string> siblingProjects;
    int thisProjectIndex;
    std::u32string name;
    std::u32string parentName;
    std::u32string topLink;
    soulng::rex::Context context;
    std::string docFilePath;
    std::string rootDir;
    std::unique_ptr<sngxml::dom::Document> doc;
    FilterList filters;
    std::string projectRoot;
    std::vector<File> filePaths;
    std::string includePath;
    std::string astFilePath;
    std::unique_ptr<sngcpp::ast::Node> ast;
    std::vector<std::unique_ptr<Import>> imports;
    std::vector<std::string> importAstFilePaths;
    std::vector<std::unique_ptr<sngcpp::ast::Node>> importAsts;
    std::vector<std::unique_ptr<soulng::lexer::Lexer>> lexers;
    sngcpp::symbols::SymbolTable symbolTable;
    std::unique_ptr<sngxml::dom::Document> contentXml;
    sngcpp::pp::ProjectHeaderFileSet headerFiles;
    std::string htmlFilePath;
    std::string htmlDir;
    std::string contentDir;
    std::string fileDir;
    std::string styleDir;
    std::string styleDirName;
    std::string styleFileName;
    std::vector<sngcpp::ast::SourceFileNode*> sourceFiles;
    std::vector<std::vector<sngcpp::ast::SourceFileNode*>> importSourceFiles;
    std::map<std::string, sngcpp::ast::SourceFileNode*> sourceFileMap;
    std::unordered_map<std::u32string, std::unique_ptr<sngxml::dom::Element>> inlineCodeMap;
    std::string contentXmlFilePath;
    bool contentXmlUpToDate;
    bool astGenerated;
    bool upToDate;
    std::map<std::u32string, Import*> importMap;
    std::string documentationXmlFileName;
    std::unique_ptr<sngxml::dom::Document> documentationXml;
    std::string grammarsXmlFilePath;
    std::unique_ptr<sngxml::dom::Document> grammarsXmlDoc;
    std::vector<gendoc::html::Grammar> grammars;
};

} // namespace gendoc

#endif // GENDOC_GENDOC_PROJECT_INCLUDED
