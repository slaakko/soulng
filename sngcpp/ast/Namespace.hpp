// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_NAMESPACE_INCLUDED
#define SNGCPP_AST_NAMESPACE_INCLUDED
#include <sngcpp/ast/Declaration.hpp>

namespace sngcpp { namespace ast {

class SNGCPP_AST_API NamespaceNode : public UnaryNode
{
public:
    NamespaceNode();
    NamespaceNode(const Span& span_);
    NamespaceNode(const Span& span_, const std::u32string& namespaceName_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const std::u32string& NamespaceName() const { return namespaceName; }
    void AddMember(const Span& span, Node* member);
private:
    std::u32string namespaceName;
};

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_NAMESPACE_INCLUDED
