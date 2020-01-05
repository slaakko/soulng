// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_PARAMETER_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_PARAMETER_SYMBOL_INCLUDED
#include <sngcpp/symbols/Symbol.hpp>

namespace sngcpp { namespace symbols {

class TypeSymbol;

class SNGCPP_SYMBOLS_API ParameterSymbol : public Symbol
{
public:
    ParameterSymbol(const Span& span_, const std::u32string& name_);
    std::u32string KindStr() override { return U"parameter"; }
    std::u32string IdStr() override;
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    bool IsParameterSymbol() const override { return true; }
    TypeSymbol* GetType() override { return type; }
    void SetType(TypeSymbol* type_) { type = type_; }
private:
    TypeSymbol* type;
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_PARAMETER_SYMBOL_INCLUDED

