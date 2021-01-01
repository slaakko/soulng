// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_BINDER_VIRTUAL_BINDER_INCLUDED
#define SNGCPP_BINDER_VIRTUAL_BINDER_INCLUDED
#include <sngcpp/binder/BinderApi.hpp>
#include <sngcpp/symbols/ClassTypeSymbol.hpp>
#include <unordered_set>

namespace sngcpp { namespace binder {

SNGCPP_BINDER_API void ResolveOverrideSets(const std::unordered_set<sngcpp::symbols::ClassTypeSymbol*>& classes);

} } // namespace sngcpp::binder

#endif // SNGCPP_BINDER_VIRTUAL_BINDER_INCLUDED
