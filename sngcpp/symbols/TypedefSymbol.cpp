// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/TypedefSymbol.hpp>

namespace sngcpp { namespace symbols {

TypedefSymbol::TypedefSymbol(const Span& span_, const std::u32string& name_) : TypeSymbol(span_, name_), type(nullptr)
{
}

std::unique_ptr<sngxml::dom::Element> TypedefSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> typeElement(new sngxml::dom::Element(U"typedef"));
    typeElement->SetAttribute(U"type", type->Id());
    return typeElement;
}

} } // namespace sngcpp::symbols
