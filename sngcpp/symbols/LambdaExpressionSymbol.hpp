// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_LAMBDA_EXPRESSION_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_LAMBDA_EXPRESSION_SYMBOL_INCLUDED
#include <sngcpp/symbols/ContainerSymbol.hpp>

namespace sngcpp { namespace symbols {

class LambdaExpressionSymbol : public ContainerSymbol
{
public:
    LambdaExpressionSymbol(const Span& span_);
    std::u32string KindStr() override { return U"lambda"; }
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_LAMBDA_EXPRESSION_SYMBOL_INCLUDED
