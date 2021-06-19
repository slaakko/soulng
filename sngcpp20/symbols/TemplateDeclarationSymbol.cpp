// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/TemplateDeclarationSymbol.hpp>

namespace sngcpp::symbols {

TypenameConstraintSymbol::TypenameConstraintSymbol() : TypeSymbol(std::u32string(), SymbolKind::typenameConstraintSymbol)
{
}

TemplateParameterSymbol::TemplateParameterSymbol(Symbol* constraint_, const std::u32string& name_, int index_) : TypeSymbol(name_, SymbolKind::templateParameterSymbol), constraint(constraint_), index(index_)
{
}

TemplateDeclarationSymbol::TemplateDeclarationSymbol() : ContainerSymbol(std::u32string(), SymbolKind::templateDeclarationSymbol)
{
    GetScope()->SetKind(ScopeKind::templateDeclarationScope);
}

void TemplateDeclarationSymbol::AddSymbol(Symbol* symbol, const SourcePos& sourcePos, Scope* groupScope, Context* context)
{
    ContainerSymbol::AddSymbol(symbol, sourcePos, groupScope, context);
    if (symbol->Kind() == SymbolKind::templateParameterSymbol)
    {
        TemplateParameterSymbol* templateParameterSymbol = static_cast<TemplateParameterSymbol*>(symbol);
        temlateParameters.push_back(templateParameterSymbol);
    }
}

} // sngcpp::symbols
