// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_READER_INCLUDED
#define SNGCPP_AST_READER_INCLUDED
#include <sngcpp/ast/AstApi.hpp>
#include <sngcpp/ast/SimpleType.hpp>
#include <sngcpp/ast/Specifier.hpp>
#include <sngcpp/ast/Class.hpp>
#include <sngcpp/ast/Enumeration.hpp>
#include <sngcpp/ast/Expression.hpp>
#include <sngcpp/ast/Literal.hpp>
#include <sngcpp/ast/Namespace.hpp>
#include <soulng/lexer/Lexer.hpp>
#include <soulng/util/BinaryReader.hpp>

namespace sngcpp { namespace ast {

class SNGCPP_AST_API Reader
{
public:
    Reader(soulng::util::BinaryReader& binaryReader_);
    void Read(soulng::lexer::Span& span);
    soulng::util::BinaryReader& GetBinaryReader() { return binaryReader; }
    SimpleTypeSpecifier ReadSimpleTypeSpecifier();
    NodeType ReadNodeType();
    Specifier ReadSpecifiers();
    ClassKey ReadClassKey();
    EnumKey ReadEnumKey();
    Operator ReadOperator();
    Suffix ReadSuffix();
    Base ReadBase();
    Node* ReadNode();
    CompoundStatementNode* ReadCompoundStatementNode();
    StringLiteralNode* ReadStringLiteralNode();
    NamespaceNode* ReadNamespaceNode();
    IdentifierNode* ReadIdentifierNode();
private:
    soulng::util::BinaryReader& binaryReader;
};

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_READER_INCLUDED
