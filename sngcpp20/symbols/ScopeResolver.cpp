// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/ScopeResolver.hpp>
#include <sngcpp20/symbols/ClassGroupSymbol.hpp>
#include <sngcpp20/symbols/ClassTypeSymbol.hpp>
#include <sngcpp20/symbols/DeclarationProcessor.hpp>
#include <sngcpp20/symbols/Exception.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Identifier.hpp>
#include <sngcpp20/ast/Template.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp::symbols {

using namespace soulng::unicode;

class ScopeResolverVisitor : public DefaultVisitor
{
public:
    ScopeResolverVisitor(Context* context_);
    Scope* GetScope() const { return currentScope; }
    void Visit(NestedNameSpecifierNode& node) override;
    void Visit(ColonColonNode& node) override;
    void Visit(IdentifierNode& node) override;
    void Visit(TemplateIdNode& node) override;
private:
    Context* context;
    bool first;
    Scope* currentScope;
};

ScopeResolverVisitor::ScopeResolverVisitor(Context* context_) : context(context_), first(false), currentScope(nullptr)
{
}

void ScopeResolverVisitor::Visit(NestedNameSpecifierNode& node)
{
    first = true;
    currentScope = context->GetSymbolTable()->CurrentScope();
    VisitSequence(node);
}

void ScopeResolverVisitor::Visit(ColonColonNode& node)
{
    if (first)
    {
        currentScope = context->GetSymbolTable()->GlobalNs().GetScope();
        first = false;
    }
}

void ScopeResolverVisitor::Visit(IdentifierNode& node)
{
    try
    {
        first = false;
        Symbol* symbol = currentScope->Lookup(node.Str(), SymbolGroupKind::typeSymbolGroup, ScopeLookup::allScopes, node.GetSourcePos(), context);
        if (symbol && symbol->Kind() == SymbolKind::classGroupSymbol)
        {
            ClassGroupSymbol* classGroup = static_cast<ClassGroupSymbol*>(symbol);
            bool exact = false;
            ClassTypeSymbol* classTypeSymbol = classGroup->GetClass(std::vector<Symbol*>(), MatchKind::exact, exact);
            if (classTypeSymbol)
            {
                symbol = classTypeSymbol;
            }
            else
            {
                symbol = nullptr;
            }
        }
        if (symbol)
        {
            Scope* scope = symbol->GetScope();
            if (scope)
            {
                currentScope = scope;
            }
            else
            {
                throw Exception("symbol '" + ToUtf8(symbol->FullName()) + "' does not have a scope", node.GetSourcePos(), context);
            }
        }
        else
        {
            throw Exception("symbol '" + ToUtf8(node.Str()) + "' not found from " + ScopeKindStr(currentScope->Kind()) + " '" + currentScope->FullName() + "'", node.GetSourcePos(), context);
        }
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void ScopeResolverVisitor::Visit(TemplateIdNode& node)
{
    try
    {
        first = false;
        TypeSymbol* type = ProcessTypeTemplateId(&node, context);
        Scope* scope = type->GetScope();
        if (scope)
        {
            currentScope = scope;
        }
        else
        {
            throw Exception("symbol '" + ToUtf8(type->FullName()) + "' does not have a scope", node.GetSourcePos(), context);
        }
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

Scope* ResolveScope(Node* nnsNode, Context* context)
{
    try
    {
        ScopeResolverVisitor visitor(context);
        nnsNode->Accept(visitor);
        return visitor.GetScope();
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
    return nullptr;
}

} // sngcpp::symbols
