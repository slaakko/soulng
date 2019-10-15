// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_SCOPE_INCLUDED
#define SNGCPP_SYMBOLS_SCOPE_INCLUDED
#include <sngcpp/symbols/SymbolsApi.hpp>
#include <sngcpp/ast/Declaration.hpp>
#include <unordered_map>
#include <stdint.h>

namespace sngcpp { namespace symbols {

using namespace sngcpp::ast;

enum class ScopeLookup : uint8_t
{
    none = 0,
    this_ = 1 << 0,
    parent = 1 << 1,
    bases = 1 << 2,
    this_and_parent = this_ | parent,
    this_and_bases = this_ | bases,
    this_and_bases_and_parent = this_ | bases | parent
};

SNGCPP_SYMBOLS_API inline ScopeLookup operator&(ScopeLookup left, ScopeLookup right)
{
    return ScopeLookup(uint8_t(left) & uint8_t(right));
}

SNGCPP_SYMBOLS_API inline ScopeLookup operator|(ScopeLookup left, ScopeLookup right)
{
    return ScopeLookup(uint8_t(left) | uint8_t(right));
}

class Symbol;
class ContainerSymbol;

class SNGCPP_SYMBOLS_API Scope
{
public:
    Scope();
    Scope(const Scope&) = delete;
    Scope(Scope&&) = delete;
    Scope& operator=(const Scope&) = delete;
    Scope& operator=(Scope&&) = delete;
    virtual ~Scope();
    virtual Symbol* Lookup(const std::u32string& name) = 0;
    virtual Symbol* Lookup(const std::u32string& name, ScopeLookup scopeLookup) = 0;
    virtual Symbol* Lookup(const std::vector<std::u32string>& nameSequence, ScopeLookup scopeLoookup) = 0;
    Symbol* Lookup(Node* nameNode);
    Symbol* Lookup(Node* nameNode, ScopeLookup scopeLookup);
};

class SNGCPP_SYMBOLS_API ContainerScope : public Scope
{
public:
    ContainerScope();
    ContainerScope(ContainerSymbol* container_);
    ContainerSymbol* Container() { return container; }
    ContainerSymbol* GlobalNs();
    void Install(Symbol* symbol);
    Symbol* Lookup(const std::u32string& name) override;
    Symbol* Lookup(const std::u32string& name, ScopeLookup scopeLookup) override;
    Symbol* Lookup(const std::vector<std::u32string>& nameSequence, ScopeLookup scopeLoookup) override;
private:
    ContainerSymbol* container;
    std::unordered_map<std::u32string, Symbol*> symbolMap;
};

class SNGCPP_SYMBOLS_API FileScope : public Scope
{
public:
    void Install(ContainerScope* containerScope, UsingDirectiveNode& usingDirectiveNode);
    void Install(ContainerScope* containerScope, UsingDeclarationNode& usingDeclarationNode);
    Symbol* Lookup(const std::u32string& name) override;
    Symbol* Lookup(const std::u32string& name, ScopeLookup scopeLookup) override;
    Symbol* Lookup(const std::vector<std::u32string>& nameSequence, ScopeLookup scopeLoookup) override;
private:
    std::vector<ContainerScope*> containerScopes;
    std::unordered_map<std::u32string, Symbol*> aliasSymbolMap;
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_SCOPE_INCLUDED
