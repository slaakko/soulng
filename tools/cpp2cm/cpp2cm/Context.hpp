// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef CPP2CM_CPP2CM_CONTEXT_INCLUDED
#define CPP2CM_CPP2CM_CONTEXT_INCLUDED
#include <sngcpp/symbols/Symbol.hpp>
#include <sngcm/ast/Namespace.hpp>
#include <unordered_map>
#include <set>
#include <string>

namespace cpp2cm {

struct Context
{
    Context();
    std::unordered_map<std::u32string, sngcm::ast::NamespaceNode*> nsmap;
    std::unordered_map<sngcpp::symbols::Symbol*, sngcm::ast::Node*> containerMap;
    std::set<std::u32string> namespaceImports;
    sngcm::ast::Node* currentContainerNode;
    sngcm::ast::NamespaceNode* currentNamespace;
    sngcpp::symbols::ClassTypeSymbol* currentClassTypeSymbol;
};

} // namespace cpp2cm

#endif // CPP2CM_CPP2CM_CONTEXT_INCLUDED
