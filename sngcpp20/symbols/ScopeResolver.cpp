// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/ScopeResolver.hpp>
#include <sngcpp20/symbols/Exception.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Identifier.hpp>
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
        currentScope = &context->GetSymbolTable()->GlobalNs().GetScope();
        first = false;
    }
}

void ScopeResolverVisitor::Visit(IdentifierNode& node)
{
    first = false;
    Symbol* symbol = currentScope->Lookup(node.Str(), ScopeLookup::thisScope, node.GetSourcePos(), context);
    if (symbol)
    {
        if (symbol->IsContainerSymbol())
        {
            ContainerSymbol* containerSymbol = static_cast<ContainerSymbol*>(symbol);
            currentScope = &containerSymbol->GetScope();
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

void ScopeResolverVisitor::Visit(TemplateIdNode& node)
{
    first = false;
    // todo
}

Scope* ResolveScope(Node* nnsNode, Context* context)
{
    ScopeResolverVisitor visitor(context);
    nnsNode->Accept(visitor);
    return visitor.GetScope();
}

} // sngcpp::symbols
