// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <gendoc/html/Html.hpp>
#include <gendoc/html/HtmlSourceCodeGenerator.hpp>
#include <gendoc/html/HtmlSourceCodeWriter.hpp>
#include <gendoc/html/HtmlLexerFileSourceGenerator.hpp>
#include <gendoc/html/HtmlParserFileSourceGenerator.hpp>
#include <gendoc/html/ClassInheritanceDiagramCode.hpp>
#include <sngxml/dom/Document.hpp>
#include <sngxml/dom/Element.hpp>
#include <sngxml/dom/CharacterData.hpp>
#include <sngxml/xpath/XPathEvaluate.hpp>
#include <sngcpp/symbols/Symbol.hpp>
#include <soulng/lexer/XmlParsingLog.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/Util.hpp>
#include <boost/filesystem.hpp>
#include <algorithm>
#include <stdexcept>
#include <unordered_set>
#include <fstream>
#include <iostream>

namespace gendoc { namespace html {

using namespace soulng::util;
using namespace soulng::unicode;
using namespace sngcpp::symbols;

void MakeDirectories(const std::string& targetDir, std::string& htmlDir, std::string& contentDir, std::string& fileDir, std::string& styleDir)
{
    htmlDir = GetFullPath(Path::Combine(targetDir, "html"));
    boost::filesystem::create_directories(htmlDir);
    contentDir = GetFullPath(Path::Combine(htmlDir, "content"));
    boost::filesystem::create_directories(contentDir);
    fileDir = GetFullPath(Path::Combine(contentDir, "file"));
    boost::filesystem::create_directories(fileDir);
    styleDir = GetFullPath(Path::Combine(htmlDir, "style"));
    boost::filesystem::create_directories(styleDir);
}

void GenerateStyleSheet(const std::string& styleDir, std::string& styleDirName, std::string& styleFileName)
{
    styleDirName = "style";
    styleFileName = "style.css";
    std::string styleFilePath = GetFullPath(Path::Combine(styleDir, styleFileName));
    std::ofstream styleSheetFile(styleFilePath);
    CodeFormatter formatter(styleSheetFile);
    formatter.WriteLine(".diagram");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("text-align: center;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine(".tree");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("margin: 20px;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine("h1, h2, h3, h4, h5, h6");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("color: #005ab4;");
    formatter.WriteLine("font-family: sans-serif;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine("table");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("font-family: sans-serif;");
    formatter.WriteLine("border-collapse: collapse;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine("table, th, td");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("text-align: left;");
    formatter.WriteLine("border: 1px solid #dddddd;");
    formatter.WriteLine("margin: 20px;");
    formatter.WriteLine("padding: 8px;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine("table.functionTable");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("font-family: sans-serif;");
    formatter.WriteLine("border-collapse: collapse;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine("table.functionTable, td.functionTableSecondCol");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("text-align: left;");
    formatter.WriteLine("border: 1px solid #dddddd;");
    formatter.WriteLine("margin: 20px;");
    formatter.WriteLine("padding: 8px;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine("td.functionTableFirstCol");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("text-align: right;");
    formatter.WriteLine("border: 1px solid #dddddd;");
    formatter.WriteLine("padding: 8px;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    //  grammars:
    formatter.WriteLine("table.grammar");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("background-color: FloralWhite;");
    formatter.WriteLine("margin: 20px;");
    formatter.WriteLine("padding: 20px;");
    formatter.WriteLine("max-width: 800px;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine("table.grammar, td.grammarThirdCol");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("vertical-align: top;");
    formatter.WriteLine("text-align: left;");
    formatter.WriteLine("padding: 8px;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine("td.grammarFirstCol");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("vertical-align: top;");
    formatter.WriteLine("text-align: right;");
    formatter.WriteLine("padding: 8px;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine("td.grammarSecondCol");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("vertical-align: top;");
    formatter.WriteLine("text-align: left;");
    formatter.WriteLine("font-family: serif;");
    formatter.WriteLine("padding: 8px;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine(".rule");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("font-family: serif;");
    formatter.WriteLine("font-style: italic;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine(".ruleChar");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("font-family: Consolas;");
    formatter.WriteLine("color: #a31515;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine(".ruleString");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("font-family: Consolas;");
    formatter.WriteLine("color: #a31515;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine(".ruleCharSet");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("font-family: Consolas;");
    formatter.WriteLine("color: #a31515;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine(".ruleKeyword");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("color: #0000cc;");
    formatter.WriteLine("font-weight: bold;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine(".ruleParams");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("color: black;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine(".ruleOp");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("padding-left: 2pt;");
    formatter.WriteLine("padding-right: 2pt;");
    formatter.WriteLine("font-family: serif;");
    formatter.WriteLine("color: black;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine(".ruleLink");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("font-family: serif;");
    formatter.WriteLine("font-style: italic;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    //  code:
    formatter.WriteLine(".code");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("font-family: Consolas;");
    formatter.WriteLine("font-size: small;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine(".lineNumber");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("color: #2b91af;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine(".type");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("color: #2b91af;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine(".pp");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("color: #808080;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine(".kw");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("color: #0000cc;");
    formatter.WriteLine("font-weight: bold;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine(".string");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("color: #a31515;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine(".comment");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("color: green;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine(".identifier");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("color: black;");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine(".other");
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("color: black;");
    formatter.DecIndent();
    formatter.WriteLine("}");
}

std::u32string GetPrefix(sngxml::dom::Element* element)
{
    std::u32string prefix;
    sngxml::dom::ParentNode* parent = element->Parent();
    while (parent && parent->GetNodeType() == sngxml::dom::NodeType::elementNode)
    {
        sngxml::dom::Element* parentElement = static_cast<sngxml::dom::Element*>(parent);
        if (parentElement->Name() == U"namespace" || parentElement->Name() == U"class")
        {
            std::u32string nsOrClassName = parentElement->GetAttribute(U"name");
            if (!nsOrClassName.empty())
            {
                if (!prefix.empty())
                {
                    prefix = nsOrClassName + U"::" + prefix;
                }
                else
                {
                    prefix = nsOrClassName;
                }
            }
        }
        parent = parent->Parent();
    }
    return prefix;
}

std::u32string MakeTitle(const std::u32string& name)
{
    if (!name.empty())
    {
        return std::u32string(1, ToUpper(name[0])) + name.substr(1);
    }
    else
    {
        return name;
    }
}

enum class Navigation
{
    header, footer
};

void GenerateNavigation(sngxml::dom::Element* pageElement, Navigation navigation,
    const std::u32string& topLink, const std::u32string& parentLink, const std::u32string& prevLink, const std::u32string& nextLink)
{
    if (!topLink.empty())
    {
        std::unique_ptr<sngxml::dom::Element> top(new sngxml::dom::Element(U"a"));
        top->SetAttribute(U"href", topLink);
        top->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"top")));
        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(top.release()));
    }
    else
    {
        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"top")));
    }
    pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" | ")));
    if (!parentLink.empty())
    {
        std::unique_ptr<sngxml::dom::Element> parent(new sngxml::dom::Element(U"a"));
        parent->SetAttribute(U"href", parentLink);
        parent->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"up")));
        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(parent.release()));
    }
    else
    {
        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"up")));
    }
    pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" | ")));
    if (!prevLink.empty())
    {
        std::unique_ptr<sngxml::dom::Element> prev(new sngxml::dom::Element(U"a"));
        prev->SetAttribute(U"href", prevLink);
        prev->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"prev")));
        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(prev.release()));
    }
    else
    {
        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"prev")));
    }
    pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" | ")));
    if (!nextLink.empty())
    {
        std::unique_ptr<sngxml::dom::Element> next(new sngxml::dom::Element(U"a"));
        next->SetAttribute(U"href", nextLink);
        next->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"next")));
        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(next.release()));
    }
    else
    {
        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"next")));
    }
    if (navigation == Navigation::header)
    {
        std::unique_ptr<sngxml::dom::Element> hr(new sngxml::dom::Element(U"hr"));
        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(hr.release()));
    }
}

std::u32string GetProject(sngxml::dom::Element* element);

enum class DocFlags : uint8_t
{
    none = 0,
    full = 1 << 0,
    paragraph = 1 << 1,
    moduleDoc = 1 << 2
};

inline DocFlags operator&(DocFlags left, DocFlags right)
{
    return DocFlags(uint8_t(left) & uint8_t(right));
}

inline DocFlags operator|(DocFlags left, DocFlags right)
{
    return DocFlags(uint8_t(left) | uint8_t(right));
}

inline DocFlags operator~(DocFlags flags)
{
    return DocFlags(~uint8_t(flags));
}

std::set<std::u32string> headerElementNames;

void InitHeaderElementNames()
{
    headerElementNames.insert(U"h1");
    headerElementNames.insert(U"h2");
    headerElementNames.insert(U"h3");
    headerElementNames.insert(U"h4");
    headerElementNames.insert(U"h5");
}

bool IsHeaderElement(sngxml::dom::Node* node)
{
    if (!node) return false;
    if (node->GetNodeType() != sngxml::dom::NodeType::elementNode) return false;
    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
    if (headerElementNames.find(element->Name()) != headerElementNames.cend())
    {
        return true;
    }
    return false;
}

sngxml::dom::Element* GetContainerElement(sngxml::dom::Element* element)
{
    if (element->Name() == U"class" || element->Name() == U"namespace" || element->Name() == U"enumType")
    {
        return element;
    }
    else if (element->Parent())
    {
        if (element->Parent()->GetNodeType() == sngxml::dom::NodeType::elementNode)
        {
            sngxml::dom::Element* parentElement = static_cast<sngxml::dom::Element*>(element->Parent());
            return GetContainerElement(parentElement);
        }
    }
    return element;
}

void GenerateDocContent(const std::u32string& projectName, sngxml::dom::Element* element, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml,
    sngxml::dom::Element* parentElement, const std::u32string& id, sngxml::dom::Document* contentXml, HtmlContentFilePathResolver* contentFilePathResolver, DocFlags flags)
{
    sngxml::dom::Element* paragraphElement;
    if ((flags & DocFlags::paragraph) != DocFlags::none)
    {
        if (!IsHeaderElement(element->FirstChild()))
        {
            paragraphElement = new sngxml::dom::Element(U"p");
            parentElement->AppendChild(std::unique_ptr<sngxml::dom::Element>(paragraphElement));
            parentElement = paragraphElement;
        }
    }
    sngxml::dom::Node* child = element->FirstChild();
    while (child != nullptr)
    {
        switch (child->GetNodeType())
        {
            case sngxml::dom::NodeType::elementNode:
            {
                sngxml::dom::Element* childElement = static_cast<sngxml::dom::Element*>(child);
                if (childElement->Name() == U"link")
                {
                    std::u32string refId = childElement->GetAttribute(U"ref");
                    sngxml::dom::Element* refElement = contentXml->GetElementById(refId);
                    if (refElement)
                    {
                        std::u32string project = GetProject(refElement);
                        if (!project.empty())
                        {
                            std::string dirPath = ".";
                            if ((flags & DocFlags::moduleDoc) != DocFlags::none)
                            {
                                dirPath = "html/content";
                            }
                            sngxml::dom::Element* containerElement = GetContainerElement(refElement);
                            std::u32string link = ToUtf32(contentFilePathResolver->ResolveContentFilePath(projectName, project, dirPath, containerElement->GetAttribute(U"id")));
                            if (!link.empty())
                            {
                                if (refElement != containerElement)
                                {
                                    link.append(1, '#').append(refId);
                                }
                                std::unique_ptr<sngxml::dom::Element> a(new sngxml::dom::Element(U"a"));
                                a->SetAttribute(U"href", link);
                                a->AppendChild(childElement->FirstChild()->CloneNode(true));
                                parentElement->AppendChild(std::move(a));
                            }
                            else
                            {
                                std::cerr << "warning: " << documentationXmlFileName << ":" << ToUtf8(id) + ": content file path for link element '" + ToUtf8(refId) + "' not found" << std::endl;
                            }
                        }
                        else
                        {
                            std::cerr << "warning: " << documentationXmlFileName << ":" << ToUtf8(id) + ": project for link element '" + ToUtf8(refId) + "' not found" << std::endl;
                        }
                    }
                    else
                    {
                        std::cerr << "warning: " << documentationXmlFileName << ":" << ToUtf8(id) + ": referenced element '" + ToUtf8(refId) + "' not found" << std::endl;
                    }
                }
                else
                {
                    std::unique_ptr<sngxml::dom::Node> c(childElement->CloneNode(false));
                    GenerateDocContent(projectName, childElement, documentationXmlFileName, documentationXml, static_cast<sngxml::dom::Element*>(c.get()), id, contentXml, contentFilePathResolver,
                        flags & ~DocFlags::paragraph);
                    parentElement->AppendChild(std::move(c));
                }
                break;
            }
            default:
            {
                parentElement->AppendChild(child->CloneNode(true));
                break;
            }
        }
        child = child->NextSibling();
    }
}

void GenerateDocumentation(const std::u32string& projectName, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml, sngxml::dom::Element* parentElement,
    const std::u32string& id, sngxml::dom::Document* contentXml, HtmlContentFilePathResolver* contentFilePathResolver, DocFlags flags)
{
    if (!documentationXml) return;
    sngxml::dom::Element* documentationElement = documentationXml->GetElementById(id);
    if (!documentationElement) return;
    std::unique_ptr<sngxml::xpath::XPathObject> description = sngxml::xpath::Evaluate(U"description", documentationElement);
    if (description)
    {
        if (description->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(description.get());
            int n = nodeSet->Length();
            if (n > 0)
            {
                for (int i = 0; i < n; ++i)
                {
                    sngxml::dom::Node* node = (*nodeSet)[i];
                    if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                    {
                        sngxml::dom::Element* descriptionElement = static_cast<sngxml::dom::Element*>(node);
                        GenerateDocContent(projectName, descriptionElement, documentationXmlFileName, documentationXml, parentElement, id, contentXml, contentFilePathResolver, flags);
                    }
                    else
                    {
                        std::cerr << "warning: " << documentationXmlFileName << ":" << ToUtf8(id) + ": description not an element node" << std::endl;
                    }
                }
            }
            else
            {
                std::cerr << "warning: " << documentationXmlFileName << ":" << ToUtf8(id) + ": no description element" << std::endl;
            }
        }
        else
        {
            std::cerr << "warning: " << documentationXmlFileName << ":" << ToUtf8(id) + ": no description element" << std::endl;
        }
    }
    else
    {
        std::cerr << "warning: " << documentationXmlFileName << ":" << ToUtf8(id) + ": no description element" << std::endl;
    }
    if ((flags & DocFlags::full) == DocFlags::none) return;
    std::unique_ptr<sngxml::xpath::XPathObject> body = sngxml::xpath::Evaluate(U"body", documentationElement);
    if (body)
    {
        if (body->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(body.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* bodyElement = static_cast<sngxml::dom::Element*>(node);
                    GenerateDocContent(projectName, bodyElement, documentationXmlFileName, documentationXml, parentElement, id, contentXml, contentFilePathResolver,
                        flags | DocFlags::paragraph);
                }
            }
        }
    }
}

