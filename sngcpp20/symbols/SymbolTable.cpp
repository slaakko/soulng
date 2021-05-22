// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/symbols/ClassTypeSymbol.hpp>
#include <sngcpp20/symbols/CompoundTypeSymbol.hpp>
#include <sngcpp20/symbols/FunctionSymbol.hpp>
#include <sngcpp20/symbols/Exception.hpp>
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
    MapNode(node, symbol, MapKind::both);
}

void SymbolTable::MapNode(Node* node, Symbol* symbol, MapKind kind)
{
    if ((kind & MapKind::nodeToSymbol) != MapKind::none)
    {
        nodeSymbolMap[node] = symbol;
    }
    if ((kind & MapKind::symbolToNode) != MapKind::none)
    {
        symbolNodeMap[symbol] = node;
    }
}

Symbol* SymbolTable::Lookup(const std::u32string& name, const SourcePos& sourcePos, Context* context) const
{
    return currentScope->Lookup(name, ScopeLookup::allScopes, sourcePos, context);
}

void SymbolTable::PushScope()
{
    scopeStack.push(currentScope);
}

void SymbolTable::PopScope()
{
    if (scopeStack.empty())
    {
        throw std::runtime_error("scope stack is empty");
    }
    currentScope = scopeStack.top();
    scopeStack.pop();
}

void SymbolTable::BeginScope(Scope& scope)
{
    PushScope();
    currentScope = &scope;
}

void SymbolTable::EndScope()
{
    PopScope();
}

void SymbolTable::BeginClass(Node* node, Context* context)
{
    ClassTypeSymbol* classTypeSymbol = new ClassTypeSymbol(node->Str());
    currentScope->AddSymbol(classTypeSymbol, node->GetSourcePos(), context);
    MapNode(node, classTypeSymbol);
    BeginScope(classTypeSymbol->GetScope());
}

void SymbolTable::EndClass()
{
    EndScope();
}

void SymbolTable::BeginFunction(Node* node, TypeSymbol* returnType, Context* context)
{
    Symbol* symbol = currentScope->Lookup(node->Str(), ScopeLookup::thisScope, node->GetSourcePos(), context);
    if (symbol)
    {
        if (symbol->IsFunctionSymbol())
        {
            FunctionSymbol* functionSymbol = static_cast<FunctionSymbol*>(symbol);
            if (functionSymbol->ReturnType() != returnType->ReferredType())
            {
                throw Exception("function return type '" + ToUtf8(returnType->FullName()) + " conflicts with earlier declaration", node->GetSourcePos(), context);
            }
            MapNode(node, functionSymbol, MapKind::nodeToSymbol);
            BeginScope(functionSymbol->GetScope());
        }
        else
        {
            throw Exception("function declaration '" + ToUtf8(node->Str()) + "' conflicts with earlier declaration of " + symbol->SymbolKindStr() + " '" + ToUtf8(symbol->FullName()) + "'",
                node->GetSourcePos(), context);
        }
    }
    else
    {
        FunctionSymbol* functionSymbol = new FunctionSymbol(node->Str()); 
        functionSymbol->SetReturnType(returnType);
        currentScope->AddSymbol(functionSymbol, node->GetSourcePos(), context);
        MapNode(node, functionSymbol);
        BeginScope(functionSymbol->GetScope());
    }
}

void SymbolTable::EndFunction()
{
    EndScope();
}

TypeSymbol* SymbolTable::GetFundamentalTypeSymbol(FundamentalTypeKind kind)
{
    auto it = fundamentalTypeMap.find(static_cast<int>(kind));
    if (it != fundamentalTypeMap.cend())
    {
        return it->second;
    }
    else
    {
        TypeSymbol* fundamentalTypeSymbol = new FundamentalTypeSymbol(kind);
        fundamentalTypeMap[static_cast<int>(kind)] = fundamentalTypeSymbol;
        types.push_back(std::unique_ptr<TypeSymbol>(fundamentalTypeSymbol));
        return fundamentalTypeSymbol;
    }
}

TypeSymbol* SymbolTable::MakeConstType(TypeSymbol* baseTypeSymbol)
{
    auto it = constTypeMap.find(baseTypeSymbol);
    if (it != constTypeMap.cend())
    {
        return it->second;
    }
    else
    {
        TypeSymbol* constTypeSymbol = new ConstTypeSymbol(baseTypeSymbol);
        constTypeMap[baseTypeSymbol] = constTypeSymbol;
        types.push_back(std::unique_ptr<TypeSymbol>(constTypeSymbol));
        return constTypeSymbol;
    }
}

TypeSymbol* SymbolTable::MakeVolatileType(TypeSymbol* baseTypeSymbol)
{
    auto it = volatileTypeMap.find(baseTypeSymbol);
    if (it != volatileTypeMap.cend())
    {
        return it->second;
    }
    else
    {
        TypeSymbol* volatileTypeSymbol = new VolatileTypeSymbol(baseTypeSymbol);
        volatileTypeMap[baseTypeSymbol] = volatileTypeSymbol;
        types.push_back(std::unique_ptr<TypeSymbol>(volatileTypeSymbol));
        return volatileTypeSymbol;
    }
}

TypeSymbol* SymbolTable::MakePointerType(TypeSymbol* baseTypeSymbol)
{
    auto it = pointerTypeMap.find(baseTypeSymbol);
    if (it != pointerTypeMap.cend())
    {
        return it->second;
    }
    else
    {
        TypeSymbol* pointerTypeSymbol = new PointerTypeSymbol(baseTypeSymbol);
        pointerTypeMap[baseTypeSymbol] = pointerTypeSymbol;
        types.push_back(std::unique_ptr<TypeSymbol>(pointerTypeSymbol));
        return pointerTypeSymbol;
    }
}

TypeSymbol* SymbolTable::MakeLvalueRefType(TypeSymbol* baseTypeSymbol)
{
    auto it = lvalueRefTypeMap.find(baseTypeSymbol);
    if (it != lvalueRefTypeMap.cend())
    {
        return it->second;
    }
    else
    {
        TypeSymbol* lvalueRefTypeSymbol = new LvalueRefTypeSymbol(baseTypeSymbol);
        lvalueRefTypeMap[baseTypeSymbol] = lvalueRefTypeSymbol;
        types.push_back(std::unique_ptr<TypeSymbol>(lvalueRefTypeSymbol));
        return lvalueRefTypeSymbol;
    }
}

TypeSymbol* SymbolTable::MakeRvalueRefType(TypeSymbol* baseTypeSymbol)
{
    auto it = rvalueRefTypeMap.find(baseTypeSymbol);
    if (it != rvalueRefTypeMap.cend())
    {
        return it->second;
    }
    else
    {
        TypeSymbol* rvalueRefTypeSymbol = new RvalueRefTypeSymbol(baseTypeSymbol);
        rvalueRefTypeMap[baseTypeSymbol] = rvalueRefTypeSymbol;
        types.push_back(std::unique_ptr<TypeSymbol>(rvalueRefTypeSymbol));
        return rvalueRefTypeSymbol;
    }
}

} // sngcpp::symbols
