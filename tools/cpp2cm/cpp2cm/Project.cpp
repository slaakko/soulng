// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <cpp2cm/cpp2cm/Project.hpp>
#include <cpp2cm/cpp2cm/Merge.hpp>
#include <cpp2cm/cpp2cm/Converter.hpp>
#include <cpp2cm/cpp2cm/PatchFileParser.hpp>
#include <sngcpp/pp/Evaluator.hpp>
#include <sngcpp/ast/SourceFile.hpp>
#include <sngcpp/lexer/CppLexer.hpp>
#include <sngcpp/parser/SourceFile.hpp>
#include <sngcpp/symbols/SymbolCreator.hpp>
#include <sngcpp/binder/StatementBinder.hpp>
#include <sngcpp/binder/VirtualBinder.hpp>
#include <sngcpp/ast/Reader.hpp>
#include <sngcpp/ast/Writer.hpp>
#include <sngcm/cmlexer/CmajorLexer.hpp>
#include <sngcm/cmparser/CompileUnit.hpp>
#include <sngcm/ast/SourceWriter.hpp>
#include <sngcm/ast/Merge.hpp>
#include <sngxml/dom/Parser.hpp>
#include <sngxml/dom/Element.hpp>
#include <sngxml/xpath/XPathEvaluate.hpp>
#include <soulng/lexer/TrivialLexer.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/Util.hpp>
#include <boost/filesystem.hpp>
#include <iostream>

namespace cpp2cm {

using namespace soulng::util;
using namespace soulng::unicode;

Project::Project(const std::string& systemXmlFilePath_, const std::string& xmlFilePath_, bool nothrowStatus_) :
    systemXmlFilePath(systemXmlFilePath_), systemRootDir(Path::GetDirectoryName(systemXmlFilePath)),
    xmlFilePath(xmlFilePath_), projectRootDir(GetFullPath(Path::GetDirectoryName(xmlFilePath))), doc(sngxml::dom::ReadDocument(xmlFilePath)), verbose(false), system(false),
    nothrowList(nothrowStatus_)
{
    sngxml::dom::Element* projectElement = doc->DocumentElement();
    name = projectElement->GetAttribute(U"name");
    if (name.empty())
    {
        throw std::runtime_error("project name not set in '" + xmlFilePath + "'");
    }
    type = projectElement->GetAttribute(U"type");
    if (type.empty())
    {
        type = U"library";
    }
    targetName = projectElement->GetAttribute(U"targetName");
    if (targetName.empty())
    {
        targetName = name;
    }
    mergeDir = Path::Combine(projectRootDir, "merge");
    SetStageDir();
    SetAstFilePath();
}

void Project::Process(bool verbose, ProcessType processType)
{
    this->verbose = verbose;
    ReadFilter();
    ReadNothrowList();
    ReadVCXProjectFilePath();
    ReadSources();
    ReadTextFiles();
    ReadMergeDirFiles();
    ReadIncludePath();
    ReadTargetDir();
    ReadInstallDir();
    ReadMap();
    ReadReferences();
    BuildAst();
    WriteAst();
    Import();
    BuildSymbolTable();
    WriteSymbolTableXml();
    Convert(processType);
}

void Project::ReadVCXProjectFilePath()
{
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/project/vcxproject", doc.get());
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* vcxprojectElement = static_cast<sngxml::dom::Element*>(node);
                    std::u32string fileAttr = vcxprojectElement->GetAttribute(U"file");
                    if (!fileAttr.empty())
                    {
                        vcxprojectFilePath = GetFullPath(Path::Combine(projectRootDir, Path::MakeCanonical(ToUtf8(fileAttr))));
                        vcxprojectRootDir = Path::GetDirectoryName(vcxprojectFilePath);
                    }
                }
            }
        }
    }
}

void Project::ReadSources()
{
    if (!vcxprojectFilePath.empty())
    {
        ReadVCSources();
        return;
    }
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/project/source", doc.get());
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* sourceElement = static_cast<sngxml::dom::Element*>(node);
                    std::u32string fileAttr = sourceElement->GetAttribute(U"file");
                    if (!fileAttr.empty())
                    {
                        File file(fileAttr, GetFullPath(Path::Combine(projectRootDir, ToUtf8(fileAttr))));
                        filters.Apply(file);
                        if (file.Included())
                        {
                            files.push_back(file);
                        }
                    }
                }
            }
        }
    }
}

