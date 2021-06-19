// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_SIMPLE_TYPE_INCLUDED
#define SNGCPP_AST_SIMPLE_TYPE_INCLUDED
#include <sngcpp20/ast/Node.hpp>

namespace sngcpp::ast {

class AST_API CharNode : public Node
{
public:
    CharNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API Char8Node : public Node
{
public:
    Char8Node(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API Char16Node : public Node
{
public:
    Char16Node(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API Char32Node : public Node
{
public:
    Char32Node(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API WCharNode : public Node
{
public:
    WCharNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API BoolNode : public Node
{
public:
    BoolNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ShortNode : public Node
{
public:
    ShortNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API IntNode : public Node
{
public:
    IntNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API LongNode : public Node
{
public:
    LongNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API SignedNode : public Node
{
public:
    SignedNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API UnsignedNode : public Node
{
public:
    UnsignedNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API FloatNode : public Node
{
public:
    FloatNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API DoubleNode : public Node
{
public:
    DoubleNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API VoidNode : public Node
{
public:
    VoidNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API Int64Node : public Node
{
public:
    Int64Node(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_SIMPLE_TYPE_INCLUDED
