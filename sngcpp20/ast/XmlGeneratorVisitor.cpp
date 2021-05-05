// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/XmlGeneratorVisitor.hpp>
#include <sngcpp20/ast/Node.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp::ast {

using namespace soulng::unicode;

void XmlGeneratorVisitor::BeginVisit(Node& node)
{
    stack.push(std::move(element));
    element.reset(new sngxml::dom::Element(ToUtf32(NodeKindStr(node.Kind()))));
    AddAttribute("type", NodeTypeStr(node.Type()));
    AddAttribute("pos", ToString(node.GetSourcePos()));
    int n = node.Count();
    if (n != 0)
    {
        AddAttribute("count", std::to_string(n));
    }
}

void XmlGeneratorVisitor::EndVisit(Node& node)
{
    std::unique_ptr<sngxml::dom::Element> parent = std::move(stack.top());
    stack.pop();
    if (parent)
    {
        parent->AppendChild(std::move(element));
        element.reset(parent.release());
    }
}

void XmlGeneratorVisitor::AddAttribute(const std::string& name, const std::string& value)
{
    element->SetAttribute(ToUtf32(name), ToUtf32(value));
}

} // namespace sngcpp::ast