void Project::ReadVCSources()
{
    if (verbose)
    {
        std::cout << ToUtf8(name) + "> " << vcxprojectFilePath << std::endl;
    }
    std::unique_ptr<sngxml::dom::Document> vcxProjectDoc = sngxml::dom::ReadDocument(vcxprojectFilePath);
    std::unique_ptr<sngxml::xpath::XPathObject> hppResult = sngxml::xpath::Evaluate(U"/Project/ItemGroup/ClInclude", vcxProjectDoc.get());
    if (hppResult)
    {
        if (hppResult->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(hppResult.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* includeFileElement = static_cast<sngxml::dom::Element*>(node);
                    std::u32string hppFileName = includeFileElement->GetAttribute(U"Include");
                    if (!hppFileName.empty())
                    {
                        File hppFile(hppFileName, GetFullPath(Path::Combine(vcxprojectRootDir, ToUtf8(hppFileName))));
                        filters.Apply(hppFile);
                        if (hppFile.Included())
                        {
                            files.push_back(hppFile);
                            headerFiles.AddProjectHeaderFile(hppFile.Path());
                        }
                    }
                }
            }
        }
    }
    std::unique_ptr<sngxml::xpath::XPathObject> cppResult = sngxml::xpath::Evaluate(U"/Project/ItemGroup/ClCompile", vcxProjectDoc.get());
    if (cppResult)
    {
        if (cppResult->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(cppResult.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* includeFileElement = static_cast<sngxml::dom::Element*>(node);
                    std::u32string cppFileName = includeFileElement->GetAttribute(U"Include");
                    if (!cppFileName.empty())
                    {
                        File cppFile(cppFileName, GetFullPath(Path::Combine(vcxprojectRootDir, ToUtf8(cppFileName))));
                        filters.Apply(cppFile);
                        if (cppFile.Included())
                        {
                            files.push_back(cppFile);
                        }
                    }
                }
            }
        }
    }
}

void Project::ReadTextFiles()
{
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/project/text/file", doc.get());
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* textFileElement = static_cast<sngxml::dom::Element*>(node);
                    std::u32string nameAttribute = textFileElement->GetAttribute(U"name");
                    if (!nameAttribute.empty())
                    {
                        textFiles.push_back(nameAttribute);
                    }
                }
            }
        }
    }
}

void Project::ReadIncludePath()
{
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/project/include", doc.get());
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* sourceElement = static_cast<sngxml::dom::Element*>(node);
                    std::u32string pathAttr = sourceElement->GetAttribute(U"path");
                    if (!pathAttr.empty())
                    {
                        includePath = ToUtf8(pathAttr);
                    }
                }
            }
        }
    }
}

void Project::ReadTargetDir()
{
    if (system) return;
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/project/target", doc.get());
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* targetElement = static_cast<sngxml::dom::Element*>(node);
                    std::u32string dirAttr = targetElement->GetAttribute(U"dir");
                    if (!dirAttr.empty())
                    {
                        targetDir = GetFullPath(Path::Combine(projectRootDir, ToUtf8(dirAttr)));
                    }
                }
            }
        }
    }
    if (targetDir.empty())
    {
        throw std::runtime_error("project target directory not set");
    }
}

void Project::ReadInstallDir()
{
    if (system) return;
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/project/install", doc.get());
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* installElement = static_cast<sngxml::dom::Element*>(node);
                    std::u32string dirAttr = installElement->GetAttribute(U"dir");
                    if (!dirAttr.empty())
                    {
                        installDir = GetFullPath(Path::Combine(projectRootDir, Path::MakeCanonical(ToUtf8(dirAttr))));
                    }
                }
            }
        }
    }
    if (installDir.empty())
    {
        throw std::runtime_error("project install directory not set");
    }
}

