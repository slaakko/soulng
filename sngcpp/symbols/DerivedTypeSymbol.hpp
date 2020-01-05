// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_DERIVED_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_DERIVED_TYPE_SYMBOL_INCLUDED
#include <sngcpp/symbols/TypeSymbol.hpp>

namespace sngcpp { namespace symbols {

enum class Derivation : uint8_t
{
    const_, volatile_, lvalueRef, rvalueRef, ptr, base
};

SNGCPP_SYMBOLS_API std::vector<Derivation> UnifyDerivations(const std::vector<Derivation>& left, const std::vector<Derivation>& right);

SNGCPP_SYMBOLS_API std::u32string MakeDerivedTypeId(const std::vector<Derivation>& derivations, TypeSymbol* baseType);
SNGCPP_SYMBOLS_API std::u32string MakeDerivedTypeName(const std::vector<Derivation>& derivations, TypeSymbol* baseType);

class SNGCPP_SYMBOLS_API DerivedTypeSymbol : public TypeSymbol
{
public:
    DerivedTypeSymbol(const Span& span_, const std::u32string& name_, TypeSymbol* baseType_, const std::vector<Derivation>& derivations_, const std::u32string& id_);
    const std::vector<Derivation>& Derivations() const { return derivations; }
    int MatchValue(TypeSymbol* argumentType) override;
    TypeSymbol* BaseType() override { return baseType; }
    bool IsDerivedTypeSymbol() const override { return true; }
    bool IsReferenceTypeSymbol() const override;
    bool IsPointerTypeSymbol() const override;
    bool HasConstDerivation() const;
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    std::u32string Id() override { return id; }
private:
    TypeSymbol* baseType;
    std::vector<Derivation> derivations;
    std::u32string id;
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_DERIVED_TYPE_SYMBOL_INCLUDED
