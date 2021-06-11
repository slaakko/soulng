// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/ClassGroupSymbol.hpp>
#include <sngcpp20/symbols/ClassTypeSymbol.hpp>
#include <sngcpp20/symbols/Scope.hpp>

namespace sngcpp::symbols {

ClassGroupSymbol::ClassGroupSymbol(const std::u32string& name_) : Symbol(name_)
{
}

bool ClassGroupSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::namespaceScope: return true;
        case ScopeKind::classScope: return true;
    }
    return false;
}

void ClassGroupSymbol::AddClass(ClassTypeSymbol* classTypeSymbol)
{
    classes.push_back(classTypeSymbol);
}

Scope* ClassGroupSymbol::GetScope() 
{
    if (classes.size() == 1)
    {
        ClassTypeSymbol* classTypeSymbol = classes.front();
        return classTypeSymbol->GetScope();
    }
    return nullptr;
}

} // sngcpp::symbols
