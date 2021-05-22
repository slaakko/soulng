// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_SCOPE_INCLUDED
#define SNGCPP_SYMBOLS_SCOPE_INCLUDED
#include <sngcpp20/symbols/SymbolsApi.hpp>
#include <sngcpp20/symbols/Context.hpp>
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace sngcpp::symbols {

using soulng::lexer::SourcePos;

class Symbol;
class ContainerSymbol;
class NamespaceSymbol;
class UsingDirectiveScope;

enum class ScopeKind : int
{
    none, namespaceScope, classScope, enumerationScope, functionScope, blockScope, usingDeclarationScope, usingDirectiveScope
};

SYMBOLS_API std::string ScopeKindStr(ScopeKind kind);

enum class ScopeLookup : int
{
    none = 0,
    thisScope = 1 << 0,
    parentScope = 1 << 1,
    baseScope = 1 << 2,
    thisAndParentScope = thisScope | parentScope,
    thisAndBaseScopes = thisScope | baseScope,
    thisAndBaseAndParentScope = thisScope | baseScope | parentScope,
    usingScope = 1 << 3,
    allScopes = thisAndBaseAndParentScope | usingScope
};

SYMBOLS_API inline ScopeLookup operator|(ScopeLookup left, ScopeLookup right)
{
    return ScopeLookup(int(left) | int(right));
}

SYMBOLS_API inline ScopeLookup operator&(ScopeLookup left, ScopeLookup right)
{
    return ScopeLookup(int(left) & int(right));
}

SYMBOLS_API inline ScopeLookup operator~(ScopeLookup lookup)
{
    return ScopeLookup(~int(lookup));
}

class SYMBOLS_API Scope
{
public:
    Scope();
    virtual ~Scope();
    ScopeKind Kind() const { return kind; }
    void SetKind(ScopeKind kind_) { kind = kind_; }
    void Install(Symbol* symbol);
    Symbol* Lookup(const std::u32string& id, ScopeLookup scopeLookup, const SourcePos& sourcePos, Context* context) const;
    virtual std::string FullName() const = 0;
    virtual void Lookup(const std::u32string& id, ScopeLookup scopeLookup, std::vector<Symbol*>& symbols) const;
    virtual void AddSymbol(Symbol* symbol, const SourcePos& sourcePos, Context* context);
private:
    ScopeKind kind;
    std::map<std::u32string, Symbol*> symbolMap;
};

class SYMBOLS_API ContainerScope : public Scope
{
public:
    ContainerScope();
    ContainerScope(const ContainerScope&) = delete;
    ContainerScope& operator=(const ContainerScope&) = delete;
    ContainerScope* ParentScope() const { return parentScope; }
    void SetParentScope(ContainerScope* parentScope_) { parentScope = parentScope_; }
    void AddBaseScope(ContainerScope* baseScope);
    ContainerSymbol* GetContainerSymbol() const { return containerSymbol; }
    void SetContainerSymbol(ContainerSymbol* containerSymbol_) { containerSymbol = containerSymbol_; }
    void AddUsingDeclaration(Symbol* usingDeclaration);
    void AddUsingDirective(NamespaceSymbol* ns, const SourcePos& sourcePos, Context* context);
    std::string FullName() const override;
    void Lookup(const std::u32string& id, ScopeLookup scopeLookup, std::vector<Symbol*>& symbols) const override;
    void AddSymbol(Symbol* symbol, const SourcePos& sourcePos, Context* context) override;
private:
    ContainerScope* parentScope;
    std::vector<ContainerScope*> baseScopes;
    Scope* usingDeclarationScope;
    ContainerSymbol* containerSymbol;
    std::vector<UsingDirectiveScope*> usingDirectiveScopes;
    std::vector<std::unique_ptr<Scope>> scopes;
};

class SYMBOLS_API UsingDeclarationScope : public Scope
{
public:
    UsingDeclarationScope(ContainerScope* parentScope_);
    std::string FullName() const override;
    void Lookup(const std::u32string& id, ScopeLookup scopeLookup, std::vector<Symbol*>& symbols) const override;
private:
    ContainerScope* parentScope;
};

class SYMBOLS_API UsingDirectiveScope : public Scope
{
public:
    UsingDirectiveScope(NamespaceSymbol* ns_);
    void Lookup(const std::u32string& id, ScopeLookup scopeLookup, std::vector<Symbol*>& symbols) const override;
    std::string FullName() const override;
    NamespaceSymbol* Ns() const { return ns; }
private:
    NamespaceSymbol* ns;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_SCOPE_INCLUDED
