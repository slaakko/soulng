// =================================
// Copyright (c) 2020 Seppo Laakko
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
    projects.insert(projectName);
}

bool NamespaceSymbol::HasProject(const std::u32string& projectName) const
{
    for (const auto& project : projects)
    {
        if (project == projectName) return true;
    }
    return false;
}

std::u32string NamespaceSymbol::FirstProject() const
{
    if (projects.empty()) return std::u32string();
    return *projects.begin();
}

} } // namespace sngcpp::symbols
