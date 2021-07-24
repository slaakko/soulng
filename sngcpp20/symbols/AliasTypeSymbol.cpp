// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/AliasTypeSymbol.hpp>
#include <sngcpp20/symbols/AliasGroupSymbol.hpp>
#include <sngcpp20/symbols/TemplateDeclarationSymbol.hpp>

namespace sngcpp::symbols {

AliasTypeSymbol::AliasTypeSymbol(const std::u32string& name_, TypeSymbol* referredType_) : 
    TypeSymbol(name_, SymbolKind::aliasTypeSymbol), referredType(referredType_), templateDeclarationSymbol(nullptr), groupScope(nullptr), group(nullptr), aliasTemplate(nullptr)
{
}

bool AliasTypeSymbol::IsAliasTemplate() const
{
    TemplateDeclarationSymbol* templateDeclarationSymbol = GetTemplateDeclarationSymbol();
    return templateDeclarationSymbol != nullptr;
}

bool AliasTypeSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
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

void AliasTypeSymbol::AddToGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context)
{
    this->groupScope = groupScope;
    AliasGroupSymbol* aliasGroup = groupScope->GetOrInsertAliasGroup(Name(), sourcePos, context);
    group = aliasGroup;
    aliasGroup->AddAliasTypeSymbol(this);
}

void AliasTypeSymbol::SetTemplateArguments(const std::vector<Symbol*>& templateArguments_)
{
    templateArguments = templateArguments_;
}

void AliasTypeSymbol::SetAliasTemplate(AliasTypeSymbol* aliasTemplate_)
{
    aliasTemplate = aliasTemplate_;
}

void AliasTypeSymbol::AddTemplateParameters(const std::vector<TemplateParameterSymbol*>& templateParameters)
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
