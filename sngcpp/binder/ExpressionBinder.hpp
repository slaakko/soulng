// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_BINDER_EXPRESSION_BINDER_INCLUDED
#define SNGCPP_BINDER_EXPRESSION_BINDER_INCLUDED
#include <sngcpp/binder/BoundSourceFile.hpp>
#include <sngcpp/symbols/SymbolTable.hpp>
#include <sngcpp/symbols/Scope.hpp>
#include <sngcpp/ast/Node.hpp>

namespace sngcpp { namespace binder {

class StatementBinder;

SNGCPP_BINDER_API std::vector<Symbol*> BindExpression(Node* node, SymbolTable& symbolTable, ContainerScope* containerScope, const std::vector<ContainerScope*>& prevContainerScopes,
    BoundSourceFile* boundSourceFile, FunctionSymbol* currentFunction, StatementBinder* statementBinder);

SNGCPP_BINDER_API std::vector<Symbol*> BindExpression(Node* node, SymbolTable& symbolTable, ContainerScope* containerScope, const std::vector<ContainerScope*>& prevContainerScopes,
    BoundSourceFile* boundSourceFile, FunctionSymbol* currentFunction, StatementBinder* statementBinder, bool& subjectIsConst);

} } // namespace sngcpp::binder

#endif // SNGCPP_BINDER_EXPRESSION_BINDER_INCLUDED
