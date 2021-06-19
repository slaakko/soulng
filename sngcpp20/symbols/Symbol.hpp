// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_SYMBOL_INCLUDED
#include <sngcpp20/symbols/SymbolsApi.hpp>
#include <sngcpp20/symbols/Context.hpp>
#include <string>
#include <vector>

namespace sngcpp::symbols {

using soulng::lexer::SourcePos;
    
class ContainerSymbol;
class Scope;

enum class ScopeKind : int;

enum class SymbolKind : int
{
    classGroupSymbol, conceptGroupSymbol, functionGroupSymbol, variableGroupSymbol, aliasGroupSymbol,
    typenameConstraintSymbol,
    valueSymbol,
    aliasTypeSymbol, arrayTypeSymbol, blockSymbol, classTypeSymbol, constTypeSymbol, volatileTypeSymbol, pointerTypeSymbol, lvalueRefTypeSymbol, rvalueRefTypeSymbol, 
    conceptSymbol, enumTypeSymbol, enumeratorSymbol, functionSymbol, functionTypeSymbol, fundamentalTypeSymbol, namespaceSymbol, templateDeclarationSymbol, templateParameterSymbol, varArgTypeSymbol,
    variableSymbol, parameterSymbol
};

class SYMBOLS_API Symbol
{
public:
    Symbol(const std::u32string& name_, SymbolKind kind_);
    virtual ~Symbol();
    virtual bool IsTypeSymbol() const { return false; }
    virtual bool IsContainerSymbol() const { return false; }
    virtual bool IsCompoundTypeSymbol() const { return false; }
    virtual Scope* GetScope() { return nullptr; }
    virtual std::u32string FullName() const;
    virtual std::string SymbolKindStr() const = 0;
    virtual bool IsValidDeclarationScope(ScopeKind scopeKind) const { return true; }
    virtual bool CanInstall() const { return true; }
    virtual void AddSymbol(Symbol* symbol, const SourcePos& sourcePos, Scope* groupScope, Context* context);
    virtual void RemoveSymbol(Symbol* symbol);
    virtual void AddToGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context);
    virtual void RemoveFromGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context);
    virtual const std::u32string& InstallationName() const { return name; }
    SymbolKind Kind() const { return kind; }
    const std::u32string& Name() const { return name; }
    ContainerSymbol* Parent() const { return parent; }
    void SetParent(ContainerSymbol* parent_) { parent = parent_; }
private:
    SymbolKind kind;
    std::u32string name;
    ContainerSymbol* parent;
};

bool SymbolsEqual(const std::vector<Symbol*>& left, const std::vector<Symbol*>& right);
bool SymbolsEqual(Symbol* left, Symbol* right);
int Match(const std::vector<Symbol*>& left, const std::vector<Symbol*>& right);
int Match(Symbol* left, Symbol* right);

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_SYMBOL_INCLUDED
