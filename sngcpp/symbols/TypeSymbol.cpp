// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/TypeSymbol.hpp>
#include <limits>

namespace sngcpp { namespace symbols {

TypeSymbol::TypeSymbol(const Span& span_, const std::u32string& name_) : ContainerSymbol(span_, name_)
{
}

std::unique_ptr<sngxml::dom::Element> TypeSymbol::CreateElement()
{
    return std::unique_ptr<sngxml::dom::Element>(new sngxml::dom::Element(U"type"));
}

bool TypeSymbol::HasBaseClass(TypeSymbol* type, int& distance)
{
    return false;
}

int TypeSymbol::MatchValue(TypeSymbol* argumentType)
{
    if (argumentType == nullptr) return 1;
    if (argumentType == this) return std::numeric_limits<int>::max();
    return 0;
}

} } // namespace sngcpp::symbols
