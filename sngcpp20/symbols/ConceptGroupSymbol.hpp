// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_CONCEP_GROUP_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_CONCEP_GROUP_SYMBOL_INCLUDED
#include <sngcpp20/symbols/Symbol.hpp>
#include <vector>

namespace sngcpp::symbols {

class ConceptSymbol;

class SYMBOLS_API ConceptGroupSymbol : public Symbol
{
public:
    ConceptGroupSymbol(const std::u32string& name_);
    std::string SymbolKindStr() const override { return "concept group symbol"; }
    void AddConcept(ConceptSymbol* conceptSymbol);
    Scope* GetScope() override;
private:
    std::vector<ConceptSymbol*> concepts;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_CONCEP_GROUP_SYMBOL_INCLUDED
