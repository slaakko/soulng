// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_FUNCTION_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_FUNCTION_TYPE_SYMBOL_INCLUDED
#include <sngcpp20/symbols/TypeSymbol.hpp>
#include <sngcpp20/symbols/VariableSymbol.hpp>

namespace sngcpp::symbols {

struct SYMBOLS_API FunctionTypeKey
{
    FunctionTypeKey();
    FunctionTypeKey(TypeSymbol* returnType_, std::vector<TypeSymbol*> parameterTypes_);
    TypeSymbol* returnType;
    std::vector<TypeSymbol*> parameterTypes;
};

SYMBOLS_API bool operator==(const FunctionTypeKey& left, const FunctionTypeKey& right);

struct SYMBOLS_API FunctionTypeKeyHash
{
    size_t operator()(const FunctionTypeKey& key) const;
};

class SYMBOLS_API FunctionTypeSymbol : public TypeSymbol
{
public:
    FunctionTypeSymbol();
    bool IsFunctionTypeSymbol() const override { return true; }
    const FunctionTypeKey& Key() const { return key; }
    void SetKey(const FunctionTypeKey& key_);
private:
    FunctionTypeKey key;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_FUNCTION_TYPE_SYMBOL_INCLUDED
