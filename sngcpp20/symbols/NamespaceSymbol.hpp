// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_NAMESPACE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_NAMESPACE_SYMBOL_INCLUDED
#include <sngcpp20/symbols/ContainerSymbol.hpp>

namespace sngcpp::symbols {

class SYMBOLS_API NamespaceSymbol : public ContainerSymbol
{
public:
    NamespaceSymbol(const std::u32string& name_);
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_NAMESPACE_SYMBOL_INCLUDED