bool GenerateNamespaceNames(const std::u32string& mainProjectName, int level, sngxml::dom::Element* namespaceTableElement, sngxml::dom::Element* namespaceParentElement,
    const std::u32string& moduleName, bool global, HtmlContentFilePathResolver* contentFilePathResolver);

bool GenerateNamespaceNames(const std::u32string& mainProjectName, int level, sngxml::dom::Element* namespaceTableElement, sngxml::dom::Element* namespaceParentElement,
    const std::u32string& moduleName, HtmlContentFilePathResolver* contentFilePathResolver)
{
    return GenerateNamespaceNames(mainProjectName, level, namespaceTableElement, namespaceParentElement, moduleName, false, contentFilePathResolver);
}

bool GenerateNamespaceNames(const std::u32string& mainProjectName, int level, sngxml::dom::Element* namespaceTableElement, sngxml::dom::Element* namespaceParentElement,
    const std::u32string& moduleName, bool global, HtmlContentFilePathResolver* contentFilePathResolver)
{
    bool rowAdded = false;
    std::unique_ptr<sngxml::xpath::XPathObject> namespaces = sngxml::xpath::Evaluate(U"namespaces/namespace", namespaceParentElement);
    if (namespaces->Type() == sngxml::xpath::XPathObjectType::nodeSet || global)
    {
        sngxml::xpath::XPathNodeSet* namespacesNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(namespaces.get());
        int n = namespacesNodeSet->Length();
        if (global)
        {
            n = 1;
        }
        for (int i = 0; i < n; ++i)
        {
            std::u32string projectName;
            sngxml::dom::Node* nsNode = nullptr;
            if (global)
            {
                nsNode = namespaceParentElement;
            }
            else
            {
                nsNode = (*namespacesNodeSet)[i];
            }
            if (nsNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
            {
                sngxml::dom::Element* nsElement = static_cast<sngxml::dom::Element*>(nsNode);
                bool addRow = false;
                std::unique_ptr<sngxml::xpath::XPathObject> project = sngxml::xpath::Evaluate(U"projects/project", nsElement);
                if (project->Type() == sngxml::xpath::XPathObjectType::nodeSet)
                {
                    sngxml::xpath::XPathNodeSet* projectNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(project.get());
                    int m = projectNodeSet->Length();
                    for (int k = 0; k < m; ++k)
                    {
                        sngxml::dom::Node* projectNode = (*projectNodeSet)[k];
                        if (projectNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
                        {
                            sngxml::dom::Element* projectElement = static_cast<sngxml::dom::Element*>(projectNode);
                            std::u32string projName = projectElement->GetAttribute(U"name");
                            if (projName == mainProjectName)
                            {
                                projectName = projName;
                                addRow = true;
                                break;
                            }
                        }
                    }
                }
                if (addRow)
                {
                    rowAdded = true;
                    std::unique_ptr<sngxml::dom::Element> trElement(new sngxml::dom::Element(U"tr"));
                    for (int l = 0; l < level; ++l)
                    {
                        std::unique_ptr<sngxml::dom::Element> tdElement(new sngxml::dom::Element(U"td"));
                        trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(tdElement.release()));
                    }
                    std::unique_ptr<sngxml::dom::Element> tdElement(new sngxml::dom::Element(U"td"));
                    std::u32string nsName = nsElement->GetAttribute(U"name");
                    if (nsName.empty())
                    {
                        nsName = U"Global Namespace";
                    }
                    std::u32string nsId = nsElement->GetAttribute(U"id");
                    std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"a"));
                    std::u32string link;
                    if (!moduleName.empty())
                    {
                        link.append(U"html/content/");
                    }
                    link.append(ToUtf32(contentFilePathResolver->ResolveContentFilePath(mainProjectName, projectName, ".", nsId)));
                    linkElement->SetAttribute(U"href", link);
                    linkElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(nsName)));
                    tdElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(linkElement.release()));
                    trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(tdElement.release()));
                    namespaceTableElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(trElement.release()));
                    bool subRowAdded = GenerateNamespaceNames(mainProjectName, level + 1, namespaceTableElement, nsElement, moduleName, contentFilePathResolver);
                    if (subRowAdded)
                    {
                        rowAdded = true;
                    }
                }
            }
        }
    }
    return rowAdded;
}

std::u32string GetProject(sngxml::dom::Element* element)
{
    if (!element) return std::u32string();
    std::u32string elementProjectName = element->GetAttribute(U"project");
    if (!elementProjectName.empty())
    {
        return elementProjectName;
    }
    else
    {
        sngxml::dom::ParentNode* parent = element->Parent();
        if (parent->GetNodeType() == sngxml::dom::NodeType::elementNode)
        {
            return GetProject(static_cast<sngxml::dom::Element*>(parent));
        }
        else
        {
            return std::u32string();
        }
    }
}

bool ProjectNameMatches(sngxml::dom::Element* element, const std::u32string& projectName)
{
    if (!element) return false;
    std::u32string elementProjectName = element->GetAttribute(U"project");
    if (!elementProjectName.empty())
    {
        return elementProjectName == projectName;
    }
    else
    {
        sngxml::dom::ParentNode* parent = element->Parent();
        if (parent->GetNodeType() == sngxml::dom::NodeType::elementNode)
        {
            return ProjectNameMatches(static_cast<sngxml::dom::Element*>(parent), projectName);
        }
        else
        {
            return false;
        }
    }
}

bool GenerateNamespaceSection(const std::u32string& mainProjectName, sngxml::dom::Element* parentNsElement, sngxml::dom::Element* pageElement, sngxml::dom::Document* contentXml,
    const std::u32string& moduleName, bool global, HtmlContentFilePathResolver* contentFilePathResolver, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml);

void GenerateNamespaceSection(const std::u32string& mainProjectName, sngxml::dom::Element* parentNsElement, sngxml::dom::Element* pageElement, sngxml::dom::Document* contentXml,
    const std::u32string& moduleName, HtmlContentFilePathResolver* contentFilePathResolver, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml)
{
    GenerateNamespaceSection(mainProjectName, parentNsElement, pageElement, contentXml, moduleName, false, contentFilePathResolver, documentationXmlFileName, documentationXml);
}

bool GenerateNamespaceSection(const std::u32string& mainProjectName, sngxml::dom::Element* parentNsElement, sngxml::dom::Element* pageElement, sngxml::dom::Document* contentXml,
    const std::u32string& moduleName, bool global, HtmlContentFilePathResolver* contentFilePathResolver, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml)
{
    std::unique_ptr<sngxml::dom::Element> namespaceTableElement(new sngxml::dom::Element(U"table"));
    if (GenerateNamespaceNames(mainProjectName, 0, namespaceTableElement.get(), parentNsElement, moduleName, global, contentFilePathResolver))
    {
        std::unique_ptr<sngxml::dom::Element> h2Element(new sngxml::dom::Element(U"h2"));
        h2Element->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"Namespaces")));
        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(h2Element.release()));
        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(namespaceTableElement.release()));
        return true;
    }
    else
    {
        return false;
    }
}

sngxml::dom::Element* GetGlobalNsElement(sngxml::dom::Document* contentXml)
{
    std::unique_ptr<sngxml::xpath::XPathObject> globalNs = sngxml::xpath::Evaluate(U"/symbolTable/namespace", contentXml);
    if (globalNs->Type() == sngxml::xpath::XPathObjectType::nodeSet)
    {
        sngxml::xpath::XPathNodeSet* globalNsNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(globalNs.get());
        if (globalNsNodeSet->Length() == 1)
        {
            sngxml::dom::Node* globalNsNode = (*globalNsNodeSet)[0];
            if (globalNsNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
            {
                sngxml::dom::Element* globalNsElement = static_cast<sngxml::dom::Element*>(globalNsNode);
                return globalNsElement;
            }
        }
    }
    return nullptr;
}

void GenerateModuleNamespaceSection(const std::u32string& mainProjectName, sngxml::dom::Element* pageElement, sngxml::dom::Document* contentXml, const std::u32string& moduleName,
    HtmlContentFilePathResolver* contentFilePathResolver, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml)
{
    sngxml::dom::Element* globalNsElement = GetGlobalNsElement(contentXml);
    if (globalNsElement)
    {
        if (!GenerateNamespaceSection(mainProjectName, globalNsElement, pageElement, contentXml, moduleName, true, contentFilePathResolver, documentationXmlFileName, documentationXml))
        {
            GenerateNamespaceSection(mainProjectName, globalNsElement, pageElement, contentXml, moduleName, false, contentFilePathResolver, documentationXmlFileName, documentationXml);
        }
    }
}

struct ByRelativeFilePath
{
    bool operator()(SourceFileNode* left, SourceFileNode* right) const
    {
        return left->RelativeSourceFilePath() < right->RelativeSourceFilePath();
    }
};

void GenerateModuleFileSection(const std::vector<sngcpp::ast::SourceFileNode*>& sourceFiles, sngxml::dom::Element* pageElement, const std::u32string& moduleName)
{
    std::vector<SourceFileNode*> moduleSourceFiles;
    int n = sourceFiles.size();
    for (int i = 0; i < n; ++i)
    {
        SourceFileNode* sourceFileNode = sourceFiles[i];
        if (sourceFileNode->ProjectName() == moduleName)
        {
            moduleSourceFiles.push_back(sourceFileNode);
        }
    }
    int m = moduleSourceFiles.size();
    if (m > 0)
    {
        std::unique_ptr<sngxml::dom::Element> fileTableElement(new sngxml::dom::Element(U"table"));
        std::unique_ptr<sngxml::dom::Element> h2Element(new sngxml::dom::Element(U"h2"));
        h2Element->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"Files")));
        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(h2Element.release()));
        std::sort(moduleSourceFiles.begin(), moduleSourceFiles.end(), ByRelativeFilePath());
        for (int i = 0; i < m; ++i)
        {
            SourceFileNode* sourceFile = moduleSourceFiles[i];
            std::u32string sourceFileName = ToUtf32(sourceFile->RelativeSourceFilePath());
            std::u32string sourceFileId = U"html/content/" + sourceFile->Id();
            std::unique_ptr<sngxml::dom::Element> trElement(new sngxml::dom::Element(U"tr"));
            std::unique_ptr<sngxml::dom::Element> tdElement(new sngxml::dom::Element(U"td"));
            std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"a"));
            linkElement->SetAttribute(U"href", sourceFileId);
            linkElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(sourceFileName)));
            tdElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(linkElement.release()));
            trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(tdElement.release()));
            fileTableElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(trElement.release()));
        }
        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(fileTableElement.release()));
    }
}

void GenerateConstructorSection(const std::u32string& projectName, sngxml::dom::Element* pageElement, sngxml::dom::Element* parentElement, const std::string& contentDir,
    const std::string& styleDirName, const std::string& styleFileName, sngxml::dom::Document* contentXml, std::vector<sngxml::dom::Element*>& constructorElements,
    HtmlContentFilePathResolver* contentFilePathResolver, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml);

void GenerateFunctionSection(const std::u32string& projectName, const std::u32string& title, sngxml::dom::Element* pageElement, sngxml::dom::Element* parentElement, const std::string& contentDir,
    const std::string& styleDirName, const std::string& styleFileName, sngxml::dom::Document* contentXml, std::vector<sngxml::dom::Element*>& functionElements,
    HtmlContentFilePathResolver* contentFilePathResolver, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml);

void GenerateClassSection(const std::u32string& projectName, sngxml::dom::Element* pageElement, sngxml::dom::Element* parentElement, sngxml::dom::Document* contentXml,
    const std::string& contentDir, const std::string& styleDirName, const std::string& styleFileName,
    std::unordered_map<std::u32string, std::unique_ptr<sngxml::dom::Element>>& inlineCodeMap, const std::string& contentXmlFilePath, bool verbose, bool rebuild,
    HtmlContentFilePathResolver* contentFilePathResolver, const std::u32string& topLink, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml);

void GenerateEnumSection(const std::u32string& projectName, sngxml::dom::Element* pageElement, sngxml::dom::Element* parentElement, sngxml::dom::Document* contentXml,
    const std::string& contentDir, const std::string& styleDirName, const std::string& styleFileName, const std::string& contentXmlFilePath, bool verbose, bool rebuild,
    const std::u32string& topLink, HtmlContentFilePathResolver* contentFilePathResolver, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml);

void GenerateVariableSection(const std::u32string& projectName, const std::u32string& title, sngxml::dom::Element* pageElement, sngxml::dom::Element* parentElement, sngxml::dom::Document* contentXml,
    const std::string& contentDir, const std::string& styleDirName, const std::string& styleFileName,
    HtmlContentFilePathResolver* contentFilePathResolver, const std::u32string& topLink, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml);

void GenerateTypedefSection(const std::u32string& projectName, sngxml::dom::Element* pageElement, sngxml::dom::Element* parentElement, sngxml::dom::Document* contentXml,
    const std::string& contentDir, const std::string& styleDirName, const std::string& styleFileName,
    HtmlContentFilePathResolver* contentFilePathResolver, const std::u32string& topLink, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml);

void GenerateFunctionDetailSection(const std::u32string& projectName, const std::u32string& title, const std::u32string& functionTitle, sngxml::dom::Element* pageElement, sngxml::dom::Element* parentElement,
    std::vector<sngxml::dom::Element*>& functionElements, sngxml::dom::Document* contentXml, std::unordered_map<std::u32string, std::unique_ptr<sngxml::dom::Element>>& inlineCodeMap,
    HtmlContentFilePathResolver* contentFilePathResolver, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml);

std::u32string MakeClassName(sngxml::dom::Element* classElement)
{
    std::u32string className = classElement->GetAttribute(U"name");
    std::unique_ptr<sngxml::xpath::XPathObject> templateParameters = sngxml::xpath::Evaluate(U"templateParameters/templateParameter", classElement);
    if (templateParameters->Type() == sngxml::xpath::XPathObjectType::nodeSet)
    {
        sngxml::xpath::XPathNodeSet* templateParameterNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(templateParameters.get());
        int n = templateParameterNodeSet->Length();
        if (n > 0)
        {
            className.append(1, '<');
            for (int i = 0; i < n; ++i)
            {
                if (i > 0)
                {
                    className.append(U", ");
                }
                sngxml::dom::Node* templateParameterNode = (*templateParameterNodeSet)[i];
                if (templateParameterNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* templateParameterElement = static_cast<sngxml::dom::Element*>(templateParameterNode);
                    className.append(templateParameterElement->GetAttribute(U"name"));
                }
            }
            className.append(1, '>');
        }
    }
    return className;
}

