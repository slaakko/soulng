// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Namespace.hpp>
#include <sngcpp/ast/Visitor.hpp>

namespace sngcpp { namespace ast {

NamespaceNode::NamespaceNode(const Span& span_) : UnaryNode(span_), namespaceName()
{
}

NamespaceNode::NamespaceNode(const Span& span_, const std::u32string& namespaceName_) : UnaryNode(span_), namespaceName(namespaceName_)
{
}

void NamespaceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void NamespaceNode::AddMember(const Span& span, Node* member)
{
    if (Child())
    {
        SetChild(new DeclarationSequenceNode(span, ReleaseChild(), member));
    }
    else
    {
        SetChild(member);
    }
}

} } // namespace sngcpp::ast
