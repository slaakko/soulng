// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Literal.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Writer.hpp>
#include <sngcpp20/ast/Reader.hpp>

namespace sngcpp::ast {

LiteralNode::LiteralNode(NodeKind kind_, const SourcePos& sourcePos_) : Node(kind_, sourcePos_)
{
}

LiteralNode::LiteralNode(NodeKind kind_, const SourcePos& sourcePos_, const std::u32string& rep_) : Node(kind_, sourcePos_), rep(rep_)
{
}

void LiteralNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.Write(rep);
}

void LiteralNode::Read(Reader& reader)
{
    Node::Read(reader);
    rep = reader.ReadStr();
}

IntegerLiteralNode::IntegerLiteralNode(const SourcePos& sourcePos_) : LiteralNode(NodeKind::integerLiteralNode, sourcePos_), value(), suffix(), base()
{
}

IntegerLiteralNode::IntegerLiteralNode(const SourcePos& sourcePos_, uint64_t value_, Suffix suffix_, Base base_, const std::u32string& rep_) : 
    LiteralNode(NodeKind::integerLiteralNode, sourcePos_, rep_), value(value_), suffix(suffix_), base(base_)
{
}

void IntegerLiteralNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void IntegerLiteralNode::Write(Writer& writer)
{
    LiteralNode::Write(writer);
    writer.GetBinaryWriter().Write(value);
    writer.GetBinaryWriter().Write(static_cast<uint8_t>(suffix));
    writer.GetBinaryWriter().Write(static_cast<uint8_t>(base));
}

void IntegerLiteralNode::Read(Reader& reader)
{
    LiteralNode::Read(reader);
    value = reader.GetBinaryReader().ReadULong();
    suffix = static_cast<Suffix>(reader.GetBinaryReader().ReadByte());
    base = static_cast<Base>(reader.GetBinaryReader().ReadByte());
}

FloatingLiteralNode::FloatingLiteralNode(const SourcePos& sourcePos_) : LiteralNode(NodeKind::floatingLiteralNode, sourcePos_), value(), suffix(), base()
{
}

FloatingLiteralNode::FloatingLiteralNode(const SourcePos& sourcePos_, double value_, Suffix suffix_, Base base_, const std::u32string& rep_) :
    LiteralNode(NodeKind::floatingLiteralNode, sourcePos_, rep_), value(value_), suffix(suffix_), base(base_)
{
}

void FloatingLiteralNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void FloatingLiteralNode::Write(Writer& writer)
{
    LiteralNode::Write(writer);
    writer.GetBinaryWriter().Write(value);
    writer.GetBinaryWriter().Write(static_cast<uint8_t>(suffix));
    writer.GetBinaryWriter().Write(static_cast<uint8_t>(base));
}

void FloatingLiteralNode::Read(Reader& reader)
{
    LiteralNode::Read(reader);
    value = reader.GetBinaryReader().ReadDouble();
    suffix = static_cast<Suffix>(reader.GetBinaryReader().ReadByte());
    base = static_cast<Base>(reader.GetBinaryReader().ReadByte());
}

CharacterLiteralNode::CharacterLiteralNode(const SourcePos& sourcePos_) : LiteralNode(NodeKind::characterLiteralNode, sourcePos_), value(), encodingPrefix()
{
}

CharacterLiteralNode::CharacterLiteralNode(const SourcePos& sourcePos_, char32_t value_, EncodingPrefix encodingPrefix_, const std::u32string& rep_) : 
    LiteralNode(NodeKind::characterLiteralNode, sourcePos_, rep_), value(value_), encodingPrefix(encodingPrefix_)
{
}

void CharacterLiteralNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void CharacterLiteralNode::Write(Writer& writer)
{
    LiteralNode::Write(writer);
    writer.GetBinaryWriter().Write(value);
    writer.GetBinaryWriter().Write(static_cast<uint8_t>(encodingPrefix));
}

void CharacterLiteralNode::Read(Reader& reader)
{
    LiteralNode::Read(reader);
    value = reader.GetBinaryReader().ReadUChar();
    encodingPrefix = static_cast<EncodingPrefix>(reader.GetBinaryReader().ReadByte());
}

StringLiteralNode::StringLiteralNode(const SourcePos& sourcePos_) : LiteralNode(NodeKind::stringLiteralNode, sourcePos_), value(), encodingPrefix()
{
}

StringLiteralNode::StringLiteralNode(NodeKind kind_, const SourcePos& sourcePos_) : LiteralNode(kind_, sourcePos_), value(), encodingPrefix()
{
}

