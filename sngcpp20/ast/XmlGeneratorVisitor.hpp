// =================================
// Copyright (c) 2022 Seppo Laakko
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
    std::unique_ptr<sngxml::dom::Element> GetElement() { return std::move(element); }
    void BeginVisit(Node& node) override;
    void EndVisit(Node& node) override;
    void VisitIdentfier(const std::u32string& id, const SourcePos& sourcePos) override;
    void VisitKeyword(const std::string& keyword, const SourcePos& sourcePos) override;
    void VisitOperator(const std::string& symbol, const SourcePos& sourcePos) override;
    void VisitToken(const std::u32string& tokenStr, const SourcePos& sourcePos) override;
    void VisitLiteral(const std::u32string& rep, const SourcePos& sourcePos) override;
    void VisitHeaderName(const std::u32string& rep, const SourcePos& sourcePos) override;
    void AddAttribute(const std::string& name, const std::string& value);
    void AddElement(sngxml::dom::Element* child);
private:
    std::unique_ptr<sngxml::dom::Element> element;
    std::stack<std::unique_ptr<sngxml::dom::Element>> stack;
};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_XML_GENERATOR_VISITOR_INCLUDED
