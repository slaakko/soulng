// =================================
// Copyright (c) 2019 Seppo Laakko
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
    char_, char16, char32, wchar, bool_, short_, int_, long_, signed_, unsigned_, float_, double_, void_, auto_, max
};

SNGCPP_AST_API std::u32string ToString(SimpleTypeSpecifier specifier);

class SNGCPP_AST_API SimpleTypeNode : public Node
{
public:
    SimpleTypeNode(const Span& span_, const std::vector<SimpleTypeSpecifier>& specifiers_);
    void Accept(Visitor& visitor) override;
    const std::vector<SimpleTypeSpecifier>& Specifiers() const { return specifiers; }
    std::u32string Str();
    std::u32string Id();
private:
    std::vector<SimpleTypeSpecifier> specifiers;
};

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_SIMPLE_TYPE_INCLUDED
