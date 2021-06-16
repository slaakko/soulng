// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/symbols/BlockSymbol.hpp>
#include <sngcpp20/symbols/ClassTypeSymbol.hpp>
#include <sngcpp20/symbols/EnumTypeSymbol.hpp>
#include <sngcpp20/symbols/CompoundTypeSymbol.hpp>
#include <sngcpp20/symbols/FunctionSymbol.hpp>
#include <sngcpp20/symbols/FunctionGroupSymbol.hpp>
#include <sngcpp20/symbols/ConceptSymbol.hpp>
#include <sngcpp20/symbols/Exception.hpp>
#include <sngcpp20/symbols/TemplateDeclarationSymbol.hpp>
#include <soulng/util/Unicode.hpp>
#include <stdexcept>

namespace sngcpp::symbols {

using namespace soulng::unicode;

SymbolTable::SymbolTable() : globalNs(std::u32string()), currentScope(globalNs.GetScope()), blockNumber(0)
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

void SymbolTable::MapNode(Node* node)
{
    if (currentScope->IsContainerScope())
    {
        ContainerScope* containerScope = static_cast<ContainerScope*>(currentScope);
        Symbol* symbol = containerScope->GetContainerSymbol();
        MapNode(node, symbol);
    }
    else
    {
        throw std::runtime_error("container scope expected");
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

void SymbolTable::BeginNamespace(Node* node, Context* context)
{
    Symbol* symbol = currentScope->Lookup(node->Str(), ScopeLookup::thisScope, node->GetSourcePos(), context);
    if (symbol)
    {
        if (symbol->IsNamespaceSymbol())
        {
            NamespaceSymbol* namespaceSymbol = static_cast<NamespaceSymbol*>(symbol);
            MapNode(node, namespaceSymbol);
            BeginScope(*namespaceSymbol->GetScope());
            return;
        }
        else
        {
            throw Exception("name of namespace '" + ToUtf8(node->Str()) + " conflicts with earlier declaration", node->GetSourcePos(), context);
        }
    }
    NamespaceSymbol* namespaceSymbol = new NamespaceSymbol(node->Str());
    MapNode(node, namespaceSymbol);
    currentScope->AddSymbol(namespaceSymbol, node->GetSourcePos(), context);
    BeginScope(*namespaceSymbol->GetScope());
}

void SymbolTable::EndNamespace(int level)
{
    for (int i = 0; i < level; ++i)
    {
        EndScope();
    }
}

void SymbolTable::BeginClass(Node* specifierNode, Node* node, Context* context)
{
    ClassTypeSymbol* classTypeSymbol = new ClassTypeSymbol(node->Str());
    classTypeSymbol->SetIdNode(node);
    currentScope->AddSymbol(classTypeSymbol, node->GetSourcePos(), context);
    MapNode(specifierNode, classTypeSymbol);
    MapNode(node, classTypeSymbol, MapKind::nodeToSymbol);
    BeginScope(*classTypeSymbol->GetScope());
}

void SymbolTable::EndClass()
{
    EndScope();
}

void SymbolTable::BeginEnumType(Node* specifierNode, Node* idNode, TypeSymbol* enumBaseType, Context* context)
{
    Symbol* symbol = currentScope->Lookup(idNode->Str(), ScopeLookup::thisScope, idNode->GetSourcePos(), context);
    if (symbol)
    {
        if (symbol->IsEnumTypeSymbol())
        {
            EnumTypeSymbol* enumTypeSymbol = static_cast<EnumTypeSymbol*>(symbol);
            BeginScope(*enumTypeSymbol->GetScope());
            return;
        }
        else
        {
            throw Exception("name of enumerated type '" + ToUtf8(idNode->Str()) + " conflicts with earlier declaration", idNode->GetSourcePos(), context);
        }
    }
    EnumTypeSymbol* enumTypeSymbol = new EnumTypeSymbol(idNode->Str(), enumBaseType);
    enumTypeSymbol->SetIdNode(idNode);
    currentScope->AddSymbol(enumTypeSymbol, idNode->GetSourcePos(), context);
    MapNode(specifierNode, enumTypeSymbol);
    MapNode(idNode, enumTypeSymbol, MapKind::nodeToSymbol);
    BeginScope(*enumTypeSymbol->GetScope());
}

void SymbolTable::EndEnumType()
{
    EndScope();
}

void SymbolTable::BeginFunction(Node* node, Scope* scope, FunctionTypeSymbol* functionType, std::vector<std::unique_ptr<ParameterSymbol>>&& parameters, bool definition, Context* context)
{
    Symbol* symbol = scope->Lookup(node->Str(), ScopeLookup::thisScope, node->GetSourcePos(), context);
    if (symbol)
    {
        if (symbol->IsFunctionGroupSymbol())
        {
            FunctionGroupSymbol* functionGroupSymbol = static_cast<FunctionGroupSymbol*>(symbol);
            FunctionSymbol* functionSymbol = functionGroupSymbol->GetFunction(parameters);
            if (functionSymbol)
            {
                if (functionSymbol->Type()->Key().returnType != functionType->Key().returnType)
                {
                    throw Exception("function return type '" + ToUtf8(functionType->Key().returnType->FullName()) + " conflicts with earlier declaration", node->GetSourcePos(), context);
                }
                if (definition)
                {
                    if (functionSymbol->Definition())
                    {
                        throw Exception("function '" + ToUtf8(functionSymbol->FullName()) + " already has a body", node->GetSourcePos(), context);
                    }
                    else
                    {
                        functionSymbol->SetDefinition();
                        MapNode(node, functionSymbol);
                    }
                }
                else
                {
                    MapNode(node, functionSymbol, MapKind::nodeToSymbol);
                }
                BeginScope(*functionSymbol->GetScope());
                return;
            }
        }
    }
    FunctionSymbol* functionSymbol = new FunctionSymbol(node->Str(), std::move(parameters), definition); 
    functionSymbol->SetType(functionType);
    scope->AddSymbol(functionSymbol, node->GetSourcePos(), context);
    MapNode(node, functionSymbol);
    BeginScope(*functionSymbol->GetScope());
}

void SymbolTable::EndFunction()
{
    EndScope();
}

void SymbolTable::RemoveFunction()
{
    FunctionSymbol* functionSymbol = nullptr;
    Scope* scope = currentScope;
    if (scope->IsContainerScope())
    {
        ContainerScope* containerScope = static_cast<ContainerScope*>(scope);
        ContainerSymbol* containerSymbol = containerScope->GetContainerSymbol();
        if (containerSymbol->IsFunctionSymbol())
        {
            functionSymbol = static_cast<FunctionSymbol*>(containerSymbol);
        }
    }
    PopScope();
    if (functionSymbol)
    {
        currentScope->RemoveSymbol(functionSymbol);
    }
}

void SymbolTable::BeginBlock(const SourcePos& sourcePos, Context* context)
{
    BlockSymbol* blockSymbol = new BlockSymbol(blockNumber++);
    currentScope->AddSymbol(blockSymbol, sourcePos, context);
    BeginScope(*blockSymbol->GetScope());
}

void SymbolTable::EndBlock()
{
    EndScope();
}

void SymbolTable::RemoveBlock()
{
    BlockSymbol* blockSymbol = nullptr;
    Scope* scope = currentScope;
    if (scope->IsContainerScope())
    {
        ContainerScope* containerScope = static_cast<ContainerScope*>(scope);
        ContainerSymbol* containerSymbol = containerScope->GetContainerSymbol();
        if (containerSymbol->IsBlockSymbol())
        {
            blockSymbol = static_cast<BlockSymbol*>(containerSymbol);
        }
    }
    PopScope();
    if (blockSymbol)
    {
        if (currentScope->IsContainerScope())
        {
            ContainerScope* containerScope = static_cast<ContainerScope*>(currentScope);
            ContainerSymbol* containerSymbol = containerScope->GetContainerSymbol();
            containerSymbol->RemoveSymbol(blockSymbol);
        }
    }
}

void SymbolTable::AddConcept(Node* node, Context* context)
{
    ConceptSymbol* conceptSymbol = new ConceptSymbol(node->Str());
    currentScope->AddSymbol(conceptSymbol, node->GetSourcePos(), context);
    MapNode(node, conceptSymbol);
}

void SymbolTable::BeginTemplateDeclaration(Node* node, Context* context)
{
    TemplateDeclarationSymbol* templateDeclarationSymbol = new TemplateDeclarationSymbol();
    currentScope->AddSymbol(templateDeclarationSymbol, node->GetSourcePos(), context);
    MapNode(node, templateDeclarationSymbol);
    BeginScope(*templateDeclarationSymbol->GetScope());
}

void SymbolTable::EndTemplateDeclaration()
{
    EndScope();
}

void SymbolTable::AddTemplateParameter(Node* node, Context* context)
{
    TemplateParameterSymbol* templateParameterSymbol = new TemplateParameterSymbol(node->Str());
    currentScope->AddSymbol(templateParameterSymbol, node->GetSourcePos(), context);
    MapNode(node, templateParameterSymbol);
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

TypeSymbol* SymbolTable::MakeFunctionType(const FunctionTypeKey& functionTypeKey)
{
    auto it = functionTypeMap.find(functionTypeKey);
    if (it != functionTypeMap.cend())
    {
        return it->second;
    }
    else
    {
        FunctionTypeSymbol* functionType = new FunctionTypeSymbol();
        functionType->SetKey(functionTypeKey);
        functionTypeMap[functionTypeKey] = functionType;
        types.push_back(std::unique_ptr<TypeSymbol>(functionType));
        return functionType;
    }
}

TypeSymbol* SymbolTable::MakeArrayType(const ArrayTypeKey& arrayTypeKey)
{
    auto it = arrayTypeMap.find(arrayTypeKey);
    if (it != arrayTypeMap.cend())
    {
        return it->second;
    }
    else
    {
        ArrayTypeSymbol* arrayType = new ArrayTypeSymbol(arrayTypeKey);
        arrayTypeMap[arrayTypeKey] = arrayType;
        types.push_back(std::unique_ptr<TypeSymbol>(arrayType));
        return arrayType;
    }
}

} // sngcpp::symbols
