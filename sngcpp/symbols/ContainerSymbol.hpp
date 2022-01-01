// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_CONTAINER_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_CONTAINER_SYMBOL_INCLUDED
#include <sngcpp/symbols/Symbol.hpp>
#include <sngcpp/symbols/Scope.hpp>

namespace sngcpp { namespace symbols {

class FunctionGroupSymbol;
class ClassGroupSymbol;

struct SNGCPP_SYMBOLS_API ByName
{
    bool operator()(Symbol* left, Symbol* right) const
    {
        return left->NameBefore(right);
    }
};

class SNGCPP_SYMBOLS_API ContainerSymbol : public Symbol
{
public:
    ContainerSymbol(const Span& span_, const std::u32string& name_);
    virtual void AddMember(std::unique_ptr<Symbol>&& member);
    const std::vector<std::unique_ptr<Symbol>>& Members() const { return members; }
    ContainerScope* GetContainerScope() override { return &containerScope; }
    bool IsContainerSymbol() const override { return true; }
    virtual int NumBases() const { return 0; }
    virtual ContainerSymbol* GetBase(int i) const { return nullptr; }
    std::unique_ptr<sngxml::dom::Element> Namespaces() override;
    std::unique_ptr<sngxml::dom::Element> Classes() override;
    std::unique_ptr<sngxml::dom::Element> Constructors() override;
    std::unique_ptr<sngxml::dom::Element> Functions() override;
    std::unique_ptr<sngxml::dom::Element> EnumTypes() override;
    std::unique_ptr<sngxml::dom::Element> Enumerators() override;
    std::unique_ptr<sngxml::dom::Element> Typedefs() override;
    std::unique_ptr<sngxml::dom::Element> Variables() override;
    std::unique_ptr<sngxml::dom::Element> Grammars() override;
private:
    ContainerScope containerScope;
    std::vector<std::unique_ptr<Symbol>> members;
    FunctionGroupSymbol* MakeFunctionGroupSymbol(const Span& span_, const std::u32string& groupName);
    ClassGroupSymbol* MakeClassGroupSymbol(const Span& span_, const std::u32string& groupName);
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_CONTAINER_SYMBOL_INCLUDED
