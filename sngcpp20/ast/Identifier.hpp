// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_IDENTIFIER_INCLUDED
#define SNGCPP_AST_IDENTIFIER_INCLUDED
#include <sngcpp20/ast/Node.hpp>
#include <string>

namespace sngcpp::ast {

class AST_API IdentifierNode : public Node
{
public:
    IdentifierNode(const SourcePos& sourcePos_, const std::u32string& id_);
    const std::u32string& Id() const { return id; }
private:
    std::u32string id;
};

class AST_API ColonColonNode : public Node
{
public:
    ColonColonNode(const SourcePos& sourcePos_);
};

class AST_API NestedNameSpecifierNode : public SequenceNode
{
public:
    NestedNameSpecifierNode(const SourcePos& sourcePos_);
};

class AST_API QualifiedIdNode : public BinaryNode
{
public:
    QualifiedIdNode(const SourcePos& sourcePos_, Node* nns_, Node* unqualifiedId_);
};

class AST_API IdentifierListNode : public ListNode
{
public:
    IdentifierListNode(const SourcePos& sourcePos_);
};

class AST_API QualifiedModuleIdNode : public BinaryNode
{
public:
    QualifiedModuleIdNode(const SourcePos& sourcePos_, Node* left_, Node* right_, const SourcePos& dotPos_);
private:
    SourcePos dotPos;
};

class AST_API DotNode : public Node
{
public:
    DotNode(const SourcePos& sourcePos_);
};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_IDENTIFIER_INCLUDED
