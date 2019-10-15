// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/SimpleTypeSymbol.hpp>

namespace sngcpp { namespace symbols {

SimpleTypeSymbol::SimpleTypeSymbol(const Span& span_, const std::u32string& name_, const std::u32string& id_) : TypeSymbol(span_, name_), id(id_)
{
}

std::unique_ptr<sngxml::dom::Element> SimpleTypeSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> typeElement(new sngxml::dom::Element(U"simpleType"));
    return typeElement;
}

} } // namespace sngcpp::symbols
