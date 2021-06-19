// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/ClassTypeSymbol.hpp>
#include <sngcpp20/symbols/ClassGroupSymbol.hpp>
#include <sngcpp20/symbols/TemplateDeclarationSymbol.hpp>

namespace sngcpp::symbols {

ClassTypeSymbol::ClassTypeSymbol(const std::u32string& name_) : TypeSymbol(name_, SymbolKind::classTypeSymbol), idNode(nullptr), classTemplate(nullptr), templateDeclarationSymbol(nullptr)
{
    GetScope()->SetKind(ScopeKind::classScope);
}

bool ClassTypeSymbol::IsClassTemplate() const
{
    TemplateDeclarationSymbol* templateDeclarationSymbol = GetTemplateDeclarationSymbol();
    return templateDeclarationSymbol != nullptr;
}

bool ClassTypeSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::namespaceScope: return true;
        case ScopeKind::templateDeclarationScope: return true;
        case ScopeKind::classScope: return true;
    }
    return false;
}

void ClassTypeSymbol::AddToGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context)
{
    ClassGroupSymbol* classGroup = groupScope->GetOrInsertClassGroup(Name(), sourcePos, context);
    classGroup->AddClass(this);
}

void ClassTypeSymbol::AddBaseClass(ClassTypeSymbol* baseClass, const SourcePos& sourcePos, Context* context)
{
    baseClasses.push_back(baseClass);
    GetScope()->AddBaseScope(baseClass->GetScope(), sourcePos, context);
}

void ClassTypeSymbol::SetTemplateArguments(const std::vector<Symbol*>& templateArguments_)
{
    templateArguments = templateArguments_;
}

void ClassTypeSymbol::AddTemplateParameters(const std::vector<TemplateParameterSymbol*>& templateParameters)
{
    if (templateArguments.empty())
    {
        for (TemplateParameterSymbol* templateParameter : templateParameters)
        {
            templateArguments.push_back(templateParameter);
        }
    }
}

int ClassTypeSymbol::Level() const
{
    Symbol* parent = Parent();
    while (parent)
    {
        if (parent->Kind() == SymbolKind::classTypeSymbol)
        {
            return static_cast<ClassTypeSymbol*>(parent)->Level() + 1;
        }
        parent = parent->Parent();
    }
    return 0;
}

} // sngcpp::symbols