void Project::ReadFilter()
{
    std::unique_ptr<sngxml::xpath::XPathObject> fileResult = sngxml::xpath::Evaluate(U"/project/filter/file", doc.get());
    if (fileResult)
    {
        if (fileResult->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(fileResult.get());
            for (int i = 0; i < nodeSet->Length(); ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string excludePattern = element->GetAttribute(U"exclude");
                    if (!excludePattern.empty())
                    {
                        Filter filter(context, Filter::Type::exclude, excludePattern);
                        filters.Add(filter);
                    }
                    else
                    {
                        std::u32string includePattern = element->GetAttribute(U"include");
                        if (!includePattern.empty())
                        {
                            Filter filter(context, Filter::Type::include, includePattern);
                            filters.Add(filter);
                        }
                    }
                }
            }
        }
    }
    std::unique_ptr<sngxml::xpath::XPathObject> functionResult = sngxml::xpath::Evaluate(U"/project/filter/function", doc.get());
    if (functionResult)
    {
        if (functionResult->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(functionResult.get());
            for (int i = 0; i < nodeSet->Length(); ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string excludeAttr = element->GetAttribute(U"exclude");
                    if (!excludeAttr.empty())
                    {
                        excludedFunctions.insert(excludeAttr);
                    }
                }
            }
        }
    }
    std::unique_ptr<sngxml::xpath::XPathObject> classResult = sngxml::xpath::Evaluate(U"/project/filter/class", doc.get());
    if (classResult)
    {
        if (classResult->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(classResult.get());
            for (int i = 0; i < nodeSet->Length(); ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string excludeAttr = element->GetAttribute(U"exclude");
                    if (!excludeAttr.empty())
                    {
                        excludedClasses.insert(excludeAttr);
                    }
                }
            }
        }
    }
}

void Project::ReadNothrowList()
{
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/project/nothrow/item", doc.get());
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            for (int i = 0; i < nodeSet->Length(); ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string typeText = element->GetAttribute(U"type");
                    Item::Type type = Item::Type::none;
                    if (typeText.empty())
                    {
                        throw std::runtime_error("nothrow item type not specified");
                    }
                    if (typeText == U"file")
                    {
                        type = Item::Type::file;
                    }
                    else if (typeText == U"class")
                    {
                        type = Item::Type::class_;
                    }
                    else if (typeText == U"function")
                    {
                        type = Item::Type::function;
                    }
                    else
                    {
                        throw std::runtime_error("unknonwn nothrow item type '" + ToUtf8(typeText) + "'");
                    }
                    std::u32string excludePattern = element->GetAttribute(U"exclude");
                    if (!excludePattern.empty())
                    {
                        NothrowPattern pattern(context, NothrowPattern::Kind::exclude, type, excludePattern);
                        nothrowList.AddPattern(pattern);
                    }
                    else
                    {
                        std::u32string includePattern = element->GetAttribute(U"include");
                        if (!includePattern.empty())
                        {
                            NothrowPattern pattern(context, NothrowPattern::Kind::include, type, includePattern);
                            nothrowList.AddPattern(pattern);
                        }
                        else
                        {
                            throw std::runtime_error("nothrow pattern kind not specified");
                        }
                    }
                }
            }
        }
    }
}

void Project::ReadMap()
{
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/project/map", doc.get());
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            for (int i = 0; i < nodeSet->Length(); ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string mapFileAttr = element->GetAttribute(U"file");
                    if (!mapFileAttr.empty())
                    {
                        std::string mapFilePath = GetFullPath(Path::Combine(projectRootDir, ToUtf8(mapFileAttr)));
                        if (verbose)
                        {
                            std::cout << ToUtf8(name) << "> " << mapFilePath << std::endl;
                        }
                        std::unique_ptr<sngxml::dom::Document> mapDoc = sngxml::dom::ReadDocument(mapFilePath);
                        MapNamespaces(mapDoc.get());
                    }
                }
            }
        }
    }
}

void Project::ReadReferences()
{
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/project/references/reference", doc.get());
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            for (int i = 0; i < nodeSet->Length(); ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string projectAttr = element->GetAttribute(U"project");
                    if (!projectAttr.empty())
                    {
                        std::u32string kindAttr = element->GetAttribute(U"kind");
                        if (kindAttr == U"install")
                        {
                            installReferences.push_back(projectAttr);
                        }
                        else if (kindAttr == U"stage")
                        {
                            stageReferences.push_back(projectAttr);
                        }
                        else
                        {
                            installReferences.push_back(projectAttr);
                            stageReferences.push_back(projectAttr);
                        }
                    }
                }
            }
        }
    }
}

void Project::MapNamespaces(sngxml::dom::Document* mapDoc)
{
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/map/namespace", mapDoc);
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            for (int i = 0; i < nodeSet->Length(); ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string source = element->GetAttribute(U"source");
                    std::u32string target = element->GetAttribute(U"target");
                    map.MapNs(source, target);
                }
            }
        }
    }
}

