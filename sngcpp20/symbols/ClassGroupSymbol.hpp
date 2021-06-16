// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_CLASS_GROUP_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_CLASS_GROUP_SYMBOL_INCLUDED
#include <sngcpp20/symbols/Symbol.hpp>
#include <vector>

namespace sngcpp::symbols {

class ClassTypeSymbol;

class SYMBOLS_API ClassGroupSymbol : public Symbol
{
public:
    ClassGroupSymbol(const std::u32string& name_);
    bool IsClassGroupSymbol() const override { return true; }
    bool IsTypeSymbol() const override { return true; }
    std::string SymbolKindStr() const override { return "class group symbol"; }
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
    Scope* GetScope() override;
    void AddClass(ClassTypeSymbol* classTypeSymbol);
    ClassTypeSymbol* GetClass(int templateArity) const;
private:
    std::vector<ClassTypeSymbol*> classes;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_CLASS_GROUP_SYMBOL_INCLUDED
