// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_READER_INCLUDED
#define SNGCPP_AST_READER_INCLUDED
#include <sngcpp20/ast/Node.hpp>
#include <soulng/lexer/SourcePos.hpp>
#include <soulng/util/BinaryReader.hpp>

namespace sngcpp::ast {

using namespace soulng::lexer;
using namespace soulng::util;

class AST_API Reader
{
public:
    Reader(const std::string& fileName);
    BinaryReader& GetBinaryReader() { return binaryReader; }
    SourcePos ReadSourcePos();
    NodeKind ReadNodeKind();
    std::u32string ReadStr();
    bool ReadBool();
    Node* ReadNode();
private:
    BinaryReader binaryReader;
};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_READER_INCLUDED
