// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/ExternalTypeSymbol.hpp>

namespace sngcpp { namespace symbols {

ExternalTypeSymbol::ExternalTypeSymbol(const Span& span_, const std::u32string& name_, ClassKey classKey_, const std::u32string& id_) :
    TypeSymbol(span_, name_), classKey(classKey_), id(id_)
{
}

std::unique_ptr<sngxml::dom::Element> ExternalTypeSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> typeElement(new sngxml::dom::Element(U"externalType"));
    return typeElement;
}

} } // namespace sngcpp::symbols
