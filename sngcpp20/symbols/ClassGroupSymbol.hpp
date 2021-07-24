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
class TypeSymbol;

enum class MatchKind
{
    exact, partial
};

struct ScoreLess
{
    bool operator()(const std::pair<Symbol*, int>& left, const std::pair<Symbol*, int>& right) const;
};

class SYMBOLS_API ClassGroupSymbol : public Symbol
{
public:
    ClassGroupSymbol(const std::u32string& name_);
    bool IsTypeSymbol() const override { return true; }
    SymbolGroupKind GetSymbolGroupKind() const override { return SymbolGroupKind::typeSymbolGroup; }
    std::string SymbolKindStr() const override { return "class group symbol"; }
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
    void AddClass(ClassTypeSymbol* classTypeSymbol);
    ClassTypeSymbol* GetClass(const std::vector<Symbol*>& templateArguments, MatchKind matchKind, bool& exact) const;
    ClassTypeSymbol* GetClassTemplate() const;
private:
    std::vector<ClassTypeSymbol*> classes;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_CLASS_GROUP_SYMBOL_INCLUDED
