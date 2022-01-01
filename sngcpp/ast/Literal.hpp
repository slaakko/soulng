// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_LITERAL_INCLUDED
#define SNGCPP_AST_LITERAL_INCLUDED
#include <sngcpp/ast/Node.hpp>
#include <string>

namespace sngcpp { namespace ast {

enum class Suffix : uint8_t
{
    none = 0, 
    f = 1 << 0, 
    l = 1 << 1,
    ll = 1 << 2, 
    u = 1 << 3
};

SNGCPP_AST_API inline Suffix operator|(Suffix left, Suffix right)
{
    return Suffix(uint8_t(left) | uint8_t(right));
}

SNGCPP_AST_API inline Suffix operator&(Suffix left, Suffix right)
{
    return Suffix(uint8_t(left) & uint8_t(right));
}

enum class Base : uint8_t
{
    decimal, hex, octal
};

SNGCPP_AST_API std::u32string ToString(Suffix suffix);

class SNGCPP_AST_API LiteralNode : public Node
{
public:
    LiteralNode(NodeType nodeType_);
    LiteralNode(NodeType nodeType_, const Span& span_, const std::u32string& rep_);
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const std::u32string& Rep() const { return rep; }
private:
    std::u32string rep;
};

class SNGCPP_AST_API FloatingLiteralNode : public LiteralNode
{
public:
    FloatingLiteralNode();
    FloatingLiteralNode(const Span& span_, double value_, Suffix suffix_, const std::u32string& rep_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    double Value() const { return value; }
    Suffix GetSuffix() const { return suffix; }
private:
    double value;
    Suffix suffix;
};

class SNGCPP_AST_API IntegerLiteralNode : public LiteralNode
{
public:
    IntegerLiteralNode();
    IntegerLiteralNode(const Span& span_, uint64_t value_, Suffix suffix_, Base base_, const std::u32string& rep_);
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

class SNGCPP_AST_API CharacterLiteralNode : public LiteralNode
{
public:
    CharacterLiteralNode();
    CharacterLiteralNode(const Span& span_, char32_t prefix_, char32_t chr_, const std::u32string& rep_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    char32_t Prefix() const { return prefix; }
    char32_t Chr() const { return chr; }
private:
    char32_t prefix;
    char32_t chr;
};

class SNGCPP_AST_API StringLiteralNode : public LiteralNode
{
public:
    StringLiteralNode();
    StringLiteralNode(const Span& span_, const std::u32string& encodingPrefix_, const std::u32string& chars_, const std::u32string& rep_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const std::u32string& EncodigPrefix() const { return encodingPrefix; }
    const std::u32string& Chars() const { return chars; }
private:
    std::u32string encodingPrefix;
    std::u32string chars;
};

class SNGCPP_AST_API BooleanLiteralNode : public LiteralNode
{
public:
    BooleanLiteralNode();
    BooleanLiteralNode(const Span& span_, bool value_, const std::u32string& rep_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    bool Value() const { return value; }
private:
    bool value;
};

class SNGCPP_AST_API NullPtrLiteralNode : public LiteralNode
{
public:
    NullPtrLiteralNode();
    NullPtrLiteralNode(const Span& span_, const std::u32string& rep_);
    void Accept(Visitor& visitor) override;
};

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_LITERAL_INCLUDED
