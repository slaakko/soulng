// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_SPECIFIER_INCLUDED
#define SNGCPP_AST_SPECIFIER_INCLUDED
#include <sngcpp/ast/AstApi.hpp>
#include <stdint.h>
#include <string>

namespace sngcpp { namespace ast {

enum class Specifier : uint32_t
{
    none = 0,
    register_ = 1 << 0,
    static_ = 1 << 1,
    threadLocal = 1 << 2,
    extern_ = 1 << 3,
    mutable_ = 1 << 4,
    inline_ = 1 << 5,
    virtual_ = 1 << 6,
    explicit_ = 1 << 7,
    override_ = 1 << 8,
    pure_ = 1 << 9,
    final_ = 1 << 10,
    new_ = 1 << 11,
    default_ = 1 << 12,
    delete_ = 1 << 13,
    friend_ = 1 << 14,
    constExpr = 1 << 15,
    const_ = 1 << 16,
    volatile_ = 1 << 17,
    public_ = 1 << 18,
    protected_ = 1 << 19,
    private_ = 1 << 20,
    extension = 1 << 21,
    access = public_ | protected_ | private_,
    virtuality = virtual_ | override_ | pure_
};

SNGCPP_AST_API constexpr inline Specifier operator|(Specifier left, Specifier right)
{
    return Specifier(uint32_t(left) | uint32_t(right));
}

SNGCPP_AST_API constexpr inline Specifier operator&(Specifier left, Specifier right)
{
    return Specifier(uint32_t(left) & uint32_t(right));
}

SNGCPP_AST_API std::u32string SpecifierStr(Specifier specifiers);

SNGCPP_AST_API constexpr inline Specifier DeclSpecifierMask()
{
    return Specifier::register_ | Specifier::static_ | Specifier::threadLocal | Specifier::extern_ | Specifier::mutable_ |
        Specifier::inline_ | Specifier::virtual_ | Specifier::explicit_ |
        Specifier::friend_ | Specifier::constExpr;
}

SNGCPP_AST_API constexpr inline Specifier VirtPureSpecifierMask()
{
    return Specifier::override_ | Specifier::final_ | Specifier::new_ | Specifier::pure_;
}

SNGCPP_AST_API constexpr inline Specifier DefaultDeleteSpecifierMask()
{
    return Specifier::default_ | Specifier::delete_;
}

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_SPECIFIER_INCLUDED