std::u32string MakeFullClassName(sngxml::dom::Element* classElement)
{
    std::u32string className = MakeClassName(classElement);
    std::u32string prefix = GetPrefix(classElement);
    if (!prefix.empty())
    {
        return prefix + U"::" + className;
    }
    else
    {
        return className;
    }
}

struct Class
{
    Class(const std::u32string& name_, int index_, int level_, bool subject_, bool hasDerivedClasses_, const std::u32string& link_);
    void Write(CodeFormatter& formatter);
    std::u32string name;
    int index;
    int level;
    bool subject;
    bool hasDerivedClasses;
    std::u32string link;
};

Class::Class(const std::u32string& name_, int index_, int level_, bool subject_, bool hasDerivedClasses_, const std::u32string& link_) :
    name(name_), index(index_), level(level_), subject(subject_), hasDerivedClasses(hasDerivedClasses_), link(link_)
{
}

void Class::Write(CodeFormatter& formatter)
{
    formatter.Write("{ ");
    formatter.Write("name: \"");
    formatter.Write(ToUtf8(soulng::lexer::XmlEscape(name)));
    formatter.Write("\", ");
    formatter.Write("id: \"");
    formatter.Write("class_" + std::to_string(index));
    formatter.Write("\", ");
    formatter.Write("level: ");
    formatter.Write(std::to_string(level));
    formatter.Write(", ");
    formatter.Write("subject: ");
    formatter.Write(subject ? "true" : "false");
    formatter.Write(", ");
    formatter.Write("hasDerivedClasses: ");
    formatter.Write(hasDerivedClasses ? "true" : "false");
    formatter.Write(", ");
    formatter.Write("link: \"");
    formatter.Write(ToUtf8(link));
    formatter.Write("\"");
    formatter.Write(" }");
}

void GenerateClassData(const std::u32string& projectName, std::vector<Class>& classes, sngxml::dom::Element* classElement, sngxml::dom::Document* contentXml, int& depth, int& level,
    HtmlContentFilePathResolver* contentFilePathResolver)
{
    int numBaseClasses = 0;
    std::unique_ptr<sngxml::xpath::XPathObject> baseClasses = sngxml::xpath::Evaluate(U"baseClasses/baseClass", classElement);
    if (baseClasses->Type() == sngxml::xpath::XPathObjectType::nodeSet)
    {
        sngxml::xpath::XPathNodeSet* baseClassNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(baseClasses.get());
        int n = baseClassNodeSet->Length();
        if (n > 0)
        {
            ++depth;
            --level;
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* baseClassNode = (*baseClassNodeSet)[i];
                if (baseClassNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* baseClassIdElement = static_cast<sngxml::dom::Element*>(baseClassNode);
                    std::u32string baseClassId = baseClassIdElement->GetAttribute(U"baseClassId");
                    sngxml::dom::Element* baseClassElement = contentXml->GetElementById(baseClassId);
                    if (baseClassElement)
                    {
                        if (baseClassElement->Name() == U"specialization")
                        {
                            std::u32string primaryTypeId = baseClassElement->GetAttribute(U"primaryTypeId");
                            baseClassElement = contentXml->GetElementById(primaryTypeId);
                        }
                        if (baseClassElement)
                        {
                            if (baseClassElement->Name() == U"class")
                            {
                                GenerateClassData(projectName, classes, baseClassElement, contentXml, depth, level, contentFilePathResolver);
                                ++numBaseClasses;
                            }
                        }
                    }
                }
            }
            ++level;
        }
    }
    std::unique_ptr<sngxml::xpath::XPathObject> derivedClasses = sngxml::xpath::Evaluate(U"derivedClasses/derivedClass", classElement);
    if (derivedClasses->Type() == sngxml::xpath::XPathObjectType::nodeSet)
    {
        sngxml::xpath::XPathNodeSet* derivedClassNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(derivedClasses.get());
        int numDerivedClasses = derivedClassNodeSet->Length();
        if (level == 0)
        {
            if (numBaseClasses > 0 || numDerivedClasses > 0)
            {
                std::u32string link = ToUtf32(contentFilePathResolver->ResolveContentFilePath(projectName, GetProject(classElement), ".", classElement->GetAttribute(U"id")));
                classes.push_back(Class(MakeFullClassName(classElement), classes.size(), level, true, numDerivedClasses > 0, link));
                if (numDerivedClasses > 0)
                {
                    ++level;
                    for (int i = 0; i < numDerivedClasses; ++i)
                    {
                        sngxml::dom::Node* derivedClassNode = (*derivedClassNodeSet)[i];
                        if (derivedClassNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
                        {
                            sngxml::dom::Element* derivedClassIdElement = static_cast<sngxml::dom::Element*>(derivedClassNode);
                            std::u32string derivedClassId = derivedClassIdElement->GetAttribute(U"derivedClassId");
                            sngxml::dom::Element* derivedClassElement = contentXml->GetElementById(derivedClassId);
                            if (derivedClassElement)
                            {
                                if (derivedClassElement->Name() == U"specialization")
                                {
                                    std::u32string primaryTypeId = derivedClassElement->GetAttribute(U"primaryTypeId");
                                    derivedClassElement = contentXml->GetElementById(primaryTypeId);
                                }
                                if (derivedClassElement)
                                {
                                    if (derivedClassElement->Name() == U"class")
                                    {
                                        std::u32string link = ToUtf32(contentFilePathResolver->ResolveContentFilePath(projectName, GetProject(derivedClassElement), ".", derivedClassElement->GetAttribute(U"id")));
                                        bool hasDerivedClasses = false;
                                        std::unique_ptr<sngxml::xpath::XPathObject> descendantClasses = sngxml::xpath::Evaluate(U"derivedClasses/derivedClass", derivedClassElement);
                                        if (descendantClasses->Type() == sngxml::xpath::XPathObjectType::nodeSet)
                                        {
                                            sngxml::xpath::XPathNodeSet* descendantClassNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(descendantClasses.get());
                                            int numDescendantClasses = descendantClassNodeSet->Length();
                                            if (numDescendantClasses > 0)
                                            {
                                                hasDerivedClasses = true;
                                            }
                                        }
                                        classes.push_back(Class(MakeFullClassName(derivedClassElement), classes.size(), level, false, hasDerivedClasses, link));
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
            std::u32string link = ToUtf32(contentFilePathResolver->ResolveContentFilePath(projectName, GetProject(classElement), ".", classElement->GetAttribute(U"id")));
            classes.push_back(Class(MakeFullClassName(classElement), classes.size(), level, false, numDerivedClasses > 0, link));
        }
    }
}

struct ByLevelAndIndex
{
    bool operator()(const Class& left, const Class& right) const
    {
        if (left.level < right.level) return true;
        if (left.level > right.level) return false;
        return left.index < right.index;
    }
};

bool GenerateClassInheritanceDiagramFile(const std::u32string& projectName, const std::string& contentDir, sngxml::dom::Element* classElement, sngxml::dom::Document* contentXml,
    std::string& inheritanceDiagramFileName, HtmlContentFilePathResolver* contentFilePathResolver)
{
    int depth = 0;
    int level = 0;
    std::vector<Class> classes;
    GenerateClassData(projectName, classes, classElement, contentXml, depth, level, contentFilePathResolver);
    if (!classes.empty())
    {
        for (Class& cls : classes)
        {
            cls.level += depth;
        }
        std::sort(classes.begin(), classes.end(), ByLevelAndIndex());
        inheritanceDiagramFileName = ToUtf8(classElement->GetAttribute(U"id")) + "_inheritance.js";
        std::string inheritanceDiagramFilePath = Path::Combine(contentDir, inheritanceDiagramFileName);
        std::ofstream inheritanceDiagramFile(inheritanceDiagramFilePath);
        CodeFormatter formatter(inheritanceDiagramFile);
        GenerateClassInheritanceDiagramCode(formatter);
        formatter.WriteLine("function drawClassInheritanceDiagram() {");
        formatter.IncIndent();
        formatter.WriteLine("var classes = [");
        formatter.IncIndent();
        bool first = true;
        for (Class& cls : classes)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                formatter.WriteLine(",");
            }
            cls.Write(formatter);
        }
        formatter.WriteLine("];");
        formatter.DecIndent();
        formatter.WriteLine("drawDiagram(classes);");
        formatter.DecIndent();
        formatter.WriteLine("}");
        formatter.WriteLine();
        return true;
    }
    else
    {
        return false;
    }
}

void GenerateClassContent(const std::u32string& projectName, sngxml::dom::Element* classElement, sngxml::dom::Document* contentXml, const std::string& contentDir, const std::string& styleDirName, const std::string& styleFileName,
    const std::u32string& topLink, const std::u32string& parentLink, const std::u32string& prevLink, std::u32string& nextLink,
    std::unordered_map<std::u32string, std::unique_ptr<sngxml::dom::Element>>& inlineCodeMap, const std::string& contentXmlFilePath, bool verbose, bool rebuild,
    HtmlContentFilePathResolver* contentFilePathResolver, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml)
{
    std::vector<sngxml::dom::Element*> constructorElements;
    std::vector<sngxml::dom::Element*> functionElements;
    std::u32string className = MakeClassName(classElement);
    std::u32string classId = classElement->GetAttribute(U"id");
    std::u32string classKey = classElement->GetAttribute(U"key");
    std::string classFileName = ToUtf8(classId) + ".html";
    std::string classFilePath = Path::Combine(contentDir, classFileName);
    if (!rebuild)
    {
        if (boost::filesystem::exists(classFilePath) && boost::filesystem::exists(contentXmlFilePath) && boost::filesystem::last_write_time(contentXmlFilePath) < boost::filesystem::last_write_time(classFilePath))
        {
            return;
        }
    }
    std::ofstream classFile(classFilePath);
    CodeFormatter formatter(classFile);
    sngxml::dom::Document classDocument;
    std::unique_ptr<sngxml::dom::Element> htmlElement(new sngxml::dom::Element(U"html"));
    std::unique_ptr<sngxml::dom::Element> headElement(new sngxml::dom::Element(U"head"));
    std::unique_ptr<sngxml::dom::Element> metaElement(new sngxml::dom::Element(U"meta"));
    metaElement->SetAttribute(U"charset", U"utf-8");
    headElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(metaElement.release()));
    std::unique_ptr<sngxml::dom::Element> titleElement(new sngxml::dom::Element(U"title"));
    std::u32string abstract_;
    if (classElement->GetAttribute(U"abstract") == U"true")
    {
        abstract_ = U"Abstract ";
    }
    std::u32string title = className + U" " + abstract_ + MakeTitle(classKey);
    titleElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(title)));
    headElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(titleElement.release()));
    std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"link"));
    linkElement->SetAttribute(U"rel", U"stylesheet");
    linkElement->SetAttribute(U"type", U"text/css");
    std::u32string relativeStyleFilePath = ToUtf32(Path::Combine(Path::Combine("..", styleDirName), styleFileName));
    linkElement->SetAttribute(U"href", relativeStyleFilePath);
    headElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(linkElement.release()));
    std::string inheritanceDiagramFileName;
    bool classInheritanceDiagramGenerated = GenerateClassInheritanceDiagramFile(projectName, contentDir, classElement, contentXml, inheritanceDiagramFileName, contentFilePathResolver);
    if (classInheritanceDiagramGenerated)
    {
        std::unique_ptr<sngxml::dom::Element> scriptElement(new sngxml::dom::Element(U"script"));
        scriptElement->SetAttribute(U"type", U"text/javascript");
        scriptElement->SetAttribute(U"src", ToUtf32(inheritanceDiagramFileName));
        scriptElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" ")));
        headElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(scriptElement.release()));
    }
    htmlElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(headElement.release()));
    std::unique_ptr<sngxml::dom::Element> bodyElement(new sngxml::dom::Element(U"body"));
    GenerateNavigation(bodyElement.get(), Navigation::header, topLink, parentLink, prevLink, nextLink);
    std::unique_ptr<sngxml::dom::Element> h1Element(new sngxml::dom::Element(U"h1"));
    h1Element->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(title)));
    bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(h1Element.release()));
    GenerateDocumentation(projectName, documentationXmlFileName, documentationXml, bodyElement.get(), classId, contentXml, contentFilePathResolver, DocFlags::full | DocFlags::paragraph);
    if (classInheritanceDiagramGenerated)
    {
        bodyElement->SetAttribute(U"onload", U"drawClassInheritanceDiagram()");
        std::unique_ptr<sngxml::dom::Element> divElement(new sngxml::dom::Element(U"div"));
        divElement->SetAttribute(U"class", U"diagram");
        std::unique_ptr<sngxml::dom::Element> svgElement(new sngxml::dom::Element(U"svg"));
        svgElement->SetAttribute(U"width", U"0");
        svgElement->SetAttribute(U"height", U"0");
        svgElement->SetAttribute(U"id", U"classInheritanceDiagram");
        svgElement->SetAttribute(U"xmlns", U"http://www.w3.org/2000/svg");
        svgElement->SetAttribute(U"version", U"2.0");
        divElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(svgElement.release()));
        bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(divElement.release()));
    }
    std::u32string definitionFileId = classElement->GetAttribute(U"definitionFileId");
    if (!definitionFileId.empty())
    {
        std::unique_ptr<sngxml::dom::Element> span(new sngxml::dom::Element(U"span"));
        span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"Definition at line ")));
        std::unique_ptr<sngxml::dom::Element> lineLink(new sngxml::dom::Element(U"a"));
        std::u32string line = classElement->GetAttribute(U"definitionLine");
        lineLink->SetAttribute(U"href", definitionFileId + U"#" + line);
        lineLink->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(line)));
        span->AppendChild(std::unique_ptr<sngxml::dom::Node>(lineLink.release()));
        span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" of ")));
        std::unique_ptr<sngxml::dom::Element> fileLink(new sngxml::dom::Element(U"a"));
        fileLink->SetAttribute(U"href", definitionFileId);
        fileLink->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(classElement->GetAttribute(U"definitionFile"))));
        span->AppendChild(std::unique_ptr<sngxml::dom::Node>(fileLink.release()));
        bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span.release()));
        bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"br")));
    }
    GenerateClassSection(projectName, bodyElement.get(), classElement, contentXml, contentDir, styleDirName, styleFileName, inlineCodeMap, contentXmlFilePath, verbose, rebuild,
        contentFilePathResolver, topLink, documentationXmlFileName, documentationXml);
    GenerateConstructorSection(projectName, bodyElement.get(), classElement, contentDir, styleDirName, styleFileName, contentXml, constructorElements, contentFilePathResolver,
        documentationXmlFileName, documentationXml);
    GenerateFunctionSection(projectName, U"Member Functions", bodyElement.get(), classElement, contentDir, styleDirName, styleFileName, contentXml, functionElements, contentFilePathResolver,
        documentationXmlFileName, documentationXml);
    GenerateEnumSection(projectName, bodyElement.get(), classElement, contentXml, contentDir, styleDirName, styleFileName, contentXmlFilePath, verbose, rebuild, topLink,
        contentFilePathResolver, documentationXmlFileName, documentationXml);
    GenerateTypedefSection(projectName, bodyElement.get(), classElement, contentXml, contentDir, styleDirName, styleFileName, contentFilePathResolver, topLink,
        documentationXmlFileName, documentationXml);
    GenerateVariableSection(projectName, U"Member Variables", bodyElement.get(), classElement, contentXml, contentDir, styleDirName, styleFileName, contentFilePathResolver, topLink,
        documentationXmlFileName, documentationXml);
    bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"hr")));
    GenerateFunctionDetailSection(projectName, U"Constructor Details", U"Constructor", bodyElement.get(), classElement, constructorElements, contentXml, inlineCodeMap, contentFilePathResolver,
        documentationXmlFileName, documentationXml);
    GenerateFunctionDetailSection(projectName, U"Member Function Details", U"Member Function", bodyElement.get(), classElement, functionElements, contentXml, inlineCodeMap, contentFilePathResolver,
        documentationXmlFileName, documentationXml);
    GenerateNavigation(bodyElement.get(), Navigation::footer, topLink, parentLink, prevLink, nextLink);
    htmlElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(bodyElement.release()));
    classDocument.AppendChild(std::unique_ptr<sngxml::dom::Node>(htmlElement.release()));
    classDocument.Write(formatter);
    if (verbose)
    {
        std::cout << ToUtf8(projectName) << "==> " << classFilePath << std::endl;
    }
}

