// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Reader.hpp>

namespace sngcpp { namespace ast {

Reader::Reader(soulng::util::BinaryReader& binaryReader_) : binaryReader(binaryReader_)
{
}

void Reader::Read(soulng::lexer::Span& span)
{
    span.fileIndex = binaryReader.ReadInt();
    span.line = binaryReader.ReadInt();
    span.start = binaryReader.ReadInt();
    span.end = binaryReader.ReadInt();
}

SimpleTypeSpecifier Reader::ReadSimpleTypeSpecifier()
{
    return SimpleTypeSpecifier(binaryReader.ReadByte());
}

NodeType Reader::ReadNodeType()
{
    uint8_t x = binaryReader.ReadByte();
    return static_cast<NodeType>(x);
}

Specifier Reader::ReadSpecifiers()
{
    return Specifier(binaryReader.ReadUInt());
}

ClassKey Reader::ReadClassKey()
{
    return ClassKey(binaryReader.ReadByte());
}

EnumKey Reader::ReadEnumKey()
{
    return EnumKey(binaryReader.ReadByte());
}

Operator Reader::ReadOperator()
{
    return Operator(binaryReader.ReadByte());
}

Suffix Reader::ReadSuffix()
{
    return Suffix(binaryReader.ReadByte());
}

Base Reader::ReadBase()
{
    return Base(binaryReader.ReadByte());
}

Node* Reader::ReadNode()
{
    NodeType nodeType = ReadNodeType();
    Node* node = NodeFactory::Instance().CreateNode(nodeType);
    node->Read(*this);
    return node;
}

CompoundStatementNode* Reader::ReadCompoundStatementNode()
{
    Node* node = ReadNode();
    if (node->GetNodeType() == NodeType::compoundStatementNode)
    {
        return static_cast<CompoundStatementNode*>(node);
    }
    else
    {
        throw std::runtime_error("compound statement node expected");
    }
}

StringLiteralNode* Reader::ReadStringLiteralNode()
{
    Node* node = ReadNode();
    if (node->GetNodeType() == NodeType::stringLiteralNode)
    {
        return static_cast<StringLiteralNode*>(node);
    }
    else
    {
        throw std::runtime_error("string literal node expected");
    }
}

NamespaceNode* Reader::ReadNamespaceNode()
{
    Node* node = ReadNode();
    if (node->GetNodeType() == NodeType::namespaceNode)
    {
        return static_cast<NamespaceNode*>(node);
    }
    else
    {
        throw std::runtime_error("namespace node expected");
    }
}

IdentifierNode* Reader::ReadIdentifierNode()
{
    Node* node = ReadNode();
    if (node->GetNodeType() == NodeType::identifierNode)
    {
        return static_cast<IdentifierNode*>(node);
    }
    else
    {
        throw std::runtime_error("identifier node expected");
    }
}

} } // namespace sngcpp::ast
