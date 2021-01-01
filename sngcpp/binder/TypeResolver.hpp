// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_BINDER_TYPE_RESOLVER_INCLUDED
#define SNGCPP_BINDER_TYPE_RESOLVER_INCLUDED
#include <sngcpp/binder/BoundSourceFile.hpp>
#include <sngcpp/symbols/SymbolTable.hpp>
#include <sngcpp/symbols/TypeSymbol.hpp>
#include <sngcpp/ast/Node.hpp>

namespace sngcpp { namespace binder {

enum class TypeResolverFlags : uint8_t
{
    none = 0,
    resolveClassGroup = 1 << 0,
    nothrow = 1 << 1,
    noExternalTypes = 1 << 2,
    notSelf = 1 << 3
};

SNGCPP_BINDER_API inline TypeResolverFlags operator|(TypeResolverFlags left, TypeResolverFlags right)
{
    return TypeResolverFlags(uint8_t(left) | uint8_t(right));
}

SNGCPP_BINDER_API inline TypeResolverFlags operator&(TypeResolverFlags left, TypeResolverFlags right)
{
    return TypeResolverFlags(uint8_t(left) & uint8_t(right));
}

SNGCPP_BINDER_API sngcpp::symbols::TypeSymbol* ResolveType(SymbolTable& symbolTable, ContainerScope* containerScope, const std::vector<ContainerScope*>& prevContainerScopes,
    BoundSourceFile& boundSourceFile, ClassTypeSymbol* currentClassType, Node* node);
SNGCPP_BINDER_API sngcpp::symbols::TypeSymbol* ResolveType(SymbolTable& symbolTable, ContainerScope* containerScope, const std::vector<ContainerScope*>& prevContainerScopes,
    BoundSourceFile& boundSourceFile, TypeResolverFlags flags, ClassTypeSymbol* currentClassType, Node* node);

} } // namespace sngcpp::binder

#endif // SNGCPP_BINDER_TYPE_RESOLVER_INCLUDED
