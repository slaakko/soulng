// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_CONCEPT_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_CONCEPT_SYMBOL_INCLUDED
#include <sngcpp20/symbols/Symbol.hpp>

namespace sngcpp::symbols {

class SYMBOLS_API ConceptSymbol : public Symbol
{
public:
    ConceptSymbol(const std::u32string& name_);
    std::string SymbolKindStr() const override { return "concept symbol"; }
    void AddToGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context) override;
    bool CanInstall() const override { return false; }
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_CONCEPT_SYMBOL_INCLUDED
