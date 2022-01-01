// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_DECLARATION_BLOCK_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_DECLARATION_BLOCK_SYMBOL_INCLUDED
#include <sngcpp/symbols/ContainerSymbol.hpp>

namespace sngcpp { namespace symbols {

class SNGCPP_SYMBOLS_API DeclarationBlockSymbol : public ContainerSymbol
{
public:
    DeclarationBlockSymbol(const Span& span_, const std::u32string& name_);
    std::u32string KindStr() override { return U"declaration_block"; }
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    bool IsDeclarationBlockSymbol() const override { return true; }
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_DECLARATION_BLOCK_SYMBOL_INCLUDED
