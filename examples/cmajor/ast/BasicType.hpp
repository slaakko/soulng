// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef CMAJOR_AST_BASIC_TYPE_INCLUDED
#define CMAJOR_AST_BASIC_TYPE_INCLUDED
#include <cmajor/ast/Node.hpp>

namespace cmajor { namespace ast {

class CMAJOR_AST_API BoolNode : public Node
{
public:
    BoolNode(const Span& span_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    std::string ToString() const override { return "bool";  }
};

class CMAJOR_AST_API SByteNode : public Node
{
public:
    SByteNode(const Span& span_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    std::string ToString() const override { return "sbyte"; }
};

class CMAJOR_AST_API ByteNode : public Node
{
public:
    ByteNode(const Span& span_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    bool IsUnsignedTypeNode() const override { return true; }
    std::string ToString() const override { return "byte"; }
};

class CMAJOR_AST_API ShortNode : public Node
{
public:
    ShortNode(const Span& span_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    std::string ToString() const override { return "short"; }
};

class CMAJOR_AST_API UShortNode : public Node
{
public:
    UShortNode(const Span& span_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    bool IsUnsignedTypeNode() const override { return true; }
    std::string ToString() const override { return "ushort"; }
};

class CMAJOR_AST_API IntNode : public Node
{
public:
    IntNode(const Span& span_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    std::string ToString() const override { return "int"; }
};

class CMAJOR_AST_API UIntNode : public Node
{
public:
    UIntNode(const Span& span_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    bool IsUnsignedTypeNode() const override { return true; }
    std::string ToString() const override { return "uint"; }
};

class CMAJOR_AST_API LongNode : public Node
{
public:
    LongNode(const Span& span_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    std::string ToString() const override { return "long"; }
};

class CMAJOR_AST_API ULongNode : public Node
{
public:
    ULongNode(const Span& span_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    bool IsUnsignedTypeNode() const override { return true; }
    std::string ToString() const override { return "ulong"; }
};

class CMAJOR_AST_API FloatNode : public Node
{
public:
    FloatNode(const Span& span_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    std::string ToString() const override { return "float"; }
};

class CMAJOR_AST_API DoubleNode : public Node
{
public:
    DoubleNode(const Span& span_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    std::string ToString() const override { return "double"; }
};

class CMAJOR_AST_API CharNode : public Node
{
public:
    CharNode(const Span& span_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    std::string ToString() const override { return "char"; }
};

class CMAJOR_AST_API WCharNode : public Node
{
public:
    WCharNode(const Span& span_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    std::string ToString() const override { return "wchar"; }
};

class CMAJOR_AST_API UCharNode : public Node
{
public:
    UCharNode(const Span& span_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    std::string ToString() const override { return "uchar"; }
};

class CMAJOR_AST_API VoidNode : public Node
{
public:
    VoidNode(const Span& span_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    std::string ToString() const override { return "void"; }
};

} } // namespace cmajor::ast

#endif // CMAJOR_AST_BASIC_TYPE_INCLUDED