void Project::SetStageDir()
{
    stageDir = Path::Combine(projectRootDir, "stage");
    boost::filesystem::create_directories(stageDir);
}

void Project::SetAstFilePath()
{
    astFilePath = GetFullPath(Path::Combine(stageDir, ToUtf8(name) + ".ast"));
}

void Project::BuildAst()
{
    sngcpp::pp::EvaluationContext evaluationContext;
    int fileIndex = 0;
    for (const File& file : files)
    {
        if (file.Included())
        {
            std::unique_ptr<sngcpp::ast::SourceFileNode> sourceFile;
            std::unique_ptr<CppLexer> lexer;
            if (verbose)
            {
                std::cout << ToUtf8(name) + "> " << file.Path() << std::endl;
            }
            sngcpp::pp::PP pp(evaluationContext);
            pp.root = vcxprojectRootDir;
            pp.includePath = Split(includePath, ';');
            pp.projectHeaderFileSet = &headerFiles;
            pp.Define(sngcpp::pp::ndebug);
            if (verbose)
            {
                pp.verbose = true;
            }
            Preprocess(file.Path(), &pp);
            std::unique_ptr<std::u32string> content(new std::u32string(std::move(pp.ctext)));
            lexer.reset(new CppLexer(content->c_str(), content->c_str() + content->length(), file.Path(), fileIndex));
            lexer->SetSeparatorChar('\n');
            sourceFile.reset(new sngcpp::ast::SourceFileNode(lexer->GetSpan(), file.Path(), ToUtf8(file.Name()), name));
            sourceFile->SetSourceFileIndex(fileIndex);
            SourceFileParser::Parse(*lexer, sourceFile.get());
            sourceFile->SetHeaderFilePaths(std::move(pp.headerFilePaths));
            sourceFile->SetText(std::move(*content));
            sourceFile->ComputeLineStarts();
            if (ast)
            {
                soulng::lexer::Span span = ast->GetSpan();
                ast.reset(new sngcpp::ast::SourceFileSequenceNode(span, ast.release(), sourceFile.release()));
            }
            else
            {
                ast.reset(sourceFile.release());
            }
            ++fileIndex;
            lexers.push_back(std::unique_ptr<soulng::lexer::Lexer>(lexer.release()));
        }
    }
}

void Project::WriteAst()
{
    if (!ast) return;
    std::vector<soulng::lexer::Lexer*> lx;
    for (const auto& lexer : lexers)
    {
        lx.push_back(lexer.get());
    }
    soulng::util::BinaryWriter binaryWriter(astFilePath);
    sngcpp::ast::Writer writer(lx, binaryWriter);
    ast->Write(writer);
    if (verbose)
    {
        std::cout << ToUtf8(name) << "==> " << astFilePath << std::endl;
    }
}

void Project::ReadAst()
{
    if (!boost::filesystem::exists(astFilePath)) return;
    if (verbose)
    {
        std::cout << ToUtf8(name) + "> " << astFilePath << std::endl;
    }
    soulng::util::BinaryReader binaryReder(astFilePath);
    sngcpp::ast::Reader reader(binaryReder);
    ast.reset(reader.ReadNode());
}

void Project::Import()
{
    ReadSystemProjects();
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/project/imports/import", doc.get());
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string nameAttr = element->GetAttribute(U"name");
                    if (!nameAttr.empty())
                    {
                        auto it = projectMap.find(nameAttr);
                        if (it != projectMap.cend())
                        {
                            Project* importProject = it->second;
                            importProject->system = true;
                            imports.push_back(importProject);
                        }
                        else
                        {
                            throw std::runtime_error("project '" + ToUtf8(nameAttr) + "' not found");
                        }
                    }
                    else
                    {
                        std::u32string projectAttr = element->GetAttribute(U"project");
                        if (!projectAttr.empty())
                        {
                            std::string projectXmlFilePath = GetFullPath(Path::Combine(projectRootDir, ToUtf8(projectAttr)));
                            std::unique_ptr<Project> project(new Project(systemXmlFilePath, projectXmlFilePath, nothrowList.Verbose()));
                            if (verbose)
                            {
                                project->verbose = true;
                            }
                            projectMap[project->name] = project.get();
                            imports.push_back(project.get());
                            projects.push_back(std::move(project));
                        }
                        else
                        {
                            throw std::runtime_error("import must have either 'name' or 'project' attribute");
                        }
                    }
                }
            }
        }
    }
}

