// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/TemplateSymbol.hpp>
#include <limits>

namespace sngcpp { namespace symbols {

TemplateParameterSymbol::TemplateParameterSymbol(const Span& span_, const std::u32string& name_) : TypeSymbol(span_, name_)
{
}

std::unique_ptr<sngxml::dom::Element> TemplateParameterSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> templateParameter(new sngxml::dom::Element(U"templateParameter"));
    return templateParameter;
}

int TemplateParameterSymbol::MatchValue(TypeSymbol* argumentType)
{
    return std::numeric_limits<int>::max() - 1;
}

} } // namespace sngcpp::symbols
