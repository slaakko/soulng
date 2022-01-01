// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/FunctionSymbol.hpp>
#include <sngcpp20/symbols/VariableSymbol.hpp>
#include <sngcpp20/symbols/FunctionGroupSymbol.hpp>
#include <sngcpp20/symbols/TemplateDeclarationSymbol.hpp>

namespace sngcpp::symbols {

FunctionSymbol::FunctionSymbol(const std::u32string& name_, FunctionTypeSymbol* type_, bool definition_) :
    ContainerSymbol(name_, SymbolKind::functionSymbol), type(type_), definition(definition_), templateDeclarationSymbol(nullptr), groupScope(nullptr)
{
    GetScope()->SetKind(ScopeKind::functionScope);
}

bool FunctionSymbol::IsConstructorSymbol() const
{
    return Name() == Parent()->Name();
}

bool FunctionSymbol::IsDestructorSymbol() const
{
    return Name() == U"~" + Parent()->Name();
}

bool FunctionSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::namespaceScope: return true;
        case ScopeKind::templateDeclarationScope: return true;
        case ScopeKind::classScope: return true;
    }
    return false;
}

void FunctionSymbol::AddToGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context)
{
    this->groupScope = groupScope;
    FunctionGroupSymbol* functionGroup = groupScope->GetOrInsertFunctionGroup(Name(), sourcePos, context);
    functionGroup->AddFunction(this);
}

void FunctionSymbol::RemoveFromGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context)
{
    FunctionGroupSymbol* functionGroup = groupScope->GetOrInsertFunctionGroup(Name(), sourcePos, context);
    functionGroup->RemoveFunction(this);
}

void FunctionSymbol::SetTemplateArguments(const std::vector<Symbol*>& templateArguments_)
{
    templateArguments = templateArguments_;
}

void FunctionSymbol::AddTemplateParameters(const std::vector<TemplateParameterSymbol*>& templateParameters)
{
    if (templateArguments.empty())
    {
        for (TemplateParameterSymbol* templateParameter : templateParameters)
        {
            templateArguments.push_back(templateParameter);
        }
    }
}

} // sngcpp::symbols
