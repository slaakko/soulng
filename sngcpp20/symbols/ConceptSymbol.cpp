// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/ConceptSymbol.hpp>
#include <sngcpp20/symbols/ConceptGroupSymbol.hpp>
#include <sngcpp20/symbols/ContainerSymbol.hpp>
#include <sngcpp20/symbols/TemplateDeclarationSymbol.hpp>

namespace sngcpp::symbols {

ConceptSymbol::ConceptSymbol(const std::u32string& name_) : Symbol(name_, SymbolKind::conceptSymbol), groupScope(nullptr), group(nullptr), templateDeclarationSymbol(nullptr)
{
}

void ConceptSymbol::SetTemplateDeclarationSymbol(TemplateDeclarationSymbol* templateDeclarationSymbol_)
{
    templateDeclarationSymbol = templateDeclarationSymbol_;
}

void ConceptSymbol::AddToGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context)
{
    this->groupScope = groupScope;
    ConceptGroupSymbol* conceptGroup = groupScope->GetOrInsertConceptGroup(Name(), sourcePos, context);
    this->group = conceptGroup;
    conceptGroup->AddConcept(this);
}

bool ConceptSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    return scopeKind == ScopeKind::templateDeclarationScope;
}

void ConceptSymbol::SetTemplateArguments(const std::vector<Symbol*>& templateArguments_)
{
    templateArguments = templateArguments_;
}

void ConceptSymbol::AddTemplateParameters(const std::vector<TemplateParameterSymbol*>& templateParameters)
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
