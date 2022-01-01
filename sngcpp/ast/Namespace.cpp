// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Namespace.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <sngcpp/ast/Writer.hpp>
#include <sngcpp/ast/Reader.hpp>

namespace sngcpp { namespace ast {

NamespaceNode::NamespaceNode() : UnaryNode(NodeType::namespaceNode)
{
}

NamespaceNode::NamespaceNode(const Span& span_) : UnaryNode(NodeType::namespaceNode, span_), namespaceName()
{
}

NamespaceNode::NamespaceNode(const Span& span_, const std::u32string& namespaceName_) : UnaryNode(NodeType::namespaceNode, span_), namespaceName(namespaceName_)
{
}

void NamespaceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void NamespaceNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.GetBinaryWriter().Write(namespaceName);
}

void NamespaceNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    namespaceName = reader.GetBinaryReader().ReadUtf32String();
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
