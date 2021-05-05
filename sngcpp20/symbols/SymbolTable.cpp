// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/symbols/ClassTypeSymbol.hpp>
#include <soulng/util/Unicode.hpp>
#include <stdexcept>

namespace sngcpp::symbols {

using namespace soulng::unicode;

SymbolTable::SymbolTable() : globalNs(std::u32string()), currentScope(&globalNs.GetScope())
{
}

Node* SymbolTable::GetNodeNothrow(Symbol* symbol) const
{
    auto it = symbolNodeMap.find(symbol);
    if (it != symbolNodeMap.cend())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}

Node* SymbolTable::GetNode(Symbol* symbol) const
{
    Node* node = GetNodeNothrow(symbol);
    if (node)
    {
        return node;
    }
    else
    {
        throw std::runtime_error("node for symbol '" + ToUtf8(symbol->Name()) + "' not found");
    }
}

Symbol* SymbolTable::GetSymbolNothrow(Node* node) const
{
    auto it = nodeSymbolMap.find(node);
    if (it != nodeSymbolMap.cend())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}

Symbol* SymbolTable::GetSymbol(Node* node) const
{
    Symbol* symbol = GetSymbolNothrow(node);
    if (symbol)
    {
        return symbol;
    }
    else
    {
        throw std::runtime_error("symbol for node not found");
    }
}

void SymbolTable::MapNode(Node* node, Symbol* symbol)
{
    nodeSymbolMap[node] = symbol;
    symbolNodeMap[symbol] = node;
}

Symbol* SymbolTable::Lookup(std::u32string& name) const
{
    return currentScope->Lookup(name, ScopeLookup::thisAndParentScope);
}

void SymbolTable::BeginScope(Scope& scope)
{
    scopeStack.push(currentScope);
    currentScope = &scope;
}

void SymbolTable::EndScope()
{
    if (scopeStack.empty())
    {
        throw std::runtime_error("scope stack is empty");
    }
    currentScope = scopeStack.top();
    scopeStack.pop();
}

void SymbolTable::BeginClass(Node* node)
{
    ClassTypeSymbol* classTypeSymbol = new ClassTypeSymbol(node->Str());
    ContainerSymbol* containerSymbol = currentScope->GetContainerSymbol();
    containerSymbol->AddSymbol(classTypeSymbol);
    MapNode(node, classTypeSymbol);
    BeginScope(classTypeSymbol->GetScope());
}

void SymbolTable::EndClass()
{
    EndScope();
}

} // sngcpp::symbols
