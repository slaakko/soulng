// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_LITERAL_INCLUDED
#define SNGCPP_AST_LITERAL_INCLUDED
#include <sngcpp20/ast/Node.hpp>
#include <string>

namespace sngcpp::ast {

enum class Suffix : uint8_t
{
    none = 0,
    u = 1 << 0,
    l = 1 << 1,
    ll = 1 << 2,
    z = 1 << 3,
    f = 1 << 4
};

inline Suffix operator|(Suffix left, Suffix right)
{
    return Suffix(uint8_t(left) | uint8_t(right));
}

inline Suffix operator&(Suffix left, Suffix right)
{
    return Suffix(uint8_t(left) & uint8_t(right));
}

inline Suffix operator~(Suffix suffix)
{
    return Suffix(~uint8_t(suffix));
}

enum class Base : uint8_t
{
    binary, octal, decimal, hexadecimal
};

enum class EncodingPrefix : uint8_t
{
    none, u8, u, U, L
};

class AST_API LiteralNode : public Node
{
public:
    LiteralNode(NodeKind kind_, const SourcePos& sourcePos_);
    LiteralNode(NodeKind kind_, const SourcePos& sourcePos_, const std::u32string& rep_);
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const std::u32string& Rep() const { return rep; }
private:
    std::u32string rep;
};

class AST_API IntegerLiteralNode : public LiteralNode
{
public:
    IntegerLiteralNode(const SourcePos& sourcePos_);
    IntegerLiteralNode(const SourcePos& sourcePos_, uint64_t value_, Suffix suffix_, Base base_, const std::u32string& rep_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    uint64_t Value() const { return value; }
    Suffix GetSuffix() const { return suffix; }
    Base GetBase() const { return base; }
private:
    uint64_t value;
    Suffix suffix;
    Base base;
};

class AST_API FloatingLiteralNode : public LiteralNode
{
public:
    FloatingLiteralNode(const SourcePos& sourcePos_);
    FloatingLiteralNode(const SourcePos& sourcePos_, double value_, Suffix suffix_, Base base_, const std::u32string& rep_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    double Value() const { return value; }
    Suffix GetSuffix() const { return suffix; }
    Base GetBase() const { return base; }
private:
    double value;
    Suffix suffix;
    Base base;
};

class AST_API CharacterLiteralNode : public LiteralNode
{
public:
    CharacterLiteralNode(const SourcePos& sourcePos_);
    CharacterLiteralNode(const SourcePos& sourcePos_, char32_t value_, EncodingPrefix encodingPrefix_, const std::u32string& rep_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    char32_t Value() const { return value; }
    EncodingPrefix GetEncodingPrefix() const { return encodingPrefix; }
private:
    char32_t value;
    EncodingPrefix encodingPrefix;
};

class AST_API StringLiteralNode : public LiteralNode
{
public:
    StringLiteralNode(const SourcePos& sourcePos_);
    StringLiteralNode(NodeKind kind_, const SourcePos& sourcePos_);
    StringLiteralNode(const SourcePos& sourcePos_, const std::u32string& value_, EncodingPrefix encodingPrefix_, const std::u32string& rep_);
    StringLiteralNode(NodeKind kind_, const SourcePos& sourcePos_, const std::u32string& value_, EncodingPrefix encodingPrefix_, const std::u32string& rep_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const std::u32string& Value() const { return value; }
    EncodingPrefix GetEncodingPrefix() const { return encodingPrefix; }
private:
    std::u32string value;
    EncodingPrefix encodingPrefix;
};

class AST_API RawStringLiteralNode : public StringLiteralNode
{
public:
    RawStringLiteralNode(const SourcePos& sourcePos_);
    RawStringLiteralNode(const SourcePos& sourcePos_, const std::u32string& value_, EncodingPrefix encodingPrefix_, const std::u32string& delimSequence_, const std::u32string& rep_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const std::u32string& DelimSequence() const { return delimSequence; }
private:
    std::u32string delimSequence;
};

class AST_API BooleanLiteralNode : public LiteralNode
{
public:
    BooleanLiteralNode(const SourcePos& sourcePos_);
    BooleanLiteralNode(const SourcePos& sourcePos_, bool value_, const std::u32string& rep_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    bool Value() const { return value; }
private:
    bool value;
};

class AST_API NullPtrLiteralNode : public LiteralNode
{
public:
    NullPtrLiteralNode(const SourcePos& sourcePos_);
    NullPtrLiteralNode(const SourcePos& sourcePos_, const std::u32string& rep_);
    void Accept(Visitor& visitor) override;
};

class AST_API UserDefinedLiteraNode : public BinaryNode
{
public:
    UserDefinedLiteraNode(const SourcePos& sourcePos_);
    UserDefinedLiteraNode(const SourcePos& sourcePos_, Node* literalNode_, Node* udSuffix_);
    void Accept(Visitor& visitor) override;
};

class AST_API LiteralOperatorIdNode : public UnaryNode
{
public:
    LiteralOperatorIdNode(const SourcePos& sourcePos_);
    LiteralOperatorIdNode(const SourcePos& sourcePos_, Node* id_, const SourcePos& stringLitPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const SourcePos& StringLitPos() const { return stringLitPos; }
private:
    SourcePos stringLitPos;
};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_LITERAL_INCLUDED
