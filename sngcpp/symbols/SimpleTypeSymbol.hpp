// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_SIMPLE_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_SIMPLE_TYPE_SYMBOL_INCLUDED
#include <sngcpp/symbols/TypeSymbol.hpp>
#include <sngcpp/ast/SimpleType.hpp>

namespace sngcpp { namespace symbols {

class SNGCPP_SYMBOLS_API SimpleTypeSymbol : public TypeSymbol
{
public:
    SimpleTypeSymbol(const Span& span_, const std::u32string& name_, const std::u32string& id_, SimpleTypeSpecifierFlags flags_);
    bool IsSimpleTypeSymbol() const override { return true; }
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    std::u32string Id() override { return id; }
    SimpleTypeSpecifierFlags Flags() const { return flags; }
private:
    std::u32string id;
    SimpleTypeSpecifierFlags flags;
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_SIMPLE_TYPE_SYMBOL_INCLUDED
