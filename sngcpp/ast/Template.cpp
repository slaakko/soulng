// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Template.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <sngcpp/ast/Writer.hpp>
#include <sngcpp/ast/Reader.hpp>

namespace sngcpp { namespace ast {

TypeParameterNode::TypeParameterNode() : Node(NodeType::typeParameterNode)
{
}

TypeParameterNode::TypeParameterNode(const Span& span_, const std::u32string& id_, Node* defaultTemplateParameter_, bool typenameUsed_) :
    Node(NodeType::typeParameterNode, span_), id(id_), defaultTemplateParameter(defaultTemplateParameter_), typenameUsed(typenameUsed_)
{
}

void TypeParameterNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void TypeParameterNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.GetBinaryWriter().Write(id);
    writer.GetBinaryWriter().Write(defaultTemplateParameter != nullptr);
    if (defaultTemplateParameter)
    {
        defaultTemplateParameter->Write(writer);
    }
    writer.GetBinaryWriter().Write(typenameUsed);
}

void TypeParameterNode::Read(Reader& reader)
{
    Node::Read(reader);
    id = reader.GetBinaryReader().ReadUtf32String();
    bool hasDefault = reader.GetBinaryReader().ReadBool();
    if (hasDefault)
    {
        defaultTemplateParameter.reset(reader.ReadNode());
    }
    typenameUsed = reader.GetBinaryReader().ReadBool();
}

TemplateParameterSequenceNode::TemplateParameterSequenceNode() : BinaryNode(NodeType::templateParameterSequenceNode)
{
}

TemplateParameterSequenceNode::TemplateParameterSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(NodeType::templateParameterSequenceNode, span_, left_, right_)
{
}

void TemplateParameterSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

TemplateDeclarationNode::TemplateDeclarationNode() : Node(NodeType::templateDeclarationNode)
{
}

TemplateDeclarationNode::TemplateDeclarationNode(const Span& span_, Node* templateParameters_, Node* declaration_) :
    Node(NodeType::templateDeclarationNode, span_), templateParameters(templateParameters_), declaration(declaration_)
{
}

void TemplateDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void TemplateDeclarationNode::Write(Writer& writer)
{
    Node::Write(writer);
    templateParameters->Write(writer);
    declaration->Write(writer);
}

void TemplateDeclarationNode::Read(Reader& reader)
{
    Node::Read(reader);
    templateParameters.reset(reader.ReadNode());
    declaration.reset(reader.ReadNode());
}

TemplateArgumentSequenceNode::TemplateArgumentSequenceNode() : BinaryNode(NodeType::templateArgumentSequenceNode)
{
}

TemplateArgumentSequenceNode::TemplateArgumentSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(NodeType::templateArgumentSequenceNode, span_, left_, right_)
{
}

void TemplateArgumentSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

TemplateIdNode::TemplateIdNode() : Node(NodeType::templateIdNode), arity(0)
{
}

TemplateIdNode::TemplateIdNode(const Span& span_, IdentifierNode* id_, Node* templateArguments_, int arity_) :
    Node(NodeType::templateIdNode, span_), id(id_), templateArguments(templateArguments_), arity(arity_)
{
}

void TemplateIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void TemplateIdNode::Write(Writer& writer)
{
    Node::Write(writer);
    id->Write(writer);
    bool hasTemplateArguments = templateArguments != nullptr;
    writer.GetBinaryWriter().Write(hasTemplateArguments);
    if (hasTemplateArguments)
    {
        templateArguments->Write(writer);
    }
    writer.GetBinaryWriter().Write(int32_t(arity));
}

void TemplateIdNode::Read(Reader& reader)
{
    Node::Read(reader);
    id.reset(reader.ReadIdentifierNode());
    bool hasTemplateArguments = reader.GetBinaryReader().ReadBool();
    if (hasTemplateArguments)
    {
        templateArguments.reset(reader.ReadNode());
    }
    arity = reader.GetBinaryReader().ReadInt();
}

TemplateArgumentNode::TemplateArgumentNode() : Node(NodeType::templateArgumentNode)
{
}

TemplateArgumentNode::TemplateArgumentNode(const Span& span_, Node* arg_) : Node(NodeType::templateArgumentNode, span_), arg(arg_)
{
}

void TemplateArgumentNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void TemplateArgumentNode::Write(Writer& writer)
{
    Node::Write(writer);
    arg->Write(writer);
}

void TemplateArgumentNode::Read(Reader& reader)
{
    Node::Read(reader);
    arg.reset(reader.ReadNode());
}

ExplicitInstantiationNode::ExplicitInstantiationNode() : UnaryNode(NodeType::explicitInstantiationNode)
{
}

ExplicitInstantiationNode::ExplicitInstantiationNode(const Span& span_, Node* declaration_) : UnaryNode(NodeType::explicitInstantiationNode, span_, declaration_)
{
}

void ExplicitInstantiationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ExplicitSpecializationNode::ExplicitSpecializationNode() : UnaryNode(NodeType::explicitSpecializationNode)
{
}

ExplicitSpecializationNode::ExplicitSpecializationNode(const Span& span_, Node* declaration_) : UnaryNode(NodeType::explicitSpecializationNode, span_, declaration_)
{
}

void ExplicitSpecializationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} } // namespace sngcpp::ast
