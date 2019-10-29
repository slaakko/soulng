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
    U"char", U"char16_t", U"char32_t", U"wchar_t", U"bool", U"short", U"int", U"long", U"signed", U"unsigned", U"float", U"double", U"void", U"auto"
};

std::u32string ToString(SimpleTypeSpecifier specifier)
{
    return simpleTypeSpecifierStr[uint8_t(specifier)];
}

SimpleTypeNode::SimpleTypeNode() : Node(NodeType::simpleTypeNode)
{
}

SimpleTypeNode::SimpleTypeNode(const Span& span_, const std::vector<SimpleTypeSpecifier>& specifiers_) : Node(NodeType::simpleTypeNode, span_), specifiers(specifiers_)
{
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
}

void SimpleTypeNode::Read(Reader& reader)
{
    Node::Read(reader);
    uint8_t n = reader.GetBinaryReader().ReadByte();
    for (uint8_t i = 0; i < n; ++i)
    {
        specifiers.push_back(reader.ReadSimpleTypeSpecifier());
    }
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

