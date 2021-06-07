// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_ENUM_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_ENUM_TYPE_SYMBOL_INCLUDED
#include <sngcpp20/symbols/TypeSymbol.hpp>

namespace sngcpp::symbols {

using namespace sngcpp::ast;

class SYMBOLS_API EnumTypeSymbol : public TypeSymbol
{
public:
    EnumTypeSymbol(const std::u32string& name_);
    bool IsEnumTypeSymbol() const override { return true; }
    void SetIdNode(Node* idNode_) { idNode = idNode_; }
    Node* IdNode() const { return idNode; }
private:
    Node* idNode;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_ENUM_TYPE_SYMBOL_INCLUDED
