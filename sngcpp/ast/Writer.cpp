// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Writer.hpp>

namespace sngcpp { namespace ast {

Writer::Writer(const std::vector<soulng::lexer::Lexer*>& lexers_, soulng::util::BinaryWriter& binaryWriter_) : lexers(lexers_), binaryWriter(binaryWriter_)
{
}

void Writer::Write(soulng::lexer::Span& span)
{
    if (span.fileIndex != -1)
    {
        soulng::lexer::Lexer* lexer = lexers[span.fileIndex];
        lexer->ConvertExternal(span);
    }
    binaryWriter.Write(int32_t(span.fileIndex));
    binaryWriter.Write(int32_t(span.line));
    binaryWriter.Write(int32_t(span.start));
    binaryWriter.Write(int32_t(span.end));
}

void Writer::Write(SimpleTypeSpecifier specifier)
{
    binaryWriter.Write(uint8_t(specifier));
}

void Writer::Write(NodeType nodeType)
{
    binaryWriter.Write(uint8_t(nodeType));
}

void Writer::Write(Specifier specifiers)
{
    binaryWriter.Write(uint32_t(specifiers));
}

void Writer::Write(ClassKey classKey)
{
    binaryWriter.Write(uint8_t(classKey));
}

void Writer::Write(EnumKey enumKey)
{
    binaryWriter.Write(uint8_t(enumKey));
}

void Writer::Write(Operator op)
{
    binaryWriter.Write(uint8_t(op));
}

void Writer::Write(Suffix suffix)
{
    binaryWriter.Write(uint8_t(suffix));
}

void Writer::Write(Base base)
{
    binaryWriter.Write(uint8_t(base));
}

} } // namespace sngcpp::ast
