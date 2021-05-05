// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Writer.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp::ast {

using namespace soulng::unicode;

Writer::Writer(const std::string& fileName) : binaryWriter(fileName)
{
}

void Writer::Write(const SourcePos& sourcePos)
{
    if (sourcePos.IsValid())
    {
        binaryWriter.WriteULEB128UInt(sourcePos.line);
        binaryWriter.WriteULEB128UInt(sourcePos.col);
    }
    else
    {
        binaryWriter.WriteULEB128UInt(0);
    }
}

void Writer::Write(NodeKind nodeKind)
{
    binaryWriter.WriteULEB128UInt(static_cast<uint32_t>(nodeKind));
}

void Writer::Write(const std::u32string& str)
{
    binaryWriter.Write(str);
}

void Writer::Write(bool value)
{
    binaryWriter.Write(value);
}

void Writer::Write(Node* node)
{
    if (!node)
    {
        Write(NodeKind::nullNode);
    }
    else
    {
        Write(node->Kind());
        Write(node->GetSourcePos());
        node->Write(*this);
    }
}

} // namespace sngcpp::ast
