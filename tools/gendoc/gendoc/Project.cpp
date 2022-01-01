// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <gendoc/gendoc/Project.hpp>
#include <gendoc/html/Html.hpp>
#include <sngcpp/pp/PP.hpp>
#include <sngcpp/lexer/CppLexer.hpp>
#include <sngcpp/parser/SourceFile.hpp>
#include <sngcpp/symbols/SymbolCreator.hpp>
#include <sngcpp/binder/VirtualBinder.hpp>
#include <sngcpp/binder/StatementBinder.hpp>
#include <sngcpp/ast/Writer.hpp>
#include <sngcpp/ast/Reader.hpp>
#include <sngxml/xpath/XPathEvaluate.hpp>
#include <sngxml/xpath/XPathDebug.hpp>
#include <sngxml/dom/Parser.hpp>
#include <sngxml/dom/Document.hpp>
#include <sngxml/dom/Element.hpp>
#include <soulng/util/BinaryWriter.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/System.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/Util.hpp>
#include <boost/filesystem.hpp>
#include <boost/process.hpp>
#include <iostream>
#include <fstream>

namespace gendoc {

const int inlineCodeLimit = 10;

using namespace soulng::util;
using namespace soulng::unicode;

Import::Import(const std::u32string& name_, const std::string& relativePath_) : name(name_), relativePath(relativePath_)
{
}

Project::Project(const std::string& docFilePath_) :
    docFilePath(docFilePath_), rootDir(Path::GetDirectoryName(docFilePath)), doc(sngxml::dom::ReadDocument(docFilePath)), contentXmlUpToDate(false), astGenerated(false), thisProjectIndex(-1),
    childrenRead(false)
{
}

void Project::Process(bool verbose, bool rebuild, bool single)
{
    ReadName();
    RunChildren(verbose, rebuild, false, single);
    GenerateAst(verbose, rebuild, true);
    GenerateContent(verbose, rebuild, false, single);
}

void Project::Clean(bool verbose, bool single)
{
    ReadName();
    if (verbose)
    {
        std::cout << "cleaning " << ToUtf8(name) << "..." << std::endl;
    }
    RunChildren(verbose, false, true, single);
    SetAstFilePath();
    SetContentXmlFilePath();
    SetHtmlFilePath();
    boost::filesystem::remove(astFilePath);
    boost::filesystem::remove(contentXmlFilePath);
    boost::filesystem::remove(htmlFilePath);
    boost::filesystem::remove(Path::Combine(rootDir, "status.msg"));
    boost::filesystem::remove_all(Path::Combine(rootDir, "html"));
    if (verbose)
    {
        std::cout << "> " << ToUtf8(name) << " cleaned" << std::endl;
    }
}

void Project::ReadChildren()
{
    if (childrenRead) return;
    childrenRead = true;
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/gendoc/child", doc.get());
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
                    std::u32string project = element->GetAttribute(U"project");
                    if (!project.empty())
                    {
                        std::string childFilePath = Path::Combine(Path::Combine(rootDir, ToUtf8(project)), "gendoc.xml");
                        children.push_back(childFilePath);
                        std::u32string childProject = project;
                        std::unique_ptr<sngxml::dom::Document> childDoc = sngxml::dom::ReadDocument(childFilePath);
                        std::unique_ptr<sngxml::xpath::XPathObject> childResult = sngxml::xpath::Evaluate(U"/gendoc/project", childDoc.get());
                        if (childResult)
                        {
                            if (childResult->Type() == sngxml::xpath::XPathObjectType::nodeSet)
                            {
                                sngxml::xpath::XPathNodeSet* childNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(childResult.get());
                                for (int i = 0; i < childNodeSet->Length(); ++i)
                                {
                                    sngxml::dom::Node* childNode = (*childNodeSet)[i];
                                    if (childNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
                                    {
                                        sngxml::dom::Element* childElement = static_cast<sngxml::dom::Element*>(childNode);
                                        std::u32string childName = childElement->GetAttribute(U"name");
                                        if (!childName.empty())
                                        {
                                            childProject.append(1, '/').append(childName).append(U".html");
                                            childProjects.push_back(std::move(childProject));
                                            childNames.push_back(childName);
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Project::RunChildren(bool verbose, bool rebuild, bool clean, bool single)
{
    ReadChildren();
    if (children.empty()) return;
    if (clean)
    {
        if (verbose)
        {
            std::cout << ToUtf8(name) << "> cleaning " << children.size() << " child projects..." << std::endl;
        }
        if (single)
        {
            RunChildrenSingle(verbose, false, clean, false, false);
        }
        else
        {
            RunChildrenWithFlags(verbose, false, "l");
        }
        if (verbose)
        {
            std::cout << ToUtf8(name) << "> " << children.size() << " child projects cleaned." << std::endl;
        }
    }
    else
    {
        if (verbose)
        {
            std::cout << ToUtf8(name) << "> building " << children.size() << " child projects..." << std::endl;
            for (const auto& child : children)
            {
                boost::filesystem::remove(GetFullPath(Path::Combine(Path::GetDirectoryName(child), "status.msg")));
            }
            std::cout << ToUtf8(name) << "> generating ASTs..." << std::endl;
        }
        if (single)
        {
            RunChildrenSingle(verbose, rebuild, false, true, false);
        }
        else
        {
            RunChildrenWithFlags(verbose, rebuild, "a");
        }
        if (verbose)
        {
            std::cout << ToUtf8(name) << "> ASTs ready." << std::endl;
            std::cout << ToUtf8(name) << "> generating content..." << std::endl;
        }
        if (single)
        {
            RunChildrenSingle(verbose, rebuild, false, false, true);
        }
        else
        {
            RunChildrenWithFlags(verbose, rebuild, "ce");
        }
        if (verbose)
        {
            std::cout << ToUtf8(name) << "> content ready." << std::endl;
            for (const auto& child : children)
            {
                std::string statusMessageFilePath = GetFullPath(Path::Combine(Path::GetDirectoryName(child), "status.msg"));
                if (boost::filesystem::exists(statusMessageFilePath))
                {
                    std::string statusMessage = soulng::util::ReadFile(statusMessageFilePath);
                    std::cout << statusMessage;
                }
            }
            std::cout << ToUtf8(name) << "> " << children.size() << " child projects built or up-to-date." << std::endl;
        }
    }
}

void Project::RunChildrenSingle(bool verbose, bool rebuild, bool clean, bool ast, bool content)
{
    for (int i = 0; i < children.size(); ++i)
    {
        Project project(children[i]);
        if (clean)
        {
            project.Clean(verbose, false);
        }
        else if (ast)
        {
            project.GenerateAst(verbose, rebuild, false);
        }
        else if (content)
        {
            project.GenerateContent(verbose, rebuild, false, false);
        }
    }
}

void Project::RunChildrenWithFlags(bool verbose, bool rebuild, const std::string& flags)
{
    std::string f = "-";
    if (verbose)
    {
        f.append("v");
    }
    if (rebuild)
    {
        f.append("r");
    }
    f.append(flags);
    std::vector<boost::process::ipstream> is;
    std::vector<boost::process::ipstream> es;
    std::vector<boost::process::child> childProcesses;
    for (int i = 0; i < children.size(); ++i)
    {
        if (verbose)
        {
            std::cout << ToUtf8(name) + ">> " << children[i] << std::endl;
        }
        is.push_back(boost::process::ipstream());
        es.push_back(boost::process::ipstream());
        boost::process::child child = boost::process::child(GetPathToExecutable(), f, children[i], boost::process::std_out > is[i], boost::process::std_err > es[i]);
        childProcesses.push_back(std::move(child));
    }
    bool running = true;
    while (running)
    {
        running = false;
        for (int i = 0; i < childProcesses.size(); ++i)
        {
            if (childProcesses[i].running())
            {
                std::string line;
                if (std::getline(is[i], line) && !line.empty())
                {
                    std::cout << line << std::endl;
                }
                running = true;
            }
        }
    }
    for (int i = 0; i < childProcesses.size(); ++i)
    {
        childProcesses[i].wait();
        int result = childProcesses[i].exit_code();
        if (result != 0)
        {
            std::string line;
            while (std::getline(es[i], line) && !line.empty())
            {
                std::cerr << line << std::endl;
            }
            throw std::runtime_error("child returned exit code " + std::to_string(result));
        }
    }
}

void Project::GenerateAst(bool verbose, bool rebuild, bool readAst)
{
    ReadName();
    ReadChildren();
    if (!children.empty()) return;
    ReadTop();
    ReadParentNameAndSiblings();
    ReadFilter();
    ReadFilePaths(verbose);
    ReadImports();
    ReadIncludePath();
    SetAstFilePath();
    SetContentXmlFilePath();
    if (BuildAst(verbose, rebuild))
    {
        WriteAst(verbose);
    }
    else if (readAst)
    {
        ReadAst(verbose);
    }
    astGenerated = true;
}

void Project::GenerateContent(bool verbose, bool rebuild, bool endMessage, bool single)
{
    try
    {
        if (!astGenerated)
        {
            ReadName();
            ReadChildren();
            ReadTop();
            ReadParentNameAndSiblings();
            if (children.empty())
            {
                ReadFilter();
                ReadFilePaths(verbose);
                ReadImports();
                ReadIncludePath();
                SetAstFilePath();
                SetContentXmlFilePath();
                ReadAst(verbose);
                astGenerated = true;
            }
            else
            {
                RunChildren(verbose, rebuild, false, single);
                SetAstFilePath();
                SetContentXmlFilePath();
            }
        }
        if (children.empty())
        {
            ImportAsts(verbose);
            BuildSymbolTable();
            GenerateContentXml(verbose, rebuild);
        }
        MakeDirectories();
        GenerateStyleSheet();
        if (!rebuild)
        {
            upToDate = true;
        }
        else
        {
            upToDate = false;
        }
        GenerateHtmlCodeFiles(verbose, rebuild);
        ReadGrammarXmlFiles(verbose);
        GenerateHtmlContent(verbose, rebuild);
        if (endMessage)
        {
            std::ofstream endFile(GetFullPath(Path::Combine(rootDir, "status.msg")));
            if (upToDate)
            {
                endFile << ToUtf8(name) << ": up-to-date" << std::endl;
            }
            else
            {
                endFile << ToUtf8(name) << ": built" << std::endl;
            }
        }
        else
        {
            if (upToDate)
            {
                if (verbose)
                {
                    std::cout << ToUtf8(name) << "> up-to-date" << std::endl;
                }
            }
            else
            {
                if (verbose)
                {
                    std::cout << ToUtf8(name) << "> built" << std::endl;
                }
            }
        }
    }
    catch (const std::exception& ex)
    {
        if (endMessage)
        {
            std::ofstream endFile(GetFullPath(Path::Combine(rootDir, "status.msg")));
            endFile << ToUtf8(name) << ": " << ex.what() << std::endl;
        }
        throw;
    }
}

void Project::SetAstFilePath()
{
    astFilePath = Path::Combine(rootDir, ToUtf8(name) + ".ast");
}

void Project::SetContentXmlFilePath()
{
    contentXmlFilePath = Path::Combine(rootDir, ToUtf8(name) + ".xml");
}

void Project::SetHtmlFilePath()
{
    htmlFilePath = Path::Combine(rootDir, ToUtf8(name) + ".html");
}

void Project::ReadName()
{
    if (!name.empty()) return;
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/gendoc/project", doc.get());
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
                    if (name.empty())
                    {
                        name = element->GetAttribute(U"name");
                    }
                    else
                    {
                        throw std::runtime_error("project name already set");
                    }
                }
            }
        }
    }
    if (name.empty())
    {
        throw std::runtime_error("project name not set in '" + docFilePath + "'");
    }
}

void Project::ReadTop()
{
    std::u32string top;
    std::string parentXmlFilePath = GetFullPath(Path::Combine(Path::Combine(rootDir, ".."), "gendoc.xml"));
    while (boost::filesystem::exists(parentXmlFilePath))
    {
        top = top + U"../";
        std::string topXmlFilePath = parentXmlFilePath;
        parentXmlFilePath = GetFullPath(Path::Combine(Path::Combine(Path::GetDirectoryName(parentXmlFilePath), ".."), "gendoc.xml"));
        if (!boost::filesystem::exists(parentXmlFilePath))
        {
            std::unique_ptr<sngxml::dom::Document> topDoc = sngxml::dom::ReadDocument(topXmlFilePath);
            std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/gendoc/project", topDoc.get());
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
                            std::u32string topName = element->GetAttribute(U"name");
                            if (!topName.empty())
                            {
                                top.append(topName).append(U".html");
                                topLink = top;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Project::ReadParentNameAndSiblings()
{
    std::string parentXmlFilePath = GetFullPath(Path::Combine(Path::Combine(rootDir, ".."), "gendoc.xml"));
    if (boost::filesystem::exists(parentXmlFilePath))
    {
        std::unique_ptr<sngxml::dom::Document> parentDoc = sngxml::dom::ReadDocument(parentXmlFilePath);
        std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/gendoc/project", parentDoc.get());
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
                        if (parentName.empty())
                        {
                            parentName = element->GetAttribute(U"name");
                            std::unique_ptr<sngxml::xpath::XPathObject> siblingResult = sngxml::xpath::Evaluate(U"/gendoc/child", parentDoc.get());
                            if (siblingResult)
                            {
                                if (siblingResult->Type() == sngxml::xpath::XPathObjectType::nodeSet)
                                {
                                    sngxml::xpath::XPathNodeSet* siblingNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(siblingResult.get());
                                    for (int i = 0; i < siblingNodeSet->Length(); ++i)
                                    {
                                        sngxml::dom::Node* siblingNode = (*siblingNodeSet)[i];
                                        if (siblingNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
                                        {
                                            sngxml::dom::Element* siblingElement = static_cast<sngxml::dom::Element*>(siblingNode);
                                            std::u32string siblingDirName = siblingElement->GetAttribute(U"project");
                                            if (!siblingDirName.empty())
                                            {
                                                std::u32string siblingProject = U"../" + siblingDirName;
                                                std::string siblingXmlFilePath = GetFullPath(Path::Combine(Path::Combine(rootDir, ToUtf8(siblingProject)), "gendoc.xml"));
                                                std::unique_ptr<sngxml::dom::Document> siblingDoc = sngxml::dom::ReadDocument(siblingXmlFilePath);
                                                std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/gendoc/project", siblingDoc.get());
                                                if (result)
                                                {
                                                    if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
                                                    {
                                                        sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
                                                        for (int j = 0; j < nodeSet->Length(); ++j)
                                                        {
                                                            sngxml::dom::Node* node = (*nodeSet)[j];
                                                            if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                                                            {
                                                                sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                                                                std::u32string siblingName = element->GetAttribute(U"name");
                                                                if (!siblingName.empty())
                                                                {
                                                                    if (siblingName == name)
                                                                    {
                                                                        thisProjectIndex = i;
                                                                    }
                                                                    siblingProject.append(1, '/').append(siblingName).append(U".html");
                                                                    siblingProjects.push_back(siblingProject);
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            throw std::runtime_error("project parent name already set");
                        }
                    }
                }
            }
        }
    }
}

void Project::ReadFilter()
{
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/gendoc/filter/file", doc.get());
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
}

void Project::ReadFilePaths(bool verbose)
{
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/gendoc/project/vcxproject", doc.get());
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
                    std::u32string fileAttribute = element->GetAttribute(U"file");
                    if (!fileAttribute.empty())
                    {
                        std::string vcxprojectFilePath = GetFullPath(Path::Combine(rootDir, ToUtf8(fileAttribute)));
                        if (verbose)
                        {
                            std::cout << ToUtf8(name) + "> " << vcxprojectFilePath << std::endl;
                        }
                        projectRoot = Path::GetDirectoryName(vcxprojectFilePath);
                        std::unique_ptr<sngxml::dom::Document> vcxprojectDoc = sngxml::dom::ReadDocument(vcxprojectFilePath);
                        std::unique_ptr<sngxml::xpath::XPathObject> hppFilesResult = sngxml::xpath::Evaluate(U"/Project/ItemGroup/ClInclude", vcxprojectDoc.get());
                        if (hppFilesResult)
                        {
                            if (hppFilesResult->Type() == sngxml::xpath::XPathObjectType::nodeSet)
                            {
                                sngxml::xpath::XPathNodeSet* hppFileNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(hppFilesResult.get());
                                for (int i = 0; i < hppFileNodeSet->Length(); ++i)
                                {
                                    sngxml::dom::Node* hppFileNode = (*hppFileNodeSet)[i];
                                    sngxml::dom::Element* hppFileElement = static_cast<sngxml::dom::Element*>(hppFileNode);
                                    std::u32string hppFileName = hppFileElement->GetAttribute(U"Include");
                                    if (!hppFileName.empty())
                                    {
                                        File hppFile(hppFileName, GetFullPath(Path::Combine(projectRoot, ToUtf8(hppFileName))));
                                        filters.Apply(hppFile);
                                        if (hppFile.Included())
                                        {
                                            filePaths.push_back(hppFile);
                                            headerFiles.AddProjectHeaderFile(hppFile.Path());
                                        }
                                    }
                                }
                            }
                        }
                        std::unique_ptr<sngxml::xpath::XPathObject> cppFilesResult = sngxml::xpath::Evaluate(U"/Project/ItemGroup/ClCompile", vcxprojectDoc.get());
                        if (cppFilesResult)
                        {
                            if (cppFilesResult->Type() == sngxml::xpath::XPathObjectType::nodeSet)
                            {
                                sngxml::xpath::XPathNodeSet* cppFileNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(cppFilesResult.get());
                                for (int i = 0; i < cppFileNodeSet->Length(); ++i)
                                {
                                    sngxml::dom::Node* cppFileNode = (*cppFileNodeSet)[i];
                                    sngxml::dom::Element* cppFileElement = static_cast<sngxml::dom::Element*>(cppFileNode);
                                    std::u32string cppFileName = cppFileElement->GetAttribute(U"Include");
                                    if (!cppFileName.empty())
                                    {
                                        File cppFile(cppFileName, GetFullPath(Path::Combine(projectRoot, ToUtf8(cppFileName))));
                                        filters.Apply(cppFile);
                                        if (cppFile.Included())
                                        {
                                            filePaths.push_back(cppFile);
                                        }
                                    }
                                }
                            }
                        }
                        std::unique_ptr<sngxml::xpath::XPathObject> otherFilesResult = sngxml::xpath::Evaluate(U"/Project/ItemGroup/None", vcxprojectDoc.get());
                        if (otherFilesResult)
                        {
                            if (otherFilesResult->Type() == sngxml::xpath::XPathObjectType::nodeSet)
                            {
                                sngxml::xpath::XPathNodeSet* otherFileNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(otherFilesResult.get());
                                for (int i = 0; i < otherFileNodeSet->Length(); ++i)
                                {
                                    sngxml::dom::Node* otherFileNode = (*otherFileNodeSet)[i];
                                    sngxml::dom::Element* otherFileElement = static_cast<sngxml::dom::Element*>(otherFileNode);
                                    std::u32string otherFileName = otherFileElement->GetAttribute(U"Include");
                                    if (!otherFileName.empty())
                                    {
                                        File otherFile(otherFileName, GetFullPath(Path::Combine(projectRoot, ToUtf8(otherFileName))));
                                        if (Path::GetExtension(otherFile.Path()) == ".parser" || Path::GetExtension(otherFile.Path()) == ".lexer")
                                        {
                                            filters.Apply(otherFile);
                                            if (otherFile.Included())
                                            {
                                                filePaths.push_back(otherFile);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Project::ReadImports()
{
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/gendoc/project/imports/import", doc.get());
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
                    std::string relativeImportDirPath = ToUtf8(element->GetAttribute(U"project"));
                    if (!relativeImportDirPath.empty())
                    {
                        std::string absoluteImportFilePath = GetFullPath(Path::Combine(Path::Combine(rootDir, relativeImportDirPath), "gendoc.xml"));
                        std::unique_ptr<sngxml::dom::Document> importDoc = sngxml::dom::ReadDocument(absoluteImportFilePath);
                        std::unique_ptr<sngxml::xpath::XPathObject> importResult = sngxml::xpath::Evaluate(U"/gendoc/project", importDoc.get());
                        if (importResult)
                        {
                            if (importResult->Type() == sngxml::xpath::XPathObjectType::nodeSet)
                            {
                                sngxml::xpath::XPathNodeSet* importNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(importResult.get());
                                for (int i = 0; i < importNodeSet->Length(); ++i)
                                {
                                    sngxml::dom::Node* importNode = (*importNodeSet)[i];
                                    if (importNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
                                    {
                                        sngxml::dom::Element* importElement = static_cast<sngxml::dom::Element*>(importNode);
                                        std::u32string importProjectName = importElement->GetAttribute(U"name");
                                        Import* importProject = new Import(importProjectName, relativeImportDirPath);
                                        importMap[importProjectName] = importProject;
                                        imports.push_back(std::unique_ptr<Import>(importProject));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Project::ReadIncludePath()
{
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/gendoc/project/include", doc.get());
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
                    std::u32string pathAttribute = element->GetAttribute(U"path");
                    if (!pathAttribute.empty())
                    {
                        if (includePath.empty())
                        {
                            includePath = Path::MakeCanonical(ToUtf8(pathAttribute));
                        }
                        else
                        {
                            throw std::runtime_error("include path already set");
                        }
                    }
                }
            }
        }
    }
}

bool Project::BuildAst(bool verbose, bool rebuild)
{
    if (!rebuild && boost::filesystem::exists(astFilePath))
    {
        bool upToDate = true;
        for (const File& file : filePaths)
        {
            if (boost::filesystem::last_write_time(file.Path()) >= boost::filesystem::last_write_time(astFilePath))
            {
                upToDate = false;
                break;
            }
        }
        if (upToDate)
        {
            return false;
        }
    }
    sngcpp::pp::EvaluationContext evaluationContext;
    int fileIndex = 0;
    for (const File& file : filePaths)
    {
        if (file.Included())
        {
            std::unique_ptr<sngcpp::ast::SourceFileNode> sourceFile;
            std::unique_ptr<CppLexer> lexer;
            if (verbose)
            {
                std::cout << ToUtf8(name) + "> " << file.Path() << std::endl;
            }
            std::string ext = Path::GetExtension(file.Path());
            if (ext == ".parser" || ext == ".lexer")
            {
                std::unique_ptr<std::u32string> content(new std::u32string(ToUtf32(soulng::util::ReadFile(file.Path()))));
                sourceFile.reset(new sngcpp::ast::SourceFileNode(soulng::lexer::Span(), file.Path(), ToUtf8(file.Name()), name));
                sourceFile->SetSourceFileIndex(fileIndex);
                sourceFile->SetText(std::move(*content));
            }
            else
            {
                sngcpp::pp::PP pp(evaluationContext);
                pp.root = projectRoot;
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
            }
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
    return true;
}

void Project::WriteAst(bool verbose)
{
    if (!ast) return;
    BinaryWriter binaryWriter(astFilePath);
    std::vector< soulng::lexer::Lexer*> lexerPtrs;
    for (const auto& lexer : lexers)
    {
        lexerPtrs.push_back(lexer.get());
    }
    sngcpp::ast::Writer writer(lexerPtrs, binaryWriter);
    ast->Write(writer);
    if (verbose)
    {
        std::cout << ToUtf8(name) + "==> " << astFilePath << std::endl;
    }
}

void Project::ReadAst(bool verbose)
{
    if (!boost::filesystem::exists(astFilePath)) return;
    if (verbose)
    {
        std::cout << ToUtf8(name) + "> " << astFilePath << std::endl;
    }
    BinaryReader binaryReader(astFilePath);
    sngcpp::ast::Reader reader(binaryReader);
    ast.reset(reader.ReadNode());
}

void Project::ImportAsts(bool verbose)
{
    for (const auto& importProject : imports)
    {
        std::string importAstFilePath = GetFullPath(Path::Combine(Path::Combine(rootDir, importProject->RelativePath()), ToUtf8(importProject->Name()) + ".ast"));
        importAstFilePaths.push_back(importAstFilePath);
        if (verbose)
        {
            std::cout << ToUtf8(name) + "> " << importAstFilePath << std::endl;
        }
        BinaryReader binaryReader(importAstFilePath);
        sngcpp::ast::Reader reader(binaryReader);
        importAsts.push_back(std::unique_ptr<sngcpp::ast::Node>(reader.ReadNode()));
    }
}

void Project::BuildSymbolTable()
{
    if (!ast) return;
    symbolTable.SetGendocMode();
    sngcpp::ast::ResolveSourceFiles(ast.get(), sourceFiles);
    for (auto& sourceFile : sourceFiles)
    {
        sourceFileMap[sourceFile->SourceFilePath()] = sourceFile;
    }
    int n = imports.size();
    for (int i = 0; i < n; ++i)
    {
        Import* importProject = imports[i].get();
        std::unique_ptr<sngcpp::ast::Node>& importAst = importAsts[i];
        sngcpp::symbols::SymbolCreator symbolCreator(symbolTable, importProject->Name());
        importAst->Accept(symbolCreator);
        importSourceFiles.push_back(std::vector<sngcpp::ast::SourceFileNode*>());
        sngcpp::ast::ResolveSourceFiles(importAst.get(), importSourceFiles.back());
        for (auto& sourceFile : importSourceFiles.back())
        {
            sourceFileMap[sourceFile->SourceFilePath()] = sourceFile;
        }
        sngcpp::binder::TypeBinder typeBinder(symbolTable, this);
        importAst->Accept(typeBinder);
    }
    sngcpp::symbols::SymbolCreator symbolCreator(symbolTable, name);
    ast->Accept(symbolCreator);
    sngcpp::binder::TypeBinder typeBinder(symbolTable, this);
    ast->Accept(typeBinder);
    sngcpp::binder::ResolveOverrideSets(typeBinder.ClassesHavingVirtualFunctions());
    std::vector<std::unique_ptr<sngcpp::binder::BoundSourceFile>> boundSourceFiles = typeBinder.SourceFiles();
    std::unordered_map<sngcpp::ast::SourceFileNode*, sngcpp::binder::BoundSourceFile*> boundSourceFileMap = typeBinder.SourceFileMap();
    sngcpp::binder::StatementBinder statementBinder(symbolTable, boundSourceFileMap);
    ast->Accept(statementBinder);
}

void Project::GenerateContentXml(bool verbose, bool rebuild)
{
    if (!boost::filesystem::exists(astFilePath)) return;
    contentXmlUpToDate = true;
    if (rebuild)
    {
        contentXmlUpToDate = false;
    }
    else
    {
        if (boost::filesystem::exists(contentXmlFilePath))
        {
            if (boost::filesystem::last_write_time(astFilePath) > boost::filesystem::last_write_time(contentXmlFilePath))
            {
                contentXmlUpToDate = false;
            }
            else
            {
                for (const std::string& importAstFilePath : importAstFilePaths)
                {
                    if (boost::filesystem::last_write_time(importAstFilePath) > boost::filesystem::last_write_time(contentXmlFilePath))
                    {
                        contentXmlUpToDate = false;
                        break;
                    }
                }
                if (contentXmlUpToDate)
                {
                    for (const auto& sourceFileVec : importSourceFiles)
                    {
                        for (const auto& sourceFile : sourceFileVec)
                        {
                            if (boost::filesystem::last_write_time(sourceFile->SourceFilePath()) > boost::filesystem::last_write_time(contentXmlFilePath))
                            {
                                contentXmlUpToDate = false;
                                break;
                            }
                        }
                        if (!contentXmlUpToDate)
                        {
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            contentXmlUpToDate = false;
        }
    }
    if (contentXmlUpToDate)
    {
        ReadContentXml(verbose);
    }
    else
    {
        WriteContentXml(verbose);
    }
}

void Project::WriteContentXml(bool verbose)
{
    contentXml = symbolTable.ToDomDocument();
    std::ofstream xmlFile(contentXmlFilePath);
    CodeFormatter formatter(xmlFile);
    formatter.SetIndentSize(1);
    contentXml->Write(formatter);
    if (verbose)
    {
        std::cout << ToUtf8(name) + "==> " << contentXmlFilePath << std::endl;
    }
}

void Project::ReadContentXml(bool verbose)
{
    if (verbose)
    {
        std::cout << ToUtf8(name) + "> " << contentXmlFilePath << std::endl;
    }
    contentXml = sngxml::dom::ReadDocument(contentXmlFilePath);
}

void Project::MakeDirectories()
{
    gendoc::html::MakeDirectories(rootDir, htmlDir, contentDir, fileDir, styleDir);
}

void Project::GenerateStyleSheet()
{
    gendoc::html::GenerateStyleSheet(styleDir, styleDirName, styleFileName);
}

void Project::GenerateHtmlCodeFiles(bool verbose, bool rebuild)
{
    for (auto& sourceFile : sourceFiles)
    {
        sourceFile->SetHtmlSourceFilePath(Path::Combine(contentDir, ToUtf8(sourceFile->Id())));
    }
    bool htmlCodeUpToDate = true;
    gendoc::html::GenerateHtmlCodeFiles(name, sourceFiles, styleDirName, styleFileName, symbolTable, inlineCodeLimit, inlineCodeMap, verbose, rebuild, htmlCodeUpToDate, this);
    if (!htmlCodeUpToDate)
    {
        upToDate = false;
    }
}

void Project::ReadGrammarXmlFiles(bool verbose)
{
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/gendoc/project/grammars", doc.get());
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
                    std::u32string grammarsFileAttribute = element->GetAttribute(U"file");
                    if (!grammarsFileAttribute.empty())
                    {
                        grammarsXmlFilePath = GetFullPath(Path::Combine(rootDir, Path::MakeCanonical(ToUtf8(grammarsFileAttribute))));
                        grammarsXmlDoc = sngxml::dom::ReadDocument(grammarsXmlFilePath);
                        std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/project/grammar", grammarsXmlDoc.get());
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
                                        std::u32string grammarFileAttribute = element->GetAttribute(U"file");
                                        if (!grammarFileAttribute.empty())
                                        {
                                            std::u32string grammarHtmlFileName = ToUtf32(Path::Combine("html/content",
                                                Path::GetFileNameWithoutExtension(Path::MakeCanonical(ToUtf8(grammarFileAttribute))) + ".html"));
                                            std::string grammarXmlFilePath = GetFullPath(Path::Combine(rootDir, Path::MakeCanonical(ToUtf8(grammarFileAttribute))));
                                            std::unique_ptr<sngxml::dom::Document> grammarXmlDoc = sngxml::dom::ReadDocument(grammarXmlFilePath);
                                            std::u32string grammarTitle = grammarXmlDoc->DocumentElement()->GetAttribute(U"title");
                                            gendoc::html::Grammar grammar(grammarHtmlFileName, grammarTitle);
                                            grammars.push_back(std::move(grammar));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Project::ReadDocumentationXml(bool verbose, bool& rebuild)
{
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/gendoc/project/documentation", doc.get());
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
                    std::u32string documentationFileAttribute = element->GetAttribute(U"file");
                    if (!documentationFileAttribute.empty())
                    {
                        documentationXmlFileName = GetFullPath(Path::Combine(rootDir, Path::MakeCanonical(ToUtf8(documentationFileAttribute))));
                        if (boost::filesystem::exists(documentationXmlFileName))
                        {
                            documentationXml = sngxml::dom::ReadDocument(documentationXmlFileName);
                            if (boost::filesystem::exists(contentXmlFilePath))
                            {
                                if (boost::filesystem::last_write_time(documentationXmlFileName) > boost::filesystem::last_write_time(contentXmlFilePath))
                                {
                                    rebuild = true;
                                }
                            }
                        }
                        else
                        {
                            std::cerr << "Documentation XML file '" + documentationXmlFileName + "' does not exist." << std::endl;
                        }
                    }
                }
            }
        }
    }
}

void Project::GenerateHtmlContent(bool verbose, bool rebuild)
{
    ReadDocumentationXml(verbose, rebuild);
    if (contentXml)
    {
        bool htmlContentUpToDate = true;
        std::u32string top;
        if (!topLink.empty())
        {
            top = U"../../";
            top.append(topLink);
        }
        gendoc::html::GenerateContent(name, contentXml.get(), contentDir, styleDirName, styleFileName, inlineCodeMap, contentXmlFilePath, verbose, rebuild, htmlContentUpToDate, this, top,
            documentationXmlFileName, documentationXml.get());
        if (!htmlContentUpToDate)
        {
            upToDate = false;
        }
    }
    bool moduleFileUpToDate = true;
    std::u32string prevProject;
    std::u32string nextProject;
    if (thisProjectIndex != -1)
    {
        if (thisProjectIndex > 0)
        {
            prevProject = siblingProjects[thisProjectIndex - 1];
        }
        if (thisProjectIndex < siblingProjects.size() - 1)
        {
            nextProject = siblingProjects[thisProjectIndex + 1];
        }
    }
    gendoc::html::GenerateModuleHtml(name, parentName, prevProject, nextProject, childProjects, childNames, contentXml.get(), contentDir, styleDirName, styleFileName, sourceFiles,
        contentXmlFilePath, verbose, rebuild, moduleFileUpToDate, this, topLink, documentationXmlFileName, documentationXml.get(), grammars);
    if (!moduleFileUpToDate)
    {
        upToDate = false;
    }
}

std::string Project::ResolveContentFilePath(const std::u32string& currentProjectName, const std::u32string& projectName, const std::string& relativeContentDirPath, const std::u32string& symbolId)
{
    if (projectName.empty())
    {
        std::cerr << "warning: import for project name is empty" << std::endl;
        return Path::Combine(relativeContentDirPath, ToUtf8(symbolId) + ".html");
    }
    else if (currentProjectName == projectName)
    {
        return Path::Combine(relativeContentDirPath, ToUtf8(symbolId) + ".html");
    }
    else
    {
        auto it = importMap.find(projectName);
        if (it != importMap.cend())
        {
            Import* imp = it->second;
            return Path::Combine(Path::Combine(Path::Combine(Path::Combine(relativeContentDirPath, "../.."), imp->RelativePath()), "html/content"), ToUtf8(symbolId) + ".html");
        }
        else
        {
            std::cerr << "warning: import for project name " + ToUtf8(projectName) + " not found" << std::endl;
            return Path::Combine(relativeContentDirPath, ToUtf8(symbolId) + ".html");
        }
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

} // namespace gendoc