StringLiteralNode::StringLiteralNode(const SourcePos& sourcePos_, const std::u32string& value_, EncodingPrefix encodingPrefix_, const std::u32string& rep_) : 
    LiteralNode(NodeKind::stringLiteralNode, sourcePos_, rep_), value(value_), encodingPrefix(encodingPrefix_)
{
}

StringLiteralNode::StringLiteralNode(NodeKind kind_, const SourcePos& sourcePos_, const std::u32string& value_, EncodingPrefix encodingPrefix_, const std::u32string& rep_) :
    LiteralNode(kind_, sourcePos_, rep_), value(value_), encodingPrefix(encodingPrefix_)
{
}

void StringLiteralNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void StringLiteralNode::Write(Writer& writer)
{
    LiteralNode::Write(writer);
    writer.Write(value);
    writer.GetBinaryWriter().Write(static_cast<uint8_t>(encodingPrefix));
}

void StringLiteralNode::Read(Reader& reader)
{
    LiteralNode::Read(reader);
    value = reader.ReadStr();
    encodingPrefix = static_cast<EncodingPrefix>(reader.GetBinaryReader().ReadByte());
}

RawStringLiteralNode::RawStringLiteralNode(const SourcePos& sourcePos_) : StringLiteralNode(NodeKind::rawStringLiteralNode, sourcePos_)
{
}

RawStringLiteralNode::RawStringLiteralNode(const SourcePos& sourcePos_, const std::u32string& value_, EncodingPrefix encodingPrefix_, const std::u32string& delimSequence_, const std::u32string& rep_) :
    StringLiteralNode(NodeKind::rawStringLiteralNode, sourcePos_, value_, encodingPrefix_, rep_), delimSequence(delimSequence_)
{
}

void RawStringLiteralNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void RawStringLiteralNode::Write(Writer& writer)
{
    StringLiteralNode::Write(writer);
    writer.Write(delimSequence);
}

void RawStringLiteralNode::Read(Reader& reader)
{
    StringLiteralNode::Read(reader);
    delimSequence = reader.ReadStr();
}

BooleanLiteralNode::BooleanLiteralNode(const SourcePos& sourcePos_) : LiteralNode(NodeKind::booleanLiteralNode, sourcePos_), value()
{
}

BooleanLiteralNode::BooleanLiteralNode(const SourcePos& sourcePos_, bool value_, const std::u32string& rep_) :
    LiteralNode(NodeKind::booleanLiteralNode, sourcePos_, rep_), value(value_)
{
}

void BooleanLiteralNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void BooleanLiteralNode::Write(Writer& writer)
{
    LiteralNode::Write(writer);
    writer.Write(value);
}

void BooleanLiteralNode::Read(Reader& reader)
{
    LiteralNode::Read(reader);
    reader.ReadBool();
}

NullPtrLiteralNode::NullPtrLiteralNode(const SourcePos& sourcePos_) : LiteralNode(NodeKind::nullPtrLiteralNode, sourcePos_)
{
}

NullPtrLiteralNode::NullPtrLiteralNode(const SourcePos& sourcePos_, const std::u32string& rep_) : 
    LiteralNode(NodeKind::nullPtrLiteralNode, sourcePos_, rep_)
{
}

void NullPtrLiteralNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

UserDefinedLiteraNode::UserDefinedLiteraNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::userDefinedLiteralNode, sourcePos_, nullptr, nullptr)
{
}

UserDefinedLiteraNode::UserDefinedLiteraNode(const SourcePos& sourcePos_, Node* literalNode_, Node* udSuffix_) :
    BinaryNode(NodeKind::userDefinedLiteralNode, sourcePos_, literalNode_, udSuffix_)
{
}

void UserDefinedLiteraNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

LiteralOperatorIdNode::LiteralOperatorIdNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::literalOperatorIdNode, sourcePos_, nullptr)
{
}

LiteralOperatorIdNode::LiteralOperatorIdNode(const SourcePos& sourcePos_, Node* id_, const SourcePos& stringLitPos_) :
    UnaryNode(NodeKind::literalOperatorIdNode, sourcePos_, id_), stringLitPos(stringLitPos_)
{
}

void LiteralOperatorIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void LiteralOperatorIdNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(stringLitPos);
}

void LiteralOperatorIdNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    stringLitPos = reader.ReadSourcePos();
}

} // namespace sngcpp::ast
