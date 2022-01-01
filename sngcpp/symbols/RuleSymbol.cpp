// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/RuleSymbol.hpp>

namespace sngcpp { namespace symbols {

RuleSymbol::RuleSymbol(const Span& span_, const std::u32string& name_) : Symbol(span_, name_)
{
    SetAccess(Specifier::public_);
    ruleBody.reset(new sngxml::dom::Element(U"span"));
    ruleBody->SetAttribute(U"xml:space", U"preserve");
}

std::u32string RuleSymbol::KindStr()
{
    return U"rule";
}

std::unique_ptr<sngxml::dom::Element> RuleSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> ruleElement(new sngxml::dom::Element(U"rule"));
    ruleElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(ruleBody.release()));
    return ruleElement;
}

} } // namespace sngcpp::symbols