void GenerateClassSection(const std::u32string& projectName, sngxml::dom::Element* pageElement, sngxml::dom::Element* parentElement, sngxml::dom::Document* contentXml,
    const std::string& contentDir, const std::string& styleDirName, const std::string& styleFileName,
    std::unordered_map<std::u32string, std::unique_ptr<sngxml::dom::Element>>& inlineCodeMap, const std::string& contentXmlFilePath, bool verbose, bool rebuild,
    HtmlContentFilePathResolver* contentFilePathResolver, const std::u32string& topLink, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml)
{
    std::unique_ptr<sngxml::dom::Element> classTableElement(new sngxml::dom::Element(U"table"));
    std::unique_ptr<sngxml::xpath::XPathObject> classes = sngxml::xpath::Evaluate(U"classes/class", parentElement);
    if (classes->Type() == sngxml::xpath::XPathObjectType::nodeSet)
    {
        std::u32string parentLink = parentElement->GetAttribute(U"id") + U".html";
        std::u32string prevLink;
        std::u32string nextLink;
        sngxml::xpath::XPathNodeSet* classNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(classes.get());
        int n = classNodeSet->Length();
        std::vector<sngxml::dom::Element*> matchedClasses;
        for (int i = 0; i < n; ++i)
        {
            sngxml::dom::Node* classNode = (*classNodeSet)[i];
            sngxml::dom::Element* classElement = static_cast<sngxml::dom::Element*>(classNode);
            if (!ProjectNameMatches(classElement, projectName)) continue;
            matchedClasses.push_back(classElement);
        }
        if (!matchedClasses.empty())
        {
            std::unique_ptr<sngxml::dom::Element> h2Element(new sngxml::dom::Element(U"h2"));
            h2Element->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"Classes")));
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(h2Element.release()));
        }
        for (int i = 0; i < matchedClasses.size(); ++i)
        {
            nextLink.clear();
            if (i < matchedClasses.size() - 1)
            {
                sngxml::dom::Element* nextClassElement = matchedClasses[i + 1];
                nextLink = nextClassElement->GetAttribute(U"id") + U".html";
            }
            sngxml::dom::Element* classElement = matchedClasses[i];
            std::unique_ptr<sngxml::dom::Element> trElement(new sngxml::dom::Element(U"tr"));
            std::unique_ptr<sngxml::dom::Element> tdElement(new sngxml::dom::Element(U"td"));
            std::u32string classKey = classElement->GetAttribute(U"key");
            std::u32string classId = classElement->GetAttribute(U"id");
            std::u32string className = classElement->GetAttribute(U"name");
            tdElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(classKey + U" ")));
            std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"a"));
            std::u32string classLink = classId + U".html";
            linkElement->SetAttribute(U"href", classLink);
            linkElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(className)));
            tdElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(linkElement.release()));
            trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(tdElement.release()));
            if (documentationXml && documentationXml->GetElementById(classId) != nullptr)
            {
                std::unique_ptr<sngxml::dom::Element> documentationTdElement(new sngxml::dom::Element(U"td"));
                GenerateDocumentation(projectName, documentationXmlFileName, documentationXml, documentationTdElement.get(), classId, contentXml, contentFilePathResolver, DocFlags::none);
                trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(documentationTdElement.release()));
            }
            classTableElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(trElement.release()));
            GenerateClassContent(projectName, classElement, contentXml, contentDir, styleDirName, styleFileName, topLink, parentLink, prevLink, nextLink, inlineCodeMap,
                contentXmlFilePath, verbose, rebuild, contentFilePathResolver, documentationXmlFileName, documentationXml);
            prevLink = classLink;
        }
        if (!matchedClasses.empty())
        {
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(classTableElement.release()));
        }
    }
}

void GenerateEnumContent(const std::u32string& projectName, sngxml::dom::Element* enumTypeElement, sngxml::dom::Document* contentXml, const std::string& contentDir, const std::string& styleDirName, const std::string& styleFileName,
    const std::u32string& topLink, const std::u32string& parentLink, const std::u32string& prevLink, std::u32string& nextLink, const std::string& contentXmlFilePath, bool verbose, bool rebuild,
    HtmlContentFilePathResolver* contentFilePathResolver, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml)
{
    std::u32string enumTypeName = enumTypeElement->GetAttribute(U"name");
    std::u32string enumTypeId = enumTypeElement->GetAttribute(U"id");
    std::u32string enumKey = enumTypeElement->GetAttribute(U"key");
    std::string enumFileName = ToUtf8(enumTypeId) + ".html";
    std::string enumFilePath = Path::Combine(contentDir, enumFileName);
    std::ofstream enumFile(enumFilePath);
    if (!rebuild)
    {
        if (boost::filesystem::exists(enumFilePath) && boost::filesystem::exists(contentXmlFilePath) && boost::filesystem::last_write_time(contentXmlFilePath) < boost::filesystem::last_write_time(enumFilePath))
        {
            return;
        }
    }
    CodeFormatter formatter(enumFile);
    sngxml::dom::Document enumDocument;
    std::unique_ptr<sngxml::dom::Element> htmlElement(new sngxml::dom::Element(U"html"));
    std::unique_ptr<sngxml::dom::Element> headElement(new sngxml::dom::Element(U"head"));
    std::unique_ptr<sngxml::dom::Element> metaElement(new sngxml::dom::Element(U"meta"));
    metaElement->SetAttribute(U"charset", U"utf-8");
    headElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(metaElement.release()));
    std::unique_ptr<sngxml::dom::Element> titleElement(new sngxml::dom::Element(U"title"));
    std::u32string title = enumTypeName + U" Enumeration";
    titleElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(title)));
    headElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(titleElement.release()));
    std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"link"));
    linkElement->SetAttribute(U"rel", U"stylesheet");
    linkElement->SetAttribute(U"type", U"text/css");
    std::u32string relativeStyleFilePath = ToUtf32(Path::Combine(Path::Combine("..", styleDirName), styleFileName));
    linkElement->SetAttribute(U"href", relativeStyleFilePath);
    headElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(linkElement.release()));
    htmlElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(headElement.release()));
    std::unique_ptr<sngxml::dom::Element> bodyElement(new sngxml::dom::Element(U"body"));
    GenerateNavigation(bodyElement.get(), Navigation::header, topLink, parentLink, prevLink, nextLink);
    std::unique_ptr<sngxml::dom::Element> h1Element(new sngxml::dom::Element(U"h1"));
    h1Element->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(title)));
    bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(h1Element.release()));
    GenerateDocumentation(projectName, documentationXmlFileName, documentationXml, bodyElement.get(), enumTypeId, contentXml, contentFilePathResolver, DocFlags::full | DocFlags::paragraph);
    std::u32string definitionFileId = enumTypeElement->GetAttribute(U"definitionFileId");
    if (!definitionFileId.empty())
    {
        std::unique_ptr<sngxml::dom::Element> span(new sngxml::dom::Element(U"span"));
        span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"Definition at line ")));
        std::unique_ptr<sngxml::dom::Element> lineLink(new sngxml::dom::Element(U"a"));
        std::u32string line = enumTypeElement->GetAttribute(U"definitionLine");
        lineLink->SetAttribute(U"href", definitionFileId + U"#" + line);
        lineLink->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(line)));
        span->AppendChild(std::unique_ptr<sngxml::dom::Node>(lineLink.release()));
        span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" of ")));
        std::unique_ptr<sngxml::dom::Element> fileLink(new sngxml::dom::Element(U"a"));
        fileLink->SetAttribute(U"href", definitionFileId);
        fileLink->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(enumTypeElement->GetAttribute(U"definitionFile"))));
        span->AppendChild(std::unique_ptr<sngxml::dom::Node>(fileLink.release()));
        bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span.release()));
        bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"br")));
    }
    std::unique_ptr<sngxml::xpath::XPathObject> enumerators = sngxml::xpath::Evaluate(U"enumerators/enumerator", enumTypeElement);
    if (enumerators->Type() == sngxml::xpath::XPathObjectType::nodeSet)
    {
        sngxml::xpath::XPathNodeSet* enumeratorNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(enumerators.get());
        int n = enumeratorNodeSet->Length();
        if (n > 0)
        {
            std::unique_ptr<sngxml::dom::Element> h2Element(new sngxml::dom::Element(U"h2"));
            h2Element->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"Enumerators")));
            bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(h2Element.release()));
            std::unique_ptr<sngxml::dom::Element> enumeratorTableElement(new sngxml::dom::Element(U"table"));
            std::unique_ptr<sngxml::dom::Element> trElement(new sngxml::dom::Element(U"tr"));
            std::unique_ptr<sngxml::dom::Element> nameThElement(new sngxml::dom::Element(U"th"));
            nameThElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"Name")));
            trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(nameThElement.release()));
            std::unique_ptr<sngxml::dom::Element> valueThElement(new sngxml::dom::Element(U"th"));
            valueThElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"Value")));
            trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(valueThElement.release()));
            enumeratorTableElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(trElement.release()));
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*enumeratorNodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* enumeratorElement = static_cast<sngxml::dom::Element*>(node);
                    std::u32string enumeratorName = enumeratorElement->GetAttribute(U"name");
                    std::u32string enumeratorValue = enumeratorElement->GetAttribute(U"value");
                    std::u32string enumeratorId = enumeratorElement->GetAttribute(U"id");
                    std::unique_ptr<sngxml::dom::Element> trElement(new sngxml::dom::Element(U"tr"));
                    trElement->SetAttribute(U"id", enumeratorId);
                    std::unique_ptr<sngxml::dom::Element> nameTdElement(new sngxml::dom::Element(U"td"));
                    nameTdElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(enumeratorName)));
                    trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(nameTdElement.release()));
                    std::unique_ptr<sngxml::dom::Element> valueTdElement(new sngxml::dom::Element(U"td"));
                    valueTdElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(enumeratorValue)));
                    trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(valueTdElement.release()));
                    enumeratorTableElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(trElement.release()));
                }
            }
            bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(enumeratorTableElement.release()));
        }
    }
    bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"hr")));
    GenerateNavigation(bodyElement.get(), Navigation::footer, topLink, parentLink, prevLink, nextLink);
    htmlElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(bodyElement.release()));
    enumDocument.AppendChild(std::unique_ptr<sngxml::dom::Node>(htmlElement.release()));
    enumDocument.Write(formatter);
    if (verbose)
    {
        std::cout << ToUtf8(projectName) << "==> " << enumFilePath << std::endl;
    }
}

void GenerateEnumSection(const std::u32string& projectName, sngxml::dom::Element* pageElement, sngxml::dom::Element* parentElement, sngxml::dom::Document* contentXml,
    const std::string& contentDir, const std::string& styleDirName, const std::string& styleFileName, const std::string& contentXmlFilePath, bool verbose, bool rebuild,
    const std::u32string& topLink, HtmlContentFilePathResolver* contentFilePathResolver, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml)
{
    std::unique_ptr<sngxml::dom::Element> enumTableElement(new sngxml::dom::Element(U"table"));
    std::unique_ptr<sngxml::xpath::XPathObject> enumTypes = sngxml::xpath::Evaluate(U"enumTypes/enumType", parentElement);
    if (enumTypes->Type() == sngxml::xpath::XPathObjectType::nodeSet)
    {
        std::u32string parentLink = parentElement->GetAttribute(U"id") + U".html";
        std::u32string prevLink;
        std::u32string nextLink;
        sngxml::xpath::XPathNodeSet* enumTypeNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(enumTypes.get());
        int n = enumTypeNodeSet->Length();
        std::vector<sngxml::dom::Element*> matchedEnums;
        for (int i = 0; i < n; ++i)
        {
            sngxml::dom::Node* enumNode = (*enumTypeNodeSet)[i];
            sngxml::dom::Element* enumElement = static_cast<sngxml::dom::Element*>(enumNode);
            if (!ProjectNameMatches(enumElement, projectName)) continue;
            matchedEnums.push_back(enumElement);
        }
        if (!matchedEnums.empty())
        {
            std::unique_ptr<sngxml::dom::Element> h2Element(new sngxml::dom::Element(U"h2"));
            h2Element->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"Enumerations")));
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(h2Element.release()));
        }
        for (int i = 0; i < matchedEnums.size(); ++i)
        {
            nextLink.clear();
            if (i < matchedEnums.size() - 1)
            {
                sngxml::dom::Element* nextEnumTypeElement = static_cast<sngxml::dom::Element*>(matchedEnums[i + 1]);
                nextLink = nextEnumTypeElement->GetAttribute(U"id") + U".html";
            }
            sngxml::dom::Element* enumTypeElement = static_cast<sngxml::dom::Element*>(matchedEnums[i]);
            std::unique_ptr<sngxml::dom::Element> trElement(new sngxml::dom::Element(U"tr"));
            std::unique_ptr<sngxml::dom::Element> tdElement(new sngxml::dom::Element(U"td"));
            std::u32string enumKey = enumTypeElement->GetAttribute(U"key");
            std::u32string enumId = enumTypeElement->GetAttribute(U"id");
            std::u32string enumTypeName = enumTypeElement->GetAttribute(U"name");
            tdElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(enumKey + U" ")));
            std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"a"));
            std::u32string enumTypeLink = enumId + U".html";
            linkElement->SetAttribute(U"href", enumTypeLink);
            linkElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(enumTypeName)));
            tdElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(linkElement.release()));
            trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(tdElement.release()));
            if (documentationXml && documentationXml->GetElementById(enumId) != nullptr)
            {
                std::unique_ptr<sngxml::dom::Element> documentationTdElement(new sngxml::dom::Element(U"td"));
                GenerateDocumentation(projectName, documentationXmlFileName, documentationXml, documentationTdElement.get(), enumId, contentXml, contentFilePathResolver, DocFlags::none);
                trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(documentationTdElement.release()));
            }
            enumTableElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(trElement.release()));
            GenerateEnumContent(projectName, enumTypeElement, contentXml, contentDir, styleDirName, styleFileName, topLink, parentLink, prevLink, nextLink, contentXmlFilePath, verbose, rebuild,
                contentFilePathResolver, documentationXmlFileName, documentationXml);
            prevLink = enumTypeLink;
        }
        if (!matchedEnums.empty())
        {
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(enumTableElement.release()));
        }
    }
}

