// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <cpp2cm/cpp2cm/System.hpp>
#include <cpp2cm/cpp2cm/Project.hpp>
#include <sngxml/dom/Document.hpp>
#include <sngxml/dom/Element.hpp>
#include <sngxml/dom/Parser.hpp>
#include <sngxml/xpath/XPathEvaluate.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/Unicode.hpp>

namespace cpp2cm {

using namespace soulng::util;
using namespace soulng::unicode;

void ProcessSystemXml(const std::string& systemXmlFilePath, bool verbose)
{
    std::string systemRootDir = Path::GetDirectoryName(systemXmlFilePath);
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
                        Project project(systemXmlFilePath, projectXmlFilePath, false);
                        project.SetSystem();
                        project.Process(verbose, ProcessType::stage);
                    }
                }
            }
        }
    }
}

} // namespace cpp2cm
