// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/symbols/BlockSymbol.hpp>
#include <sngcpp20/symbols/ClassGroupSymbol.hpp>
#include <sngcpp20/symbols/ClassTypeSymbol.hpp>
#include <sngcpp20/symbols/ConceptGroupSymbol.hpp>
#include <sngcpp20/symbols/EnumTypeSymbol.hpp>
#include <sngcpp20/symbols/CompoundTypeSymbol.hpp>
#include <sngcpp20/symbols/FunctionSymbol.hpp>
#include <sngcpp20/symbols/FunctionGroupSymbol.hpp>
#include <sngcpp20/symbols/VariableGroupSymbol.hpp>
#include <sngcpp20/symbols/VariableSymbol.hpp>
#include <sngcpp20/symbols/AliasGroupSymbol.hpp>
#include <sngcpp20/symbols/AliasTypeSymbol.hpp>
#include <sngcpp20/symbols/ConceptSymbol.hpp>
#include <sngcpp20/symbols/GenericTypeSymbol.hpp>
#include <sngcpp20/symbols/NullPtrTypeSymbol.hpp>
#include <sngcpp20/symbols/Exception.hpp>
#include <sngcpp20/symbols/TemplateDeclarationSymbol.hpp>
#include <soulng/util/Unicode.hpp>
#include <stdexcept>

namespace sngcpp::symbols {

using namespace soulng::unicode;

SymbolTable::SymbolTable() : globalNs(std::u32string()), currentScope(globalNs.GetScope()), blockNumber(0), varArgTypeSymbol(nullptr), typenameContraintSymbol(nullptr), genericTypeSymbol(nullptr), nullPtrTypeSymbol(nullptr)
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
        if (GetSymbolNothrow(node) == nullptr)
        {
            nodeSymbolMap[node] = symbol;
        }
    }
    if ((kind & MapKind::symbolToNode) != MapKind::none)
    {
        symbolNodeMap[symbol] = node;
    }
}

