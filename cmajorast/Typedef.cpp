// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <cmajorast/Typedef.hpp>
#include <cmajorast/Identifier.hpp>
#include <cmajorast/Visitor.hpp>
#include <cmajorast/AstWriter.hpp>
#include <cmajorast/AstReader.hpp>

namespace cmajor { namespace ast {

TypedefNode::TypedefNode(const Span& span_) : Node(NodeType::typedefNode, span_), specifiers(Specifiers::none), typeExpr(), id()
{
}

TypedefNode::TypedefNode(const Span& span_, Specifiers specifiers_, Node* typeExpr_, IdentifierNode* id_) : Node(NodeType::typedefNode, span_), specifiers(specifiers_), typeExpr(typeExpr_), id(id_)
{
    typeExpr->SetParent(this);
    id->SetParent(this);
}

Node* TypedefNode::Clone(CloneContext& cloneContext) const
{
    return new TypedefNode(GetSpan(), specifiers, typeExpr->Clone(cloneContext), static_cast<IdentifierNode*>(id->Clone(cloneContext)));
}

void TypedefNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void TypedefNode::Write(AstWriter& writer)
{
    Node::Write(writer);
    writer.Write(specifiers);
    writer.Write(typeExpr.get());
    writer.Write(id.get());
}

void TypedefNode::Read(AstReader& reader)
{
    Node::Read(reader);
    specifiers = reader.ReadSpecifiers();
    typeExpr.reset(reader.ReadNode());
    typeExpr->SetParent(this);
    id.reset(reader.ReadIdentifierNode());
    id->SetParent(this);
}

} } // namespace cmajor::ast