void Project::ReadSystemProjects()
{
    if (system) return;
    std::unique_ptr<sngxml::dom::Document> systemXmlDoc = sngxml::dom::ReadDocument(systemXmlFilePath);
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/cpp2cm/projects/project", systemXmlDoc.get());
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string fileAttr = element->GetAttribute(U"file");
                    if (!fileAttr.empty())
                    {
                        std::string projectXmlFilePath = GetFullPath(Path::Combine(systemRootDir, ToUtf8(fileAttr)));
                        std::unique_ptr<Project> project(new Project(systemXmlFilePath, projectXmlFilePath, nothrowList.Verbose()));
                        if (verbose)
                        {
                            project->verbose = true;
                        }
                        projectMap[project->name] = project.get();
                        projects.push_back(std::move(project));
                    }
                }
            }
        }
    }
}

void Project::BuildSymbolTable()
{
    if (!ast) return;
    sngcpp::ast::ResolveSourceFiles(ast.get(), sourceFiles);
    for (auto& sourceFile : sourceFiles)
    {
        sourceFileMap[sourceFile->SourceFilePath()] = sourceFile;
    }
    int n = imports.size();
    for (int i = 0; i < n; ++i)
    {
        Project* importProject = imports[i];
        importProject->ReadAst();
        sngcpp::symbols::SymbolCreator symbolCreator(symbolTable, importProject->name);
        importProject->ast->Accept(symbolCreator);
        sngcpp::binder::TypeBinder typeBinder(symbolTable, this);
        importProject->ast->Accept(typeBinder);
    }
    sngcpp::symbols::SymbolCreator symbolCreator(symbolTable, name);
    if (system)
    {
        symbolCreator.SetCpp2CmMode();
    }
    ast->Accept(symbolCreator);
    sngcpp::binder::TypeBinder typeBinder(symbolTable, this);
    ast->Accept(typeBinder);
    std::vector<std::unique_ptr<sngcpp::binder::BoundSourceFile>> boundSourceFiles = typeBinder.SourceFiles();
    sngcpp::binder::ResolveOverrideSets(typeBinder.ClassesHavingVirtualFunctions());
    std::unordered_map<sngcpp::ast::SourceFileNode*, sngcpp::binder::BoundSourceFile*> boundSourceFileMap = typeBinder.SourceFileMap();
    sngcpp::binder::StatementBinder statementBinder(symbolTable, boundSourceFileMap);
    ast->Accept(statementBinder);
}

void Project::WriteSymbolTableXml()
{
    std::string symbolTableXmlFilePath = GetFullPath(Path::Combine(stageDir, ToUtf8(name) + ".xml"));
    std::unique_ptr<sngxml::dom::Document> symbolTableXmlDoc = symbolTable.ToDomDocument();
    if (system)
    {
        if (boost::filesystem::exists(symbolTableXmlFilePath))
        {
            std::unique_ptr<sngxml::dom::Document> stageSymbolTableXmlDoc = sngxml::dom::ReadDocument(symbolTableXmlFilePath);
            symbolTableXmlDoc = Merge(symbolTableXmlDoc.get(), stageSymbolTableXmlDoc);
        }
    }
    std::ofstream symbolTableXmlFile(symbolTableXmlFilePath);
    soulng::util::CodeFormatter formatter(symbolTableXmlFile);
    symbolTableXmlDoc->Write(formatter);
    if (verbose)
    {
        std::cout << ToUtf8(name) + "==> " << symbolTableXmlFilePath << std::endl;
    }
}

void Project::ReadSymbolTableXml()
{
    std::string symbolTableXmlFilePath = GetFullPath(Path::Combine(stageDir, ToUtf8(name) + ".xml"));
    symbolTableXmlDoc = sngxml::dom::ReadDocument(symbolTableXmlFilePath);
}

