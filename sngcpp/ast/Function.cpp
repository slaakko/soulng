// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Function.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <sngcpp/ast/Writer.hpp>
#include <sngcpp/ast/Reader.hpp>

namespace sngcpp { namespace ast {

ParameterNode::ParameterNode() : Node(NodeType::parameterNode)
{
}

ParameterNode::ParameterNode(const Span& span_, Node* typeExpr_, Node* declarator_) : Node(NodeType::parameterNode, span_), typeExpr(typeExpr_), declarator(declarator_)
{
}

void ParameterNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ParameterNode::Write(Writer& writer)
{
    Node::Write(writer);
    typeExpr->Write(writer);
    writer.GetBinaryWriter().Write(declarator != nullptr);
    if (declarator)
    {
        declarator->Write(writer);
    }
}

void ParameterNode::Read(Reader& reader)
{
    Node::Read(reader);
    typeExpr.reset(reader.ReadNode());
    bool hasDeclarator = reader.GetBinaryReader().ReadBool();
    if (hasDeclarator)
    {
        declarator.reset(reader.ReadNode());
    }
}

ParameterSequenceNode::ParameterSequenceNode() : BinaryNode(NodeType::parameterSequenceNode)
{
}

ParameterSequenceNode::ParameterSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(NodeType::parameterSequenceNode, span_, left_, right_)
{
}

void ParameterSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

FunctionNode::FunctionNode() : Node(NodeType::functionNode), specifiers()
{
}

FunctionNode::FunctionNode(const Span& span_, Specifier specifiers_, Node* typeExpr_, Node* declarator_, CompoundStatementNode* body_) : 
    Node(NodeType::functionNode, span_), specifiers(specifiers_), typeExpr(typeExpr_), declarator(declarator_), body(body_)
{
}

void FunctionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void FunctionNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.Write(specifiers);
    typeExpr->Write(writer);
    declarator->Write(writer);
    writer.GetBinaryWriter().Write(body != nullptr);
    if (body)
    {
        body->Write(writer);
    }
}

void FunctionNode::Read(Reader& reader)
{
    Node::Read(reader);
    specifiers = reader.ReadSpecifiers();
    typeExpr.reset(reader.ReadNode());
    declarator.reset(reader.ReadNode());
    bool hasBody = reader.GetBinaryReader().ReadBool();
    if (hasBody)
    {
        body.reset(reader.ReadCompoundStatementNode());
    }
}

bool IsFunctionDeclarator(Node* declaratorNode)
{
    return declaratorNode->IsFunctionDeclaratorNode();
}

bool HasPureSpecifier(Specifier specifiers)
{
    return (specifiers & Specifier::pure_) != Specifier::none;
}

} } // namespace sngcpp::ast
