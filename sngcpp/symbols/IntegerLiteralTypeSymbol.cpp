// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/IntegerLiteralTypeSymbol.hpp>

namespace sngcpp { namespace symbols {

IntegerLiteralTypeSymbol::IntegerLiteralTypeSymbol(const Span& span_, const std::u32string& name_, const std::u32string& id_) : TypeSymbol(span_, name_), id(id_)
{
}

std::unique_ptr<sngxml::dom::Element> IntegerLiteralTypeSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> typeElement(new sngxml::dom::Element(U"integerLiteralType"));
    return typeElement;
}

} } // namespace sngcpp::symbols