Symbol* SymbolTable::Lookup(const std::u32string& name, SymbolGroupKind symbolGroupKind, const SourcePos& sourcePos, Context* context) const
{
    return currentScope->Lookup(name, symbolGroupKind, ScopeLookup::allScopes, sourcePos, context);
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
    Symbol* symbol = currentScope->Lookup(node->Str(), SymbolGroupKind::typeSymbolGroup, ScopeLookup::thisScope, node->GetSourcePos(), context);
    if (symbol)
    {
        if (symbol->Kind() == SymbolKind::namespaceSymbol)
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
    currentScope->AddSymbol(namespaceSymbol, SymbolGroupKind::typeSymbolGroup, node->GetSourcePos(), nullptr, context);
    BeginScope(*namespaceSymbol->GetScope());
}

void SymbolTable::EndNamespace(int level)
{
    for (int i = 0; i < level; ++i)
    {
        EndScope();
    }
}

void SymbolTable::BeginClass(Node* specifierNode, Node* node, std::vector<Symbol*>& templateArguments, Context* context)
{
    Scope* groupScope = currentScope;
    TemplateDeclarationSymbol* templateDeclarationSymbol = nullptr;
    if (currentScope->Kind() == ScopeKind::templateDeclarationScope)
    {
        templateDeclarationSymbol = static_cast<TemplateDeclarationSymbol*>(currentScope->GetSymbol());
        groupScope = currentScope->ParentScope();
    }
    Symbol* symbol = nullptr;
    if (node->GetSourcePos().line == 8853)
    {
        int x = 0;
    }
    if (!node->Str().empty())
    {
        symbol = groupScope->Lookup(node->Str(), SymbolGroupKind::typeSymbolGroup, ScopeLookup::thisScope, node->GetSourcePos(), context);
    }
    if (symbol)
    {
        if (symbol->Kind() == SymbolKind::classGroupSymbol)
        {
            ClassGroupSymbol* classGroup = static_cast<ClassGroupSymbol*>(symbol);
            bool exact = false;
            ClassTypeSymbol* classTypeSymbol = classGroup->GetClass(templateArguments, MatchKind::exact, exact);
            if (classTypeSymbol)
            {
                MapNode(specifierNode, classTypeSymbol, MapKind::nodeToSymbol);
                BeginScope(*classTypeSymbol->GetScope());
                return;
            }
        }
        else
        {
            throw Exception("name of class group '" + ToUtf8(node->Str()) + " conflicts with earlier declaration", node->GetSourcePos(), context);
        }
    }
    ClassTypeSymbol* classTypeSymbol = new ClassTypeSymbol(node->Str());
    classTypeSymbol->SetIdNode(node);
    classTypeSymbol->SetTemplateArguments(templateArguments);
    currentScope->AddSymbol(classTypeSymbol, SymbolGroupKind::typeSymbolGroup, node->GetSourcePos(), groupScope, context);
    if (templateDeclarationSymbol)
    {
        classTypeSymbol->SetTemplateDeclarationSymbol(templateDeclarationSymbol);
        classTypeSymbol->AddTemplateParameters(templateDeclarationSymbol->TemplateParameters());
    }
    if (specifierNode)
    {
        MapNode(specifierNode, classTypeSymbol);
    }
    MapNode(node, classTypeSymbol, MapKind::nodeToSymbol);
    BeginScope(*classTypeSymbol->GetScope());
}

void SymbolTable::EndClass()
{
    EndScope();
}

void SymbolTable::BeginEnumType(Node* specifierNode, Node* idNode, TypeSymbol* enumBaseType, Context* context)
{
    Symbol* symbol = nullptr;
    if (!idNode->Str().empty())
    {
        currentScope->Lookup(idNode->Str(), SymbolGroupKind::typeSymbolGroup, ScopeLookup::thisScope, idNode->GetSourcePos(), context);
    }
    if (symbol)
    {
        if (symbol->Kind() == SymbolKind::enumTypeSymbol)
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
    currentScope->AddSymbol(enumTypeSymbol, SymbolGroupKind::typeSymbolGroup, idNode->GetSourcePos(), nullptr, context);
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
    Scope* groupScope = scope;
    TemplateDeclarationSymbol* templateDeclarationSymbol = nullptr;
    if (currentScope->Kind() == ScopeKind::templateDeclarationScope)
    {
        templateDeclarationSymbol = static_cast<TemplateDeclarationSymbol*>(currentScope->GetSymbol());
        groupScope = scope->ParentScope();
    }
    Symbol* symbol = groupScope->Lookup(node->Str(), SymbolGroupKind::functionSymbolGroup, ScopeLookup::thisScope, node->GetSourcePos(), context);
    if (symbol)
    {
        if (symbol->Kind() == SymbolKind::functionGroupSymbol)
        {
            FunctionGroupSymbol* functionGroupSymbol = static_cast<FunctionGroupSymbol*>(symbol);
            FunctionSymbol* functionSymbol = functionGroupSymbol->GetFunction(parameters);
            if (functionSymbol)
            {
                if (!SymbolsEqual(functionSymbol->Type()->Key().returnType, functionType->Key().returnType))
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
    currentScope->AddSymbol(functionSymbol, SymbolGroupKind::functionSymbolGroup, node->GetSourcePos(), groupScope, context);
    if (templateDeclarationSymbol)
    {
        functionSymbol->SetTemplateDeclarationSymbol(templateDeclarationSymbol);
    }
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
        if (containerSymbol->Kind() == SymbolKind::functionSymbol)
        {
            functionSymbol = static_cast<FunctionSymbol*>(containerSymbol);
        }
    }
    PopScope();
    if (functionSymbol)
    {
        currentScope->RemoveSymbol(functionSymbol, SymbolGroupKind::functionSymbolGroup);
    }
}

void SymbolTable::BeginBlock(const SourcePos& sourcePos, Context* context)
{
    BlockSymbol* blockSymbol = new BlockSymbol(blockNumber++);
    currentScope->AddSymbol(blockSymbol, SymbolGroupKind::blockSymbolGroup, sourcePos, nullptr, context);
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
        if (containerSymbol->Kind() == SymbolKind::blockSymbol)
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
            containerSymbol->RemoveSymbol(blockSymbol, SymbolGroupKind::blockSymbolGroup);
        }
    }
}

void SymbolTable::AddAliasType(Node* node, Scope* scope, TypeSymbol* type, Context* context)
{
    Scope* groupScope = scope;
    TemplateDeclarationSymbol* templateDeclarationSymbol = nullptr;
    if (scope->Kind() == ScopeKind::templateDeclarationScope)
    {
        templateDeclarationSymbol = static_cast<TemplateDeclarationSymbol*>(scope->GetSymbol());
        groupScope = scope->ParentScope();
    }
    if (node->Str() == type->Name() && groupScope == type->GetGroupScope())
    {
        return;
    }
    Symbol* symbol = groupScope->Lookup(node->Str(), SymbolGroupKind::typeSymbolGroup, ScopeLookup::thisScope, node->GetSourcePos(), context);
    if (symbol)
    {
        if (symbol->Kind() == SymbolKind::aliasGroupSymbol)
        {
            return;
        }
        if (symbol->Kind() == SymbolKind::classGroupSymbol)
        {
            return;
        }
    }
    AliasTypeSymbol* aliasTypeSymbol = new AliasTypeSymbol(node->Str(), type);
    if (templateDeclarationSymbol)
    {
        aliasTypeSymbol->SetTemplateDeclarationSymbol(templateDeclarationSymbol);
    }
    currentScope->AddSymbol(aliasTypeSymbol, SymbolGroupKind::typeSymbolGroup, node->GetSourcePos(), groupScope, context);
    MapNode(node, aliasTypeSymbol);
}

void SymbolTable::AddConcept(Node* node, Context* context)
{
    Scope* groupScope = currentScope;
    TemplateDeclarationSymbol* templateDeclarationSymbol = nullptr;
    if (currentScope->Kind() == ScopeKind::templateDeclarationScope)
    {
        templateDeclarationSymbol = static_cast<TemplateDeclarationSymbol*>(currentScope->GetSymbol());
        groupScope = currentScope->ParentScope();
    }
    Symbol* symbol = groupScope->Lookup(node->Str(), SymbolGroupKind::conceptSymbolGroup, ScopeLookup::thisScope, node->GetSourcePos(), context);
    if (symbol)
    {
        if (symbol->Kind() == SymbolKind::conceptGroupSymbol)
        {
            ConceptGroupSymbol* conceptGroupSymbol = static_cast<ConceptGroupSymbol*>(symbol);
            ConceptSymbol* conceptSymbol = conceptGroupSymbol->GetConcept();
            if (conceptSymbol)
            {
                BeginScope(*conceptSymbol->GetScope());
                return;
            }
        }
    }
    ConceptSymbol* conceptSymbol = new ConceptSymbol(node->Str());
    currentScope->AddSymbol(conceptSymbol, SymbolGroupKind::conceptSymbolGroup, node->GetSourcePos(), groupScope, context);
    MapNode(node, conceptSymbol);
}

void SymbolTable::AddVariable(Node* node, Scope* scope, TypeSymbol* type, SymbolKind kind, Context* context)
{
    Scope* groupScope = scope;
    TemplateDeclarationSymbol* templateDeclarationSymbol = nullptr;
    if (scope->Kind() == ScopeKind::templateDeclarationScope)
    {
        templateDeclarationSymbol = static_cast<TemplateDeclarationSymbol*>(scope->GetSymbol());
        groupScope = scope->ParentScope();
    }
    Symbol* symbol = groupScope->Lookup(node->Str(), SymbolGroupKind::variableSymbolGroup, ScopeLookup::thisScope, node->GetSourcePos(), context);
    if (symbol)
    {
        if (symbol->Kind() == SymbolKind::variableGroupSymbol)
        {
            return;
        }
    }
    VariableSymbol* variableSymbol = new VariableSymbol(node->Str(), kind);
    variableSymbol->SetType(type);
    scope->AddSymbol(variableSymbol, SymbolGroupKind::variableSymbolGroup, node->GetSourcePos(), groupScope, context);
    MapNode(node, variableSymbol);
}

void SymbolTable::BeginTemplateDeclaration(Node* node, Context* context)
{
    TemplateDeclarationSymbol* templateDeclarationSymbol = new TemplateDeclarationSymbol();
    currentScope->AddSymbol(templateDeclarationSymbol, SymbolGroupKind::blockSymbolGroup, node->GetSourcePos(), nullptr, context);
    MapNode(node, templateDeclarationSymbol);
    BeginScope(*templateDeclarationSymbol->GetScope());
}

void SymbolTable::EndTemplateDeclaration()
{
    EndScope();
}

void SymbolTable::AddTemplateParameter(Node* node, const std::u32string& name, Symbol* contstraint, int index, Context* context)
{
    TemplateParameterSymbol* templateParameterSymbol = new TemplateParameterSymbol(contstraint, name, index);
    currentScope->AddSymbol(templateParameterSymbol, SymbolGroupKind::typeSymbolGroup, node->GetSourcePos(), nullptr, context);
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

TypeSymbol* SymbolTable::MakeVarArgTypeSymbol()
{
    if (!varArgTypeSymbol)
    {
        varArgTypeSymbol = new VarArgTypeSymbol();
        types.push_back(std::unique_ptr<TypeSymbol>(varArgTypeSymbol));
    }
    return varArgTypeSymbol;
}

TypeSymbol* SymbolTable::MakeTypeNameConstraintSymbol()
{
    if (!typenameContraintSymbol)
    {
        typenameContraintSymbol = new TypenameConstraintSymbol();
        types.push_back(std::unique_ptr<TypeSymbol>(typenameContraintSymbol));
    }
    return typenameContraintSymbol;
}

TypeSymbol* SymbolTable::MakeGenericTypeSymbol()
{
    if (!genericTypeSymbol)
    {
        genericTypeSymbol = new GenericTypeSymbol();
        types.push_back(std::unique_ptr<TypeSymbol>(genericTypeSymbol));
    }
    return genericTypeSymbol;
}

TypeSymbol* SymbolTable::MakeNullPtrTypeSymbol()
{
    if (!nullPtrTypeSymbol)
    {
        nullPtrTypeSymbol = new NullPtrTypeSymbol();
        types.push_back(std::unique_ptr<TypeSymbol>(nullPtrTypeSymbol));
    }
    return nullPtrTypeSymbol;
}

} // sngcpp::symbols
