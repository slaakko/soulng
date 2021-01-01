// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_INTEGER_LITERAL_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_INTEGER_LITERAL_TYPE_SYMBOL_INCLUDED
#include <sngcpp/symbols/TypeSymbol.hpp>

namespace sngcpp { namespace symbols {

class SNGCPP_SYMBOLS_API IntegerLiteralTypeSymbol : public TypeSymbol
{
public:
    IntegerLiteralTypeSymbol(const Span& span_, const std::u32string& name_, const std::u32string& id_);
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    std::u32string Id() override { return id; }
private:
    std::u32string id;
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_INTEGER_LITERAL_TYPE_SYMBOL_INCLUDED
