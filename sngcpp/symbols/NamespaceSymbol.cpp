// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/NamespaceSymbol.hpp>

namespace sngcpp { namespace symbols {

NamespaceSymbol::NamespaceSymbol(const Span& span_, const std::u32string& name_) : ContainerSymbol(span_, name_)
{
}

std::unique_ptr<sngxml::dom::Element> NamespaceSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> namespaceElement(new sngxml::dom::Element(U"namespace"));
    if (!projects.empty())
    {
        std::unique_ptr<sngxml::dom::Element> projectsElement(new sngxml::dom::Element(U"projects"));
        for (const std::u32string& projectName : projects)
        {
            std::unique_ptr<sngxml::dom::Element> projectElement(new sngxml::dom::Element(U"project"));
            projectElement->SetAttribute(U"name", projectName);
            projectsElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(projectElement.release()));
        }
        namespaceElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(projectsElement.release()));
    }
    return namespaceElement;
}

void NamespaceSymbol::AddProject(const std::u32string& projectName)
{
    if (projectName == U"binder")
    {
        int x = 0;
    }
    projects.insert(projectName);
}

} } // namespace sngcpp::symbols
