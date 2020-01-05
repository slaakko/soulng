// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/GrammarSymbol.hpp>

namespace sngcpp { namespace symbols {

GrammarSymbol::GrammarSymbol(const Span& span_, const std::u32string& name_) : ContainerSymbol(span_, name_)
{
    SetAccess(Specifier::public_);
}

std::u32string GrammarSymbol::KindStr()
{
    return U"grammar";
}

void GrammarSymbol::AddMember(std::unique_ptr<Symbol>&& member)
{
    Symbol* m = member.get();
    ContainerSymbol::AddMember(std::move(member));
    if (m->IsRuleSymbol())
    {
        rules.push_back(static_cast<RuleSymbol*>(m));
    }
}

std::unique_ptr<sngxml::dom::Element> GrammarSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> grammarElement(new sngxml::dom::Element(U"grammar"));
    if (!rules.empty())
    {
        std::unique_ptr<sngxml::dom::Element> rulesElement(new sngxml::dom::Element(U"rules"));
        for (RuleSymbol* ruleSymbol : rules)
        {
            std::unique_ptr<sngxml::dom::Element> ruleElement(ruleSymbol->ToDomElement());
            rulesElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(ruleElement.release()));
        }
        grammarElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(rulesElement.release()));
    }
    return grammarElement;
}

} } // namespace sngcpp::symbols
