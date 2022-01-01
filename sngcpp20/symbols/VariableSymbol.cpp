// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/VariableSymbol.hpp>
#include <sngcpp20/symbols/VariableGroupSymbol.hpp>
#include <sngcpp20/symbols/TemplateDeclarationSymbol.hpp>
#include <sngcpp20/symbols/Scope.hpp>

namespace sngcpp::symbols {

VariableSymbol::VariableSymbol(const std::u32string& name_) : 
    Symbol(name_, SymbolKind::variableSymbol), type(nullptr), value(nullptr), groupScope(nullptr), group(nullptr), variableTemplate(nullptr), templateDeclarationSymbol(nullptr)
{
}

VariableSymbol::VariableSymbol(const std::u32string& name_, SymbolKind kind_) : 
    Symbol(name_, kind_), type(nullptr), value(nullptr), groupScope(nullptr), group(nullptr), variableTemplate(nullptr), templateDeclarationSymbol(nullptr)
{
}

bool VariableSymbol::IsVariableTemplate() const
{
    TemplateDeclarationSymbol* templateDeclarationSymbol = GetTemplateDeclarationSymbol();
    return templateDeclarationSymbol != nullptr;
}

void VariableSymbol::AddToGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context)
{
    this->groupScope = groupScope;
    VariableGroupSymbol* variableGroup = groupScope->GetOrInsertVariableGroup(Name(), sourcePos, context);
    group = variableGroup;
    variableGroup->AddVariable(this);
}

void VariableSymbol::SetVariableTemplate(VariableSymbol* variableTemplate_)
{
    variableTemplate = variableTemplate_;
}

void VariableSymbol::SetTemplateArguments(const std::vector<Symbol*>& templateArguments_)
{
    templateArguments = templateArguments_;
}

bool VariableSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::namespaceScope: return true;
        case ScopeKind::templateDeclarationScope: return true;
        case ScopeKind::classScope: return true;
        case ScopeKind::blockScope: return true;
    }
    return false;
}

void VariableSymbol::AddTemplateParameters(const std::vector<TemplateParameterSymbol*>& templateParameters)
{
    if (templateArguments.empty())
    {
        for (TemplateParameterSymbol* templateParameter : templateParameters)
        {
            templateArguments.push_back(templateParameter);
        }
    }
}

ParameterSymbol::ParameterSymbol(const std::u32string& name_) : VariableSymbol(name_, SymbolKind::parameterSymbol)
{
}

bool ParameterSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::functionScope: return true;
    }
    return false;
}

} // sngcpp::symbols
