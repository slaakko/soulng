                                                                                                                                                                                            // =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_ENUM_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_ENUM_TYPE_SYMBOL_INCLUDED
#include <sngcpp20/symbols/TypeSymbol.hpp>

namespace sngcpp::symbols {

using namespace sngcpp::ast;

class SYMBOLS_API EnumeratorSymbol : public Symbol
{
public:
    EnumeratorSymbol(const std::u32string& name_, uint64_t value_, const std::u32string& rep_);
    std::string SymbolKindStr() const override { return "enumerator symbol"; }
    uint64_t Value() const { return value; }
    const std::u32string& Rep() const { return rep; }
private:
    uint64_t value;
    std::u32string rep;
};

class SYMBOLS_API EnumTypeSymbol : public TypeSymbol
{
public:
    EnumTypeSymbol(const std::u32string& name_, TypeSymbol* enumBaseType_);
    std::string SymbolKindStr() const override { return "enum type symbol"; }
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
    void SetIdNode(Node* idNode_) { idNode = idNode_; }
    Node* IdNode() const { return idNode; }
    void AddEnumerator(EnumeratorSymbol* enumerator);
    const std::vector<std::unique_ptr<EnumeratorSymbol>>& Enumerators() const { return enumerators; }
private:
    Node* idNode;
    TypeSymbol* enumBaseType;
    std::vector<std::unique_ptr<EnumeratorSymbol>> enumerators;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_ENUM_TYPE_SYMBOL_INCLUDED
