// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/PseudoTypeSymbol.hpp>

namespace sngcpp { namespace symbols {

PseudoTypeSymbol::PseudoTypeSymbol(const Span& span_, const std::u32string& name_, const std::u32string& id_) : TypeSymbol(span_, name_), id(id_), functionGroup(nullptr)
{
}

std::unique_ptr<sngxml::dom::Element> PseudoTypeSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> typeElement(new sngxml::dom::Element(U"pseudoType"));
    return typeElement;
}

} } // namespace sngcpp::symbols
