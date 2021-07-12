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
class TemplateDeclarationSymbol;
class ClassGroupSymbol;
class FunctionGroupSymbol; 
class ConceptGroupSymbol;
class VariableGroupSymbol;
class AliasGroupSymbol;

enum class ScopeKind : int
{
    none, namespaceScope, templateDeclarationScope, classScope, enumerationScope, functionScope, blockScope, usingDeclarationScope, usingDirectiveScope
};

SYMBOLS_API std::string ScopeKindStr(ScopeKind kind);

enum class SymbolGroupKind;

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
    void Install(Symbol* symbol, SymbolGroupKind symbolGroupKind);
    void Uninstall(Symbol* symbol, SymbolGroupKind symbolGroupKind);
    Symbol* Lookup(const std::u32string& id, SymbolGroupKind symbolGroupKind, ScopeLookup scopeLookup, const SourcePos& sourcePos, Context* context) const;
    virtual std::string FullName() const = 0;
    virtual bool IsContainerScope() const { return false; }
    virtual Symbol* GetSymbol() { return nullptr; }
    virtual void Lookup(const std::u32string& id, SymbolGroupKind symbolGroupKinds, ScopeLookup scopeLookup, std::vector<Symbol*>& symbols) const;
    virtual void AddSymbol(Symbol* symbol, SymbolGroupKind symbolGroupKind, const SourcePos& sourcePos, Scope* groupScope, Context* context);
    virtual void RemoveSymbol(Symbol* symbol, SymbolGroupKind symbolGroupKind);
    virtual Scope* ParentScope() const { return nullptr; }
    virtual void SetParentScope(Scope* parentScope_);
    virtual void AddBaseScope(Scope* baseScope, const SourcePos& sourcePos, Context* context);
    virtual void AddUsingDeclaration(Symbol* usingDeclaration, const SourcePos& sourcePos, Context* context);
    virtual void AddUsingDirective(NamespaceSymbol* ns, const SourcePos& sourcePos, Context* context);
    virtual ClassGroupSymbol* GetOrInsertClassGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context);
    virtual FunctionGroupSymbol* GetOrInsertFunctionGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context);
    virtual ConceptGroupSymbol* GetOrInsertConceptGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context);
    virtual VariableGroupSymbol* GetOrInsertVariableGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context);
    virtual AliasGroupSymbol* GetOrInsertAliasGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context);
private:
    ScopeKind kind;
    std::map<std::pair<std::u32string, SymbolGroupKind>, Symbol*> symbolMap;
};

class SYMBOLS_API ContainerScope : public Scope
{
public:
    ContainerScope();
    ContainerScope(const ContainerScope&) = delete;
    ContainerScope& operator=(const ContainerScope&) = delete;
    Scope* ParentScope() const override { return parentScope; }
    void SetParentScope(Scope* parentScope_) override { parentScope = parentScope_; }
    bool IsContainerScope() const override { return true; }
    void AddBaseScope(Scope* baseScope, const SourcePos& sourcePos, Context* context) override;
    Symbol* GetSymbol() override;
    ContainerSymbol* GetContainerSymbol() const { return containerSymbol; }
    void SetContainerSymbol(ContainerSymbol* containerSymbol_) { containerSymbol = containerSymbol_; }
    void AddUsingDeclaration(Symbol* usingDeclaration, const SourcePos& sourcePos, Context* context) override;
    void AddUsingDirective(NamespaceSymbol* ns, const SourcePos& sourcePos, Context* context) override;
    std::string FullName() const override;
    void Lookup(const std::u32string& id, SymbolGroupKind symbolGroupKinds, ScopeLookup scopeLookup, std::vector<Symbol*>& symbols) const override;
    void AddSymbol(Symbol* symbol, SymbolGroupKind symbolGroupKind, const SourcePos& sourcePos, Scope* groupScope, Context* context) override;
    void RemoveSymbol(Symbol* symbol, SymbolGroupKind symbolGroupKind) override;
    ClassGroupSymbol* GetOrInsertClassGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context) override;
    FunctionGroupSymbol* GetOrInsertFunctionGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context) override;
    ConceptGroupSymbol* GetOrInsertConceptGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context) override;
    VariableGroupSymbol* GetOrInsertVariableGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context) override;
    AliasGroupSymbol* GetOrInsertAliasGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context) override;
private:
    Scope* parentScope;
    std::vector<Scope*> baseScopes;
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
    void Lookup(const std::u32string& id, SymbolGroupKind symbolGroupKind, ScopeLookup scopeLookup, std::vector<Symbol*>& symbols) const override;
private:
    ContainerScope* parentScope;
};

class SYMBOLS_API UsingDirectiveScope : public Scope
{
public:
    UsingDirectiveScope(NamespaceSymbol* ns_);
    void Lookup(const std::u32string& id, SymbolGroupKind symbolGroupKind, ScopeLookup scopeLookup, std::vector<Symbol*>& symbols) const override;
    std::string FullName() const override;
    NamespaceSymbol* Ns() const { return ns; }
private:
    NamespaceSymbol* ns;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_SCOPE_INCLUDED
