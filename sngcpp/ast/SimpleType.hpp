// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_SIMPLE_TYPE_INCLUDED
#define SNGCPP_AST_SIMPLE_TYPE_INCLUDED
#include <sngcpp/ast/Node.hpp>
#include <string>
#include <vector>
#include <stdint.h>

namespace sngcpp { namespace ast {

enum class SimpleTypeSpecifier : uint8_t
{
    none, char_, char16, char32, wchar, bool_, short_, int_, long_, signed_, unsigned_, float_, double_, void_, auto_, max
};

enum class SimpleTypeSpecifierFlags : uint16_t
{
    none = 0, char_ = 1 << 0, char16 = 1 << 1, char32 = 1 << 2, wchar = 1 << 3, bool_ = 1 << 4, short_ = 1 << 5, int_ = 1 << 6, long_ = 1 << 7, longLong_ = 1 << 8,
    signed_ = 1 << 9, unsigned_ = 1 << 10, float_ = 1 << 11, double_ = 1 << 12, void_ = 1 << 13, auto_ = 1 << 14
};

constexpr inline SimpleTypeSpecifierFlags operator|(SimpleTypeSpecifierFlags left, SimpleTypeSpecifierFlags right)
{
    return SimpleTypeSpecifierFlags(uint16_t(left) | uint16_t(right));
}

constexpr inline SimpleTypeSpecifierFlags operator&(SimpleTypeSpecifierFlags left, SimpleTypeSpecifierFlags right)
{
    return SimpleTypeSpecifierFlags(uint16_t(left) & uint16_t(right));
}

constexpr inline SimpleTypeSpecifierFlags operator~(SimpleTypeSpecifierFlags flags)
{
    return SimpleTypeSpecifierFlags(~uint16_t(flags));
}

SNGCPP_AST_API std::u32string ToString(SimpleTypeSpecifier specifier);

class SNGCPP_AST_API SimpleTypeNode : public Node
{
public:
    SimpleTypeNode();
    SimpleTypeNode(const Span& span_, const std::vector<SimpleTypeSpecifier>& specifiers_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const std::vector<SimpleTypeSpecifier>& Specifiers() const { return specifiers; }
    SimpleTypeSpecifierFlags Flags() const { return flags; }
    std::u32string Str();
    std::u32string Id();
private:
    std::vector<SimpleTypeSpecifier> specifiers;
    SimpleTypeSpecifierFlags flags;
};

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_SIMPLE_TYPE_INCLUDED
