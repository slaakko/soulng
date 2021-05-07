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

void XmlGeneratorVisitor::VisitIdentfier(const std::u32string& id, const SourcePos& sourcePos)
{
    std::unique_ptr<sngxml::dom::Element> idElement(new sngxml::dom::Element(U"identifier"));
    idElement->SetAttribute(U"value", id);
    idElement->SetAttribute(U"pos", ToUtf32(ToString(sourcePos)));
    AddElement(idElement.release());
}

void XmlGeneratorVisitor::VisitKeyword(const std::string& keyword, const SourcePos& sourcePos)
{
    std::unique_ptr<sngxml::dom::Element> kwElement(new sngxml::dom::Element(U"keyword"));
    kwElement->SetAttribute(U"value", ToUtf32(keyword));
    kwElement->SetAttribute(U"pos", ToUtf32(ToString(sourcePos)));
    AddElement(kwElement.release());
}

void XmlGeneratorVisitor::VisitOperator(const std::string& symbol, const SourcePos& sourcePos)
{
    std::unique_ptr<sngxml::dom::Element> opElement(new sngxml::dom::Element(U"operator"));
    opElement->SetAttribute(U"value", ToUtf32(symbol));
    opElement->SetAttribute(U"pos", ToUtf32(ToString(sourcePos)));
    AddElement(opElement.release());
}

void XmlGeneratorVisitor::VisitToken(const std::u32string& tokenStr, const SourcePos& sourcePos)
{
    std::unique_ptr<sngxml::dom::Element> tokenElement(new sngxml::dom::Element(U"token"));
    tokenElement->SetAttribute(U"value", tokenStr);
    tokenElement->SetAttribute(U"pos", ToUtf32(ToString(sourcePos)));
    AddElement(tokenElement.release());
}

void XmlGeneratorVisitor::VisitLiteral(const std::u32string& rep, const SourcePos& sourcePos)
{
    std::unique_ptr<sngxml::dom::Element> literalElement(new sngxml::dom::Element(U"literal"));
    literalElement->SetAttribute(U"value", rep);
    literalElement->SetAttribute(U"pos", ToUtf32(ToString(sourcePos)));
    AddElement(literalElement.release());
}

void XmlGeneratorVisitor::VisitHeaderName(const std::u32string& rep, const SourcePos& sourcePos)
{
    std::unique_ptr<sngxml::dom::Element> headerElement(new sngxml::dom::Element(U"header"));
    headerElement->SetAttribute(U"value", rep);
    headerElement->SetAttribute(U"pos", ToUtf32(ToString(sourcePos)));
    AddElement(headerElement.release());
}

void XmlGeneratorVisitor::AddAttribute(const std::string& name, const std::string& value)
{
    element->SetAttribute(ToUtf32(name), ToUtf32(value));
}

void XmlGeneratorVisitor::AddElement(sngxml::dom::Element* child)
{
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(child));
}
} // namespace sngcpp::ast
