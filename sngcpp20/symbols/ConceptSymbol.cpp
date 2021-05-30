// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/ConceptSymbol.hpp>
#include <sngcpp20/symbols/ConceptGroupSymbol.hpp>
#include <sngcpp20/symbols/ContainerSymbol.hpp>

namespace sngcpp::symbols {

ConceptSymbol::ConceptSymbol(const std::u32string& name_) : Symbol(name_)
{
}

void ConceptSymbol::AddToGroup(ContainerSymbol* containerSymbol, const SourcePos& sourcePos, Context* context) 
{
    ConceptGroupSymbol* conceptGroup = containerSymbol->GetOrInsertConceptGroup(Name(), sourcePos, context);
    conceptGroup->AddConcept(this);
}

} // sngcpp::symbols
