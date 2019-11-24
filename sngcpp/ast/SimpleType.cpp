// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/SimpleType.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <sngcpp/ast/Writer.hpp>
#include <sngcpp/ast/Reader.hpp>

namespace sngcpp { namespace ast {

const char32_t* simpleTypeSpecifierStr[uint8_t(SimpleTypeSpecifier::max)]
{
    U"", U"char", U"char16_t", U"char32_t", U"wchar_t", U"bool", U"short", U"int", U"long", U"signed", U"unsigned", U"float", U"double", U"void", U"auto"
};

std::u32string ToString(SimpleTypeSpecifier specifier)
{
    return simpleTypeSpecifierStr[uint8_t(specifier)];
}

SimpleTypeNode::SimpleTypeNode() : Node(NodeType::simpleTypeNode), flags(SimpleTypeSpecifierFlags::none)
{
}

SimpleTypeNode::SimpleTypeNode(const Span& span_, const std::vector<SimpleTypeSpecifier>& specifiers_) :
    Node(NodeType::simpleTypeNode, span_), specifiers(specifiers_), flags(SimpleTypeSpecifierFlags::none)
{
    SimpleTypeSpecifier prev = SimpleTypeSpecifier::none;
    for (auto s : specifiers)
    {
        switch (s)
        {
            case SimpleTypeSpecifier::char_: flags = flags | SimpleTypeSpecifierFlags::char_; break;
            case SimpleTypeSpecifier::char16: flags = flags | SimpleTypeSpecifierFlags::char16; break;
            case SimpleTypeSpecifier::char32: flags = flags | SimpleTypeSpecifierFlags::char32; break;
            case SimpleTypeSpecifier::wchar: flags = flags | SimpleTypeSpecifierFlags::wchar; break;
            case SimpleTypeSpecifier::bool_: flags = flags | SimpleTypeSpecifierFlags::bool_; break;
            case SimpleTypeSpecifier::short_: flags = flags | SimpleTypeSpecifierFlags::short_; break;
            case SimpleTypeSpecifier::int_: flags = flags | SimpleTypeSpecifierFlags::int_; break;
            case SimpleTypeSpecifier::long_:
            {
                if (prev == SimpleTypeSpecifier::long_)
                {
                    flags = flags & ~SimpleTypeSpecifierFlags::long_;
                    flags = flags | SimpleTypeSpecifierFlags::longLong_;
                }
                else
                {
                    flags = flags | SimpleTypeSpecifierFlags::long_;
                }
                break;
            }
            case SimpleTypeSpecifier::signed_: flags = flags | SimpleTypeSpecifierFlags::signed_; break;
            case SimpleTypeSpecifier::unsigned_: flags = flags | SimpleTypeSpecifierFlags::unsigned_; break;
            case SimpleTypeSpecifier::float_: flags = flags | SimpleTypeSpecifierFlags::float_; break;
            case SimpleTypeSpecifier::double_: flags = flags | SimpleTypeSpecifierFlags::double_; break;
            case SimpleTypeSpecifier::void_: flags = flags | SimpleTypeSpecifierFlags::void_; break;
            case SimpleTypeSpecifier::auto_: flags = flags | SimpleTypeSpecifierFlags::auto_; break;
        }
        prev = s;
    }
}

void SimpleTypeNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void SimpleTypeNode::Write(Writer& writer)
{
    Node::Write(writer);
    uint8_t n = specifiers.size();
    writer.GetBinaryWriter().Write(n);
    for (const auto& specifier : specifiers)
    {
        writer.Write(specifier);
    }
    writer.GetBinaryWriter().Write(static_cast<uint16_t>(flags));
}

void SimpleTypeNode::Read(Reader& reader)
{
    Node::Read(reader);
    uint8_t n = reader.GetBinaryReader().ReadByte();
    for (uint8_t i = 0; i < n; ++i)
    {
        specifiers.push_back(reader.ReadSimpleTypeSpecifier());
    }
    flags = static_cast<SimpleTypeSpecifierFlags>(reader.GetBinaryReader().ReadUShort());
}

std::u32string SimpleTypeNode::Str()
{
    std::u32string str;
    bool first = true;
    for (SimpleTypeSpecifier specifier : specifiers)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            str.append(U" ");
        }
        str.append(ToString(specifier));
    }
    return str;
}

std::u32string SimpleTypeNode::Id()
{
    std::u32string id;
    bool first = true;
    for (SimpleTypeSpecifier specifier : specifiers)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            id.append(U".");
        }
        id.append(ToString(specifier));
    }
    return id;
}

} } // namespace sngcpp::ast

