// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/ArrayTypeSymbol.hpp>

namespace sngcpp::symbols {

ArrayTypeKey::ArrayTypeKey(TypeSymbol* elementType_, uint64_t dimension_) : elementType(elementType_), dimension(dimension_)
{
}

bool operator==(const ArrayTypeKey& left, const ArrayTypeKey& right)
{
    if (left.dimension != right.dimension) return false;
    if (left.elementType != right.elementType) return false;
    return true;
}

size_t ArrayTypeKeyHash::operator()(const ArrayTypeKey& key) const
{
    size_t hashCode = std::hash<uint64_t>()(key.dimension);
    hashCode ^= std::hash<TypeSymbol*>()(key.elementType);
    return hashCode;
}

ArrayTypeSymbol::ArrayTypeSymbol(const ArrayTypeKey& key_) : TypeSymbol(std::u32string()), key(key_)
{
}

} // sngcpp::symbols
