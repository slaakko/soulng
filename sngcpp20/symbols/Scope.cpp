// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Scope.hpp>
#include <sngcpp20/symbols/ClassGroupSymbol.hpp>
#include <sngcpp20/symbols/ConceptGroupSymbol.hpp>
#include <sngcpp20/symbols/ContainerSymbol.hpp>
#include <sngcpp20/symbols/FunctionGroupSymbol.hpp>
#include <sngcpp20/symbols/VariableGroupSymbol.hpp>
#include <sngcpp20/symbols/AliasGroupSymbol.hpp>
#include <sngcpp20/symbols/NamespaceSymbol.hpp>
#include <sngcpp20/symbols/TemplateDeclarationSymbol.hpp>
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
    auto it = symbolMap.find(symbol->InstallationName());
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
    symbolMap[symbol->InstallationName()] = symbol;
}

void Scope::Uninstall(Symbol* symbol)
{
    symbolMap.erase(symbol->InstallationName());
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
    if ((scopeLookup & ScopeLookup::thisAndBaseScopes) != ScopeLookup::none)
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

void Scope::AddSymbol(Symbol* symbol, const SourcePos& sourcePos, Scope* groupScope, Context* context)
{
    throw Exception("cannot declare symbol '" + ToUtf8(symbol->Name()) + "' in " + ScopeKindStr(kind) + " '" + FullName() + "'", sourcePos, context);
}

void Scope::RemoveSymbol(Symbol* symbol)
{
    throw std::runtime_error("could not remove symbol");
}

void Scope::SetParentScope(Scope* parentScope_)
{
    throw std::runtime_error("could not set parent scope");
}

void Scope::AddBaseScope(Scope* baseScope, const SourcePos& sourcePos, Context* context)
{
    throw Exception("cannot add base class scope to " + ScopeKindStr(kind) + " '" + FullName() + "'", sourcePos, context);
}

void Scope::AddUsingDeclaration(Symbol* usingDeclaration, const SourcePos& sourcePos, Context* context)
{
    throw Exception("cannot add using declaration '" + ToUtf8(usingDeclaration->FullName()) + "' to " + ScopeKindStr(kind) + " '" + FullName() + "'", sourcePos, context);
}

void Scope::AddUsingDirective(NamespaceSymbol* ns, const SourcePos& sourcePos, Context* context)
{
    throw Exception("cannot add using directive '" + ToUtf8(ns->FullName()) + "' to " + ScopeKindStr(kind) + " '" + FullName() + "'", sourcePos, context);
}

ClassGroupSymbol* Scope::GetOrInsertClassGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context)
{
    throw Exception("cannot add class group '" + ToUtf8(name) + "' to " + ScopeKindStr(kind) + " '" + FullName() + "'", sourcePos, context);
}

FunctionGroupSymbol* Scope::GetOrInsertFunctionGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context)
{
    throw Exception("cannot add function group '" + ToUtf8(name) + "' to " + ScopeKindStr(kind) + " '" + FullName() + "'", sourcePos, context);
}

ConceptGroupSymbol* Scope::GetOrInsertConceptGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context)
{
    throw Exception("cannot add concept group '" + ToUtf8(name) + "' to " + ScopeKindStr(kind) + " '" + FullName() + "'", sourcePos, context);
}

VariableGroupSymbol* Scope::GetOrInsertVariableGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context)
{
    throw Exception("cannot add variable group '" + ToUtf8(name) + "' to " + ScopeKindStr(kind) + " '" + FullName() + "'", sourcePos, context);
}

AliasGroupSymbol* Scope::GetOrInsertAliasGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context)
{
    throw Exception("cannot add alias group '" + ToUtf8(name) + "' to " + ScopeKindStr(kind) + " '" + FullName() + "'", sourcePos, context);
}

ContainerScope::ContainerScope() : Scope(), parentScope(nullptr), usingDeclarationScope(nullptr), containerSymbol(nullptr)
{
}

void ContainerScope::AddBaseScope(Scope* baseScope, const SourcePos& sourcePos, Context* context)
{
    if (baseScope->IsContainerScope())
    {
        ContainerScope* containerScope = static_cast<ContainerScope*>(baseScope);
        ContainerSymbol* baseClassSymbol = containerScope->GetContainerSymbol();
        Install(baseClassSymbol);
    }
    baseScopes.push_back(baseScope);
}

