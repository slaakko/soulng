// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/Scope.hpp>
#include <sngcpp/symbols/ContainerSymbol.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <sngcpp/ast/Expression.hpp>
#include <unordered_set>

namespace sngcpp { namespace symbols {

class NameResolver : public Visitor
{
public:
    void Visit(IdentifierNode& identifierNode) override;
    void Visit(NestedIdNode& nestedIdNode) override;
    const std::vector<std::u32string>& NameSequence() const { return nameSequence; }
private:
    std::vector<std::u32string> nameSequence;
};

void NameResolver::Visit(IdentifierNode& identifierNode)
{
    nameSequence.push_back(identifierNode.Identifier());
}

void NameResolver::Visit(NestedIdNode& nestedIdNode)
{
    if (nestedIdNode.Left())
    {
        nestedIdNode.Left()->Accept(*this);
    }
    else
    {
        nameSequence.push_back(std::u32string());
    }
    nestedIdNode.Right()->Accept(*this);
}

Scope::Scope()
{
}

Scope::~Scope()
{
}

Symbol* Scope::Lookup(Node* nameNode)
{
    return Lookup(nameNode, ScopeLookup::this_);
}

Symbol* Scope::Lookup(Node* nameNode, ScopeLookup scopeLookup)
{
    NameResolver nameResolver;
    nameNode->Accept(nameResolver);
    if (nameResolver.NameSequence().empty())
    {
        return nullptr;
    }
    else if (nameResolver.NameSequence().size() == 1)
    {
        return Lookup(nameResolver.NameSequence().front(), scopeLookup);
    }
    else
    {
        return Lookup(nameResolver.NameSequence(), scopeLookup);
    }
}

ContainerScope::ContainerScope() : container()
{
}

ContainerScope::ContainerScope(ContainerSymbol* container_) : container(container_)
{
}

ContainerSymbol* ContainerScope::GlobalNs()
{
    ContainerSymbol* globalNs = container;
    while (globalNs->Parent())
    {
        globalNs = globalNs->Parent();
    }
    return globalNs;
}

void ContainerScope::Install(Symbol* symbol)
{
    symbolMap[symbol->Name()] = symbol;
}

Symbol* ContainerScope::Lookup(const std::u32string& name)
{
    return Lookup(name, ScopeLookup::this_);
}

Symbol* ContainerScope::Lookup(const std::u32string& name, ScopeLookup scopeLookup)
{
    auto it = symbolMap.find(name);
    if (it != symbolMap.cend())
    {
        return it->second;
    }
    if ((scopeLookup & ScopeLookup::bases) != ScopeLookup::none)
    {
        int n = container->NumBases();
        for (int i = 0; i < n; ++i)
        {
            ContainerSymbol* baseSymbol = container->GetBase(i);
            ContainerScope* baseScope = baseSymbol->GetContainerScope();
            Symbol* s = baseScope->Lookup(name, scopeLookup);
            if (s)
            {
                return s;
            }
        }
    }
    if ((scopeLookup & ScopeLookup::parent) != ScopeLookup::none)
    {
        ContainerSymbol* parent = container->Parent();
        if (parent)
        {
            ContainerScope* parentScope = parent->GetContainerScope();
            Symbol* s = parentScope->Lookup(name, scopeLookup);
            if (s)
            {
                return s;
            }
        }
    }
    return nullptr;
}

Symbol* ContainerScope::Lookup(const std::vector<std::u32string>& nameSequence, ScopeLookup scopeLoookup)
{
    ContainerScope* scope = this;
    Symbol* s = nullptr;
    int n = nameSequence.size();
    bool allComponentsMatched = true;
    for (int i = 0; i < n; ++i)
    {
        const std::u32string& name = nameSequence[i];
        if (name.empty())
        {
            scope = GlobalNs()->GetContainerScope();
        }
        else if (scope)
        {
            s = scope->Lookup(name, ScopeLookup::this_);
            if (s)
            {
                scope = s->GetContainerScope();
            }
            else
            {
                allComponentsMatched = false;
            }
        }
    }
    if (!s || !allComponentsMatched)
    {
        if ((scopeLoookup & ScopeLookup::parent) != ScopeLookup::none)
        {
            ContainerSymbol* parent = container->Parent();
            if (parent)
            {
                return parent->GetContainerScope()->Lookup(nameSequence, scopeLoookup);
            }
            else
            {
                return nullptr;
            }
        }
    }
    return s;
}

void FileScope::Install(ContainerScope* containerScope, UsingDirectiveNode& usingDirectiveNode)
{
    Symbol* symbol = static_cast<Scope*>(containerScope)->Lookup(usingDirectiveNode.NamespaceName(), ScopeLookup::this_and_parent);
    if (symbol)
    {
        if (symbol->IsNamespaceSymbol())
        {
            ContainerScope* containerScope = symbol->GetContainerScope();
            if (containerScope)
            {
                for (ContainerScope* scope : containerScopes)
                {
                    if (scope == containerScope) return;
                }
                containerScopes.push_back(containerScope);
            }
            else
            {
                throw std::runtime_error("container scope expected");
            }
        }
        else
        {
            throw std::runtime_error("namespace symbol expected");
        }
    }
}

void FileScope::Install(ContainerScope* containerScope, UsingDeclarationNode& usingDeclarationNode)
{
    Symbol* symbol = static_cast<Scope*>(containerScope)->Lookup(usingDeclarationNode.QualifiedId(), ScopeLookup::this_and_parent);
    if (symbol)
    {
        aliasSymbolMap[symbol->Name()] = symbol;
    }
}

Symbol* FileScope::Lookup(const std::u32string& name)
{
    return Lookup(name, ScopeLookup::this_);
}

Symbol* FileScope::Lookup(const std::u32string& name, ScopeLookup scopeLookup)
{
    if (scopeLookup != ScopeLookup::this_)
    {
        throw std::runtime_error("file scope supports only this scope lookup");
    }
    std::unordered_set<Symbol*> foundSymbols;
    auto it = aliasSymbolMap.find(name);
    if (it != aliasSymbolMap.cend())
    {
        Symbol* symbol = it->second;
        foundSymbols.insert(symbol);
    }
    else
    {
        for (ContainerScope* containerScope : containerScopes)
        {
            Symbol* symbol = containerScope->Lookup(name, ScopeLookup::this_);
            if (symbol)
            {
                foundSymbols.insert(symbol);
            }
        }
    }
    if (foundSymbols.empty())
    {
        return nullptr;
    }
    else if (foundSymbols.size() > 1)
    {
        return nullptr;
    }
    else
    {
        return *foundSymbols.begin();
    }
}

Symbol* FileScope::Lookup(const std::vector<std::u32string>& nameSequence, ScopeLookup scopeLoookup)
{
    std::unordered_set<Symbol*> foundSymbols;
    for (ContainerScope* containerScope : containerScopes)
    {
        Symbol* symbol = containerScope->Lookup(nameSequence, ScopeLookup::this_);
        if (symbol)
        {
            foundSymbols.insert(symbol);
        }
    }
    if (foundSymbols.empty())
    {
        return nullptr;
    }
    else if (foundSymbols.size() > 1)
    {
        return nullptr;
    }
    else
    {
        return *foundSymbols.begin();
    }
}

} } // namespace sngcpp::symbols
