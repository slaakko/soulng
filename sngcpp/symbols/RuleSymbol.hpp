// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_RULE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_RULE_SYMBOL_INCLUDED
#include <sngcpp/symbols/Symbol.hpp>

namespace sngcpp { namespace symbols {

class SNGCPP_SYMBOLS_API RuleSymbol : public Symbol
{
public:
    RuleSymbol(const Span& span_, const std::u32string& name_);
    std::u32string KindStr() override;
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    bool IsRuleSymbol() const override { return true; }
    sngxml::dom::Element* Body() { return ruleBody.get(); }
private:
    std::unique_ptr<sngxml::dom::Element> ruleBody;
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_RULE_SYMBOL_INCLUDED
