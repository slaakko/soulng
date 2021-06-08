// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_SYMBOL_INCLUDED
#include <sngcpp20/symbols/SymbolsApi.hpp>
#include <sngcpp20/symbols/Context.hpp>
#include <string>

namespace sngcpp::symbols {

using soulng::lexer::SourcePos;
    
class ContainerSymbol;

enum class ScopeKind : int;

class SYMBOLS_API Symbol
{
public:
    Symbol(const std::u32string& name_);
    virtual ~Symbol();
    virtual bool IsTypeSymbol() const { return false; }
    virtual bool IsContainerSymbol() const { return false; }
    virtual bool IsFunctionSymbol() const { return false; }
    virtual bool IsParameterSymbol() const { return false; }
    virtual bool IsNamespaceSymbol() const { return false; }
    virtual bool IsClassTypeSymbol() const { return false; }
    virtual bool IsEnumTypeSymbol() const { return false; }
    virtual bool IsClassGroupSymbol() const { return false; }
    virtual bool IsFunctionGroupSymbol() const { return false; }
    virtual bool IsConceptGroupSymbol() const { return false; }
    virtual std::u32string FullName() const;
    virtual std::string SymbolKindStr() const = 0;
    virtual bool IsValidDeclarationScope(ScopeKind scopeKind) const { return true; }
    virtual bool CanInstall() const { return true; }
    virtual void AddSymbol(Symbol* symbol, const SourcePos& sourcePos, Context* context);
    virtual void AddToGroup(ContainerSymbol* containerSymbol, const SourcePos& sourcePos, Context* context);
    const std::u32string& Name() const { return name; }
    ContainerSymbol* Parent() const { return parent; }
    void SetParent(ContainerSymbol* parent_) { parent = parent_; }
private:
    std::u32string name;
    ContainerSymbol* parent;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_SYMBOL_INCLUDED
