// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Declarator.hpp>
#include <sngcpp/ast/Expression.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <sngcpp/ast/Writer.hpp>
#include <sngcpp/ast/Reader.hpp>

namespace sngcpp { namespace ast {

IdDeclaratorNode::IdDeclaratorNode() : Node(NodeType::idDeclaratorNode)
{
}

IdDeclaratorNode::IdDeclaratorNode(const Span& span_, Node* idNode_) : Node(NodeType::idDeclaratorNode, span_), idNode(idNode_)
{
}

void IdDeclaratorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void IdDeclaratorNode::Write(Writer& writer)
{
    Node::Write(writer);
    idNode->Write(writer);
}

void IdDeclaratorNode::Read(Reader& reader)
{
    Node::Read(reader);
    idNode.reset(reader.ReadNode());
}

ArrayDeclaratorNode::ArrayDeclaratorNode() : Node(NodeType::arrayDeclaratorNode)
{
}

ArrayDeclaratorNode::ArrayDeclaratorNode(const Span& span_, Node* declarator_, Node* size_) : Node(NodeType::arrayDeclaratorNode, span_), declarator(declarator_), size(size_)
{
}

void ArrayDeclaratorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ArrayDeclaratorNode::Write(Writer& writer)
{
    Node::Write(writer);
    declarator->Write(writer);
    writer.GetBinaryWriter().Write(size != nullptr);
    if (size)
    {
        size->Write(writer);
    }
}

void ArrayDeclaratorNode::Read(Reader& reader)
{
    Node::Read(reader);
    declarator.reset(reader.ReadNode());
    bool hasSize = reader.GetBinaryReader().ReadBool();
    if (hasSize)
    {
        size.reset(reader.ReadNode());
    }
}

FunctionDeclaratorNode::FunctionDeclaratorNode() : Node(NodeType::functionDeclaratorNode)
{
}

FunctionDeclaratorNode::FunctionDeclaratorNode(const Span& span_, Node* declarator_, Node* parameters_, Specifier cvSpecifiers_) :
    Node(NodeType::functionDeclaratorNode, span_), declarator(declarator_), parameters(parameters_), cvSpecifiers(cvSpecifiers_)
{
}

void FunctionDeclaratorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void FunctionDeclaratorNode::Write(Writer& writer)
{
    Node::Write(writer);
    declarator->Write(writer);
    writer.GetBinaryWriter().Write(parameters != nullptr);
    if (parameters)
    {
        parameters->Write(writer);
    }
    writer.Write(cvSpecifiers);
}

void FunctionDeclaratorNode::Read(Reader& reader)
{
    Node::Read(reader);
    declarator.reset(reader.ReadNode());
    bool hasParameters = reader.GetBinaryReader().ReadBool();
    if (hasParameters)
    {
        parameters.reset(reader.ReadNode());
    }
    cvSpecifiers = reader.ReadSpecifiers();
}

FunctionPtrIdNode::FunctionPtrIdNode() : Node(NodeType::functionPtrIdNode)
{
}

FunctionPtrIdNode::FunctionPtrIdNode(const Span& span_, const std::u32string& id_) : Node(NodeType::functionPtrIdNode, span_), id(id_)
{
}

void FunctionPtrIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void FunctionPtrIdNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.GetBinaryWriter().Write(id);
}

void FunctionPtrIdNode::Read(Reader& reader)
{
    Node::Read(reader);
    id = reader.GetBinaryReader().ReadUtf32String();
}

MemberFunctionPtrIdNode::MemberFunctionPtrIdNode() : Node(NodeType::memberFunctionPtrIdNode)
{
}

MemberFunctionPtrIdNode::MemberFunctionPtrIdNode(const Span& span_, Node* classNameNode_, const std::u32string& id_) :
    Node(NodeType::memberFunctionPtrIdNode, span_), classNameNode(classNameNode_), id(id_)
{
}

void MemberFunctionPtrIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void MemberFunctionPtrIdNode::Write(Writer& writer)
{
    Node::Write(writer);
    classNameNode->Write(writer);
    writer.GetBinaryWriter().Write(id);
}

void MemberFunctionPtrIdNode::Read(Reader& reader)
{
    Node::Read(reader);
    classNameNode.reset(reader.ReadNode());
    id = reader.GetBinaryReader().ReadUtf32String();
}

InitDeclaratorNode::InitDeclaratorNode() : Node(NodeType::initDeclaratorNode)
{
}

InitDeclaratorNode::InitDeclaratorNode(const Span& span_, Node* declarator_, Node* initializer_) : Node(NodeType::initDeclaratorNode, span_), declarator(declarator_), initializer(initializer_)
{
}

void InitDeclaratorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void InitDeclaratorNode::Write(Writer& writer)
{
    Node::Write(writer);
    declarator->Write(writer);
    writer.GetBinaryWriter().Write(initializer != nullptr);
    if (initializer)
    {
        initializer->Write(writer);
    }
}

void InitDeclaratorNode::Read(Reader& reader)
{
    Node::Read(reader);
    declarator.reset(reader.ReadNode());
    bool hasInitializer = reader.GetBinaryReader().ReadBool();
    if (hasInitializer)
    {
        initializer.reset(reader.ReadNode());
    }
}

AssignmentInitializerNode::AssignmentInitializerNode() : UnaryNode(NodeType::assignmentInitializerNode)
{
}

AssignmentInitializerNode::AssignmentInitializerNode(const Span& span_, Node* initializer_) : UnaryNode(NodeType::assignmentInitializerNode, span_, initializer_)
{
}

void AssignmentInitializerNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ExpressionListInitializerNode::ExpressionListInitializerNode() : UnaryNode(NodeType::expressionListInitializerNode)
{
}

ExpressionListInitializerNode::ExpressionListInitializerNode(const Span& span_, Node* initializer_) : UnaryNode(NodeType::expressionListInitializerNode, span_, initializer_)
{
}

void ExpressionListInitializerNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ExpressionInitializerNode::ExpressionInitializerNode() : UnaryNode(NodeType::expressionInitializerNode)
{
}

ExpressionInitializerNode::ExpressionInitializerNode(const Span& span_, Node* expr_) : UnaryNode(NodeType::expressionInitializerNode, span_, expr_)
{
}

void ExpressionInitializerNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

BracedInitializerListNode::BracedInitializerListNode() : UnaryNode(NodeType::bracedInitializerListNode)
{
}

BracedInitializerListNode::BracedInitializerListNode(const Span& span_) : UnaryNode(NodeType::bracedInitializerListNode, span_)
{
}

void BracedInitializerListNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void BracedInitializerListNode::AddInitializer(const Span& span, Node* initializer)
{
    if (Child())
    {
        SetChild(new ExpressionSequenceNode(span, ReleaseChild(), initializer));
    }
    else
    {
        SetChild(initializer);
    }
}

void BracedInitializerListNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(endBraceSpan);
}

void BracedInitializerListNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    reader.Read(endBraceSpan);
}

} } // namespace sngcpp::ast