Symbol* ContainerScope::GetSymbol()
{
    return containerSymbol; 
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
            for (Scope* baseScope : baseScopes)
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

void ContainerScope::AddUsingDeclaration(Symbol* usingDeclaration, const SourcePos& sourcePos, Context* context)
{
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

void ContainerScope::AddSymbol(Symbol* symbol, const SourcePos& sourcePos, Scope* groupScope, Context* context)
{
    if (!symbol->IsValidDeclarationScope(Kind()))
    {
        throw Exception("cannot declare symbol '" + ToUtf8(symbol->Name()) + "' in " + ScopeKindStr(Kind()) + " '" + FullName() + "'", sourcePos, context);
    }
    containerSymbol->AddSymbol(symbol, sourcePos, groupScope, context); 
}

void ContainerScope::RemoveSymbol(Symbol* symbol)
{
}

ClassGroupSymbol* ContainerScope::GetOrInsertClassGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context)
{
    Symbol* symbol = Scope::Lookup(name, ScopeLookup::thisScope, sourcePos, context);
    if (symbol)
    {
        if (symbol->Kind() == SymbolKind::classGroupSymbol)
        {
            ClassGroupSymbol* classGroupSymbol = static_cast<ClassGroupSymbol*>(symbol);
            return classGroupSymbol;
        }
        else
        {
            std::string errorMessage = "name of class group '" + ToUtf8(name) + "' conflicts with earlier declaration of '" + symbol->SymbolKindStr() + " '" + ToUtf8(symbol->FullName()) + "'";
            throw Exception(errorMessage, sourcePos, context);
        }
    }
    else
    {
        ClassGroupSymbol* classGroupSymbol = new ClassGroupSymbol(name);
        AddSymbol(classGroupSymbol, sourcePos, this, context);
        return classGroupSymbol;
    }
}

FunctionGroupSymbol* ContainerScope::GetOrInsertFunctionGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context)
{
    Symbol* symbol = Scope::Lookup(name, ScopeLookup::thisScope, sourcePos, context);
    if (symbol)
    {
        if (symbol->Kind() == SymbolKind::functionGroupSymbol)
        {
            FunctionGroupSymbol* functionGroupSymbol = static_cast<FunctionGroupSymbol*>(symbol);
            return functionGroupSymbol;
        }
        else
        {
            std::string errorMessage = "name of function group '" + ToUtf8(name) + "' conflicts with earlier declaration of '" + symbol->SymbolKindStr() + " '" + ToUtf8(symbol->FullName()) + "'";
            throw Exception(errorMessage, sourcePos, context);
        }
    }
    else
    {
        FunctionGroupSymbol* functionGroupSymbol = new FunctionGroupSymbol(name);
        AddSymbol(functionGroupSymbol, sourcePos, this, context);
        return functionGroupSymbol;
    }
}

ConceptGroupSymbol* ContainerScope::GetOrInsertConceptGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context)
{
    Symbol* symbol = Scope::Lookup(name, ScopeLookup::thisScope, sourcePos, context);
    if (symbol)
    {
        if (symbol->Kind() == SymbolKind::conceptGroupSymbol)
        {
            ConceptGroupSymbol* conceptGroupSymbol = static_cast<ConceptGroupSymbol*>(symbol);
            return conceptGroupSymbol;
        }
        else
        {
            std::string errorMessage = "name of concept group '" + ToUtf8(name) + "' conflicts with earlier declaration of '" + symbol->SymbolKindStr() + " '" + ToUtf8(symbol->FullName()) + "'";
            throw Exception(errorMessage, sourcePos, context);
        }
    }
    else
    {
        ConceptGroupSymbol* conceptGroupSymbol = new ConceptGroupSymbol(name);
        AddSymbol(conceptGroupSymbol, sourcePos, this, context);
        return conceptGroupSymbol;
    }
}

VariableGroupSymbol* ContainerScope::GetOrInsertVariableGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context)
{
    Symbol* symbol = Scope::Lookup(name, ScopeLookup::thisScope, sourcePos, context);
    if (symbol)
    {
        if (symbol->Kind() == SymbolKind::variableGroupSymbol)
        {
            VariableGroupSymbol* variableGroupSymbol = static_cast<VariableGroupSymbol*>(symbol);
            return variableGroupSymbol;
        }
        else
        {
            std::string errorMessage = "name of variable group '" + ToUtf8(name) + "' conflicts with earlier declaration of '" + symbol->SymbolKindStr() + " '" + ToUtf8(symbol->FullName()) + "'";
            throw Exception(errorMessage, sourcePos, context);
        }
    }
    else
    {
        VariableGroupSymbol* variableGroupSymbol = new VariableGroupSymbol(name);
        AddSymbol(variableGroupSymbol, sourcePos, this, context);
        return variableGroupSymbol;
    }
}

AliasGroupSymbol* ContainerScope::GetOrInsertAliasGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context)
{
    Symbol* symbol = Scope::Lookup(name, ScopeLookup::thisScope, sourcePos, context);
    if (symbol)
    {
        if (symbol->Kind() == SymbolKind::aliasGroupSymbol)
        {
            AliasGroupSymbol* aliasGroupSymbol = static_cast<AliasGroupSymbol*>(symbol);
            return aliasGroupSymbol;
        }
        else
        {
            std::string errorMessage = "name of alias group '" + ToUtf8(name) + "' conflicts with earlier declaration of '" + symbol->SymbolKindStr() + " '" + ToUtf8(symbol->FullName()) + "'";
            throw Exception(errorMessage, sourcePos, context);
        }
    }
    else
    {
        AliasGroupSymbol* aliasGroupSymbol = new AliasGroupSymbol(name);
        AddSymbol(aliasGroupSymbol, sourcePos, this, context);
        return aliasGroupSymbol;
    }
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
    ns->GetScope()->Lookup(id, scopeLookup, symbols);
}

std::string UsingDirectiveScope::FullName() const
{
    return ToUtf8(ns->FullName());
}

} // sngcpp::symbols
