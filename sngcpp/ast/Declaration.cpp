// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Declaration.hpp>
#include <sngcpp/ast/Visitor.hpp>

namespace sngcpp { namespace ast {

SimpleDeclarationNode::SimpleDeclarationNode(const Span& span_, Specifier specifiers_, Node* typeExpr_, Node* declarator_) :
    Node(span_), specifiers(specifiers_), typeExpr(typeExpr_), declarator(declarator_)
{
}

void SimpleDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

AliasDeclarationNode::AliasDeclarationNode(const Span& span_, const std::u32string& id_, Node* typeExpr_) : Node(span_), id(id_), typeExpr(typeExpr_)
{
}

void AliasDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

UsingDirectiveNode::UsingDirectiveNode(const Span& span_, Node* namespaceName_) : Node(span_), namespaceName(namespaceName_)
{
}

void UsingDirectiveNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

UsingDeclarationNode::UsingDeclarationNode(const Span& span_, Node* qualifiedId_) : Node(span_), qualifiedId(qualifiedId_)
{
}

void UsingDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

TypedefNode::TypedefNode(const Span& span_, Node* typeExpr_, Node* declarator_) : Node(span_), typeExpr(typeExpr_), declarator(declarator_)
{
}

void TypedefNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

DeclarationSequenceNode::DeclarationSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(span_, left_, right_)
{
}

void DeclarationSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

LinkageSpecificationNode::LinkageSpecificationNode(const Span& span_, StringLiteralNode* language_) : Node(span_), language(language_)
{
}

void LinkageSpecificationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
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
