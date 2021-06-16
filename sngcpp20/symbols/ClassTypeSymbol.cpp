// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/ClassTypeSymbol.hpp>
#include <sngcpp20/symbols/ClassGroupSymbol.hpp>

namespace sngcpp::symbols {

ClassTypeSymbol::ClassTypeSymbol(const std::u32string& name_) : TypeSymbol(name_), idNode(nullptr), templateArity(0)
{
    GetScope()->SetKind(ScopeKind::classScope);
}

bool ClassTypeSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::namespaceScope: return true;
        case ScopeKind::classScope: return true;
    }
    return false;
}

void ClassTypeSymbol::AddToGroup(ContainerSymbol* containerSymbol, const SourcePos& sourcePos, Context* context)
{
    ClassGroupSymbol* classGroup = containerSymbol->GetOrInsertClassGroup(Name(), sourcePos, context);
    classGroup->AddClass(this);
}

void ClassTypeSymbol::AddBaseClass(ClassTypeSymbol* baseClass, const SourcePos& sourcePos, Context* context)
{
    baseClasses.push_back(baseClass);
    GetScope()->AddBaseScope(baseClass->GetScope(), sourcePos, context);
}

int ClassTypeSymbol::Level() const
{
    Symbol* parent = Parent();
    while (parent)
    {
        if (parent->IsClassTypeSymbol())
        {
            return static_cast<ClassTypeSymbol*>(parent)->Level() + 1;
        }
        parent = parent->Parent();
    }
    return 0;
}

} // sngcpp::symbols