void AppendTypeName(const std::u32string& projectName, sngxml::dom::Element* pageElement, sngxml::dom::Element* parentElement, const std::u32string& typeId, sngxml::dom::Document* contentXml,
    HtmlContentFilePathResolver* contentFilePathResolver)
{
    sngxml::dom::Element* typeElement = contentXml->GetElementById(typeId);
    if (typeElement)
    {
        std::u32string typeProject = GetProject(typeElement);
        std::u32string typeElementName = typeElement->Name();
        if (typeElementName == U"simpleType")
        {
            std::unique_ptr<sngxml::dom::Element> span(new sngxml::dom::Element(U"span"));
            span->SetAttribute(U"class", U"kw");
            span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(typeElement->GetAttribute(U"name"))));
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span.release()));
        }
        else if (typeElementName == U"externalType")
        {
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(typeElement->GetAttribute(U"name"))));
        }
        else if (typeElementName == U"integerLiteralType")
        {
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(typeElement->GetAttribute(U"name"))));
        }
        else if (typeElementName == U"derivedType")
        {
            std::unique_ptr<sngxml::xpath::XPathObject> derivations = sngxml::xpath::Evaluate(U"derivations/derivation", typeElement);
            if (derivations->Type() == sngxml::xpath::XPathObjectType::nodeSet)
            {
                sngxml::xpath::XPathNodeSet* derivationNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(derivations.get());
                int n = derivationNodeSet->Length();
                for (int i = 0; i < n; ++i)
                {
                    sngxml::dom::Node* derivationNode = (*derivationNodeSet)[i];
                    if (derivationNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
                    {
                        sngxml::dom::Element* derivationElement = static_cast<sngxml::dom::Element*>(derivationNode);
                        std::u32string derivationKind = derivationElement->GetAttribute(U"kind");
                        if (derivationKind == U"base")
                        {
                            std::u32string typeId = derivationElement->GetAttribute(U"typeId");
                            AppendTypeName(projectName, pageElement, parentElement, typeId, contentXml, contentFilePathResolver);
                        }
                        else
                        {
                            std::u32string derivationStr = derivationElement->GetAttribute(U"str");
                            if (derivationKind == U"specifier")
                            {
                                std::unique_ptr<sngxml::dom::Element> span(new sngxml::dom::Element(U"span"));
                                span->SetAttribute(U"class", U"kw");
                                span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(derivationStr)));
                                pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span.release()));
                            }
                            else
                            {
                                pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(derivationStr)));
                            }
                        }
                    }
                }
            }
        }
        else if (typeElementName == U"specialization")
        {
            std::u32string primaryTypeId = typeElement->GetAttribute(U"primaryTypeId");
            AppendTypeName(projectName, pageElement, parentElement, primaryTypeId, contentXml, contentFilePathResolver);
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"<")));
            std::unique_ptr<sngxml::xpath::XPathObject> templateArguments = sngxml::xpath::Evaluate(U"templateArguments/templateArgument", typeElement);
            if (templateArguments->Type() == sngxml::xpath::XPathObjectType::nodeSet)
            {
                sngxml::xpath::XPathNodeSet* templateArgumentNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(templateArguments.get());
                int n = templateArgumentNodeSet->Length();
                for (int i = 0; i < n; ++i)
                {
                    if (i > 0)
                    {
                        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U", ")));
                    }
                    sngxml::dom::Node* templateArgumentNode = (*templateArgumentNodeSet)[i];
                    if (templateArgumentNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
                    {
                        sngxml::dom::Element* templateArgumentElement = static_cast<sngxml::dom::Element*>(templateArgumentNode);
                        std::u32string templateArgumentTypeId = templateArgumentElement->GetAttribute(U"typeId");
                        AppendTypeName(projectName, pageElement, parentElement, templateArgumentTypeId, contentXml, contentFilePathResolver);
                    }
                }
            }
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U">")));
        }
        else if (typeElementName == U"typedef")
        {
            std::u32string parentProject;
            std::u32string parentId;
            sngxml::dom::ParentNode* parent = typeElement->Parent();
            while (parent)
            {
                if (parent->Name() == U"class" || parent->Name() == U"namespace")
                {
                    if (parent->GetNodeType() == sngxml::dom::NodeType::elementNode)
                    {
                        sngxml::dom::Element* parentElement = static_cast<sngxml::dom::Element*>(parent);
                        parentProject = GetProject(parentElement);
                        parentId = parentElement->GetAttribute(U"id");
                        break;
                    }
                }
                parent = parent->Parent();
            }
            std::u32string link = ToUtf32(contentFilePathResolver->ResolveContentFilePath(projectName, parentProject, ".", parentId)) + U"#" + typeId;
            std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"a"));
            linkElement->SetAttribute(U"href", link);
            linkElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(typeElement->GetAttribute(U"name"))));
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(linkElement.release()));
        }
        else
        {
            std::u32string link = ToUtf32(contentFilePathResolver->ResolveContentFilePath(projectName, typeProject, ".", typeId));
            std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"a"));
            linkElement->SetAttribute(U"href", link);
            linkElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(typeElement->GetAttribute(U"name"))));
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(linkElement.release()));
        }
    }
    else
    {
        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"@TYPE_NOT_FOUND")));
    }
}

void AppendParameter(const std::u32string& projectName, sngxml::dom::Element* pageElement, sngxml::dom::Element* parentElement, sngxml::dom::Element* parameterElement,
    sngxml::dom::Document* contentXml, HtmlContentFilePathResolver* contentFilePathResolver)
{
    std::u32string typeId = parameterElement->GetAttribute(U"type");
    AppendTypeName(projectName, pageElement, parentElement, typeId, contentXml, contentFilePathResolver);
    std::u32string name = parameterElement->GetAttribute(U"name");
    if (!name.empty())
    {
        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" " + name)));
    }
}

std::u32string MakeConstructorName(sngxml::dom::Element* constructorElement, bool fullName);

std::u32string MakeConstructorName(sngxml::dom::Element* constructorElement)
{
    return MakeConstructorName(constructorElement, false);
}

std::u32string MakeConstructorName(sngxml::dom::Element* constructorElement, bool fullName)
{
    std::u32string contructorName = constructorElement->GetAttribute(U"name");
    if (fullName)
    {
        std::u32string prefix = GetPrefix(constructorElement);
        if (!prefix.empty())
        {
            return prefix + U"::" + contructorName;
        }
        else
        {
            return contructorName;
        }
    }
    else
    {
        return contructorName;
    }
}

std::u32string MakeFunctionName(sngxml::dom::Element* functionElement, bool fullName);

std::u32string MakeFunctionName(sngxml::dom::Element* functionElement)
{
    return MakeFunctionName(functionElement, false);
}

std::u32string MakeFunctionName(sngxml::dom::Element* functionElement, bool fullName)
{
    std::u32string functionName = functionElement->GetAttribute(U"name");
    if (fullName)
    {
        std::u32string prefix = GetPrefix(functionElement);
        if (!prefix.empty())
        {
            functionName = prefix + U"::" + functionName;
        }
    }
    std::unique_ptr<sngxml::xpath::XPathObject> templateParameters = sngxml::xpath::Evaluate(U"templateParameters/templateParameter", functionElement);
    if (templateParameters->Type() == sngxml::xpath::XPathObjectType::nodeSet)
    {
        sngxml::xpath::XPathNodeSet* templateParameterNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(templateParameters.get());
        int n = templateParameterNodeSet->Length();
        if (n > 0)
        {
            functionName.append(1, '<');
            for (int i = 0; i < n; ++i)
            {
                if (i > 0)
                {
                    functionName.append(U", ");
                }
                sngxml::dom::Node* templateParameterNode = (*templateParameterNodeSet)[i];
                if (templateParameterNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* templateParameterElement = static_cast<sngxml::dom::Element*>(templateParameterNode);
                    functionName.append(templateParameterElement->GetAttribute(U"name"));
                }
            }
            functionName.append(1, '>');
        }
    }
    return functionName;
}

void AppendParameterList(const std::u32string& projectName, sngxml::dom::Element* pageElement, sngxml::dom::Element* parentElement, sngxml::dom::Element* functionElement,
    sngxml::dom::Document* contentXml, HtmlContentFilePathResolver* contentFilePathResolver)
{
    std::unique_ptr<sngxml::xpath::XPathObject> parameters = sngxml::xpath::Evaluate(U"parameters/parameter", functionElement);
    if (parameters->Type() == sngxml::xpath::XPathObjectType::nodeSet)
    {
        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"(")));
        sngxml::xpath::XPathNodeSet* parameterNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(parameters.get());
        int n = parameterNodeSet->Length();
        for (int i = 0; i < n; ++i)
        {
            if (i > 0)
            {
                pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U", ")));
            }
            sngxml::dom::Node* parameterNode = (*parameterNodeSet)[i];
            if (parameterNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
            {
                sngxml::dom::Element* parameterElement = static_cast<sngxml::dom::Element*>(parameterNode);
                AppendParameter(projectName, pageElement, parentElement, parameterElement, contentXml, contentFilePathResolver);
            }
        }
        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U")")));
    }
}

void GenerateVariableSection(const std::u32string& projectName, const std::u32string& title, sngxml::dom::Element* pageElement, sngxml::dom::Element* parentElement, sngxml::dom::Document* contentXml,
    const std::string& contentDir, const std::string& styleDirName, const std::string& styleFileName, HtmlContentFilePathResolver* contentFilePathResolver, const std::u32string& topLink,
    const std::string& documentationFileName, sngxml::dom::Document* documentationXml)
{
    std::unique_ptr<sngxml::dom::Element> variableTableElement(new sngxml::dom::Element(U"table"));
    std::unique_ptr<sngxml::xpath::XPathObject> variables = sngxml::xpath::Evaluate(U"variables/variable", parentElement);
    if (variables->Type() == sngxml::xpath::XPathObjectType::nodeSet)
    {
        std::u32string parentLink = parentElement->GetAttribute(U"id") + U".html";
        std::u32string prevLink;
        std::u32string nextLink;
        sngxml::xpath::XPathNodeSet* variableNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(variables.get());
        int n = variableNodeSet->Length();
        std::vector<sngxml::dom::Element*> matchedVariables;
        for (int i = 0; i < n; ++i)
        {
            sngxml::dom::Node* variableNode = (*variableNodeSet)[i];
            sngxml::dom::Element* variableElement = static_cast<sngxml::dom::Element*>(variableNode);
            if (!ProjectNameMatches(variableElement, projectName)) continue;
            matchedVariables.push_back(variableElement);
        }
        if (!matchedVariables.empty())
        {
            std::unique_ptr<sngxml::dom::Element> h2Element(new sngxml::dom::Element(U"h2"));
            h2Element->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(title)));
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(h2Element.release()));
        }
        for (int i = 0; i < matchedVariables.size(); ++i)
        {
            sngxml::dom::Element* variableElement = matchedVariables[i];
            std::u32string variableTypeId = variableElement->GetAttribute(U"type");
            std::u32string variableName = variableElement->GetAttribute(U"name");
            std::u32string specifiers = variableElement->GetAttribute(U"specifiers");
            std::u32string variableId = variableElement->GetAttribute(U"id");
            std::unique_ptr<sngxml::dom::Element> trElement(new sngxml::dom::Element(U"tr"));
            trElement->SetAttribute(U"id", variableId);
            std::unique_ptr<sngxml::dom::Element> typeTdElement(new sngxml::dom::Element(U"td"));
            AppendTypeName(projectName, typeTdElement.get(), parentElement, variableTypeId, contentXml, contentFilePathResolver);
            typeTdElement->SetAttribute(U"class", U"functionTableFirstCol");
            typeTdElement->SetAttribute(U"xml:space", U"preserve");
            trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(typeTdElement.release()));
            std::unique_ptr<sngxml::dom::Element> nameTdElement(new sngxml::dom::Element(U"td"));
            nameTdElement->SetAttribute(U"class", U"functionTableSecondCol");
            nameTdElement->SetAttribute(U"xml:space", U"preserve");
            nameTdElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(variableName)));
            if (!specifiers.empty())
            {
                nameTdElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" ")));
                std::unique_ptr<sngxml::dom::Element> span(new sngxml::dom::Element(U"span"));
                span->SetAttribute(U"class", U"kw");
                span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(specifiers)));
                nameTdElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span.release()));
            }
            trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(nameTdElement.release()));
            if (documentationXml && documentationXml->GetElementById(variableId) != nullptr)
            {
                std::unique_ptr<sngxml::dom::Element> documentationTdElement(new sngxml::dom::Element(U"td"));
                GenerateDocumentation(projectName, documentationFileName, documentationXml, documentationTdElement.get(), variableId, contentXml, contentFilePathResolver, DocFlags::none);
                trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(documentationTdElement.release()));
            }
            variableTableElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(trElement.release()));
        }
        if (!matchedVariables.empty())
        {
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(variableTableElement.release()));
        }
    }
}

