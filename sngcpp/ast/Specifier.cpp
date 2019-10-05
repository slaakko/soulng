// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Specifier.hpp>

namespace sngcpp { namespace ast {

std::u32string SpecifierStr(Specifier specifiers)
{
    std::u32string s;
    if ((specifiers & Specifier::public_) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"public");
    }
    else if ((specifiers & Specifier::protected_) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"protected");
    }
    else if ((specifiers & Specifier::private_) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"private");
    }
    if ((specifiers & Specifier::const_) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"const");
    }
    if ((specifiers & Specifier::constExpr) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"constexpr");
    }
    if ((specifiers & Specifier::volatile_) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"volatile");
    }
    if ((specifiers & Specifier::explicit_) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"explicit");
    }
    if ((specifiers & Specifier::mutable_) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"mutable");
    }
    if ((specifiers & Specifier::inline_) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"inline");
    }
    if ((specifiers & Specifier::static_) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"static");
    }
    if ((specifiers & Specifier::extern_) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"extern");
    }
    if ((specifiers & Specifier::register_) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"register");
    }
    if ((specifiers & Specifier::threadLocal) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"thread_local");
    }
    if ((specifiers & Specifier::pure_) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"pure");
    }
    if ((specifiers & Specifier::virtual_) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"virtual");
    }
    if ((specifiers & Specifier::override_) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"override");
    }
    if ((specifiers & Specifier::final_) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"final");
    }
    if ((specifiers & Specifier::new_) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"new");
    }
    if ((specifiers & Specifier::default_) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"default");
    }
    if ((specifiers & Specifier::delete_) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"delete");
    }
    if ((specifiers & Specifier::friend_) != Specifier::none)
    {
        if (!s.empty())
        {
            s.append(1, ' ');
        }
        s.append(U"friend");
    }
    return s;
}

} } // namespace sngcpp::ast
