// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/LambdaExpressionSymbol.hpp>

namespace sngcpp { namespace symbols {

LambdaExpressionSymbol::LambdaExpressionSymbol(const Span& span_) : ContainerSymbol(span_, U"lambda")
{
}

std::unique_ptr<sngxml::dom::Element> LambdaExpressionSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> lambdaElement(new sngxml::dom::Element(U"lambda"));
    return lambdaElement;
}

} } // namespace sngcpp::symbols
