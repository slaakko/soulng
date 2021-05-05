// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Reader.hpp>

namespace sngcpp::ast {

Reader::Reader(const std::string& fileName) : binaryReader(fileName)
{
}

SourcePos Reader::ReadSourcePos()
{
    int line = binaryReader.ReadULEB128UInt();
    if (line == 0) return SourcePos();
    int col = binaryReader.ReadULEB128UInt();
    return SourcePos(line, col);
}

NodeKind Reader::ReadNodeKind()
{
    uint32_t kind = binaryReader.ReadULEB128UInt();
    return static_cast<NodeKind>(kind);
}

std::u32string Reader::ReadStr()
{
    return binaryReader.ReadUtf32String();
}

bool Reader::ReadBool()
{
    return binaryReader.ReadBool();
}

Node* Reader::ReadNode()
{
    NodeKind kind = ReadNodeKind();
    if (kind == NodeKind::nullNode)
    {
        return nullptr;
    }
    else
    {
        SourcePos sourcePos = ReadSourcePos();
        Node* node = CreateNode(kind, sourcePos);
        node->Read(*this);
        return node;
    }
}

} // namespace sngcpp::ast
