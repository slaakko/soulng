// =================================
// Copyright (c) 2022 Seppo Laakko
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
    if (!primaryId.empty())
    {
        typeElement->SetAttribute(U"primaryId", primaryId);
    }
    return typeElement;
}

int TypedefSymbol::MatchValue(TypeSymbol* argumentType)
{
    return type->MatchValue(argumentType);
}

void TypedefSymbol::SetPrimaryId(const std::u32string& primaryId_)
{
    primaryId = primaryId_;
}

} } // namespace sngcpp::symbols
