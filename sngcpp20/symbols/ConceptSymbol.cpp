// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/ConceptSymbol.hpp>
#include <sngcpp20/symbols/ConceptGroupSymbol.hpp>
#include <sngcpp20/symbols/ContainerSymbol.hpp>

namespace sngcpp::symbols {

ConceptSymbol::ConceptSymbol(const std::u32string& name_) : Symbol(name_, SymbolKind::conceptSymbol), groupScope(nullptr)
{
}

void ConceptSymbol::AddToGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context)
{
    this->groupScope = groupScope;
    ConceptGroupSymbol* conceptGroup = groupScope->GetOrInsertConceptGroup(Name(), sourcePos, context);
    conceptGroup->AddConcept(this);
}

} // sngcpp::symbols
