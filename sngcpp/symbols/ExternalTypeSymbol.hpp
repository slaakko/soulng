// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_EXTERNAL_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_EXTERNAL_TYPE_SYMBOL_INCLUDED
#include <sngcpp/symbols/TypeSymbol.hpp>
#include <sngcpp/ast/Class.hpp>

namespace sngcpp { namespace symbols {

class SNGCPP_SYMBOLS_API ExternalTypeSymbol : public TypeSymbol
{
public:
    ExternalTypeSymbol(const Span& span_, const std::u32string& name_, ClassKey classKey_, const std::u32string& id_);
    bool IsExternalTypeSymbol() const override { return true; }
    ClassKey GetClassKey() const { return classKey; }
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    std::u32string Id() override { return id; }
private:
    ClassKey classKey;
    std::u32string id;
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_EXTERNAL_TYPE_SYMBOL_INCLUDED
