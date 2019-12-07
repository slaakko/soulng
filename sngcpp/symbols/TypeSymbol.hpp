// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_TYPE_SYMBOL_INCLUDED
#include <sngcpp/symbols/ContainerSymbol.hpp>
#include <sngcpp/ast/Class.hpp>

namespace sngcpp { namespace symbols {

using namespace sngcpp::ast;

class SNGCPP_SYMBOLS_API TypeSymbol : public ContainerSymbol
{
public:
    TypeSymbol(const Span& span_, const std::u32string& name_);
    bool IsTypeSymbol() const override { return true; }
    TypeSymbol* GetType() override { return this; }
    virtual TypeSymbol* BaseType() { return this; }
    virtual bool HasBaseClass(TypeSymbol* type, int& distance);
    virtual int MatchValue(TypeSymbol* argumentType);
    virtual bool IsSimpleTypeSymbol() const { return false; }
    virtual bool IsElaborateClassTypeSymbol() const { return false; }
    virtual bool IsDerivedTypeSymbol() const { return false; }
    virtual bool IsExternalTypeSymbol() const { return false; }
    virtual bool IsReferenceTypeSymbol() const { return false; }
    virtual bool IsTemplateParameterSymbol() const { return false; }
    virtual bool HasConstDerivation() const { return false; }
    virtual ClassKey GetClassKey() const { return ClassKey::class_; }
    std::u32string KindStr() override { return U"type"; }
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_TYPE_SYMBOL_INCLUDED
