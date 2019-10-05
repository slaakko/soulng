// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Template.hpp>
#include <sngcpp/ast/Visitor.hpp>

namespace sngcpp { namespace ast {

TypeParameterNode::TypeParameterNode(const Span& span_, const std::u32string& id_, Node* defaultTemplateParameter_, bool typenameUsed_) :
    Node(span_), id(id_), defaultTemplateParameter(defaultTemplateParameter_), typenameUsed(typenameUsed_)
{
}

void TypeParameterNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

TemplateParameterSequenceNode::TemplateParameterSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(span_, left_, right_)
{
}

void TemplateParameterSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

TemplateDeclarationNode::TemplateDeclarationNode(const Span& span_, Node* templateParameters_, Node* declaration_) :
    Node(span_), templateParameters(templateParameters_), declaration(declaration_)
{
}

void TemplateDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

TemplateArgumentSequenceNode::TemplateArgumentSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(span_, left_, right_)
{
}

void TemplateArgumentSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

TemplateIdNode::TemplateIdNode(const Span& span_, IdentifierNode* id_, Node* templateArguments_, int arity_) :
    Node(span_), id(id_), templateArguments(templateArguments_), arity(arity_)
{
}

void TemplateIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

TemplateArgumentNode::TemplateArgumentNode(const Span& span_, Node* arg_) : Node(span_), arg(arg_)
{
}

void TemplateArgumentNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ExplicitInstantiationNode::ExplicitInstantiationNode(const Span& span_, Node* declaration_) : UnaryNode(span_, declaration_)
{
}

void ExplicitInstantiationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ExplicitSpecializationNode::ExplicitSpecializationNode(const Span& span_, Node* declaration_) : UnaryNode(span_, declaration_)
{
}

void ExplicitSpecializationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} } // namespace sngcpp::ast
