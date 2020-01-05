// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_TEMPLATE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_TEMPLATE_SYMBOL_INCLUDED
#include <sngcpp/symbols/TypeSymbol.hpp>

namespace sngcpp { namespace symbols {

class SNGCPP_SYMBOLS_API TemplateParameterSymbol : public TypeSymbol
{
public:
    TemplateParameterSymbol(const Span& span_, const std::u32string& name_);
    std::u32string KindStr() override { return U"templateParameter"; }
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    bool IsTemplateParameterSymbol() const override { return true; }
    int MatchValue(TypeSymbol* argumentType) override;
};

} } // namespace sngcpp::symbol

#endif // SNGCPP_SYMBOLS_TEMPLATE_SYMBOL_INCLUDED
