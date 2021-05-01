// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_WRITER_INCLUDED
#define SNGCPP_AST_WRITER_INCLUDED
#include <sngcpp20/ast/Node.hpp>
#include <soulng/lexer/SourcePos.hpp>
#include <soulng/util/BinaryWriter.hpp>

namespace sngcpp::ast {

using namespace soulng::lexer;
using namespace soulng::util;   

class AST_API Writer
{
public:
    Writer(const std::string& fileName);
    BinaryWriter& GetBinaryWriter() { return binaryWriter; }
    void Write(const SourcePos& sourcePos);
    void Write(NodeKind nodeKind);
    void Write(Node* node);
private:
    BinaryWriter binaryWriter;
};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_WRITER_INCLUDED
