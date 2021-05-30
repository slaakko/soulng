// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/ContainerSymbol.hpp>
#include <sngcpp20/symbols/ClassGroupSymbol.hpp>
#include <sngcpp20/symbols/FunctionGroupSymbol.hpp>
#include <sngcpp20/symbols/ConceptGroupSymbol.hpp>
#include <sngcpp20/symbols/Exception.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp::symbols {

using namespace soulng::unicode;

ContainerSymbol::ContainerSymbol(const std::u32string& name_) : Symbol(name_)
{
    scope.SetContainerSymbol(this);
}

void ContainerSymbol::AddSymbol(Symbol* symbol, const SourcePos& sourcePos, Context* context)
{
    symbol->AddToGroup(this, sourcePos, context);
    symbol->SetParent(this);
    if (symbol->IsContainerSymbol())
    {
        ContainerSymbol* child = static_cast<ContainerSymbol*>(symbol);
        child->GetScope().SetParentScope(&scope);
    }
    if (symbol->CanInstall())
    {
        scope.Install(symbol);
    }
    symbols.push_back(std::unique_ptr<Symbol>(symbol));
}

ClassGroupSymbol* ContainerSymbol::GetOrInsertClassGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context)
{
    Scope& scope = GetScope();
    Symbol* symbol = scope.Lookup(name, ScopeLookup::thisScope, sourcePos, context);
    if (symbol)
    {
        if (symbol->IsClassGroupSymbol())
        {
            ClassGroupSymbol* classGroupSymbol = static_cast<ClassGroupSymbol*>(symbol);
            return classGroupSymbol;
        }
        else
        {
            std::string errorMessage = "name of class group '" + ToUtf8(name) + "' conflicts with earlier declaration of '" + symbol->SymbolKindStr() + " '" + ToUtf8(symbol->FullName()) + "'";
            throw Exception(errorMessage, sourcePos, context);
        }
    }
    else
    {
        ClassGroupSymbol* classGroupSymbol = new ClassGroupSymbol(name);
        AddSymbol(classGroupSymbol, sourcePos, context);
        return classGroupSymbol; 
    }
}

FunctionGroupSymbol* ContainerSymbol::GetOrInsertFunctionGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context)
{
    Scope& scope = GetScope();
    Symbol* symbol = scope.Lookup(name, ScopeLookup::thisScope, sourcePos, context);
    if (symbol)
    {
        if (symbol->IsFunctionGroupSymbol())
        {
            FunctionGroupSymbol* functionGroupSymbol = static_cast<FunctionGroupSymbol*>(symbol);
            return functionGroupSymbol;
        }
        else
        {
            std::string errorMessage = "name of function group '" + ToUtf8(name) + "' conflicts with earlier declaration of '" + symbol->SymbolKindStr() + " '" + ToUtf8(symbol->FullName()) + "'";
            throw Exception(errorMessage, sourcePos, context);
        }
    }
    else
    {
        FunctionGroupSymbol* functionGroupSymbol = new FunctionGroupSymbol(name);
        AddSymbol(functionGroupSymbol, sourcePos, context);
        return functionGroupSymbol;
    }
}

ConceptGroupSymbol* ContainerSymbol::GetOrInsertConceptGroup(const std::u32string& name, const SourcePos& sourcePos, Context* context)
{
    Scope& scope = GetScope();
    Symbol* symbol = scope.Lookup(name, ScopeLookup::thisScope, sourcePos, context);
    if (symbol)
    {
        if (symbol->IsConceptGroupSymbol())
        {
            ConceptGroupSymbol* conceptGroupSymbol = static_cast<ConceptGroupSymbol*>(symbol);
            return conceptGroupSymbol;
        }
        else
        {
            std::string errorMessage = "name of concept group '" + ToUtf8(name) + "' conflicts with earlier declaration of '" + symbol->SymbolKindStr() + " '" + ToUtf8(symbol->FullName()) + "'";
            throw Exception(errorMessage, sourcePos, context);
        }
    }
    else
    {
        ConceptGroupSymbol* conceptGroupSymbol = new ConceptGroupSymbol(name);
        AddSymbol(conceptGroupSymbol, sourcePos, context);
        return conceptGroupSymbol;
    }
}

} // sngcpp::symbols
