// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcm/ast/AstWriter.hpp>
#include <sngcm/ast/Node.hpp>

namespace sngcm { namespace ast {

AstWriter::AstWriter(const std::string& fileName_) : binaryWriter(fileName_)
{
}

void AstWriter::Write(Node* node)
{
    binaryWriter.Write(static_cast<uint8_t>(node->GetNodeType()));
    Write(node->GetSpan());
    node->Write(*this);
}

void AstWriter::Write(Specifiers specifiers)
{
    binaryWriter.Write(static_cast<uint32_t>(specifiers));
}

void AstWriter::Write(const Span& span)
{
    if (!span.Valid())
    {
        binaryWriter.Write(false);
    }
    else
    {
        binaryWriter.Write(true);
        binaryWriter.WriteULEB128UInt(static_cast<uint32_t>(span.fileIndex));
        binaryWriter.WriteULEB128UInt(static_cast<uint32_t>(span.line));
        binaryWriter.WriteULEB128UInt(static_cast<uint32_t>(span.start));
        binaryWriter.WriteULEB128UInt(static_cast<uint32_t>(span.end));
    }
}

} } // namespace sngcm::ast
