// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/VariableSymbol.hpp>

namespace sngcpp { namespace symbols {

VariableSymbol::VariableSymbol(const Span& span_, const std::u32string& name_) : Symbol(span_, name_), specifiers(Specifier::none), type(nullptr)
{
}

void VariableSymbol::AddSpecifiers(Specifier specifiers_)
{
    specifiers = specifiers | specifiers_;
}

std::unique_ptr<sngxml::dom::Element> VariableSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> variableElement(new sngxml::dom::Element(U"variable"));
    variableElement->SetAttribute(U"type", type->Id());
    if (specifiers != Specifier::none)
    {
        variableElement->SetAttribute(U"specifiers", SpecifierStr(specifiers));
    }
    return variableElement;
}

} } // namespace sngcpp::symbols