void Project::Convert(ProcessType processType)
{
    if (system) return;
    std::string dir;
    if (processType == ProcessType::stage)
    {
        dir = targetDir;
    }
    else if (processType == ProcessType::install)
    {
        dir = installDir;
    }
    boost::filesystem::create_directories(dir);
    map.SetCurrentProjectName(name);
    Converter converter(verbose, targetDir, symbolTable, map, excludedClasses, excludedFunctions, nothrowList);
    map.SetSymbolTable(&symbolTable);
    for (Project* importProject : imports)
    {
        if (importProject->system)
        {
            importProject->ReadSymbolTableXml();
            map.AddSourceXmlDoc(importProject->symbolTableXmlDoc.get(), importProject->name);
        }
    }
    ast->Accept(converter);
    converter.Write();
    ReadPatchFiles();
    SourceFiles& sourceFiles = converter.GetSourceFiles();
    sourceFiles.Sort();
    if (!patchFiles.empty())
    {
        if (verbose)
        {
            std::cout << "patching:" << std::endl;
        }
        for (const auto& patchFile : patchFiles)
        {
            if (verbose)
            {
                std::cout << "> " << patchFile->Path() << std::endl;
            }
            sourceFiles.Apply(patchFile.get());
        }
    }
    sourceFiles.Write();
    if (boost::filesystem::exists(mergeDir))
    {
        if (verbose)
        {
            std::cout << "merging:" << std::endl;
        }
        for (const auto& sourceFile : sourceFiles.Get())
        {
            std::string sourceFilePath = GetFullPath(Path::Combine(mergeDir, ToUtf8(sourceFile->Name())));
            if (boost::filesystem::exists(sourceFilePath))
            {
                auto it = mergeFileMap.find(sourceFile->Name());
                if (it != mergeFileMap.cend())
                {
                    File* mergeFile = it->second;
                    mergeFile->SetIncluded(true);
                }
                std::string sourceContent = ReadFile(sourceFilePath);
                CmajorLexer sourceLexer(ToUtf32(sourceContent), sourceFilePath, 0);
                ParsingContext sourceCtx;
                std::unique_ptr<sngcm::ast::CompileUnitNode> sourceCu = CompileUnitParser::Parse(sourceLexer, &sourceCtx);
                std::string targetFilePath = sourceFile->Path();
                std::string targetContent = ReadFile(targetFilePath);
                CmajorLexer targetLexer(ToUtf32(targetContent), targetFilePath, 0);
                ParsingContext targetCtx;
                std::unique_ptr<sngcm::ast::CompileUnitNode> targetCu = CompileUnitParser::Parse(targetLexer, &targetCtx);
                sngcm::ast::Merge(*sourceCu, *targetCu);
                sngcm::ast::ArrangeClassMembers(*targetCu);
                std::ofstream targetFile(targetFilePath);
                CodeFormatter formatter(targetFile);
                sngcm::ast::SourceWriter sourceWriter(formatter);
                targetCu->Accept(sourceWriter);
                if (verbose)
                {
                    std::cout << "==> " << targetFilePath << " <- " << sourceFilePath << std::endl;
                }
            }
        }
        for (const auto& mergeFile : mergeDirFiles)
        {
            if (!mergeFile->Included())
            {
                std::string sourceFilePath = mergeFile->Path();
                if (boost::filesystem::exists(sourceFilePath))
                {
                    std::string sourceContent = ReadFile(sourceFilePath);
                    CmajorLexer sourceLexer(ToUtf32(sourceContent), sourceFilePath, 0);
                    ParsingContext sourceCtx;
                    std::unique_ptr<sngcm::ast::CompileUnitNode> cu = CompileUnitParser::Parse(sourceLexer, &sourceCtx);
                    File* target = new File(mergeFile->Name(), GetFullPath(Path::Combine(targetDir, Path::GetFileName(mergeFile->Path()))));
                    std::string targetFilePath = target->Path();
                    std::ofstream targetFile(targetFilePath);
                    CodeFormatter formatter(targetFile);
                    sngcm::ast::SourceWriter sourceWriter(formatter);
                    cu->Accept(sourceWriter);
                    extraFiles.push_back(std::unique_ptr<File>(target));
                    if (verbose)
                    {
                        std::cout << "==> " << targetFilePath << " <- " << sourceFilePath << std::endl;
                    }
                }
            }
        }
    }
    if (processType == ProcessType::install)
    {
        if (verbose)
        {
            std::cout << "installing:" << std::endl;
        }
        for (const auto& sourceFile : sourceFiles.Get())
        {
            std::string targetFilePath = Path::Combine(dir, ToUtf8(sourceFile->Name()));
            if (boost::filesystem::exists(targetFilePath))
            {
                boost::filesystem::remove(targetFilePath);
            }
            boost::filesystem::copy_file(sourceFile->Path(), targetFilePath);
            if (verbose)
            {
                std::cout << sourceFile->Path() << " -> " << targetFilePath << std::endl;
            }
        }
        for (const auto& extraFile : extraFiles)
        {
            std::string targetFilePath = Path::Combine(dir, ToUtf8(extraFile->Name()));
            if (boost::filesystem::exists(targetFilePath))
            {
                boost::filesystem::remove(targetFilePath);
            }
            boost::filesystem::copy_file(extraFile->Path(), targetFilePath);
            if (verbose)
            {
                std::cout << extraFile->Path() << " -> " << targetFilePath << std::endl;
            }
        }
    }
    if (verbose)
    {
        std::cout << "creating project file:" << std::endl;
    }
    std::string projectFilePath = Path::Combine(dir, ToUtf8(targetName) + ".cmp");
    std::ofstream projectFile(projectFilePath);
    CodeFormatter formatter(projectFile);
    formatter.WriteLine("project " + ToUtf8(targetName) + ";");
    if (type == U"library")
    {
        formatter.WriteLine("target=library;");
    }
    else if (type == U"program")
    {
        formatter.WriteLine("target=program;");
    }
    if (processType == ProcessType::stage)
    {
        for (const auto& reference : stageReferences)
        {
            formatter.WriteLine("reference <" + ToUtf8(reference) + ">;");
        }
    }
    else if (processType == ProcessType::install)
    {
        for (const auto& reference : installReferences)
        {
            formatter.WriteLine("reference <" + ToUtf8(reference) + ">;");
        }
    }
    std::vector<std::u32string> sourceFileNames;
    for (const auto& sourceFile : sourceFiles.Get())
    {
        sourceFileNames.push_back(sourceFile->Name());
    }
    for (const auto& extraFile : extraFiles)
    {
        sourceFileNames.push_back(extraFile->Name());
    }
    for (const auto& textFile : textFiles)
    {
        sourceFileNames.push_back(textFile);
    }
    std::sort(sourceFileNames.begin(), sourceFileNames.end());
    for (const auto& sourceFileName : sourceFileNames)
    {
        if (Path::GetExtension(ToUtf8(sourceFileName)) == ".cm")
        {
            formatter.WriteLine("source <" + ToUtf8(sourceFileName) + ">;");
        }
        else
        {
            formatter.WriteLine("text <" + ToUtf8(sourceFileName) + ">;");
        }
    }
    if (verbose)
    {
        std::cout << "==> " << projectFilePath << std::endl;
    }
}

