// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Enumeration.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <sngcpp/ast/Writer.hpp>
#include <sngcpp/ast/Reader.hpp>

namespace sngcpp { namespace ast {

std::u32string ToString(EnumKey enumKey)
{
    switch (enumKey)
    {
        case EnumKey::enumClass_: return U"enum class";
        case EnumKey::enumStruct_: return U"enum struct";
        case EnumKey::enum_: return U"enum";
    }
    return std::u32string();
}

EnumTypeNode::EnumTypeNode() : Node(NodeType::enumTypeNode), enumKey()
{
}

EnumTypeNode::EnumTypeNode(const Span& span_, EnumKey enumKey_, Node* enumName_, Node* enumBase_) : Node(NodeType::enumTypeNode, span_), enumKey(enumKey_), enumName(enumName_), enumBase(enumBase_)
{
}

void EnumTypeNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void EnumTypeNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.Write(enumKey);
    enumName->Write(writer);
    writer.GetBinaryWriter().Write(enumBase != nullptr);
    if (enumBase)
    {
        enumBase->Write(writer);
    }
    writer.GetBinaryWriter().Write(enumerators != nullptr);
    if (enumerators)
    {
        enumerators->Write(writer);
    }
    writer.Write(openBraceSpan);
    writer.Write(closeBraceSpan);
}

void EnumTypeNode::Read(Reader& reader)
{
    Node::Read(reader);
    enumKey = reader.ReadEnumKey();
    enumName.reset(reader.ReadNode());
    bool hasEnumBase = reader.GetBinaryReader().ReadBool();
    if (hasEnumBase)
    {
        enumBase.reset(reader.ReadNode());
    }
    bool hasEnumerators = reader.GetBinaryReader().ReadBool();
    if (hasEnumerators)
    {
        enumerators.reset(reader.ReadNode());
    }
    reader.Read(openBraceSpan);
    reader.Read(closeBraceSpan);
}

void EnumTypeNode::AddEnumerator(const Span& span_, Node* enumerator_)
{
    if (enumerators)
    {
        enumerators.reset(new EnumeratorSequenceNode(span_, enumerators.release(), enumerator_));
    }
    else
    {
        enumerators.reset(enumerator_);
    }
}

EnumeratorNode::EnumeratorNode() : Node(NodeType::enumeratorNode)
{
}

EnumeratorNode::EnumeratorNode(const Span& span_, const std::u32string& enumerator_, Node* value_, const std::u32string& valueStr_) : 
    Node(NodeType::enumeratorNode, span_), enumerator(enumerator_), value(value_), valueStr(valueStr_)
{
}

void EnumeratorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void EnumeratorNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.GetBinaryWriter().Write(enumerator);
    writer.GetBinaryWriter().Write(value != nullptr);
    if (value)
    {
        value->Write(writer);
    }
    writer.GetBinaryWriter().Write(valueStr);
    writer.Write(assignmentSignSpan);
}

void EnumeratorNode::Read(Reader& reader)
{
    Node::Read(reader);
    enumerator = reader.GetBinaryReader().ReadUtf32String();
    bool hasValue = reader.GetBinaryReader().ReadBool();
    if (hasValue)
    {
        value.reset(reader.ReadNode());
    }
    valueStr = reader.GetBinaryReader().ReadUtf32String();
    reader.Read(assignmentSignSpan);
}

EnumeratorSequenceNode::EnumeratorSequenceNode() : BinaryNode(NodeType::enumeratorSequenceNode)
{
}

EnumeratorSequenceNode::EnumeratorSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(NodeType::enumeratorSequenceNode, span_, left_, right_)
{
}

void EnumeratorSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} } // namespace sngcpp::ast
