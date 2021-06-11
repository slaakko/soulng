// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Scope.hpp>
#include <sngcpp20/symbols/ContainerSymbol.hpp>
#include <sngcpp20/symbols/NamespaceSymbol.hpp>
#include <sngcpp20/symbols/Exception.hpp>
#include <soulng/util/Unicode.hpp>
#include <stdexcept>

namespace sngcpp::symbols {

using namespace soulng::unicode;

std::string ScopeKindStr(ScopeKind kind)
{
    switch (kind)
    {
        case ScopeKind::namespaceScope: return "namespace scope";
        case ScopeKind::templateDeclarationScope: "temnplate declaration scope";
        case ScopeKind::classScope: return "class scope";
        case ScopeKind::enumerationScope: return "enumeration scope";
        case ScopeKind::functionScope: return "function scope";
        case ScopeKind::blockScope: return "block scope";
        case ScopeKind::usingDeclarationScope: return "using declaration scope";
        case ScopeKind::usingDirectiveScope: return "using directive scope";
    }
    return "unknown scope";
}

Scope::Scope() : kind()
{
}

Scope::~Scope()
{
}

void Scope::Install(Symbol* symbol)
{
    auto it = symbolMap.find(symbol->Name());
    if (it != symbolMap.cend())
    {
        Symbol* existingSymbol = it->second;
        if (existingSymbol != symbol)
        {
            throw std::runtime_error("cannot install symbol '" + ToUtf8(symbol->FullName()) + "' to " + ScopeKindStr(kind) + " '" + FullName() + "': name conflicts with existing symbol '" + 
                ToUtf8(existingSymbol->FullName()) + "'");
        }
        else
        {
            return;
        }
    }
    symbolMap[symbol->Name()] = symbol;
}

void Scope::Uninstall(Symbol* symbol)
{
    symbolMap.erase(symbol->Name());
}

Symbol* Scope::Lookup(const std::u32string& id, ScopeLookup scopeLookup, const SourcePos& sourcePos, Context* context) const
{
    std::vector<Symbol*> symbols;
    Lookup(id, scopeLookup, symbols);
    if (symbols.empty())
    {
        return nullptr;
    }
    else if (symbols.size() == 1)
    {
        return symbols.front();
    }
    else
    {
        std::string errorMessage = "ambiguous reference to symbol '" + ToUtf8(id) + "': could be:\n";
        bool first = true;
        for (Symbol* symbol : symbols)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                errorMessage.append(" or\n");
            }
            errorMessage.append(ToUtf8(symbol->FullName()));
        }
        throw Exception(errorMessage, sourcePos, context);
    }
}

void Scope::Lookup(const std::u32string& id, ScopeLookup scopeLookup, std::vector<Symbol*>& symbols) const
{
    if ((scopeLookup & ScopeLookup::thisScope) != ScopeLookup::none)
    {
        auto it = symbolMap.find(id);
        if (it != symbolMap.cend())
        {
            Symbol* symbol = it->second;
            if (std::find(symbols.begin(), symbols.end(), symbol) == symbols.end())
            {
                symbols.push_back(symbol);
            }
        }
    }
}

void Scope::AddSymbol(Symbol* symbol, const SourcePos& sourcePos, Context* context)
{
    throw Exception("cannot declare symbol '" + ToUtf8(symbol->Name()) + "' in " + ScopeKindStr(kind) + " '" + FullName() + "'", sourcePos, context);
}

void Scope::RemoveSymbol(Symbol* symbol)
{
    throw std::runtime_error("could not remove symbol");
}

ContainerScope::ContainerScope() : Scope(), parentScope(nullptr), usingDeclarationScope(nullptr), containerSymbol(nullptr)
{
}

void ContainerScope::AddBaseScope(ContainerScope* baseScope)
{
    if (std::find(baseScopes.begin(), baseScopes.end(), baseScope) == baseScopes.end())
    {
        baseScopes.push_back(baseScope);
    }
}

