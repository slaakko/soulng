// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_SYMBOL_TABLE_INCLUDED
#define SNGCPP_SYMBOLS_SYMBOL_TABLE_INCLUDED
#include <sngcpp20/symbols/ArrayTypeSymbol.hpp>
#include <sngcpp20/symbols/NamespaceSymbol.hpp>
#include <sngcpp20/symbols/Exception.hpp>
#include <sngcpp20/symbols/FundamentalTypeSymbol.hpp>
#include <sngcpp20/symbols/FunctionTypeSymbol.hpp>
#include <sngcpp20/symbols/TemplateDeclarationSymbol.hpp>
#include <sngcpp20/symbols/VarArgTypeSymbol.hpp>
#include <sngcpp20/ast/Identifier.hpp>
#include <sngcpp20/ast/Class.hpp>
#include <unordered_map>
#include <map>
#include <stack>

namespace sngcpp::symbols {

using namespace sngcpp::ast;

class ParameterSymbol;
class FunctionTypeSymbol;
class ClassTypeSymbol;
class AliasTypeSymbol;
class Value;

enum class MapKind : int
{
    none, nodeToSymbol = 1 << 0, symbolToNode = 1 << 1, both = nodeToSymbol | symbolToNode
};

inline MapKind operator|(MapKind left, MapKind right)
{
    return MapKind(int(left) | int(right));
}

inline MapKind operator&(MapKind left, MapKind right)
{
    return MapKind(int(left) & int(right));
}

inline MapKind operator~(MapKind kind)
{
    return MapKind(~int(kind));
}

class SYMBOLS_API SymbolTable
{
public:
    SymbolTable();
    ~SymbolTable();
    const NamespaceSymbol& GlobalNs() const { return globalNs; }
    NamespaceSymbol& GlobalNs() { return globalNs; }
    Node* GetNodeNothrow(Symbol* symbol) const;
    Node* GetNode(Symbol* symbol) const;
    Symbol* GetSymbolNothrow(Node* node) const;
    Symbol* GetSymbol(Node* node) const;
    void MapNode(Node* node);
    void MapNode(Node* node, Symbol* symbol);
    void MapNode(Node* node, Symbol* symbol, MapKind kind);
    void UnmapNode(Node* node);
    Symbol* Lookup(const std::u32string& name, SymbolGroupKind symbolGroupKind, const SourcePos& sourcePos, Context* context) const;
    Scope* CurrentScope() const { return currentScope; }
    void SetCurrentScope(Scope* scope) { currentScope = scope; }
    void PushScope();
    void PopScope();
    void BeginScope(Scope& scope);
    void EndScope();
    void BeginNamespace(Node* node, Context* context);
    void EndNamespace(int level);
    void BeginClass(Node* specifierNode, Node* node, std::vector<Symbol*>& templateArguments, Context* context);
    void EndClass();
    void BeginEnumType(Node* specifierNode, Node* idNode, TypeSymbol* enumBaseType, Context* context);
    void EndEnumType();
    void BeginFunction(Node* node, Scope* scope, FunctionTypeSymbol* functionType, std::vector<std::unique_ptr<ParameterSymbol>>&& parameters, bool definition, const SourcePos& sourcePos, 
        const std::u32string& functionName, Context* context);
    void EndFunction();
    void RemoveFunction();
    void BeginBlock(const SourcePos& sourcePos, Context* context);
    void EndBlock();
    void RemoveBlock();
    void AddAliasType(Node* node, Scope* scope, TypeSymbol* type, Context* context);
    void AddConcept(Node* node, std::vector<Symbol*>& templateArguments, Context* context);
    void AddVariable(Node* node, const std::vector<Symbol*>& templateArguments, Value* value, Scope* scope, TypeSymbol* type, SymbolKind kind, Context* context);
    void BeginTemplateDeclaration(Node* node, Context* context);
    void EndTemplateDeclaration();
    void AddTemplateParameter(Node* node, const std::u32string& name, Symbol* constraint, int index, Context* context);
    ClassTypeSymbol* Instantiate(ClassTypeSymbol* classTemplate, const std::vector<Symbol*>& templateArguments);
    AliasTypeSymbol* Instantiate(AliasTypeSymbol* aliasTemplate, const std::vector<Symbol*>& templateArguments);
    VariableSymbol* Instantiate(VariableSymbol* variableTemplate, const std::vector<Symbol*>& templateArguments);
    TypeSymbol* GetFundamentalTypeSymbol(FundamentalTypeKind kind);
    TypeSymbol* MakeConstType(TypeSymbol* baseTypeSymbol);
    TypeSymbol* MakeVolatileType(TypeSymbol* baseTypeSymbol);
    TypeSymbol* MakePointerType(TypeSymbol* baseTypeSymbol);
    TypeSymbol* MakeLvalueRefType(TypeSymbol* baseTypeSymbol);
    TypeSymbol* MakeRvalueRefType(TypeSymbol* baseTypeSymbol);
    TypeSymbol* MakeFunctionType(const FunctionTypeKey& functionTypeKey);
    TypeSymbol* MakeArrayType(const ArrayTypeKey& arrayTypeKey);
    TypeSymbol* MakeVarArgTypeSymbol();
    TypeSymbol* MakeTypeNameConstraintSymbol();
    TypeSymbol* MakeGenericTypeSymbol();
    TypeSymbol* MakeNullPtrTypeSymbol();
    ErrorSymbol* MakeErrorSymbol(int errorIndex);
    int AddError(const std::exception& error);
    const std::exception& GetError(int errorIndex) const;
private:
    NamespaceSymbol globalNs;
    std::stack<Scope*> scopeStack;
    Scope* currentScope;
    std::unordered_map<Node*, Symbol*> nodeSymbolMap;
    std::unordered_map<Symbol*, Node*> symbolNodeMap;
    std::unordered_map<int, TypeSymbol*> fundamentalTypeMap;
    std::unordered_map<TypeSymbol*, TypeSymbol*> constTypeMap;
    std::unordered_map<TypeSymbol*, TypeSymbol*> volatileTypeMap;
    std::unordered_map<TypeSymbol*, TypeSymbol*> pointerTypeMap;
    std::unordered_map<TypeSymbol*, TypeSymbol*> lvalueRefTypeMap;
    std::unordered_map<TypeSymbol*, TypeSymbol*> rvalueRefTypeMap;
    std::unordered_map<FunctionTypeKey, TypeSymbol*, FunctionTypeKeyHash> functionTypeMap;
    std::unordered_map<ArrayTypeKey, TypeSymbol*, ArrayTypeKeyHash> arrayTypeMap;
    std::map<std::vector<Symbol*>, ClassTypeSymbol*> classSpecializationMap;
    std::map<std::vector<Symbol*>, AliasTypeSymbol*> aliasTypeSpecializationMap;
    std::map<std::vector<Symbol*>, VariableSymbol*> variableSpecializationMap;
    TypeSymbol* varArgTypeSymbol;
    TypeSymbol* typenameContraintSymbol;
    TypeSymbol* genericTypeSymbol;
    TypeSymbol* nullPtrTypeSymbol;
    std::vector<std::unique_ptr<TypeSymbol>> types;
    std::vector<std::unique_ptr<Symbol>> symbols;
    std::vector<std::exception> errors;
    int blockNumber;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_SYMBOL_TABLE_INCLUDED
