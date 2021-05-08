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
    void MapNode(Node* node, Symbol* symbol);
    Symbol* Lookup(const std::u32string& name) const;
    Scope* CurrentScope() const { return currentScope; }
    void BeginScope(Scope& scope);
    void EndScope();
    void BeginClass(Node* node);
    void EndClass();
    TypeSymbol* GetFundamentalTypeSymbol(FundamentalTypeKind kind);
private:
    NamespaceSymbol globalNs;
    std::stack<Scope*> scopeStack;
    Scope* currentScope;
    std::unordered_map<Node*, Symbol*> nodeSymbolMap;
    std::unordered_map<Symbol*, Node*> symbolNodeMap;
    std::unordered_map<int, TypeSymbol*> fundamentalTypeMap;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_SYMBOL_TABLE_INCLUDED
