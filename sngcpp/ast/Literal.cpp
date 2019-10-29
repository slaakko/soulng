// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Literal.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <sngcpp/ast/Writer.hpp>
#include <sngcpp/ast/Reader.hpp>

namespace sngcpp { namespace ast {

std::u32string ToString(Suffix suffix)
{
    std::u32string s;
    if ((suffix & Suffix::u) != Suffix::none)
    {
        s.append(U"u");
    }
    if ((suffix & Suffix::f) != Suffix::none)
    {
        s.append(U"f");
    }
    if ((suffix & Suffix::l) != Suffix::none)
    {
        s.append(U"l");
    }
    if ((suffix & Suffix::ll) != Suffix::none)
    {
        s.append(U"ll");
    }
    return s;
}

LiteralNode::LiteralNode(NodeType nodeType_) : Node(nodeType_)
{
}

LiteralNode::LiteralNode(NodeType nodeType_, const Span& span_, const std::u32string& rep_) : Node(nodeType_, span_), rep(rep_)
{
}

void LiteralNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.GetBinaryWriter().Write(rep);
}

void LiteralNode::Read(Reader& reader)
{
    Node::Read(reader);
    rep = reader.GetBinaryReader().ReadUtf32String();
}

FloatingLiteralNode::FloatingLiteralNode() : LiteralNode(NodeType::floatingLiteralNode)
{
}

FloatingLiteralNode::FloatingLiteralNode(const Span& span_, double value_, Suffix suffix_, const std::u32string& rep_) : LiteralNode(NodeType::floatingLiteralNode, span_, rep_), value(value_), suffix(suffix_)
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
    writer.Write(suffix);
}

void FloatingLiteralNode::Read(Reader& reader)
{
    LiteralNode::Read(reader);
    value = reader.GetBinaryReader().ReadDouble();
    suffix = reader.ReadSuffix();
}

IntegerLiteralNode::IntegerLiteralNode() : LiteralNode(NodeType::integerLiteralNode)
{
}

IntegerLiteralNode::IntegerLiteralNode(const Span& span_, uint64_t value_, Suffix suffix_, Base base_, const std::u32string& rep_) : 
    LiteralNode(NodeType::integerLiteralNode, span_, rep_), value(value_), suffix(suffix_), base(base_)
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
    writer.Write(suffix);
    writer.Write(base);
}

void IntegerLiteralNode::Read(Reader& reader)
{
    LiteralNode::Read(reader);
    value = reader.GetBinaryReader().ReadULong();
    suffix = reader.ReadSuffix();
    base = reader.ReadBase();
}

CharacterLiteralNode::CharacterLiteralNode() : LiteralNode(NodeType::characterLiteralNode)
{
}

CharacterLiteralNode::CharacterLiteralNode(const Span& span_, char32_t prefix_, char32_t chr_, const std::u32string& rep_) : 
    LiteralNode(NodeType::characterLiteralNode, span_, rep_), prefix(prefix_), chr(chr_)
{
}

void CharacterLiteralNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void CharacterLiteralNode::Write(Writer& writer)
{
    LiteralNode::Write(writer);
    writer.GetBinaryWriter().Write(prefix);
    writer.GetBinaryWriter().Write(chr);
}

void CharacterLiteralNode::Read(Reader& reader)
{
    LiteralNode::Read(reader);
    prefix = reader.GetBinaryReader().ReadUChar();
    chr = reader.GetBinaryReader().ReadUChar();
}

StringLiteralNode::StringLiteralNode() : LiteralNode(NodeType::stringLiteralNode)
{
}

StringLiteralNode::StringLiteralNode(const Span& span_, const std::u32string& encodingPrefix_, const std::u32string& chars_, const std::u32string& rep_) :
    LiteralNode(NodeType::stringLiteralNode, span_, rep_), encodingPrefix(encodingPrefix_), chars(chars_)
{
}

void StringLiteralNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void StringLiteralNode::Write(Writer& writer)
{
    LiteralNode::Write(writer);
    writer.GetBinaryWriter().Write(encodingPrefix);
    writer.GetBinaryWriter().Write(chars);
}

void StringLiteralNode::Read(Reader& reader)
{
    LiteralNode::Read(reader);
    encodingPrefix = reader.GetBinaryReader().ReadUtf32String();
    chars = reader.GetBinaryReader().ReadUtf32String();
}

BooleanLiteralNode::BooleanLiteralNode() : LiteralNode(NodeType::booleanLiteralNode)
{
}

BooleanLiteralNode::BooleanLiteralNode(const Span& span_, bool value_, const std::u32string& rep_) : LiteralNode(NodeType::booleanLiteralNode, span_, rep_), value(value_)
{
}

void BooleanLiteralNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void BooleanLiteralNode::Write(Writer& writer)
{
    LiteralNode::Write(writer);
    writer.GetBinaryWriter().Write(value);
}

void BooleanLiteralNode::Read(Reader& reader)
{
    LiteralNode::Read(reader);
    value = reader.GetBinaryReader().ReadBool();
}

NullPtrLiteralNode::NullPtrLiteralNode() : LiteralNode(NodeType::nullPtrLiteralNode)
{
}

NullPtrLiteralNode::NullPtrLiteralNode(const Span& span_, const std::u32string& rep_) : LiteralNode(NodeType::nullPtrLiteralNode, span_, rep_)
{
}

void NullPtrLiteralNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} } // namespace sngcpp::ast