void GenerateTypedefSection(const std::u32string& projectName, sngxml::dom::Element* pageElement, sngxml::dom::Element* parentElement, sngxml::dom::Document* contentXml,
    const std::string& contentDir, const std::string& styleDirName, const std::string& styleFileName, HtmlContentFilePathResolver* contentFilePathResolver, const std::u32string& topLink,
    const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml)
{
    std::unique_ptr<sngxml::dom::Element> typedefTableElement(new sngxml::dom::Element(U"table"));
    std::unique_ptr<sngxml::xpath::XPathObject> typedefs = sngxml::xpath::Evaluate(U"typedefs/typedef", parentElement);
    if (typedefs->Type() == sngxml::xpath::XPathObjectType::nodeSet)
    {
        std::u32string parentLink = parentElement->GetAttribute(U"id") + U".html";
        std::u32string prevLink;
        std::u32string nextLink;
        sngxml::xpath::XPathNodeSet* typedefNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(typedefs.get());
        int n = typedefNodeSet->Length();
        std::vector<sngxml::dom::Element*> matchedTypedefs;
        for (int i = 0; i < n; ++i)
        {
            sngxml::dom::Node* typedefNode = (*typedefNodeSet)[i];
            sngxml::dom::Element* typedefElement = static_cast<sngxml::dom::Element*>(typedefNode);
            if (!ProjectNameMatches(typedefElement, projectName)) continue;
            matchedTypedefs.push_back(typedefElement);
        }
        if (!matchedTypedefs.empty())
        {
            std::unique_ptr<sngxml::dom::Element> h2Element(new sngxml::dom::Element(U"h2"));
            h2Element->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"Typedefs")));
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(h2Element.release()));
        }
        for (int i = 0; i < matchedTypedefs.size(); ++i)
        {
            sngxml::dom::Element* typedefElement = matchedTypedefs[i];
            std::u32string typedefTypeId = typedefElement->GetAttribute(U"type");
            std::u32string typedefName = typedefElement->GetAttribute(U"name");
            std::u32string typedefId = typedefElement->GetAttribute(U"id");
            std::unique_ptr<sngxml::dom::Element> trElement(new sngxml::dom::Element(U"tr"));
            trElement->SetAttribute(U"id", typedefId);
            std::unique_ptr<sngxml::dom::Element> typeTdElement(new sngxml::dom::Element(U"td"));
            AppendTypeName(projectName, typeTdElement.get(), parentElement, typedefTypeId, contentXml, contentFilePathResolver);
            typeTdElement->SetAttribute(U"class", U"functionTableFirstCol");
            typeTdElement->SetAttribute(U"xml:space", U"preserve");
            trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(typeTdElement.release()));
            std::unique_ptr<sngxml::dom::Element> nameTdElement(new sngxml::dom::Element(U"td"));
            nameTdElement->SetAttribute(U"class", U"functionTableSecondCol");
            nameTdElement->SetAttribute(U"xml:space", U"preserve");
            nameTdElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(typedefName)));
            trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(nameTdElement.release()));
            if (documentationXml && documentationXml->GetElementById(typedefId) != nullptr)
            {
                std::unique_ptr<sngxml::dom::Element> documentationTdElement(new sngxml::dom::Element(U"td"));
                GenerateDocumentation(projectName, documentationXmlFileName, documentationXml, documentationTdElement.get(), typedefId, contentXml, contentFilePathResolver, DocFlags::none);
                trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(documentationTdElement.release()));
            }
            typedefTableElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(trElement.release()));
        }
        if (!matchedTypedefs.empty())
        {
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(typedefTableElement.release()));
        }
    }
}

void GenerateConstructorSection(const std::u32string& projectName, sngxml::dom::Element* pageElement, sngxml::dom::Element* parentElement, const std::string& contentDir,
    const std::string& styleDirName, const std::string& styleFileName, sngxml::dom::Document* contentXml, std::vector<sngxml::dom::Element*>& constructorElements,
    HtmlContentFilePathResolver* contentFilePathResolver, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml)
{
    std::unique_ptr<sngxml::dom::Element> constructorTableElement(new sngxml::dom::Element(U"table"));
    constructorTableElement->SetAttribute(U"class", U"constructorTable");
    std::unique_ptr<sngxml::xpath::XPathObject> constructors = sngxml::xpath::Evaluate(U"constructors/constructor", parentElement);
    if (constructors->Type() == sngxml::xpath::XPathObjectType::nodeSet)
    {
        sngxml::xpath::XPathNodeSet* constructorNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(constructors.get());
        int n = constructorNodeSet->Length();
        std::vector<sngxml::dom::Element*> matchedConstructors;
        for (int i = 0; i < n; ++i)
        {
            sngxml::dom::Node* constructorNode = (*constructorNodeSet)[i];
            sngxml::dom::Element* constructorElement = static_cast<sngxml::dom::Element*>(constructorNode);
            if (!ProjectNameMatches(constructorElement, projectName)) continue;
            matchedConstructors.push_back(constructorElement);
        }
        if (!matchedConstructors.empty())
        {
            std::unique_ptr<sngxml::dom::Element> h2Element(new sngxml::dom::Element(U"h2"));
            h2Element->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"Constructors")));
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(h2Element.release()));
        }
        for (int i = 0; i < matchedConstructors.size(); ++i)
        {
            sngxml::dom::Element* constructorElement = matchedConstructors[i];
            constructorElements.push_back(constructorElement);
            std::unique_ptr<sngxml::dom::Element> trElement(new sngxml::dom::Element(U"tr"));
            std::unique_ptr<sngxml::dom::Element> tdElement(new sngxml::dom::Element(U"td"));
            tdElement->SetAttribute(U"class", U"constructorTableFirstCol");
            tdElement->SetAttribute(U"xml:space", U"preserve");
            std::u32string constuctorName = MakeConstructorName(constructorElement);
            std::u32string constructorId = constructorElement->GetAttribute(U"id");
            std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"a"));
            std::u32string constructorLink = parentElement->GetAttribute(U"id");
            constructorLink.append(U".html#").append(constructorId);
            linkElement->SetAttribute(U"href", constructorLink);
            linkElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(constuctorName)));
            tdElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(linkElement.release()));
            AppendParameterList(projectName, tdElement.get(), parentElement, constructorElement, contentXml, contentFilePathResolver);
            std::u32string specifiers = constructorElement->GetAttribute(U"specifiers");
            if (!specifiers.empty())
            {
                tdElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" ")));
                std::unique_ptr<sngxml::dom::Element> span(new sngxml::dom::Element(U"span"));
                span->SetAttribute(U"class", U"kw");
                span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(specifiers)));
                tdElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span.release()));
            }
            trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(tdElement.release()));
            if (documentationXml && documentationXml->GetElementById(constructorId) != nullptr)
            {
                std::unique_ptr<sngxml::dom::Element> documentationTdElement(new sngxml::dom::Element(U"td"));
                GenerateDocumentation(projectName, documentationXmlFileName, documentationXml, documentationTdElement.get(), constructorId, contentXml, contentFilePathResolver, DocFlags::none);
                trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(documentationTdElement.release()));
            }
            constructorTableElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(trElement.release()));
        }
        if (!matchedConstructors.empty())
        {
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(constructorTableElement.release()));
        }
    }
}

void GenerateFunctionSection(const std::u32string& projectName, const std::u32string& title, sngxml::dom::Element* pageElement, sngxml::dom::Element* parentElement, const std::string& contentDir,
    const std::string& styleDirName, const std::string& styleFileName, sngxml::dom::Document* contentXml, std::vector<sngxml::dom::Element*>& functionElements,
    HtmlContentFilePathResolver* contentFilePathResolver, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml)
{
    std::unique_ptr<sngxml::dom::Element> functionTableElement(new sngxml::dom::Element(U"table"));
    functionTableElement->SetAttribute(U"class", U"functionTable");
    std::unique_ptr<sngxml::xpath::XPathObject> functions = sngxml::xpath::Evaluate(U"functions/function", parentElement);
    if (functions->Type() == sngxml::xpath::XPathObjectType::nodeSet)
    {
        sngxml::xpath::XPathNodeSet* functionNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(functions.get());
        int n = functionNodeSet->Length();
        std::vector<sngxml::dom::Element*> matchedFunctions;
        for (int i = 0; i < n; ++i)
        {
            sngxml::dom::Node* functionNode = (*functionNodeSet)[i];
            sngxml::dom::Element* functionElement = static_cast<sngxml::dom::Element*>(functionNode);
            if (!ProjectNameMatches(functionElement, projectName)) continue;
            matchedFunctions.push_back(functionElement);
        }
        if (!matchedFunctions.empty())
        {
            std::unique_ptr<sngxml::dom::Element> h2Element(new sngxml::dom::Element(U"h2"));
            h2Element->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(title)));
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(h2Element.release()));
        }
        for (int i = 0; i < matchedFunctions.size(); ++i)
        {
            sngxml::dom::Element* functionElement = static_cast<sngxml::dom::Element*>(matchedFunctions[i]);
            functionElements.push_back(functionElement);
            std::unique_ptr<sngxml::dom::Element> trElement(new sngxml::dom::Element(U"tr"));
            std::u32string returnTypeId = functionElement->GetAttribute(U"returnType");
            if (returnTypeId.empty())
            {
                std::unique_ptr<sngxml::dom::Element> tdElement(new sngxml::dom::Element(U"td"));
                tdElement->SetAttribute(U"class", U"functionTableFirstCol");
                tdElement->SetAttribute(U"xml:space", U"preserve");
                trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(tdElement.release()));
            }
            else
            {
                std::unique_ptr<sngxml::dom::Element> tdElement(new sngxml::dom::Element(U"td"));
                tdElement->SetAttribute(U"class", U"functionTableFirstCol");
                tdElement->SetAttribute(U"xml:space", U"preserve");
                AppendTypeName(projectName, tdElement.get(), parentElement, returnTypeId, contentXml, contentFilePathResolver);
                trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(tdElement.release()));
            }
            std::unique_ptr<sngxml::dom::Element> tdElement(new sngxml::dom::Element(U"td"));
            tdElement->SetAttribute(U"class", U"functionTableSecondCol");
            tdElement->SetAttribute(U"xml:space", U"preserve");
            std::u32string functionName = MakeFunctionName(functionElement);
            std::u32string functionId = functionElement->GetAttribute(U"id");
            std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"a"));
            std::u32string functionLink = parentElement->GetAttribute(U"id");
            functionLink.append(U".html#").append(functionId);
            linkElement->SetAttribute(U"href", functionLink);
            linkElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(functionName)));
            tdElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(linkElement.release()));
            AppendParameterList(projectName, tdElement.get(), parentElement, functionElement, contentXml, contentFilePathResolver);
            std::u32string specifiers = functionElement->GetAttribute(U"specifiers");
            if (!specifiers.empty())
            {
                tdElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" ")));
                std::unique_ptr<sngxml::dom::Element> span(new sngxml::dom::Element(U"span"));
                span->SetAttribute(U"class", U"kw");
                span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(specifiers)));
                tdElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span.release()));
            }
            trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(tdElement.release()));
            if (documentationXml && documentationXml->GetElementById(functionId) != nullptr)
            {
                std::unique_ptr<sngxml::dom::Element> documentationTdElement(new sngxml::dom::Element(U"td"));
                GenerateDocumentation(projectName, documentationXmlFileName, documentationXml, documentationTdElement.get(), functionId, contentXml, contentFilePathResolver, DocFlags::none);
                trElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(documentationTdElement.release()));
            }
            functionTableElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(trElement.release()));
        }
        if (!functionElements.empty())
        {
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(functionTableElement.release()));
        }
    }
}

struct ByFunctionName
{
    bool operator()(const std::pair<std::u32string, std::unique_ptr<sngxml::dom::Element>>& left, const std::pair<std::u32string, std::unique_ptr<sngxml::dom::Element>>& right) const
    {
        return left.first < right.first;
    }
};

