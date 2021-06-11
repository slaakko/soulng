// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_SYMBOL_TABLE_INCLUDED
#define SNGCPP_SYMBOLS_SYMBOL_TABLE_INCLUDED
#include <sngcpp20/symbols/NamespaceSymbol.hpp>
#include <sngcpp20/symbols/FundamentalTypeSymbol.hpp>
#include <sngcpp20/ast/Identifier.hpp>
#include <sngcpp20/ast/Class.hpp>
#include <unordered_map>
#include <stack>

namespace sngcpp::symbols {

using namespace sngcpp::ast;

class ParameterSymbol;

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
    const NamespaceSymbol& GlobalNs() const { return globalNs; }
    NamespaceSymbol& GlobalNs() { return globalNs; }
    Node* GetNodeNothrow(Symbol* symbol) const;
    Node* GetNode(Symbol* symbol) const;
    Symbol* GetSymbolNothrow(Node* node) const;
    Symbol* GetSymbol(Node* node) const;
    void MapNode(Node* node);
    void MapNode(Node* node, Symbol* symbol);
    void MapNode(Node* node, Symbol* symbol, MapKind kind);
    Symbol* Lookup(const std::u32string& name, const SourcePos& sourcePos, Context* context) const;
    Scope* CurrentScope() const { return currentScope; }
    void SetCurrentScope(Scope* scope) { currentScope = scope; }
    void PushScope();
    void PopScope();
    void BeginScope(Scope& scope);
    void EndScope();
    void BeginNamespace(Node* node, Context* context);
    void EndNamespace(int level);
    void BeginClass(Node* specifierNode, Node* node, Context* context);
    void EndClass();
    void BeginEnumType(Node* specifierNode, Node* node, Context* context);
    void EndEnumType();
    void BeginFunction(Node* node, Scope* scope, TypeSymbol* returnType, const std::vector<ParameterSymbol*>& parameters, bool definition, Context* context);
    void EndFunction();
    void RemoveFunction();
    void BeginBlock(const SourcePos& sourcePos, Context* context);
    void EndBlock();
    void AddConcept(Node* node, Context* context);
    void BeginTemplateDeclaration(Node* node, Context* context);
    void EndTemplateDeclaration();
    void AddTemplateParameter(Node* node, Context* context);
    TypeSymbol* GetFundamentalTypeSymbol(FundamentalTypeKind kind);
    TypeSymbol* MakeConstType(TypeSymbol* baseTypeSymbol);
    TypeSymbol* MakeVolatileType(TypeSymbol* baseTypeSymbol);
    TypeSymbol* MakePointerType(TypeSymbol* baseTypeSymbol);
    TypeSymbol* MakeLvalueRefType(TypeSymbol* baseTypeSymbol);
    TypeSymbol* MakeRvalueRefType(TypeSymbol* baseTypeSymbol);
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
    std::vector<std::unique_ptr<TypeSymbol>> types;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_SYMBOL_TABLE_INCLUDED
