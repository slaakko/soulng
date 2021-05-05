// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_XML_GENERATOR_VISITOR_INCLUDED
#define SNGCPP_AST_XML_GENERATOR_VISITOR_INCLUDED
#include <sngcpp20/ast/Visitor.hpp>
#include <sngxml/dom/Element.hpp>
#include <stack>

namespace sngcpp::ast {

class AST_API XmlGeneratorVisitor : public DefaultVisitor
{
public:
    void BeginVisit(Node& node) override;
    void EndVisit(Node& node) override;
    void AddAttribute(const std::string& name, const std::string& value);
private:
    std::unique_ptr<sngxml::dom::Element> element;
    std::stack<std::unique_ptr<sngxml::dom::Element>> stack;
};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_XML_GENERATOR_VISITOR_INCLUDED
