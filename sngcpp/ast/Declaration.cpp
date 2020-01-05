// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Declaration.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <sngcpp/ast/Writer.hpp>
#include <sngcpp/ast/Reader.hpp>

namespace sngcpp { namespace ast {

SimpleDeclarationNode::SimpleDeclarationNode() : Node(NodeType::simpleDeclarationNode), specifiers()
{
}

SimpleDeclarationNode::SimpleDeclarationNode(const Span& span_, Specifier specifiers_, Node* typeExpr_, Node* declarator_) :
    Node(NodeType::simpleDeclarationNode, span_), specifiers(specifiers_), typeExpr(typeExpr_), declarator(declarator_)
{
}

void SimpleDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void SimpleDeclarationNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.Write(specifiers);
    typeExpr->Write(writer);
    bool hasDeclarator = declarator != nullptr;
    writer.GetBinaryWriter().Write(hasDeclarator);
    if (hasDeclarator)
    {
        declarator->Write(writer);
    }
}

void SimpleDeclarationNode::Read(Reader& reader)
{
    Node::Read(reader);
    specifiers = reader.ReadSpecifiers();
    typeExpr.reset(reader.ReadNode());
    bool hasDeclarator = reader.GetBinaryReader().ReadBool();
    if (hasDeclarator)
    {
        declarator.reset(reader.ReadNode());
    }
}

AliasDeclarationNode::AliasDeclarationNode() : Node(NodeType::aliasDeclarationNode)
{
}

AliasDeclarationNode::AliasDeclarationNode(const Span& span_, const std::u32string& id_, Node* typeExpr_) : Node(NodeType::aliasDeclarationNode, span_), id(id_), typeExpr(typeExpr_)
{
}

void AliasDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void AliasDeclarationNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.GetBinaryWriter().Write(id);
    typeExpr->Write(writer);
}

void AliasDeclarationNode::Read(Reader& reader)
{
    Node::Read(reader);
    id = reader.GetBinaryReader().ReadUtf32String();
    typeExpr.reset(reader.ReadNode());
}

UsingDirectiveNode::UsingDirectiveNode() : Node(NodeType::usingDirectiveNode)
{
}

UsingDirectiveNode::UsingDirectiveNode(const Span& span_, Node* namespaceName_) : Node(NodeType::usingDirectiveNode, span_), namespaceName(namespaceName_)
{
}

void UsingDirectiveNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void UsingDirectiveNode::Write(Writer& writer)
{
    Node::Write(writer);
    namespaceName->Write(writer);
}

void UsingDirectiveNode::Read(Reader& reader)
{
    Node::Read(reader);
    namespaceName.reset(reader.ReadNode());
}

UsingDeclarationNode::UsingDeclarationNode() : Node(NodeType::usingDeclarationNode)
{
}

UsingDeclarationNode::UsingDeclarationNode(const Span& span_, Node* qualifiedId_) : Node(NodeType::usingDeclarationNode, span_), qualifiedId(qualifiedId_)
{
}

void UsingDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void UsingDeclarationNode::Write(Writer& writer)
{
    Node::Write(writer);
    qualifiedId->Write(writer);
}

void UsingDeclarationNode::Read(Reader& reader)
{
    Node::Read(reader);
    qualifiedId.reset(reader.ReadNode());
}

TypedefNode::TypedefNode() : Node(NodeType::typedefNode)
{
}

TypedefNode::TypedefNode(const Span& span_, Node* typeExpr_, Node* declarator_) : Node(NodeType::typedefNode, span_), typeExpr(typeExpr_), declarator(declarator_)
{
}

void TypedefNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void TypedefNode::Write(Writer& writer)
{
    Node::Write(writer);
    typeExpr->Write(writer);
    declarator->Write(writer);
}

void TypedefNode::Read(Reader& reader)
{
    Node::Read(reader);
    typeExpr.reset(reader.ReadNode());
    declarator.reset(reader.ReadNode());
}

DeclarationSequenceNode::DeclarationSequenceNode() : BinaryNode(NodeType::declarationSequenceNode)
{
}

DeclarationSequenceNode::DeclarationSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(NodeType::declarationSequenceNode, span_, left_, right_)
{
}

void DeclarationSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

LinkageSpecificationNode::LinkageSpecificationNode() : Node(NodeType::linkageSpecificationNode)
{
}

LinkageSpecificationNode::LinkageSpecificationNode(const Span& span_, StringLiteralNode* language_) : Node(NodeType::linkageSpecificationNode, span_), language(language_)
{
}

void LinkageSpecificationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void LinkageSpecificationNode::Write(Writer& writer)
{
    Node::Write(writer);
    language->Write(writer);
    writer.GetBinaryWriter().Write(declarations != nullptr);
    if (declarations)
    {
        declarations->Write(writer);
    }
}

void LinkageSpecificationNode::Read(Reader& reader)
{
    Node::Read(reader);
    language.reset(reader.ReadStringLiteralNode());
    bool hasDeclarations = reader.GetBinaryReader().ReadBool();
    if (hasDeclarations)
    {
        declarations.reset(reader.ReadNode());
    }
}

void LinkageSpecificationNode::AddDeclaration(const Span& span_, Node* declaration)
{
    if (declarations)
    {
        declarations.reset(new DeclarationSequenceNode(span_, declarations.release(), declaration));
    }
    else
    {
        declarations.reset(declaration);
    }
}

} } // namespace sngcpp::ast