void Project::ReadPatchFiles()
{
    int index = 0;
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/project/patches/patch", doc.get());
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string file = element->GetAttribute(U"file");
                    if (!file.empty())
                    {
                        std::string patchFilePath = GetFullPath(Path::Combine(projectRootDir, ToUtf8(file)));
                        std::string content = ReadFile(patchFilePath);
                        std::u32string text = ToUtf32(content);
                        if (!text.empty())
                        {
                            TrivialLexer lexer(text, patchFilePath, index++);
                            std::unique_ptr<cpp2cm::PatchFile> patchFile = PatchFileParser::Parse(lexer);
                            patchFiles.push_back(std::move(patchFile));
                        }
                    }
                }
            }
        }
    }
}

void Project::ReadMergeDirFiles()
{
    if (!boost::filesystem::exists(mergeDir)) return;
    boost::filesystem::directory_iterator it = boost::filesystem::directory_iterator(mergeDir);
    while (it != boost::filesystem::directory_iterator())
    {
        const boost::filesystem::directory_entry& entry = *it;
        if (entry.status().type() == boost::filesystem::file_type::regular_file)
        {
            std::string filePath = entry.path().generic_string();
            if (Path::GetExtension(filePath) == ".cm")
            {
                File* file = new File(ToUtf32(Path::GetFileName(filePath)), GetFullPath(filePath));
                file->SetIncluded(false);
                mergeDirFiles.push_back(std::unique_ptr<File>(file));
                mergeFileMap[file->Name()] = file;
            }
        }
        ++it;
    }
}

sngcpp::ast::SourceFileNode* Project::GetSourceFile(const std::string& sourceFilePath) const
{
    auto it = sourceFileMap.find(sourceFilePath);
    if (it != sourceFileMap.cend())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}

} // namespace cpp2cm
