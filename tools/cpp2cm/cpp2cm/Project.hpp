// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef CPP2CM_CPP2CM_PROJECT_INCLUDED
#define CPP2CM_CPP2CM_PROJECT_INCLUDED
#include <cpp2cm/cpp2cm/File.hpp>
#include <cpp2cm/cpp2cm/Filter.hpp>
#include <cpp2cm/cpp2cm/NothrowList.hpp>
#include <cpp2cm/cpp2cm/Map.hpp>
#include <cpp2cm/cpp2cm/Patch.hpp>
#include <sngxml/dom/Document.hpp>
#include <sngcpp/pp/PP.hpp>
#include <sngcpp/ast/Node.hpp>
#include <sngcpp/symbols/SymbolTable.hpp>
#include <sngcpp/binder/TypeBinder.hpp>
#include <soulng/lexer/Lexer.hpp>
#include <soulng/rex/Context.hpp>

namespace cpp2cm {

enum class ProcessType
{
    stage, install
};

class Project : public sngcpp::binder::SourceFileResolver
{
public:
    Project(const std::string& systemXmlFilePath_, const std::string& xmlFilePath_, bool nothrowStatus_);
    void Process(bool verbose, ProcessType processType);
    void ReadVCXProjectFilePath();
    void ReadSources();
    void ReadVCSources();
    void ReadTextFiles();
    void ReadIncludePath();
    void ReadTargetDir();
    void ReadInstallDir();
    void ReadFilter();
    void ReadNothrowList();
    void ReadMap();
    void ReadReferences();
    void MapNamespaces(sngxml::dom::Document* mapDoc);
    void BuildAst();
    void WriteAst();
    void ReadAst();
    void Import();
    void ReadSystemProjects();
    void BuildSymbolTable();
    void WriteSymbolTableXml();
    void ReadSymbolTableXml();
    void Convert(ProcessType processType);
    void SetStageDir();
    void SetAstFilePath();
    void SetSystem() { system = true; }
    sngcpp::ast::SourceFileNode* GetSourceFile(const std::string& sourceFilePath) const override;
    void ReadPatchFiles();
    void ReadMergeDirFiles();
private:
    std::string systemXmlFilePath;
    std::string systemRootDir;
    std::string xmlFilePath;
    std::string projectRootDir;
    std::string astFilePath;
    std::string vcxprojectFilePath;
    std::string vcxprojectRootDir;
    std::string targetDir;
    std::string installDir;
    std::string mergeDir;
    std::unique_ptr<sngxml::dom::Document> doc;
    std::u32string name;
    std::u32string type;
    std::u32string targetName;
    std::vector<std::u32string> stageReferences;
    std::vector<std::u32string> installReferences;
    std::vector<File> files;
    std::unique_ptr<sngcpp::ast::Node> ast;
    bool verbose;
    std::string includePath;
    std::vector<std::unique_ptr<soulng::lexer::Lexer>> lexers;
    sngcpp::symbols::SymbolTable symbolTable;
    std::string stageDir;
    std::vector<sngcpp::ast::SourceFileNode*> sourceFiles;
    std::map<std::string, sngcpp::ast::SourceFileNode*> sourceFileMap;
    bool system;
    std::vector<std::unique_ptr<Project>> projects;
    std::unordered_map<std::u32string, Project*> projectMap;
    std::vector<Project*> imports;
    sngcpp::pp::ProjectHeaderFileSet headerFiles;
    soulng::rex::Context context;
    FilterList filters;
    Map map;
    std::unique_ptr<sngxml::dom::Document> symbolTableXmlDoc;
    std::vector<std::unique_ptr<PatchFile>> patchFiles;
    std::set<std::u32string> excludedFunctions;
    std::set<std::u32string> excludedClasses;
    std::vector<std::unique_ptr<File>> mergeDirFiles;
    std::map<std::u32string, File*> mergeFileMap;
    std::vector<std::unique_ptr<File>> extraFiles;
    std::vector<std::u32string> textFiles;
    NothrowList nothrowList;
};

} // namespace cpp2cm

#endif // CPP2CM_CPP2CM_PROJECT_INCLUDED
