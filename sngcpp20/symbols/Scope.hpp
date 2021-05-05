// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_SCOPE_INCLUDED
#define SNGCPP_SYMBOLS_SCOPE_INCLUDED
#include <sngcpp20/symbols/SymbolsApi.hpp>
#include <map>
#include <string>
#include <vector>

namespace sngcpp::symbols {

class Symbol;
class ContainerSymbol;

enum class ScopeLookup : int
{
    none = 0,
    thisScope = 1 << 0,
    parentScope = 1 << 1,
    baseScope = 1 << 2,
    thisAndParentScope = thisScope | parentScope,
    thisAndBaseScope = thisScope | baseScope,
    thisAndBaseAndParentScope = thisScope | baseScope | parentScope
};

inline ScopeLookup operator|(ScopeLookup left, ScopeLookup right)
{
    return ScopeLookup(int(left) | int(right));
}

inline ScopeLookup operator&(ScopeLookup left, ScopeLookup right)
{
    return ScopeLookup(int(left) & int(right));
}

inline ScopeLookup operator~(ScopeLookup lookup)
{
    return ScopeLookup(~int(lookup));
}

class SYMBOLS_API Scope
{
public:
    Scope();
    Scope* ParentScope() const { return parentScope; }
    void SetParentScope(Scope* parentScope_) { parentScope = parentScope_;  }
    ContainerSymbol* GetContainerSymbol() const { return containerSymbol; }
    void SetContainerSymbol(ContainerSymbol* containerSymbol_) { containerSymbol = containerSymbol_; }
    void Install(Symbol* symbol);
    Symbol* Lookup(const std::u32string& id, ScopeLookup scopeLookup) const;
private:
    std::map<std::u32string, Symbol*> symbolMap;
    Scope* parentScope;
    ContainerSymbol* containerSymbol;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_SCOPE_INCLUDED
