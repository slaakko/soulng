// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_ARRAY_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_ARRAY_TYPE_SYMBOL_INCLUDED
#include <sngcpp20/symbols/TypeSymbol.hpp>

namespace sngcpp::symbols {

struct SYMBOLS_API ArrayTypeKey
{
    ArrayTypeKey(TypeSymbol* elementType_, uint64_t dimension_);
    TypeSymbol* elementType;
    uint64_t dimension;
};

SYMBOLS_API bool operator==(const ArrayTypeKey& left, const ArrayTypeKey& right);

struct SYMBOLS_API ArrayTypeKeyHash
{
    size_t operator()(const ArrayTypeKey& key) const;
};

class SYMBOLS_API ArrayTypeSymbol : public TypeSymbol
{
public:
    ArrayTypeSymbol(const ArrayTypeKey& key_);
    const ArrayTypeKey& Key() const { return key; }
private:
    ArrayTypeKey key;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_ARRAY_TYPE_SYMBOL_INCLUDED
