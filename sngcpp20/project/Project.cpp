// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/project/Project.hpp>
#include <sngxml/dom/Element.hpp>
#include <sngxml/dom/Parser.hpp>
#include <sngxml/dom/Document.hpp>
#include <sngxml/xpath/XPathEvaluate.hpp>
#include <boost/filesystem.hpp>
#include <soulng/rex/Context.hpp>
#include <soulng/rex/Match.hpp>
#include <soulng/rex/Nfa.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/util/Unicode.hpp>
#include <algorithm>
#include <iostream>

namespace sngcpp::project {

using namespace soulng::rex;
using namespace soulng::util;
using namespace soulng::unicode;

Project::Project(const std::string& path_, bool verbose) : dirPath(GetFullPath(path_))
{
    if (boost::filesystem::exists(dirPath))
    {
        if (boost::filesystem::is_directory(dirPath))
        {
            filePath = Path::Combine(dirPath, "sngcpp.xml");
        }
        else if (boost::filesystem::is_regular_file(dirPath))
        {
            filePath = dirPath;
            dirPath = Path::GetDirectoryName(filePath);
        }
    }
    rootPath = dirPath;
    if (!boost::filesystem::exists(filePath))
    {
        throw std::runtime_error("project file sngcpp.xml not found from directory '" + dirPath + "'");
    }
    if (verbose)
    {
        std::cout << "> " << filePath << std::endl;
    }
    std::unique_ptr<sngxml::dom::Document> doc = sngxml::dom::ReadDocument(filePath);
    if (doc->DocumentElement()->Name() != U"sngcpp")
    {
        throw std::runtime_error("root element not 'sngcpp' in '" + filePath + "'");
    }
    std::unique_ptr<sngxml::xpath::XPathObject> projectObject = sngxml::xpath::Evaluate(U"/sngcpp/project", doc.get());
    if (projectObject)
    {
        if (projectObject->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(projectObject.get());
            int n = nodeSet->Length();
            if (n == 1)
            {
                sngxml::dom::Node* node = (*nodeSet)[0];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    name = ToUtf8(element->GetAttribute(U"name"));
                    if (name.empty())
                    {
                        throw std::runtime_error("project 'name' attribute not found in '" + filePath + "'");
                    }
                    std::u32string path = element->GetAttribute(U"path");
                    if (!path.empty())
                    {
                        rootPath = GetFullPath(Path::Combine(dirPath, ToUtf8(path)));
                    }
                }
            }
            else
            {
                throw std::runtime_error("single project element under root 'sngcpp' element expected in '" + filePath + "'");
            }
        }
    }
    if (!boost::filesystem::exists(rootPath))
    {
        throw std::runtime_error("source root path '" + rootPath + "' not found");
    }
    std::cout << ">> " << rootPath << std::endl;
    std::unique_ptr<sngxml::xpath::XPathObject> fileObject = sngxml::xpath::Evaluate(U"/sngcpp/project/files/file", doc.get());
    if (fileObject)
    {
        if (fileObject->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(fileObject.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string name = element->GetAttribute(U"name");
                    if (name.empty())
                    {
                        throw std::runtime_error("'file' element has no 'name' attribute in '" + filePath + "'");
                    }
                    File file;
                    file.name = ToUtf8(name);
                    file.path = GetFullPath(Path::Combine(rootPath, file.name));
                    files.push_back(file);
                }
            }
        }
    }
}

void MakeProjectFile(const std::string& path, const std::string& patterns, bool verbose)
{
    std::string currentDir = GetFullPath(".");
    std::string dirPath = GetFullPath(path);
    std::string filePath;
    if (boost::filesystem::exists(dirPath))
    {
        if (boost::filesystem::is_directory(dirPath))
        {
            filePath = Path::Combine(currentDir, "sngcpp.xml");
        }
        else if (boost::filesystem::is_regular_file(dirPath))
        {
            filePath = dirPath;
            dirPath = Path::GetDirectoryName(filePath);
        }
    }
    else
    {
        throw std::runtime_error("path '" + path + "' not found");
    }
    std::string projectName = Path::GetFileNameWithoutExtension(dirPath);
    sngxml::dom::Document doc;
    doc.AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"sngcpp")));
    std::unique_ptr<sngxml::dom::Element> projectElement(new sngxml::dom::Element(U"project"));
    projectElement->SetAttribute(U"name", ToUtf32(projectName));
    if (currentDir != dirPath)
    {
        std::string relativeDirPath = MakeRelativeDirPath(dirPath, currentDir);
        projectElement->SetAttribute(U"path", ToUtf32(relativeDirPath));
    }
    if (verbose)
    {
        std::cout << "> " << dirPath << std::endl;
    }
    std::vector<std::string> patternVec = Split(patterns, ';');
    Context context;
    std::vector<Nfa> nfas;
    for (const std::string& pattern : patternVec)
    {
        nfas.push_back(CompileFilePattern(context, ToUtf32(pattern)));
    }
    std::vector<std::string> fileNames;
    boost::filesystem::directory_iterator it(dirPath);
    while (it != boost::filesystem::directory_iterator())
    {
        boost::filesystem::directory_entry entry(*it);
        std::string filePath = GetFullPath(entry.path().generic_string());
        std::string fileName = Path::GetFileName(filePath);
        for (Nfa& nfa : nfas)
        {
            if (PatternMatch(ToUtf32(fileName), nfa))
            {
                fileNames.push_back(fileName);
            }
        }
        ++it;
    }
    std::sort(fileNames.begin(), fileNames.end());
    std::unique_ptr<sngxml::dom::Element> filesElement(new sngxml::dom::Element(U"files"));
    for (const std::string& fileName : fileNames)
    {
        std::unique_ptr<sngxml::dom::Element> fileElement(new sngxml::dom::Element(U"file"));
        fileElement->SetAttribute(U"name", ToUtf32(fileName));
        filesElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(fileElement.release()));
    }
    projectElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(filesElement.release()));
    doc.DocumentElement()->AppendChild(std::unique_ptr<sngxml::dom::Node>(projectElement.release()));
    std::ofstream file(filePath);
    CodeFormatter formatter(file);
    doc.Write(formatter);
    if (verbose)
    {
        std::cout << "==> " << filePath << std::endl;
    }
}

} // namespace sngcpp::project