void GenerateFunctionDetailSection(const std::u32string& projectName, const std::u32string& title, const std::u32string& functionTitle, sngxml::dom::Element* pageElement,
    sngxml::dom::Element* parentElement, std::vector<sngxml::dom::Element*>& functionElements, sngxml::dom::Document* contentXml,
    std::unordered_map<std::u32string, std::unique_ptr<sngxml::dom::Element>>& inlineCodeMap, HtmlContentFilePathResolver* contentFilePathResolver, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml)
{
    if (functionElements.empty()) return;
    std::unique_ptr<sngxml::dom::Element> h2Element(new sngxml::dom::Element(U"h2"));
    h2Element->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(title)));
    pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(h2Element.release()));
    int n = functionElements.size();
    for (int i = 0; i < n; ++i)
    {
        sngxml::dom::Element* functionElement = functionElements[i];
        std::u32string functionId = functionElement->GetAttribute(U"id");
        std::unique_ptr<sngxml::dom::Element> h3Element(new sngxml::dom::Element(U"h3"));
        h3Element->SetAttribute(U"id", functionId);
        std::u32string functionText = functionElement->GetAttribute(U"name");
        functionText.append(1, ' ').append(functionTitle);
        h3Element->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(functionText)));
        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(h3Element.release()));
        std::unique_ptr<sngxml::dom::Element> h4Element(new sngxml::dom::Element(U"h4"));
        std::u32string returnTypeId = functionElement->GetAttribute(U"returnType");
        if (!returnTypeId.empty())
        {
            AppendTypeName(projectName, h4Element.get(), parentElement, returnTypeId, contentXml, contentFilePathResolver);
            h4Element->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" ")));
        }
        std::u32string functionName;
        if (functionElement->Name() == U"function")
        {
            functionName = MakeFunctionName(functionElement, true);
        }
        else if (functionElement->Name() == U"constructor")
        {
            functionName = MakeConstructorName(functionElement, true);
        }
        h4Element->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(functionName)));
        AppendParameterList(projectName, h4Element.get(), parentElement, functionElement, contentXml, contentFilePathResolver);
        std::u32string specifiers = functionElement->GetAttribute(U"specifiers");
        if (!specifiers.empty())
        {
            h4Element->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" ")));
            std::unique_ptr<sngxml::dom::Element> span(new sngxml::dom::Element(U"span"));
            span->SetAttribute(U"class", U"kw");
            span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(specifiers)));
            h4Element->AppendChild(std::unique_ptr<sngxml::dom::Node>(span.release()));
        }
        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(h4Element.release()));
        GenerateDocumentation(projectName, documentationXmlFileName, documentationXml, pageElement, functionId, contentXml, contentFilePathResolver, DocFlags::full | DocFlags::paragraph);
        bool codeAdded = false;
        std::u32string definitionFileId = functionElement->GetAttribute(U"definitionFileId");
        if (!definitionFileId.empty())
        {
            std::unique_ptr<sngxml::dom::Element> span(new sngxml::dom::Element(U"span"));
            span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"Definition at line ")));
            std::unique_ptr<sngxml::dom::Element> lineLink(new sngxml::dom::Element(U"a"));
            std::u32string line = functionElement->GetAttribute(U"definitionLine");
            lineLink->SetAttribute(U"href", definitionFileId + U"#" + line);
            lineLink->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(line)));
            span->AppendChild(std::unique_ptr<sngxml::dom::Node>(lineLink.release()));
            span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" of ")));
            std::unique_ptr<sngxml::dom::Element> fileLink(new sngxml::dom::Element(U"a"));
            fileLink->SetAttribute(U"href", definitionFileId);
            fileLink->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(functionElement->GetAttribute(U"definitionFile"))));
            span->AppendChild(std::unique_ptr<sngxml::dom::Node>(fileLink.release()));
            auto it = inlineCodeMap.find(functionElement->GetAttribute(U"id"));
            if (it != inlineCodeMap.cend())
            {
                sngxml::dom::Element* inlineCode = it->second.get();
                if (inlineCode)
                {
                    span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U":")));
                    span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"br")));
                    std::unique_ptr<sngxml::dom::Element> inlineCode = std::move(it->second);
                    span->AppendChild(std::unique_ptr<sngxml::dom::Node>(inlineCode->CloneNode(true)));
                    span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"br")));
                    codeAdded = true;
                }
            }
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span.release()));
            if (!codeAdded)
            {
                pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"br")));
            }
        }
        std::u32string declarationFileId = functionElement->GetAttribute(U"declarationFileId");
        if (!declarationFileId.empty())
        {
            if (codeAdded)
            {
                pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"br")));
            }
            std::unique_ptr<sngxml::dom::Element> span(new sngxml::dom::Element(U"span"));
            span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"Declaration at line ")));
            std::unique_ptr<sngxml::dom::Element> lineLink(new sngxml::dom::Element(U"a"));
            std::u32string line = functionElement->GetAttribute(U"declarationLine");
            lineLink->SetAttribute(U"href", declarationFileId + U"#" + line);
            lineLink->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(line)));
            span->AppendChild(std::unique_ptr<sngxml::dom::Node>(lineLink.release()));
            span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" of ")));
            std::unique_ptr<sngxml::dom::Element> fileLink(new sngxml::dom::Element(U"a"));
            fileLink->SetAttribute(U"href", declarationFileId);
            fileLink->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(functionElement->GetAttribute(U"declarationFile"))));
            span->AppendChild(std::unique_ptr<sngxml::dom::Node>(fileLink.release()));
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span.release()));
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"br")));
        }
        bool hasOverriddenFunctions = false;
        std::unique_ptr<sngxml::xpath::XPathObject> overriddenFunctions = sngxml::xpath::Evaluate(U"overriddenFunctions/overriddenFunction", functionElement);
        if (overriddenFunctions->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* overriddenNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(overriddenFunctions.get());
            int n = overriddenNodeSet->Length();
            if (n > 0)
            {
                pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"br")));
                hasOverriddenFunctions = true;
                std::unique_ptr<sngxml::dom::Element> span(new sngxml::dom::Element(U"span"));
                span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"Base class overridden functions: ")));
                std::vector<std::pair<std::u32string, std::unique_ptr<sngxml::dom::Element>>> overriddenFunctionsVec;
                for (int i = 0; i < n; ++i)
                {
                    sngxml::dom::Node* overriddenNode = (*overriddenNodeSet)[i];
                    if (overriddenNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
                    {
                        sngxml::dom::Element* overriddenIdElement = static_cast<sngxml::dom::Element*>(overriddenNode);
                        std::u32string overriddenId = overriddenIdElement->GetAttribute(U"functionId");
                        if (!overriddenId.empty())
                        {
                            sngxml::dom::Element* overriddenElement = contentXml->GetElementById(overriddenId);
                            sngxml::dom::ParentNode* overriddenParent = overriddenElement->Parent();
                            if (overriddenParent->GetNodeType() == sngxml::dom::NodeType::elementNode)
                            {
                                sngxml::dom::Element* overriddenParentElement = static_cast<sngxml::dom::Element*>(overriddenParent);
                                if (overriddenParentElement->Name() == U"functions")
                                {
                                    sngxml::dom::ParentNode* functionsParent = overriddenParentElement->Parent();
                                    if (functionsParent->GetNodeType() == sngxml::dom::NodeType::elementNode)
                                    {
                                        sngxml::dom::Element* classElement = static_cast<sngxml::dom::Element*>(functionsParent);
                                        if (classElement->Name() == U"class")
                                        {
                                            std::u32string classId = classElement->GetAttribute(U"id");
                                            if (!classId.empty())
                                            {
                                                std::u32string proj = GetProject(classElement);
                                                if (!proj.empty())
                                                {
                                                    std::u32string classLink = ToUtf32(contentFilePathResolver->ResolveContentFilePath(projectName, proj, ".", classId));
                                                    std::u32string overriddenLink = classLink + U"#" + overriddenId;
                                                    std::u32string overriddenFunctionName = MakeFunctionName(overriddenElement, true);
                                                    std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"a"));
                                                    linkElement->SetAttribute(U"href", overriddenLink);
                                                    linkElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(overriddenFunctionName)));
                                                    overriddenFunctionsVec.push_back(std::make_pair(overriddenFunctionName, std::move(linkElement)));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                std::sort(overriddenFunctionsVec.begin(), overriddenFunctionsVec.end(), ByFunctionName());
                int n = overriddenFunctionsVec.size();
                for (int i = 0; i < n; ++i)
                {
                    if (i > 0)
                    {
                        span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U", ")));
                    }
                    std::pair<std::u32string, std::unique_ptr<sngxml::dom::Element>>& p = overriddenFunctionsVec[i];
                    std::unique_ptr<sngxml::dom::Element> linkElement = std::move(p.second);
                    span->AppendChild(std::unique_ptr<sngxml::dom::Node>(linkElement.release()));
                }
                pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span.release()));
                pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"br")));
            }
        }
        bool hasOverrides = false;
        std::unique_ptr<sngxml::xpath::XPathObject> overrides = sngxml::xpath::Evaluate(U"overrides/override", functionElement);
        if (overrides->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* overrideNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(overrides.get());
            int n = overrideNodeSet->Length();
            if (n > 0)
            {
                pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"br")));
                hasOverrides = true;
                std::unique_ptr<sngxml::dom::Element> span(new sngxml::dom::Element(U"span"));
                span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"Derived class overrides: ")));
                std::vector<std::pair<std::u32string, std::unique_ptr<sngxml::dom::Element>>> overrideVec;
                for (int i = 0; i < n; ++i)
                {
                    sngxml::dom::Node* overrideNode = (*overrideNodeSet)[i];
                    if (overrideNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
                    {
                        sngxml::dom::Element* overrideIdElement = static_cast<sngxml::dom::Element*>(overrideNode);
                        std::u32string overrideId = overrideIdElement->GetAttribute(U"functionId");
                        if (!overrideId.empty())
                        {
                            sngxml::dom::Element* overrideElement = contentXml->GetElementById(overrideId);
                            sngxml::dom::ParentNode* overrideParent = overrideElement->Parent();
                            if (overrideParent->GetNodeType() == sngxml::dom::NodeType::elementNode)
                            {
                                sngxml::dom::Element* overrideParentElement = static_cast<sngxml::dom::Element*>(overrideParent);
                                if (overrideParentElement->Name() == U"functions")
                                {
                                    sngxml::dom::ParentNode* functionsParent = overrideParentElement->Parent();
                                    if (functionsParent->GetNodeType() == sngxml::dom::NodeType::elementNode)
                                    {
                                        sngxml::dom::Element* classElement = static_cast<sngxml::dom::Element*>(functionsParent);
                                        if (classElement->Name() == U"class")
                                        {
                                            std::u32string classId = classElement->GetAttribute(U"id");
                                            if (!classId.empty())
                                            {
                                                std::u32string proj = GetProject(classElement);
                                                if (!proj.empty())
                                                {
                                                    std::u32string classLink = ToUtf32(contentFilePathResolver->ResolveContentFilePath(projectName, proj, ".", classId));
                                                    std::u32string overrideLink = classLink + U"#" + overrideId;
                                                    std::u32string overrideFunctionName = MakeFunctionName(overrideElement, true);
                                                    std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"a"));
                                                    linkElement->SetAttribute(U"href", overrideLink);
                                                    linkElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(overrideFunctionName)));
                                                    overrideVec.push_back(std::make_pair(overrideFunctionName, std::move(linkElement)));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                std::sort(overrideVec.begin(), overrideVec.end(), ByFunctionName());
                int n = overrideVec.size();
                for (int i = 0; i < n; ++i)
                {
                    if (i > 0)
                    {
                        span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U", ")));
                    }
                    std::pair<std::u32string, std::unique_ptr<sngxml::dom::Element>>& p = overrideVec[i];
                    std::unique_ptr<sngxml::dom::Element> linkElement = std::move(p.second);
                    span->AppendChild(std::unique_ptr<sngxml::dom::Node>(linkElement.release()));
                }
                pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span.release()));
                pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"br")));
            }
        }
        bool hasCalls = false;
        std::unique_ptr<sngxml::xpath::XPathObject> calls = sngxml::xpath::Evaluate(U"calls/call", functionElement);
        if (calls->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* callNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(calls.get());
            int n = callNodeSet->Length();
            if (n > 0)
            {
                hasCalls = true;
                std::unique_ptr<sngxml::dom::Element> span(new sngxml::dom::Element(U"span"));
                span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"Calls: ")));
                std::vector<std::pair<std::u32string, std::unique_ptr<sngxml::dom::Element>>> callVec;
                for (int i = 0; i < n; ++i)
                {
                    sngxml::dom::Node* callNode = (*callNodeSet)[i];
                    if (callNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
                    {
                        sngxml::dom::Element* callIdElement = static_cast<sngxml::dom::Element*>(callNode);
                        std::u32string callId = callIdElement->GetAttribute(U"functionId");
                        if (!callId.empty())
                        {
                            sngxml::dom::Element* callElement = contentXml->GetElementById(callId);
                            sngxml::dom::ParentNode* callParent = callElement->Parent();
                            if (callParent->GetNodeType() == sngxml::dom::NodeType::elementNode)
                            {
                                sngxml::dom::Element* callParentElement = static_cast<sngxml::dom::Element*>(callParent);
                                if (callParentElement->Name() == U"functions")
                                {
                                    sngxml::dom::ParentNode* functionsParent = callParentElement->Parent();
                                    if (functionsParent->GetNodeType() == sngxml::dom::NodeType::elementNode)
                                    {
                                        sngxml::dom::Element* parentElement = static_cast<sngxml::dom::Element*>(functionsParent);
                                        if (parentElement->Name() == U"class" || parentElement->Name() == U"namespace")
                                        {
                                            std::u32string parentId = parentElement->GetAttribute(U"id");
                                            if (!parentId.empty())
                                            {
                                                std::u32string proj = GetProject(parentElement);
                                                if (!proj.empty())
                                                {
                                                    std::u32string parentLink = ToUtf32(contentFilePathResolver->ResolveContentFilePath(projectName, proj, ".", parentId));
                                                    std::u32string callLink = parentLink + U"#" + callId;
                                                    std::u32string callFunctionName = MakeFunctionName(callElement, true);
                                                    std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"a"));
                                                    linkElement->SetAttribute(U"href", callLink);
                                                    linkElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(callFunctionName)));
                                                    callVec.push_back(std::make_pair(callFunctionName, std::move(linkElement)));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                std::sort(callVec.begin(), callVec.end(), ByFunctionName());
                int n = callVec.size();
                for (int i = 0; i < n; ++i)
                {
                    if (i > 0)
                    {
                        span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U", ")));
                    }
                    std::pair<std::u32string, std::unique_ptr<sngxml::dom::Element>>& p = callVec[i];
                    std::unique_ptr<sngxml::dom::Element> linkElement = std::move(p.second);
                    span->AppendChild(std::unique_ptr<sngxml::dom::Node>(linkElement.release()));
                }
                if (n > 0)
                {
                    pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"br")));
                    pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span.release()));
                    pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"br")));
                }
                else
                {
                    hasCalls = false;
                }
            }
        }
        bool hasCalledBy = false;
        std::unique_ptr<sngxml::xpath::XPathObject> calledBy = sngxml::xpath::Evaluate(U"calledByFunctions/calledByFunction", functionElement);
        if (calledBy->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* calledByNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(calledBy.get());
            int n = calledByNodeSet->Length();
            if (n > 0)
            {
                hasCalledBy = true;
                std::unique_ptr<sngxml::dom::Element> span(new sngxml::dom::Element(U"span"));
                span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"Called by: ")));
                std::vector<std::pair<std::u32string, std::unique_ptr<sngxml::dom::Element>>> calledByVec;
                for (int i = 0; i < n; ++i)
                {
                    sngxml::dom::Node* calledByNode = (*calledByNodeSet)[i];
                    if (calledByNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
                    {
                        sngxml::dom::Element* calledByIdElement = static_cast<sngxml::dom::Element*>(calledByNode);
                        std::u32string calledById = calledByIdElement->GetAttribute(U"functionId");
                        if (!calledById.empty())
                        {
                            sngxml::dom::Element* calledByElement = contentXml->GetElementById(calledById);
                            sngxml::dom::ParentNode* calledByParent = calledByElement->Parent();
                            if (calledByParent->GetNodeType() == sngxml::dom::NodeType::elementNode)
                            {
                                sngxml::dom::Element* calledByParentElement = static_cast<sngxml::dom::Element*>(calledByParent);
                                if (calledByParentElement->Name() == U"functions")
                                {
                                    sngxml::dom::ParentNode* functionsParent = calledByParentElement->Parent();
                                    if (functionsParent->GetNodeType() == sngxml::dom::NodeType::elementNode)
                                    {
                                        sngxml::dom::Element* parentElement = static_cast<sngxml::dom::Element*>(functionsParent);
                                        if (parentElement->Name() == U"class" || parentElement->Name() == U"namespace")
                                        {
                                            std::u32string parentId = parentElement->GetAttribute(U"id");
                                            if (!parentId.empty())
                                            {
                                                std::u32string proj = GetProject(parentElement);
                                                if (!proj.empty())
                                                {
                                                    std::u32string parentLink = ToUtf32(contentFilePathResolver->ResolveContentFilePath(projectName, proj, ".", parentId));
                                                    std::u32string calledByLink = parentLink + U"#" + calledById;
                                                    std::u32string calledByFunctionName = MakeFunctionName(calledByElement, true);
                                                    std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"a"));
                                                    linkElement->SetAttribute(U"href", calledByLink);
                                                    linkElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(calledByFunctionName)));
                                                    calledByVec.push_back(std::make_pair(calledByFunctionName, std::move(linkElement)));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                std::sort(calledByVec.begin(), calledByVec.end(), ByFunctionName());
                int n = calledByVec.size();
                for (int i = 0; i < n; ++i)
                {
                    if (i > 0)
                    {
                        span->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U", ")));
                    }
                    std::pair<std::u32string, std::unique_ptr<sngxml::dom::Element>>& p = calledByVec[i];
                    std::unique_ptr<sngxml::dom::Element> linkElement = std::move(p.second);
                    span->AppendChild(std::unique_ptr<sngxml::dom::Node>(linkElement.release()));
                }
                if (n > 0)
                {
                    pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"br")));
                    pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span.release()));
                    pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"br")));
                }
                else
                {
                    hasCalledBy = false;
                }
            }
        }
        if (!definitionFileId.empty() || !declarationFileId.empty() || hasOverrides || hasOverriddenFunctions || hasCalls || hasCalledBy)
        {
            pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"br")));
        }
        pageElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"hr")));
    }
}

