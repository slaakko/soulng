// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Namespace.hpp>
#include <sngcpp20/symbols/Exception.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/symbols/ScopeResolver.hpp>
#include <sngcpp20/symbols/EnumTypeSymbol.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp::symbols {

using namespace soulng::unicode;

class NamespaceCreatorVisitor : public DefaultVisitor
{
public:
    NamespaceCreatorVisitor(Context* context_);
    void Visit(ColonColonNode& node) override;
    void Visit(IdentifierNode& node) override;
private:
    Context* context;
    Scope* currentScope;
    bool first;
};

NamespaceCreatorVisitor::NamespaceCreatorVisitor(Context* context_) : context(context_), first(true), currentScope(context->GetSymbolTable()->CurrentScope())
{
}

void NamespaceCreatorVisitor::Visit(ColonColonNode& node)
{
    if (first)
    {
        currentScope = context->GetSymbolTable()->GlobalNs().GetScope();
        first = false;
    }
}

void NamespaceCreatorVisitor::Visit(IdentifierNode& node)
{
    first = false;
    context->GetSymbolTable()->BeginNamespace(&node, context);
    currentScope = context->GetSymbolTable()->CurrentScope();
}

void BeginNamespace(Node* node, Context* context)
{
    NamespaceCreatorVisitor visitor(context);
    node->Accept(visitor);
}

void EndNamespace(int level, Context* context)
{
    context->GetSymbolTable()->EndNamespace(level);
}

class UsingDirectiveAdder : public DefaultVisitor
{
public:
    UsingDirectiveAdder(Context* context_);
    void Visit(UsingDirectiveNode& node) override;
    void Visit(QualifiedIdNode& node) override;
    void Visit(IdentifierNode& node) override;
private:
    Context* context;
    Scope* scope;
};

UsingDirectiveAdder::UsingDirectiveAdder(Context* context_) : context(context_), scope(context->GetSymbolTable()->CurrentScope())
{
}

void UsingDirectiveAdder::Visit(UsingDirectiveNode& node)
{
    node.Id()->Accept(*this);
}

void UsingDirectiveAdder::Visit(QualifiedIdNode& node)
{
    scope = ResolveScope(node.Left(), context);
    node.Right()->Accept(*this);
}

void UsingDirectiveAdder::Visit(IdentifierNode& node)
{
    Symbol* symbol = scope->Lookup(node.Str(), ScopeLookup::thisScope, node.GetSourcePos(), context);
    if (symbol->Kind() == SymbolKind::namespaceSymbol)
    {
        NamespaceSymbol* ns = static_cast<NamespaceSymbol*>(symbol);
        context->GetSymbolTable()->CurrentScope()->AddUsingDirective(ns, node.GetSourcePos(), context);
    }
    else
    {
        throw Exception("symbol '" + ToUtf8(symbol->FullName()) + "' does not denote a namespace", node.GetSourcePos(), context);
    }
}

void AddUsingDirective(Node* node, Context* context)
{
    UsingDirectiveAdder visitor(context);
    node->Accept(visitor);
}

class UsingDeclarationAdder : public DefaultVisitor
{
public:
    UsingDeclarationAdder(Context* context_);
    void Visit(UsingDeclarationNode& node) override;
    void Visit(QualifiedIdNode& node) override;
    void Visit(IdentifierNode& node) override;
private:
    Context* context;
    Scope* scope;
};

UsingDeclarationAdder::UsingDeclarationAdder(Context* context_) : context(context_), scope(context->GetSymbolTable()->CurrentScope())
{
}

void UsingDeclarationAdder::Visit(UsingDeclarationNode& node)
{
    node.Declarators()->Accept(*this);
}

void UsingDeclarationAdder::Visit(QualifiedIdNode& node)
{
    scope = ResolveScope(node.Left(), context);
    node.Right()->Accept(*this);
}

void UsingDeclarationAdder::Visit(IdentifierNode& node)
{
    Symbol* symbol = scope->Lookup(node.Str(), ScopeLookup::thisScope, node.GetSourcePos(), context);
    if (symbol)
    {
        if (symbol->Kind() == SymbolKind::namespaceSymbol)
        {
            throw Exception("symbol '" + ToUtf8(symbol->FullName()) + "' denotes a namespace", node.GetSourcePos(), context);
        }
        else
        {
            context->GetSymbolTable()->CurrentScope()->AddUsingDeclaration(symbol, node.GetSourcePos(), context);
        }
    }
    else
    {
        throw Exception("symbol '" + ToUtf8(node.Str()) + "' not found", node.GetSourcePos(), context);
    }
}

void AddUsingDeclaration(Node* node, Context* context)
{
    UsingDeclarationAdder visitor(context);
    node->Accept(visitor);
}

class UsingEnumDeclarationAdder : public DefaultVisitor
{
public:
    UsingEnumDeclarationAdder(Context* context_);
    void Visit(UsingEnumDeclarationNode& node) override;
    void Visit(QualifiedIdNode& node) override;
    void Visit(IdentifierNode& node) override;
private:
    Context* context;
    Scope* scope;
};

UsingEnumDeclarationAdder::UsingEnumDeclarationAdder(Context* context_) : context(context_), scope(context->GetSymbolTable()->CurrentScope())
{
}

void UsingEnumDeclarationAdder::Visit(QualifiedIdNode& node)
{
    scope = ResolveScope(node.Left(), context);
    node.Right()->Accept(*this);
}

void UsingEnumDeclarationAdder::Visit(UsingEnumDeclarationNode& node)
{
    node.ElaboratedEnumSpecifier()->Accept(*this);
}

void UsingEnumDeclarationAdder::Visit(IdentifierNode& node)
{
    Symbol* symbol = scope->Lookup(node.Str(), ScopeLookup::thisScope, node.GetSourcePos(), context);
    if (symbol)
    {
        if (symbol->Kind() == SymbolKind::enumTypeSymbol)
        {
            EnumTypeSymbol* enumTypeSymbol = static_cast<EnumTypeSymbol*>(symbol);
            for (const auto& enumeratorSymbol : enumTypeSymbol->Enumerators())
            {
                context->GetSymbolTable()->CurrentScope()->AddUsingDeclaration(enumeratorSymbol.get(), node.GetSourcePos(), context);
            }
        }
        else
        {
            throw Exception("symbol '" + ToUtf8(symbol->FullName()) + "' does not denote an enumerated type", node.GetSourcePos(), context);
        }
    }
    else
    {
        throw Exception("symbol '" + ToUtf8(node.Str()) + "' not found", node.GetSourcePos(), context);
    }
}

void AddUsingEnumDeclaration(Node* node, Context* context)
{
    UsingEnumDeclarationAdder visitor(context);
    node->Accept(visitor);
}

} // sngcpp::symbols
