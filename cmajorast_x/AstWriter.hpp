// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef CMAJOR_AST_AST_WRITER_INCLUDED
#define CMAJOR_AST_AST_WRITER_INCLUDED
#include <cmajorast/AstApi.hpp>
#include <cmajorast/Specifier.hpp>
#include <soulng/util/BinaryWriter.hpp>
#include <soulng/lexer/Span.hpp>

namespace cmajor { namespace ast {

using namespace soulng::util;
using soulng::lexer::Span;
class Node;

class AST_API AstWriter
{
public:
    AstWriter(const std::string& fileName_);
    BinaryWriter& GetBinaryWriter() { return binaryWriter; }
    void Write(Node* node);
    void Write(Specifiers specifiers);
    void Write(const Span& span);
private:
    BinaryWriter binaryWriter;
};

} } // namespace cmajor::ast

#endif // CMAJOR_AST_AST_WRITER_INCLUDED