void GenerateContent(const std::u32string& projectName, sngxml::dom::Document* contentXml, const std::string& contentDir, const std::string& styleDirName, const std::string& styleFileName,
    std::unordered_map<std::u32string, std::unique_ptr<sngxml::dom::Element>>& inlineCodeMap, const std::string& contentXmlFilePath, bool verbose, bool rebuild, bool& upToDate,
    HtmlContentFilePathResolver* contentFilePathResolver, const std::u32string& topLink, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml)
{
    upToDate = true;
    std::unique_ptr<sngxml::xpath::XPathObject> namespaces = sngxml::xpath::Evaluate(U"//namespace", contentXml);
    if (namespaces->Type() == sngxml::xpath::XPathObjectType::nodeSet)
    {
        sngxml::xpath::XPathNodeSet* namespaceNodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(namespaces.get());
        std::u32string parentLink = U"../../" + projectName + U".html";
        std::u32string prevLink;
        std::u32string nextLink;
        int n = namespaceNodeSet->Length();
        for (int i = 0; i < n; ++i)
        {
            nextLink.clear();
            sngxml::dom::Node* nsNode = (*namespaceNodeSet)[i];
            if (nsNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
            {
                sngxml::dom::Element* nsElement = static_cast<sngxml::dom::Element*>(nsNode);
                if (i < n - 1)
                {
                    sngxml::dom::Node* nextNsNode = (*namespaceNodeSet)[i + 1];
                    if (nextNsNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
                    {
                        sngxml::dom::Element* nextNsElement = static_cast<sngxml::dom::Element*>(nextNsNode);
                        std::u32string nextNsId = nextNsElement->GetAttribute(U"id");
                        std::string nextNsFileName = ToUtf8(nextNsId) + ".html";
                        nextLink = ToUtf32(nextNsFileName);
                    }
                }
                std::vector<sngxml::dom::Element*> functionElements;
                std::u32string nsName = nsElement->GetAttribute(U"name");
                std::u32string nsId = nsElement->GetAttribute(U"id");
                std::string nsFileName = ToUtf8(nsId) + ".html";
                std::string nsFilePath = Path::Combine(contentDir, nsFileName);
                if (!rebuild)
                {
                    if (boost::filesystem::exists(nsFilePath) && boost::filesystem::exists(contentXmlFilePath) && boost::filesystem::last_write_time(contentXmlFilePath) < boost::filesystem::last_write_time(nsFilePath))
                    {
                        continue;
                    }
                }
                std::ofstream nsFile(nsFilePath);
                CodeFormatter formatter(nsFile);
                sngxml::dom::Document nsDocument;
                std::unique_ptr<sngxml::dom::Element> htmlElement(new sngxml::dom::Element(U"html"));
                std::unique_ptr<sngxml::dom::Element> headElement(new sngxml::dom::Element(U"head"));
                std::unique_ptr<sngxml::dom::Element> metaElement(new sngxml::dom::Element(U"meta"));
                metaElement->SetAttribute(U"charset", U"utf-8");
                headElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(metaElement.release()));
                std::unique_ptr<sngxml::dom::Element> titleElement(new sngxml::dom::Element(U"title"));
                std::u32string title;
                if (nsName.empty())
                {
                    title = U"Global Namespace";
                }
                else
                {
                    title = nsName + U" Namespace";
                }
                titleElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(title)));
                headElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(titleElement.release()));
                std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"link"));
                linkElement->SetAttribute(U"rel", U"stylesheet");
                linkElement->SetAttribute(U"type", U"text/css");
                std::u32string relativeStyleFilePath = ToUtf32(Path::Combine(Path::Combine("..", styleDirName), styleFileName));
                linkElement->SetAttribute(U"href", relativeStyleFilePath);
                headElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(linkElement.release()));
                htmlElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(headElement.release()));
                std::unique_ptr<sngxml::dom::Element> bodyElement(new sngxml::dom::Element(U"body"));
                GenerateNavigation(bodyElement.get(), Navigation::header, topLink, parentLink, prevLink, nextLink);
                std::unique_ptr<sngxml::dom::Element> h1Element(new sngxml::dom::Element(U"h1"));
                h1Element->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(title)));
                bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(h1Element.release()));
                GenerateNamespaceSection(projectName, nsElement, bodyElement.get(), contentXml, std::u32string(), contentFilePathResolver, documentationXmlFileName, documentationXml);
                GenerateClassSection(projectName, bodyElement.get(), nsElement, contentXml, contentDir, styleDirName, styleFileName, inlineCodeMap, contentXmlFilePath, verbose, rebuild,
                    contentFilePathResolver, topLink, documentationXmlFileName, documentationXml);
                GenerateFunctionSection(projectName, U"Functions", bodyElement.get(), nsElement, contentDir, styleDirName, styleFileName, contentXml, functionElements,
                    contentFilePathResolver, documentationXmlFileName, documentationXml);
                GenerateEnumSection(projectName, bodyElement.get(), nsElement, contentXml, contentDir, styleDirName, styleFileName, contentXmlFilePath, verbose, rebuild, topLink,
                    contentFilePathResolver, documentationXmlFileName, documentationXml);
                GenerateTypedefSection(projectName, bodyElement.get(), nsElement, contentXml, contentDir, styleDirName, styleFileName, contentFilePathResolver, topLink,
                    documentationXmlFileName, documentationXml);
                GenerateVariableSection(projectName, U"Variables", bodyElement.get(), nsElement, contentXml, contentDir, styleDirName, styleFileName, contentFilePathResolver, topLink,
                    documentationXmlFileName, documentationXml);
                bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"hr")));
                GenerateFunctionDetailSection(projectName, U"Function Details", U"Function", bodyElement.get(), nsElement, functionElements, contentXml, inlineCodeMap, contentFilePathResolver,
                    documentationXmlFileName, documentationXml);
                GenerateNavigation(bodyElement.get(), Navigation::footer, topLink, parentLink, prevLink, nextLink);
                htmlElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(bodyElement.release()));
                nsDocument.AppendChild(std::unique_ptr<sngxml::dom::Node>(htmlElement.release()));
                nsDocument.Write(formatter);
                upToDate = false;
                if (verbose)
                {
                    std::cout << ToUtf8(projectName) << "==> " << nsFilePath << std::endl;
                }
                prevLink = ToUtf32(nsFileName);
            }
        }
    }
}

void GenerateModuleHtml(const std::u32string& projectName, const std::u32string& parentProjectName, const std::u32string& prevProject, const std::u32string& nextProject,
    const std::vector<std::u32string>& childProjects, const std::vector<std::u32string>& childProjectNames,
    sngxml::dom::Document* contentXml, const std::string& contentDir, const std::string& styleDirName,
    const std::string& styleFileName, const std::vector<sngcpp::ast::SourceFileNode*>& sourceFiles, const std::string& contentXmlFilePath, bool verbose, bool rebuild, bool& upToDate,
    HtmlContentFilePathResolver* contentFilePathResolver, const std::u32string& topLink, const std::string& documentationXmlFileName, sngxml::dom::Document* documentationXml)
{
    upToDate = true;
    std::string moduleFilePath = GetFullPath(Path::Combine(Path::Combine(contentDir, "../.."), ToUtf8(projectName) + ".html"));
    if (rebuild || !childProjects.empty())
    {
        upToDate = false;
    }
    else
    {
        if (boost::filesystem::exists(moduleFilePath))
        {
            if (boost::filesystem::exists(contentXmlFilePath) && boost::filesystem::last_write_time(contentXmlFilePath) < boost::filesystem::last_write_time(moduleFilePath))
            {
                return;
            }
        }
        else
        {
            upToDate = false;
        }
    }
    std::u32string parentLink;
    if (!parentProjectName.empty())
    {
        parentLink = U"../" + parentProjectName + U".html";
    }
    std::u32string prevLink = prevProject;
    std::u32string nextLink = nextProject;
    std::ofstream moduleFile(moduleFilePath);
    CodeFormatter formatter(moduleFile);
    sngxml::dom::Document moduleDocument;
    std::unique_ptr<sngxml::dom::Element> htmlElement(new sngxml::dom::Element(U"html"));
    std::unique_ptr<sngxml::dom::Element> headElement(new sngxml::dom::Element(U"head"));
    std::unique_ptr<sngxml::dom::Element> metaElement(new sngxml::dom::Element(U"meta"));
    metaElement->SetAttribute(U"charset", U"utf-8");
    headElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(metaElement.release()));
    std::unique_ptr<sngxml::dom::Element> titleElement(new sngxml::dom::Element(U"title"));
    std::u32string title = projectName + U" Module";
    titleElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(title)));
    headElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(titleElement.release()));
    std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"link"));
    linkElement->SetAttribute(U"rel", U"stylesheet");
    linkElement->SetAttribute(U"type", U"text/css");
    std::u32string relativeStyleFilePath = ToUtf32(Path::Combine(Path::Combine("html", styleDirName), styleFileName));
    linkElement->SetAttribute(U"href", relativeStyleFilePath);
    headElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(linkElement.release()));
    htmlElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(headElement.release()));
    std::unique_ptr<sngxml::dom::Element> bodyElement(new sngxml::dom::Element(U"body"));
    std::unique_ptr<sngxml::dom::Element> h1Element(new sngxml::dom::Element(U"h1"));
    std::u32string documentTitle = projectName;
    documentTitle.append(U" Module");
    h1Element->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(documentTitle)));
    bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(h1Element.release()));
    GenerateNavigation(bodyElement.get(), Navigation::header, topLink, parentLink, prevLink, nextLink);
    GenerateDocumentation(projectName, documentationXmlFileName, documentationXml, bodyElement.get(), projectName, contentXml, contentFilePathResolver,
        DocFlags::full | DocFlags::paragraph | DocFlags::moduleDoc);
    int n = childProjects.size();
    if (n > 0)
    {
        std::unique_ptr<sngxml::dom::Element> modulesElement(new sngxml::dom::Element(U"h2"));
        modulesElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"Modules")));
        bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(modulesElement.release()));
        std::unique_ptr<sngxml::dom::Element> moduleTableElement(new sngxml::dom::Element(U"table"));
        std::unique_ptr<sngxml::dom::Element> headerRowElement(new sngxml::dom::Element(U"tr"));
        std::unique_ptr<sngxml::dom::Element> nameElement(new sngxml::dom::Element(U"th"));
        nameElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"Module")));
        headerRowElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(nameElement.release()));
        if (n == childProjectNames.size())
        {
            for (int i = 0; i < n; ++i)
            {
                const std::u32string& childProjectLink = childProjects[i];
                const std::u32string& childProjectName = childProjectNames[i];
                std::unique_ptr<sngxml::dom::Element> moduleRowElement(new sngxml::dom::Element(U"tr"));
                std::unique_ptr<sngxml::dom::Element> nameElement(new sngxml::dom::Element(U"td"));
                std::unique_ptr<sngxml::dom::Element> moduleLinkElement(new sngxml::dom::Element(U"a"));
                moduleLinkElement->SetAttribute(U"href", childProjectLink);
                moduleLinkElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(childProjectName)));
                nameElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(moduleLinkElement.release()));
                moduleRowElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(nameElement.release()));
                if (documentationXml && documentationXml->GetElementById(childProjectName) != nullptr)
                {
                    std::unique_ptr<sngxml::dom::Element> descriptionElement(new sngxml::dom::Element(U"td"));
                    GenerateDocumentation(projectName, documentationXmlFileName, documentationXml, descriptionElement.get(), childProjectName, contentXml, contentFilePathResolver, DocFlags::none);
                    moduleRowElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(descriptionElement.release()));
                }
                moduleTableElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(moduleRowElement.release()));
            }
        }
        bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(moduleTableElement.release()));
    }
    if (contentXml)
    {
        GenerateModuleNamespaceSection(projectName, bodyElement.get(), contentXml, projectName, contentFilePathResolver, documentationXmlFileName, documentationXml);
        GenerateModuleFileSection(sourceFiles, bodyElement.get(), projectName);
    }
    bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"br")));
    bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"hr")));
    GenerateNavigation(bodyElement.get(), Navigation::footer, topLink, parentLink, prevLink, nextLink);
    htmlElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(bodyElement.release()));
    moduleDocument.AppendChild(std::unique_ptr<sngxml::dom::Node>(htmlElement.release()));
    moduleDocument.Write(formatter);
    if (verbose)
    {
        std::cout << ToUtf8(projectName) << "==> " << moduleFilePath << std::endl;
    }
}

int Log10(int n)
{
    int log10 = 1;
    int m = n / 10;
    while (m > 0)
    {
        ++log10;
        m = m / 10;
    }
    return log10;
}

std::vector<std::u32string> GetLines(const std::u32string& text)
{
    std::vector<std::u32string> lines;
    std::u32string line;
    int state = 0;
    for (char32_t c : text)
    {
        switch (state)
        {
            case 0:
            {
                if (c == '\n')
                {
                    lines.push_back(std::move(line));
                    line.clear();
                    state = 1;
                }
                else if (c != '\r')
                {
                    line.append(1, c);
                }
                break;
            }
            case 1:
            {
                if (c == '\n')
                {
                    lines.push_back(std::move(line));
                    line.clear();
                }
                else if (c != '\r')
                {
                    line.append(1, c);
                    state = 0;
                }
                break;
            }
        }
    }
    if (state == 0)
    {
        lines.push_back(std::move(line));
    }
    return lines;
}

void GenerateHtmlCodeFiles(const std::u32string& projectName, const std::vector<sngcpp::ast::SourceFileNode*>& sourceFiles, const std::string& styleDirName, const std::string& styleFileName,
    sngcpp::symbols::SymbolTable& symbolTable, int inlineCodeLimit, std::unordered_map<std::u32string, std::unique_ptr<sngxml::dom::Element>>& inlineCodeMap, bool verbose, bool rebuild,
    bool& upToDate,
    HtmlContentFilePathResolver* contentFilePathResolver)
{
    upToDate = true;
    for (sngcpp::ast::SourceFileNode* sourceFile : sourceFiles)
    {
        if (!rebuild)
        {
            if (boost::filesystem::exists(sourceFile->HtmlSourceFilePath()))
            {
                if (boost::filesystem::last_write_time(sourceFile->SourceFilePath()) < boost::filesystem::last_write_time(sourceFile->HtmlSourceFilePath()))
                {
                    continue;
                }
            }
        }
        std::vector<std::u32string> inputLines = GetLines(sourceFile->Text());
        int n = inputLines.size();
        int numDigits = Log10(n);
        if (Path::GetExtension(sourceFile->SourceFilePath()) == ".lexer")
        {
            HtmlLexerFileSourceGenerator generator(projectName, inputLines, numDigits, styleDirName, styleFileName);
            sourceFile->Accept(generator);
        }
        else if (Path::GetExtension(sourceFile->SourceFilePath()) == ".parser")
        {
            HtmlParserFileSourceGenerator generator(projectName, inputLines, numDigits, styleDirName, styleFileName);
            sourceFile->Accept(generator);
        }
        else
        {
            HtmlSourceCodeGenerator generator(projectName, inputLines, numDigits, styleDirName, styleFileName, symbolTable, inlineCodeLimit, inlineCodeMap, contentFilePathResolver);
            sourceFile->Accept(generator);
            generator.WriteDocument();
        }
        upToDate = false;
        if (verbose)
        {
            std::cout << ToUtf8(projectName) << "==> " << sourceFile->HtmlSourceFilePath() << std::endl;
        }
    }
}

} } // namespace gendoc::html
