// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_IDENTIFIER_INCLUDED
#define SNGCPP_AST_IDENTIFIER_INCLUDED
#include <sngcpp20/ast/Node.hpp>
#include <string>

namespace sngcpp::ast {

class AST_API IdentifierNode : public CompoundNode
{
public:
    IdentifierNode(const SourcePos& sourcePos_);
    IdentifierNode(const SourcePos& sourcePos_, const std::u32string& str_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    std::u32string Str() const override { return str; }
private:
    std::u32string str;
};

class AST_API UnnamedNode : public Node
{
public:
    UnnamedNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ColonColonNode : public Node
{
public:
    ColonColonNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API NestedNameSpecifierNode : public SequenceNode
{
public:
    NestedNameSpecifierNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API QualifiedIdNode : public BinaryNode
{
public:
    QualifiedIdNode(const SourcePos& sourcePos_);
    QualifiedIdNode(const SourcePos& sourcePos_, Node* nns_, Node* unqualifiedId_);
    void Accept(Visitor& visitor) override;
};

class AST_API IdentifierListNode : public ListNode
{
public:
    IdentifierListNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API QualifiedModuleIdNode : public BinaryNode
{
public:
    QualifiedModuleIdNode(const SourcePos& sourcePos_);
    QualifiedModuleIdNode(const SourcePos& sourcePos_, Node* left_, Node* right_, const SourcePos& dotPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const SourcePos& DotPos() const { return dotPos; }
private:
    SourcePos dotPos;
};

class AST_API DotNode : public Node
{
public:
    DotNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_IDENTIFIER_INCLUDED
