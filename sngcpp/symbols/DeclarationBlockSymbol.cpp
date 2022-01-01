// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/DeclarationBlockSymbol.hpp>

namespace sngcpp { namespace symbols {

DeclarationBlockSymbol::DeclarationBlockSymbol(const Span& span_, const std::u32string& name_) : ContainerSymbol(span_, name_)
{
}

std::unique_ptr<sngxml::dom::Element> DeclarationBlockSymbol::CreateElement()
{
    return std::unique_ptr<sngxml::dom::Element>(new sngxml::dom::Element(U"block"));
}

} } // namespace sngcpp::symbols