std::string ContainerScope::FullName() const
{
    if (Kind() == ScopeKind::blockScope)
    {
        return std::string();
    }
    return ToUtf8(containerSymbol->FullName());
}

void ContainerScope::Lookup(const std::u32string& id, ScopeLookup scopeLookup, std::vector<Symbol*>& symbols) const
{
    Scope::Lookup(id, scopeLookup, symbols);
    if ((scopeLookup & ScopeLookup::parentScope) != ScopeLookup::none)
    {
        if (symbols.empty())
        {
            if (parentScope)
            {
                parentScope->Lookup(id, scopeLookup, symbols);
            }
        }
    }
    if ((scopeLookup & ScopeLookup::baseScope) != ScopeLookup::none)
    {
        if (symbols.empty())
        {
            for (ContainerScope* baseScope : baseScopes)
            {
                baseScope->Lookup(id, scopeLookup, symbols);
            }
        }
    }
    if ((scopeLookup & ScopeLookup::usingScope) != ScopeLookup::none)
    {
        if (usingDeclarationScope)
        {
            usingDeclarationScope->Lookup(id, scopeLookup, symbols);
        }
        for (Scope* usingDirectiveScope : usingDirectiveScopes)
        {
            usingDirectiveScope->Lookup(id, scopeLookup, symbols);
        }
    }
}

void ContainerScope::AddUsingDeclaration(Symbol* usingDeclaration)
{
    // todo: check rules for adding a using declaration to various kind of scopes
    if (!usingDeclarationScope)
    {
        usingDeclarationScope = new UsingDeclarationScope(this);
        scopes.push_back(std::unique_ptr<Scope>(usingDeclarationScope));
    }
    usingDeclarationScope->Install(usingDeclaration);
}

void ContainerScope::AddUsingDirective(NamespaceSymbol* ns, const SourcePos& sourcePos, Context* context)
{
    if (Kind() == ScopeKind::namespaceScope || Kind() == ScopeKind::blockScope)
    {
        for (UsingDirectiveScope* scope : usingDirectiveScopes)
        {
            if (scope->Ns() == ns) return;
        }
        UsingDirectiveScope* usingDirectiveScope = new UsingDirectiveScope(ns);
        scopes.push_back(std::unique_ptr<Scope>(usingDirectiveScope));
        usingDirectiveScopes.push_back(usingDirectiveScope);
    }
    else
    {
        throw Exception("cannot add using directive to " + ScopeKindStr(Kind()), sourcePos, context);
    }
}

void ContainerScope::AddSymbol(Symbol* symbol, const SourcePos& sourcePos, Context* context)
{
    if (!symbol->IsValidDeclarationScope(Kind()))
    {
        throw Exception("cannot declare symbol '" + ToUtf8(symbol->Name()) + "' in " + ScopeKindStr(Kind()) + " '" + FullName() + "'", sourcePos, context);
    }
    containerSymbol->AddSymbol(symbol, sourcePos, context); 
}

void ContainerScope::RemoveSymbol(Symbol* symbol)
{

}

UsingDeclarationScope::UsingDeclarationScope(ContainerScope* parentScope_) : Scope(), parentScope(parentScope_)
{
    SetKind(ScopeKind::usingDeclarationScope);
}

std::string UsingDeclarationScope::FullName() const
{
    return parentScope->FullName();
}

void UsingDeclarationScope::Lookup(const std::u32string& id, ScopeLookup scopeLookup, std::vector<Symbol*>& symbols) const
{
    return Scope::Lookup(id, ScopeLookup::thisScope, symbols);
}

UsingDirectiveScope::UsingDirectiveScope(NamespaceSymbol* ns_) : Scope(), ns(ns_)
{
    SetKind(ScopeKind::usingDirectiveScope);
}

void UsingDirectiveScope::Lookup(const std::u32string& id, ScopeLookup scopeLookup, std::vector<Symbol*>& symbols) const
{
    ns->GetScope().Lookup(id, scopeLookup, symbols);
}

std::string UsingDirectiveScope::FullName() const
{
    return ToUtf8(ns->FullName());
}

} // sngcpp::symbols
