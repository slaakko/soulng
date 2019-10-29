// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_PSEUDO_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_PSEUDO_TYPE_SYMBOL_INCLUDED
#include <sngcpp/symbols/TypeSymbol.hpp>

namespace sngcpp { namespace symbols {

class SNGCPP_SYMBOLS_API PseudoTypeSymbol : public TypeSymbol
{
public:
    PseudoTypeSymbol(const Span& span_, const std::u32string& name_, const std::u32string& id_);
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    std::u32string Id() override { return id; }
    bool IsPseudoTypeSymbol() const override { return true; }
    void SetFunctionGroup(FunctionGroupSymbol* functionGroup_) { functionGroup = functionGroup_; }
    FunctionGroupSymbol* GetFunctionGroup() const { return functionGroup; }
private:
    std::u32string id;
    FunctionGroupSymbol* functionGroup;
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_PSEUDO_TYPE_SYMBOL_INCLUDED
