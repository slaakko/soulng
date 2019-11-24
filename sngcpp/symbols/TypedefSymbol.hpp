// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_TYPEDEF_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_TYPEDEF_SYMBOL_INCLUDED
#include <sngcpp/symbols/TypeSymbol.hpp>

namespace sngcpp { namespace symbols {

class SNGCPP_SYMBOLS_API TypedefSymbol : public TypeSymbol
{
public:
    TypedefSymbol(const Span& span_, const std::u32string& name_);
    std::u32string KindStr() override { return U"typedef"; }
    int MatchValue(TypeSymbol* argumentType) override;
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    bool IsTypedefSymbol() const override { return true; }
    TypeSymbol* GetType() override { return type; }
    void SetType(TypeSymbol* type_) { type = type_; }
    void SetPrimaryId(const std::u32string& primaryId_);
    const std::u32string& PrimaryId() const { return primaryId; }
private:
    TypeSymbol* type;
    std::u32string primaryId;
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_TYPEDEF_SYMBOL_INCLUDED
