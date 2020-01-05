// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_GRAMMAR_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_GRAMMAR_SYMBOL_INCLUDED
#include <sngcpp/symbols/ContainerSymbol.hpp>
#include <sngcpp/symbols/RuleSymbol.hpp>

namespace sngcpp { namespace symbols {

class SNGCPP_SYMBOLS_API GrammarSymbol : public ContainerSymbol
{
public:
    GrammarSymbol(const Span& span_, const std::u32string& name_);
    void AddMember(std::unique_ptr<Symbol>&& member) override;
    std::u32string KindStr() override;
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    bool IsGrammarSymbol() const override { return true; }
private:
    std::vector<RuleSymbol*> rules;
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_GRAMMAR_SYMBOL_INCLUDED
