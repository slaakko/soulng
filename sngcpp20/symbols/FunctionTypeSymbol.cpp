// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/FunctionTypeSymbol.hpp>

namespace sngcpp::symbols {

FunctionTypeKey::FunctionTypeKey() : returnType(nullptr), parameterTypes()
{
}

FunctionTypeKey::FunctionTypeKey(TypeSymbol* returnType_, std::vector<TypeSymbol*> parameterTypes_) : returnType(returnType_), parameterTypes(parameterTypes_)
{
}

bool operator==(const FunctionTypeKey& left, const FunctionTypeKey& right)
{
    if (left.returnType != right.returnType) return false;
    if (left.parameterTypes.size() != right.parameterTypes.size()) return false;
    int n = left.parameterTypes.size();
    for (int i = 0; i < n; ++i)
    {
        if (left.parameterTypes[i] != right.parameterTypes[i]) return false;
    }
    return true;
}

size_t FunctionTypeKeyHash::operator()(const FunctionTypeKey& key) const
{
    size_t hashCode = std::hash<TypeSymbol*>()(key.returnType);
    for (TypeSymbol* paramType : key.parameterTypes)
    {
        hashCode ^= std::hash<TypeSymbol*>()(paramType);
    }
    return hashCode;
}

FunctionTypeSymbol::FunctionTypeSymbol() : TypeSymbol(std::u32string()), key()
{
}

void FunctionTypeSymbol::SetKey(const FunctionTypeKey& key_)
{
    key = key_;
}

} // sngcpp::symbols

